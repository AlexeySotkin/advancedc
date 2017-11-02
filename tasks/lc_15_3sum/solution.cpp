#include <algorithm>
#include <iostream>

// O(n) = n*log(n) + (n^2/2)*log(n)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // using set to uniquify triplets
        set<vector<int>> tmp;
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        std::sort(nums.begin(), nums.end());
        for (auto a = ++nums.begin(), N = nums.end(); a != N; ++a) {
            for (auto b = nums.begin(); b < a; ++b) { // Since the square is simetric, we can drop half of it
                auto c = std::lower_bound(nums.begin(), nums.end(), -(*a + *b));
                if (c != nums.end() && c != a && c != b && *a+*b+*c == 0) {
                    vector<int> v{*a, *b, *c};
                    std::sort(v.begin(), v.end());
                    tmp.insert(v);
                }
            }
        }
        
        return vector<vector<int>>(tmp.begin(), tmp.end());
    }
};
