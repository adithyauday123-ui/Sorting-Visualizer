#include <stdio.h>
#include <unistd.h>

int arr[10];

int arrayRead(void);
void bubbleSort(int arr[], int n);
void displayArray(int arr[], int n);
void selectionSort(int arr[], int n);

int main(void)
{
    int x;
    int n;

    n = arrayRead();
    printf("Select which sorting algorithm to use:\n");
    printf("1 : Bubble Sort\n");
    printf("2 : Selection Sort\n");    
    scanf("%d", &x);

    switch (x)
    {
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}



int arrayRead(void)
{
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    return n;
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
