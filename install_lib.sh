#in csci499_patriya-piyawiroj/third_party
cd third_party
git clone https://github.com/google/glog.git
./autogen.sh
./configure
make
sudo make install
