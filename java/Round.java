
import java.text.DecimalFormat;
import java.math.BigDecimal;

public class Round{
	public static void main(String argc[]) {
		// 方式二：DecimalFormat方式
		//DecimalFormat默认采用了RoundingMode.HALF_EVEN这种类型,而且format之后的结果是一个字符串类型String
		DecimalFormat df = new DecimalFormat("#.000");
		System.out.println(df.format(new BigDecimal(1.0145)));//1.014
		System.out.println(df.format(new BigDecimal(1.1315)));//1.131
		
		
		// 方式一：BigDecimal方式
		double f = 3.1315;
		BigDecimal b = new BigDecimal(String.valueOf(f));
		double f1 = b.setScale(3, BigDecimal.ROUND_HALF_UP).doubleValue();
		System.out.println("方式一：" + f1);
		//注意：这里一定不要直接使用new BigDecimal(double)的构造方法，
		//而要使用new BigDecimal(new Double(1.1315).toString())的方式，不然会出现精确问题
	}
}