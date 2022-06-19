import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner in = new Scanner(System.in);
		
		int N = in.nextInt();
		
		int[] origin = new int[N];
		int[] sorted = new int[N];
		HashMap<Integer, Integer> rankMap = new HashMap<Integer,Integer>();
		
		for(int i=0;i<N;i++) {
			sorted[i] = origin[i] = in.nextInt();
		}
		
		Arrays.sort(sorted);
		
		int rank=0;
		for(int v : sorted) {
			
			if(!rankMap.containsKey(v)) {
				rankMap.put(v, rank++);
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for(int key : origin) {
			int ranking = rankMap.get(key);
			sb.append(ranking).append(' ');
		}
		
		System.out.println(sb);
		in.close();
	}

}
