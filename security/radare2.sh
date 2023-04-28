#!/bin/sh
#
#  Install radare2 on fedora
#  All tks to my friend Neriberto (@neriberto)[https://github.com/neriberto]
#

R2_VERSION=master

# R2pipe python version
R2_PIPE_PY_VERSION=0.8.9

# R2pipe node version
R2_PIPE_NPM_VERSION=2.3.2

mkdir -p ~/radare_install && cd ~/radare_install

dpkg --add-architecture i386 && \
    dnf update && \
    dnf install -y \
    curl \
    gcc \
    git \
    bison \
    pkg-config \
    make \
    glib \
    npm \
    glibc \
    ncurses-devel \
    libstdc++ \
    gnupg2 \
    sudo && \
    dnf install -y nodejs python-pip && \
    pip install r2pipe=="$R2_PIPE_PY_VERSION" && \
    npm install --unsafe-perm -g "r2pipe@$R2_PIPE_NPM_VERSION" && \
    cd /mnt && \
    git clone -b "$R2_VERSION" --depth 1 https://github.com/radare/radare2.git && \
    cd radare2 && \
    ./sys/install.sh && \
    make install && \
    dnf install -y ghc-lzma-conduit && \
    dnf remove -y \
    bison \
    glib && \
    dnf autoremove -y && \
    dnf clean all && rm -rf /tmp/* /var/tmp/*
