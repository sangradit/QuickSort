#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int left, int right){				      
	int pivot = arr[left];                      //leftmost element as pivot
	int i = left + 1;                           //index of smaller element
	for (int j = left + 1; j <= right; j++){
		if (arr[j] < pivot){
			swap(&arr[j], &arr[i]);             //swap elements
			i++;
		}
	}
	swap(&arr[left], &arr[i - 1]);              //place pivot in correct position
            
	cout << "[";                                //show partition info
	for (int k = left; k <= right; k++) {
		if (k == i - 1)
			cout << "(" << arr[k] << ")";       // mark pivot position
		else
			cout << arr[k];
		if (k < right) cout << " ";
	}
	cout << "]" << endl;

	return (i - 1);
}

void quickSort(int arr[], int left, int right) {
	if (left < right){
		int pi = partition(arr, left, right);   //partition index
		quickSort(arr, left, pi - 1);           //sort left subarray
		quickSort(arr, pi + 1, right);          //sort right subarray
	}			
}					  

void printArr(int arr[], int length){
	for (int i = 0; i < length; i++)
		cout << arr[i] << " ";
}

int main(){
	ifstream inputFile("input.txt");            //read values from file into vector
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
