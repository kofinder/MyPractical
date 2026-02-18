#include <iostream>


/*

********************************************************************************
* The Tower of Hanoi is a mathematical puzzle or recursion problem.
    
    1. Only one disk can be moved at a time.

    2. You can only move the top disk of any peg.

    3. No larger disk may be placed on top of a smaller one.
********************************************************************************

PSEUDOCODE hanoi(disk, source, middle, dest)

    if disk == 0 then 
        print "Move disk", n, "from", source, "to", dest
        return;
    end if

    hanoi(desk - 1, source, dest, middle)

    print "Move disk", n, "from", source, "to", dest

    hanoi(desk - 1, middle, source, dest)
    
end PSEUDOCODE

*/


void hanoi(int disk, char source, char middle, char dest) {
    using namespace std;

    if(disk ==0) {
        cout << "Move disk " << disk << " from " << source << " to " << dest << endl;
        return;
    }

    hanoi(disk-1, source, dest, middle);

    cout << "Move disk " << disk << " from " << source << " to " << dest << endl;

    hanoi(disk-1, middle, source, dest);
}

int main() {

    hanoi(3, 'A', 'B', 'C');

    return 0;
}