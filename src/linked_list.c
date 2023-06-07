#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/linked_list.h"
#include "../include/cursor_control.h"
#include "../include/menu.h"

LinkedList* create_node(employee* data) {
	LinkedList* node = (LinkedList*)malloc(sizeof(LinkedList));
	node->data = *data;
	node->next = NULL;
	return node;
}

LinkedList* create_linked_list() {
	LinkedList* head = (LinkedList*)malloc(sizeof(LinkedList));
	head->next = NULL; // 初始化链表为空
	return head;
}

void insert_node(LinkedList* head) {
	employee* data = create_employee_data(head);
	if (data == NULL) {
		return;
	}
	LinkedList* node = create_node(data);
	node->next = head->next;
	head->next = node;
}

void delete_node(LinkedList* head) {
	delete_employee_data(head);
}

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

void search_node(LinkedList* head) {
	search_employee_data(head);
}

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

int get_linked_list_size(LinkedList* head) {
	int size = 0;
	LinkedList* p = head->next;
	while (p != NULL) {
		size++;
		p = p->next;
	}
	return size;
}

void destroy_linked_list(LinkedList* head) {
	LinkedList* current = head;
	LinkedList* next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
}

void sort_linked_list(LinkedList* head) {
	sort_employee(head);
}