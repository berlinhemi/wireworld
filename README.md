## About
Program that visualizes a Cellular Automata simulation similar Wireworld
## Build 
```sh
mkdir build
cd build
cmake ..
make
```
## Run
```sh
./wireworld --steps=20 --timeout=1 maps/map_small.txt
./wireworld --steps=30 --timeout=0.5 --random maps/map_or.txt
```
