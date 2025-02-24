FROM debian:buster

RUN apt-get update && apt-get install -y mariadb-server tini net-tools

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./tools/init_db.sh /var/www/init_db.sh
RUN chmod +x /var/www/init_db.sh

RUN mkdir -p /var/run/mysqld
RUN chown -R mysql:mysql /var/run/mysqld
ENTRYPOINT [ "/usr/bin/tini", "--", "/var/www/init_db.sh" ]

EXPOSE 3306

CMD ["mysql"]
