#include <stdio.h>
#include <stdbool.h>
#include "../include/salary_management_system_menu.h"
#include "../include/utilities.h"
#include "../include/linked_list.h"
#include "../include/file_io.h"
#include "../include/pattern.h"
#include "../include/menu.h"
#include "../include/cursor_control.h"
#include "../include/print_number_diamond.h"
#include "../include/sell_goldfish.h"
#include "../include/salary_management_system_menu.h"

void init();
void function_service();

void salary_management_system() {
	init();
}
void init() {
	LinkedList* head = create_linked_list();
	print_startup_screen();
	read_file(head);
	print_startup_message();
	hide_console_cursor();
	salary_management_system_menu();
	function_service(head);
}

void function_service(LinkedList* head) {
	int i = 9;
	while (true) {
		char ch = getch();
		if (ch == 13) {
			switch (i) {
			case 9:
				insert_node(head);
				salary_management_system_menu();
				i = 9;
				break;
			case 11:
				delete_node(head);
				salary_management_system_menu();
				i = 9;
				break;
			case 13:
				update_node(head);
				salary_management_system_menu();
				i = 9;
				break;
			case 15:
				search_node(head);
				salary_management_system_menu();
				i = 9;
				break;
			case 17:
				print_linked_list(head);
				salary_management_system_menu();
				i = 9;
				break;
			case 19:
				sort_employee(head);
				salary_management_system_menu();
				i = 9;
				break;
			case 21:
				save_file(head);
				salary_management_system_menu();
				i = 9;
				break;
			case 23:
				save_and_exit(head);
				return 0;
			}
		}
		else if (ch == -32) {
			ch = getch();
			clear_arrow();
			switch (ch) {
			case 72:
				if (i != 9)i -= 2;
				break;
			case 80:
				if (i != 23)i += 2;
				break;
			}
			gotoXY(70, i);
			print_arrow();
		}
	}
}
