// https://open.kattis.com/problems/oddities
// Version 1: 0.13 s
// Version 2: 0.14 s

package oddities;

import kattio.Kattio;

interface evenOrOdd {
    void check(int a);
}

public class Oddities {
    private static Kattio io = new Kattio(System.in, System.out);

    public static void main(String[] args) {
        evenOrOdd task = (int a) -> {
            io.println((a % 2 == 0) ? (a + " is even") : (a + " is odd"));
        };

        final int n = io.getInt();
        for (int i = 0; i < n; i++) {
            task.check(io.getInt());
        }
        io.close();
    }

    /* Version 1
    public static void main(String[] args) {
        final int n = io.getInt();
        int x;
        for (int i = 0; i < n; i++) {
            x = io.getInt();
            io.println((x % 2 == 0) ? (x + " is even") : (x + " is odd"));
        }
        io.close();
    }
    */
}
