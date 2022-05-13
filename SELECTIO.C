
#include<stdio.h>
#include<conio.h>
void Select(int [],int);
int i,j,loc,n,x;
void main()
{
 int a[20];
 clrscr();
 printf("\nEnter No. Of Elements In Array:");
 scanf("%d",&x);
 printf("\nEnter Array Elements:");
 for(i=0; i<x; i++)
 {
  scanf("%d",&a[i]);
 }
 printf("\nArray Elements Are:");
 for(i=0; i<x; i++)
 {
  printf("%d ",a[i]);
 }
 Select(a,x);
getch();
}
void Select(int arr[],int n)
{
 for(i=0; i<n-1; i++)
{
  loc=i;
  for(j=i+1; j<n; j++)
  {
   if(arr[loc]>arr[j])
   {
    loc=j;
   }
  }
 if(loc!=i)
 {
  int temp=arr[i];
      arr[i]=arr[loc];
      arr[loc]=temp;
  printf("\nSwapping %d and %d",arr[i],arr[loc]);
 }
}
 printf("\nSorted Array Is:");
 for(i=0; i<n; i++)
  {
   printf("%d ",arr[i]);
  }
}
