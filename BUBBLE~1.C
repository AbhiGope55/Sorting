#include<stdio.h>
#include<conio.h>
void bubble_sort(int [],int);
void main()
{
  int arr[100],n,i;
  clrscr();
  printf("Enter Number Of Elements:");
  scanf("%d",&n);
  printf("\nEnter Array Elements:");
   for(i=0; i<n; i++)
    {
     scanf("%d",&arr[i]);
    }
  bubble_sort(arr,n);
  getch();
}
void bubble_sort(int a[],int n)
{
  int pass,i,temp,flag;
  for(pass=1; pass<=n-1; pass++)
   {
    flag=0;
     for(i=0; i<=n-1-pass; i++)
      if(a[i]>a[i+1])
      {
       flag=1;
       temp=a[i];
       a[i]=a[i+1];
       a[i+1]=temp;
       printf("\nSwapping %d And %d",a[i],a[i+1]);
      }
    printf("\nAfter Pass %d Array Is:",pass);
     for(i=0; i<n; i++)
      printf("%d ",a[i]);
   if(flag==0)
   {
    printf("\nTotal Passes:%d",pass);
     return;
   }
  }
 printf("\nSorted Elements using Bubble sort Are:");
  for(i=0; i<n; i++)
   printf("%d ",a[i]);
}







