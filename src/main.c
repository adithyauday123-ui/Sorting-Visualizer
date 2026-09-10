#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include <unistd.h>

int arr[10];

void viewArray(int n);
void randomArray(int arr[], int n);
void arrayRead(int n);
void bubbleSort(int arr[], int n);
void displayArray(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);

int main(void)
{
    int x;
    int n;
    srand(time(NULL));
    
    printf("Enter array size : ");
    scanf("%d",&n); 

    printf("1 : Enter array manually\n");
    printf("2 : Generate random array\n");
    scanf("%d",&x);
    if(x==1) 
        arrayRead(n);
    else if(x==2)
        randomArray(arr,n);
    else
        printf("Invalid choice");
    viewArray(n);

    printf("Select which sorting algorithm to use:\n");
    printf("1 : Bubble Sort\n");
    printf("2 : Selection Sort\n");
    printf("3 : Insertion Sort\n");    
    scanf("%d", &x);

    switch (x)
    {
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            break;
        case 3:
	    insertionSort(arr,n);
	    break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}

void viewArray(int n)
{
     printf("\nArray : ");
     for(int c=0;c<n;c++)
     {
           printf("%d ",arr[c]);
     }
     printf("\n\n");
}

void randomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 20 + 1;
    }
}


void  arrayRead(int n)
{
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}


void bubbleSort(int arr[], int n)
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

void displayArray(int arr[], int n)
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


void selectionSort(int arr[], int n)
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


void insertionSort(int arr[], int n)
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
