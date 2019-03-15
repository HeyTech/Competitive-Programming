// https://open.kattis.com/problems/fizzbuzz
// v1: 0.09 s

package fizzBuzz;

import kattio.Kattio;

public class FizzBuzz {
    private static final Kattio io = new Kattio(System.in, System.out);

    public static void main(String[] args) {
        int x = io.getInt();
        int y = io.getInt();
        int n = io.getInt();
        boolean dx;
        boolean dy;

        for (int i = 1; i <= n; i++) {
            dy = i % y == 0;
            dx = i % x == 0;
            if (dx && dy) {
                io.println("FizzBuzz");
            } else if (dy) {
                io.println("Buzz");
            } else if (dx) {
                io.println("Fizz");
            } else {
                io.println(i);
            }
        }
        io.close();


    }
}
