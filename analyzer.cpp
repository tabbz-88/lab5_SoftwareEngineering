#include <iostream>
#include <chrono>
#include <array>
#include "StringData.h"
using namespace std;

int binarySearch(vector<string> data, string searchStr) {
    int low = 0;
    int high = data.size() - 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (data[mid] == searchStr)
            return mid;
        if (data[mid] < searchStr)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int linearSearch(vector<string> data, string searchStr) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == searchStr)
            return i;
    }
    return -1;
}

int main() {
    std::vector<std::string>& data = getStringData();
    auto start = std::chrono::high_resolution_clock::now();
    string searchStr = "mzzzz";
    int searchIndex = binarySearch(data, searchStr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << "Found at index " << searchIndex << " in " << duration.count() << " seconds";
    return 0;
}