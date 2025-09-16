class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        """
        Algorithm intuition:
            - since we need to return top k elements, we can use a heap with a hash map
            - the hash map can be first used to store the counts
            - for heap (min heap), we can insert a tuple of (freq, elem_value)
            - we use a min heap to only keep top k frequencies
            - we then iterate through the counts, val first
            - we do max k insertions in heap, if current size of heap exceeds k, we pop from heap
        Time: O(n log k)
        Space: O(k)
        """

        counts = defaultdict(int)
        for num in nums:
            counts[num] += 1

        max_heap = []

        for key, val in counts.items():
            print(key, val)
            heapq.heappush(max_heap, (val, key))
            if len(max_heap) > k:
                heapq.heappop(max_heap)

        ans = []
        for _, k in max_heap:
            ans.append(k)

        return ans
