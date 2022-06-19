package map;

import java.util.HashMap;
import java.util.Scanner;

public class Main2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		int m = in.nextInt();
		
		HashMap<String, Integer> map_stoi = new HashMap<String,Integer>();
		HashMap<Integer,String> map_itos = new HashMap<Integer,String>();
		
		for(int i=0; i < n; i++) {
			String temp = in.next();
			map_stoi.put(temp, i+1);
			map_itos.put(i+1,temp );
		}
		
		
		for(int i=0;i<m;i++) {
			String temp = in.next();
			if(Character.isDigit(temp.charAt(0)))
				System.out.println(map_itos.get(Integer.parseInt(temp)));
			else
				System.out.println(map_stoi.get(temp));
		}
		

		
	}

}
