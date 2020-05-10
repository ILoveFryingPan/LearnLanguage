

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class CmpFileTool {
    /**
     * �ж������ļ��������Ƿ���ͬ���ļ���Ҫ�þ���·��
     * @param fileName1 ���ļ�1�ľ���·��
     * @param fileName2 ���ļ�2�ľ���·��
     * @return ��ͬ����true������ͬ����false
     */
    public static boolean isSameFile(String fileName1,String fileName2){
        FileInputStream fis1 = null;
        FileInputStream fis2 = null;
        try {
            fis1 = new FileInputStream(fileName1);
            fis2 = new FileInputStream(fileName2);

            int len1 = fis1.available();//�����ܵ��ֽ���
            int len2 = fis2.available();

            if (len1 == len2) {//������ͬ����ȽϾ�������
                //���������ֽڻ�����
                byte[] data1 = new byte[len1];
                byte[] data2 = new byte[len2];

                //�ֱ������ļ������ݶ��뻺����
                fis1.read(data1);
                fis2.read(data2);

                //���αȽ��ļ��е�ÿһ���ֽ�
                for (int i=0; i<len1; i++) {
                    //ֻҪ��һ���ֽڲ�ͬ�������ļ��Ͳ�һ��
                    if (data1[i] != data2[i]) {
                        System.out.println("�ļ����ݲ�һ��");
                        return false;
                    }
                }
                System.out.println("�����ļ���ȫ��ͬ");
                return true;
            } else {
				int minLength = 0;
				if(len1 > len2) {
					minLength = len2;
				} else {
					minLength = len1;
				}
				
				//���������ֽڻ�����
                byte[] data1 = new byte[len1];
                byte[] data2 = new byte[len2];

                //�ֱ������ļ������ݶ��뻺����
                fis1.read(data1);
                fis2.read(data2);

                //���αȽ��ļ��е�ÿһ���ֽ�
                for (int i=0; i < minLength; i++) {
                    //ֻҪ��һ���ֽڲ�ͬ�������ļ��Ͳ�һ��
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
						System.out.println("��ͬ�ĵط���" + showStr);
                        System.out.println("�ļ����ݲ�һ��");
                        return false;
                    }
                }
				
                //���Ȳ�һ�����ļ��϶���ͬ
				System.out.println("�����ļ����Ȳ�һ��");
                return false;
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {//�ر��ļ�������ֹ�ڴ�й©
            if (fis1 != null) {
                try {
                    fis1.close();
                } catch (IOException e) {
                    //����
                    e.printStackTrace();
                }
            }
            if (fis2 != null) {
                try {
                    fis2.close();
                } catch (IOException e) {
                    //����
                    e.printStackTrace();
                }
            }
        }
		System.out.println("�ȽϷ������쳣");
        return false;
    }
	
	public static void main(String args[]) {
		System.out.println("�����ĸ�����" + args.length + "\n");
		for(int i = 0; i < args.length; i++) {
			System.out.println(i + "������ֵ��" + args[i] + "\n");
		}
		
		if(args.length != 2) {
			System.out.println("������������");
			return;
		}
		
		if(isSameFile(args[0], args[1])) {
			System.out.println("�ļ���ͬ");
		} else {
			System.out.println("�ļ���ͬ");
		}
	}
}
