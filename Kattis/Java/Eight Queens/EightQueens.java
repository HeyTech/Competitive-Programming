package eightQueens;
import java.util.HashMap;
import java.util.Map;


import kattio.Kattio;

public class EightQueens {
	static Kattio io = new Kattio(System.in, System.out);
	public static void main(String[] args) {
		Map<Integer, int[]> dict = new HashMap<Integer, int[]>();
		boolean valid = true;
		
			for (int y = 0; y < 8; y++) {  // 8×8 chess board
				String wo = io.getWord();
				int x = wo.indexOf("*"); // searching for the index of the queen (x-axis)
				int res = wo.chars().reduce(0, (a, c) -> a + (c == '*' ? 1 : 0));

				if(res == 1 && valid){
					for (int j = 0; j < dict.size() ; j++) {  // calculating the slope for all previous queens 
						int[] temp = dict.get(j);
						if (Math.abs((double)(x-temp[0])/(y-temp[1])) == 1){  // if slope is equal to 1, means the queens can attack each other diagonally 
							valid = false;
						}
						else if(y == temp[1] || x == temp[0]){
							valid = false;
						}
					}
					int[] a = {x, y};
					dict.put(y, a);
				}
				else{
					valid = false;
				}
			}
			
		if(!valid){
			io.print("invalid");
		}else{
			io.print("valid");
		}
		io.close();
	}

}
