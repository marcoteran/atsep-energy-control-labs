/*
  Banco basico ATSEP: ESP32 + 74HC08 (referencia didactica).
  Solo LEDs a 3,3 V. Nunca conectar cargas o tensiones de red.
  Monitor serie: 115200 baudios; comandos 1, 2, 3, 4, b, k.
*/
const uint8_t LED_ALARMA = 18;
const uint8_t PIN_MARCHA = 14;
const uint8_t PIN_PARO = 13;    // 1 = PARO_OK, 0 = pulsado
const uint8_t PIN_A = 32;       // red apta
const uint8_t PIN_B = 33;       // planta disponible
const uint8_t PIN_FALLA = 25;
const uint8_t CMD1 = 23;       // a 74HC08 pin 1
const uint8_t CMD2 = 22;       // a 74HC08 pin 4

const unsigned long CONF_FALLA = 3000UL;
const unsigned long TIEMPO_MUERTO = 2000UL;
const unsigned long CONF_RETORNO = 5000UL;

enum Etapa { RED, ESPERA_FALLA, MUERTO_PLANTA,
             PLANTA, ESPERA_RETORNO, MUERTO_RED,
             SIN_FUENTE, DETENIDO };
Etapa etapa = DETENIDO;
unsigned long inicioEtapa = 0;
int practica = 0;
bool retenido = false;
bool anteriorMarcha = false;
bool trabado = false;           // prueba b: CMD1 forzado alto
bool fallaDoble = false;        // prueba k: CMD1 y CMD2 altos
int anteriorEntradas = -1;

bool paroOK() { return digitalRead(PIN_PARO) == HIGH; }
bool marcha() { return digitalRead(PIN_MARCHA) == HIGH; }
bool redApta() { return digitalRead(PIN_A) == HIGH; }
bool plantaLista() { return digitalRead(PIN_B) == HIGH; }
bool hayFalla() { return digitalRead(PIN_FALLA) == HIGH; }

void salidas(bool km1, bool km2, bool alarma) {
  // La compuerta 74HC08 inhibe los LEDs KM1/KM2 al pulsar PARO.
  digitalWrite(CMD1, km1 ? HIGH : LOW);
  digitalWrite(CMD2, km2 ? HIGH : LOW);
  digitalWrite(LED_ALARMA, alarma ? HIGH : LOW);
}

void cambiar(Etapa nueva, unsigned long ahora, const char* mensaje) {
  etapa = nueva;
  inicioEtapa = ahora;
  Serial.println(mensaje);
}

void seleccionar(int p, unsigned long ahora) {
  practica = p;
  retenido = false;
  trabado = false;
  fallaDoble = false;
  anteriorMarcha = marcha();
  anteriorEntradas = -1;
  salidas(false, false, false);
  Serial.printf("Practica %d seleccionada.\n", p);
  if (p == 4) {
    if (!paroOK()) cambiar(DETENIDO, ahora, "PARO activo: libere y escriba 4.");
    else if (redApta()) cambiar(RED, ahora, "RED: KM1 habilitado.");
    else cambiar(SIN_FUENTE, ahora, "Sin red: esperando fuente.");
  }
}

void procesarComandos(unsigned long ahora) {
  while (Serial.available() > 0) {
    char c = (char)Serial.read();
    if (c >= '1' && c <= '4') seleccionar(c - '0', ahora);
    else if (c == 'b' && practica == 3) {
      trabado = !trabado;
      Serial.println(trabado ? "Prueba b: CMD1 forzado a 1."
                              : "Prueba b finalizada.");
    } else if (c == 'k' && practica == 4) {
      fallaDoble = !fallaDoble;
      Serial.println(fallaDoble ? "Prueba k: ambas ordenes a 1."
                                 : "Prueba k terminada: control normal.");
    }
  }
}

void reportarEntradas() {
  int bits = (marcha() ? 1 : 0) | (paroOK() ? 2 : 0)
            | (redApta() ? 4 : 0) | (plantaLista() ? 8 : 0)
            | (hayFalla() ? 16 : 0);
  if (bits != anteriorEntradas) {
    anteriorEntradas = bits;
    Serial.printf("MARCHA=%d PARO_OK=%d A=%d B=%d FALLA=%d\n",
      marcha(), paroOK(), redApta(), plantaLista(), hayFalla());
  }
}

