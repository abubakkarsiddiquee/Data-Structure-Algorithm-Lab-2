#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<int>& A, int N, int M) {
    if (M > N) {
        return -1; // Invalid input
    }
    
    sort(A.begin(), A.end()); // Sort the array
    
    long long minDiff = INT_MAX; // Initialize minDiff with a large value
    
    for (int i = 0; i + M - 1 < N; ++i) {
        long long diff = A[i + M - 1] - A[i]; // Calculate difference for current window
        minDiff = min(minDiff, diff); // Update minDiff with minimum difference found so far
    }
    
    return minDiff;
}

int main() {
        int N, M;
        cin >> N >> M; // Number of chocolates and number of students
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i]; // Input array
        }
        long long minDiff = findMinDiff(A, N, M);
        cout << minDiff << endl;
    }
