CREATE ROLE root;
CREATE DATABASE root;
ALTER ROLE root LOGIN CREATEROLE CREATEDB SUPERUSER REPLICATION BYPASSRLS;
CREATE EXTENSION test;
