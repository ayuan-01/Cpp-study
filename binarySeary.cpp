#include <iostream>
#include <vector>
using namespace std;

int binarySeach(vector<int> nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left)/2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return left;
}

int main() {
    vector<int> nums = {1, 2, 3, 4,5};
    int res = binarySeach(nums, 3);

    cout << res;

    return 0;

}
