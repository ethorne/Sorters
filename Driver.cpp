#include <iostream>
#include "Sorters.cpp"

enum sortCodes{
	insertionSortCode = 0,
	selectionSortCode,
	mergeSortCode,
	quickSortCode,
	shellSortCode,
	END
};

void populateList(int* arr, int size);

void printList(int* arr, int size);

void runSort(sortCodes sortCode);

int main()
{
	for(int sortCode = insertionSortCode; sortCode != END; sortCode++)
	{
		runSort((sortCodes) sortCode);
	}

	return 0;
}

void populateList(int* arr, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

void printList(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << "\t";
		if ((i+1) % 5 == 0)
		{
			std::cout << std::endl;
		}
	}
}

void runSort(sortCodes sortCode)
{
	const int ARR_SIZE = 10;

	switch (sortCode)
	{
		case insertionSortCode:
			std::cout << "-- INSERTION SORT --" << std::endl;
			break;
		case selectionSortCode:
			std::cout << "-- SELECTION SORT --" << std::endl;
			break;
		case mergeSortCode:
			std::cout << "-- MERGE SORT --" << std::endl;
			break;
		case quickSortCode:
			std::cout << "-- QUICK SORT --" << std::endl;
			break;
		case shellSortCode:
			std::cout << "-- SHELL SORT --" << std::endl;
			break;
		default:
			std::cout << "UNKNOWN SORT CODE" << std::endl;
			return;
	}

	int* arr = new int[ARR_SIZE];
	populateList(arr, ARR_SIZE);

	std::cout << "list before sort" << std::endl;
	printList(arr, ARR_SIZE);

	std::cout << "\nlist after sort" << std::endl;

	switch (sortCode)
	{
		case insertionSortCode:
			insertionSort(arr);
			break;
		case selectionSortCode:
			selectionSort(arr);
			break;
		case mergeSortCode:
			mergeSort(arr, 0, ARR_SIZE-1);
			break;
		case quickSortCode:
			quickSort(arr, 0, ARR_SIZE-1);
			break;
		case shellSortCode:
			shellSort(arr);
			break;
		default:
			return;
	}
	printList(arr, ARR_SIZE);

	std::cout << "\n-----------------------------------------\n";
}