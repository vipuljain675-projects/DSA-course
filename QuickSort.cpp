#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int partition(vector<int>& arr, int st, int end)
    {
        // Choose the last element as pivot
        int pivot = arr[end];

        // i keeps track of the last position of elements <= pivot
        int i = st - 1;

        // Compare every element with the pivot
        for (int j = st; j < end; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;

                swap(arr[i], arr[j]);
            }
        }

        // Place the pivot in its correct position
        i++;
        swap(arr[i], arr[end]);

        // Return the pivot index
        return i;
    }

    void quickSort(vector<int>& arr, int st, int end)
    {
        // Base Case
        if (st < end)
        {
            // Find the correct position of pivot
            int pivotIndex = partition(arr, st, end);

            // Sort the left part
            quickSort(arr, st, pivotIndex - 1);

            // Sort the right part
            quickSort(arr, pivotIndex + 1, end);
        }
    }
};

int main()
{
    vector<int> arr = {6, 3, 9, 5, 2, 8};

    Solution obj;

    cout << "Original Array: ";
    for (int x : arr)
        cout << x << " ";

    cout << endl;

    obj.quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";
    for (int x : arr)
        cout << x << " ";

    cout << endl;

    return 0;
}
