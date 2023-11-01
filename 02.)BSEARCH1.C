#include<stdio.h>
#include<conio.h>
int counter=0;
int N,key,ar[100];
int beg, mid,end;
int BSearch(int key,int beg,int end)
{
  mid=(beg+end)/2;
  if(end>=mid)
  {
  if(key==ar[mid])
  {
  counter++;
  return mid;
  }
  else if(key>ar[mid])
  {
  counter++;
  return BSearch(key,mid+1,end);
  }
  else
  {
  counter++;
  return BSearch(key,beg,mid-1);
  }
  }
  return -1;
}
int main()
{
  int i,N,result;
  clrscr();
  printf("\nEnter Size Of Array: \n");
  scanf("%d",&N);
  for(i=0;i<N;i++)
  {
    printf("Enter Element(%d): ",i);
    scanf("%d",&ar[i]);
  }
  printf("\nEnter Element To Be Searched : ");
  scanf("%d",&key);
  beg=0;
  end=N;
  result=BSearch(key,beg,end);
  if(result==-1)
  {
  printf("\nElement Not Found");
  }
  else
  {
  printf("\nElement Found At Index %d",result);
  }
  printf("\nTime Complexity = %d",counter);
  getch();
  return 0;
}