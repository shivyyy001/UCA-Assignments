/**
 * Program to find the Mth smallest element in unsorted array of size N.
 * Compilation : gcc Mth_smallest.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 19/8/2021
 * Ques 2 Assignment_8 - Algorithm .
 *
 */
 

#include<stdio.h>

// Function to swap 2 elements.
void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


// Function to find pivot. 
int partition(int *a , int n , int start , int end)
{
    int count = 0;
    int first = a[start];
    
    // calculating number of elements which are less than first element i.e a[start].
    for(int i = start ; i <= end ; i++)
    {
        if(a[i] < first)
        {
            count++;
        }
    }
    
    // swapping a[start] with a[start + count] to put a[start] to its correct position.
    swap(&a[start] , &a[start + count]);
    
    
    int i = start;
    int j = end;
    
    // traversing left array of pivot element from beginning and right array from end. 
    while(i < (count+start) && j > (count+start))
    {
        /* if element at left array if greater than equals to pivot element and also element at
        right array is less than pivot element then swap them to make left array have smaller elements
        than pivot and right array have greater and equal elements than pivot */
        if(a[i] >= first && a[j] < first)
        {
            swap(&a[i] , &a[j]);
            i++;
            j--;
        }
        
        // else if left array element is already less than pivot element then just increase the index i.
        else if(a[i] < first)
        {
            i++;
        }
        
        // else if right array element is already greater than equals to pivot element then just decrease the index j.
        else if(a[j] >= first)
        {
            j--;
        }
    }
    
    // return the pivot element index start + count.
    return start + count;
}



// Function for quick sort.
void q_sort(int *a , int n , int start , int end)
{
    // base case ->
    if(start >= end)
    {
        return;
    }
    
    // calculating pivot element index.
    int pivot = partition(a , n , start , end);
    
    // recursively calling for left and right half of pivot index.
    q_sort(a , n , start , pivot - 1);
    q_sort(a , n , pivot + 1 , end);
}


int main()
{
    int n = 0;
    int m = 0;
    printf("Enter number of array elements , n: \n");
    scanf("%d" , &n);
    
    printf("Enter m : \n");
    scanf("%d" , &m);
    
    int array[n];
    printf("Enter %d array elements \n" , n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d" , &array[i]);
    }
    
    // Calling q_sort function to sort the array using quick sort.
    q_sort(array , n , 0 , n - 1);
    
    // printing the Mth smallest element in array.
    printf("%dth smallest element = %d \n" , m , array[m - 1]);
    
}

