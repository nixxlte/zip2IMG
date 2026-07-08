### zip2IMG is an utility that decompress the system.img from a ROM.zip

It currently supports:
- Windows
- Linux
###### it technically supports any Linux distro, but "zip2img --install" is currently only adapted for Debian-based distros.

Utility dependencies:<br>
- brotli
- 7zip (you can install both by running zip2img --install)
---
- sdat2img
- img2simg (both comes with zip2IMG zip file)

### bugs:
this project is not finished, so expect fatal bugs to be fixed really soon
- [FATAL] Windows returns the error " 'C:\Program' is not recognized as an internal or external command,
operable program or batch file. " when decompressing the ROM, despite the path being the right one.