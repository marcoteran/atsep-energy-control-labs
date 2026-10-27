# Auditoría de entrega — ATSEP controles eléctricos

**Estado:** comprobaciones automáticas aprobadas el 27 de octubre de 2026. Esta auditoría no equivale a pruebas sobre un ESP32 físico ni a certificación eléctrica.

## Juez 1 · Integridad del material académico — APROBADO

- Presentación original incorporada sin alteraciones: `235` páginas.
- Guía LaTeX compilada a PDF: `15` páginas, con cuatro prácticas, hoja de conexiones, código de referencia y diagramas.
- Documentación para estudiante, docente, mapa de unidades teóricas y portal de clase.
- Material fuente reproducible con script de compilación y firmware `.ino` separado.

## Juez 2 · Descargas y navegación — APROBADO LOCALMENTE

- Enlaces relativos de todos los archivos Markdown comprobados por `tests/validate_repo.py`.
- Enlace web de descarga del `.ino` presente dentro del PDF.
- Adjunto `.ino` PDF en el panel de archivos incrustados **y** como icono de clip en el documento.
- Contenido del adjunto comparado byte a byte con `firmware/banco_simple_esp32.ino`.
- Enlace al repositorio fuente del simulador `atsep-controllogyc` presente en PDF y README.
- La presentación está en el repositorio y enlazada desde portada, mapa de clases y portal HTML.

**Pendiente de la publicación:** los enlaces web que apuntan a `marcoteran/atsep-energy-control-labs` **no son accesibles hasta crear y subir este nuevo repositorio**. Las descargas internas del ZIP y el `.ino` incrustado en PDF sí están disponibles antes de publicarlo.

## Juez 3 · Coherencia técnica y seguridad — APROBADO EN SIMULACIÓN

- Comprobados los ocho pines del programa de referencia, tres tiempos de control y comandos `1`, `2`, `3`, `4`, `b`, `k`.
- Compilado y ejecutado `tests/test_lab.cpp` con mocks de entradas/salidas digitales: aprobados retención, fallo, rearme, anti-microcorte, transferencia y dos fallos forzados.
- Figura de implantación física de protoboard se complementa con tabla completa de conexiones. No se presenta como prueba de continuidad real.
- El programa y la guía distinguen lógica de control educativa de mando de potencia; los enclavamientos certificados quedan explícitamente fuera de alcance.
- Revisión visual de PDF: imágenes y láminas dentro del documento; sin errores fatales ni cajas `Overfull` en compilación; ningún texto fuera de los límites de la página tras corregir la rotación de la lámina horizontal.

## Limitaciones declaradas

1. **Hardware:** no se conectó un ESP32 real, no se probó polaridad de componentes comprados ni tensión real en las salidas del 74HC08.
2. **Publicación:** el nuevo repositorio todavía debe crearse desde GitHub CLI o la interfaz de GitHub. El conector disponible permitió inspeccionar el simulador, pero no crear un repositorio nuevo.
3. **Permisos:** la presentación es material académico adjuntado por el docente; se propone repositorio privado hasta definir si se distribuirá públicamente.
4. **PDF:** el hipervínculo web requiere publicación y permiso de GitHub si es privado; la extracción del adjunto PDF depende del visor.
5. **Fotografías:** se mantienen las ilustraciones didácticas alternativas de la guía; no se aportaron las fotografías físicas del kit y la polaridad.

### Repetir controles

```bash
python3 tests/validate_repo.py
g++ -std=c++17 -Wall -Wextra -O2 tests/test_lab.cpp -o /tmp/test_atsep && /tmp/test_atsep
bash scripts/build_pdf.sh
```