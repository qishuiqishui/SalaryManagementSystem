#include <stdbool.h>
#include <conio.h>
#include "../include/menu.h"
#include "../include/cursor_control.h"
#include "../include/print_number_diamond.h"
#include "../include/sell_goldfish.h"
#include "../include/salary_management_system_menu.h"

// ����Ӧ�ó���ĺ�������
void run_application();

int main(void) {
	// ���� run_application ����
	run_application();
	return 0;
}

void run_application() {
	// �������˵�����
	main_menu();

	int i = 6; // ʹ�� 6 ��ʼ������ 'i'

	// ��������ѭ��
	while (true) {
		char ch = getch(); // ���û���ȡһ���ַ�

		if (ch == 13) { // ����û��Ƿ��»س�����ASCII�� 13��
			switch (i) {
			case 6:
				sell_goldfish(); // ���� sell_goldfish ����
				main_menu(); // �������˵�����
				i = 6; // �� 'i' ����Ϊ 6
				break;
			case 8:
				print_number_diamond(); // ���� print_number_diamond ����
				main_menu(); // �������˵�����
				i = 6; // �� 'i' ����Ϊ 6
				break;
			case 10:
				salary_management_system(); // ���� salary_management_system ����
				main_menu(); // �������˵�����
				i = 6; // �� 'i' ����Ϊ 6
				break;
			case 12:
				return; // �˳� run_application ����
			}
		}
		else if (ch == -32) { // ����û��Ƿ������������ͷ����
			ch = getch(); // ��ȡʵ�ʵļ�ͷ����

			clear_arrow(); // ���� clear_arrow ����

			switch (ch) {
			case 72: // �ϼ�ͷ��
				if (i != 6)
					i -= 2; // ��� 'i' ������ 6�������ȥ 2
				break;
			case 80: // �¼�ͷ��
				if (i != 12)
					i += 2; // ��� 'i' ������ 12��������� 2
				break;
			}

			gotoXY(70, i); // �����λ������Ϊ���� (70, i)
			print_arrow(); // ���� print_arrow ����
		}
	}
}
