#include "postgres.h"

#include "commands/defrem.h"
#include "tsearch/ts_locale.h"
#include "tsearch/ts_utils.h"
#include "utils/builtins.h"

#include "fmgr.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif


typedef struct
{
	StopList	stoplist;
} DictRvSL;

PG_FUNCTION_INFO_V1(drsl_init);

Datum 
drsl_init(PG_FUNCTION_ARGS)
{
	List	   *dictoptions = (List *) PG_GETARG_POINTER(0);
	DictRvSL *d = (DictRvSL *) palloc0(sizeof(DictRvSL));
	bool		stoploaded = false;
	ListCell   *l;

	foreach(l, dictoptions)
	{
		DefElem    *defel = (DefElem *) lfirst(l);

		if (strcmp(defel->defname, "stopwords") == 0)
		{
			if (stoploaded)
				ereport(ERROR,
						(errcode(ERRCODE_INVALID_PARAMETER_VALUE),
						 errmsg("multiple StopWords parameters")));
			readstoplist(defGetString(defel), &d->stoplist, lowerstr);
			stoploaded = true;
		}
		else
		{
			ereport(ERROR,
					(errcode(ERRCODE_INVALID_PARAMETER_VALUE),
					 errmsg("unrecognized simple dictionary parameter: \"%s\"",
							defel->defname)));
		}
	}

	PG_RETURN_POINTER(d);
}
PG_FUNCTION_INFO_V1(drsl_lexize);

Datum 
drsl_lexize(PG_FUNCTION_ARGS)
{
	DictRvSL *d = (DictRvSL *) PG_GETARG_POINTER(0);
	char	   *in = (char *) PG_GETARG_POINTER(1);
	int32		len = PG_GETARG_INT32(2);
	char	   *txt;
	TSLexeme   *res;

	txt = lowerstr_with_len(in, len);


	if (searchstoplist(&(d->stoplist), txt))
	{
		/* accept */
		res = palloc0(sizeof(TSLexeme) * 2);
		res[0].lexeme = txt;
		PG_RETURN_POINTER(res);
	}
	else	{
		/* reject  */
		pfree(txt);
		res = palloc0(sizeof(TSLexeme) * 2);
		PG_RETURN_POINTER(res);
	}
}