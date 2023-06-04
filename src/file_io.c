#include <conio.h>
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "../include/utilities.h"

void read_file(LinkedList* head) {
	FILE* fp;
	/*if ((fp = fopen("数据.txt", "rb")) == NULL) {
		printf("文件打开失败！");
		getch();
		exit(1);
	}*/
	if ((fp = fopen("data.txt", "rb")) == NULL) {
		printf("文件不存在，创建新文件\n");
		fp = fopen("data.txt", "w");
	}

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
	if (fgetc(fp) == EOF) {																	//防止文件为空（仍然会执行一次下面的循环）
		fclose(fp);
		return;
	}
	fseek(fp, -1, SEEK_CUR);//指针后移（前面读取字符后移了一个位置）

	LinkedList* L = head;
	while (!feof(fp)) {
		LinkedList* p = (LinkedList*)malloc(sizeof(LinkedList));									//创建新节点读取文件内容
		fscanf(fp, "%d %s %f %f %f %f ", &p->data.id, &p->data.name, &p->data.salary, &p->data.bonus, &p->data.fine, &p->data.actual);//增加员工人数
		L->next = p;																		//将新节点连接到链表尾部
		p->next = NULL;
		L = p;
	}
	printf("\n\t\t\t\t\t工资信息文件导入成功");
	fclose(fp);																				//关闭文件
}

void save_file(LinkedList* head) {
	FILE* fp;
	if ((fp = fopen("data.txt", "w")) == NULL) {
		printf("文件打开失败！");
		exit(1);
	}

	LinkedList* L = head->next; // 跳过头节点
	while (L != NULL) {
		fprintf(fp, "%d %s %.2f %.2f %.2f %.2f\n", L->data.id, L->data.name, L->data.salary, L->data.bonus, L->data.fine, L->data.actual);
		L = L->next;
	}

	printf("\n\t\t\t\t\t工资信息文件保存成功");
	fclose(fp);
	getch();
}