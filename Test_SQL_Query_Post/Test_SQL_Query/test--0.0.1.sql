--complain if script script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION test" to load this file. \quit
CREATE OR REPLACE FUNCTION get_smt(input text)
RETURNS TABLE (id INT, name VARCHAR)
LANGUAGE plpgsql IMMUTABLE STRICT
	AS $$
		BEGIN
			RETURN QUERY EXECUTE format('SELECT * FROM %I', input);
		END;
    $$;
