#include <windows.h>
#include "../include/cursor_control.h"

// 隐藏终端指针
void hide_console_cursor()
{
	// 创建一个控制终端指针的结构体，其中第一个字段表示结构体大小，第二个字段表示是否显示指针（0表示隐藏）
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };

	// 设置终端的控制指针信息
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

// 显示终端指针
void show_console_cursor()
{
	// 创建一个控制终端指针的结构体，其中第一个字段表示结构体大小，第二个字段表示是否显示指针（1表示显示）
	CONSOLE_CURSOR_INFO cursor_info = { 1, 1 };

	// 设置终端的控制指针信息
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

// 移动终端指针位置
void gotoXY(int x, int y) {
	// 获取标准输出句柄
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	// 创建一个表示终端位置的结构体
	COORD pos;

	// 设置终端的横坐标位置
	pos.X = x;
	// 设置终端的纵坐标位置
	pos.Y = y;

	// 设置终端的光标位置为指定的坐标位置
	SetConsoleCursorPosition(handle, pos);
}