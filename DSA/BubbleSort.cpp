// C++ program to implement
// of Bubble sort
#include <iostream>
using namespace std;

// Function to sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j+1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 3, 1, 4, 2, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, N);

    cout << "Sorted array: ";
    printArray(arr, N);
    return 0;
}