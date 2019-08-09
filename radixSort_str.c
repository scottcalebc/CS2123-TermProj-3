#include<stdio.h>
#include<string.h>
#include "projectHeader.h"

void countSort_str(char *a[], int n, int exp) 
{ 
    //int output[n]; // output array 
    int i, count[256] = {0}; 
    char output[n][MAX_LEN];
     
    
    
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) {
        //count[ (a[i]/exp)%10 ]++; 
        ++count[a[i][exp]];
        }
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i= 1; i < 256; i++) {
        count[i] += count[i - 1]; 
       
    }
    
    // Build the output array 
    for (i= n - 1; i >= 0; i--) 
    { 
        //output[count[a[i][exp]] - 1] = a[i]; 
        strcpy(output[count[a[i][exp]] - 1],a[i]);
        //count[ (a[i]/exp)%10 ]--; 
        --count[a[i][exp]];
    } 
    
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
    {
        //a[i]= output[i];
        strcpy(a[i],output[i]);
    }
} 
  

int getMax_str(char *a[], int n) 
{ 
    int mx = 0;
    int i;
    for (i = 1; i < n; i++) 
        if (strlen(a[i]) > mx) 
            mx = strlen(a[i]); 
    return mx; 
    
    /*
    char mx[MAX_LEN];
    strcpy(mx,a[0]); 
    int i;
    for (i = 1; i < n; i++) 
        if (strcmp(a[i], mx)>0) 
            strcpy(mx, a[i]); 
    return mx; 
     */ 
} 

void radixSort_str(char *a[], int n) 
{ 
    //printf("Starting");
    // Find the maximum number to know number of digits 
    int m = getMax_str(a, n); 
    int exp;
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for ( exp = m - 1; exp >= 0; exp--) {
        countSort_str(a, n, exp); 
} 
}

