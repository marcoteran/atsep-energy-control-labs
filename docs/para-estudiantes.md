# Ruta para estudiantes

[← Inicio](../README.md) · [Guía del laboratorio](../guia/guia_laboratorio_ESP32_ATSEP.pdf) · [Programa ESP32](../firmware/banco_simple_esp32.ino)

## Antes de la sesión

Consulta los conceptos de control, mando y potencia, pulsadores, retención y enclavamiento en las [diapositivas](../presentaciones/controles_electricos_y_logica_cableada.pdf) y explora los [11 módulos del simulador](https://github.com/marcoteran/atsep-controllogyc).

## Durante la sesión

**Preparación (20 min)**: identifica el ESP32, los pines 3V3/GND y el integrado 74HC08, revisa todas las conexiones antes de energizar y abre el Monitor serie a 115200 baudios.

**Práctica 1 (25 min)**: calcula la resistencia y mide la caída de tensión en LED y resistencia.

**Práctica 2 (35 min)**: aprende a reconocer 0 y 1 en pulsadores y DIP. Comprueba por qué no debes dejar entradas flotantes.

**Práctica 3 (45 min)**: ensaya la retención con MARCHA y la inhibición con PARO en la lógica AND.

**Práctica 4 (40 min)**: simula los tiempos de transferencia red–planta y reflexiona sobre el enclavamiento cruzado.

**Cierre (15 min)**: entrega las tablas, respuestas y foto del montaje.

> El LED representa una orden. **No confirma el estado de contactos de potencia reales.** Trabaja solo con USB/3,3 V.
