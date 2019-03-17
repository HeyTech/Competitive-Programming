package sigmaJava;

import kattio.Kattio;

public class TextureAnalysis {
    private static Kattio io = new Kattio(System.in, System.out);

    /*
     * Version 4: 0.35 s
     */
    public static void main(String[] args) {
        String line; // To read input line
        int counter = 0; // Counter according to the number of read inputs
        int dots, finDots;
        char c;

        while (!(line = io.getWord()).equals("END")) { // Read line and check if end of file
            dots = -1;
            finDots = -1;
            String text = " EVEN";

            for (int i = 0; i < line.length(); i++) { // iterate through the whole string
                c = line.charAt(i); // Fetch the char att the increasing index
                if (c == '*') { // Check if the current char is equals to '*'
                    if (finDots == -1) { // update the final dots, will be true till dots value changes, then never updates again
                        finDots = dots;
                    } else if (finDots != dots) {  // after finDots is updated, this if-statement checks if new pattern of (..) is equals to the first recorded pattern
                        text = " NOT EVEN";
                        break;
                    }
                    dots = 0; // reset dots every time char == '*'
                } else {
                    dots++;
                }
            }
            io.println(++counter + text);
        }
        io.close();
    }
}

