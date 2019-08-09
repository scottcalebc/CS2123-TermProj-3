#include <stdio.h>
#include <stdlib.h>
#include "projectHeader.h"

void countSort(int b[], int n, int exp) 
{ 
    int *output = malloc(sizeof(int) * n); // output array 
    int i, count[10] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++)
    {  
        count[ (b[i]/exp)%10 ]++; 
    }
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (b[i]/exp)%10 ] - 1] = b[i]; 
        count[ (b[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        b[i] = output[i]; 

    free(output);
} 
  

int getMax(int b[], int n) 
{ 
    int mx = b[0]; 
    int i;
    for (i = 1; i < n; i++) 
        if (b[i] > mx) 
            mx = b[i]; 
    return mx; 
} 

void radixSort_int(int b[], int n) 
{ 
    // Find the maximum number to know number of digits 
    int m = getMax(b, n); 
    int exp;
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for ( exp = 1; m/exp > 0; exp *= 10) 
        countSort(b, n, exp); 
} 