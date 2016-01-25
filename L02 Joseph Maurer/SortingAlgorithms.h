#ifndef SORTINGALGORITHMS
#define SORTINGALGORITHMS

#include <iostream>
using std::endl;
using std::cout;
#include <fstream>
using std::ofstream;
#include <ctime>
using std::clock_t;




template <typename T>
void BrutteBubbleSort(T & arr, int n);

template <typename T>
void FlagBubbleSort(T & arr, int n);

template <typename T>
void Selection(T & arr, int n);

template <typename T>
void Insertion(T & arr, int n);

template <typename T>
void Shell(T & arr, int n);


template <typename T>
bool verify();

template <typename T>
void PrintTimes(char name[], double time, int n, T & arr);

template <typename T>
double stop_timer(double start, char  name[], T & arr, int n);

template <typename T>
void Swap(T & ArrayA, T & ArrayB);









template <typename T>
void BrutteBubbleSort(T & arr, int n)
{
	cout << endl << endl;
	clock_t start(clock());

	int pass(0);
	for (int i(0); i < n; ++i)
	{
		for (int j(0); j < (n - pass - 1); ++j)
		{
			if (arr[j] > arr[j + 1])
				Swap(arr[j], arr[j + 1]);
		}
		pass++;
	}
	double time = stop_timer(start, "Brutte Force Bubble", arr, n);
	PrintTimes("Brutte Force Bubble", time, n, arr);
}

template <typename T>
void FlagBubbleSort(T & arr, int n)
{
	clock_t start(clock());
	int pass(0);
	bool sorted(false);
	for (int i(0); i < n && sorted == false; i++)
	{
		sorted = true;
		for (int j(0); j < (n - pass - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				sorted = false;
				Swap(arr[j], arr[j + 1]);
			}
		}
	}
	double time = stop_timer(start, "Flagged Force Bubble", arr, n);
	PrintTimes("Flagged Force Bubble", time, n, arr);
}

template <typename T>
void Selection(T & arr, int n)
{
	clock_t start(clock());
	int N = n;
	int max(0);
	for (int i(0); i < N; ++i)
	{
		max = 0;
		for (int j = 1; j < (N - i); ++j)
		{
			if (arr[j] > arr[max])
				max = j;
		}
		Swap(arr[N - i - 1], arr[max]);
	}
	double time = stop_timer(start, "Selection", arr, n);
	PrintTimes("Selection", time, n, arr);
	//for (int a(0); a < m_n; ++a)
	//cout << m_array[a] << ' ';
}

