def create_cipher(offset):
  alphabet_list=['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
  offset_alphabet=alphabet_list[offset:]+alphabet_list[:offset]
  cipher={}
  n=0
  for i in alphabet_list:
      cipher[i]=offset_alphabet[n]
      n+=1
  cipher[" "]=" "
  return cipher

def encrypt(cipher,message):
    encrypt_mes=''
    for i in range(0,len(message)):
        encrypt_mes+=cipher[message[i]]
        i+=1
    return encrypt_mes


cipher=create_cipher(3)
print(cipher)
print(encrypt(cipher,"cat"))