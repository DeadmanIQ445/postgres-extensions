EXTENSION = base36        # the extensions name
DATA = base36--0.0.1.sql  # script files to install
REGRESS = base36_test     # our test script file (without extension)
MODULES = base36          # our c module file to build

# postgres build stuff
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
