#include "q_assert.h"

#include <stdlib.h>

#include "qcommon/q_color.h"
#include "qcommon/qcommon.h"

void Q_assert_fail(const char *file, const char *function, int line, const char *message)
{
	Com_Printf(S_COLOR_YELLOW "%s:%u: %s: assertion `%s\' failed\n", file, line, function, message);
#ifdef OPENJO_NONFATAL_ASSERT
#ifdef OPENJO_NONFATAL_ASSERT_STACKTRACE
	Sys_StacktraceDump();
#endif
#else
	abort();
#endif
}

// vim: set noexpandtab tabstop=4 shiftwidth=4 :
