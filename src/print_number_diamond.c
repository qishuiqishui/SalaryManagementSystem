#include <stdio.h>
#include <math.h>
#include <windows.h>
#include "../include/print_number_diamond.h"

// ��������
void print_number_diamond() {
	system("cls");//����
	printf("\t\t\t\t����������������������������������������������������������������������������������������������������\n\n");
	printf("\t\t\t\t\t\t    ��������\n\n");
	printf("\t\t\t\t����������������������������������������������������������������������������������������������������\n\n");
	printf("\t\t\t\t    ����Ŀ����Ƴ����ӡn(n��17)�����¶ԳƵ����ֿ�\n\n");
	printf("\t\t\t\t�����Σ���һ��Ϊ1��1���ڶ���ǰ���Ϊ2��2��������n��\n\n");
	printf("\t\t\t\t�������룬��ͼ��ʾ��ʹ��ѭ��������̡�\n\n");
	printf("\t\t\t\t    �������ʾ��ͼ�����¶Գƣ�Ӧ�þ���ֵ����e=fabs(\n\n");
	printf("\t\t\t\tk-d)������kΪѭ��������ȡ1��2������n��nΪ����)��d=\n\n");
	printf("\t\t\t\t(n+1)/2��ÿ�д�ӡx+2*e���ո��d-e�����֣�����β�� \n\n");
	printf("\t\t\t\t�У��������ӡ�м�Ŀո�ͺ�d-e�����֡�          \n\n");
	printf("\t\t\t\t                     1                        \n\n");
	printf("\t\t\t\t                  22   22                     \n\n");
	printf("\t\t\t\t                333     333                   \n\n");
	printf("\t\t\t\t              4444       4444                 \n\n");
	printf("\t\t\t\t                333     333                   \n\n");
	printf("\t\t\t\t                  22   22                     \n\n");
	printf("\t\t\t\t                     1                        \n\n");
	int n;													//����
	printf("\n\n������n(����):");
	scanf("%d", &n);
	for (int k = 1; k <= n; k++) {							//ѭ��n��
		int d = (n + 1) / 2;								//������һ��
		int e = fabs(k - d);								//��֤eΪ����
		for (int i = 1; i <= 3 * e; i++) {
			printf(" ");									//��ӡ�ո�
		}
		for (int i = 1; i <= d - e; i++) {
			printf("%d", k);								//��ӡ����
		}
		if (k != 1 && k != n) {									//���ڵ�һ�к����һ��
			for (int i = 1; i <= 3 * (d - e) - 2; i++) {
				printf(" ");								//��ӡ�ո�
			}
			for (int i = 1; i <= d - e; i++) {
				printf("%d", k);							//��ӡ����
			}
		}
		printf("\n");
	}
	getch();
}
