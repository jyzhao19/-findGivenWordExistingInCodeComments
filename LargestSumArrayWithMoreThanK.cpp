#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> arr, int num) {
    int arrLength = arr.size();
    vector<int> dp(arrLength, INT_MIN);
    vector<int> dp_s(arrLength, 0);
    dp[num - 1] = 0;
    for (int i = 0; i<num; i++)
        dp[num - 1] += arr[i];

    int res = dp[num - 1];
    for (int i = num; i<arrLength; i++) {
        if (dp[i - 1] >= 0 || arr[dp_s[i - 1]]>0) {
            dp[i] = dp[i - 1] + arr[i];
            dp_s[i] = dp_s[i - 1];
        }
        else {
            dp[i] = dp[i - 1] + arr[i] - arr[dp_s[i - 1]];
            dp_s[i] = dp_s[i] + 1;
        }
        res = res > dp[i] ? res : dp[i];
    }

    cout << "JZ: ";
    for (auto i : dp_s)
        cout << i << " ";

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
