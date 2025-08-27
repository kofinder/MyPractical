/*
 * More POSIX / XSI (X/Open System Interface) feature macros:
 *
 * _POSIX_ADVISORY_INFO
 *     Advisory information option — provides APIs like posix_fadvise()
 *     to give the kernel hints about expected file access patterns.
 *
 * _POSIX_CPUTIME
 *     Support for per-process and per-thread CPU time clocks
 *     (clock_getcpuclockid(), CLOCK_PROCESS_CPUTIME_ID, CLOCK_THREAD_CPUTIME_ID).
 *
 * _POSIX_FSYNC
 *     Indicates support for fsync() to synchronize a file's in-memory
 *     state with storage.
 *
 * _POSIX_IPV6
 *     Confirms that the implementation supports IPv6 sockets.
 *
 * _POSIX_MEMLOCK
 *     Ability to lock all process memory into RAM (mlockall) so it
 *     cannot be paged out.
 *
 * _POSIX_MEMLOCK_RANGE
 *     Ability to lock specific memory ranges into RAM (mlock, munlock).
 *
 * _POSIX_MESSAGE_PASSING
 *     POSIX message queues (<mqueue.h>): mq_open, mq_send, mq_receive, etc.
 *
 * _POSIX_MONOTONIC_CLOCK
 *     Support for CLOCK_MONOTONIC in clock_gettime(); unaffected by
 *     system time changes, useful for measuring intervals.
 *
 * _POSIX_PRIORITIZED_IO
 *     Prioritized asynchronous I/O operations with lio_listio().
 *
 * _POSIX_PRIORITY_SCHEDULING
 *     Support for real-time scheduling policies (SCHED_FIFO, SCHED_RR)
 *     with sched_setscheduler(), pthread_setschedparam().
 *
 * _POSIX_RAW_SOCKETS
 *     Ability to use raw sockets (e.g., creating your own IP packets).
 *     Typically requires root privileges.
 *
 * _POSIX_SHARED_MEMORY_OBJECTS
 *     Shared memory objects (shm_open, shm_unlink) for interprocess
 *     communication via memory.
 *
 * _POSIX_SPAWN
 *     posix_spawn() / posix_spawnp() APIs — lightweight process creation
 *     combining fork+exec in one call.
 *
 * _POSIX_SPORADIC_SERVER
 *     Real-time scheduling option for sporadic server tasks (rarely
 *     implemented on general-purpose OSes).
 *
 * _POSIX_SYNCHRONIZED_IO
 *     Guarantees that writes to a file descriptor complete synchronously
 *     (data reaches storage before write() returns).
 *
 * _POSIX_THREAD_ATTR_STACKADDR
 *     Thread attribute to set a custom stack address (pthread_attr_setstackaddr()).
 *
 * _POSIX_THREAD_CPUTIME
 *     Per-thread CPU-time clocks (CLOCK_THREAD_CPUTIME_ID).
 *
 * _POSIX_THREAD_ATTR_STACKSIZE
 *     Thread attribute to set stack size (pthread_attr_setstacksize()).
 *
 * _POSIX_THREAD_PRIO_INHERIT
 *     Mutexes with priority inheritance protocol to reduce priority
 *     inversion (pthread_mutexattr_setprotocol()).
 *
 * _POSIX_THREAD_PRIO_PROTECT
 *     Mutexes with priority protection protocol (ceiling priority).
 *
 * _POSIX_THREAD_PRIORITY_SCHEDULING
 *     Ability for threads to use real-time scheduling policies.
 *
 * _POSIX_THREAD_PROCESS_SHARED
 *     Thread synchronization objects (mutexes, condvars) that can be
 *     shared across processes (PTHREAD_PROCESS_SHARED).
 *
 * _POSIX_THREAD_SPORADIC_SERVER
 *     Sporadic server scheduling option for threads (very rarely supported).
 *
 * _POSIX_TRACE
 *     POSIX tracing framework (trace_create, trace_event) — almost never
 *     implemented in mainstream OSes.
 *
 * _POSIX_TRACE_EVENT_FILTER
 *     Ability to filter which trace events are recorded.
 *
 * _POSIX_TRACE_INHERIT
 *     Whether trace settings are inherited across fork/exec.
 *
 * _POSIX_TRACE_LOG
 *     Ability to log trace events to a trace log.
 *
 * _POSIX_TYPED_MEMORY_OBJECTS
 *     Typed memory objects (posix_typed_mem_open) with memory types like
 *     shared vs private — almost never available in practice.
 *
 * _XOPEN_CRYPT
 *     Support for the XSI encryption/crypt() API in <unistd.h>.
 *
 * _XOPEN_REALTIME
 *     XSI extension guaranteeing presence of POSIX realtime options
 *     (clocks, timers, semaphores, etc.).
 *
 * _XOPEN_REALTIME_THREADS
 *     XSI extension guaranteeing realtime capabilities for threads
 *     (priority scheduling, realtime mutexes).
 *
 * _XOPEN_STREAMS
 *     STREAMS API (putmsg, getmsg) support. Rarely supported on Linux,
 *     mostly legacy System V UNIX.
 *
 * _XOPEN_UNIX
 *     Indicates general XSI UNIX option support (full X/Open UNIX profile).
 *     If defined, the system provides core UNIX interfaces (fork, exec,
 *     signals, file ops, etc.).
 */


 #define _POSIX_C_SOURCE 200809L   // ask headers to expose POSIX.1-2008 features

