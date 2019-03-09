//https://open.kattis.com/problems/catalansquare
// https://en.wikipedia.org/wiki/Catalan_number

package catalanSquare;
import java.math.BigInteger;
import kattio.Kattio;

public class CatalanSquare {
	static Kattio io = new Kattio(System.in, System.out);

	public static void main(String[] args) {
		int N = io.getInt();
		BigInteger[] c = new BigInteger[(N == 0 ? 1 : N+1)];
		c[0] = BigInteger.ONE;
		for (int i = 1; i < N +1; i++) { // The Catalan numbers satisfy the recurrence relations
			c[i] = (c[i-1].multiply(BigInteger.valueOf(4*i+2)).divide(BigInteger.valueOf(i+2)));
		}
		System.out.println(c[c.length-1]);
	}
}
