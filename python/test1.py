def create_cipher(offset):
  alphabet_list=['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
  chipher={}
  n,i=0,0
  while i < (len(alphabet_list)):
      if i>=(len(alphabet_list)-offset):
          chipher[alphabet_list[i]]=alphabet_list[n]
          i+=1
          n+=1
      else:
        chipher[alphabet_list[i]]=alphabet_list[i+offset]
        i+=1
        
    
  # while n < offset:
  #  chipher[alphabet_list[i]]=alphabet_list[n]
   #   i+=1
    #  n+=1

  return chipher

def encrypt(cipher,message):
    encrypt_mes=''
    for i in range(0,len(message)):
        encrypt_mes+=cipher[message[i]]
        i+=1
    return encrypt_mes

cipher=create_cipher(3)
print(cipher)
print(encrypt(cipher,"abcz"))