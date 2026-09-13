#include <stdio.h>
#include <unistd.h>
#include "sorting.h"
void displayArray(int arr[], int n);


void bubbleSort(int arr[], int n)                              //Bubble Sort
{
    int comparisons = 0;
    int swaps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;
            printf("\033[H\033[J");
            printf("Bubble Sort\n\n");
            displayArray(arr, n);
            printf("\nComparing %d and %d\n", arr[j], arr[j + 1]);
            usleep(500000);

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
	        swaps++;
                printf("\033[H\033[J");
                printf("Bubble Sort\n\n");
                displayArray(arr, n);
                printf("\nSwapped!\n");
                usleep(500000);
            }
        }
    }
    printf("\nsorted\n\n");
    printf("===Sorting statistics===\n");
    printf("Comparisons = %d\n",comparisons);
    printf("Swaps = %d\n",swaps);    
}




void selectionSort(int arr[], int n)                           //Selection sort
{
    int i, j, min, temp;
    int comparisons = 0;
    int swaps = 0;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            printf("\033[H\033[J");
            displayArray(arr, n);
            printf("\nComparing %d and %d\n", arr[min], arr[j]);
            usleep(300000);
	    comparisons++;
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
	    swaps ++;
            printf("\033[H\033[J");
            displayArray(arr, n);
            printf("\nSwapped %d and %d\n", arr[i], arr[min]);
            usleep(500000);
        }
    }
    printf("\033[H\033[J");
    displayArray(arr, n);
    printf("\nSorted!\n\n");
    printf("===Sorting statistics===\n");
    printf("Comparisons = %d\n",comparisons);
    printf("Swaps = %d\n",swaps);
}


void insertionSort(int arr[], int n)                      //Insertion Sort
{
    int i, j, key;
    int comparisons = 0;
    int shifts = 0;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0)
        {
            comparisons++;
            if (arr[j] <= key)
                break;
            printf("\033[H\033[J");
            printf("Insertion Sort\n\n");
            displayArray(arr, n);
            printf("\nComparing %d and %d\n", arr[j], key);
            usleep(500000);
            arr[j + 1] = arr[j];
            shifts++;
            j--;
            printf("\033[H\033[J");
            printf("Insertion Sort\n\n");
            displayArray(arr, n);
            printf("\nShifting...\n");
            usleep(500000);
        }
        arr[j + 1] = key;
        printf("\033[H\033[J");
        printf("Insertion Sort\n\n");
        displayArray(arr, n);
        printf("\nInserted %d\n", key);
        usleep(500000);
    }
    printf("\033[H\033[J");
    displayArray(arr, n);
    printf("\nSorted!\n");
    printf("\n=== Sorting statistics ===\n");
    printf("Comparisons = %d\n", comparisons);
    printf("Shifts      = %d\n", shifts);
}
