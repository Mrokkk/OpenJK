#include <map>
#include <string>
#include <algorithm>

#include "server/exe_headers.h"

#include "ui_local.h"
#include "ui_shared.h"
#include "ui_layout.h"
#include "menudef.h"

using constantsMap_t = std::map<std::string, std::string>;

constantsMap_t constants;

void Constant_Set(const char *name, const char *value)
{
	constants[name] = std::string(value);
}

qboolean Constant_GetString(const char *name, const char **value)
{
	auto it = constants.find(name);

	if (it == constants.end())
	{
		return qfalse;
	}

	*value = it->second.c_str();

	return qtrue;
}

qboolean Constant_GetInt(const char *name, int *value)
{
	const char *string;

	if (!Constant_GetString(name, &string))
	{
		return qfalse;
	}

	*value = atoi(string);

	return qtrue;
}

qboolean Constant_GetFloat(const char *name, float *value)
{
	const char *string;

	if (!Constant_GetString(name, &string))
	{
		return qfalse;
	}

	*value = atof(string);

	return qtrue;
}

// vim: set noexpandtab tabstop=4 shiftwidth=4 :
