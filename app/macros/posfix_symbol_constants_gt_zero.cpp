/*
 * POSIX Feature Option Macros:
 *
 * _POSIX_JOB_CONTROL
 *     Indicates support for job control (suspending/resuming processes
 *     from the terminal using signals like SIGTSTP / SIGCONT).
 *
 * _POSIX_REGEXP
 *     Indicates that POSIX regular expressions are supported via <regex.h>
 *     (functions: regcomp, regexec, regfree).
 *
 * _POSIX_SAVED_IDS
 *     Means the system supports saved set-user-ID and set-group-ID.
 *     This lets privileged programs temporarily drop and then regain
 *     their effective user/group IDs.
 *
 * _POSIX_SHELL
 *     Confirms that a POSIX-conforming shell (typically /bin/sh) is
 *     available on the system.
 *
 * _POSIX_VDISABLE
 *     Defines a special character value used in termios control arrays
 *     (c_cc[]) to disable terminal control characters (e.g. disabling
 *     Ctrl+Z suspend by setting VSUSP = _POSIX_VDISABLE).
 */

 #include <stdio.h>
 #include <unistd.h>
 
 int main(void) {
 #ifdef _POSIX_JOB_CONTROL
     printf("Job control supported: %ld\n", (long)_POSIX_JOB_CONTROL);
 #endif
 
 #ifdef _POSIX_REGEXP
     printf("Regex supported: %ld\n", (long)_POSIX_REGEXP);
 #endif
 
 #ifdef _POSIX_SAVED_IDS
     printf("Saved IDs supported: %ld\n", (long)_POSIX_SAVED_IDS);
 #endif
 
 #ifdef _POSIX_SHELL
     printf("Shell supported: %ld\n", (long)_POSIX_SHELL);
 #endif
 
 #ifdef _POSIX_VDISABLE
     printf("_POSIX_VDISABLE value: %d\n", _POSIX_VDISABLE);
 #endif
     return 0;
 }
 