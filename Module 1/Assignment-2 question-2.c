#include <stdio.h>
 
int main()
{
    int num;
    int count = 0;
 
    printf("Enter a number:\n");
    scanf("%d", &num);
    while (num != 0)
    {
        if ((num & 1) == 1)
            count++;
        num = num >> 1;
    }
    printf("Count of Set Bits :%d", count);
    return 0;
}
