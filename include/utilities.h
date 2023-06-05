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
employee* update_employee_data(LinkedList* head, int id);
void search_employee_data(LinkedList* head);
void search_by_name(LinkedList* head);
void search_by_id(LinkedList* head);
void destroy_linked_list(LinkedList* head);
void delete_employee_data(LinkedList* head);

#endif //SALARYMANAGEMENTSYSTEM_UTILITIES_H
