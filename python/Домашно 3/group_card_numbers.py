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

def group_card_numbers(card_numbers):
    visa_cards=[]
    mastercard_cards=[]
    discover_cards=[]
    unknown_cards=[]
    dict_for_cards={'Visa': visa_cards,'Mastercard': mastercard_cards,'Discover': discover_cards,'Unknown': unknown_cards}
    i=0
    l=len(card_numbers)
    while(l!=0):
        if get_card_network(card_numbers[i])=='Visa':
            visa_cards.append(card_numbers[i])
        elif get_card_network(card_numbers[i])=='Mastercard':
            mastercard_cards.append(card_numbers[i])
        elif get_card_network(card_numbers[i])=='Discover':
            discover_cards.append(card_numbers[i])
        else:
            unknown_cards.append(card_numbers[i])
        l=l-1
        i=i+1
    return dict_for_cards



print(group_card_numbers(card_numbers = [
'4916734313471210',
'4916734313471211',
'4485988000328437',
'4916195917598231366',
'5417266585296299',
'5555555555554444',
'5176971378227838',
'6011531243068077',
'6011663835677047',
'6011701484601571523',
'346331303550927',
'343551581289061',
'343551581289060',
'348001148210148',
]))