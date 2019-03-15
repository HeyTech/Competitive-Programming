package aaah;

import kattio.Kattio;

public class Aaah {
    private static Kattio io = new Kattio(System.in, System.out);
    public static void main(String[] args) {
        io.println((io.getWord().length() >= io.getWord().length()) ? "go" : "no");
        io.close();
    }
}