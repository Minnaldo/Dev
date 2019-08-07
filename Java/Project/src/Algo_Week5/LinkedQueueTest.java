package Algo_Week5;

public class LinkedQueueTest {
    public static void main(String[] args) {
        LinkedQueue<Integer> lq = new LinkedQueue<>();

        lq.enQueue(1);
        lq.enQueue(2);
        lq.enQueue(30);
        lq.enQueue(11);
        lq.print();
        System.out.println("큐의 크기는 " + lq.size() + "입니다");
//        System.out.println(lq.deQueue() + "가 삭제되었습니다");
//        System.out.println(lq.deQueue() + "가 삭제되었습니다");
//        System.out.println(lq.deQueue() + "가 삭제되었습니다");
//        System.out.println(lq.deQueue() + "가 삭제되었습니다");
    }

}

class LinkedQueue<E> {
    private Node front;
    private Node rear;
    static int size;

    public void enQueue(E data) {
        if (front.link == null) {
            Node newNode = new Node(data);
            front.link = newNode;
            rear.link = newNode;
        } else {
            Node newNode = new Node(data);
            rear.link.link = newNode;
            rear.link = newNode;
        }
        size++;
    }


    public E deQueue() {
        if (front == null) {
            System.out.println("Queue is Empty");
            return null;
        } else {
            E retVal = front.link.value;
            front.link = front.link.link;
            if (front.link == null) rear.link = null;
            size--;
            return retVal;
        }

    }

    public int size() {
        return this.size;
    }

    public void print() {
        Node tmp = front.link;

        while (tmp != null) {
            System.out.println(tmp.value + " ");
            tmp = tmp.link;
        }
    }

    LinkedQueue() {
        this.front = new Node();
        this.rear = new Node();
        this.size = 0;
    }


    class Node {
        E value;
        Node link;

        Node() {
        }

        Node(E value) {
            this.value = value;
        }
    }
}
