#include "../include/cursor_control.h"
#include "../include/menu.h"
#include "windows.h"
#include <stdio.h>

void main_menu() {
	int i = 9;
	system("cls");
	system("color EC");
	printf("\t\t                    \n");
	printf("\t\t                     (@^o^@) ��ӭʹ�ù��ʹ������ϵͳ o(�R���Q)o\n");
	printf("\t\t                    \n");
	printf("\t\t\t\t����������������������������������������������������������������������������������������������������\n\n");
	printf("\t\t\t\t\t\t  ���ʹ���ϵͳ\n\n");
	printf("\t\t\t\t����������������������������������������������������������������������������������������������������\n\n");
	printf("\t\t\t\t��             ��.����ְ��������Ϣ               ��\n\n");
	printf("\t\t\t\t��             ��.ɾ��ְ��������Ϣ               ��\n\n");
	printf("\t\t\t\t��             ��.�޸�ְ��������Ϣ               ��\n\n");
	printf("\t\t\t\t��             ��.��ѯְ��������Ϣ               ��\n\n");
	printf("\t\t\t\t��             ��.��Ϣ�ܲ�ѯ                     ��\n\n");
	printf("\t\t\t\t��             ��.����������ѯ                   ��\n\n");
	printf("\t\t\t\t��             ��.�����ļ�                       ��\n\n");
	printf("\t\t\t\t��             ��.�����ļ����˳�                 ��\n\n");
	printf("ʹ��˵�������¼�ѡ�񣬻س���ȷ��\n");
	gotoXY(70, i);
	printf("<=====");
}

void print_menu_header() {
	printf("\t\t\t\t����������������������������������������������������������������������������������������������������\n\n");
	printf("\t\t\t\t\t\t  ���ʹ���ϵͳ\n\n");
	printf("\t\t\t\t����������������������������������������������������������������������������������������������������\n\n");
}

void print_search_error_menu() {
	printf("\t\t\t\t                   ���޴���!!!                    \n\n");
	printf("\t\t\t\t��                  ��������                      ��\n\n");
	printf("\t\t\t\t��                  �˳�                          ��\n\n");
}

void print_salary_header() {
	printf("\t\t\t\t���    ����    ��������  ����      ����     ʵ������\n\n");
}

void print_sort_menu() {
	printf("\t\t\t\t��                  ������������                  ��\n\n");
	printf("\t\t\t\t��                  ʵ����������                  ��\n\n");
	printf("\t\t\t\t��                  �˳�                          ��\n\n");
}

void print_search_menu() {
	printf("\t\t\t\t��                  ID����                        ��\n\n");
	printf("\t\t\t\t��                  ��������                      ��\n\n");
	printf("\t\t\t\t��                  �˳�                          ��\n\n");
}

void print_update_menu() {
	printf("\t\t\t\t��                  �޸�����                      ��\n\n");
	printf("\t\t\t\t��                  �޸Ļ�������                  ��\n\n");
	printf("\t\t\t\t��                  �޸Ľ���                      ��\n\n");
	printf("\t\t\t\t��                  �޸ķ���                      ��\n\n");
	printf("\t\t\t\t��                  �˳�                          ��\n\n");
}

void print_input_prompt() {
	printf("\t\t\t\t                ������                          \n\n");
}

void print_name_prompt() {
	printf("\t\t\t\t===============>������");
}

void print_id_prompt() {
	printf("\t\t\t\t===============>ְ���ţ�");
}


void print_salary_prompt() {
	printf("\t\t\t\t===============>�������ʣ�");
}

void print_bonus_prompt() {
	printf("\t\t\t\t===============>����");
}

void print_fine_prompt() {
	printf("\t\t\t\t===============>���");
}

void print_arrow() {
	printf("<=====");
}

void clear_arrow() {
	printf("\b\b\b\b\b\b      ");
}

void print_confirm_options() {
	printf("\t\t\t\t��                  ��������                      ��\n\n");
	printf("\t\t\t\t��                  ȷ��                          ��\n\n");
	printf("\t\t\t\t��                  ȡ��                          ��\n\n");
}

void print_options() {
	printf("\n\t\t\t\t��                  ��������                      ��\n\n");
	printf("\t\t\t\t��                  �˳�                          ��\n\n");
}