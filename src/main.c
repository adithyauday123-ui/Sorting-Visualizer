#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include <unistd.h>
#include "sorting.h"

int arr[10];      //Global array declaration

void viewArray(int n);
void randomArray(int arr[], int n);
void arrayRead(int n);

int main(void)        //Main function
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

    printf("Select which sorting algorithm to use:\n");    //Sorting menu
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

void viewArray(int n)                                        //Function to display array
{
     printf("\nArray : ");
     for(int c=0;c<n;c++)
     {
           printf("%d ",arr[c]);
     }
     printf("\n\n");
}

void randomArray(int arr[], int n)                            //Function to generate random array
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 20 + 1;
    }
}


void  arrayRead(int n)                                        //Function for reading array
{
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}



  





