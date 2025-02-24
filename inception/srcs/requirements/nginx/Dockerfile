FROM debian:bullseye

RUN apt-get update && apt-get install -y niginx openssl

# SSL 설정
RUN mkdir -p /etc/niginx/ssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/niginx/ssl/nginx.key \
    -out /etc/niginx/ssl/nginx.crt \
    -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=42/CN=login.42.fr"

COPY conf/niginx.conf /etc/niginx/conf.d/default/conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
