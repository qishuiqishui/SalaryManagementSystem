#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "../include/linked_list.h"
#include "../include/cursor_control.h"
#include "../include/menu.h"

// 创建节点
LinkedList* create_node(employee* data) {
	// 创建新节点
	LinkedList* node = (LinkedList*)malloc(sizeof(LinkedList));

	// 节点初始化
	node->data = *data;
	node->next = NULL;

	// 返回节点
	return node;
}

// 创建链表
LinkedList* create_linked_list() {
	// 创建头节点
	LinkedList* head = (LinkedList*)malloc(sizeof(LinkedList));

	// 头节点初始化
	head->next = NULL;

	// 返回头节点
	return head;
}

// 插入节点
void insert_node(LinkedList* head) {
	// 创建数据
	employee* data = create_employee_data(head);

	// 若返回NULL，表示用户退出，取消插入操作
	if (data == NULL) {
		return;
	}

	// 创建新节点
	LinkedList* node = create_node(data);

	// 链表头插法
	node->next = head->next;
	head->next = node;
}

// 删除节点
void delete_node(LinkedList* head) {
	delete_employee_data(head);
}

// 更新节点
void update_node(LinkedList* head) {
	LinkedList* p = head;
	int id;
	show_console_cursor();
	system("cls");
	system("color 03");
	print_menu_header();
	print_input_prompt();
	print_id_prompt();
	scanf("%d", &id);
	hide_console_cursor();
	employee* new_data = update_employee_data(head, id);
	if (new_data == NULL) {
		return;
	}
	while (p->next != NULL) {
		if (p->next->data.id == id) {
			p->next->data = *new_data;
			return;
		}
		p = p->next;
	}
}

// 查找节点
void search_node(LinkedList* head) {
	search_employee_data(head);
}

// 打印链表
void print_linked_list(LinkedList* head) {
	system("cls");
	LinkedList* p = head->next;
	print_menu_header();
	print_salary_header();
	while (p != NULL) {
		printf("\t\t\t\t%-8d%-8s%-10.2f%-10.2f%-9.2f%-9.2f\n", p->data.id, p->data.name, p->data.salary, p->data.bonus, p->data.fine, p->data.actual);
		p = p->next;
	}
	printf("\n\n\n\t\t\t\t按任意键返回菜单\n\n");
	getch();
}

// 获取链表长度
int get_linked_list_size(LinkedList* head) {
	int size = 0;
	LinkedList* p = head->next;
	while (p != NULL) {
		size++;
		p = p->next;
	}
	return size;
}

// 销毁链表
void destroy_linked_list(LinkedList* head) {
	LinkedList* current = head;
	LinkedList* next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
}

// 链表排序
void sort_linked_list(LinkedList* head) {
	sort_employee(head);
}