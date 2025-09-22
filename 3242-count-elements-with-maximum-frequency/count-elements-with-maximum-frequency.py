class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        mp = {}
        maxFreq = 0
        for i in range(len(nums)):
            mp[nums[i]] = mp.get(nums[i],0) + 1
            if mp[nums[i]]>maxFreq:
                maxFreq=mp[nums[i]]

        count = 0
        for ele in mp:
            if mp[ele]==maxFreq:
                count += mp[ele]
        
        return count
        