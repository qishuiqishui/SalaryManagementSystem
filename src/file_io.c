#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "../include/utilities.h"

// 读取文件
void read_file(LinkedList* head) {
	FILE* fp;

	// 以二进制模式读取
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		// 若文件不存在，自动创建
		printf("文件不存在，创建新文件\n");
		fp = fopen("data.txt", "w");
	}

	// 线程休眠模拟延迟
	printf("数据加载中");
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

	// 检测文件是否为空
	if (fgetc(fp) == EOF) {
		fclose(fp);
		return;
	}

	// 文件指针恢复到之前的位置
	fseek(fp, -1, SEEK_CUR);

	// 创建L指针指向头节点
	LinkedList* L = head;

	while (!feof(fp)) {
		// 创建新节点用于读取文件内容
		LinkedList* p = (LinkedList*)malloc(sizeof(LinkedList));
		fscanf(fp, "%d %s %f %f %f %f ", &p->data.id, &p->data.name, &p->data.salary, &p->data.bonus, &p->data.fine, &p->data.actual);

		// 链表尾插法
		L->next = p;
		p->next = NULL;
		L = p;
	}

	printf("\n\t\t\t\t\t工资信息文件导入成功");
	fclose(fp);
}

// 保存文件
void save_file(LinkedList* head) {
	FILE* fp;

	// 以写入模式打开文件
	if ((fp = fopen("data.txt", "w")) == NULL) {
		// 若文件打开失败，程序异常终止
		printf("出现异常！");
		exit(1);
	}

	// 按照id排序
	sort_by_id(head);

	// 创建L指针指向头节点的下一节点（头节点无数据）
	LinkedList* L = head->next;
	while (L != NULL) {
		// 将链表中的值写入文件
		fprintf(fp, "%d %s %.2f %.2f %.2f %.2f\n", L->data.id, L->data.name, L->data.salary, L->data.bonus, L->data.fine, L->data.actual);
		L = L->next;
	}

	printf("\n\n\n\n\t\t\t\t\t工资信息文件保存成功");

	fclose(fp);
	getch();
}

// 保存并退出
void save_and_exit(LinkedList* head) {
	//保存文件
	save_file(head);

	//销毁链表
	destroy_linked_list(head);

	printf("\n\t\t\t\t\t欢迎下次使用~~~");
	getch();
}
