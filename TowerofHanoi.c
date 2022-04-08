#include <stdio.h>

void TOH(int n, char source, char temp, char dest)
{
    if(n > 0)
    {
    TOH(n-1, source, dest, temp);
    printf("Move disk %d form %c to %c\n", n,source,dest);
    TOH(n-1, temp, source, dest);
    }
}

int main()
{
    int n = 1;      //n is number of disks
    TOH(n, 'A', 'B', 'C');
}
