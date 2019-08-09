#include <stdio.h>
#include "projectHeader.h"

void selectionSort_int(int arr[], int n)
{
	int lh, rh, i, temp;
	
	for(lh = 0; lh < n; lh++)
	{
		rh = lh;
		
		for(i = lh + 1; i < n; i++)
		{
			if(arr[i] < arr[rh])
			rh = i;
		}
		
		temp = arr[lh];
		arr[lh] = arr[rh];
		arr[rh] = temp;
	}
}
