def is_card_number_valid(number):
    tmp = [int(x) for x in number]  
    for i in range(len(tmp) - 2, -1, -2):
        tmp[i] *= 2
        if tmp[i] > 9:
            tmp[i] -= 9
    return sum(tmp) % 10 == 0

def filter_valid(grouped_card_numbers):
    m = 0
    n = 0
    for card_network, card_numbers in grouped_card_numbers.items():
        n = 0
        for card_number in card_numbers:
            m = card_number
            if is_card_number_valid(m) == 0:
                grouped_card_numbers[card_network].remove(grouped_card_numbers[card_network][n])
            n = n + 1
    return(grouped_card_numbers)


grouped_card_numbers = {
'Visa':
['4916734313471210','4916734313471211','4485988000328437','4916195917598231366'],
'Mastercard': ['5417266585296299','5555555555554444','5176971378227838',],
'Discover': ['6011531243068077','6011663835677047','6011701484601571523',],
'Unknown':
['346331303550927','343551581289061','348001148210148','343551581289060',]
}
print(filter_valid(grouped_card_numbers))
