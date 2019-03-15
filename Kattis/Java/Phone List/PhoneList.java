package phoneList;

import kattio.Kattio;

import java.util.Arrays;

public class PhoneList {
    private static final Kattio io = new Kattio(System.in, System.out);

    public static void main(String[] args) {
        final int t = io.getInt();
        String[] phoneList;
        for (int i = 0; i < t; i++) {

            phoneList = new String[io.getInt()];
            for (int j = 0; j < phoneList.length; j++) {
                phoneList[j] = io.getWord();
            }
            Arrays.sort(phoneList);
            boolean found = false;
            for (int j = 1; j < phoneList.length; j++) {
                if (phoneList[j].startsWith(phoneList[j - 1])) {
                    found = true;
                }
            }
            io.println((found) ? "NO" : "YES");


        }
        io.close();
    }

}
