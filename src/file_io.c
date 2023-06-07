#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "../include/utilities.h"

// ��ȡ�ļ�
void read_file(LinkedList* head) {
	FILE* fp;

	// �Զ�����ģʽ��ȡ
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		// ���ļ������ڣ��Զ�����
		printf("�ļ������ڣ��������ļ�\n");
		fp = fopen("data.txt", "w");
	}

	// �߳�����ģ���ӳ�
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

	// ����ļ��Ƿ�Ϊ��
	if (fgetc(fp) == EOF) {
		fclose(fp);
		return;
	}

	// �ļ�ָ��ָ���֮ǰ��λ��
	fseek(fp, -1, SEEK_CUR);

	// ����Lָ��ָ��ͷ�ڵ�
	LinkedList* L = head;

	while (!feof(fp)) {
		// �����½ڵ����ڶ�ȡ�ļ�����
		LinkedList* p = (LinkedList*)malloc(sizeof(LinkedList));
		fscanf(fp, "%d %s %f %f %f %f ", &p->data.id, &p->data.name, &p->data.salary, &p->data.bonus, &p->data.fine, &p->data.actual);

		// ����β�巨
		L->next = p;
		p->next = NULL;
		L = p;
	}

	printf("\n\t\t\t\t\t������Ϣ�ļ�����ɹ�");
	fclose(fp);
}

// �����ļ�
void save_file(LinkedList* head) {
	FILE* fp;

	// ��д��ģʽ���ļ�
	if ((fp = fopen("data.txt", "w")) == NULL) {
		// ���ļ���ʧ�ܣ������쳣��ֹ
		printf("�����쳣��");
		exit(1);
	}

	// ����id����
	sort_by_id(head);

	// ����Lָ��ָ��ͷ�ڵ����һ�ڵ㣨ͷ�ڵ������ݣ�
	LinkedList* L = head->next;
	while (L != NULL) {
		// �������е�ֵд���ļ�
		fprintf(fp, "%d %s %.2f %.2f %.2f %.2f\n", L->data.id, L->data.name, L->data.salary, L->data.bonus, L->data.fine, L->data.actual);
		L = L->next;
	}

	printf("\n\n\n\n\t\t\t\t\t������Ϣ�ļ�����ɹ�");

	fclose(fp);
	getch();
}

// ���沢�˳�
void save_and_exit(LinkedList* head) {
	//�����ļ�
	save_file(head);

	//��������
	destroy_linked_list(head);

	printf("\n\t\t\t\t\t��ӭ�´�ʹ��~~~");
	getch();
}
