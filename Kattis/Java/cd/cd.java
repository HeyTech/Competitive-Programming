// https://open.kattis.com/problems/cd

package cd;

import java.io.*;
import java.util.Arrays;

import kattio.Kattio;

public class cd {
    static Kattio io = new Kattio(System.in, System.out);
    public static void main(String[] args) throws IOException {
        int N;
        int M;
        int[] jack;

        while(true){
            N = io.getInt();
            M = io.getInt();
            if (N == 0 && M == 0) { break; }
            jack = new int[N];

            for (int i = 0; i < N; i++) {
                jack[i] = io.getInt();
            }

            int counter = 0;
            for (int i = 0; i < M; i++) {
                if (Arrays.binarySearch(jack, io.getInt()) >= 0) {
                    counter++;
                }
            }

            System.out.println(counter);

        }
        io.close();

    }

}
