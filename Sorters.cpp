#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <cassert>
#ifndef _SORTERS_
#define _SORTERS_

void merge(int* a, int lo, int hi, int mid)
{
	int temp[hi-lo];
	int hiCtr = mid+1;
	int loCtr = lo;
	int tempCtr = lo;
	
	while(loCtr <= mid && hiCtr <= hi)
	{
		if (a[loCtr] < a[hiCtr])
		{
			temp[tempCtr++] = a[loCtr++];
		}
		else
		{
			temp[tempCtr++] = a[hiCtr++];
		}
	}

	while(loCtr <= mid)
	{
		temp[tempCtr++] = a[loCtr++];
	}
	while(hiCtr <= hi)
	{
		temp[tempCtr++] = a[hiCtr++];
	}

	tempCtr = 0;
	for(int i = lo; i < hi; i++)
	{
		a[i] = temp[tempCtr++];
	}
}

void mergeSort(int* a, int lo, int hi)
{
	if (lo >= hi)
	{
		return;
	}
	int mid = lo + ((hi-lo)/2);
	mergeSort(a, lo, mid);
	mergeSort(a, mid+1, hi);
	merge(a, lo, hi, mid);
}

int partition(int* arr, int lo, int hi)
{
	int pivot = arr[hi];
	int i = lo;

	for (int j = lo; j < hi; j++)
	{
		if (arr[j] <= pivot)
		{
			std::swap(arr[i++], arr[j]);
		}
	}
	std::swap(arr[++i], arr[hi]);
	return i;
}

int random_partition(int* arr, int lo, int hi)
{
	srand(time(NULL));
	if (lo < hi)
	{
		int i = (rand() % (hi-lo)) + lo;
		std::swap(arr[i], arr[hi]);
	}
	return partition(arr, lo, hi);
}

int random_select(int* arr, int lo, int hi, int i)
{
	assert(i >=1 && i <= hi);

	int pivot;

	while (lo < hi)
	{
		pivot = random_partition(arr, lo, hi);
		int k = pivot - lo + 1; // k is rank of pivot

		if (i == k) // i is rank which we seek
		{
			return arr[pivot];
		}
		else if (i < k) // sought after item is left of pivot
		{
			hi = pivot - 1;
		}
		else // sought after item is right of pivott;
		{
			lo = pivot + 1;
			i -= k;
		}
	}
	return arr[lo];
}

void quickSort(int* arr, int lo, int hi)
{
	if (lo >= hi) return;
	int pivot = random_partition(arr, lo, hi);
	quickSort(arr, lo, pivot-1);
	quickSort(arr, pivot+1, hi);
}

void insertionSort(int* arr, int size)
{
	int temp, j;

	for (int i = 1; i < size; i++)
	{
		temp = arr[i];

		for (j = i; j > 0 && arr[j-1] > temp; j--)
		{
			arr[j] = arr[j-1];
		}

		arr[j] = temp;
	}
}

void selectionSort(int* arr, int size)
{
	int i, j, minIndex;
	for (i = 0; i < size - 1; i++){
		minIndex = i;
	
		for (j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}

		if (minIndex != i){
			std::swap(arr[i], arr[minIndex]);
		}
	}
}

void shellSort(int* arr, int size)
{
	for (int gap = size / 2; gap > 0; gap /= 2){
		for (int i = gap; i < size; i++){
			int temp = arr[i];
			int j = i;

			for(; j >= gap && temp < arr[j - gap]; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
}

#endif
