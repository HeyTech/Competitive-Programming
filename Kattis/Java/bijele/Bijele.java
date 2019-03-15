// https://open.kattis.com/problems/bijele
// v1: 0.14 s
// v2: 0.14 s
// v3: 0.13 s
// v4: 0.14 s

package bijele;


import kattio.Kattio;

import java.util.Arrays;
import java.util.List;
import java.util.function.BinaryOperator;

public class Bijele {
    private static final Kattio io = new Kattio(System.in, System.out);

    public static void main(String[] args) {
        BinaryOperator<Integer> op = (a, b) -> (a - b);

        int[] cor = {1, 1, 2, 2, 2, 8};
        for(int i = 0; i < 6; i++){
            io.print(op.apply(cor[i], io.getInt()) + " ");
        }
        io.close();
    }

    /* version 3
    public static void main(String[] args) {
        int[] cor = {1, 1, 2, 2, 2, 8};
        for(int i = 0; i < 6; i++){
            io.print(cor[i] - io.getInt() + " ");
        }
        io.close();
    }
    */

    /* version 2
    public static void main(String[] args) {
        List<Integer> cards = Arrays.asList(1, 1, 2, 2, 2, 8);
        BinaryOperator<Integer> op = (a, b) -> (a - b);
        cards.forEach(var -> io.print(op.apply(var, io.getInt()) + " "));
        io.close();
    }
    *\

    /* version 1
    public static void main(String[] args) {
        List<Integer> cards = Arrays.asList(1, 1, 2, 2, 2, 8);
        cards.forEach(var -> io.print(var - io.getInt() + " "));
        io.close();
    }
    */

}
