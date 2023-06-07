#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>
#include "../include/utilities.h"
#include "../include/cursor_control.h"
#include "../include/linked_list.h"
#include "../include/menu.h"


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
		print_menu_header();
		print_input_prompt();
		print_id_prompt();
		scanf("%d", &data->id);
		bool flag = false;
		while (p->next != NULL) {
			if (p->next->data.id == data->id) {
				hide_console_cursor();
				printf("\n\n\n\t\t\t\t\t 职工号已存在！请重新输入!!! (按任意键继续)\n\n");
				getch();
				flag = true;
				break;
			}
			p = p->next;
		}
		if (flag)continue;
		print_name_prompt();
		scanf("%s", data->name);
		print_salary_prompt();
		scanf("%f", &data->salary);
		print_bonus_prompt();
		scanf("%f", &data->bonus);
		print_fine_prompt();
		scanf("%f", &data->fine);
		data->actual = data->salary + data->bonus - data->fine;
		hide_console_cursor();
		system("cls");
		print_menu_header();
		printf("\t\t\t\t◆                 请确认信息                     ◆\n\n");
		printf("\t\t\t\t\t\t职工号：%d\n", data->id);
		printf("\t\t\t\t\t\t姓名：%s\n", data->name);
		printf("\t\t\t\t\t\t基本工资：%.2f\n", data->salary);
		printf("\t\t\t\t\t\t奖金：%.2f\n", data->bonus);
		printf("\t\t\t\t\t\t罚金：%.2f\n", data->fine);
		printf("\t\t\t\t\t\t实发工资：%.2f\n", data->actual);
		printf("\t\t\t\t——————————————————————————————————————————————————\n\n");
		int i = 16;
		print_confirm_options();
		gotoXY(70, i);
		print_arrow();
		getchar();
		while (true) {
			char ch = getch();
			if (ch == 13) {
				switch (i) {
				case 16:
					i = 16;
					break;
				case 18:
					printf("\n\n\n\n\n\n\t\t\t\t\t\t创建成功！(按任意键继续)\n");
					getch();
					return data;
				case 20:
					return NULL;
				}
				break;
			}
			else if (ch == -32) {
				ch = getch();
				clear_arrow();
				switch (ch) {
				case 72:
					if (i != 16)i -= 2;
					break;
				case 80:
					if (i != 20)i += 2;
					break;
				}
				gotoXY(70, i);
				print_arrow();
			}
		}
	}
}

