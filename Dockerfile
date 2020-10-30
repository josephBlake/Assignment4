#
# Alexander Blake
#
# DockerFile: create docker image for testing dateCalc code
#   - start with ubuntu 16:04, add g++ and GoogleTest
# Usage:
#   - create:
#       docker build ./

FROM ubuntu:18.04
# install build tools
RUN apt-get update; apt-get install -y g++ cmake git libgtest-dev
# set up GoogleTest
RUN cd /usr/src/gtest; cmake CMakeLists.txt; make; cp *.a /usr/lib
# copy code under test (current repo) into container
COPY . /dateCalc
# build the code and run tests
RUN cd /dateCalc; make clean; make test
