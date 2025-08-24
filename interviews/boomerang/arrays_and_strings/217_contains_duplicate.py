class Solution:
    # set solution
    # def containsDuplicate(self, nums: List[int]) -> bool:
    #     """
    #     1. We can use a set to add unique elements to set
    #     2. while adding each element to set, we check if the current element is already in set
    #     3. if true, we return true, else iterate through till end.
    #     """
    #     seen = set()

    #     for num in nums:
    #         if num in seen:
    #             return True
    #         seen.add(num)
    #     return False

    # hash map solution
    def containsDuplicate(self, nums: List[int]) -> bool:
        seen = {}

        for num in nums:
            if num in seen and seen[num] >= 1:
                return True
            seen[num] = seen.get(num, 0) + 1

        return False
