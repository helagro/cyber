
# ------------------------ BUILD STAGE ----------------------- #

# Pulls ubuntu 22.04 image, names it to builder
FROM ubuntu:22.04 as builder 

# Updates and upgrades packages. -y flag means yes to all prompts
RUN apt-get update -y && \
    apt-get upgrade -y 

# Installs cmake and build-essential packages, without recommended packages
RUN apt-get install -y --no-install-recommends \
    cmake \
    build-essential

# Copies the current directory to /opt/sources
ADD . /opt/sources

# Creates build directory
RUN mkdir /opt/sources/build

# Sets the working directory to the build directory
WORKDIR /opt/sources/build

# Builds project with cmake, makes the project, runs tests
RUN cmake -D CMAKE_BUILD_TYPE=Release .. && \
    make && \
    make test

# Strips the binary
RUN strip -s helloworld 

# ----------------------- BUNDLE STAGE ----------------------- #

# Pulls scratch image, which is an empty image
FROM scratch

# Copies the binary from the builder stage to the scratch image
COPY --from=builder /opt/sources/build/helloworld /

# Sets the entrypoint to the binary
ENTRYPOINT ["/helloworld"]