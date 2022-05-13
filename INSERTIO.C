
#include<stdio.h>
#include<conio.h>
void insert(int [],int);

int i,j;
void main()
{
 int arr[100],n;
 clrscr();
 printf("\nEnter The No. Of Elements In Array:");
 scanf("%d",&n);
 printf("\nEnter Array Elements:");
 for(i=1; i<=n; i++)
 {
  scanf("%d",&arr[i]);
 }
 printf("\nArray Elements Are:");
 for(i=1; i<=n; i++)
 {
  printf(" %d ",arr[i]);
 }
 insert(arr,n);
getch();
}
void insert(int a[],int n)
{
 int key;
 for(j=2; j<=n; j++)
  {
   key=a[j];
   i=j-1;
   while(i>0 && a[i]>key)
   {
    a[i+1]=a[i];
    i=i-1;
   }
   a[i+1]=key;
  }
 printf("\nSorted Array Is:");
 for(j=1; j<=n; j++)
 {
  printf(" %d ",a[j]);
 }
}
