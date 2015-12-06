#include<stdio.h>
int main(){
    int arr[10] = {1,2,3,5,-10,20,40};
    int n = 7;
    Largest_sub_array(arr,n);
    return 0;
}
void Largest_sub_array(int a[], int n)
{
   int start1,end,start2 = 0;
   int max_sum = 0,sum = 0;
   int i;
   for(i = 0;i<n;i++)
   {
     sum = sum + a[i];
     if(sum < 0)
     {
        sum = 0;
        start2 = i+1;
     }
     else if(sum > max_sum)
     {
        max_sum = sum;
        start1 = start2;
        end = i;
     }
   }
   printf("Max sum is %d\n",max_sum);
   printf("Array is: \n");
   for(i = start1; i < end;i++){
        printf("%d ",a[i]);
    }
}
