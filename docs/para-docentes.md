# Guía del instructor · 3 horas

[← Inicio](../README.md) · [Guía PDF](../guia/guia_laboratorio_ESP32_ATSEP.pdf) · [Mapa de clases](mapa-de-clases.md)

**Propósito:** conectar el control cableado que se observa en la presentación, las condiciones lógicas del simulador y un circuito didáctico físico.

## Secuencia

| Momento | Tiempo | Criterio de éxito |
|---|---:|---|
| Introducción y seguridad | 20 min | Reconocen pines y verifican el kit |
| LED y resistencia | 25 min | Calculan y miden sin cortocircuitos |
| Entradas y pull-up/pull-down | 35 min | Explican 0/1 y flotación |
| Retención e inhibición | 45 min | Distinguen software y cableado |
| Transferencia red–planta | 40 min | Explican ausencia de enclavamiento cruzado |
| Evidencias y reflexión | 15 min | Entregan tablas y justifican decisiones |

**Antes de la clase:** confirmar el modelo exacto de ESP32, probar el firmware real en el hardware elegido y comprobar el cableado contra el esquema, no solamente contra la vista ilustrativa de protoboard. El 74HC08 debe recibir 3,3 V, GND y desacoplo de 100 nF.

**Límites de seguridad:** usar LEDs, nunca bobinas/contactores reales; la entrada PARO educativa no equivale a un paro de emergencia de seguridad.

**Evaluación:** predicción del comportamiento antes de accionar, coincidencia entre medición y análisis, calidad de explicaciones y evidencia documental.
