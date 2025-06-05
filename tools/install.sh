#!/bin/sh
set -e

echo "This script installs beh (Better feh)"
git clone https://github.com/ManiProjs/beh.git /tmp/behrepo-65c3ve

cd /tmp/behrepo-65c3ve
cmake -S . -B build
cd build
if [ -e "Makefile" ]; then
    make
else if [ -e "build.ninja" ]; then
    ninja
fi

cp /tmp/behrepo-65c3ve/build/beh ~/.local/bin

echo "Done! beh is now installed."
