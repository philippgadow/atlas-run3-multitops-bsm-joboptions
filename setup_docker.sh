#!/bin/bash

docker run -it --rm \
        -v /cvmfs:/cvmfs \
        -v $HOME:$HOME \
        -v $PWD:$PWD \
        -v $HOME/.globus:/home/atlas/.globus \
        -v /tmp/.X11-unix:/tmp/.X11-unix \
        -e DISPLAY=${DISPLAY} \
        -e RUCIO_ACCOUNT=$USER \
        -h ${HOSTNAME} \
        --workdir $PWD \
        atlas/centos7-atlasos-dev:latest
