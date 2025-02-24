FROM debian:bullseye

RUN apt update -yq && \
    apt upgrade -yq && \
	apt-get install -yq apt-transport-https lsb-release ca-certificates wget gnupg && \
    apt install -yq php7.4 && \
	apt install -yq php7.4-mysql && \
	apt install -yq php7.4-cli && \
	apt install -yq php7.4-mbstring && \
	apt install -yq php7.4-fpm && \
	apt install -yq php7.4-gettext && \
	apt install -yq mariadb-client && \
	apt install -yq wget && \
    rm -rf /etc/php/7.4/fpm/pool.d/www.conf && \
    mkdir -p /run/php

# WordPress 설치
COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/
COPY ./tools/wp-setup.sh /usr/local/bin/wp-setup.sh
RUN chmod +x /usr/local/bin/wp-setup.sh

ENTRYPOINT ["wp-setup.sh"]

CMD ["php-fpm7.4", "-F"]
