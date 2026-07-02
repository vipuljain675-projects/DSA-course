// Count Inversions using Merge Sort
// Time: O(n log n)
// Space: O(n)

#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;

    int i = st;
    int j = mid + 1;

    int invCount = 0;

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
            invCount += (mid - i + 1);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[st + idx] = temp[idx];
    }

    return invCount;
}

int mergeSort(vector<int> &arr, int st, int end)
{
    if (st >= end)
        return 0;

    int mid = st + (end - st) / 2;

    int leftInvCount = mergeSort(arr, st, mid);
    int rightInvCount = mergeSort(arr, mid + 1, end);

    int invCount = merge(arr, st, mid, end);

    return leftInvCount + rightInvCount + invCount;
}

int main()
{
    vector<int> arr = {6, 3, 5, 2, 7};

    int ans = mergeSort(arr, 0, arr.size() - 1);

    cout << "Inversion Count = " << ans << endl;

    return 0;
}