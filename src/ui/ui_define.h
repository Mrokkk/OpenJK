#ifndef __UI_DEFINE_H
#define __UI_DEFINE_H

#include "ui_shared.h"

void Constant_Set(const char *name, const char *value);
qboolean Constant_GetString(const char *name, const char **value);
qboolean Constant_GetInt(const char *name, int *value);
qboolean Constant_GetFloat(const char *name, float *value);

#endif
