FROM debian:jessie
MAINTAINER pavik - https://github.com/pavik

ENV TUNEZ_USER=tunez

ENV TUNEZ_URL_LATEST=https://github.com/TunezCoinNG/TunezCoinNG/releases/latest \
 TUNEZ_URL_DOWNLOAD=https://github.com/TunezCoinNG/TunezCoinNG/releases/download \
 TUNEZ_CONF=/home/$TUNEZ_USER/.TunezNG/TunezNG.conf

RUN apt-get -qq update && \
apt-get install -yq wget ca-certificates pwgen curl && \
rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* && \
export TUNEZ_URL=`curl -Ls -o /dev/null -w %{url_effective} $TUNEZ_URL_LATEST` && \
export TUNEZ_VERSION=`echo $TUNEZ_URL | grep -oP 'tag\/v(.+?)$' | sed -E 's/tag\/v//'` && \
wget $TUNEZ_URL_DOWNLOAD/v$TUNEZ_VERSION/tunez-$TUNEZ_VERSION-x86_64-linux-gnu.tar.gz -O /tmp/tunez.tar.gz && \
mkdir -p /opt && \
cd /opt && \
tar xvzf /tmp/tunez.tar.gz && \
rm /tmp/tunez.tar.gz && \
ln -sf tunez-$TUNEZ_VERSION tunez && \
ln -sf /opt/tunez/bin/tunezd /usr/local/bin/tunezd && \
ln -sf /opt/tunez/bin/tunez-cli /usr/local/bin/tunez-cli && \
ln -sf /opt/tunez/bin/tunez-tx /usr/local/bin/tunez-tx && \
adduser --uid 1000 --system ${TUNEZ_USER} && \
mkdir -p /home/${TUNEZ_USER}/.TunezNG/ && \
chown -R ${TUNEZ_USER} /home/${TUNEZ_USER} && \
echo "success: $TUNEZ_CONF"

USER tunez
RUN printf "listen=1\nserver=1\ntxindex=1\nrpcuser=*Your\$Username*\nrpcpassword=*Your\$Password*\nrpcport=16413\nport=16511\nrpcallowip=127.0.0.1\n" > $TUNEZ_CONF && \
    sed -i -e 's/\*Your$Username\*/tunez/g' ${TUNEZ_CONF} && \
    sed -i -e 's/\*Your$Password\*/'`pwgen 32 1`'/g' ${TUNEZ_CONF} && \
    echo "success"

EXPOSE 16511
VOLUME ["/home/tunez/.TunezNG"]
WORKDIR /home/tunez

ENTRYPOINT ["/usr/local/bin/tunezd"]