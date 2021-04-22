#!/bin/sh

git clone https://github.com/junaidrahim/locate-route
cd locate-route
mkdir build
cd build
cmake ..
make
echo "Moving locate_route binary to /usr/bin"
sudo mv locate_route /usr/bin/ 
cd ../.. 
echo "Cleaning Up"
rm -rf locate-route


