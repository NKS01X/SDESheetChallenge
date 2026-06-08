class Solution {
public:
    int reversePairs(vector<int>& nums) {

        auto cntBeforeMerging = [&](int lo, int mid, int hi)->int {
            int count = 0;
            int j = mid + 1;

            for (int i = lo; i <= mid; ++i) {
                while (j <= hi && (long long)nums[i] > 2LL * nums[j]) {
                    j++;
                }
                count += (j - (mid + 1));
            }
            return count;
        };

        const auto& merge = [&](int lo, int mid, int hi) -> void {
            int i = lo, j = mid + 1;
            vector<int> temp;

            while (i <= mid && j <= hi) {
                if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
                else temp.push_back(nums[j++]);
            }

            while (i <= mid) temp.push_back(nums[i++]);
            while (j <= hi) temp.push_back(nums[j++]);

            for (int i = lo; i <= hi; ++i) {
                nums[i] = temp[i - lo];
            }
        };

        const auto& cnt = [&](auto& self, int lo, int hi)->int {
            if (lo >= hi) return 0;

            int mid = lo + (hi - lo) / 2;

            int left = self(self, lo, mid);
            int right = self(self, mid + 1, hi);

            int curr = cntBeforeMerging(lo, mid, hi);

            merge(lo, mid, hi);

            return left + right + curr;
        };

        return cnt(cnt, 0, nums.size() - 1);
    }
};