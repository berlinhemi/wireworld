# About
Program that visualizes a Cellular Automata simulation similar Wireworld
# Build 
mkdir build
cd build
cmake ..
make
# Run
./wireworld --steps=20 --timeout=1 maps/map_small.txt
./wireworld --steps=30 --timeout=0.5 --random maps/map_or.txt
