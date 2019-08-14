package Algo_Week6;

public class BinaryTree {
    private char[] tree;
    int max_depth;

    public BinaryTree(int max_depth) {
        tree = new char[(1 << max_depth) + 1];
        this.max_depth = max_depth;
    }

    public void setRoot(char data) {
        tree[1] = data;
    }

    public void setLeft(int parent, char data) {
        tree[parent * 2] = data;
    }

    public void setRight(int parent, char data) {
        tree[parent * 2 + 1] = data;
    }

    @Override
    public String toString() {
        for (int i = 0; i <= max_depth; i++) {
            for (int j = 0; j < (1 << i); j++) {
                System.out.print(tree[(1 << i) + j] + " ");
            }
            System.out.println();
        }
        return null;
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree(4);

        tree.setRoot('A');
        tree.setLeft(1, 'B');
        tree.setRight(1, 'C');
        tree.setLeft(2, 'D');
        tree.setRight(2, 'E');
        tree.setLeft(3, 'F');
        tree.setRight(3, 'G');
        tree.setLeft(4, 'H');
        tree.setRight(4, 'I');
        tree.setLeft(5, 'J');
        tree.setRight(5, 'K');
        tree.setLeft(6, 'L');
        tree.setRight(6, 'M');
        System.out.println(tree);
    }
}
