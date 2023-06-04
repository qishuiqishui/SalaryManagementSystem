#ifndef SALARYMANAGEMENTSYSTEM_LINKED_LIST_H
#define SALARYMANAGEMENTSYSTEM_LINKED_LIST_H

#include "utilities.h"

LinkedList* create_node(employee data);

LinkedList* create_linked_list();

void insert_node(LinkedList* head);

void delete_node(LinkedList* head, int id);

void update_node(LinkedList* head);

void search_node(LinkedList* head, int id);

void print_linked_list(LinkedList* head);

int get_linked_list_size(LinkedList* head);

#endif //SALARYMANAGEMENTSYSTEM_LINKED_LIST_H