template <typename T>
void Insertion(T & arr, int n)
{ 
	clock_t start(clock());

	int temp = 0;
	for (int i = 1, j = 0; i < n; ++i)
	{
		temp = arr[i];
		for (j = i; j > 0 && temp < arr[j - 1]; --j)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
	double time = stop_timer(start, "Insertion", arr, n);
	PrintTimes("Insertion", time, n, arr);
}

template <typename T>
void HeapBuild(int first_index, int last_index, T & arr)
{
	// calculate the largest 
	int largest_index = (first_index * 2) + 1;

	while (largest_index <= last_index)
	{
		// make sure not out of bounds
		if (largest_index < last_index && arr[largest_index] < arr[largest_index + 1])
		{
			largest_index++; // just look at the next item
		}
		if (arr[first_index] < arr[largest_index])// reset the parent
		{
			Swap(arr[largest_index], arr[first_index]);
			first_index = largest_index;
			largest_index = (first_index * 2) + 1;
		}
		else
		{
			largest_index = last_index + 1;
		}
	}
}
template <typename T>    
void Heap(T & arr, int n)
{
	clock_t start(clock());
	int first_index(0);
	int last_index(n);
	//loop starting first at the midpoint of the array and continue
	// while first is greater than or equal to zero
	for (first_index = (n / 2) /*- 1*/; first_index >= 0; first_index--)
	{
		HeapBuild(first_index, last_index - 1, arr);
	}

	for (int i(n - 1); i > 0; i--)
	{
		Swap(arr[0], arr[i]);
		HeapBuild(0, i - 1, arr);
	}

	double time = stop_timer(start, "Heap", arr, n);
	PrintTimes("Heap", time, n, arr);
	//for (int a(0); a < m_n; ++a)
	//	cout << m_array[a] << ' ';
}


template <typename T>
void Shell(T & arr, int n)
{
	int temp_location = 0;
	//T temp_value = 0;

	clock_t start(clock());

	int length = (n / 2);
	int * Increments = new int[length];

	for (int h(0), i(0); h < n; i++)
	{
		Increments[i] = h;
		h = (3 * h) + 1;
	}


	for (int a(0); a < length; ++a)
	{
		int h = Increments[length - a];
		for (int hCnt = h; hCnt < (2 * h); ++hCnt)
		{
			// insertion sort
			for (int i(hCnt); i < n;)
			{ 
				int temp = arr[i];
				temp_location = i;
				while ((temp_location - h) >= 0 && temp < arr[temp_location - h])
				{
					arr[temp_location] = arr[temp_location - h];
					temp_location = temp_location - h;
				}
				arr[temp_location] = temp;
				i = i + h;
			}
		}
	}

	double time = stop_timer(start, "Shell", arr, n);
	PrintTimes("Shell", time, n, arr);

	delete[] Increments;
	Increments = nullptr;
}



template <typename T>
void Quick(int first, int last, T & arr)
{
	int small = first + 1;
	int large = last;
	int pivot = arr[first];

	while (small <= large)
	{
		while (arr[small] < pivot)
			small++;
		while (arr[large] > pivot)
			large--;
		if (small < large)
		{
			Swap(arr[small], arr[large]);
			small++;
			large--;
		}
		else
			small++;
	}

	Swap(arr[large], arr[first]);

	if (first < large - 1)
		Quick(first, large - 1, arr);

	if (last > large+1)
		Quick(large+1, last, arr);

}
template <typename T>
void Quick_largest(T & arr, int n)
{
	//for (int a(0); a < n; ++a)
	//	cout << arr[a] << ' ';
	//cout << endl;
	clock_t start(clock());
	int max(0);
	if (n >= 2)
	{
		for (int i(1); i < n; i++)
		{
			if (arr[max] < arr[i])
				max = i;
		}
		Swap(arr[n - 1], arr[max]);
		
		Quick(0, n - 2, arr);
	}
	double time = stop_timer(start, "Quick", arr, n);
	PrintTimes("Quick", time, n, arr);

	/*for (int a(0); a < n; ++a)
		cout << arr[a] << ' ';*/
}




template <typename T>
void Merge(T & arr, int n)
{
	//cout << endl;
	//for (int a(0); a < n; ++a)
	//	cout << arr[a] << ' ';
	//cout << endl;
	clock_t start(clock());
	int * temp_array = new int [n];

	Merge_sort(temp_array, 0, (n - 1), arr);

	delete[] temp_array;
	temp_array = nullptr;
	double time = stop_timer(start, "Merge", arr, n);
	PrintTimes("Merge", time, n, arr);

	//for (int a(0); a < n; ++a)
	//	cout << arr[a] << ' ';
	//cout << endl;
}

template <typename T>
void Merge_sort(int temp[], int left_index, int right_index, T & arr)
{
	if (left_index < right_index)
	{
		int mid = ((left_index + right_index) / 2); // find the middle

		Merge_sort(temp, left_index, mid, arr);
		Merge_sort(temp, mid + 1, right_index, arr);
		Merge_algorithm(temp, left_index, mid + 1, right_index, arr);
	}

}
template <typename T>
void Merge_algorithm(int temp[], int left, int right, int right_end, T & arr)
{
	int left_end = right - 1;
	int temp_pos = left;
	
	int left_start = left;

	while (left <= left_end && right <= right_end)
	{
		if (arr[left] <= arr[right])
		{
			temp[temp_pos] = arr[left];
			temp_pos++;
			left++;
		}
		else
		{
			temp[temp_pos] = arr[right];
			temp_pos++;
			right++;
		}
	}
	if (left <= left_end)
	{
		while (temp_pos <= right_end  && left <= left_end)
		{
			temp[temp_pos] = arr[left];
			temp_pos++;
			left++;
		}
	}
	if (right <= right_end)
	{
		while (temp_pos <= right_end && right <= right_end)
		{
			temp[temp_pos] = arr[right];
			temp_pos++;
			right++;
		}
	}

	while (left_start <= right_end)
	{
		arr[left_start] = temp[left_start];
		//T temp2 = 0;
		//	temp2 = *&temp[left_start];
		//arr[left_start] = *temp2;
		left_start++;
	}
}



template <typename T>
double stop_timer(double start, char  name[], T & arr, int n)
{
	clock_t end(clock());
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\n\nTime for " << name << " Sort sorting "
		<< n << " elements is" << endl;


	cout << "Hours:   " << (int)time / 3600 << endl;
	cout << "Minutes: " << (((int)time % 3600) / 60) << endl;
	cout << "Seconds: " << ((int)time % 60) << endl;
	cout << "Milli:   " << (int)(time * 1000) % 1000 << endl;
	bool prove = verify(arr, n);
	if (prove == 1)
		cout << "Check: Array is sorted\n";
	else
		cout << "Check: Array IS NOT sorted\n";
	return time;

}
template <typename T>
bool verify(T & arr, int n)
{
	bool test(true);
	for (int i(0); i < (n - 1); i++)
	{
		if (arr[i] > arr[i + 1])
			test = false;
	}
	return test;
}

template <typename T>
void PrintTimes(char name[], double time, int n, T & arr)
{
	ofstream fout("Output.txt", std::ios_base::app);

	if (fout.is_open())
	{
		fout << "\n\nTime for " << name << " Sort sorting " << n << " elements is" << endl;
		fout << "Hours:   " << (int)time / 3600 << endl;
		fout << "Minutes: " << (((int)time % 3600) / 60) << endl;
		fout << "Seconds: " << ((int)time % 60) << endl;
		fout << "Milli:   " << (int)(time * 1000) % 1000 << endl;

		for (int i(0); i < n; i++)
			fout << arr[i] << ' ';
		cout << endl << endl;

		fout.close();
	}
	else
		cout << "File not opened\n";
}


template <typename T>
void Swap(T & ArrayA, T & ArrayB)
{
	T Temp(ArrayA);
	ArrayA = ArrayB;
	ArrayB = Temp;
}

#endif