#---------------------------------------------------------------------------------------------------
# Dockerfile to Sniper Simulator
#---------------------------------------------------------------------------------------------------
# Operation System: Ubuntu 20.04
# Sniper Simulator: 7.3
# Benchmarks: Splash2, Parsec 2.1, SPEC CPU2006 and SPEC CPU2017
#
# @author: Kleber Kruger - UNICAMP (Licensed under the MIT License).
#---------------------------------------------------------------------------------------------------

FROM ubuntu:20.04

# Add i386 support for support for Pin
RUN dpkg --add-architecture i386

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive \
    apt-get install -y \
    #
    # For i386 support
    python \
    screen \
    tmux \
    binutils \
    libc6:i386 \
    libncurses5:i386 \
    libstdc++6:i386 \
    #
    # For building Sniper
    automake \
    build-essential \
    curl \
    wget \
    libboost-dev \
    libsqlite3-dev \
    zlib1g-dev \
    libbz2-dev \
    g++-7 \
    # g++-4.8 \
    #
    # For building RISC-V Tools
    autoconf \
    automake \
    autotools-dev \
    bc \
    bison \
    curl \
    device-tree-compiler \
    flex \
    gawk \
    gperf \
    libexpat-dev \
    libgmp-dev \
    libmpc-dev \
    libmpfr-dev \
    libtool \
    libusb-1.0-0-dev \
    patchutils \
    pkg-config \
    texinfo \
    zlib1g-dev \
    #
    # Helper utilities
    gdb \
    git \
    # xz-utils \
    doxygen \
    #
    # For install Python 3
    python3 \
    python3-pip \
    python3-dev \
    #
    # For build benchmarks
    gfortran \
    xsltproc \
    gettext \
    libx11-dev \
    libxext-dev \
    libxt-dev \
    libxmu-dev \
    libxi-dev \
    #
    # Clean up
    && apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

# Install python libraries
RUN pip3 --disable-pip-version-check --no-cache-dir install \
    numpy \
    matplotlib

# Create an user non-root
ARG USERNAME=kleberkruger
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Create the user
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    #
    # [Optional] Add sudo support. Omit if you don't need to install software after connecting.
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME \
    #
    # Clean up
    && apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

# [Optional] Set the default user. Omit if you want to keep the default as root.
USER $USERNAME
