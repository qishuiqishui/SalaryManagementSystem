#include <stdbool.h>
#include <conio.h>
#include "../include/menu.h"
#include "../include/cursor_control.h"
#include "../include/print_number_diamond.h"
#include "../include/sell_goldfish.h"
#include "../include/salary_management_system_menu.h"

// 运行应用程序的函数声明
void run_application();

int main(void) {
	// 调用 run_application 函数
	run_application();
	return 0;
}

void run_application() {
	// 调用主菜单函数
	main_menu();

	int i = 6; // 使用 6 初始化变量 'i'

	// 进入无限循环
	while (true) {
		char ch = getch(); // 从用户获取一个字符

		if (ch == 13) { // 检查用户是否按下回车键（ASCII码 13）
			switch (i) {
			case 6:
				sell_goldfish(); // 调用 sell_goldfish 函数
				main_menu(); // 调用主菜单函数
				i = 6; // 将 'i' 重置为 6
				break;
			case 8:
				print_number_diamond(); // 调用 print_number_diamond 函数
				main_menu(); // 调用主菜单函数
				i = 6; // 将 'i' 重置为 6
				break;
			case 10:
				salary_management_system(); // 调用 salary_management_system 函数
				main_menu(); // 调用主菜单函数
				i = 6; // 将 'i' 重置为 6
				break;
			case 12:
				return; // 退出 run_application 函数
			}
		}
		else if (ch == -32) { // 检查用户是否按下特殊键（箭头键）
			ch = getch(); // 获取实际的箭头键码

			clear_arrow(); // 调用 clear_arrow 函数

			switch (ch) {
			case 72: // 上箭头键
				if (i != 6)
					i -= 2; // 如果 'i' 不等于 6，则将其减去 2
				break;
			case 80: // 下箭头键
				if (i != 12)
					i += 2; // 如果 'i' 不等于 12，则将其加上 2
				break;
			}

			gotoXY(70, i); // 将光标位置设置为坐标 (70, i)
			print_arrow(); // 调用 print_arrow 函数
		}
	}
}
