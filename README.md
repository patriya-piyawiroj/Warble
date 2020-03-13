# csci499_patriya-piyawiroj

## Environment
Using Vagrant box: ubuntu/bionic64

## Install prerequisites
```
sudo apt-get update
sudo apt-get install build-essential autoconf libtool pkg-config
sudo apt-get install golang
sudo apt-get install make
sudo apt-get install cmake
sudo apt-get upgrade
```

## Install third-party
```
cd third_party
git clone -b $(curl -L https://grpc.io/release) https://github.com/grpc/grpc

# install grpc
cd grpc
git submodule update --init
cmake .
make
sudo make install

#install protobuf
cd third_party/protobuf
sudo make install
```

install pacakges
```
# google test
cd third_party/googletest
cmake .
make
sudo make install

# gflags
cd third_party/gflags
cmake .
make
sudo make install
```

## Make files
