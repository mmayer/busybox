#ifndef _RANDOM_H
#define _RANDOM_H 1

#include <features.h>
#include <sys/types.h>

#ifndef GRND_NONBLOCK
#define GRND_NONBLOCK 0x01
#endif
#ifndef GRND_RANDOM
#define GRND_RANDOM 0x02
#endif
#ifndef GRND_INSECURE
#define GRND_INSECURE 0x04
#endif

ssize_t getrandom(void *buffer, size_t length, unsigned int flags);

#endif /* _RANDOM_H */
