import java.util.LinkedList;
import java.util.Queue;

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

    public void preorder(int idx) {
        // 전위순회
        visit(tree[idx]);
        if (idx * 2 < tree.length) {
            preorder(idx * 2);
        }
        if (idx * 2 + 1 < tree.length) {
            preorder(idx * 2 + 1);
        }
    }

    public void postorder(int idx) {
        // 후위순회
        if (idx * 2 < tree.length) {
            postorder(idx * 2);
        }
        if (idx * 2 + 1 < tree.length) {
            postorder(idx * 2 + 1);
        }
        visit(tree[idx]);
    }

    public void inorder(int idx) {
        // 중위순회
        if (idx * 2 < tree.length) {
            inorder(idx * 2);
        }
        visit(tree[idx]);
        if (idx * 2 + 1 < tree.length) {
            inorder(idx * 2 + 1);
        }
    }

    public void levelorder(int idx) {
        Queue<Integer> q = new LinkedList<>();
        q.add(idx);
        int curidx = 0;
        while (!q.isEmpty()) {
            curidx = q.poll();
            visit(tree[curidx]);
            int left = curidx * 2;
            int right = curidx * 2 + 1;
            if (left < tree.length) {
                q.add(left);
            }
            if (right < tree.length) {
                q.add(right);
            }
        }
    }

    public void visit(char ch) {
        System.out.print(ch + " ");
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < max_depth; i++) {
            for (int j = 0; j < (1 << i); j++) {
                // System.out.print(tree[(1 << i) + j] + " ");
                sb.append(tree[(1 << i) + j]).append(" ");
            }
            sb.append("\n");
        }
        return sb.toString();
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
        // System.out.println(tree);

        tree.levelorder(1);
        System.out.println();
        tree.preorder(1);
        System.out.println();
        tree.postorder(1);
        System.out.println();
        tree.inorder(1);
        System.out.println();
    }
}
