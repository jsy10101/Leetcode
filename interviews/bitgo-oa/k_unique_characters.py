def KUniqueCharacters(strParam):
    """
    Algorithm Approach:
    - Use sliding window technique to find longest substring with exactly k unique characters
    - Start from index 1 (second character) since first character is k
    - Use a hash map to track character frequencies in current window
    - Expand window when unique chars < k, shrink when unique chars > k
    - Keep track of the longest valid substring found
    - Finally, concatenate with challenge token and replace every 4th char with underscore

    Time: O(n) where n is length of string
    Space: O(k) for the character frequency map
    """

    if len(strParam) < 2:
        return strParam

    # Extract k from first character and the actual string to process
    k = int(strParam[0])
    s = strParam[1:]  # Start from second position

    if k == 0 or len(s) == 0:
        return ""

    # Sliding window approach
    left = 0
    char_count = {}
    max_length = 0
    result_start = 0

    for right in range(len(s)):
        # Add current character to window
        char_count[s[right]] = char_count.get(s[right], 0) + 1

        # Shrink window if we have more than k unique characters
        while len(char_count) > k:
            char_count[s[left]] -= 1
            if char_count[s[left]] == 0:
                del char_count[s[left]]
            left += 1

        # Check if current window has exactly k unique characters
        if len(char_count) == k:
            current_length = right - left + 1
            if current_length > max_length:
                max_length = current_length
                result_start = left

    # Extract the longest substring with k unique characters
    if max_length == 0:
        longest_substring = ""
    else:
        longest_substring = s[result_start : result_start + max_length]

    # Concatenate with challenge token
    challenge_token = "ps208emd49b"
    final_result = longest_substring + challenge_token

    # Most efficient: Use string slicing and join
    # Take every 4-character chunk, replace 4th char with underscore
    chunks = []
    for i in range(0, len(final_result), 4):
        chunk = final_result[i : i + 4]
        if len(chunk) == 4:
            chunks.append(chunk[:3] + "_")
        else:
            chunks.append(chunk)  # Last chunk if shorter than 4

    return "".join(chunks)


# Test with the provided examples
print(KUniqueCharacters("3aabbacbebebe"))  # Expected: cbe_ebe_sz0_emd_9b
print(KUniqueCharacters("2aabbcbbbdef"))  # Expected: bbc_bbp_z08_md4_b
