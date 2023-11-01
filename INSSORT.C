#include<stdio.h>
#include<conio.h>
int counter=0;
void inssort(int arr[100],int n)
{
    int i,j,key;
    for(j=1;j<n;j++)
    {
     counter++;
     key=arr[j];
     i=j-1;
     while(i>=0 && arr[i]>key)
     {
      arr[i+1]=arr[i];
      i--;
      counter++;
     }
     arr[i+1]=key;
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
    inssort(arr,n);
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