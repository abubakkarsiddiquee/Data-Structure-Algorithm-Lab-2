#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (nums[j] <= pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[right]);
    return i + 1;
}

int quickselect(vector<int>& nums, int k, int left, int right) {
    if (left == right) {
        return nums[left];
    }
    int pivotIndex = partition(nums, left, right);
    int countRight = right - pivotIndex + 1;
    if (countRight == k) {
        return nums[pivotIndex];
    } else if (countRight > k) {
        return quickselect(nums, k, pivotIndex + 1, right);
    } else {
        return quickselect(nums, k - countRight, left, pivotIndex - 1);
    }
}
int findKthLargest(vector<int>& nums, int k) {
    return quickselect(nums, k, 0, nums.size() - 1);
}

int main() {
    int n, k;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Input: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "k: ";
    cin >> k;

    int result = findKthLargest(nums, k);
    cout << result << endl;

    return 0;
}
