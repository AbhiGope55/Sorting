#include<stdio.h>
#include<conio.h>
void Bubble(int [],int);
void main()
{
 int arr[100],n,i;
 clrscr();
 printf("\nEnter The Size Of Array:");
 scanf("%d",&n);
 printf("\nEnter Array Elements:");
 for(i=1; i<=n; i++)
  {
   scanf("%d",&arr[i]);
  }
 Bubble(arr,n);
 printf("\nSorted Array Using Bubble Sort:");
 for(i=1; i<=n; i++)
 {
  printf("%d ",arr[i]);
 }
getch();
}
void Bubble(int a[],int n)
{
 int i,j,flag;
 for(i=n; i>=1; i--)
 {
  flag=0;
  for(j=1; j<=i-1; j++)
   if(a[j]>a[j+1])
   {
    int t=a[j];
	a[j]=a[j+1];
	a[j+1]=t;
	flag=1;
   printf("\nSwapping %d and %d",a[j],a[j+1]);
    printf("\nAfter Pass %d Array Is:",(n-j)+1);
  for(j=1; j<=n; j++)
   printf("%d ",a[j]);
   }

  if(flag==0)
  {
   printf("\ntotal pass:%d",i);
    return;
  }
  }

}