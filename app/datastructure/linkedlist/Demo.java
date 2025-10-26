package datastructure.linkedlist;

import java.io.*;
import java.util.stream.*;

class SinglyLinkedListNode {
    public int data;
    public SinglyLinkedListNode next;

    public SinglyLinkedListNode(int nodeData) {
        this.data = nodeData;
        this.next = null;
    }
}

class SinglyLinkedList {
    public SinglyLinkedListNode head;
    public SinglyLinkedListNode tail;

    public SinglyLinkedList() {
        this.head = null;
        this.tail = null;
    }

    public void insertNode(int nodeData) {
        SinglyLinkedListNode node = new SinglyLinkedListNode(nodeData);

        if (this.head == null) {
            this.head = node;
        } else {
            this.tail.next = node;
        }

        this.tail = node;
    }
}

class SinglyLinkedListPrintHelper {
    public static void printList(SinglyLinkedListNode node) {
        while (node != null) {

            node = node.next;

            if (node != null) {
                System.out.println(node);
            }
        }
    }
}

class Result {

    // 4
    // 11
    // 9
    // 2
    // 9
    // 1

    // expected result: 11 2 9

    static SinglyLinkedListNode get(SinglyLinkedListNode llist, int index) {
        if (index <= 0) {
            return null;
        }
        SinglyLinkedListNode temp = llist;
        for (int i = 0; i < index; i++) {
            temp = temp.next;
        }
        return temp;
    }

    static SinglyLinkedListNode deleteNode(SinglyLinkedListNode llist, int position) {
        if (position == 0) {
            return null;
        }
        SinglyLinkedListNode head = llist;
        SinglyLinkedListNode prev = get(llist, position - 1);
        if (prev != null) {
            SinglyLinkedListNode temp = prev.next;
            prev.next = temp.next;
            temp.next = null;
        }

        return head;
    }

}

public class Demo {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        SinglyLinkedList llist = new SinglyLinkedList();
        int llistCount = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, llistCount).forEach(i -> {
            try {
                int llistItem = Integer.parseInt(bufferedReader.readLine().trim());
                llist.insertNode(llistItem);
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        int position = Integer.parseInt(bufferedReader.readLine().trim());

        SinglyLinkedListNode llist1 = Result.deleteNode(llist.head, position);

        SinglyLinkedListPrintHelper.printList(llist1);

        bufferedReader.close();
    }
}
