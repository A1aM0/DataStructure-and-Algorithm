//
//  main.cpp
//  leetcode-661
//
//  Created by 杨松皓 on 2022/3/24.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
//        return forceTraverse(img);
        return prefixSum(img);
    }
    
private:
    /// 暴力循环
    vector<vector<int>> forceTraverse(vector<vector<int>>& img) {
        vector<vector<int>> result(img.size(), vector<int>(img.front().size()));
        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img.front().size(); j++) {
                int cnt = 0, sum = 0;
                for (int row = i - 1; row <= i + 1; row++) {
                    for (int col = j - 1; col <= j + 1; col++) {
                        if (row < 0 || row >= img.size() || col <0 || col >= img.front().size()) continue;
                        cnt++;
                        sum += img[row][col];
                    }
                }
                result[i][j] = sum / cnt;
            }
        }
        printVector(result);
        return result;
    }
    
    /// 前缀和
    vector<vector<int>> prefixSum(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img.front().size();
        
        vector<vector<int>> preSum(img.size() + 1, vector<int>(img.front().size() + 1));
        for (int i = 1; i < preSum.size(); i++) {
            for (int j = 1; j < preSum.front().size(); j++) {
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + img[i - 1][j - 1];
            }
        }
        
        vector<vector<int>> result(img.size(), vector<int>(img.front().size()));
        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img.front().size(); j++) {
                int left = max(j - 1, 0);
                int right = min(j + 1, cols - 1);
                int up = max(i - 1, 0);
                int down = min(i + 1, rows - 1);
                
                int cnt = (right - left + 1) * (down - up + 1);
                int sum = preSum[down + 1][right + 1] - preSum[up][right + 1] - preSum[down + 1][left] + preSum[up][left];
                result[i][j] = sum / cnt;
            }
        }
        printVector(result);
        return result;
    }
    
    /// 打印数组
    void printVector(vector<vector<int>>& vec) {
        cout << "resule is: " << endl;
        for (vector<int>& row : vec) {
            for (int num : row) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> img1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> img2 = {{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};
    s.imageSmoother(img1);
    s.imageSmoother(img2);
    
    return 0;
}
