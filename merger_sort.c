#include <stdio.h>

#define SIZE 8

int temp[SIZE] = {0};

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
    
    //copy sorted values from the temp back to original array 
    for (i = 0; i < SIZE; i++)
    {
        array[i] = temp[i];
    }
    
}

void sort (int array[], int start, int end)
{
    if (end > start)
    {
        int middle = (start + end) / 2;

        // sort left half
        sort(array, start, middle);

        // sort right half
        sort(array, middle + 1, end);

        // merge the two halves
        merge(array, start, middle, middle + 1, end);
    }
}

int main(void)
{
    int numbers[SIZE] = { 4, 15, 16, 50, 8, 23, 42, 108};
    
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    
    sort(numbers, 0, SIZE - 1);
    
    /*
    //copy sorted values from the temp array back to the original array 
    for (int i = 0; i < SIZE; i++)
    {
        numbers[i] = temp[i];
    }
    */
 
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}
