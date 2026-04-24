#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> count;
    
    void mergeSort(vector<pair<int,int>>& v, int left, int right) {
        if (left >= right) return;
        int mid = (left + right) / 2;
        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);
        merge(v, left, mid, right);
    }

    void merge(vector<pair<int,int>>& v, int left, int mid, int right) {
        vector<pair<int,int>> temp;
        int i = left, j = mid + 1;
        int rightCount = 0;

        while (i <= mid && j <= right) {
            if (v[j].first < v[i].first) {
                rightCount++;
                temp.push_back(v[j++]);
            } else {
                count[v[i].second] += rightCount;
                temp.push_back(v[i++]);
            }
        }

        while (i <= mid) {
            count[v[i].second] += rightCount;
            temp.push_back(v[i++]);
        }

        while (j <= right) {
            temp.push_back(v[j++]);
        }

        for (int k = left; k <= right; k++) {
            v[k] = temp[k - left];
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        count.assign(n, 0);
        vector<pair<int,int>> v;
        
        for (int i = 0; i < n; i++)
            v.push_back({nums[i], i});
        
        mergeSort(v, 0, n - 1);
        return count;
    }
};

int main() {
    vector<int> nums = {5,2,6,1};
    Solution obj;
    vector<int> res = obj.countSmaller(nums);
    
    for (int x : res) cout << x << " ";
    return 0;
}