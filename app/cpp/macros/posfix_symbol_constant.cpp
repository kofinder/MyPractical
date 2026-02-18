
/*
 * POSIX Feature Option Macros (all from POSIX.1-2008, value 200809L):
 *
 * _POSIX_ASYNCHRONOUS_IO
 *     Asynchronous I/O (aio_* functions) for files, allowing reads/writes
 *     to be queued without blocking the calling thread.
 *
 * _POSIX_BARRIERS
 *     Thread barriers (pthread_barrier_*), used to synchronize a group
 *     of threads until all have reached the same point.
 *
 * _POSIX_CLOCK_SELECTION
 *     Clock selection for timed waits (e.g. pthread_condattr_setclock),
 *     and support for additional clocks like CLOCK_MONOTONIC.
 *
 * _POSIX_MAPPED_FILES
 *     Memory-mapped file support (mmap/munmap/msync), useful for shared
 *     memory and efficient file access.
 *
 * _POSIX_MEMORY_PROTECTION
 *     Memory protection primitives (mprotect), lets you set read/write/exec
 *     permissions on memory regions.
 *
 * _POSIX_READER_WRITER_LOCKS
 *     Reader/writer locks (pthread_rwlock_*), allow multiple readers or
 *     a single writer to share access safely.
 *
 * _POSIX_REALTIME_SIGNALS
 *     Real-time signals (SIGRTMIN..SIGRTMAX) with queuing and delivery
 *     of extra data (sigqueue, sigaction with SA_SIGINFO).
 *
 * _POSIX_SEMAPHORES
 *     POSIX semaphores for thread/process synchronization (sem_* APIs).
 *
 * _POSIX_SPIN_LOCKS
 *     Spin locks (pthread_spin_*), lightweight locks that busy-wait
 *     instead of blocking — useful for very short critical sections.
 *
 * _POSIX_THREAD_SAFE_FUNCTIONS
 *     Guarantees that thread-safe (“_r”) functions like localtime_r,
 *     strtok_r, getpwnam_r are available.
 *
 * _POSIX_THREADS
 *     POSIX threads (pthread_* APIs): thread creation, mutexes, condvars,
 *     and most multithreading primitives.
 *
 * _POSIX_TIMEOUTS
 *     Timed versions of blocking calls (e.g. sem_timedwait, mq_timedreceive,
 *     pthread_cond_timedwait).
 *
 * _POSIX_TIMERS
 *     POSIX timers (timer_create, timer_settime) that deliver signals or
 *     spawn threads when they expire.
 *
 * _POSIX2_C_BIND
 *     POSIX.2 C language binding option, ensures that C interfaces for
 *     utilities specified in POSIX.2 are available.
 */

#define _POSIX_C_SOURCE 200809L   // ask headers to expose POSIX.1-2008 features

#include <stdio.h>
#include <unistd.h>

struct check {
    const char *name;
    int sc;     // corresponding _SC_* for sysconf (or -1 if none)
#ifdef __STDC_VERSION__
    long macro;
#endif
};

int main(void) {
    struct {
        const char *macro_name;
        long macro_value;
        int sc;
    } checks[] = {
#ifdef _POSIX_ASYNCHRONOUS_IO
        {"_POSIX_ASYNCHRONOUS_IO", _POSIX_ASYNCHRONOUS_IO, _SC_ASYNCHRONOUS_IO},
#else
        {"_POSIX_ASYNCHRONOUS_IO", -1, _SC_ASYNCHRONOUS_IO},
#endif
#ifdef _POSIX_BARRIERS
        {"_POSIX_BARRIERS", _POSIX_BARRIERS, _SC_BARRIERS},
#else
        {"_POSIX_BARRIERS", -1, _SC_BARRIERS},
#endif
#ifdef _POSIX_CLOCK_SELECTION
        {"_POSIX_CLOCK_SELECTION", _POSIX_CLOCK_SELECTION, _SC_CLOCK_SELECTION},
#else
        {"_POSIX_CLOCK_SELECTION", -1, _SC_CLOCK_SELECTION},
#endif
#ifdef _POSIX_MAPPED_FILES
        {"_POSIX_MAPPED_FILES", _POSIX_MAPPED_FILES, _SC_MAPPED_FILES},
#else
        {"_POSIX_MAPPED_FILES", -1, _SC_MAPPED_FILES},
#endif
#ifdef _POSIX_MEMORY_PROTECTION
        {"_POSIX_MEMORY_PROTECTION", _POSIX_MEMORY_PROTECTION, _SC_MEMORY_PROTECTION},
#else
        {"_POSIX_MEMORY_PROTECTION", -1, _SC_MEMORY_PROTECTION},
#endif
#ifdef _POSIX_READER_WRITER_LOCKS
        {"_POSIX_READER_WRITER_LOCKS", _POSIX_READER_WRITER_LOCKS, _SC_READER_WRITER_LOCKS},
#else
        {"_POSIX_READER_WRITER_LOCKS", -1, _SC_READER_WRITER_LOCKS},
#endif
#ifdef _POSIX_REALTIME_SIGNALS
        {"_POSIX_REALTIME_SIGNALS", _POSIX_REALTIME_SIGNALS, _SC_REALTIME_SIGNALS},
#else
        {"_POSIX_REALTIME_SIGNALS", -1, _SC_REALTIME_SIGNALS},
#endif
#ifdef _POSIX_SEMAPHORES
        {"_POSIX_SEMAPHORES", _POSIX_SEMAPHORES, _SC_SEMAPHORES},
#else
        {"_POSIX_SEMAPHORES", -1, _SC_SEMAPHORES},
#endif
#ifdef _POSIX_SPIN_LOCKS
        {"_POSIX_SPIN_LOCKS", _POSIX_SPIN_LOCKS, _SC_SPIN_LOCKS},
#else
        {"_POSIX_SPIN_LOCKS", -1, _SC_SPIN_LOCKS},
#endif
#ifdef _POSIX_THREAD_SAFE_FUNCTIONS
        {"_POSIX_THREAD_SAFE_FUNCTIONS", _POSIX_THREAD_SAFE_FUNCTIONS, _SC_THREAD_SAFE_FUNCTIONS},
#else
        {"_POSIX_THREAD_SAFE_FUNCTIONS", -1, _SC_THREAD_SAFE_FUNCTIONS},
#endif
#ifdef _POSIX_THREADS
        {"_POSIX_THREADS", _POSIX_THREADS, _SC_THREADS},
#else
        {"_POSIX_THREADS", -1, _SC_THREADS},
#endif
#ifdef _POSIX_TIMEOUTS
        {"_POSIX_TIMEOUTS", _POSIX_TIMEOUTS, _SC_TIMEOUTS},
#else
        {"_POSIX_TIMEOUTS", -1, _SC_TIMEOUTS},
#endif
#ifdef _POSIX_TIMERS
        {"_POSIX_TIMERS", _POSIX_TIMERS, _SC_TIMERS},
#else
        {"_POSIX_TIMERS", -1, _SC_TIMERS},
#endif
#ifdef _POSIX2_C_BIND
        {"_POSIX2_C_BIND", _POSIX2_C_BIND, _SC_2_C_BIND},
#else
        {"_POSIX2_C_BIND", -1, _SC_2_C_BIND},
#endif
    };

    size_t n = sizeof(checks) / sizeof(checks[0]);
    for (size_t i = 0; i < n; i++) {
        printf("%s: ", checks[i].macro_name);

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