#include <stdio.h>
#include <unistd.h>

struct check {
    const char *name;
    long macro_value;   // -1 if not defined
    int sc;             // _SC_* constant for sysconf, or -1 if none
};

int main(void) {
    struct check checks[] = {
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
        #ifdef _POSIX_FSYNC
                {"_POSIX_FSYNC", _POSIX_FSYNC, _SC_FSYNC},
        #else
                {"_POSIX_FSYNC", -1, _SC_FSYNC},
        #endif
        #ifdef _POSIX_IPV6
                {"_POSIX_IPV6", _POSIX_IPV6, _SC_IPV6},
        #else
                {"_POSIX_IPV6", -1, _SC_IPV6},
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
        #ifdef _POSIX_MONOTONIC_CLOCK
                {"_POSIX_MONOTONIC_CLOCK", _POSIX_MONOTONIC_CLOCK, _SC_MONOTONIC_CLOCK},
        #else
                {"_POSIX_MONOTONIC_CLOCK", -1, _SC_MONOTONIC_CLOCK},
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
        #ifdef _POSIX_RAW_SOCKETS
                {"_POSIX_RAW_SOCKETS", _POSIX_RAW_SOCKETS, _SC_RAW_SOCKETS},
        #else
                {"_POSIX_RAW_SOCKETS", -1, _SC_RAW_SOCKETS},
        #endif
        #ifdef _POSIX_SHARED_MEMORY_OBJECTS
                {"_POSIX_SHARED_MEMORY_OBJECTS", _POSIX_SHARED_MEMORY_OBJECTS, _SC_SHARED_MEMORY_OBJECTS},
        #else
                {"_POSIX_SHARED_MEMORY_OBJECTS", -1, _SC_SHARED_MEMORY_OBJECTS},
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
        #ifdef _POSIX_SYNCHRONIZED_IO
                {"_POSIX_SYNCHRONIZED_IO", _POSIX_SYNCHRONIZED_IO, _SC_SYNCHRONIZED_IO},
        #else
                {"_POSIX_SYNCHRONIZED_IO", -1, _SC_SYNCHRONIZED_IO},
        #endif
        #ifdef _POSIX_THREAD_ATTR_STACKADDR
                {"_POSIX_THREAD_ATTR_STACKADDR", _POSIX_THREAD_ATTR_STACKADDR, _SC_THREAD_ATTR_STACKADDR},
        #else
                {"_POSIX_THREAD_ATTR_STACKADDR", -1, _SC_THREAD_ATTR_STACKADDR},
        #endif
        #ifdef _POSIX_THREAD_CPUTIME
                {"_POSIX_THREAD_CPUTIME", _POSIX_THREAD_CPUTIME, _SC_THREAD_CPUTIME},
        #else
                {"_POSIX_THREAD_CPUTIME", -1, _SC_THREAD_CPUTIME},
        #endif
        #ifdef _POSIX_THREAD_ATTR_STACKSIZE
                {"_POSIX_THREAD_ATTR_STACKSIZE", _POSIX_THREAD_ATTR_STACKSIZE, _SC_THREAD_ATTR_STACKSIZE},
        #else
                {"_POSIX_THREAD_ATTR_STACKSIZE", -1, _SC_THREAD_ATTR_STACKSIZE},
        #endif
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
        #ifdef _POSIX_THREAD_PROCESS_SHARED
                {"_POSIX_THREAD_PROCESS_SHARED", _POSIX_THREAD_PROCESS_SHARED, _SC_THREAD_PROCESS_SHARED},
        #else
                {"_POSIX_THREAD_PROCESS_SHARED", -1, _SC_THREAD_PROCESS_SHARED},
        #endif
        #ifdef _POSIX_THREAD_SPORADIC_SERVER
                {"_POSIX_THREAD_SPORADIC_SERVER", _POSIX_THREAD_SPORADIC_SERVER, _SC_THREAD_SPORADIC_SERVER},
        #else
                {"_POSIX_THREAD_SPORADIC_SERVER", -1, _SC_THREAD_SPORADIC_SERVER},
        #endif
        #ifdef _POSIX_TRACE
                {"_POSIX_TRACE", _POSIX_TRACE, _SC_TRACE},
        #else
                {"_POSIX_TRACE", -1, _SC_TRACE},
        #endif
        #ifdef _POSIX_TRACE_EVENT_FILTER
                {"_POSIX_TRACE_EVENT_FILTER", _POSIX_TRACE_EVENT_FILTER, _SC_TRACE_EVENT_FILTER},
        #else
                {"_POSIX_TRACE_EVENT_FILTER", -1, _SC_TRACE_EVENT_FILTER},
        #endif
        #ifdef _POSIX_TRACE_INHERIT
                {"_POSIX_TRACE_INHERIT", _POSIX_TRACE_INHERIT, _SC_TRACE_INHERIT},
        #else
                {"_POSIX_TRACE_INHERIT", -1, _SC_TRACE_INHERIT},
        #endif
        #ifdef _POSIX_TRACE_LOG
                {"_POSIX_TRACE_LOG", _POSIX_TRACE_LOG, _SC_TRACE_LOG},
        #else
                {"_POSIX_TRACE_LOG", -1, _SC_TRACE_LOG},
        #endif
        #ifdef _POSIX_TYPED_MEMORY_OBJECTS
                {"_POSIX_TYPED_MEMORY_OBJECTS", _POSIX_TYPED_MEMORY_OBJECTS, _SC_TYPED_MEMORY_OBJECTS},
        #else
                {"_POSIX_TYPED_MEMORY_OBJECTS", -1, _SC_TYPED_MEMORY_OBJECTS},
        #endif
        #ifdef _XOPEN_CRYPT
                {"_XOPEN_CRYPT", _XOPEN_CRYPT, _SC_XOPEN_CRYPT},
        #else
                {"_XOPEN_CRYPT", -1, _SC_XOPEN_CRYPT},
        #endif
        #ifdef _XOPEN_REALTIME
                {"_XOPEN_REALTIME", _XOPEN_REALTIME, _SC_XOPEN_REALTIME},
        #else
                {"_XOPEN_REALTIME", -1, _SC_XOPEN_REALTIME},
        #endif
        #ifdef _XOPEN_REALTIME_THREADS
                {"_XOPEN_REALTIME_THREADS", _XOPEN_REALTIME_THREADS, _SC_XOPEN_REALTIME_THREADS},
        #else
                {"_XOPEN_REALTIME_THREADS", -1, _SC_XOPEN_REALTIME_THREADS},
        #endif
        #ifdef _XOPEN_STREAMS
                {"_XOPEN_STREAMS", _XOPEN_STREAMS, _SC_XOPEN_STREAMS},
        #else
                {"_XOPEN_STREAMS", -1, _SC_XOPEN_STREAMS},
        #endif
        #ifdef _XOPEN_UNIX
                {"_XOPEN_UNIX", _XOPEN_UNIX, _SC_XOPEN_UNIX},
        #else
                {"_XOPEN_UNIX", -1, _SC_XOPEN_UNIX},
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
