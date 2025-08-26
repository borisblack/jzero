FROM ubuntu:22.04

# Update and install
RUN apt-get update -y && DEBIAN_FRONTEND=noninteractive apt-get install -y sudo locales vim mc build-essential \
    libicu-dev gdb pkg-config git libreadline-dev zlib1g-dev flex bison graphviz cmake ninja-build

# Set locale
ENV LANGUAGE=en_US.UTF-8
ENV LANG=en_US.UTF-8
ENV LC_ALL=en_US.UTF-8
ENV TZ=Asia/Krasnoyarsk
ENV DEBIAN_FRONTEND=noninteractive
RUN locale-gen en_US.UTF-8
# RUN git config --global core.autocrlf false

# Add users
RUN useradd -m -d /home/developer -s /bin/bash developer \
    && echo developer:master | chpasswd \
    && usermod -a -G sudo developer \
    && echo developer ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/developer

ENTRYPOINT ["tail", "-f", "/dev/null"]
