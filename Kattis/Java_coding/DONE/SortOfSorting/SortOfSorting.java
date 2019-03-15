// https://open.kattis.com/submissions/3918977
// V1: 0.59 s
// V1: 0.59 s

package SortOfSorting;

import kattio.Kattio;

import java.util.ArrayList;
import java.util.List;

public class SortOfSorting {
    private static Kattio io = new Kattio(System.in, System.out);

    // Version 2
    public static void main(String[] args) {
        int N;
        List<String> items;
        boolean first = true;

        while ((N = io.getInt()) > 0) {
            if (first) { first = false; } else { System.out.println(); }
            items = new ArrayList<>();
            for (int i = 0; i < N; i++) { items.add(io.getWord()); }

            items.stream()
                    .sorted((o1, o2) -> (o1.substring(0, 2)).compareTo(o2.substring(0, 2)))
                    .forEach(System.out::println);
        }
    }

    /* Version 1
    public static void main(String[] args) {
        int N;
        String[] items;
        boolean first = true;

        while ((N = io.getInt()) > 0) {
            if (first) {
                first = false;
            } else {
                System.out.println();
            }

            items = new String[N];

            for (int i = 0; i < items.length; i++) {
                items[i] = io.getWord();
            }
            Arrays.sort(items, Comparator.comparing(o -> o.substring(0, 2)));
            Arrays.asList(items).forEach(System.out::println);

        }
        io.close();
    }
    */
}
