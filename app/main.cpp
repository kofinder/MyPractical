#include <iostream>
#include <memory>
#include <vector>

#include "queue/queue.hpp"
#include "stack/stack.hpp"
#include "tree/binary_search_tree.hpp"
#include "linkedlist/single_linked_list.hpp"
#include "doublylinkedlist/doubly_linked_list.hpp"

using namespace std;
using namespace queue;
using namespace stack;
using namespace tree;
using namespace linkedlist;
using namespace doublyllist;


int main() {

    SinglyLinkedList list(1);
    list.append(100);
    list.append(200);
    list.append(400);


    list.prepend(500);
    list.prepend(400);
    
    list.print();
    
    return 0;
}
