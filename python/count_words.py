def count_words(my_list):
    words={}
    for i in range(0,len(my_list)):
        words[my_list[i]]=my_list.count(my_list[i])
    return words
print(count_words(["apple", "banana", "apple", "pie"]))