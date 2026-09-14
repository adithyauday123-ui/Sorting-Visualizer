#include<stdio.h>


void displayArray(int arr[], int n)                              //Function display array
{
    for (int i = 0; i < n; i++)
    {
        printf("%2d ", arr[i]);
        for (int j = 0; j < arr[i]; j++)
        {
            printf("█ ");
        }
        printf("\n\n");
    }
}

