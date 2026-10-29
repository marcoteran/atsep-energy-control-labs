# Taller en grupo · El cuarto eléctrico del Aeródromo Escuela

[← Inicio](../README.md) · [Diapositivas](../presentaciones/marcoteran_energy_electriccontroland_wiredlogyc.pdf) · [Guía del laboratorio](../guia/guia_laboratorio_ATSEP.pdf)

Taller para grupos de **cuatro** integrantes con roles rotativos: diseño lógico, especificación, verificación de fallas y registro. Recorre el caso del módulo sección por sección y en cada etapa pide **decisiones de ingeniería** justificadas con datos, normas y modos de falla.

Etapas de la versión completa:

| Etapa | Tarea | Diapositivas |
|---|---|---:|
| 1 | Leer el plano del extractor | p. 15, 33 |
| 2 | Especificar contactor, relé térmico y fuente de mando | p. 50 |
| 3 | Especificar el frente del tablero | p. 79 |
| 4 | Diseñar la lógica MAN-0-AUT con mando local y remoto | p. 100 |
| 5 | Bomba de trasiego, alarmas y temporizadores | p. 122, 141 |
| 6 | Transferencia red–planta: presupuesto de 15 s, barreras y Cat II | p. 158, 178 |
| 7 | Diagnóstico y línea de mando a la torre | p. 204 |
| 8 | Cierre, registro de decisiones y defensa oral | — |

## Dos versiones

| Versión | Duración | PDF | Fuente |
|---|---|---|---|
| Corta | 1 h 30 min, una sesión | [Descargar](https://github.com/marcoteran/atsep-energy-control-labs/raw/refs/heads/master/taller/taller_cuarto_electrico_ATSEP_90min.pdf) | [.tex](taller_cuarto_electrico_ATSEP_90min.tex) |
| Completa | 4 h, dos sesiones de 2 h | [Descargar](https://github.com/marcoteran/atsep-energy-control-labs/raw/refs/heads/master/taller/taller_cuarto_electrico_ATSEP.pdf) | [.tex](taller_cuarto_electrico_ATSEP.tex) |

La versión corta conserva el caso y deja las preguntas que mantiene tal como están en la completa, pero deja fuera el frente del tablero, los temporizadores del tablero de servicios, Cat II, la falla del mando de 24 V CC y los cálculos de la línea a la torre.

## Compilar

Desde la raíz del repositorio, dos pasadas. Para la versión corta, cambie `taller_cuarto_electrico_ATSEP` por `taller_cuarto_electrico_ATSEP_90min` en los dos comandos.

```bash
pdflatex -interaction=nonstopmode -halt-on-error -output-directory=taller taller/taller_cuarto_electrico_ATSEP.tex
```

**Versión docente con soluciones:** necesita `taller/soluciones_taller.tex`, que está en `.gitignore` y no se publica en el repositorio.

```bash
pdflatex -interaction=nonstopmode -halt-on-error -output-directory=taller -jobname=taller_cuarto_electrico_ATSEP_docente "\def\versiondocente{}\input{taller/taller_cuarto_electrico_ATSEP.tex}"
```
