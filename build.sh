mkdir -p ./build

cd ./build

cmake ../perf_sleep/

make install

# mamba deactivate