#include <windows.h>
#include <stdio.h>
#include "../include/cursor_control.h"
#include "../include/menu.h"

// 打印主菜单
void main_menu() {
	int i = 6;
	system("cls");
	system("color f3");
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
	printf("\t\t\t\t\t\t  课程设计系统\n\n");
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
	printf("\t\t\t\t☆             Ⅰ.出售金鱼                         ☆\n\n");
	printf("\t\t\t\t★             Ⅱ.数字棱形                         ★\n\n");
	printf("\t\t\t\t☆             Ⅲ.工资管理系统                     ☆\n\n");
	printf("\t\t\t\t★             Ⅳ.退出                             ★\n\n");
	printf("使用说明：上下键选择，回车键确定\n");
	gotoXY(70, i);
	printf("<=====");
}

// 打印工资管理系统菜单
void salary_management_system_menu() {
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

// 打印菜单标题
void print_menu_header() {
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
	printf("\t\t\t\t\t\t  工资管理系统\n\n");
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
}

// 打印错误菜单
void print_search_error_menu() {
	printf("\t\t\t\t                   查无此人!!!                    \n\n");
	printf("\t\t\t\t◆                  重新输入                      ◆\n\n");
	printf("\t\t\t\t◆                  退出                          ◆\n\n");
}

// 打印工资标题
void print_salary_header() {
	printf("\t\t\t\t编号    姓名    基本工资  奖金      罚金     实发工资\n\n");
}

// 打印排序标题
void print_sort_menu() {
	printf("\t\t\t\t◆                  基本工资排序                  ◆\n\n");
	printf("\t\t\t\t◆                  实发工资排序                  ◆\n\n");
	printf("\t\t\t\t◆                  退出                          ◆\n\n");
}

// 打印查找标题
void print_search_menu() {
	printf("\t\t\t\t◆                  ID查找                        ◆\n\n");
	printf("\t\t\t\t◆                  姓名查找                      ◆\n\n");
	printf("\t\t\t\t◆                  退出                          ◆\n\n");
}

// 打印更新标题
void print_update_menu() {
	printf("\t\t\t\t◆                  修改姓名                      ◆\n\n");
	printf("\t\t\t\t◆                  修改基本工资                  ◆\n\n");
	printf("\t\t\t\t◆                  修改奖金                      ◆\n\n");
	printf("\t\t\t\t◆                  修改罚金                      ◆\n\n");
	printf("\t\t\t\t◆                  退出                          ◆\n\n");
}

// 打印提示信息
void print_input_prompt() {
	printf("\t\t\t\t                请输入                          \n\n");
}

// 打印姓名提示
void print_name_prompt() {
	printf("\t\t\t\t===============>姓名：");
}

// 打印ID提示
void print_id_prompt() {
	printf("\t\t\t\t===============>职工号：");
}

// 打印基本工资提示
void print_salary_prompt() {
	printf("\t\t\t\t===============>基本工资：");
}

// 打印奖金提示
void print_bonus_prompt() {
	printf("\t\t\t\t===============>奖金：");
}

// 打印罚金提示
void print_fine_prompt() {
	printf("\t\t\t\t===============>罚款：");
}

// 打印箭头
void print_arrow() {
	printf("<=====");
}

// 清除箭头
void clear_arrow() {
	printf("\b\b\b\b\b\b      ");
}

// 打印确认信息
void print_confirm_options() {
	printf("\t\t\t\t◆                  重新输入                      ◆\n\n");
	printf("\t\t\t\t◆                  确认                          ◆\n\n");
	printf("\t\t\t\t◆                  取消                          ◆\n\n");
}

// 打印选项
void print_options() {
	printf("\n\t\t\t\t◆                  重新输入                      ◆\n\n");
	printf("\t\t\t\t◆                  退出                          ◆\n\n");
}