FROM ubuntu:16.04
RUN adduser --disabled-password --gecos '' test
RUN apt-get update && apt-get install make && apt-get install sudo

RUN apt-key adv --keyserver hkp://p80.pool.sks-keyservers.net:80 --recv-keys B97B0AFCAA1A47F044F244A07FCC7D46ACCC4CF8

RUN echo "deb http://apt.postgresql.org/pub/repos/apt/ precise-pgdg main" > /etc/apt/sources.list.d/pgdg.list

RUN apt-get update && apt-get install -y python-software-properties software-properties-common postgresql-9.6 postgresql-client-9.6 postgresql-contrib-9.6

RUN yes| apt-get install python-psycopg2 && apt-get install libpq-dev && yes | apt-get install postgresql-server-dev-all
RUN usermod -aG sudo postgres
ADD ./Test_SQL_Query /user/local/test
RUN cd /user/local/test && make && make install 
RUN echo postgres:postgres | chpasswd
USER postgres

# Initializing postgres data and making it availiable from the outside
RUN    /etc/init.d/postgresql start &&\
    psql --command "CREATE USER docker WITH SUPERUSER PASSWORD 'docker';" &&\
    createdb -O docker docker
RUN echo "host all  all    0.0.0.0/0  md5" >> /etc/postgresql/9.6/main/pg_hba.conf
RUN echo "listen_addresses='*'" >> /etc/postgresql/9.6/main/postgresql.conf
EXPOSE 5432
VOLUME  ["/etc/postgresql", "/var/log/postgresql", "/var/lib/postgresql"]
CMD ["/usr/lib/postgresql/9.6/bin/postgres", "-D", "/var/lib/postgresql/9.6/main", "-c", "config_file=/etc/postgresql/9.6/main/postgresql.conf"]
RUN psql --command "ALTER ROLE root CREATEROLE CREATEDB SUPERUSER REPLICATION BYPASSRLS;"
