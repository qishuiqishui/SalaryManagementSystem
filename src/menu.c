#include "../include/cursor_control.h"
#include "../include/menu.h"
#include "windows.h"
#include <stdio.h>

void main_menu() {
	int i = 9;
	system("cls");
	system("color EC");
	printf("\t\t                    \n");
	printf("\t\t                     (@^o^@) 欢迎使用工资管理管理系统 o(≧▽≦)o\n");
	printf("\t\t                    \n");
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
	printf("\t\t\t\t\t\t  工资管理系统\n\n");
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
	printf("\t\t\t\t☆             Ⅰ.创建职工工资信息               ☆\n\n");
	printf("\t\t\t\t★             Ⅱ.修改职工工资信息               ★\n\n");
	printf("\t\t\t\t☆             Ⅲ.删除职工工资信息               ☆\n\n");
	printf("\t\t\t\t★             Ⅳ.查询职工工资信息               ★\n\n");
	printf("\t\t\t\t☆             Ⅴ.信息总查询                     ☆\n\n");
	printf("\t\t\t\t★             Ⅵ.工资排名查询                   ★\n\n");
	printf("\t\t\t\t☆             Ⅶ.保存文件                       ☆\n\n");
	printf("\t\t\t\t★             Ⅷ.保存文件并退出                 ★\n\n");
	printf("使用说明：上下键选择，回车键确定\n");
	gotoXY(70, i);
	printf("<=====");
}