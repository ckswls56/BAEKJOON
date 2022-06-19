package map;

import java.util.HashMap;
import java.util.Scanner;

public class Main1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		HashMap<Integer, Boolean> map = new HashMap<Integer,Boolean>();
		
		int sangen[] = new int[n];
		for(int i: sangen) {
			sangen[i] = in.nextInt();
			map.put(sangen[i], true);
		}
		
		int m = in.nextInt();
		for(int i=0;i<m;i++) {
			if(map.get(in.nextInt())!=null)
				System.out.print("1 ");
			else
				System.out.print("0 ");
		}
		
	}

}
