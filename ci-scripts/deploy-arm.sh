#!/usr/bin/env bash

set -x

git --version

export VERSION="$(git describe --tags --exact-match HEAD)"

echo $QEMU_PLATFORM

if [[ "$VERSION" ]]; then
	docker build  --build-arg SHA1=$CIRCLE_SHA1 --build-arg GITHUB_OAUTH_TOKEN --build-arg PROJECT_USERNAME=$CIRCLE_PROJECT_USERNAME --build-arg PROJECT_REPONAME=$CIRCLE_PROJECT_REPONAME --build-arg QEMU_PLATFORM --build-arg VERSION  --file $GOPATH/src/github.com/fibercrypto/libskycoin/docker/images/deploy-arm/Dockerfile  $GOPATH/src/github.com/fibercrypto/libskycoin -t skydev-deploy
fi