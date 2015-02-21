#include <stdio.h>
#include <iostream>
using namespace std ;

int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0], i;
   int curr_max = a[0];
 
   for (i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
        cout << max_so_far << endl ;
   }
   return max_so_far;
}
 
/* Driver program to test maxSubArraySum */
int main()
{
   int a[] =  {1,2,-1,3,4};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   printf("Maximum contiguous sum is %d\n", max_sum);
   return 0;
}
