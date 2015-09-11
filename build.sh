#!/bin/bash -e

REPO_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
BUILD_FOLDER=$REPO_DIR/build

echo REPO_DIR=$REPO_DIR
echo BUILD_FOLDER=$BUILD_FOLDER

mkdir -p $BUILD_FOLDER
pushd $BUILD_FOLDER
qmake $REPO_DIR
make
popd
