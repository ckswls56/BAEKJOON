package map;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.StringTokenizer;


public class Main5{

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		
		HashMap<Integer, Integer> map = new HashMap<Integer,Integer>();
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i=0;i<n;i++) {
			int temp = Integer.parseInt(st.nextToken());
			
			if(map.containsKey(temp))
				map.put(temp, map.get(temp)+1);
			else
				map.put(temp, 1);
		}
		
		int m = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<m;i++) {
			int temp = Integer.parseInt(st.nextToken());
			bw.append(map.getOrDefault(temp, 0).toString()+" ");
		}
		bw.flush();
		
	}
}

