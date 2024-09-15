# Learning Resources
- https://en.cppreference.com
- https://simplifycpp.org
- https://github.com/federico-busato/Modern-CPP-Programming
- https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines
- https://valgrind.org/docs/manual/quick-start.html#quick-start.prepare


# EXPRIMENT COMMAND
* man objdump
* objdump -t cxx.


# MEMNORY DEBUGING
 - Enable Compiler Flags for Debugging
    - g++ -g -Wall -Wextra -pedantic -fsanitize=address -fsanitize=undefined -o my_program my_program.cpp
    * -g: Generates debugging information.
    * -Wall -Wextra: Enables warnings for potential issues.
    * -fsanitize=address: Enables the AddressSanitizer for detecting memory bugs.
    * -fsanitize=undefined: Enables checks for undefined behavior.

 - Valgrind (Memory Leak Detection)
    - valgrind --leak-check=full --track-origins=yes ./my_program

- AddressSanitizer (ASan)
    - g++ -fsanitize=address -g -o my_program my_program.cpp

- Undefined Behavior Sanitizer (UBSan)
    - g++ -fsanitize=undefined -g -o my_program my_program.cpp

- Static Code Analysis
    - scan-build g++ -o my_program my_program.cpp
    - cppcheck --enable=all my_program.cpp

- Heap Profiling Tools
    - valgrind --tool=massif ./my_program
    - massif-visualizer massif.out.<pid>

- Third-Party Memory Debugging Tools
    - drmemory -- ./my_program