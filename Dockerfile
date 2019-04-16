ARG OS_EMU
ARG HW_EMU
FROM balenalib/${HW_EMU}-${OS_EMU}-golang
ADD . $GOPATH/src/github.com/skycoin/libskycoin/

RUN [ "cross-build-start" ]
ARG OS-EMU
RUN sh $GOPATH/src/github.com/skycoin/libskycoin/ci-scripts/docker_install_${OS-EMU}
RUN go get github.com/gz-c/gox
RUN go get -t ./...
ENV CGO_ENABLED=1
RUN cd $GOPATH/src/github.com/skycoin/libskycoin && make clean-libc
RUN cd $GOPATH/src/github.com/skycoin/libskycoin && make install-deps-libc-linux
RUN cd $GOPATH/src/github.com/skycoin/libskycoin && make test-libc 

RUN [ "cross-build-end" ]  

WORKDIR $GOPATH/src/github.com/skycoin

VOLUME $GOPATH/src/