#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projectHeader.h"

void heapify_str(char *list[], int n, int i) 
{ 
    
    int largest = i; // Initialize largest as root 
    int left = 2*i + 1; // left = 2*i + 1 
    int right = 2*i + 2; // right = 2*i + 2 

    char temp[MAX_LEN];
    // If left child is larger than root 
    if (left < n && (strcmp(list[left],list[largest])> 0)) 
        largest = left; 
  
    // If right child is larger than largest so far 
    if (right < n && (strcmp(list[right],list[largest])>0)) 
        largest = right; 
    
    // If largest is not root  
    if (largest != i) 
    { 
        strcpy(temp, list[i]);
        strcpy(list[i], list[largest]);
        strcpy(list[largest], temp);
        // Recursively heapify the affected sub-tree 
        heapify_str(list, n, largest); 
    }
} 

void heapSort_str(char *list[], int n) 
{ 
    int i;
    char temp[MAX_LEN];
    // Build heap (rearrange array) 
    
    for (i = n / 2 - 1; i >= 0; i--) 
        heapify_str(list, n, i); 
  
    // One by one extract an element from heap 
    for (i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        strcpy(temp, list[0]);
        strcpy(list[0], list[i]);
        strcpy(list[i], temp);
        // call max heapify on the reduced heap 
        heapify_str(list, i, 0); 
    } 
    
} 


























/*
int main() 
{ 
    
    int i;
    char *arr[] = {"X", "Y", "Z", "A", "D", "T"}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    
    heapSort(arr, n); 
    printf("Sorted array is: \n"); 
    for(i = 0; i < n; i++){
        printf("%s ", arr[i]);
    }
    
}
*/




