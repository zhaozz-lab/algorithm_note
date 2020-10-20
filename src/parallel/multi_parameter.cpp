﻿#include <stdio.h>
#include <stdarg.h>

#include <iostream>
#include <fstream>

double average(int num, ...)
{

    va_list valist;
    double sum = 0.0;
    int i;

    /* 为 num 个参数初始化 valist */
    va_start(valist, num);

    /* 访问所有赋给 valist 的参数 */
    for (i = 0; i < num; i++)
    {
        sum += va_arg(valist, int);
    }
    /* 清理为 valist 保留的内存 */
    va_end(valist);

    return sum / num;
}

int printresult(std::ofstream& result, record &oneRecord)
{
    result << oneRecord.w << oneRecord.w << oneRecord.s << std::endl;
    return 1;
}
int main()
{
    printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2, 3, 4, 5));
    printf("Average of 5, 10, 15 = %f\n", average(3, 5, 10, 15));
}