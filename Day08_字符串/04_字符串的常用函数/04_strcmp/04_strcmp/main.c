#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// strcmp �� C ���������ڱȽ������ַ����ĺ��������Ĺ����ǱȽ������ַ��������ݣ������ݱȽϽ������һ������ֵ
//����ֵ
//  ����ֵ <  0��str1 С�� str2�����ֵ�˳�򣩡�
//	����ֵ == 0��str1 �� str2 ��ȡ�
//	����ֵ >  0��str1 ���� str2�����ֵ�˳�򣩡�
// 
// str �����ַ�����string����
// cmp �� compare���Ƚϣ�����д��
int main() {
    char str1[] = "apple";
    char str2[] = "banana";
    char str3[] = "apple";

    int result1 = strcmp(str1, str2); // "apple" vs "banana"
    int result2 = strcmp(str1, str3); // "apple" vs "apple"

    printf("Result1: %d\n", result1); // -1 ���������"apple" < "banana"��  "apple" С�� "banana" ����Ϊ 'a' < 'b'��'a'��97���� 'b'��98����
    printf("Result2: %d\n", result2); // 0  ��� 0��"apple" == "apple"��

	return 0;
}