class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        create a dictionary which stores the complement
        if dic[complement] is in dic, return the index
        """
        dic = {}

        for i in range(len(nums)):
            comp = target - nums[i]

            if comp in dic:
                return [dic[comp], i]

            dic[nums[i]] = i

        return [-1, -1]
