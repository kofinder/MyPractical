/*
 * POSIX I/O, Memory, and Real-Time Feature Macros:
 *
 * _POSIX_FSYNC
 *     Support for fsync() and fdatasync() to ensure data is flushed
 *     to storage — important for databases and reliable I/O.
 *
 * _POSIX_MEMLOCK
 *     Ability to lock all process memory into RAM using mlockall(),
 *     preventing paging for real-time or latency-sensitive apps.
 *
 * _POSIX_MEMLOCK_RANGE
 *     Ability to lock specific memory ranges using mlock() and munlock(),
 *     useful for protecting critical buffers without locking all memory.
 *
 * _POSIX_MESSAGE_PASSING
 *     POSIX message queues (mq_open, mq_send, mq_receive) for
 *     standardized inter-process communication.
 *
 * _POSIX_PRIORITIZED_IO
 *     Support for prioritized asynchronous I/O (lio_listio),
 *     allowing I/O requests to have priority levels.
 *
 * _POSIX_PRIORITY_SCHEDULING
 *     Real-time scheduling policies (SCHED_FIFO, SCHED_RR) for threads
 *     and processes to control execution priority.
 *
 * _POSIX_SHARED_MEMORY_OBJECTS
 *     Shared memory objects (shm_open + mmap) for inter-process communication.
 *
 * _POSIX_SYNCHRONIZED_IO
 *     Guarantees that writes are synchronized with storage,
 *     ensuring reliable I/O operations.
 */


#define _POSIX_C_SOURCE 200809L   // request POSIX.1-2008 features

#include <stdio.h>
#include <unistd.h>

struct posix_check {
    const char *name;
    long macro_value;  // -1 if not defined
    int sc;            // corresponding _SC_* constant for sysconf, or -1 if none
};

int main(void) {
    struct posix_check checks[] = {
#ifdef _POSIX_FSYNC
        {"_POSIX_FSYNC", _POSIX_FSYNC, _SC_FSYNC},
#else
        {"_POSIX_FSYNC", -1, _SC_FSYNC},
#endif
#ifdef _POSIX_MEMLOCK
        {"_POSIX_MEMLOCK", _POSIX_MEMLOCK, _SC_MEMLOCK},
#else
        {"_POSIX_MEMLOCK", -1, _SC_MEMLOCK},
#endif
#ifdef _POSIX_MEMLOCK_RANGE
        {"_POSIX_MEMLOCK_RANGE", _POSIX_MEMLOCK_RANGE, _SC_MEMLOCK_RANGE},
#else
        {"_POSIX_MEMLOCK_RANGE", -1, _SC_MEMLOCK_RANGE},
#endif
#ifdef _POSIX_MESSAGE_PASSING
        {"_POSIX_MESSAGE_PASSING", _POSIX_MESSAGE_PASSING, _SC_MESSAGE_PASSING},
#else
        {"_POSIX_MESSAGE_PASSING", -1, _SC_MESSAGE_PASSING},
#endif
#ifdef _POSIX_PRIORITIZED_IO
        {"_POSIX_PRIORITIZED_IO", _POSIX_PRIORITIZED_IO, _SC_PRIORITIZED_IO},
#else
        {"_POSIX_PRIORITIZED_IO", -1, _SC_PRIORITIZED_IO},
#endif
#ifdef _POSIX_PRIORITY_SCHEDULING
        {"_POSIX_PRIORITY_SCHEDULING", _POSIX_PRIORITY_SCHEDULING, _SC_PRIORITY_SCHEDULING},
#else
        {"_POSIX_PRIORITY_SCHEDULING", -1, _SC_PRIORITY_SCHEDULING},
#endif
#ifdef _POSIX_SHARED_MEMORY_OBJECTS
        {"_POSIX_SHARED_MEMORY_OBJECTS", _POSIX_SHARED_MEMORY_OBJECTS, _SC_SHARED_MEMORY_OBJECTS},
#else
        {"_POSIX_SHARED_MEMORY_OBJECTS", -1, _SC_SHARED_MEMORY_OBJECTS},
#endif
#ifdef _POSIX_SYNCHRONIZED_IO
        {"_POSIX_SYNCHRONIZED_IO", _POSIX_SYNCHRONIZED_IO, _SC_SYNCHRONIZED_IO},
#else
        {"_POSIX_SYNCHRONIZED_IO", -1, _SC_SYNCHRONIZED_IO},
#endif
    };

    size_t n = sizeof(checks) / sizeof(checks[0]);

    for (size_t i = 0; i < n; i++) {
        printf("%s: ", checks[i].name);

        if (checks[i].macro_value != -1)
            printf("compile-time = %ld; ", checks[i].macro_value);
        else
            printf("compile-time = (not defined); ");

        long r = sysconf(checks[i].sc);
        if (r == -1)
            printf("runtime = not supported\n");
        else
            printf("runtime = %ld\n", r);
    }

    return 0;
}
