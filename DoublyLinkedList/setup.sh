rm -rf googletest
sudo apt-get update
sudo apt-get install -y libpthread-stubs0-dev libpthread-workqueue-dev
git clone https://github.com/google/googletest.git
cd googletest/googletest
cmake ..
make