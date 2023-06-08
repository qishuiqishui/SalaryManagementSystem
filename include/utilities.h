#ifndef SALARYMANAGEMENTSYSTEM_UTILITIES_H
#define SALARYMANAGEMENTSYSTEM_UTILITIES_H

// 职工信息结构体
typedef struct employee {
	int id;						// 工号
	char name[10];				// 姓名
	float salary;				// 基本工资
	float bonus;				// 奖金
	float fine;					// 罚款
	float actual;				// 实发工资
} employee;

// 链表
typedef struct LinkedList {
	employee data;				// 数据
	struct LinkedList* next;    // 指向下一节点
} LinkedList;


// 比较函数，按照基本工资进行比较
int compare_salary(const void* a, const void* b);

// 比较函数，按照实发工资进行比较
int compare_actual(const void* a, const void* b);

// 比较函数，按照职工号进行比较
int compare_id(const void* a, const void* b);

// 将链表转换为数组
employee* list_to_array(LinkedList* head);

// 创建职工数据
employee* create_employee_data(head);

// 更新职工数据
employee* update_employee_data(LinkedList* head, int id);

// 查找职工数据
void search_employee_data(LinkedList* head);

// 按工号查找
void search_by_name(LinkedList* head);

// 按姓名查找
void search_by_id(LinkedList* head);

// 删除职工数据
void delete_employee_data(LinkedList* head);

// 职工排序
void sort_employee(LinkedList* head);

// 按基本工排序
void sort_by_salary(LinkedList* head);

// 按工号排序
void sort_by_id(LinkedList* head);

// 按实发工资排序
void sort_by_actual(LinkedList* head);

#endif //SALARYMANAGEMENTSYSTEM_UTILITIES_H
