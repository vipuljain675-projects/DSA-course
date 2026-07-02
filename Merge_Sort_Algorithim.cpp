/*
=========================================================
        Merge Sort (Apna College Style)
=========================================================
*/

#include <iostream>
#include <vector>

using namespace std;

//---------------------------------------------------------
// Merge Function
//---------------------------------------------------------
void merge(vector<int>& arr, int st, int mid, int end)
{
    vector<int> temp;

    int i = st;
    int j = mid + 1;

    // Compare Left & Right Half
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Remaining Left Half
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    // Remaining Right Half
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy Temp into Original Array
    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[idx + st] = temp[idx];
    }
}

//---------------------------------------------------------
// Merge Sort
//---------------------------------------------------------
void mergeSort(vector<int>& arr, int st, int end)
{
    // Base Case (Exactly as taught by Shraddha Ma'am)
    if (st < end)
    {
        int mid = st + (end - st) / 2;

        // Left Half
        mergeSort(arr, st, mid);

        // Right Half
        mergeSort(arr, mid + 1, end);

        // Merge
        merge(arr, st, mid, end);
    }
}

//---------------------------------------------------------
// Driver Code
//---------------------------------------------------------
int main()
{
    vector<int> arr = {6, 3, 9, 5, 2, 8};

    cout << "Original Array\n\n";

    for (int x : arr)
        cout << x << " ";

    cout << "\n\n";

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array\n\n";

    for (int x : arr)
        cout << x << " ";

    cout << endl;

    return 0;
}