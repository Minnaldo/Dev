package Algo_Week5;

public class PriorityQueue {
}

class Tree {
    Node root;

    Tree(){
        root = new Node();
    }


    public void add(int data) {
        Node newNode = new Node();

        if(root.left == null){
            root.left = newNode;
        }else{
            Node cur = root.left;

            if(newNode.data > cur.data){
                cur.right = newNode;
            }else{
                cur.left = newNode;
            }
        }
    }


    class Node {
        Node left;
        Node right;
        int data;

        public Node() {
        }

        public Node(int data) {
            this.data = data;
        }
    }
}
