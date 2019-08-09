#include<stdio.h>
#include "projectHeader.h"

int partition_int (int arr[], int low, int high) 
{ 
    int temp, j;
    int pivot = arr[(high+low)/2];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; 
        } 
    } 
    // Swapping array elemnents
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1); 
} 


void quickSort_int(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition_int(arr, low, high); 
        // Separately sort elements before 
        // partition and after partition 
        quickSort_int(arr, low, pi - 1); 
        quickSort_int(arr, pi + 1, high); 
    } 
} 