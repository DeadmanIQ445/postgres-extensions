FROM postgres
#libraries for testing
RUN  apt-get update && yes| apt-get install make && yes| apt-get install python-psycopg2 && apt-get install libpq-dev && yes | apt-get install postgresql-server-dev-all 
RUN yes | apt-get install libicu-dev
RUN yes | apt-get install gcc

COPY BOW_Index /home/postgres/BOW_Index

#Creating extension
RUN cd /home/postgres/BOW_Index && make install && cp *.stop $(pg_config --sharedir)/tsearch_data

#To create root user annd grant him all permissions
COPY BOW_Index/permissions.sql /docker-entrypoint-initdb.d/


