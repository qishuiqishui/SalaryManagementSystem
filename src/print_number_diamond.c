#include <stdio.h>
#include <math.h>
#include <windows.h>
#include "../include/print_number_diamond.h"

// 数字棱形
void print_number_diamond() {
	system("cls");//清屏
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
	printf("\t\t\t\t\t\t    数字菱形\n\n");
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
	printf("\t\t\t\t    【题目】设计程序打印n(n≤17)行上下对称的数字空\n\n");
	printf("\t\t\t\t心菱形，第一行为1个1，第二行前后各为2个2……其中n由\n\n");
	printf("\t\t\t\t键盘输入，如图所示。使用循环方法编程。\n\n");
	printf("\t\t\t\t    【编程提示】图形上下对称，应用绝对值函数e=fabs(\n\n");
	printf("\t\t\t\tk-d)，其中k为循环变量，取1，2，…，n（n为奇数)，d=\n\n");
	printf("\t\t\t\t(n+1)/2。每行打印x+2*e个空格和d-e个数字，除首尾两 \n\n");
	printf("\t\t\t\t行，其余需打印中间的空格和后d-e个数字。          \n\n");
	printf("\t\t\t\t                     1                        \n\n");
	printf("\t\t\t\t                  22   22                     \n\n");
	printf("\t\t\t\t                333     333                   \n\n");
	printf("\t\t\t\t              4444       4444                 \n\n");
	printf("\t\t\t\t                333     333                   \n\n");
	printf("\t\t\t\t                  22   22                     \n\n");
	printf("\t\t\t\t                     1                        \n\n");
	int n;													//行数
	printf("\n\n请输入n(行数):");
	scanf("%d", &n);
	for (int k = 1; k <= n; k++) {							//循环n次
		int d = (n + 1) / 2;								//行数的一半
		int e = fabs(k - d);								//保证e为正数
		for (int i = 1; i <= 3 * e; i++) {
			printf(" ");									//打印空格
		}
		for (int i = 1; i <= d - e; i++) {
			printf("%d", k);								//打印数字
		}
		if (k != 1 && k != n) {									//不在第一行和最后一行
			for (int i = 1; i <= 3 * (d - e) - 2; i++) {
				printf(" ");								//打印空格
			}
			for (int i = 1; i <= d - e; i++) {
				printf("%d", k);							//打印数字
			}
		}
		printf("\n");
	}
	getch();
}
