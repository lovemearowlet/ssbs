# ssbs (0.1)
SP649's Simple Build Script - a small interpiter for a ssbs a small build script for any distro that is minimal as of now! loook below for a example called neofetch-7.1.0-min.ssbs:
```
<start>
<info>
Package is Neofetch (minimal)
Version is 7.1.0
Dependancys are bash 3.2+ (minimal) 
<exec>
git clone https://github.com/dylanaraps/neofetch.git
cd neofetch
sudo make install
cd -
rm -rf neofetch
<end>
```
