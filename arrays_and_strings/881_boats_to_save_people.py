from typing import List


class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        """
        Algorithm intuition:
            - Sort the array to enable greedy two-pointer approach
            - Use two pointers: 'l' (lightest remaining) and 'r' (heaviest remaining)
            - Always put the heaviest person in a boat (they must go somewhere)
            - Then try to pair them with the lightest available person if weight allows
            - This greedy strategy minimizes total boats needed
        Time: O(n log n) - dominated by sorting
        Space: O(1) - only using constant extra space
        """
        people.sort()

        l, r = 0, len(people) - 1  # l: lightest, r: heaviest
        boats = 0

        while l <= r:
            # Always assign the heaviest person to a boat
            remainder = limit - people[r]
            r -= 1  # Remove heaviest person from consideration
            boats += 1  # Count this boat

            # If there's still room, add the lightest available person
            # We can keep adding lightest people as long as they fit
            # (though at most one more person per boat due to problem constraints)
            if l <= r and remainder >= people[l]:
                l += 1  # Pair lightest person with heaviest in same boat

        return boats
