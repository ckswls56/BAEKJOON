package map;

import java.util.HashMap;
import java.util.Scanner;

public class Main7 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		
		String str = in.nextLine();
		HashMap<String, Boolean> map = new HashMap<String,Boolean>();
		int count=0;
		
		for(int i=0;i<str.length();i++) {
			for(int j=i+1;j<=str.length();j++) {
				String temp = str.substring(i, j);
				if(!map.containsKey(temp)) {
					map.put(temp, true);
					count++;
				}
					
				
			}
		}
		
		System.out.println(count);
	}

}
