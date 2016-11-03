/*

My current implementaiton of merge-sort

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int temp[SIZE] = {0};

// calls sort and copies values from temp to original array 
void mergesort (int array[], int start, int end);

//split array into a miltiple of sub-arrays and calls merge 
void sort (int array[], int start, int end);

//sort, merge and store values in temp array 
void merge (int array[], int start_1, int end_1, int start_2, int end_2);

int main(void)
{
    int numbers[SIZE] = { 4, 15, 16, 50, 8, 23, 42, 108};
    
    printf("Not sorted array:\n");
    
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    
    mergesort(numbers, 0, SIZE - 1);
    
    printf("Sorted array:\n");
    
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}

void mergesort (int array[], int start, int end)
{
    sort(array, start, end);
    
    //copy sorted values from the temp array back to the original array 
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = temp[i];
    }
}

void sort (int array[], int start, int end)
{
    int middle = (start + end) / 2;
    
    if (end > start)
    {
        // sort left half
        sort(array, start, middle);

        // sort right half
        sort(array, middle + 1, end);
    }
    
    // merge the two halves
    merge(array, start, middle, middle + 1, end);
}

void merge (int array[], int start_1, int end_1, int start_2, int end_2)
{
    int i = 0;
    
    // while there are elements in both subarrays 
    while ((start_1 <= end_1) && (start_2 <= end_2))
    {
        // compare numbers at the start of the subarrays 
        if (array[start_1] > array[start_2])
        {
            // append smaller to array 
            temp[i] = array[start_2];
            start_2++; 
            i++;
        }
        else
        {
            temp[i] = array[start_1];
            start_1++; 
            i++;
        }
    }
    
    // while elements remain in subbarray 2
    while ((start_1 > end_1) && (start_2 <= end_2))
    {
        // append elements to array 
        temp[i] = array[start_2];
        i++; 
        start_2++;
    }
    
    // while elements remain in subbarray 1
    while ((start_2 > end_2) && (start_1 <= end_1))
    {
        // append elements to array 
        temp[i] = array[start_1];
        i++; 
        start_1++;
    }
    
}



