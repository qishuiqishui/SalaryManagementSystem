#ifndef SALARYMANAGEMENTSYSTEM_UTILITIES_H
#define SALARYMANAGEMENTSYSTEM_UTILITIES_H
typedef struct employee {
	int id;                    // 工号
	char name[10];            // 姓名
	float salary;            // 基本工资
	float bonus;            // 奖金
	float fine;                // 罚款
	float actual;            // 实发工资
} employee;

typedef struct LinkedList {
	employee data;
	struct LinkedList* next;    // 指向下一节点
} LinkedList;

employee* create_employee_data(head);
employee* update_employee_data(LinkedList* head, int id);
void search_employee_data(LinkedList* head);
void search_by_name(LinkedList* head);
void search_by_id(LinkedList* head);
void destroy_linked_list(LinkedList* head);
void delete_employee_data(LinkedList* head);

#endif //SALARYMANAGEMENTSYSTEM_UTILITIES_H
