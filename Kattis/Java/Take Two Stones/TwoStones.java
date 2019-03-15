package TakeTwoStones;

import java.util.Scanner;

public class TwoStones {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNextLong()) {
			long a = sc.nextLong();
			if (a %2 == 0){
				System.out.println("Bob");
			}
			else{
				System.out.println("Alice");
			}
			// solve test case and output answer
		}
		sc.close();
	}
}
