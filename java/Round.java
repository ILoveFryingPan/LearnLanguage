
import java.text.DecimalFormat;
import java.math.BigDecimal;

public class Round{
	public static void main(String argc[]) {
		// ��ʽ����DecimalFormat��ʽ
		//DecimalFormatĬ�ϲ�����RoundingMode.HALF_EVEN��������,����format֮��Ľ����һ���ַ�������String
		DecimalFormat df = new DecimalFormat("#.000");
		System.out.println(df.format(new BigDecimal(1.0145)));//1.014
		System.out.println(df.format(new BigDecimal(1.1315)));//1.131
		
		
		// ��ʽһ��BigDecimal��ʽ
		double f = 3.1315;
		BigDecimal b = new BigDecimal(String.valueOf(f));
		double f1 = b.setScale(3, BigDecimal.ROUND_HALF_UP).doubleValue();
		System.out.println("��ʽһ��" + f1);
		//ע�⣺����һ����Ҫֱ��ʹ��new BigDecimal(double)�Ĺ��췽����
		//��Ҫʹ��new BigDecimal(new Double(1.1315).toString())�ķ�ʽ����Ȼ����־�ȷ����
	}
}