set(LIB_DS_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/queue/queue.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stack/stack.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tree/binary_search_tree.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/linkedlist/single_linked_list.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/doublylinkedlist/doubly_linked_list.cpp
)

set(LIB_DS_HEADERS 
    ${CMAKE_CURRENT_SOURCE_DIR}/queue/queue.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stack/stack.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tree/binary_search_tree.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/linkedlist/single_linked_list.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/doublylinkedlist/doubly_linked_list.hpp
)

set(LIBRARY_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")

add_library("dslibs" STATIC ${LIB_DS_SOURCES} ${LIB_DS_HEADERS})

target_include_directories("dslibs" PUBLIC ${LIBRARY_INCLUDES})
