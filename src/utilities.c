#include "../include/utilities.h"
#include "../include/cursor_control.h"
#include "../include/linked_list.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "stdbool.h"
#include "conio.h"

int compare_salary(const void* a, const void* b) {
	const employee* emp1 = (const employee*)a;
	const employee* emp2 = (const employee*)b;
	return  (emp1->salary < emp2->salary) - (emp1->salary > emp2->salary);
}

int compare_actual(const void* a, const void* b) {
	const employee* emp1 = (const employee*)a;
	const employee* emp2 = (const employee*)b;
	return (emp1->actual < emp2->actual) - (emp1->actual > emp2->actual);
}

int compare_id(const void* a, const void* b) {
	const employee* emp1 = (const employee*)a;
	const employee* emp2 = (const employee*)b;
	return emp1->id - emp2->id;
}

employee* list_to_array(LinkedList* head) {
	int size = get_linked_list_size(head);
	employee* arr = (employee*)malloc(sizeof(employee) * size);
	LinkedList* current = head->next;
	for (int i = 0; i < size; i++) {
		arr[i] = current->data;
		current = current->next;
	}
	// 返回数组指针
	return arr;
}

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

employee* update_employee_data(LinkedList* head, int id) {
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
						printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t◆请输入◆\n\n");
						printf("\t\t\t\t===============>姓名：");
						scanf("%s", new_data->name);
						break;
					case 11:
						printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t◆请输入◆\n\n");
						printf("\t\t\t\t===============>基本工资：");
						scanf("%f", &new_data->salary);
						break;
					case 13:
						printf("\n\n\n\n\n\n\t\t\t\t\t\t◆请输入◆\n\n");
						printf("\t\t\t\t===============>奖金：");
						scanf("%f", &new_data->bonus);
						break;
					case 15:
						printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t◆请输入◆\n\n");
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
						printf("\n\n\n\n\t\t\t\t\t\t◆请重新输入◆\n");
						printf("\n\t\t\t\t\t\t(按任意键继续)\n\n");
						getch();
						free(new_data);
						update_node(head);
						return NULL;
					case 10:
						free(new_data);
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

void search_employee_data(LinkedList* head) {
	system("cls");
	system("color 03");
	while (true) {
		system("cls");
		printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
		printf("\t\t\t\t\t\t  工资管理系统\n\n");
		printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
		printf("\t\t\t\t◆                  ID查找                        ◆\n\n");
		printf("\t\t\t\t◆                  姓名查找                      ◆\n\n");
		printf("\t\t\t\t◆                  退出                          ◆\n\n");
		int i = 6;
		gotoXY(70, i);
		printf("<=====");
		while (true) {
			char ch = getch();
			if (ch == 13) {

				switch (i) {
				case 6:
					search_by_id(head);
					break;
				case 8:
					search_by_name(head);
					break;
				case 10:
					return;
				}
				break;
			}
			else if (ch == -32) {
				ch = getch();
				printf("\b\b\b\b\b\b      ");
				switch (ch) {
				case 72:
					if (i != 6)i -= 2;
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

void search_by_id(LinkedList* head) {
	LinkedList* p = head;
	int id;
	system("cls");
	system("color 03");
	show_console_cursor();
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
	printf("\t\t\t\t\t\t  工资管理系统\n\n");
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
	printf("\t\t\t\t◆                请输入职工信息                  ◆\n\n");
	printf("\t\t\t\t===============>职工号：");
	scanf("%d", &id);
	hide_console_cursor();
	bool flag = false;
	while (p->next != NULL) {
		if (p->next->data.id == id) {
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
			printf("\t\t\t\t\t\t职工号：%d\n", p->next->data.id);
			printf("\t\t\t\t\t\t姓名：%s\n", p->next->data.name);
			printf("\t\t\t\t\t\t基本工资：%.2f\n", p->next->data.salary);
			printf("\t\t\t\t\t\t奖金：%.2f\n", p->next->data.bonus);
			printf("\t\t\t\t\t\t罚金：%.2f\n", p->next->data.fine);
			printf("\t\t\t\t\t\t实发工资：%.2f\n\n", p->next->data.actual);
			printf("\t\t\t\t◆                  重新输入                      ◆\n\n");
			printf("\t\t\t\t◆                  退出                          ◆\n\n");
			int i = 13;
			gotoXY(70, i);
			printf("<=====");
			while (true) {
				char ch = getch();
				if (ch == 13) {
					switch (i) {
					case 13:
						search_by_id(head);
						return;
					case 15:
						return;
					}
				}
				else if (ch == -32) {
					ch = getch();
					printf("\b\b\b\b\b\b      ");
					switch (ch) {
					case 72:
						if (i != 13)i -= 2;
						break;
					case 80:
						if (i != 15)i += 2;
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
						printf("\n\n\n\n\t\t\t\t\t\t◆请重新输入◆\n");
						printf("\t\t\t\t\t\t(按任意键继续)\n\n");
						getch();
						search_by_id(head);
						return;
					case 10:
						return;
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

void search_by_name(LinkedList* head) {
	LinkedList* p = head;
	char name[100];
	system("cls");
	system("color 03");
	show_console_cursor();
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
	printf("\t\t\t\t\t\t  工资管理系统\n\n");
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
	printf("\t\t\t\t◆                请输入职工信息                  ◆\n\n");
	printf("\t\t\t\t===============>姓名：");
	scanf("%s", name);
	hide_console_cursor();
	bool flag = false;
	int count = 0;
	system("cls");
	while (p->next != NULL) {
		if (strcmp(p->next->data.name, name) == 0) {
			if (count == 0) {
				printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
				printf("\t\t\t\t\t\t  工资管理系统\n\n");
				printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
				printf("\t\t\t\t编号    姓名    基本工资  奖金      罚金     实发工资\n\n");
			}
			printf("\t\t\t\t%-8d%-8s%-10.2f%-10.2f%-9.2f%-9.2f\n", p->next->data.id, p->next->data.name, p->next->data.salary, p->next->data.bonus, p->next->data.fine, p->next->data.actual);
			count++;
			flag = true;
		}
		p = p->next;
	}
	while (true) {
		if (flag) {
			printf("\t\t\t\t◆                  重新输入                      ◆\n\n");
			printf("\t\t\t\t◆                  退出                          ◆\n\n");
			int i = 8 + count;
			int left = i;
			int right = left + 2;
			gotoXY(70, i);
			printf("<=====");
			while (true) {
				char ch = getch();
				if (ch == 13) {
					if (i == 8 + count) {
						search_by_name(head);
						return;
					}
					else {
						return;
					}
				}
				else if (ch == -32) {
					ch = getch();
					printf("\b\b\b\b\b\b      ");
					switch (ch) {
					case 72:
						if (i != left)i -= 2;
						break;
					case 80:
						if (i != right)i += 2;
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
						printf("\n\n\n\n\t\t\t\t\t\t◆请重新输入◆\n");
						printf("\t\t\t\t\t\t(按任意键继续)\n\n");
						getch();
						search_by_name(head);
						return;
					case 10:
						return;
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

void delete_employee_data(LinkedList* head) {
	LinkedList* p = head;
	LinkedList* temp;
	int id;
	show_console_cursor();
	system("cls");
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
	printf("\t\t\t\t\t\t  工资管理系统\n\n");
	printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
	printf("\t\t\t\t◆                请输入要删除职工的ID             ◆\n\n");
	printf("\t\t\t\t===============>职工号：");
	scanf("%d", &id);
	hide_console_cursor();
	bool flag = false;
	while (p->next != NULL) {
		if (p->next->data.id == id) {
			temp = p->next;
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
			printf("\t\t\t\t\t\t职工号：%d\n", temp->data.id);
			printf("\t\t\t\t\t\t姓名：%s\n", temp->data.name);
			printf("\t\t\t\t\t\t基本工资：%.2f\n", temp->data.salary);
			printf("\t\t\t\t\t\t奖金：%.2f\n", temp->data.bonus);
			printf("\t\t\t\t\t\t罚金：%.2f\n", temp->data.fine);
			printf("\t\t\t\t\t\t实发工资：%.2f\n\n", temp->data.actual);
			printf("\t\t\t\t\t\t确认删除吗？\n\n");
			printf("\t\t\t\t◆                  重新输入                      ◆\n\n");
			printf("\t\t\t\t◆                  确认                          ◆\n\n");
			printf("\t\t\t\t◆                  退出                          ◆\n\n");
			int i = 15;
			gotoXY(70, i);
			printf("<=====");
			while (true) {
				char ch = getch();
				if (ch == 13) {
					switch (i) {
					case 15:
						delete_node(head);
						return;
					case 17:
						p->next = p->next->next;
						free(temp);
						printf("已经成功删除！");
						return;
					case 19:
						return;
					}
				}
				else if (ch == -32) {
					ch = getch();
					printf("\b\b\b\b\b\b      ");
					switch (ch) {
					case 72:
						if (i != 15)i -= 2;
						break;
					case 80:
						if (i != 19)i += 2;
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
						printf("\n\n\n\n\t\t\t\t\t\t◆请重新输入◆\n");
						printf("\t\t\t\t\t\t(按任意键继续)\n\n");
						getch();
						search_by_id(head);
						return;
					case 10:
						return;
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

void sort_employee(LinkedList* head) {
	system("cls");
	system("color 03");
	while (true) {
		system("cls");
		printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
		printf("\t\t\t\t\t\t  工资管理系统\n\n");
		printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
		printf("\t\t\t\t◆                  基本工资排序                  ◆\n\n");
		printf("\t\t\t\t◆                  实际工资排序                  ◆\n\n");
		printf("\t\t\t\t◆                  退出                          ◆\n\n");
		int i = 6;
		gotoXY(70, i);
		printf("<=====");
		while (true) {
			char ch = getch();
			if (ch == 13) {
				switch (i) {
				case 6:
					sort_by_salary(head);
					print_linked_list(head);
					break;
				case 8:
					sort_by_actual(head);
					print_linked_list(head);
					break;
				case 10:
					return;
				}
				break;
			}
			else if (ch == -32) {
				ch = getch();
				printf("\b\b\b\b\b\b      ");
				switch (ch) {
				case 72:
					if (i != 6)i -= 2;
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

void sort_by_salary(LinkedList* head) {
	int size = get_linked_list_size(head);

	// 将链表转换为数组
	employee* arr = list_to_array(head);

	// 使用 qsort 函数进行排序
	qsort(arr, size, sizeof(employee), compare_salary);

	// 更新链表中的数据
	LinkedList* current = head->next;
	for (int i = 0; i < size; i++) {
		current->data = arr[i];
		current = current->next;
	}

	// 释放数组内存
	free(arr);
}

void sort_by_id(LinkedList* head) {
	int size = get_linked_list_size(head);

	// 将链表转换为数组
	employee* arr = list_to_array(head);

	// 使用 qsort 函数进行排序
	qsort(arr, size, sizeof(employee), compare_id);

	// 更新链表中的数据
	LinkedList* current = head->next;
	for (int i = 0; i < size; i++) {
		current->data = arr[i];
		current = current->next;
	}

	// 释放数组内存
	free(arr);
}

void sort_by_actual(LinkedList* head) {
	int size = get_linked_list_size(head);

	// 将链表转换为数组
	employee* arr = list_to_array(head);

	// 使用 qsort 函数进行排序
	qsort(arr, size, sizeof(employee), compare_actual);

	// 更新链表中的数据
	LinkedList* current = head->next;
	for (int i = 0; i < size; i++) {
		current->data = arr[i];
		current = current->next;
	}

	// 释放数组内存
	free(arr);
}