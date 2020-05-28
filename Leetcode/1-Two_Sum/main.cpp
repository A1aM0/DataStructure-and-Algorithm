#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for(i=0;i<nums.size()-1;i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    return {i,j};
                }
            }
        }
        return {i,j};
    };
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> a{1, 2, 3, 4, 6, 5};
    Solution s;
    vector<int> ans = s.twoSum(a, 10);
//    cout << ss;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}