employee* update_employee_data(LinkedList* head, int id) {
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
			system("color 03");
			print_menu_header();
			print_salary_header();
			printf("\t\t\t\t%-8d%-8s%-10.2f%-10.2f%-9.2f%-9.2f\n\n", new_data->id, new_data->name, new_data->salary, new_data->bonus, new_data->fine, new_data->actual);
			print_update_menu();
			int i = 10;
			gotoXY(70, i);
			print_arrow();
			while (true) {
				char ch = getch();
				if (ch == 13) {
					show_console_cursor();
					switch (i) {
					case 10:
						printf("\n\n\n\n\n\n\n\n\n\n");
						print_input_prompt();
						print_name_prompt();
						scanf("%s", new_data->name);
						break;
					case 12:
						printf("\n\n\n\n\n\n\n\n");
						print_input_prompt();
						print_salary_prompt();
						scanf("%f", &new_data->salary);
						break;
					case 14:
						printf("\n\n\n\n\n\n");
						print_input_prompt();
						print_bonus_prompt();
						scanf("%f", &new_data->bonus);
						break;
					case 16:
						printf("\n\n\n\n");
						print_input_prompt();
						print_fine_prompt();
						scanf("%f", &new_data->fine);
						break;
					case 18:
						return new_data;
					}
					new_data->actual = new_data->salary + new_data->bonus - new_data->fine;
					hide_console_cursor();
					break;
				}
				else if (ch == -32) {
					ch = getch();
					clear_arrow();
					switch (ch) {
					case 72:
						if (i != 10)i -= 2;
						break;
					case 80:
						if (i != 18)i += 2;
						break;
					}
					gotoXY(70, i);
					print_arrow();
				}
			}
		}
		else {
			system("cls");
			print_menu_header();
			print_search_error_menu();
			int i = 8;
			gotoXY(70, i);
			print_arrow();
			while (true) {
				char ch = getch();
				if (ch == 13) {
					switch (i) {
					case 8:
						printf("\n\n\n\n\t\t\t\t\t\t请重新输入(按任意键继续)\n");
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
					clear_arrow();
					switch (ch) {
					case 72:
						if (i != 8)i -= 2;
						break;
					case 80:
						if (i != 10)i += 2;
						break;
					}
					gotoXY(70, i);
					print_arrow();
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
		print_menu_header();
		print_search_menu();
		int i = 6;
		gotoXY(70, i);
		print_arrow();
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
				clear_arrow();
				switch (ch) {
				case 72:
					if (i != 6)i -= 2;
					break;
				case 80:
					if (i != 10)i += 2;
					break;
				}
				gotoXY(70, i);
				print_arrow();
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
	print_menu_header();
	print_input_prompt();
	print_id_prompt();
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
			print_menu_header();
			printf("\t\t\t\t\t\t职工号：%d\n", p->next->data.id);
			printf("\t\t\t\t\t\t姓名：%s\n", p->next->data.name);
			printf("\t\t\t\t\t\t基本工资：%.2f\n", p->next->data.salary);
			printf("\t\t\t\t\t\t奖金：%.2f\n", p->next->data.bonus);
			printf("\t\t\t\t\t\t罚金：%.2f\n", p->next->data.fine);
			printf("\t\t\t\t\t\t实发工资：%.2f\n\n", p->next->data.actual);
			print_options();
			int i = 14;
			gotoXY(70, i);
			print_arrow();
			while (true) {
				char ch = getch();
				if (ch == 13) {
					switch (i) {
					case 14:
						search_by_id(head);
						return;
					case 16:
						return;
					}
				}
				else if (ch == -32) {
					ch = getch();
					clear_arrow();
					switch (ch) {
					case 72:
						if (i != 14)i -= 2;
						break;
					case 80:
						if (i != 16)i += 2;
						break;
					}
					gotoXY(70, i);
					print_arrow();
				}
			}
		}
		else {
			system("cls");
			print_menu_header();
			print_search_error_menu();
			int i = 8;
			gotoXY(70, i);
			print_arrow();
			while (true) {
				char ch = getch();
				if (ch == 13) {
					switch (i) {
					case 8:
						printf("\n\n\n\n\t\t\t\t\t\t请重新输入(按任意键继续)\n");
						getch();
						search_by_id(head);
						return;
					case 10:
						return;
					}
				}
				else if (ch == -32) {
					ch = getch();
					clear_arrow();
					switch (ch) {
					case 72:
						if (i != 8)i -= 2;
						break;
					case 80:
						if (i != 10)i += 2;
						break;
					}
					gotoXY(70, i);
					print_arrow();
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
	print_menu_header();
	print_input_prompt();
	print_name_prompt();
	scanf("%s", name);
	hide_console_cursor();
	bool flag = false;
	int count = 0;
	system("cls");
	while (p->next != NULL) {
		if (strcmp(p->next->data.name, name) == 0) {
			if (count == 0) {
				print_menu_header();
				print_salary_header();
			}
			printf("\t\t\t\t%-8d%-8s%-10.2f%-10.2f%-9.2f%-9.2f\n", p->next->data.id, p->next->data.name, p->next->data.salary, p->next->data.bonus, p->next->data.fine, p->next->data.actual);
			count++;
			flag = true;
		}
		p = p->next;
	}
	while (true) {
		if (flag) {
			print_options();
			int i = 9 + count;
			int left = i;
			int right = left + 2;
			gotoXY(70, i);
			print_arrow();
			while (true) {
				char ch = getch();
				if (ch == 13) {
					if (i == 9 + count) {
						search_by_name(head);
						return;
					}
					else {
						return;
					}
				}
				else if (ch == -32) {
					ch = getch();
					clear_arrow();
					switch (ch) {
					case 72:
						if (i != left)i -= 2;
						break;
					case 80:
						if (i != right)i += 2;
						break;
					}
					gotoXY(70, i);
					print_arrow();
				}
			}
		}
		else {
			system("cls");
			print_menu_header();
			print_search_error_menu();
			int i = 8;
			gotoXY(70, i);
			print_arrow();
			while (true) {
				char ch = getch();
				if (ch == 13) {
					switch (i) {
					case 8:
						printf("\n\n\n\n\t\t\t\t\t\t请重新输入(按任意键继续)\n");
						getch();
						search_by_name(head);
						return;
					case 10:
						return;
					}
				}
				else if (ch == -32) {
					ch = getch();
					clear_arrow();
					switch (ch) {
					case 72:
						if (i != 8)i -= 2;
						break;
					case 80:
						if (i != 10)i += 2;
						break;
					}
					gotoXY(70, i);
					print_arrow();
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
	system("color 03");
	print_menu_header();
	print_input_prompt();
	print_id_prompt();
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
			print_menu_header();
			printf("\t\t\t\t\t\t职工号：%d\n", temp->data.id);
			printf("\t\t\t\t\t\t姓名：%s\n", temp->data.name);
			printf("\t\t\t\t\t\t基本工资：%.2f\n", temp->data.salary);
			printf("\t\t\t\t\t\t奖金：%.2f\n", temp->data.bonus);
			printf("\t\t\t\t\t\t罚金：%.2f\n", temp->data.fine);
			printf("\t\t\t\t\t\t实发工资：%.2f\n\n", temp->data.actual);
			printf("\t\t\t\t\t\t确认删除吗？\n\n");
			print_confirm_options();
			int i = 15;
			gotoXY(70, i);
			print_arrow();
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
					clear_arrow();
					switch (ch) {
					case 72:
						if (i != 15)i -= 2;
						break;
					case 80:
						if (i != 19)i += 2;
						break;
					}
					gotoXY(70, i);
					print_arrow();
				}
			}
		}
		else {
			system("cls");
			print_menu_header();
			print_search_error_menu();
			int i = 8;
			gotoXY(70, i);
			print_arrow();
			while (true) {
				char ch = getch();
				if (ch == 13) {
					switch (i) {
					case 8:
						printf("\n\n\n\n\t\t\t\t\t\t请重新输入(按任意键继续)\n");
						getch();
						delete_employee_data(head);
						return;
					case 10:
						return;
					}
				}
				else if (ch == -32) {
					ch = getch();
					clear_arrow();
					switch (ch) {
					case 72:
						if (i != 8)i -= 2;
						break;
					case 80:
						if (i != 10)i += 2;
						break;
					}
					gotoXY(70, i);
					print_arrow();
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
		print_menu_header();
		print_sort_menu();
		int i = 6;
		gotoXY(70, i);
		print_arrow();
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
				clear_arrow();
				switch (ch) {
				case 72:
					if (i != 6)i -= 2;
					break;
				case 80:
					if (i != 10)i += 2;
					break;
				}
				gotoXY(70, i);
				print_arrow();
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