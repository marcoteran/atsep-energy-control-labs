# Publicar este repositorio en GitHub

**Estado del paquete:** preparado, con ruta de destino `marcoteran/atsep-energy-control-labs`. Los enlaces PDF a GitHub funcionan **después de publicar** el repositorio y otorgar permisos si es privado.

## Windows / PowerShell — paso a paso

1. Descargue y descomprima el ZIP en una carpeta.
2. Instale GitHub CLI desde PowerShell: `winget install --id GitHub.cli`.
3. Abra una **nueva** ventana PowerShell y ejecute `gh auth login` para iniciar sesión con su cuenta.
4. Abra PowerShell en la carpeta descomprimida.
5. Ejecute `.\scripts\publicar_github.ps1`.
6. Confirme los archivos en `https://github.com/marcoteran/atsep-energy-control-labs`.

El script crea el repo inicialmente **privado**, sin modificar el repo del simulador. Para acceso de estudiantes, puede invitarlos o decidir publicar el repositorio después de revisar el permiso de distribución de las diapositivas.

## Publicación manual (si no quiere utilizar el script)

Cree un nuevo repositorio vacío llamado `atsep-energy-control-labs` dentro del usuario `marcoteran`, sin añadir README automático. Luego desde la raíz del ZIP descomprimido:

```bash
git init -b master
git add .
git commit -m "feat: curso ATSEP con teoria, simulador y laboratorio ESP32"
git remote add origin https://github.com/marcoteran/atsep-energy-control-labs.git
git push -u origin master
```

GitHub Pages (opcional): en Settings → Pages, publicar la rama `master` y la carpeta `/docs`. El portal será `https://marcoteran.github.io/atsep-energy-control-labs/` si la configuración y la visibilidad permiten GitHub Pages.