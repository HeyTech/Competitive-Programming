package stuckInATimeLoop;

import kattio.Kattio;

public class StuckInATimeLoop {
    private static Kattio io = new Kattio(System.in, System.out);
    public static void main(String[] args) {
        int n = io.getInt();
        for (int i = 1; i <= n; i++) {
            io.println(i + " Abracadabra");
        }
        io.close();
    }
}
