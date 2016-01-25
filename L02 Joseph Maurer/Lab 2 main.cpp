/***********************************************************
* Author:			Joseph Maurer
* Lab Number:		CST 211 Lab 02
* Filename:			Lab 2 Main.cpp
* Date Created:		04/13/15
* Modifications:
*
* Overview:
*	This program's purpose is to use a plethora of 
*	differenet sorting algorithms in order to sort
*	through three different data types. These data 
*	types include vectors, native arrays, and 
*	my array's from my array class. It applies the
*	Brute Force Bubble, Flagged Bubble, Selection,
*	Insertion, Shell, Heap, Merge, and Quick Sorts.
*	The amount of arguments is passed in through
*	command line arguments.
*
*
* Input:
*	There is no input required for this program.
*
* Output:
*	The output of this program will mainly be to a 
*	text file called Output.txt. In this file, it will
*	print out all of the contents of the sorted array
*	as well as the time it took for each sort. 
*	Example Output below: 
****************NATIVE ARRAY****************
//
//
//
//Time for Brutte Force Bubble Sort sorting 10000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 2
//Milli:   341
//Check: Array is sorted
//
//
//
//
//Time for Flagged Force Bubble Sort sorting 10000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 2
//Milli:   657
//Check: Array is sorted
//
//
//
//
//Time for Selection Sort sorting 10000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 0
//Milli:   297
//Check: Array is sorted
//
//
//
//
//Time for Insertion Sort sorting 10000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 0
//Milli:   187
//Check: Array is sorted
//
//
//
//
//Time for Shell Sort sorting 75000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 0
//Milli:   62
//Check: Array is sorted
//
//
//
//
//Time for Heap Sort sorting 75000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 0
//Milli:   125
//Check: Array is sorted
//
//
//
//
//Time for Quick Sort sorting 75000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 0
//Milli:   47
//Check: Array is sorted
//
//
//
//
//Time for Merge Sort sorting 75000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 0
//Milli:   47
//Check: Array is sorted
//
//
//****************VECTORS****************
//
//
//
//Time for Brutte Force Bubble Sort sorting 10000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 22
//Milli:   366
//Check: Array is sorted
//
//
//
//
//Time for Flagged Force Bubble Sort sorting 10000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 36
//Milli:   862
//Check: Array is sorted
//
//
//
//
//Time for Selection Sort sorting 10000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 13
//Milli:   566
//Check: Array is sorted
//
//
//
//
//Time for Insertion Sort sorting 10000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 10
//Milli:   157
//Check: Array is sorted
//
//
//
//
//Time for Heap Sort sorting 75000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 0
//Milli:   994
//Check: Array is sorted
//
//
//
//
//Time for Shell Sort sorting 75000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 0
//Milli:   813
//Check: Array is sorted
//
//
//
//
//Time for Quick Sort sorting 75000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 0
//Milli:   687
//Check: Array is sorted
//
//
//
//
//Time for Merge Sort sorting 75000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 0
//Milli:   563
//Check: Array is sorted
//
//
//****************My Array Class****************
//
//
//
//Time for Brutte Force Bubble Sort sorting 10000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 13
//Milli:   707
//Check: Array is sorted
//
//
//
//
//Time for Flagged Force Bubble Sort sorting 10000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 21
//Milli:   450
//Check: Array is sorted
//
//
//
//
//Time for Selection Sort sorting 10000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 7
//Milli:   778
//Check: Array is sorted
//
//
//
//
//Time for Insertion Sort sorting 10000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 5
//Milli:   860
//Check: Array is sorted
//
//
//
//
//Time for Heap Sort sorting 75000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 0
//Milli:   609
//Check: Array is sorted
//
//
//
//
//Time for Shell Sort sorting 75000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 0
//Milli:   500
//Check: Array is sorted
//
//
//
//
//Time for Quick Sort sorting 75000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 0
//Milli:   406
//Check: Array is sorted
//
//
//
//
//Time for Merge Sort sorting 75000 elements is
//Hours:   0
//Minutes: 0
//Seconds: 0
//Milli:   328
//Check: Array is sorted
//
//
//Press any key to continue . . .
************************************************************/

#define _CRTDBG_MAP_ALLOC
#include <iostream>
	using std::cout;
#include <ctime>	
	using std::time;
#include <vector>
	using std::vector;

#include "SortingAlgorithms.h"
#include "Exception.h"
#include "Array.h"


template <typename T>
void Randomize(T * array_fill, int N);
template <typename T>
void ResetArray(T & filler, T const_array, int N);

