#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

int half(int number, int a[], int n);
int binsearch(int x, int v[], int n);
int factorial(int i);
void stringExpand(char s[]);
int maximumNumberOfConventions(int a, int b);
int primeNumber(int a);
void out99();
void start1();
void swap(int *, int *);
int leapYear(int n);

int main(int argc, char const *argv[])
{
    start1();
    return 0;
}


    /**
 * @brief  判断闰年
 * @note
 * @param  n: 年
 * @retval
 */
    int
    leapYear(int n)
{
    if (n%4==0&&n%100!=0)
    {
        return 1;
    }else if(n%400==0){
        return 1;
    }
    return 0;
};

/**
 * @brief  交换两数内容
 * @note
 * @param  *a: 数1
 * @param  *b: 数2
 * @retval None
 */
void swap(int *a, int *b)
{
    int *temp = malloc(sizeof(int));
    *temp = *a;
    *a = *b;
    *b = *temp;
    free(temp);
}

void start1(){
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("普通搜索:索引为:%d\n", binsearch(3, v, 10));
    printf("二分法搜索:索引为:%d\n", half(10, v, 10));
    // stringExpand("test string out!");
    int a = 6, b = 72;
    printf("%d和%d的最大公约数为:%d\n", a, b, maximumNumberOfConventions(a, b));
    // todo 输出100到200之间的素数
    int i;
    for (i = 100; i <= 200; i++)
    {
        if (primeNumber(i))
        {
            printf("%d ", i);
        }
    }
    // todo 输出乘法表
    // out99();

    // todo 交换
    a = 10;
    b = 20;
    swap(&a, &b);
    printf("\n%d %d\n", a, b);

    // todo 闰年
    for (i = 2021; i <= 2050; i++)
    {
        if (leapYear(i))
        {
            printf("%d ", i);
        }
    }
}


/**
 * @brief  99乘法表
 * @note
 * @retval None
 */
void out99(){
    printf("\n");
    int i, j;
    for (i = 1; i <=9; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d*%d=%-2d ", j, i, i * j);
        }
        printf("\n");
    }
}

/**
 * @brief  判断是否为素数
 * @note
 * @param  a: 大于1的整数
 * @retval 结果
 */
int primeNumber(int a)
{
    // todo 不为2且能被2整除
    if (a % 2 == 0 && a != 2)
    {
        return 0;
    }
    int i = 3;
    for (; i <= sqrt(a); i += 2)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
};
/**
 * @brief  求最大公约数,辗转相除法
 * @note   不需要大小顺序,最小公倍数为两数相乘除以最大公约数
 * @param  a: 数1
 * @param  b: 数2
 * @retval 最大公约数
 */
int maximumNumberOfConventions(int a, int b)
{
    //!当while循环没有执行时,最大公约数为小的那个数
    int c = a > b ? b : a;
    //!且判断表达式不能写为c=a%b,否则c的值一定会被覆盖
    // todo 当a<b时,第一次循环会将两数互换
    while (a % b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return c;
}
/**
 * @brief  演出模式输出字符串
 * @note   仅支持英文,等其他单字节字符.
 * @param  s[]: 待输出字符串
 */
void stringExpand(char s[])
{
    int end = strlen(s) - 1;
    int start = 0;
    char s2[255] = {0};
    int i = 0;
    for (i = 0; i <= end; i++)
    {
        s2[i] = '#';
    }
    for (; start <= end; end--, start++)
    {
        s2[start] = s[start];
        s2[end] = s[end];
        printf("%s\n", s2);
        Sleep(1000UL);
    }
}
/**
 * @brief  二分法
 * @note
 * @param  number:查找数字
 * @param  a[]: 查找数组
 * @param  n: 长度
 * @retval 数组索引或-1
 */
int half(int number, int a[], int n)
{
    int top = 0, start = 0, end = n;
    while (start <= end)
    {
        top = (start + end) / 2;
        if (a[top] > number)
        {
            end = top - 1;
        }
        else if (a[top] < number)
        {
            start = top + 1;
        }
        else
        {
            return top;
        }
    }
    return -1;
}
/**
 * @brief  递归计算阶乘
 * @note
 * @param  i: i阶乘
 * @retval 值
 */
int factorial(int i)
{
    if (1 == i)
        return 1;
    return i * factorial(i - 1);
}
/**
 * @brief  查找数组是否存在指定数
 * @note
 * @param  x: 查找的数字
 * @param  v[]: 被查找数组
 * @param  n: 被查找数组长度
 * @retval 返回数组索引或-1
 */
int binsearch(int x, int v[], int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            return i;
        }
    }
    return -1;
}