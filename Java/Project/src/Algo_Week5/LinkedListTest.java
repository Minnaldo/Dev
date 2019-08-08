package Algo_Week5;

public class LinkedListTest {

    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        list.addToFirst(1);
        list.addToFirst(2);
        list.addToFirst(3);
        list.addToLast(10);
        list.addToLast(30);
        list.addToLast(50);
        System.out.println(list.toString());
    }

}

class LinkedList {

    private Node front;
    private Node rear;
    int size;

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        Node tmp = front.next;
        while (tmp != null) {
            sb.append(tmp.data + " ");
            tmp = tmp.next;
        }
        return sb.toString();
    }

    public boolean isEmpty() {
        if (front.next == rear.next) {
            return true;
        }
        return false;
    }

    public void addToFirst(int data) {
        Node newNode = new Node(data);
        if (front.next == null) {
            front.next = newNode;
            rear.next = newNode;
        } else {
            newNode.next = front.next;
            front.next = newNode;
        }
        size++;
    }

    public void addToLast(int data) {
        Node newNode = new Node(data);
        if (front.next == null) {
            front.next = newNode;
            rear.next = newNode;
        } else {
            rear.next.next = newNode;
            rear.next = newNode;
        }
        size++;
    }

    // idx는 0부터 시작
    public void add(int data, int idx) {
        Node newNode = new Node(data);
        Node tmpNode = front.next;
        int tmpidx = 0;

        while (tmpidx < idx - 1) {
            tmpNode = tmpNode.next;
            tmpidx++;
        }
        newNode.next = tmpNode.next.next;
        tmpNode.next = newNode;

        size++;
    }

    // idx는 0부터 시작
    public void delete(int idx) {


        if (idx == 0) {
            // 가장 앖의 노드를 삭제
            Node delNode = front.next;
            Node newFront = delNode.next;

            front.next = newFront;
            delNode = null;

        } else if (idx == size - 1) {
            // 가장 뒤의 노드를 삭제
            Node tmpNode = front.next;
            int tmpidx = 0;
            while (tmpidx < idx - 1) {
                tmpidx++;
            }
        } else {
            Node tmpNode = front.next;
            int tmpidx = 0;
            while (tmpidx < idx - 1) {
                tmpNode = tmpNode.next;
                tmpidx++;
            }

            tmpNode.next = tmpNode.next.next;
        }


        size--;
    }

    // idx번째 Node를 넘김
    public Node get(int idx) {
        Node tmpNode = front.next;
        int tmpidx = 0;
        while (tmpidx != idx) {
            tmpNode = tmpNode.next;
            tmpidx++;
        }
        return tmpNode;
    }

    public void print() {
        Node tmpNode = front.next;
        while (tmpNode != null) {
            System.out.print(tmpNode.data + " ");
            tmpNode = tmpNode.next;
        }
    }

    public int getSize() {
        return size;
    }

    LinkedList() {
        front = new Node();
        rear = new Node();
        size = 0;
    }

    class Node {
        Node next;
        int data;

        Node() {
        }

        Node(int data) {
            this.data = data;
        }
    }
}
