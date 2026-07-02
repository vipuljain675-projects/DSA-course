#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& stalls, int n, int cows, int minDist)
{
    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i = 1; i < n; i++)
    {
        if(stalls[i] - lastPos >= minDist)
        {
            cowCount++;
            lastPos = stalls[i];

            if(cowCount == cows)
            {
                return true;
            }
        }
    }

    return false;
}

int aggressiveCows(vector<int>& stalls, int cows)
{
    sort(stalls.begin(), stalls.end());

    int n = stalls.size();

    int start = 1;
    int end = stalls[n - 1] - stalls[0];

    int ans = -1;

    while(start <= end)
    {
        int mid = start + (end - start) / 2;

        if(isPossible(stalls, n, cows, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9};

    int cows = 3;

    cout << aggressiveCows(stalls, cows);

    return 0;
}