#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include "../include/utilities.h"
#include "../include/linked_list.h"
#include "../include/file_io.h"
#include "../include/pattern.h"
#include "../include/menu.h"
#include "../include/cursor_control.h"

int main(void) {
	LinkedList* head = create_linked_list();
	//print_startup_screen();
	read_file(head);
	//print_startup_message();
	hide_console_cursor();
	main_menu();
	int i = 9;
	while (true) {
		char ch = getch();
		if (ch == 13) {
			switch (i) {
			case 9:
				insert_node(head);
				main_menu();
				i = 9;
				break;
			case 11:
				update_node(head);
				main_menu();
				i = 9;
				break;
			case 13:
				main_menu();
				i = 9;
				break;
			case 15:
				search_node(head);
				main_menu();
				i = 9;
				break;
			case 17:
				main_menu();
				i = 9;
				break;
			case 19:
				save_file(head);
				return 0;
			}
		}
		else if (ch == -32) {
			ch = getch();
			printf("\b\b\b\b\b\b      ");
			switch (ch) {
			case 72:
				if (i != 9)i -= 2;
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
