import java.io.*;
import java.util.*;

public class Baek_11047 {
	static int n,k,ans;
	static int[] arr;
	public static void main (String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		arr = new int[n];		
		for(int i = 0; i<n; i++){
			arr[i]= Integer.parseInt(br.readLine());
		}

		Arrays.sort(arr);
		
		int idx = n-1;
		int tmp = k;
		while(tmp != 0){
			int a = tmp/arr[idx];
			if(a != 0){
				tmp -= a*arr[idx];
				ans += a;
			}
		idx--;
		}
        
        System.out.println(ans);
	}
}
