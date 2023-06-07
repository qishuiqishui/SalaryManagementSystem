#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "../include/sell_goldfish.h"


void sell_goldfish() {
	system("cls");//清屏
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
	printf("\t\t\t\t\t\t    出售金鱼\n\n");
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
	printf("\t\t\t\t    【题目】买买提将养的一缸金鱼分5次出售:第1次实\n\n");
	printf("\t\t\t\t出全部的一半加二分之一条；第2次卖出余下的三分之一\n\n");
	printf("\t\t\t\t加三分之一条；第3次卖出余下的四分之一加四分之一条；\n\n");
	printf("\t\t\t\t第4次卖出余下的五分之一加五分之一条；最后卖出余下\n\n");
	printf("\t\t\t\t的11条。间:原来的鱼缸有几条金鱼?使用循环方法求解。\n\n");
	printf("\t\t\t\t    【编程提示】题目中所有的鱼是分5次出售的，每次卖 \n\n");
	printf("\t\t\t\t出的策略相同:第j次卖剩下的（j+1）分之一再加l/（j+1)\n\n");
	printf("\t\t\t\t条。第5次将第4次余下的11条全卖了。假定第j次鱼的总 \n\n");
	printf("\t\t\t\t数为x，则第j次余下x-（x+1）/（j+1）。当第4次出售\n\n");
	printf("\t\t\t\t完毕时，应该剩下11条。若x满足上述要求，则x就是题目\n\n");
	printf("\t\t\t\t的解。注意，(x+1 )/(j+1)应满足整除条件。\n\n");
	int x;

	for (x = 1;; x++) {
		int j;
		int remaining = x;

		for (j = 1; j <= 4; j++) {
			remaining = remaining - (remaining / (j + 1)) - 1;
		}

		if (remaining == 11) {
			break;
		}
	}

	printf("原来的鱼缸有%d条金鱼\n", x);
	getch();
}