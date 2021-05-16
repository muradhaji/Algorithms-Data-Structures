def canConstruct(word, wordBank, memo = None):
  if memo == None: memo = {}
  if word in memo: return memo[word]
  if word == "": return True

  for subStr in wordBank:
    if subStr == word[:len(subStr)]:
      if canConstruct(word[len(subStr):], wordBank, memo):
        memo[word] = True
        return True
  
  memo[word] = False
  return False

print(canConstruct("abcdef",["ab","abc","cd","def","abcd"])) #True
print(canConstruct("skateboard",["bo","rd","ate","t","ska","sk"])) #False
print(canConstruct("dynamic",["dy","na","mi","yna","mic","d"])) #True
print(canConstruct("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
["a","aa","aaa","aaaa","aaaaa",]))  #False