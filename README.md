# Shifty

## Installing on Linux
### Fedora
Currently there is a bug with the official dnf install that will cause a game to appear unresponsive (even though it isn't). So we must build and install it from the official git repo.

#### Dependencies
This probably isn't all the dependencies, but it is a good number of them.
```
sudo dnf install cmake freetype-devel libvorbis-devel flac-devel openal-soft-devel libudev-devel freeglut-devel libXrandr-devel libX11-devel
```
#### Download and install SFML:
```
git clone https://github.com/SFML/SFML.git
cd SFML
git checkout 2.4.x
cmake . && cmake --build .
sudo cmake --build . --target install
```
