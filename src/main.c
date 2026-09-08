#include <stdio.h>
#include <unistd.h>

int arr[10];

int arrayRead(void);
void bubbleSort(int arr[], int n);

void displayArray(int arr[], int n);
int main(void)
{
    int x;
    int n;

    n = arrayRead();
    printf("Select which sorting algorithm to use:\n");
    printf("1 : Bubble Sort\n");
    scanf("%d", &x);

    switch (x)
    {
        case 1:
            bubbleSort(arr, n);
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
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
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
                printf("\033[H\033[J");
                printf("Bubble Sort\n\n");
                displayArray(arr, n);
                printf("\nSwapped!\n");
                usleep(500000);
            }
        }
    }
}

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%2d ", arr[i]);
        for (int j = 0; j < arr[i]; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
