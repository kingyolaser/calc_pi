package pi;

import java.math.BigDecimal;
import java.math.RoundingMode;

/*
 * atan(1/x)���v�Z����B
 */
public class CalcAtan {
	
	static final int scale=1000;
	
	public static BigDecimal atan_1divx(int b){
		BigDecimal a_big = new BigDecimal(1);
		BigDecimal b_big = new BigDecimal(b);
		BigDecimal ret = new BigDecimal(0);
		
		//scale�Ō��߂������łقڂO�ɂȂ�搔�����߂�B
		final int maxp = (int)(scale / Math.log10(b));
		
		a_big = a_big.divide(b_big, scale, RoundingMode.HALF_EVEN);
		ret = ret.add(a_big);
		
		//���[�v
		for( int i=3; ; i+=4 ){
			if( i>maxp ){
				break;
			}
			
			a_big = a_big.divide(b_big, scale, RoundingMode.HALF_EVEN);
			a_big = a_big.divide(b_big, scale, RoundingMode.HALF_EVEN);
			ret = ret.subtract(a_big.divide(new BigDecimal(i), scale, RoundingMode.HALF_EVEN));
			
			a_big = a_big.divide(b_big, scale, RoundingMode.HALF_EVEN);
			a_big = a_big.divide(b_big, scale, RoundingMode.HALF_EVEN);
			ret = ret.add(a_big.divide(new BigDecimal(i+2), scale, RoundingMode.HALF_EVEN ));
			
		}
		
		return ret;
	}
}
