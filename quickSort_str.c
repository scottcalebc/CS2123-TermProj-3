#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "projectHeader.h"


int partition_str (char *arr[], int low, int high) 
{ 
    char temp[1][MAX_LEN]; //to store temp variable
    int j;
    char* pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
    for (j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (strcmp((arr[j]), (pivot)) <= 0)
        { 
            i++;    // increment index of smaller element 
            temp[0][0] = *arr[i];
            *arr[i] = *arr[j];
            *arr[j] = temp[0][0]; 
        } 
    } 
    // Swapping array elemnents
    temp[0][0] = *arr[i + 1];
    *arr[i + 1] = *arr[high];
    *arr[high] = temp[0][0];
    return (i + 1); 
} 


void quickSort_str(char *arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition_str(arr, low, high);
        // Separately sort elements before 
        // partition and after partition 
        quickSort_str(arr, low, (pi - 1)); 
        quickSort_str(arr, (pi + 1), high); 
    } 
} 
