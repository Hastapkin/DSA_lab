#include <iostream>
#include <vector>
using namespace std;

// 1. Modify binary search to count occurrences of a target value in a sorted array
int countOccurrences(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1, count = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            count++;
            // Count occurrences on the left and right of mid
            int leftMid = mid - 1;
            while (leftMid >= left && arr[leftMid] == target) {
                count++;
                leftMid--;
            }
            int rightMid = mid + 1;
            while (rightMid <= right && arr[rightMid] == target) {
                count++;
                rightMid++;
            }
            break;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}

// 2. Implement jump search with adjustable step size
int jumpSearch(const vector<int>& arr, int target, int stepSize) {
    int n = arr.size();
    int step = stepSize;
    int prev = 0;
    
    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += stepSize;
        if (prev >= n) return -1;
    }
    
    for (int i = prev; i < min(step, n); ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// 3. Modify interpolation search for an array of strings
int interpolationSearchString(const vector<string>& arr, const string& target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }
        int pos = low + ((target.compare(arr[low]) * (high - low)) / (arr[high].compare(arr[low])));
        if (arr[pos] == target) {
            return pos;
        }
        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

// 4. Find missing number using binary search
int findMissingNumber(const vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] != mid) {
            if (mid == 0 || arr[mid - 1] == mid - 1) {
                return mid;
            }
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return arr.size();
}

// 7. Find the kth smallest element in an unsorted array using modified binary search
#include <queue>

int findKthSmallest(const vector<int>& arr, int k) {
    priority_queue<int> maxHeap;
    for (int num : arr) {
        maxHeap.push(num);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

int main() {
    // Example for binary search count occurrences
    vector<int> sortedArray = {1, 2, 2, 2, 3, 4, 5};
    cout << "Count of 2: " << countOccurrences(sortedArray, 2) << endl;

    // Example for jump search
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};
    cout << "Index of 9: " << jumpSearch(arr, 9, 3) << endl;

    // Example for interpolation search with strings
    vector<string> stringArr = {"apple", "banana", "cherry", "date", "fig"};
    cout << "Index of 'cherry': " << interpolationSearchString(stringArr, "cherry") << endl;

    // Example for finding missing number
    vector<int> missingArr = {0, 1, 2, 4, 5, 6};
    cout << "Missing number: " << findMissingNumber(missingArr) << endl;

    // Example for finding kth smallest element
    vector<int> unsortedArray = {7, 10, 4, 3, 20, 15};
    cout << "3rd smallest element: " << findKthSmallest(unsortedArray, 3) << endl;

    return 0;
}
