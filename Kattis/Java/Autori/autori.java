package Autori;

import Katto.Kattio;

public class autori {
	static Kattio io = new Kattio(System.in);
	public static void main(String[] args) {
		StringBuilder sb = new StringBuilder();  // PS: Not safe for thread synchronization
		String[] na = io.getWord().split("-");
		
		for(String a : na){
			sb.append(a.charAt(0));
		}
		io.print(sb);
		io.close();
	}
}
