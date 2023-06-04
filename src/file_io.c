#include <conio.h>
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "../include/utilities.h"

void read_file(LinkedList* head) {
	FILE* fp;
	/*if ((fp = fopen("����.txt", "rb")) == NULL) {
		printf("�ļ���ʧ�ܣ�");
		getch();
		exit(1);
	}*/
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("�ļ������ڣ��������ļ�\n");
		fp = fopen("data.txt", "w");
	}

	printf("���ݼ�����");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".\n");
	if (fgetc(fp) == EOF) {																	//��ֹ�ļ�Ϊ�գ���Ȼ��ִ��һ�������ѭ����
		fclose(fp);
		return;
	}
	fseek(fp, -1, SEEK_CUR);//ָ����ƣ�ǰ���ȡ�ַ�������һ��λ�ã�

	LinkedList* L = head;
	while (!feof(fp)) {
		LinkedList* p = (LinkedList*)malloc(sizeof(LinkedList));									//�����½ڵ��ȡ�ļ�����
		fscanf(fp, "%d %s %f %f %f %f ", &p->data.id, &p->data.name, &p->data.salary, &p->data.bonus, &p->data.fine, &p->data.actual);//����Ա������
		L->next = p;																		//���½ڵ����ӵ�����β��
		p->next = NULL;
		L = p;
	}
	printf("\n\t\t\t\t\t������Ϣ�ļ�����ɹ�");
	fclose(fp);																				//�ر��ļ�
}

void save_file(LinkedList* head) {
	FILE* fp;
	if ((fp = fopen("data.txt", "w")) == NULL) {
		printf("�ļ���ʧ�ܣ�");
		exit(1);
	}

	LinkedList* L = head->next; // ����ͷ�ڵ�
	while (L != NULL) {
		fprintf(fp, "%d %s %.2f %.2f %.2f %.2f\n", L->data.id, L->data.name, L->data.salary, L->data.bonus, L->data.fine, L->data.actual);
		L = L->next;
	}

	printf("\n\t\t\t\t\t������Ϣ�ļ�����ɹ�");
	fclose(fp);
	getch();
}