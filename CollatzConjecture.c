//this program is just to calculate how many iterations it takes to reach to 1 in Collatz Sequence if you start at any number...

#include <stdio.h>

int main()
{
    int n = 4;
    int result = 26, count = 0, res;
    do{
      res = result % 2;
      if(res == 0)
      {
        result = result / 2;
        count++;
      }
      else
      {
        result = 3 * result + 1;
        count++;
      }
    }while(result != 1);
    printf("Iteration = %d ", count);
}
