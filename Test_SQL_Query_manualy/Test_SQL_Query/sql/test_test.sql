CREATE EXTENSION test;
CREATE TABLE asd( id SERIAL UNIQUE NOT NULL PRIMARY KEY,
				name VARCHAR (50));

insert into asd(
    name
)
select
    md5('test')
from generate_series(1, 1000) s(i);
SELECT * FROM get_smt('asd');
