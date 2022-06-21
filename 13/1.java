import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int x,y,w,h;
		x=in.nextInt();
		y=in.nextInt();
		w=in.nextInt();
		h=in.nextInt();
		int res[] = new int[4];
		res[0]=x;
		res[1]=w-x;
		res[2]=y;
		res[3]=h-y;
		int min=1000;
		for(int i=0;i<4;i++) {
			if(res[i]<min)
				min=res[i];
		}
		System.out.println(min);
		
	}

}

