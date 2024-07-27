set(LIBRARY_SOURCES "smartpointer.cpp")
set(LIBRARY_HEADERS "smartpointer.hpp")

set(LIBRARY_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")

add_library("smartpointer" STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})

target_include_directories("smartpointer" PUBLIC ${LIBRARY_INCLUDES})
