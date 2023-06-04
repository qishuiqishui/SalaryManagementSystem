#ifndef SALARYMANAGEMENTSYSTEM_UTILITIES_H
#define SALARYMANAGEMENTSYSTEM_UTILITIES_H
typedef struct employee {
	int id;                    // ����
	char name[10];            // ����
	float salary;            // ��������
	float bonus;            // ����
	float fine;                // ����
	float actual;            // ʵ������
} employee;

typedef struct LinkedList {
	employee data;
	struct LinkedList* next;    // ָ����һ�ڵ�
} LinkedList;

employee* create_employee_data(head);
employee* update_by_id(LinkedList* head, int id);
#endif //SALARYMANAGEMENTSYSTEM_UTILITIES_H
