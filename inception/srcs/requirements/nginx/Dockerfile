FROM debian:buster

RUN apt-get update && apt-get install -y nginx openssl tini

RUN mkdir -p /etc/nginx/ssl && \
    openssl req -x509 -nodes -days 365 -newkey rsa:4096 \
    -keyout /etc/nginx/ssl/hyeonwch.key \
    -out /etc/nginx/ssl/hyeonwch.crt \
    -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=42/CN=hyeonwch.42.fr" && \
    chown www-data:www-data \
    /etc/nginx/ssl/hyeonwch.key \
    /etc/nginx/ssl/hyeonwch.crt

COPY conf/nginx.conf /etc/nginx/conf.d/default.conf

RUN mkdir -p /run/nginx

EXPOSE 443

# tini를 컨테이너의 시작점으로 설정 (좀비 프로세스 방지)
ENTRYPOINT ["/usr/bin/tini", "--"]

CMD ["nginx", "-g", "daemon off;"]
