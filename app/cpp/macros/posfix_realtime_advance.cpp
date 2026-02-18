/*
 * POSIX Real-Time, Advisory, and Process Control Feature Macros:
 *
 * _POSIX_ADVISORY_INFO
 *     Provides advisory information APIs (like posix_fadvise)
 *     to give the kernel hints about expected file access patterns,
 *     which can improve I/O performance.
 *
 * _POSIX_CPUTIME
 *     Support for per-process and per-thread CPU-time clocks
 *     (CLOCK_PROCESS_CPUTIME_ID, CLOCK_THREAD_CPUTIME_ID),
 *     useful for profiling or real-time accounting.
 *
 * _POSIX_MONOTONIC_CLOCK
 *     Support for CLOCK_MONOTONIC in clock_gettime(), providing
 *     a clock that is not affected by system time changes.
 *
 * _POSIX_SPAWN
 *     Support for lightweight process creation with posix_spawn()
 *     and posix_spawnp(), combining fork + exec in one call.
 *
 * _POSIX_SPORADIC_SERVER
 *     Real-time scheduling feature for sporadic server tasks,
 *     providing temporal isolation for scheduled threads or processes.
 *
 * _POSIX_TYPED_MEMORY_OBJECTS
 *     Support for typed memory objects (posix_typed_mem_open),
 *     allowing creation of memory objects with different types or attributes.
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
