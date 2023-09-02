#!/bin/sh

alias DATE="date '+%Y%m%d_%H%M'"

cd /usr/src
mkdir -p /logs_mfsbsd
time make buildworld -j12 \
        > /logs_mfsbsd/buildWorld_$(DATE).log 2>&1
time make buildkernel -j6 \
        >> /logs_mfsbsd/buildKernel_$(DATE).log 2>&1

cd ./release

COUNT=0
while [ $COUNT -lt 10 ]
do
    time make release WITH_MFSBSD=1 \
            > /logs_mfsbsd/release_$(DATE).log 2>&1

    mkdir -p ./images
    make install WITH_MFSBSD=1 DESTDIR=/usr/src/release/images \
            > /logs_mfsbsd/install_$(DATE).log 2>&1

    echo "--------------------------------------------------------------"
    echo "> Completed at $(DATE)"
    echo "--------------------------------------------------------------"

    make mfsbsd-clean

    COUNT=$(expr $COUNT + 1)
done
