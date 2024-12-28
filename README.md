# ssbs (0.2)
SP649's Simple Build Script - a small interpiter for a ssbs a small build script for any distro that is minimal as of now! loook below for a example called neofetch-7.1.0.ssbs:
```
<start>
<pkgname>
neofetch
<version>
7.1.0
<repo>
https://github.com/dylanaraps/neofetch.git
<exec>
git clone https://github.com/dylanaraps/neofetch.git
cd neofetch
sudo make install
cd -
rm -rf neofetch
<end>
```
## to install:
```
git clone https://github.com/lovemearowlet/ssbs.git
make
sudo (or doas) make install
```
## to uninstall:
```
sudo make uninstall
```
## usage:
```
ssbs -f /path/to/file.ssbs
```
make sure to review the file that you are installing!
## info:
- Makefile is very generic so feel free to edit to your liking!
- Made by SP649
- Lines of code (counting makefile): 105
## to do
- add a config file 
- add a build directory
- add more functions 
