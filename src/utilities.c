#include "../include/utilities.h"
#include "../include/cursor_control.h"
#include "../include/linked_list.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "stdbool.h"
#include "conio.h"

employee* create_employee_data(LinkedList* head) {
	while (true) {
		show_console_cursor();
		LinkedList* p = head;
		system("cls");
		system("color 03");
		employee* data = (employee*)malloc(sizeof(employee));
		printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
		printf("\t\t\t\t\t\t  工资管理系统\n\n");
		printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
		printf("\t\t\t\t◆                请输入职工信息                  ◆\n\n");
		printf("\t\t\t\t===============>职工号：");
		scanf("%d", &data->id);
		bool flag = false;
		while (p->next != NULL) {
			if (p->next->data.id == data->id) {
				printf("\n\n\n\t\t\t\t\t◆ 职工号已存在！请重新输入!!! ◆\n\n");
				printf("\n\t\t\t\t\t\t(按任意键继续)\n\n");
				getch();
				flag = true;
				break;
			}
			p = p->next;
		}
		if (flag)continue;
		printf("\t\t\t\t===============>姓名：");
		scanf("%s", data->name);
		printf("\t\t\t\t===============>基本工资：");
		scanf("%f", &data->salary);
		printf("\t\t\t\t===============>奖金：");
		scanf("%f", &data->bonus);
		printf("\t\t\t\t===============>罚金：");
		scanf("%f", &data->fine);
		data->actual = data->salary + data->bonus - data->fine;
		hide_console_cursor();
		system("cls");
		printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
		printf("\t\t\t\t\t\t  工资管理系统\n\n");
		printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
		printf("\t\t\t\t◆                 请确认信息                     ◆\n\n");
		printf("\t\t\t\t\t\t职工号：%d\n", data->id);
		printf("\t\t\t\t\t\t姓名：%s\n", data->name);
		printf("\t\t\t\t\t\t基本工资：%.2f\n", data->salary);
		printf("\t\t\t\t\t\t奖金：%.2f\n", data->bonus);
		printf("\t\t\t\t\t\t罚金：%.2f\n", data->fine);
		printf("\t\t\t\t\t\t实发工资：%.2f\n", data->actual);
		printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
		int i = 16;
		printf("\t\t\t\t◆                  确认                          ◆\n\n");
		printf("\t\t\t\t◆                  重新输入                      ◆\n\n");
		printf("\t\t\t\t◆                  取消                          ◆\n\n");
		gotoXY(70, i);
		printf("<=====");
		getchar();
		while (true) {
			char ch = getch();
			if (ch == 13) {
				switch (i) {
				case 16:
					printf("\n\n\n\n\n\t\t\t\t\t\t◆创建成功！◆\n\n");
					printf("\n\t\t\t\t\t\t(按任意键继续)\n\n");
					getch();
					return data;
				case 18:
					printf("\n\n\t\t\t\t\t\t◆请重新输入◆\n\n");
					printf("\n\t\t\t\t\t\t(按任意键继续)\n\n");
					getch();
					i = 16;
					break;
				case 20:
					return NULL;
				}
				break;
			}
			else if (ch == -32) {
				ch = getch();
				printf("\b\b\b\b\b\b      ");
				switch (ch) {
				case 72:
					if (i != 16)i -= 2;
					break;
				case 80:
					if (i != 20)i += 2;
					break;
				}
				gotoXY(70, i);
				printf("<=====");
			}
		}
	}
}

employee* update_by_id(LinkedList* head, int id) {
	system("cls");
	system("color 03");
	LinkedList* p = head;
	employee* new_data = (employee*)malloc(sizeof(employee));
	bool flag = false;
	while (p->next != NULL) {
		if (p->next->data.id == id) {
			*new_data = p->next->data;
			flag = true;
			break;
		}
		p = p->next;
	}
	while (true) {
		if (flag) {
			system("cls");
			printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
			printf("\t\t\t\t\t\t  工资管理系统\n\n");
			printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
			printf("\t\t\t\t编号 姓名 基本工资  奖金      罚金     实发工资\n");
			printf("\t\t\t\t%-5d%-5s%-10.2f%-10.2f%-9.2f%-9.2f\n\n", new_data->id, new_data->name, new_data->salary, new_data->bonus, new_data->fine, new_data->actual);
			printf("\t\t\t\t◆                  修改姓名                      ◆\n\n");
			printf("\t\t\t\t◆                  修改基本工资                  ◆\n\n");
			printf("\t\t\t\t◆                  修改奖金                      ◆\n\n");
			printf("\t\t\t\t◆                  修改罚金                      ◆\n\n");
			printf("\t\t\t\t◆                  退出                          ◆\n\n");
			int i = 9;
			gotoXY(70, i);
			printf("<=====");
			while (true) {
				char ch = getch();
				if (ch == 13) {
					show_console_cursor();
					switch (i) {
					case 9:
						printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t◆请重新输入◆\n\n\n");
						printf("\t\t\t\t===============>姓名：");
						scanf("%s", new_data->name);
						break;
					case 11:
						printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t◆请重新输入◆\n\n\n");
						printf("\t\t\t\t===============>基本工资：");
						scanf("%f", &new_data->salary);
						break;
					case 13:
						printf("\n\n\n\n\n\n\t\t\t\t\t\t◆请重新输入◆\n\n\n");
						printf("\t\t\t\t===============>奖金：");
						scanf("%f", &new_data->bonus);
						break;
					case 15:
						printf("\n\n\n\n\n\n\t\t\t\t\t\t◆请重新输入◆\n\n\n");
						printf("\t\t\t\t===============>罚金：");
						scanf("%f", &new_data->fine);
						break;
					case 17:
						return new_data;
					}
					new_data->actual = new_data->salary + new_data->bonus - new_data->fine;
					hide_console_cursor();
					break;
				}
				else if (ch == -32) {
					ch = getch();
					printf("\b\b\b\b\b\b      ");
					switch (ch) {
					case 72:
						if (i != 9)i -= 2;
						break;
					case 80:
						if (i != 17)i += 2;
						break;
					}
					gotoXY(70, i);
					printf("<=====");
				}
			}
		}
		else {
			system("cls");
			printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
			printf("\t\t\t\t\t\t  工资管理系统\n\n");
			printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
			printf("\t\t\t\t                   查无此人!!!                    \n\n");
			printf("\t\t\t\t◆                  重新输入                      ◆\n\n");
			printf("\t\t\t\t◆                  退出                          ◆\n\n");
			int i = 8;
			gotoXY(70, i);
			printf("<=====");
			while (true) {
				char ch = getch();
				if (ch == 13) {
					switch (i) {
					case 8:
						printf("\n\n\n\n\t\t\t\t\t\t◆请重新输入◆\n\n");
						printf("\n\t\t\t\t\t\t(按任意键继续)\n\n");
						getch();
						update_node(head);
						return;
					case 10:
						return NULL;
					}
				}
				else if (ch == -32) {
					ch = getch();
					printf("\b\b\b\b\b\b      ");
					switch (ch) {
					case 72:
						if (i != 8)i -= 2;
						break;
					case 80:
						if (i != 10)i += 2;
						break;
					}
					gotoXY(70, i);
					printf("<=====");
				}
			}
		}
	}
}

