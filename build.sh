rm -rf build
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/Users/Shared/libs -DBUILD_SHARED_LIBS=OFF
cmake --build ./ --config Release
cmake --install ./
cd ..