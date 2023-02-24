#include <features.h>

#if defined(__GLIBC__) && __GLIBC__ == 2 && __GLIBC_MINOR__ <= 24

#ifndef __NR_getrandom
#include <errno.h>
#endif
#include <sys/syscall.h>
#include "random.h"

ssize_t getrandom(void *buffer, size_t length, unsigned int flags)
{
#ifdef __NR_getrandom
	return syscall(__NR_getrandom, buffer, length, flags);
#else
	/* For kernels that don't support getrandom() (< 3.17). */
	errno = ENOSYS;
	return -1;
#endif
}

#endif /* __GLIBC__ ... */
