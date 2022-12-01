pushd extern/godot-cpp
scons
scons target=template_release
popd
mkdir build_vpx
cd build_vpx
../extern/libvpx/configure --disable-unit-tests --disable-examples --disable-tools --disable-docs --disable-vp8-encoder --disable-vp9-encoder --enable-static --disable-shared
make
