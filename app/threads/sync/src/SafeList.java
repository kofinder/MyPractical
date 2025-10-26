package threads.sync.src;

import java.util.ArrayList;
import java.util.List;

class SafeList {
    private List<Integer> list = new ArrayList<>();

    public void addItem(int item) {
        synchronized (list) {
            list.add(item);
        }
    }

    public void printList() {
        synchronized (list) {
            System.out.println(list);
        }
    }
}
