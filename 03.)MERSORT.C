#include<stdio.h>
#include<conio.h>
int counter=0;

void merge(int arr[100], int left[100], int right[100], int left_size, int right_size) {
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size)
     {
	counter++;
	if (left[i] < right[j]) {
	    arr[k] = left[i];
	    i++;
	} else {
	    arr[k] = right[j];
	    j++;
	}
	k++;
    }
    while (i < left_size)
     {
	counter++;
	arr[k] = left[i];
	i++;
	k++;
    }
    while (j < right_size)
    {
	counter++;
	arr[k] = right[j];
	j++;
	k++;
    }
}

void merge_sort(int arr[100], int size)
 {
   int mid = size / 2;
   int *left_half=(int*)malloc(mid* sizeof(int));
   int *right_half=(int*)malloc((size-mid)* sizeof(int));
   int i;
    if (size <= 1) {
	return;
    }

    for ( i = 0; i < mid; i++)
     {
	left_half[i] = arr[i];
    }
    for ( i = mid; i < size; i++)
     {
	right_half[i - mid] = arr[i];
    }
    merge_sort(left_half, mid);
    merge_sort(right_half, size - mid);
    merge(arr, left_half, right_half, mid, size - mid);
}

int main() {
    int a,i;
    int tab[100];
    clrscr();
    printf("Enter number of elements in array: ");
    scanf("%d", &a);

    printf("Enter elements of array:\n");
    for ( i = 0; i < a; i++) {
	scanf("%d", &tab[i]);
    }
    printf("Original array: ");
    for ( i = 0; i < a; i++) {
	printf("%d ", tab[i]);
    }
    printf("\n");
    merge_sort(tab, a);
    printf("Sorted array: ");
    for ( i = 0; i < a; i++) {
	printf("%d ", tab[i]);
    }
    printf("\n");
    printf("Time Complexity is:- %d",counter);
    getch();
    return 0;
}