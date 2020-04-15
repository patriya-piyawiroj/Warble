cd third_party
git clone -b $(curl -L https://grpc.io/release) https://github.com/grpc/grpc

# install grpc
cd grpc
git submodule update --init
make
sudo make install

# install protobuf
# in grpc root dir
cmake .

cd third_party/protobuf
sudo make install

# install submodule dependency
git submodule init
git submodule update

# google test
cd ../googletest
cmake .
make
sudo make install

# gflags
cd ../gflags
cmake .
make
sudo make install

# in grpc root dir
cd ../../..
sudo cmake .
make