void controlarTransferencia(unsigned long ahora) {
  if (!paroOK()) {
    if (etapa != DETENIDO)
      cambiar(DETENIDO, ahora, "PARO: control detenido; reinicie con 4.");
    return;
  }
  switch (etapa) {
    case RED:
      if (!redApta()) cambiar(ESPERA_FALLA, ahora, "Fallo de red: contando 3 s.");
      break;
    case ESPERA_FALLA:
      if (redApta()) cambiar(RED, ahora, "Microcorte: sigue KM1.");
      else if (ahora - inicioEtapa >= CONF_FALLA)
        cambiar(MUERTO_PLANTA, ahora, "Red confirmada perdida: KM1 abierto.");
      break;
    case MUERTO_PLANTA:
      if (ahora - inicioEtapa >= TIEMPO_MUERTO) {
        if (redApta()) cambiar(RED, ahora, "Red disponible: KM1.");
        else if (plantaLista()) cambiar(PLANTA, ahora, "Planta: KM2 habilitado.");
        else cambiar(SIN_FUENTE, ahora, "Ninguna fuente disponible.");
      }
      break;
    case PLANTA:
      if (!plantaLista()) cambiar(SIN_FUENTE, ahora, "Planta no disponible: KM2 abierto.");
      else if (redApta()) cambiar(ESPERA_RETORNO, ahora, "Red retorno: contando 5 s.");
      break;
    case ESPERA_RETORNO:
      if (!redApta()) cambiar(PLANTA, ahora, "Retorno inestable: sigue KM2.");
      else if (!plantaLista()) cambiar(SIN_FUENTE, ahora, "Planta perdida: KM2 abierto.");
      else if (ahora - inicioEtapa >= CONF_RETORNO)
        cambiar(MUERTO_RED, ahora, "Retorno confirmado: KM2 abierto.");
      break;
    case MUERTO_RED:
      if (ahora - inicioEtapa >= TIEMPO_MUERTO) {
        if (redApta()) cambiar(RED, ahora, "Red: KM1 habilitado.");
        else if (plantaLista()) cambiar(PLANTA, ahora, "Sin red: vuelve KM2.");
        else cambiar(SIN_FUENTE, ahora, "Sin fuentes.");
      }
      break;
    case SIN_FUENTE:
      if (redApta()) cambiar(RED, ahora, "Red disponible: KM1.");
      else if (plantaLista()) cambiar(MUERTO_PLANTA, ahora, "Planta lista: espera 2 s.");
      break;
    case DETENIDO:
      break; // solo se rearma enviando 4
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_MARCHA, INPUT);     // resistencias externas de 10 kOhm
  pinMode(PIN_PARO, INPUT);
  pinMode(PIN_A, INPUT);
  pinMode(PIN_B, INPUT);
  pinMode(PIN_FALLA, INPUT);
  pinMode(LED_ALARMA, OUTPUT);
  pinMode(CMD1, OUTPUT);
  pinMode(CMD2, OUTPUT);
  salidas(false, false, false);
  Serial.println("Banco básico ATSEP. Escriba 1, 2, 3 o 4.");
}

void loop() {
  unsigned long ahora = millis();
  procesarComandos(ahora);
  bool m = marcha();
  bool ok = paroOK();
  if (practica == 1) salidas(false, false, true);
  else if (practica == 2) {
    reportarEntradas();
    salidas(false, false, m);
  } else if (practica == 3) {
    if (!ok || hayFalla()) retenido = false;
    else if (m && !anteriorMarcha) retenido = true;
    salidas(trabado || retenido, false, hayFalla());
  } else if (practica == 4) {
    controlarTransferencia(ahora);
    bool km1 = etapa == RED || etapa == ESPERA_FALLA;
    bool km2 = etapa == PLANTA || etapa == ESPERA_RETORNO;
    if (fallaDoble) { km1 = true; km2 = true; }
    salidas(km1, km2, !redApta() || hayFalla());
  } else salidas(false, false, false);
  anteriorMarcha = m;
  delay(10);
}