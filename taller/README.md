# Taller en grupo · El cuarto eléctrico del Aeródromo Escuela

[← Inicio](../README.md) · [Diapositivas](../presentaciones/marcoteran_energy_electriccontroland_wiredlogyc.pdf) · [Guía del laboratorio](../guia/guia_laboratorio_ATSEP.pdf)

Taller de **4 horas** (dos sesiones de 2 h) para grupos de **cuatro** integrantes con roles rotativos: diseño lógico, especificación, verificación de fallas y registro. Recorre el caso del módulo sección por sección y en cada etapa pide **decisiones de ingeniería** justificadas con datos, normas y modos de falla.

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

- **PDF para estudiantes:** [taller_cuarto_electrico_ATSEP.pdf](taller_cuarto_electrico_ATSEP.pdf)
- **Fuente editable:** [taller_cuarto_electrico_ATSEP.tex](taller_cuarto_electrico_ATSEP.tex)

## Compilar

Desde la raíz del repositorio, dos pasadas:

```bash
pdflatex -interaction=nonstopmode -halt-on-error -output-directory=taller taller/taller_cuarto_electrico_ATSEP.tex
```

**Versión docente con soluciones:** necesita `taller/soluciones_taller.tex`, que está en `.gitignore` y no se publica en el repositorio.

```bash
pdflatex -interaction=nonstopmode -halt-on-error -output-directory=taller -jobname=taller_cuarto_electrico_ATSEP_docente "\def\versiondocente{}\input{taller/taller_cuarto_electrico_ATSEP.tex}"
```
