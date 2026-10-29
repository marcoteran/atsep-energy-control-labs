# Banco físico con ESP32

[← Inicio](../README.md) · [Firmware](../firmware/banco_simple_esp32.ino) · [Presentación](../presentaciones/marcoteran_energy_electriccontroland_wiredlogyc.pdf)

Esta guía introduce progresivamente **LED y resistencia**, **pulsadores e interruptores**, **marcha–paro con retención** y **transferencia red–planta**. Todo sucede a **3,3 V** y las salidas son LEDs de demostración, no contactores reales.

- **PDF:** [guia_laboratorio_ATSEP.pdf](guia_laboratorio_ATSEP.pdf)
- **Fuente editable:** [guia_laboratorio_ESP32_ATSEP.tex](guia_laboratorio_ESP32_ATSEP.tex)
- **Código Arduino:** [banco_simple_esp32.ino](../firmware/banco_simple_esp32.ino)

Para compilar en la raíz del repositorio: `pdflatex -interaction=nonstopmode -halt-on-error -output-directory=guia guia/guia_laboratorio_ESP32_ATSEP.tex` (dos pasadas). El PDF incluye un enlace al `.ino` en GitHub y un adjunto extraíble cuando se compila con el firmware presente. Se necesita una distribución LaTeX con CircuitikZ, TikZ, babel y attachfile2.
