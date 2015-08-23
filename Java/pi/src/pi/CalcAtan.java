package pi;

import java.math.BigDecimal;
import java.math.RoundingMode;

/*
 * atan(1/x)���v�Z����B
 */
public class CalcAtan {
	
	static int scale=10;
	
	public static BigDecimal atan_1divx(int b){
		BigDecimal a_big = new BigDecimal(1);
		BigDecimal b_big = new BigDecimal(b);
		BigDecimal ret = new BigDecimal(0);
		
		a_big = a_big.divide(b_big, scale, RoundingMode.HALF_EVEN);
		ret = ret.add(a_big);
		
		//���[�v
		a_big = a_big.divide(b_big, scale, RoundingMode.HALF_EVEN);
		a_big = a_big.divide(b_big, scale, RoundingMode.HALF_EVEN);
		ret = ret.subtract(a_big.divide(new BigDecimal(3), 10, RoundingMode.HALF_EVEN));
		
		a_big = a_big.divide(b_big, scale, RoundingMode.HALF_EVEN);
		a_big = a_big.divide(b_big, scale, RoundingMode.HALF_EVEN);
		ret = ret.add(a_big.divide(new BigDecimal(5)));
		
		
		return ret;
	}
}
