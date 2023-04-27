#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = pivot;
    arr[high] = temp;
    return i; // index of pivot
}

void Quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pidx = partition(arr, low, high);

        Quicksort(arr, low, pidx - 1);
        Quicksort(arr, pidx + 1, high);
    }
}

int main()
{
    int arr[] = {6, 3, 9, 5, 2, 1666666};
    int n = sizeof(arr) / sizeof(arr[0]);
    Quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
