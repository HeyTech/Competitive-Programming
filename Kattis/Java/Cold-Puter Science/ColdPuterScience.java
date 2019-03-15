package coldPuterScience;

import kattio.Kattio;

public class ColdPuterScience {
    private static Kattio io = new Kattio(System.in, System.out);

    public static void main(String[] args) {
        final int n = io.getInt();
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (io.getInt() < 0) {
                counter++;
            }
        }
        io.println(counter);
        io.close();

    }
}
