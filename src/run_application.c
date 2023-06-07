#include <stdbool.h>
#include <conio.h>
#include "../include/menu.h"
#include "../include/cursor_control.h"
#include "../include/print_number_diamond.h"
#include "../include/sell_goldfish.h"
#include "../include/salary_management_system_menu.h"


void run_application();

int main(void) {
	run_application();
	return 0;
}

void run_application() {
	main_menu();
	int i = 6;
	while (true) {
		char ch = getch();
		if (ch == 13) {
			switch (i) {
			case 6:
				sell_goldfish();
				main_menu();
				i = 6;
				break;
			case 8:
				print_number_diamond();
				main_menu();
				i = 6;
				break;
			case 10:
				salary_management_system();
				main_menu();
				i = 6;
				break;
			case 12:
				return;
			}
		}
		else if (ch == -32) {
			ch = getch();
			clear_arrow();
			switch (ch) {
			case 72:
				if (i != 6)i -= 2;
				break;
			case 80:
				if (i != 12)i += 2;
				break;
			}
			gotoXY(70, i);
			print_arrow();
		}
	}
}
