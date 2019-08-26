import java.util.Scanner;

public class BinSearch {
    public static void main(String[] args){
        int[] arr = {1,3,5,7,9};

        Scanner sc = new Scanner(System.in);

        int key = sc.nextInt();
        int idx = arr.length/2;
        while(true){

            if(arr[idx] == key){
                break;
            }
        }
    }
}