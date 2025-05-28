#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define Q_UNLIKELY(x) __builtin_expect(!!(x), 0)

#ifndef OPENJO_NONFATAL_ASSERT
__attribute__((noreturn))
#endif
void Q_assert_fail(const char *file, const char *function, int line, const char *message);

#define Q_assert(cond) \
	((Q_UNLIKELY(!(cond))) \
		? Q_assert_fail(__FILE__, __FUNCTION__, __LINE__, #cond) \
		: (void)0)

#ifdef __cplusplus
}
#endif

// vim: set noexpandtab tabstop=4 shiftwidth=4 :
