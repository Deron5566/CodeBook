#include <bits/stdc++.h>
using namespace std;

int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
}

int mergeSort(vector<int>& nums, int l, int r){
    int m, i, j, ans = 0;
    if(l >= r)
        return 0;

    m = l + (r - l) / 2;
    ans += mergeSort(nums, l, m);
    ans += mergeSort(nums, m + 1, r);

    i = l, j = m + 1;
    while(i <= m && j <= r){
        if(nums[i] > nums[j]){
            ans += m - i + 1;
            j++;
        }
        else
            i++;
    }
    inplace_merge(nums.begin() + l, nums.begin() + m + 1, nums.begin() + r + 1);
    return ans;
}
