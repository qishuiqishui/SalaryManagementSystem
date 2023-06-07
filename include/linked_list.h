#ifndef SALARYMANAGEMENTSYSTEM_LINKED_LIST_H
#define SALARYMANAGEMENTSYSTEM_LINKED_LIST_H

#include "utilities.h"

// �����ڵ�
LinkedList* create_node(employee data);

// ��������
LinkedList* create_linked_list();

// ����ڵ�
void insert_node(LinkedList* head);

// ɾ���ڵ�
void delete_node(LinkedList* head);

// ���½ڵ�
void update_node(LinkedList* head);

// ���ҽڵ�
void search_node(LinkedList* head);

// ��ӡ����
void print_linked_list(LinkedList* head);

// ��ȡ������
int get_linked_list_size(LinkedList* head);

// ��������
void destroy_linked_list(LinkedList* head);

// ��������
void sort_linked_list(LinkedList* head);

#endif //SALARYMANAGEMENTSYSTEM_LINKED_LIST_H
