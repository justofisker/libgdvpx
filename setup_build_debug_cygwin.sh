pushd extern/godot-cpp
echo env.Append(ENV = os.environ) >> SConstruct
scons use-mingw=yes
popd
mkdir build_vpx
pushd build_vpx
../extern/libvpx/configure --disable-unit-tests --disable-examples --disable-tools --disable-docs --disable-vp8-encoder --disable-vp9-encoder --enable-static --disable-shared
make
popd
mkdir build
pushd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
popd