int main( const int argc, char * argv[])
{
	// Clear out the old stuff from the file
	ofstream fout("Output.txt");

	// Memory leak checker
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// convert char stars into ints for fast 
	const int length(atoi(argv[1])); 

	// factor for N^2 sorts
	const int shorter_length(atoi(argv[2]));

	if (argc != 3)
	{
		Exception e1("Not the right number of arguments");
		cout << e1.getMessage() << endl;
		return 1; // Ask Todd if this is okay
	}



	int * arrayA = new int[shorter_length];
	int * const_array = new int[shorter_length];

	Randomize(arrayA, shorter_length);

	// Fill the constant array with the rand values
	for (long int j(0); j < shorter_length; ++j)
		const_array[j] = arrayA[j];

	cout << "****************NATIVE ARRAY****************";

	BrutteBubbleSort(arrayA, shorter_length);
	
	ResetArray(arrayA, const_array, shorter_length);
	FlagBubbleSort(arrayA, shorter_length);

	ResetArray(arrayA, const_array, shorter_length);
	Selection(arrayA, shorter_length);

	ResetArray(arrayA, const_array, shorter_length);
	Insertion(arrayA, shorter_length); 

	int * arrayA2 = new int[length];
	int * long_const_array = new int[length];
	Randomize(arrayA2, length);

	// Fill the constant array with the rand values
	for (long int j(0); j < length; ++j)
		long_const_array[j] = arrayA2[j];

	////Long sorts
	ResetArray(arrayA2, long_const_array, length);
	Shell(arrayA2, length);

	ResetArray(arrayA2, long_const_array, length);
	Heap(arrayA2, length);


	ResetArray(arrayA2, long_const_array, length);
	Quick_largest(arrayA2, length);  

	ResetArray(arrayA2, long_const_array, length);
	Merge(arrayA2, length);


	cout << "****************VECTORS****************";

	vector<int> arrayB(shorter_length);

	for (int j(0); j < shorter_length; ++j)
		arrayB[j] = const_array[j];
	BrutteBubbleSort(arrayB, shorter_length);

	for (int j(0); j < shorter_length; ++j)
		arrayB[j] = const_array[j];
	FlagBubbleSort(arrayB, shorter_length);

	for (int j(0); j < shorter_length; ++j)
		arrayB[j] = const_array[j];
	Selection(arrayB, shorter_length);

	for (int j(0); j < shorter_length; ++j)
		arrayB[j] = const_array[j];
	Insertion(arrayB, shorter_length);

	for (int j(0); j < shorter_length; ++j)
		arrayB[j] = const_array[j];

	vector<int> arrayB2(length); // Long Sorts

	for (int j(0); j < length; ++j)
		arrayB2[j] = const_array[j];
	Heap(arrayB2, length);

	for (int j(0); j < length; ++j)
		arrayB2[j] = const_array[j];
	Shell(arrayB2, length);

	for (int j(0); j < length; ++j)
		arrayB2[j] = const_array[j];
	Quick_largest(arrayB2, length);

	for (int j(0); j < length; ++j)
		arrayB2[j] = const_array[j];
	Merge(arrayB2, length);

	cout << "****************My Array Class****************";

	Array<int> arrayC(shorter_length, 0);

	for (int j(0); j < shorter_length; ++j)
		arrayC[j] = const_array[j];
	BrutteBubbleSort(arrayC, shorter_length);

	for (int j(0); j < shorter_length; ++j)
		arrayC[j] = const_array[j];
	FlagBubbleSort(arrayC, shorter_length);

	for (int j(0); j < shorter_length; ++j)
		arrayC[j] = const_array[j];
	Selection(arrayC, shorter_length);

	for (int j(0); j < shorter_length; ++j)
		arrayC[j] = const_array[j];
	Insertion(arrayC, shorter_length);

	Array<int> arrayC2(length, 0);

	for (int j(0); j < length; ++j)
		arrayC2[j] = const_array[j];
	Heap(arrayC2, length);

	for (int j(0); j < length; ++j)
		arrayC2[j] = const_array[j];
	Shell(arrayC2, length);

	for (int j(0); j < length; ++j)
		arrayC2[j] = const_array[j];
	Quick_largest(arrayC2, length);

	for (int j(0); j < length; ++j)
		arrayC2[j] = const_array[j];
	Merge(arrayC2, length);

	delete[] arrayA;
	delete[] const_array;
	delete[] arrayA2;
	delete[] long_const_array;

	return 0;
}

template <typename T>
void Randomize(T * array_fill, int N)
{
	srand(time(0));
	for (int i = 0; i < N; ++i)
		array_fill[i] = rand();
}

template <typename T>
void ResetArray(T & filler, T const_array, int N)
{
	for (int i = 0; i < N; ++i)
		filler[i] = const_array[i];
}
