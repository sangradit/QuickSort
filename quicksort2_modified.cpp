#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int l, int r)
{
	int pivot = arr[l];
	int i = l + 1;
	for (int j = l + 1; j <= r; j++)
	{
		if (arr[j] < pivot)
		{
			swap(&arr[j], &arr[i]);
			i++;
		}
	}
	swap(&arr[l], &arr[i - 1]);
	return (i - 1);
}

void quickSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int x = partition(arr, l, r);
		quickSort(arr, l, x - 1);
		quickSort(arr, x + 1, r);
	}
}

void printArr(int arr[], int length)
{
	for (int i = 0; i < length; i++)
		cout << arr[i] << endl;
}

int main()
{
	ifstream inputFile("input.txt");
	if (!inputFile)
	{
		cerr << "Unable to open file input.txt" << endl;
		return 1;
	}

	vector<int> values;
	int num;
	while (inputFile >> num)
	{
		values.push_back(num);
	}
	inputFile.close();

	int length = values.size();
	int arr[length];

	for (int i = 0; i < length; i++)
		arr[i] = values[i];

	cout << endl << "--------------" << endl << "Sorted Array:\n";
	quickSort(arr, 0, length - 1);
	printArr(arr, length);

	return 0;
}
