// https://open.kattis.com/problems/countingstars
/**
 * 4 4
 * --#-
 * #--#
 * -##-
 * ----
 *
 * Case #: 3
 */



package CountingStars;


import kattio.Kattio;

import java.awt.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class CountingStars {
    public static Kattio io = new Kattio(System.in, System.out);

    private static String[][] fillsky(int x, int y) {
        String[][] sky = new String[x][y];
        while (x-- > 0) {
            sky[x] = io.getWord().split("");
        }
        return sky;
    }

    private static void printSky(String[][] sky) {
        System.out.println();
        for (int i = 0; i < sky.length; i++) {
            for (int j = 0; j < sky[0].length; j++) {
                System.out.print(sky[i][j]);
            }
            System.out.println();
        }

    }

    private static ArrayList<Point> getNeighbours(String[][] sky, Point p) {

        int x = sky.length;
        int y = sky[0].length;

        ArrayList<Point> neig = new ArrayList<Point>() {
            {
                add(new Point(p.x, p.y + 1));
                //add(new Point(p.x + 1, p.y + 1));
                add(new Point(p.x + 1, p.y));
                //add(new Point(p.x + 1, p.y + -1));
                add(new Point(p.x, p.y + -1));
                //add(new Point(p.x + -1, p.y + -1));
                add(new Point(p.x + -1, p.y));
                //add(new Point(p.x + -1, p.y + 1));
            }
        };
        for (int i = neig.size() - 1; i >= 0; i--) {
            Point po = neig.get(i);
            // System.out.println(po.x + ":" + x + " - " + po.y + ":" +y);
            if (po.x >= x || po.x < 0 || po.y < 0 || po.y >= y || !sky[po.x][po.y].equals("-")) {
                //System.out.println("--- " + po.x + " " + po.y);
                neig.remove(i);
            }
        }
        return neig;


    }

    public static void runSolution() {
        int cases = 0;
        int counter;
        Queue<Point> queue;
        while (io.hasMoreTokens()) {
            int X = io.getInt();
            int Y = io.getInt();
            queue = new LinkedList<>();
            String[][] sky = fillsky(X, Y);
            counter = 0;
            for (int i = 0; i < X; i++) {
                for (int j = 0; j < Y; j++) {
                    if (sky[i][j].equals("-")) {
                        counter++;
                        queue.add(new Point(i, j));
                        while (!queue.isEmpty()) {
                            Point temp = queue.remove();
                            sky[temp.x][temp.y] = "*";
                            for (Point p : getNeighbours(sky, temp)) {
                                if (!queue.contains(p)) {
                                    queue.add(p);
                                }
                            }
                        }
                    }
                }
            }
            System.out.println("Case " + ++cases + ": " + counter);
            //io.println("Case " + ++cases + ": " + counter);
        }
    }


    public static void main(String[] args) {
        runSolution();
        io.close();
    }
}