

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class CmpFileTool {
    /**
     * 判断两个文件的内容是否相同，文件名要用绝对路径
     * @param fileName1 ：文件1的绝对路径
     * @param fileName2 ：文件2的绝对路径
     * @return 相同返回true，不相同返回false
     */
    public static boolean isSameFile(String fileName1,String fileName2){
        FileInputStream fis1 = null;
        FileInputStream fis2 = null;
        try {
            fis1 = new FileInputStream(fileName1);
            fis2 = new FileInputStream(fileName2);

            int len1 = fis1.available();//返回总的字节数
            int len2 = fis2.available();

            if (len1 == len2) {//长度相同，则比较具体内容
                //建立两个字节缓冲区
                byte[] data1 = new byte[len1];
                byte[] data2 = new byte[len2];

                //分别将两个文件的内容读入缓冲区
                fis1.read(data1);
                fis2.read(data2);

                //依次比较文件中的每一个字节
                for (int i=0; i<len1; i++) {
                    //只要有一个字节不同，两个文件就不一样
                    if (data1[i] != data2[i]) {
                        System.out.println("文件内容不一样");
                        return false;
                    }
                }
                System.out.println("两个文件完全相同");
                return true;
            } else {
				int minLength = 0;
				if(len1 > len2) {
					minLength = len2;
				} else {
					minLength = len1;
				}
				
				//建立两个字节缓冲区
                byte[] data1 = new byte[len1];
                byte[] data2 = new byte[len2];

                //分别将两个文件的内容读入缓冲区
                fis1.read(data1);
                fis2.read(data2);

                //依次比较文件中的每一个字节
                for (int i=0; i < minLength; i++) {
                    //只要有一个字节不同，两个文件就不一样
                    if (data1[i] != data2[i]) {
						int min = 0;
						int max = 0;
						if(i > 20) {
							min = i - 20;
						} else {
							min = 0;
						}
						
						if(i + 20 < minLength) {
							max = i + 20;
						} else {
							max = minLength - 1;
						}
						
						byte[] showData = new byte[max - min + 1];
						System.out.println("min:" + min + "max:" + max + "minLength:" + minLength);
						for(int j = min; j <= max; j++) {
							showData[j - min] = data1[j];
						}
						String showStr = new String(showData);
						System.out.println("不同的地方：" + showStr);
                        System.out.println("文件内容不一样");
                        return false;
                    }
                }
				
                //长度不一样，文件肯定不同
				System.out.println("两个文件长度不一样");
                return false;
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {//关闭文件流，防止内存泄漏
            if (fis1 != null) {
                try {
                    fis1.close();
                } catch (IOException e) {
                    //忽略
                    e.printStackTrace();
                }
            }
            if (fis2 != null) {
                try {
                    fis2.close();
                } catch (IOException e) {
                    //忽略
                    e.printStackTrace();
                }
            }
        }
		System.out.println("比较发生了异常");
        return false;
    }
	
	public static void main(String args[]) {
		System.out.println("参数的个数：" + args.length + "\n");
		for(int i = 0; i < args.length; i++) {
			System.out.println(i + "参数的值：" + args[i] + "\n");
		}
		
		if(args.length != 2) {
			System.out.println("参数个数不对");
			return;
		}
		
		if(isSameFile(args[0], args[1])) {
			System.out.println("文件相同");
		} else {
			System.out.println("文件不同");
		}
	}
}
