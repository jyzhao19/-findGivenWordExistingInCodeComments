#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> arr, int num) {

    int arrLength = arr.size();
    vector<int> dp(arrLength, INT_MIN); // max subarray ending at every indices

    dp[0] = arr[0];
    for (int i = 1; i < arrLength; i++) {
        if (dp[i - 1] > 0) {
            dp[i] = dp[i - 1] + arr[i];
        }
        else 
            dp[i] = arr[i];
    }

    int slidWindow = 0;
    for (int i=0;i<num; i++)
        slidWindow += arr[i];

    int res = slidWindow;
    for (int i = num; i<arrLength; i++) {
        slidWindow = slidWindow + arr[i] - arr[i-num];
        res = max(res, max(slidWindow, slidWindow+dp[i-num]));
    }
    
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr = vector<int>(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        int k;
        cin >> k;
        cout << solution(arr, k) << endl;
    }
    return 0;
}
