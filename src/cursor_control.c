#include "../include/cursor_control.h"
#include "windows.h"

void hide_console_cursor()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void show_console_cursor()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 1 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void gotoXY(int x, int y) { //光标移动到(x,y)位置
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos;

    pos.X = x;

    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}