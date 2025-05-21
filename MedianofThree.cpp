#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

// Return index of median of three
int medianOfThree(int arr[], int left, int right) {
	int mid = left + (right - left) / 2;
	if (arr[left] > arr[mid]) swap(&arr[left], &arr[mid]);
	if (arr[left] > arr[right]) swap(&arr[left], &arr[right]);
	if (arr[mid] > arr[right]) swap(&arr[mid], &arr[right]);
	return mid;
}

int partition(int arr[], int left, int right) {
	int medianIdx = medianOfThree(arr, left, right);
	swap(&arr[medianIdx], &arr[right]); // Move pivot to end
	int pivot = arr[right];

	int i = left;
	for (int j = left; j < right; j++) {
		if (arr[j] < pivot) {
			swap(&arr[j], &arr[i]);
			i++;
		}
	}
	swap(&arr[i], &arr[right]); // place pivot in correct position

    // Show partition info
	cout << "[";
	for (int k = left; k <= right; ++k) {
		if (k == i)
			cout << "(" << arr[k] << ")";
		else
			cout << arr[k];
		if (k < right) cout << " ";
	}
	cout << "]" << endl;

	return i;
}

void quickSort(int arr[], int left, int right) {
	if (left < right){
		int pi = partition(arr, left, right);
		quickSort(arr, left, pi - 1);
		quickSort(arr, pi + 1, right);
	}			
}

void printArr(int arr[], int length){
	for (int i = 0; i < length; i++)
		cout << arr[i] << " ";
}

int main(){
	ifstream inputFile("input.txt");
	if (!inputFile){
		cerr << "Unable to open file input.txt" << endl;
		return 1;
	}
	vector<int> values;
	int num;
	while (inputFile >> num){
		values.push_back(num);
	}
	inputFile.close();

	int length = values.size();
	int arr[length];

	for (int i = 0; i < length; i++)
		arr[i] = values[i];

	cout << "Original Array:\n";
	printArr(arr, length);
	cout << endl << "--------------" << endl << "Partition:\n";
	quickSort(arr, 0, length - 1);
	cout << "--------------" << endl << "Sorted Array:\n";
	printArr(arr, length);
	cout << endl << endl;
	return 0;
}
