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

void mergeSortHelper(int* a, int lo, int hi)
{
	if (lo >= hi)
	{
		return;
	}
	int mid = lo + ((hi-lo)/2);

	mergeSortHelper(a, lo, mid);
	mergeSortHelper(a, mid+1, hi);
	merge(a, lo, hi, mid);
}

void mergeSort(int* a, int size)
{
	mergeSortHelper(a, 0, size - 1);
	std::cout << "outta helper" << std::endl;
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

void quickSortHelper(int* arr, int lo, int hi)
{
	if (hi <= lo) 
		return;
	int pivot = random_partition(arr, lo, hi);
	quickSortHelper(arr, lo, pivot-1);
	quickSortHelper(arr, pivot+1, hi);
}

void quickSort(int *arr, int size)
{
	quickSortHelper(arr, 0, size-1);
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
