#include "../include/pattern.h"
#include<stdio.h>
#include<windows.h>

void print_startup_screen()
{
	system("color EC");
	//system("color F0");
	printf("           *********                                                                         *****         *****\n");
	Sleep(200);
	printf("       *****************                                                                   *********     *********\n");
	Sleep(200);
	printf("    *********     *********                                                              ************* *************\n");
	Sleep(200);
	printf("   *********       ********                                                             *****************************\n");
	Sleep(200);
	printf("  ***********     *******                                                               *****************************\n");
	Sleep(200);
	printf(" *********************           ****          ****          ****          ****         *****************************\n");
	Sleep(200);
	printf(" ******************            ********      ********      ********      ********         **************************\n");
	Sleep(200);
	printf("****************              **********    **********    **********    **********         ***********************\n");
	Sleep(200);
	printf(" ******************            ********      ********      ********      ********            *******************\n");
	Sleep(200);
	printf(" *********************           ****          ****          ****          ****                ***************\n");
	Sleep(200);
	printf("  ************************                                                                       ***********\n");
	Sleep(200);
	printf("   *************************                                                                       *******\n");
	Sleep(200);
	printf("    ***********************                                                                          ***\n");
	Sleep(200);
	printf("       *****************                                                                              *\n");
	Sleep(200);
	printf("           *********                                                             \n");
	Sleep(200);
}

void print_startup_message() {
	printf("\n\n\n");
	printf("欢");
	Sleep(200);
	printf(" 迎");
	Sleep(200);
	printf(" 使");
	Sleep(200);
	printf(" 用");
	Sleep(200);
	printf(" 工");
	Sleep(200);
	printf(" 资");
	Sleep(200);
	printf(" 管");
	Sleep(200);
	printf(" 理");
	Sleep(200);
	printf(" 系");
	Sleep(200);
	printf(" 统！");
	Sleep(200);
	printf(" (请按任意键进入...)");
	getchar();
}
