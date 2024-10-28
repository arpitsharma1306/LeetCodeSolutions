#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("O3", "unroll-loops")
#pragma GCC optimize ("-ffloat-store")

auto init = []() { 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
} ();

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        constexpr int N{100'000};
        std::array<bool, N+1> ns{};

        for(const int i : nums) { ns[i] = true; }

        int ans{-1};

        for(size_t i{0}; i<N; ++i) {
            if (ns[i] == false) { continue; }

            int len{0};
            size_t index{i};
            while(index < N && ns[index]) {
                ++len;
                index = index * index;
            }

            if (len > 1) { ans = std::max(ans, len); }
        }

        return ans;
    }
};