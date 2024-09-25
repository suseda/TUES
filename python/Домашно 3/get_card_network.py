def get_card_network(card_number):
    l=len(card_number)
    if card_number[0]=='4' and (l==13 or l==16 or l==19):
        return 'Visa'
    elif l==16 and card_number[0]=='5' and (card_number[1]=='1' or card_number[1]=='2' or card_number[1]=='3' or card_number[1]=='4' or card_number[1]=='5'):
        return 'Mastercard'
    elif (l==16 or l==17 or l==18 or l==19) and card_number[0]=='6':
        return 'Discover'
    else:      
        return 'Unknown'

print(get_card_network('4011531243068077'))