// https://open.kattis.com/problems/anothercandies

package AnotherCandies;

import kattio.Kattio;

import java.math.BigInteger;

public class AnotherCandies {
    private static Kattio io = new Kattio(System.in, System.out);


    // version 1: Run Time 0.19 s
    public static void main(String[] args) {
        int n;
        BigInteger sum; // > n^63 ??
        final int t = io.getInt(); // 0 < t < 100
        for (int i = 0; i < t; i++) {
            n = io.getInt();

            sum = BigInteger.ZERO;
            for (int j = 0; j < n; j++) {
                sum = sum.add(new BigInteger(io.getWord()));
            }
            io.println((sum.mod(BigInteger.valueOf(n)).equals(BigInteger.ZERO)) ? "YES" : "NO");
        }
        io.close();
    }
}