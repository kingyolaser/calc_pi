
package pi;

import static pi.CalcAtan.atan;

public class CalcPi {
	public static void main(String[] argv){
		double pi=4*atan(1);
		System.out.println(pi);
	}
}
