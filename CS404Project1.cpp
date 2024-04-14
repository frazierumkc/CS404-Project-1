#include <iostream>
#include <chrono>
#include "Sort.h"

using namespace std;
using namespace std::chrono;

int main() {
	Sort <int> mySort;
	vector<vector<int>> myVector;
	
	// Quantity of integers per vector, change as needed
	const int NUMBER_OF_INTEGERS = 100;
	// Quantity of vectors (number of times sorting test will be repeated)
	const int NUMBER_OF_REPS = 100;

	myVector.resize(NUMBER_OF_REPS);
	
	// Fill each vector with random integers
	for (int i = 0; i < NUMBER_OF_REPS; i++) {
		for (int j = 0; j < NUMBER_OF_INTEGERS; j++) {
			myVector[i].push_back(rand() % 1000);
		}
	}

	// Bubble sort test
	auto start = high_resolution_clock::now();
	for (int i = 0; i < NUMBER_OF_REPS; i++) {
		mySort.bubbleSort(myVector[i]);
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Average time taken by bubble sort algorithm: " << static_cast<double>(duration.count())
		/ static_cast<double>(NUMBER_OF_REPS) << " microseconds\n\n";

	// Selection sort test
	start = high_resolution_clock::now();
	for (int i = 0; i < NUMBER_OF_REPS; i++) {
		mySort.selectionSort(myVector[i]);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Average time taken by selection sort algorithm: " << static_cast<double>(duration.count())
		/ static_cast<double>(NUMBER_OF_REPS) << " microseconds\n\n";

	// Insertion sort test
	start = high_resolution_clock::now();
	for (int i = 0; i < NUMBER_OF_REPS; i++) {
		mySort.insertionSort(myVector[i]);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Average time taken by insertion sort algorithm: " << static_cast<double>(duration.count())
		/ static_cast<double>(NUMBER_OF_REPS) << " microseconds\n\n";

	// Quick sort test
	start = high_resolution_clock::now();
	for (int i = 0; i < NUMBER_OF_REPS; i++) {
		mySort.quickSort(myVector[i]);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Average time taken by quick sort algorithm: " << static_cast<double>(duration.count())
		/ static_cast<double>(NUMBER_OF_REPS) << " microseconds\n\n";

	// Merge sort test
	start = high_resolution_clock::now();
	for (int i = 0; i < NUMBER_OF_REPS; i++) {
		mySort.mergeSort(myVector[i]);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Average time taken by merge sort algorithm: " << static_cast<double>(duration.count())
		/ static_cast<double>(NUMBER_OF_REPS) << " microseconds\n\n";

}