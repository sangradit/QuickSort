#include <bits/stdc++.h>
using namespace std;

void printPartition(int a[], int l, int r, int i) {
    cout << "[";
    for (int k = l; k <= r; ++k) {
        if (k == i)
            cout << "(" << a[k] << ")";
        else
            cout << a[k];
        if (k < r)
            cout << " ";
    }
    cout << "]" << endl;
}

// This function partitions a[] in three parts
void partition(int a[], int l, int r, int& i, int& j)
{
    i = l - 1, j = r;
    int p = l - 1, q = r;
    int v = a[r]; // pivot is last element

    while (true) {
        while (a[++i] < v);
        while (v < a[--j])
            if (j == l)
                break;

        if (i >= j)
            break;

        swap(a[i], a[j]);

        if (a[i] == v) {
            p++;
            swap(a[p], a[i]);
        }

        if (a[j] == v) {
            q--;
            swap(a[j], a[q]);
        }
    }

    swap(a[i], a[r]);

    j = i - 1;
    for (int k = l; k < p; k++, j--)
        swap(a[k], a[j]);

    i = i + 1;
    for (int k = r - 1; k > q; k--, i++)
        swap(a[i], a[k]);

    // Show partition info (pivot at i - 1 after final placement)
    printPartition(a, l, r, i - 1);
}

// 3-way partition based quick sort
void quicksort(int a[], int l, int r)
{
    if (r <= l)
        return;

    int i, j;
    partition(a, l, r, i, j);
    quicksort(a, l, j);
    quicksort(a, i, r);
}

// Print array
void printarr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Unable to open file input.txt" << endl;
        return 1;
    }

    vector<int> values;
    int num;
    while (inputFile >> num) {
        values.push_back(num);
    }
    inputFile.close();

    int size = values.size();
    if (size == 0) {
        cout << "The file is empty." << endl;
        return 1;
    }

    int* a = new int[size];
    for (int i = 0; i < size; i++) {
        a[i] = values[i];
    }

    cout << "Original Array:\n";
    printarr(a, size);

    cout << "--------------\nPartition Steps:\n";
    quicksort(a, 0, size - 1);

    cout << "--------------\nSorted Array:\n";
    printarr(a, size);

    delete[] a;
    return 0;
}
