#include<stdio.h>
#include<conio.h>
int counter=0;
void selsort(int arr[100],int n)
{
int i,j,small,temp;
for(i=0;i<n-1;i++)
{
 small=i;
 counter++ ;
 for(j=i+1;j<n;j++)
 {
  counter++;
  if (arr[j]<arr[small])
  {
    small=j;
    counter++;
  }
 }
   temp=arr[i];
   arr[i]=arr[small];
   arr[small]=temp;
   counter++;
}
}
  int main()
  {
    int n;
    int i;
    int arr[100];
    clrscr();
    printf("Enter the amount of elements:- ");
    scanf("%d",&n);
    printf("Enter the elements:- \n");
    for(i=0;i<n;i++)
    {
     scanf("%d",&arr[i]);
    }
     printf("\nOriginal Array :- \n");
    for(i=0;i<n;i++)
    {
     printf("%d\n",arr[i]);
    }
    selsort(arr,n);
    printf("\nSorted Array :-\n" );
    for(i=0;i<n;i++)
    {
     printf("%d\n",arr[i]);
    }
    printf("\n");
    printf("Time Complexity:- %d",counter);
    getch();
    return 0;
  }