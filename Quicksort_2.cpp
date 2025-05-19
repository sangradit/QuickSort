#include <iostream>
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
	int i = l+1;
	for(int j=l+1; j<=r; j++)
	{
		if(arr[j] < pivot)
		{
			swap(&arr[j], &arr[i]);
			i++;
		}
	}
	swap(&arr[l], &arr[i-1]);
	return (i-1);

}
void quickSort(int arr[], int l, int r)
{
	if(l<r)
	{
		int x = partition(arr, l ,r);
		quickSort(arr, l, x-1);
		quickSort(arr, x+1, r);
	}
}
void printArr(int arr[], int length)
{
	for(int i=0; i<length; i++)
		cout << arr[i] << endl;
}
void getArr(int arr[], int length)
{
	cout << "Enter the numbers!" << endl;
	for(int i=0; i<length; i++)
		cin >> arr[i];
}
int getLength()
{
	int length;
	cout << "Enter the length of the array!" << endl;
	cin >> length; 
	return length;
}
int main() {
	
	int length = getLength();
	int arr[length];
	getArr(arr, length);
	cout << endl << endl << "--------------" << endl << endl;
	quickSort(arr, 0, length-1);
	printArr(arr, length);
	return 0;
}
