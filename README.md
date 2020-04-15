# csci499_patriya-piyawiroj

## Environment
Using Vagrant box: ubuntu/bionic64 (virtualbox, 20190109.0.0)

## Install prerequisites
```
sudo apt-get update
sudo apt-get install build-essential autoconf libtool pkg-config
sudo apt-get install golang
sudo apt-get install make
sudo apt-get install cmake
sudo apt-get install software-properties-common
sudo add-apt-repository ppa:george-edison55/cmake-3.x
sudo apt-get install libgflags-dev
sudo apt-get install libunwind-dev
sudo apt-get upgrade
```

## Install third-parties
```
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
```

install pacakges
```
# google test
cd ../../third_party/googletest
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
```

```
# in csci499_patriya-piyawiroj/third_party
git clone https://github.com/google/glog.git
./autogen.sh
./configure
make
sudo make install
```

## Make files

```
# At root directory, will compile subdirectories
cmake .
make
```

## Phase 1 Notes:
In /warble: run ./warble followed by arguments<br />
In /store: run ./key_value_store_server to start server <br />
]
