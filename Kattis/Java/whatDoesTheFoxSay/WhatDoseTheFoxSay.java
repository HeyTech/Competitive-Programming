// https://open.kattis.com/problems/whatdoesthefoxsay

package whatDoesTheFoxSay;
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

class WhatDoseTheFoxSay {
  public static void main(String[] args) throws Exception {
    BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter dc = new BufferedWriter(new OutputStreamWriter(System.out));

    final int n = Integer.parseInt(sc.readLine());
    for (int i = 0; i < n; i++) {
      ArrayList<String> sounds = new ArrayList<String>(Arrays.asList(sc.readLine().split(" ")));
      while (true) {
        String l = sc.readLine();
        if (l.equals("what does the fox say?")) { break; }
        else { sounds.removeIf(l.split(" ")[2]::equals); }
      }
      for (String e : sounds){
        System.out.print(e + " ");
      }
    }
    sc.close(); dc.close();
  }
}
