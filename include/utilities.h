#ifndef SALARYMANAGEMENTSYSTEM_UTILITIES_H
#define SALARYMANAGEMENTSYSTEM_UTILITIES_H

// ְ����Ϣ�ṹ��
typedef struct employee {
	int id;						// ����
	char name[10];				// ����
	float salary;				// ��������
	float bonus;				// ����
	float fine;					// ����
	float actual;				// ʵ������
} employee;

// ����
typedef struct LinkedList {
	employee data;				// ����
	struct LinkedList* next;    // ָ����һ�ڵ�
} LinkedList;


// �ȽϺ��������ջ������ʽ��бȽ�
int compare_salary(const void* a, const void* b);

// �ȽϺ���������ʵ�����ʽ��бȽ�
int compare_actual(const void* a, const void* b);

// �ȽϺ���������ְ���Ž��бȽ�
int compare_id(const void* a, const void* b);

// ������ת��Ϊ����
employee* list_to_array(LinkedList* head);

// ����ְ������
employee* create_employee_data(head);

// ����ְ������
employee* update_employee_data(LinkedList* head, int id);

// ����ְ������
void search_employee_data(LinkedList* head);

// �����Ų���
void search_by_name(LinkedList* head);

// ����������
void search_by_id(LinkedList* head);

// ɾ��ְ������
void delete_employee_data(LinkedList* head);

// ְ������
void sort_employee(LinkedList* head);

// ������������
void sort_by_salary(LinkedList* head);

// ����������
void sort_by_id(LinkedList* head);

// ��ʵ����������
void sort_by_actual(LinkedList* head);

#endif //SALARYMANAGEMENTSYSTEM_UTILITIES_H
