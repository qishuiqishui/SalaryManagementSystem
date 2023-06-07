#ifndef SALARYMANAGEMENTSYSTEM_FILE_IO_H
#define SALARYMANAGEMENTSYSTEM_FILE_IO_H

#include "../include/utilities.h"

// 读取文件
void read_file(LinkedList* head);

// 写入文件
void save_file(LinkedList* head);

// 保存并退出
void save_and_exit(LinkedList* head);

#endif //SALARYMANAGEMENTSYSTEM_FILE_IO_H
