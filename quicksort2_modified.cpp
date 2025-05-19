//bikin dulu input.txt isi angka pake https://texttools.org/random-number-generator
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

int partition(int arr[], int l, int r) //time complexity partition: O(n) karena kita ngeliat setiap elemen dalam array yg jumlahnya itu n
{				       //nah walaupun udah dipartisi jadi dua kita tetap ngeliat setiap elemennya lagi yg jumlahnya n kali
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
		quickSort(arr, l, x - 1); //dalam kasus ideal dimana nilai pivotnya merupakan nilai tengah data, berarti kan data itu dibagi dua
		quickSort(arr, x + 1, r); //jadi banyaknya kita bagi array itu jadi dua (level partition) adalah log2(n) kali,
	}				  //fungsi partition dengan time complexity untuk setiap level O(n) dieksekusi sebanyak log2(n) kali
}					  //sehingga time complexity Quick Sort dalam kasus ideal adalah O(nlogn)

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
