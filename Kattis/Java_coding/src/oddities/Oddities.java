package oddities;

import kattio.Kattio;

public class Oddities {
    private static Kattio io = new Kattio(System.in, System.out);

    public static void main(String[] args) {
        final int n = io.getInt();
        int x;
        for (int i = 0; i < n; i++) {
            x = io.getInt();
            io.println((x % 2 == 0) ? (x + " is even") : (x + " is odd"));
        }
        io.close();
    }
}
