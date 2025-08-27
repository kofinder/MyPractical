/*
 * POSIX Tracing Feature Macros:
 *
 * _POSIX_TRACE
 *     General support for the POSIX tracing framework, which allows
 *     logging and monitoring of system events for debugging and profiling.
 *
 * _POSIX_TRACE_EVENT_FILTER
 *     Ability to filter trace events selectively, so only certain types
 *     of events are recorded or monitored.
 *
 * _POSIX_TRACE_LOG
 *     Support for writing trace data to trace logs, providing persistent
 *     storage of event records for analysis.
 *
 * _POSIX_TRACE_INHERIT
 *     Trace settings can be inherited by child processes, ensuring
 *     that tracing continues across forked processes.
 */


 #include <stdio.h>
#include <unistd.h>

int main(void) {
#ifdef _POSIX_TRACE
    printf("_POSIX_TRACE supported: %ld\n", (long)_POSIX_TRACE);
#endif

#ifdef _POSIX_TRACE_EVENT_FILTER
    printf("_POSIX_TRACE_EVENT_FILTER supported: %ld\n", (long)_POSIX_TRACE_EVENT_FILTER);
#endif

#ifdef _POSIX_TRACE_LOG
    printf("_POSIX_TRACE_LOG supported: %ld\n", (long)_POSIX_TRACE_LOG);
#endif

#ifdef _POSIX_TRACE_INHERIT
    printf("_POSIX_TRACE_INHERIT supported: %ld\n", (long)_POSIX_TRACE_INHERIT);
#endif

    // Runtime checks via sysconf
#ifdef _SC_TRACE
    long trace = sysconf(_SC_TRACE);
    printf("_SC_TRACE runtime = %ld\n", trace);
#endif
#ifdef _SC_TRACE_EVENT_FILTER
    long filter = sysconf(_SC_TRACE_EVENT_FILTER);
    printf("_SC_TRACE_EVENT_FILTER runtime = %ld\n", filter);
#endif
#ifdef _SC_TRACE_LOG
    long log = sysconf(_SC_TRACE_LOG);
    printf("_SC_TRACE_LOG runtime = %ld\n", log);
#endif
#ifdef _SC_TRACE_INHERIT
    long inherit = sysconf(_SC_TRACE_INHERIT);
    printf("_SC_TRACE_INHERIT runtime = %ld\n", inherit);
#endif

    return 0;
}
