#define _POSIX_C_SOURCE 200809L   // request POSIX.1-2008 features

#include <stdio.h>
#include <unistd.h>

struct feature_check {
    const char *name;
    long macro_value;  // -1 if not defined
    int sc;            // corresponding _SC_* constant for sysconf, or -1 if none
};

int main(void) {
    struct feature_check features[] = {
        /* Job control / shell features */
#ifdef _POSIX_JOB_CONTROL
        {"_POSIX_JOB_CONTROL", _POSIX_JOB_CONTROL, -1},
#else
        {"_POSIX_JOB_CONTROL", -1, -1},
#endif
#ifdef _POSIX_SAVED_IDS
        {"_POSIX_SAVED_IDS", _POSIX_SAVED_IDS, -1},
#else
        {"_POSIX_SAVED_IDS", -1, -1},
#endif
#ifdef _POSIX_REGEXP
        {"_POSIX_REGEXP", _POSIX_REGEXP, -1},
#else
        {"_POSIX_REGEXP", -1, -1},
#endif
#ifdef _POSIX_SHELL
        {"_POSIX_SHELL", _POSIX_SHELL, -1},
#else
        {"_POSIX_SHELL", -1, -1},
#endif
#ifdef _POSIX_VDISABLE
        {"_POSIX_VDISABLE", _POSIX_VDISABLE, -1},
#else
        {"_POSIX_VDISABLE", -1, -1},
#endif

        /* POSIX I/O / Memory / Real-time */
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

        /* POSIX Advisory / Realtime */
#ifdef _POSIX_ADVISORY_INFO
        {"_POSIX_ADVISORY_INFO", _POSIX_ADVISORY_INFO, _SC_ADVISORY_INFO},
#else
        {"_POSIX_ADVISORY_INFO", -1, _SC_ADVISORY_INFO},
#endif
#ifdef _POSIX_CPUTIME
        {"_POSIX_CPUTIME", _POSIX_CPUTIME, _SC_CPUTIME},
#else
        {"_POSIX_CPUTIME", -1, _SC_CPUTIME},
#endif
#ifdef _POSIX_MONOTONIC_CLOCK
        {"_POSIX_MONOTONIC_CLOCK", _POSIX_MONOTONIC_CLOCK, _SC_MONOTONIC_CLOCK},
#else
        {"_POSIX_MONOTONIC_CLOCK", -1, _SC_MONOTONIC_CLOCK},
#endif
#ifdef _POSIX_SPAWN
        {"_POSIX_SPAWN", _POSIX_SPAWN, _SC_SPAWN},
#else
        {"_POSIX_SPAWN", -1, _SC_SPAWN},
#endif
#ifdef _POSIX_SPORADIC_SERVER
        {"_POSIX_SPORADIC_SERVER", _POSIX_SPORADIC_SERVER, _SC_SPORADIC_SERVER},
#else
        {"_POSIX_SPORADIC_SERVER", -1, _SC_SPORADIC_SERVER},
#endif
#ifdef _POSIX_TYPED_MEMORY_OBJECTS
        {"_POSIX_TYPED_MEMORY_OBJECTS", _POSIX_TYPED_MEMORY_OBJECTS, _SC_TYPED_MEMORY_OBJECTS},
#else
        {"_POSIX_TYPED_MEMORY_OBJECTS", -1, _SC_TYPED_MEMORY_OBJECTS},
#endif

        /* Realtime Threads */
#ifdef _POSIX_THREAD_PRIO_INHERIT
        {"_POSIX_THREAD_PRIO_INHERIT", _POSIX_THREAD_PRIO_INHERIT, _SC_THREAD_PRIO_INHERIT},
#else
        {"_POSIX_THREAD_PRIO_INHERIT", -1, _SC_THREAD_PRIO_INHERIT},
#endif
#ifdef _POSIX_THREAD_PRIO_PROTECT
        {"_POSIX_THREAD_PRIO_PROTECT", _POSIX_THREAD_PRIO_PROTECT, _SC_THREAD_PRIO_PROTECT},
#else
        {"_POSIX_THREAD_PRIO_PROTECT", -1, _SC_THREAD_PRIO_PROTECT},
#endif
#ifdef _POSIX_THREAD_PRIORITY_SCHEDULING
        {"_POSIX_THREAD_PRIORITY_SCHEDULING", _POSIX_THREAD_PRIORITY_SCHEDULING, _SC_THREAD_PRIORITY_SCHEDULING},
#else
        {"_POSIX_THREAD_PRIORITY_SCHEDULING", -1, _SC_THREAD_PRIORITY_SCHEDULING},
#endif
#ifdef _POSIX_THREAD_ROBUST_PRIO_INHERIT
        {"_POSIX_THREAD_ROBUST_PRIO_INHERIT", _POSIX_THREAD_ROBUST_PRIO_INHERIT, _SC_THREAD_ROBUST_PRIO_INHERIT},
#else
        {"_POSIX_THREAD_ROBUST_PRIO_INHERIT", -1, _SC_THREAD_ROBUST_PRIO_INHERIT},
#endif
#ifdef _POSIX_THREAD_ROBUST_PRIO_PROTECT
        {"_POSIX_THREAD_ROBUST_PRIO_PROTECT", _POSIX_THREAD_ROBUST_PRIO_PROTECT, _SC_THREAD_ROBUST_PRIO_PROTECT},
#else
        {"_POSIX_THREAD_ROBUST_PRIO_PROTECT", -1, _SC_THREAD_ROBUST_PRIO_PROTECT},
#endif
#ifdef _POSIX_THREAD_CPUTIME
        {"_POSIX_THREAD_CPUTIME", _POSIX_THREAD_CPUTIME, _SC_THREAD_CPUTIME},
#else
        {"_POSIX_THREAD_CPUTIME", -1, _SC_THREAD_CPUTIME},
#endif
#ifdef _POSIX_THREAD_SPORADIC_SERVER
        {"_POSIX_THREAD_SPORADIC_SERVER", _POSIX_THREAD_SPORADIC_SERVER, _SC_THREAD_SPORADIC_SERVER},
#else
        {"_POSIX_THREAD_SPORADIC_SERVER", -1, _SC_THREAD_SPORADIC_SERVER},
#endif
    };

    size_t n = sizeof(features) / sizeof(features[0]);

    for (size_t i = 0; i < n; i++) {
        printf("%-35s: ", features[i].name);

        if (features[i].macro_value != -1)
            printf("compile-time = %ld; ", features[i].macro_value);
        else
            printf("compile-time = (not defined); ");

        if (features[i].sc != -1) {
            long r = sysconf(features[i].sc);
            if (r == -1)
                printf("runtime = not supported\n");
            else
                printf("runtime = %ld\n", r);
        } else {
            printf("runtime = N/A\n");
        }
    }

    return 0;
}
