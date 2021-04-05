#include <iostream>
#include <vector>
using namespace std;

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec)
{
    os << "{";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(os, ","));
    os << "}";
    return os;
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
    void quickSort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int pivot = partition(nums, low, high);
            quickSort(nums, low, pivot -1);
            quickSort(nums, pivot +1, high);
        }
    }
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        while (low < high) {
            while (low < high && nums[high] >= pivot)
                --high;
            nums[low] = nums[high];
            while (low < high && nums[low] <= pivot)
                ++low;
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }
};

//int main()
//{
//    //Your MyQueue object will be instantiated and called as such:
//    Solution s;
//    vector<int> nums1 = { 5, 2, 3, 1 };
//    vector<int> nums2 = { 5,1,1,2,0,0};
//    vector<int> nums= s.sortArray(nums2);
//    cout << nums;
//    return 0;
//}
