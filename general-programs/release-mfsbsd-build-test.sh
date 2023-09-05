#!/bin/sh

alias DATE="date '+%Y%m%d_%H%M'"
mkdir -p /logs_mfsbsd

#
# TESTING mfsBSD BUILD (release.sh)
#
cd /usr/src/release
cat ./release.conf.sample | sed \
	-e 's/GITROOT="https:\/\/git.freebsd.org\/"/GITROOT="https:\/\/github.com\/soobinrho\/"/g' \
	-e 's/GITSRC="src.git"/GITSRC="freebsd-src.git"/g' \
	-e 's/GITPORTS="ports.git"/GITPORTS="freebsd-ports.git"/g' \
	-e 's/SRCBRANCH="main"/SRCBRANCH="integrate-mfsBSD-building"/g' \
	-e 's/#WITH_MFSBSD=/WITH_MFSBSD=1/g' \
	> ./release.conf

./release.sh -c ./release.conf \
    > /logs_mfsbsd/release_sh_build_$(DATE).log 2>&1

echo "--------------------------------------------------------------"
echo "> Type: mfsBSD build (release.sh)"
echo "> Completed Time: $(DATE)"
echo "--------------------------------------------------------------"

ls -lh /scratch/R/mfsbsdimages
