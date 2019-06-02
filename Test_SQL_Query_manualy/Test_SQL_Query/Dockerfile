FROM postgres
RUN  apt-get update && yes| apt-get install python-psycopg2 && apt-get install libpq-dev && yes | apt-get install postgresql-server-dev-all
COPY ./Test_SQL_Query /home/postgres/
COPY test.control /usr/share/postgresql/11/extension
COPY test--0.0.1.sql /usr/share/postgresql/11/extension
