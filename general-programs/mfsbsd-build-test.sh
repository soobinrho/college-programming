#!/bin/sh

alias DATE="date '+%Y%m%d_%H%M'"
mkdir -p /logs_mfsbsd

#
# TESTING BUILD INTERFACE 1
#
cd /usr/src/release
make mfsbsd-se-img mfsbsd-se-iso \
    > /logs_mfsbsd/interface1_build_$(DATE).log 2>&1

echo "--------------------------------------------------------------"
echo "> Type: mfsBSD build"
echo "> Completed Time: $(DATE)"
echo "--------------------------------------------------------------"

ls -lh /usr/obj/usr/src/amd64.amd64/release/mfsbsd*

#
# Clean up.
#
make clean > /dev/null
cd /usr/src && make clean > /dev/null

#
# TESTING BUILD INTERFACE 2
#
cd /usr/src
time make buildworld -j12 \
        > /logs_mfsbsd/interface2_buildWorld_$(DATE).log 2>&1
time make buildkernel -j6 \
        > /logs_mfsbsd/interface2_buildKernel_$(DATE).log 2>&1

cd ./release
COUNT=0
while [ $COUNT -lt 10 ]
do
    time make obj release WITH_MFSBSD=1 \
            > /logs_mfsbsd/interface2_release_$(DATE).log 2>&1

    mkdir -p ./images
    make install WITH_MFSBSD=1 DESTDIR=/usr/src/release/images \
            > /logs_mfsbsd/interface2_install_$(DATE).log 2>&1

    echo "--------------------------------------------------------------"
    echo "> Type: mfsBSD build alongside all release artifacts"
    echo "> Completed Time: $(DATE)"
    echo "--------------------------------------------------------------"

    ls -lh /usr/src/release/images/mfsbsdimages/
    make mfsbsd-clean > /dev/null

    COUNT=$(expr $COUNT + 1)
done

# The main difference between INTERFACE 1 and INTERFACE 2
# is that the first one doesn't create any other release artifacts
# other than the ones required by mfsBSD itself.
#
# INTERFACE 1 creates mfsBSD images by invokding `mfsbsd/Makefile`
# with the `CUSTOM=1 BUILDWORLD=1 BUILDKERNEL=1` flags.
#
# INTERFACE 2 builds mfsBSD and every other FreeBSD installation media,
# including cdrom, dvdrom, memstick, and mini-memstick.
