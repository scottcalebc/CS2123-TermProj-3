#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "projectHeader.h"

//sorting algorithms here
/*
 1
 2
 3
 4
 5
 6
 */
//linear int
int linearSearchIterative_int(int data[], int n, int target)
{
int i;
for (i = 0; i < n; i++)
if (data[i] == target)
return i;

return -1;
}

//linear str
int linearSearchIterative_str(char *data[], int n, char *target[])
{
int i; 
for (i = 0; i < n; i++)
{
if (strcmp(data[i],target[0])==0)
{
return i;
}
}
return -1;
}

//binary int
int BinarySearchIterative_int(int data[], int n, int target)// BSI
{ // data is sorted
int low = 0, high = n - 1;
while (low <= high) {
int mid = (low + high) / 2;
if (data[mid] == target) return mid;
else if (data[mid] < target) low = mid + 1;
else high = mid - 1;
}
return -1;
}

//binary str
int BinarySearchIterative_str(char *data[], int n, char *target[])// BSI
{ // data is sorted
int low = 0, high = n - 1;
while (low <= high) {
int mid = (low + high) / 2;
if (strcmp(data[mid],target[0])==0) return mid;
else if (strcmp(data[mid],target[0])<0) low = mid + 1;
else high = mid - 1;
}
return -1;
}


