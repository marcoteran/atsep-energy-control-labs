# Taller en grupo · El cuarto eléctrico del Aeródromo Escuela

[← Inicio](../README.md) · [Diapositivas](../presentaciones/marcoteran_energy_electriccontroland_wiredlogyc.pdf) · [Guía del laboratorio](../guia/guia_laboratorio_ATSEP.pdf)

Taller para grupos de **cuatro** integrantes con roles rotativos: diseño lógico, especificación, verificación de fallas y registro. Recorre el caso del módulo sección por sección y en cada etapa pide **decisiones de ingeniería** justificadas con datos, normas y modos de falla.

Duración: **1 h 30 min** en una sesión.

| Etapa | Tarea | Min | Diapositivas |
|---|---|--:|---:|
| 0 | Organización: roles y caso | 5 | — |
| 1 | Leer el plano del extractor | 10 | p. 15, 33 |
| 2 | Especificar contactor, relé térmico y fuente de mando | 15 | p. 50 |
| 3 | Diseñar la lógica MAN-0-AUT con mando local y remoto | 20 | p. 100 |
| 4 | Bomba de trasiego: captadores y alarma | 10 | p. 122 |
| 5 | Transferencia red–planta: presupuesto de 15 s y barreras | 15 | p. 158, 178 |
| 6 | Diagnóstico con puntos de prueba | 10 | p. 204 |
| 7 | Cierre, registro de decisiones y defensa oral | 5 | — |

- **PDF para estudiantes:** [Descargar](https://github.com/marcoteran/atsep-energy-control-labs/raw/refs/heads/master/taller/taller_cuarto_electrico_ATSEP_90min.pdf)
- **Fuente editable:** [taller_cuarto_electrico_ATSEP_90min.tex](taller_cuarto_electrico_ATSEP_90min.tex)

La fuente de una versión ampliada de 4 h se conserva en `taller_cuarto_electrico_ATSEP.tex`.

## Compilar

Desde la raíz del repositorio, dos pasadas:

```bash
pdflatex -interaction=nonstopmode -halt-on-error -output-directory=taller taller/taller_cuarto_electrico_ATSEP_90min.tex
```

**Versión docente con soluciones:** necesita `taller/soluciones_taller.tex`, que está en `.gitignore` y no se publica en el repositorio.

```bash
pdflatex -interaction=nonstopmode -halt-on-error -output-directory=taller -jobname=taller_cuarto_electrico_ATSEP_90min_docente "\def\versiondocente{}\input{taller/taller_cuarto_electrico_ATSEP_90min.tex}"
```
