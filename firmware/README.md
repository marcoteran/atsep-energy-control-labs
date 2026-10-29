# Firmware ESP32 · Banco ATSEP

[← Inicio](../README.md) · [Descargar programa](banco_simple_esp32.ino) · [Guía PDF](../guia/guia_laboratorio_ATSEP.pdf)

1. Instala **Arduino IDE** y el soporte de placas **ESP32** de Espressif.
2. Descarga [`banco_simple_esp32.ino`](banco_simple_esp32.ino), ábrelo en Arduino IDE y selecciona el modelo **ESP32 DevKitC** correcto y su puerto.
3. Carga el programa y abre el Monitor serie a **115200 baudios**.
4. Introduce **1–4** para seleccionar las prácticas. La guía explica las pruebas de falla `b` y `k`.

**Seguridad:** alimenta únicamente por USB y 3,3 V; no apliques 5 V a los GPIO, y no conectes contactores ni red de potencia. Las compuertas AND ilustran una inhibición de mando: **no constituyen un paro de emergencia ni un enclavamiento certificado**.
