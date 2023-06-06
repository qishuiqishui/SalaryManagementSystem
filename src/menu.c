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
	printf("\t\t\t\t★             Ⅱ.删除职工工资信息               ★\n\n");
	printf("\t\t\t\t☆             Ⅲ.修改职工工资信息               ☆\n\n");
	printf("\t\t\t\t★             Ⅳ.查询职工工资信息               ★\n\n");
	printf("\t\t\t\t☆             Ⅴ.信息总查询                     ☆\n\n");
	printf("\t\t\t\t★             Ⅵ.工资排名查询                   ★\n\n");
	printf("\t\t\t\t☆             Ⅶ.保存文件                       ☆\n\n");
	printf("\t\t\t\t★             Ⅷ.保存文件并退出                 ★\n\n");
	printf("使用说明：上下键选择，回车键确定\n");
	gotoXY(70, i);
	printf("<=====");
}

void print_menu_header() {
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
	printf("\t\t\t\t\t\t  工资管理系统\n\n");
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
}

void print_search_error_menu() {
	printf("\t\t\t\t                   查无此人!!!                    \n\n");
	printf("\t\t\t\t◆                  重新输入                      ◆\n\n");
	printf("\t\t\t\t◆                  退出                          ◆\n\n");
}

void print_salary_header() {
	printf("\t\t\t\t编号    姓名    基本工资  奖金      罚金     实发工资\n\n");
}

void print_sort_menu() {
	printf("\t\t\t\t◆                  基本工资排序                  ◆\n\n");
	printf("\t\t\t\t◆                  实发工资排序                  ◆\n\n");
	printf("\t\t\t\t◆                  退出                          ◆\n\n");
}

void print_search_menu() {
	printf("\t\t\t\t◆                  ID查找                        ◆\n\n");
	printf("\t\t\t\t◆                  姓名查找                      ◆\n\n");
	printf("\t\t\t\t◆                  退出                          ◆\n\n");
}

void print_update_menu() {
	printf("\t\t\t\t◆                  修改姓名                      ◆\n\n");
	printf("\t\t\t\t◆                  修改基本工资                  ◆\n\n");
	printf("\t\t\t\t◆                  修改奖金                      ◆\n\n");
	printf("\t\t\t\t◆                  修改罚金                      ◆\n\n");
	printf("\t\t\t\t◆                  退出                          ◆\n\n");
}

void print_input_prompt() {
	printf("\t\t\t\t                请输入                          \n\n");
}

void print_name_prompt() {
	printf("\t\t\t\t===============>姓名：");
}

void print_id_prompt() {
	printf("\t\t\t\t===============>职工号：");
}


void print_salary_prompt() {
	printf("\t\t\t\t===============>基本工资：");
}

void print_bonus_prompt() {
	printf("\t\t\t\t===============>奖金：");
}

void print_fine_prompt() {
	printf("\t\t\t\t===============>罚款：");
}

void print_arrow() {
	printf("<=====");
}

void clear_arrow() {
	printf("\b\b\b\b\b\b      ");
}

void print_confirm_options() {
	printf("\t\t\t\t◆                  重新输入                      ◆\n\n");
	printf("\t\t\t\t◆                  确认                          ◆\n\n");
	printf("\t\t\t\t◆                  取消                          ◆\n\n");
}

void print_options() {
	printf("\n\t\t\t\t◆                  重新输入                      ◆\n\n");
	printf("\t\t\t\t◆                  退出                          ◆\n\n");
}