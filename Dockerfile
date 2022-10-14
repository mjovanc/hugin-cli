FROM ubuntu:22.04

COPY . /usr/src/hugin
WORKDIR /usr/src/hugin

# install build dependencies
RUN apt-get update && \
    apt-get install -y \
      build-essential \
      libssl-dev \
      libffi-dev \
      python3-dev \
      gcc-11 \
      g++-11 \
      git \
      cmake

# create the build directory
RUN mkdir build
WORKDIR /usr/src/hugin/build

# build and install
RUN cmake .. && make

WORKDIR /usr/src/hugin/build

# set executable permission on kryptokrona deamon
RUN chmod +x Hugin

CMD [ "/bin/sh", "-c", "./Hugin" ]