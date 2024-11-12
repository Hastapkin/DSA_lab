//Sort student records by grades, names, or age. 
//Evaluate the performance of various sorting algorithms for large datasets.
//Sorting by different attributes (alphabetical names or numerical grades)
//Merge Sort would be suitable for a stable sort, preserving the relative order of students with equal grades.
#include <iostream>
#include <vector>
#include <algorithm>

// Counting Sort function
void countingSort(std::vector<int>& arr) {
    int maxElement = *std::max_element(arr.begin(), arr.end());
    std::vector<int> count(maxElement + 1, 0);

    for (int num : arr) count[num]++;
    int index = 0;
    for (int i = 0; i <= maxElement; ++i) {
        while (count[i]-- > 0) arr[index++] = i;
    }
}

// Main function to test Counting Sort
int main() {
    std::vector<int> data = {4, 2, 2, 8, 3, 3, 1};
    countingSort(data);

    std::cout << "Sorted Array: ";
    for (int num : data) std::cout << num << " ";
    return 0;
}
