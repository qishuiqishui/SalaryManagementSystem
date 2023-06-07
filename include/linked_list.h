#ifndef SALARYMANAGEMENTSYSTEM_LINKED_LIST_H
#define SALARYMANAGEMENTSYSTEM_LINKED_LIST_H

#include "utilities.h"

// 创建节点
LinkedList* create_node(employee data);

// 创建链表
LinkedList* create_linked_list();

// 插入节点
void insert_node(LinkedList* head);

// 删除节点
void delete_node(LinkedList* head);

// 更新节点
void update_node(LinkedList* head);

// 查找节点
void search_node(LinkedList* head);

// 打印链表
void print_linked_list(LinkedList* head);

// 获取链表长度
int get_linked_list_size(LinkedList* head);

// 销毁链表
void destroy_linked_list(LinkedList* head);

// 链表排序
void sort_linked_list(LinkedList* head);

#endif //SALARYMANAGEMENTSYSTEM_LINKED_LIST_H
