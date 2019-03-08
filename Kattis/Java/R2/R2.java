package R2;

import Katto.Kattio;

public class R2 {
	static Kattio io = new Kattio(System.in, System.out);
	public static void main(String[] args) {
		io.println(-io.getInt()+2*io.getInt());
		io.close();
	}
}
