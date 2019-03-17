package sigmaJava;

public class Node<Point> {
    public Node<Point> parent;
    public Point data;

    public Node(Point current) {
        this.parent = null;
        this.data = current;
    }

    public Node(Node<Point> parent, Point current) {
        this.parent = parent;
        this.data = current;
    }
}
