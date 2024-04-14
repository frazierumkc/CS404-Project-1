#pragma once
#include <vector>
#include <random>

using namespace std;

template<typename Item_Type>
class Sort {
public:

	/*Returns a sorted copy of a vector using selection sort algorithm.
	* @param unsortedVector Vector to be sorted
	* @return Sorted copy of the vector
	*/
	vector<Item_Type> selectionSort(vector<Item_Type> unsortedVector) {

		vector<Item_Type> v = unsortedVector;
		Item_Type temp;

		for (int i = 0; i < v.size() - 1; i++) {

			temp = v[i];
			int minIndex = i;
			for (int j = i + 1; j < v.size(); j++) {
				if (v[j] < v[minIndex]) {
					minIndex = j;
				}
			}

			v[i] = v[minIndex];
			v[minIndex] = temp;
		}

		return v;
	}

	/*Returns a sorted copy of a vector using insertion sort algorithm.
	* @param unsortedVector Vector to be sorted
	* @return Sorted copy of the vector
	*/
	vector<Item_Type> insertionSort(vector<Item_Type> unsortedVector) {

		vector<Item_Type> v = unsortedVector;
		Item_Type temp;

		for (int i = 1; i < v.size(); i++) {
			int j = i;
			while (j > 0 && v[j] < v[j - 1]) {
				temp = v[j];
				v[j] = v[j - 1];
				v[j - 1] = temp;

				j = j - 1;
			}
		}

		return v;
	}

	/*Returns a sorted copy of a vector using quick sort algorithm.
	* @param unsortedVector Vector to be sorted
	* @return Sorted copy of the vector
	*/
	vector<Item_Type> quickSort(vector<Item_Type> unsortedVector) {
		vector<Item_Type> v = unsortedVector;
		quickSortImp(v, 0, v.size() - 1);
		return v;
	}

	/*Returns a sorted copy of a vector using merge sort algorithm.
	* @param unsortedVector Vector to be sorted
	* @return Sorted copy of the vector
	*/
	vector<Item_Type> mergeSort(vector<Item_Type> unsortedVector) {
		vector<Item_Type> v = unsortedVector;
		
		mergeSortImp(v, 0, v.size() - 1);

		return v;
	}

	/*Returns a sorted copy of a vector using bubble sort algorithm.
	* @param unsortedVector Vector to be sorted
	* @return Sorted copy of the vector
	*/
	vector<Item_Type> bubbleSort(vector<Item_Type> unsortedVector) {
		vector<Item_Type> v = unsortedVector;
		Item_Type temp;

		for (int i = 0; i < v.size(); i++) {
			for (int i = 0; i < v.size() - 1; i++) {
				if (v[i] > v[i + 1]) {
					temp = v[i];
					v[i] = v[i + 1];
					v[i + 1] = temp;
				}
			}
		}

		return v;
	}

private:

	/*Implementation of quick sort algorithm. Sorts a vector using quick sort algorithm.
	* @param unsortedVector Vector to be sorted
	*/
	void quickSortImp(vector<Item_Type>& unsortedVector, int low, int high) {

		if (low < high) {
			// Partition index
			int pi = partition(unsortedVector, low, high);

			quickSortImp(unsortedVector, low, pi - 1);
			quickSortImp(unsortedVector, pi + 1, high);
		}
	}

	/*Partition function for use in quick sort algorithm.
	* @param unsortedVector Vector to find the partition of
	*/
	int partition(vector<Item_Type>& unsortedVector, int low, int high)
	{
		// pivot is last element in vector
		Item_Type pivot = unsortedVector[high];
		Item_Type temp;
		int i = (low - 1);

		for (int j = low; j <= high; j++)
		{
			if (unsortedVector[j] < pivot)
			{
				i++;
				temp = unsortedVector[i];
				unsortedVector[i] = unsortedVector[j];
				unsortedVector[j] = temp;
			}
		}
		temp = unsortedVector[i + 1];
		unsortedVector[i + 1] = unsortedVector[high];
		unsortedVector[high] = temp;
		return (i + 1);
	}

	/*Implementation of merge sort algorithm. Sorts a vector using merge sort algorithm.
	* @param v Vector to be sorted
	* @param begin Left-most index of the sub-vector to be sorted
	* @param end Right-most index of the sub-vector to be sorted
	*/
	void mergeSortImp(vector<Item_Type>& v, int const begin, int const end)
	{
		if (begin >= end)
			return;

		int mid = begin + (end - begin) / 2;
		mergeSortImp(v, begin, mid);
		mergeSortImp(v, mid + 1, end);
		merge(v, begin, mid, end);
	}

	/*Merges two sub-vectors.
	*/
	void merge(vector<Item_Type>& v, int const left, int const mid, int const right)
	{
		int const subOne = mid - left + 1;
		int const subTwo = right - mid;

		// Create temporary arrays
		auto* leftArray = new Item_Type[subOne], * rightArray = new Item_Type[subTwo];

		// Copy data to temporary arrays
		for (auto i = 0; i < subOne; i++)
			leftArray[i] = v[left + i];
		for (auto j = 0; j < subTwo; j++)
			rightArray[j] = v[mid + 1 + j];

		auto indexOfSubOne = 0, indexOfSubTwo = 0;
		int indexOfMergedArray = left;

		// Merge the temporary arrays back into vector
		while (indexOfSubOne < subOne && indexOfSubTwo < subTwo) {
			if (leftArray[indexOfSubOne] <= rightArray[indexOfSubTwo]) {
				v[indexOfMergedArray] = leftArray[indexOfSubOne];
				indexOfSubOne++;
			}
			else {
				v[indexOfMergedArray] = rightArray[indexOfSubTwo];
				indexOfSubTwo++;
			}
			indexOfMergedArray++;
		}

		// Copy the remaining elements of left array
		while (indexOfSubOne < subOne) {
			v[indexOfMergedArray] = leftArray[indexOfSubOne];
			indexOfSubOne++;
			indexOfMergedArray++;
		}

		// Copy the remaining elements of right array
		while (indexOfSubTwo < subTwo) {
			v[indexOfMergedArray] = rightArray[indexOfSubTwo];
			indexOfSubTwo++;
			indexOfMergedArray++;
		}
		delete[] leftArray;
		delete[] rightArray;
	}
};