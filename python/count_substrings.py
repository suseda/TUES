def count_substrings(haystack, needle):
    if len(needle) > len(haystack):
        return 0
    
    if needle == haystack:
        return 1

    i = 0
    count = 0
    while i < len(haystack):
        if haystack[i: i + len(needle)] == needle:
            count += 1
            i += len(needle)
        else:
            i += 1
    return count

print(count_substrings("This is a test string", "is"))
print(count_substrings("babababa", "baba"))
print(count_substrings("Python is an awesome language to program in!", "o"))
print(count_substrings("We have nothing in common!", "really?"))
print(count_substrings("This is this and that is this", "this"))