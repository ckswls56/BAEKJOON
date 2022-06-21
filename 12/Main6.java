package map;

import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;


public class Main6 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		int m = in.nextInt();
		HashMap<Integer, Integer> a = new HashMap<Integer,Integer>();
		HashMap<Integer, Integer> b = new HashMap<Integer,Integer>();
		int a_arr[] = new int[n];
		int b_arr[] = new int[m];
		
		for(int i=0; i<n; i++) {
			a_arr[i] = in.nextInt();
			a.put(a_arr[i],a_arr[i]);
		}
		
	
		for(int i=0; i<m;i++) {
			b_arr[i] = in.nextInt();
			b.put(b_arr[i],b_arr[i]);
		}
		
		int count = 0;
		
		for(int i=0; i<n; i++) {
			int temp = a_arr[i];
			if(b.get(temp)==null)
				count++;
		}
	
		for(int i=0; i<m; i++) {
			int temp = b_arr[i];
			if(a.get(temp)==null)
				count++;
		}
		
		System.out.println(count);
		
	}
}
