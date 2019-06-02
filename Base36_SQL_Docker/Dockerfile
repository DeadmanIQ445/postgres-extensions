FROM postgres
#libraries for testing
RUN  apt-get update && yes| apt-get install make && yes| apt-get install python-psycopg2 && apt-get install libpq-dev && yes | apt-get install postgresql-server-dev-all
COPY Base36_SQL /home/postgres/base36

#Creating extension
RUN cd /home/postgres/base36 && make install

#To create root user annd grant him all permissions
COPY Base36_SQL/permissions.sql /docker-entrypoint-initdb.d/


