#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Partition function for QuickSort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Binary Search function
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    srand(time(0));

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    // Generate random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    cout << "\nGenerated array:\n";
    for (int x : arr) cout << x << " ";

    // Sort array
    quickSort(arr, 0, n - 1);

    cout << "\n\nSorted array:\n";
    for (int x : arr) cout << x << " ";

    // Search element
    int target;
    cout << "\n\nEnter element to search: ";
    cin >> target;

    int result = binarySearch(arr, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}