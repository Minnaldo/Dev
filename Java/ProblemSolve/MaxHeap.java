import java.util.Arrays;

public class MaxHeap {

    private int[] tree = new int[128];
    private int size = 1;

    public void swap(int[] arr, int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    public void add(int data) {
        int idx = size++;
        tree[idx] = data;

        // 정렬 부분
        while (idx > 0) {
            if (tree[idx / 2] < tree[idx] && idx / 2 != 0) {
                swap(tree, idx / 2, idx);
                idx /= 2;
            } else
                break;
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < (1 << i); j++) {
                // System.out.print(tree[j]+" ");
                if (tree[(1 << i) + j] != 0)
                    sb.append(tree[(1 << i) + j] + " ");
            }
            // System.out.println();
            sb.append("\n");
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        MaxHeap heap = new MaxHeap();
        heap.add(13);
        heap.add(10);
        heap.add(12);
        heap.add(18);
        heap.add(20);
        heap.add(29);

        System.out.println(heap.toString());
    }
}