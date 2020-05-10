 
 import java.util.regex.Pattern;
 import java.util.regex.Matcher;
 
 public class Replace {
 /**
	 * �����е�Ӣ��˫���ű������
	 * @param str ��Ҫ��Q���ַ���
	 * @return
	 */
	public static String processUtil(String str ) {
		String regex = "(.*)\"(.*)\"(.*)";
		Pattern pattern = Pattern.compile(regex);
		Matcher matcher = pattern.matcher(str );
		while (matcher.find()) {
			str = matcher.group(1) + "��" + matcher.group(2) + "��" + matcher.group(3);
			matcher = pattern.matcher(str );
		}
		return str ;
	}
	
	public static void main(String[] args) {
 
 
		 String content = "����������\"�������鰩4�꣬������ƺ��չ�㷺Ƥ��ת�ƻ�����\"��Ժ\"��";
		 System.out.println("ԭ�����ַ����ǣ�"+content);
		 String result = processUtil(content);
		 System.out.println("�滻���ַ����ǣ�"+result);
    }
 }