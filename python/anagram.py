def is_anagram(fst_word, snd_word):
  fst_word=fst_word.upper()
  snd_word=snd_word.upper()
  if(sorted(fst_word)== sorted(snd_word)): 
        return True 
  else: 
        return False
  

print (is_anagram("BrEaD","beArD"))