
#include<stdio.h>
#include<conio.h>
int Bubble(int [],int);
void main()
{
 int arr[100],n,i;
 clrscr();
 printf("\nEnter Number Of Elemets:");
 scanf("%d",&n);
 printf("\nEnter Array Elements:");
 for(i=1; i<n; i++)
 {
  scanf("%d ",&arr[i]);
 }
 Bubble(arr,n);
 for(i=1; i<n; i++)
  printf("%d ",arr[i]);
getch();
}
int Bubble(int a[],int n)
{
 int i,j,t;
 for(i=n; i>=0; i--)
 {
  for(j=0; j<=n-i-1; j++)
  {
   if(a[j]>a[j+1])
   {
    t=a[j];
    a[j]=a[j+1];
    a[j+1]=t;
   }
  }
 }
 return a[j];
}
