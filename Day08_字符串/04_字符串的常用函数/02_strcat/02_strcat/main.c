#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
// strcat �� C ����������ƴ���ַ����ĺ���
// str �����ַ�����string����cat �� concatenate�����ӣ�����д��
// ��һ��������Ŀ���ַ�����destination�����ڶ���������Դ�ַ�����source���� ��Ŀ����ǰ��Դ�ں�������������ͷ����
int main() {
	char str1[10] = { 'a', 'b','c','\0' };
	char str2[10] = "ab2";
	char* str3 = "abc";
	strcat(str2, str1);
	printf("%s\n", str2); // abc2abc

	//strcat(str3, str1);    ֻ�����������ַ������޷���Ϊƴ�ӵ�Ŀ�괮,��ΪֻҪƴ�Ӿͻ�ı�ֵ��ָ�붨����ַ����Ǵ洢��ֻ���������ڵ�
	strcat(str2, str1);
	printf("%s\n", str2); // ab2abcabc 
	strcat(str2, str1); // �ᳬ�������С��10����������鱨��
	printf("%s\n", str2); // ab2abcabcabc 

	return 0;
}