#include<stdio.h>
#include "projectHeader.h"

void heapify_int(int b[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int left = 2*i + 1; // left = 2*i + 1 
    int right = 2*i + 2; // right = 2*i + 2 
    
    int temp;
    // If left child is larger than root 
    if (left < n && b[left] > b[largest]) 
        largest = left; 
        
    // If right child is larger than largest so far 
    if (right < n && b[right] > b[largest]) 
        largest = right; 
        
    // If largest is not root 
   
    if (largest != i) 
    { 
        temp = b[i];
        b[i] = b[largest];
        b[largest] = temp;
        // Recursively heapify the affected sub-tree 
        heapify_int(b, n, largest); 
    } 
} 

void heapSort_int(int b[], int n) 
{ 
    int temp, i;
    // Build heap (rearrange array) 
    for (i = n / 2 - 1; i >= 0; i--) 
        heapify_int(b, n, i); 
  
    // One by one extract an element from heap 
    for (i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        temp = b[0];
        b[0] = b[i];
        b[i] = temp;
  
        // call max heapify on the reduced heap 
        heapify_int(b, i, 0); 
    } 
} 