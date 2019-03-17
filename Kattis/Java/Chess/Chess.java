package sigmaJava;

import kattio.Kattio;
// import kattio.Timeit;

import java.awt.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;


public class ProblemC {
    private static Kattio io = new Kattio(System.in, System.out);

    /**
     * @param c, convert a char to int: (’A’ to ’H’) - (1 to 8).
     */
    private static int charToInt(char c) {
        return c - 'A' + 1;
    }

    /**
     * @param c, convert an int to char: (1 to 8) - (’A’ to ’H’).
     */
    private static char IntToChar(int c) {
        return (char) (64 + c);
    }

    /**
     * Fill the chess board with:
     * start = 1,
     * target = 2,
     * visited 0,
     * non-visited = -1
     *
     * @param start, .
     */
    private static int[][] fillChess(Point start, Point target) {
        int[][] chess = new int[8][8];
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                chess[i][j] = -1;
            }
        }
        chess[8 - start.y][start.x - 1] = 1;
        chess[8 - target.y][target.x - 1] = 2;

        return chess;
    }


    public static int[][] addNeigToChess(int[][] chess, Point p) {
        chess[8 - p.y][p.x - 1] = 0;
        return chess;
    }

    public static int checkChessValue(int[][] chess, Point p) {
        return chess[8 - p.y][p.x - 1];
    }


    /**
     * Printing the map, easier to visualize
     *
     * @param chess:
     */
    private static void printChess(int[][] chess) {
        System.out.println();
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (chess[i][j] > -1) {
                    System.out.print(" " + chess[i][j] + " ");
                } else {
                    System.out.print(chess[i][j] + " ");
                }
            }
            System.out.println();
        }
    }

    /**
     * Getting all the diagonally neighbours of the current position
     *
     * @param p, current position
     * @return : a new LinkedList of all possible neighbours
     */
    private static LinkedList<Point> getNeighbour(Point p) {
        LinkedList<Point> temp;
        LinkedList<Point> neig = new LinkedList<>();
        neig.add(p);
        int i = 8;
        while (--i > 0) {
            temp = new LinkedList<>();
            temp.add(new Point(p.x + i, p.y + i));
            temp.add(new Point(p.x - i, p.y + i));
            temp.add(new Point(p.x + i, p.y - i));
            temp.add(new Point(p.x - i, p.y - i));
            for (Point po : temp) {
                if (po.x <= 8 && po.y <= 8) {
                    if (po.x > 0 && po.y > 0) {
                        neig.add(po); // diagonally up right
                    }
                }
            }
        }
        return neig;
    }


    public static void runSolution() {
        int t = io.getInt(); // reading number of test cases
        Queue<Node<Point>> queue;
        ArrayList<ArrayList> pathTarget;
        Point start, target;
        int[][] chess;

        while (t-- > 0) {
            pathTarget = new ArrayList<ArrayList>();
            queue = new LinkedList<>(); // Creating a Queue for Breadth first search
            start = new Point(charToInt(io.getWord().charAt(0)), io.getInt()); // start position of bishop
            target = new Point(charToInt(io.getWord().charAt(0)), io.getInt()); // target position of bishop

            chess = fillChess(start, target);
            Node<Point> start_node = new Node<Point>(start);
            Node<Point> current;

            if (start.equals(target)) {
                io.println(0 + " " + IntToChar(start.x) + " " + start.y);
            } else {
                queue.add(start_node);
                while (!queue.isEmpty()) {
                    current = queue.remove();
                    LinkedList<Point> neig = getNeighbour(current.data);

                    for (Point p : neig) {
                        int value = checkChessValue(chess, p);

                        if (value == -1) {
                            addNeigToChess(chess, p);
                            queue.add(new Node<Point>(current, p));
                        } else if (value == 2) {
                            ArrayList<Point> temp_list = new ArrayList<Point>();
                            Node<Point> temp = new Node<>(current, p);

                            while (temp != null) {
                                //temp_list.add(temp.data);
                                temp_list.add(0, temp.data);
                                temp = temp.parent;
                            }
                            pathTarget.add(temp_list);
                            // io.println("FOUND!!!");
                        }
                    }
                    // printChess(chess);
                }

                if (pathTarget.size() > 0) {
                    int shortindex = 99;
                    int shortlength = 99;

                    for (int i = 0; i < pathTarget.size(); i++) {
                        if (pathTarget.get(i).size() < shortlength) {
                            shortlength = pathTarget.get(i).size();
                            shortindex = i;
                        }
                    }

                    if (shortlength <= 4) {
                        ArrayList<Point> shortesPath = pathTarget.get(shortindex);
                        io.print(shortlength - 1);
                        for (Point p : shortesPath) {
                            io.print(" " + IntToChar(p.x) + " " + p.y);
                        }
                        io.println();
                    } else {
                        io.println("Impossible");
                    }
                } else {
                    io.println("Impossible");
                }
            }
        }
    }


    public static void main(String[] args) {
        runSolution();
        /*
        Node<Point> start = new Node<Point>(new Point(1, 2));
        Node<Point> node = new Node<Point>(start, new Point(3, 3));
        System.out.println(start.data);
        System.out.println(node.parent.parent.data);
        */
        //Timeit.code(() -> runSolution());
        io.close();
        // Timeit.code(() -> test2());

    }
}
