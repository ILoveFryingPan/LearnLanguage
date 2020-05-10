 
 import java.util.regex.Pattern;
 import java.util.regex.Matcher;
 
 public class Replace {
 /**
	 * 把其中的英文双引号变成中文
	 * @param str 需要替換的字符串
	 * @return
	 */
	public static String processUtil(String str ) {
		String regex = "(.*)\"(.*)\"(.*)";
		Pattern pattern = Pattern.compile(regex);
		Matcher matcher = pattern.matcher(str );
		while (matcher.find()) {
			str = matcher.group(1) + "“" + matcher.group(2) + "”" + matcher.group(3);
			matcher = pattern.matcher(str );
		}
		return str ;
	}
	
	public static void main(String[] args) {
 
 
		 String content = "【患者主因\"发现右乳癌4年，多程治疗后进展广泛皮肤转移化疗中\"入院\"】";
		 System.out.println("原来的字符串是："+content);
		 String result = processUtil(content);
		 System.out.println("替换后字符串是："+result);
    }
 }