# postgres-extensions

Test_SQL_Query and Dockerfile here are working together and here docker image is created based on ubuntu and almost everything initialized manualy

Test_SQL_Query_Post is basicaly the same thing, but there docker image is based on postgres image, so no database initializtion required, that is why it looks smaller and nicer.

Test_SQL_Query_Post is major version.

If you look deeper, then it is easy to notice that basicaly what my images do is run makefile, so basicaly I am just emulating steps that I would normally do on ubuntu (no wonder, those docker images are based on ubuntu). That is why there is no separate version to run on my machine, it is the same as for docker.
