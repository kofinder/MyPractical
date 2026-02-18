/*
 * POSIX Realtime Threads and Thread Scheduling Feature Macros:
 *
 * _POSIX_THREAD_PRIO_INHERIT
 *     Support for mutexes with **priority inheritance** protocol,
 *     which helps avoid priority inversion when high-priority threads
 *     are blocked by lower-priority threads holding a mutex.
 *
 * _POSIX_THREAD_PRIO_PROTECT
 *     Support for mutexes with **priority protection** protocol,
 *     also called "priority ceiling", ensuring threads temporarily
 *     inherit a ceiling priority while holding a mutex.
 *
 * _POSIX_THREAD_PRIORITY_SCHEDULING
 *     Ability for threads to use **real-time scheduling policies**
 *     (SCHED_FIFO, SCHED_RR) and set thread-specific priorities.
 *
 * _POSIX_THREAD_ROBUST_PRIO_INHERIT
 *     Robust mutexes with priority inheritance support,
 *     survive thread termination without leaving mutexes permanently locked.
 *
 * _POSIX_THREAD_ROBUST_PRIO_PROTECT
 *     Robust mutexes with priority protection support,
 *     combining robustness and priority ceiling features.
 *
 * _POSIX_THREAD_CPUTIME
 *     Per-thread CPU-time clocks (CLOCK_THREAD_CPUTIME_ID),
 *     useful for profiling and accounting per-thread CPU usage.
 *
 * _POSIX_THREAD_SPORADIC_SERVER
 *     Support for sporadic server scheduling for threads,
 *     providing temporal isolation for scheduled threads in real-time systems.
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
