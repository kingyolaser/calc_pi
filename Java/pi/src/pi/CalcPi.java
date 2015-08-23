
package pi;

import static pi.CalcAtan.atan_1divx;

import java.math.BigDecimal;

public class CalcPi {
	public static void main(String[] argv){
		BigDecimal a=atan_1divx(5).multiply(new BigDecimal(4));
		BigDecimal b=atan_1divx(239);
		
		BigDecimal pi = a.subtract(b).multiply(new BigDecimal(4));
				
		System.out.println(pi);
	}
}
