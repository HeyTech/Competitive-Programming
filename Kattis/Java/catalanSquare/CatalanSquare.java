//https://open.kattis.com/problems/catalansquare

package catalanSquare;
import java.math.BigInteger;

import kattio.Kattio;
import profile.codeProfiler;

public class CatalanSquare {
	static Kattio io = new Kattio(System.in, System.out);	
	
	public static void solution(){
		int N = io.getInt();
		BigInteger[] c = new BigInteger[(N == 0 ? 1 : N+1)];
		c[0] = BigInteger.ONE;
		for (int i = 1; i < N +1; i++) {
			c[i] = (c[i-1].multiply(BigInteger.valueOf(4*i+2)).divide(BigInteger.valueOf(i+2)));
		}
		System.out.println(c[c.length-1]);
	}
	
	public static void main(String[] args) {
		try {
			codeProfiler.timeIt("code 0", () -> solution());	
		} catch (Exception e) {
			System.out.println("Error main");
		}	

		 
	}
}
