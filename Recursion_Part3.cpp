#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//=========================================================
// METHOD 1 : Print All Subsets (No Duplicates in Array)
// Example Input : {1,2,3}
//=========================================================

void printSubsets(vector<int>& arr, vector<int>& subset, int idx)
{
    // Base Case
    if(idx == arr.size())
    {
        cout << "{ ";

        for(int x : subset)
        {
            cout << x << " ";
        }

        cout << "}" << endl;
        return;
    }

    // Include Current Element
    subset.push_back(arr[idx]);
    printSubsets(arr, subset, idx + 1);

    // Backtrack
    subset.pop_back();

    // Exclude Current Element
    printSubsets(arr, subset, idx + 1);
}

//=========================================================
// METHOD 2 : Print Subsets (Duplicates Allowed in Array)
// Example Input : {1,2,2}
//=========================================================

void printSubsetsWithDuplicates(vector<int>& arr, vector<int>& subset, int idx)
{
    // Base Case
    if(idx == arr.size())
    {
        cout << "{ ";

        for(int x : subset)
        {
            cout << x << " ";
        }

        cout << "}" << endl;
        return;
    }

    // Include Current Element
    subset.push_back(arr[idx]);
    printSubsetsWithDuplicates(arr, subset, idx + 1);

    // Backtrack
    subset.pop_back();

    // Skip all duplicate elements before going to Exclude branch
    while(idx + 1 < arr.size() && arr[idx] == arr[idx + 1])
    {
        idx++;
    }

    // Exclude Current Element
    printSubsetsWithDuplicates(arr, subset, idx + 1);
}

//=========================================================
// MAIN
//=========================================================

int main()
{
    // ---------------- METHOD 1 ----------------
    cout << "All Subsets (Unique Elements)\n\n";

    vector<int> arr1 = {1,2,3};
    vector<int> subset1;

    printSubsets(arr1, subset1, 0);

    cout << "\n=====================================\n\n";

    // ---------------- METHOD 2 ----------------
    cout << "Subsets With Duplicate Handling\n\n";

    vector<int> arr2 = {1,2,2};

    // Sort is compulsory
    sort(arr2.begin(), arr2.end());

    vector<int> subset2;

    printSubsetsWithDuplicates(arr2, subset2, 0);

    return 0;
}