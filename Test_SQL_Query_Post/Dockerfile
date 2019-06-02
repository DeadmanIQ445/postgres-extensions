FROM postgres
#libraries for testing
RUN  apt-get update && yes| apt-get install make && yes| apt-get install python-psycopg2 && apt-get install libpq-dev && yes | apt-get install postgresql-server-dev-all
COPY Test_SQL_Query /home/postgres/Test_SQL_Query

#Creating extension
RUN cd /home/postgres/Test_SQL_Query && make install

#To create root user annd grant him all permissions
COPY Test_SQL_Query/permissions.sql /docker-entrypoint-initdb.d/


