def howSum(sum, nums):
  if sum < 0: return None
  if sum == 0: return []
  for num in nums:
    result = howSum(sum-num, nums)
    if result != None:
      result.append(num)
      return result
  return None

print(howSum(7, [2,3])) #[3,2,2]
print(howSum(7, [5,3,4,7])) #[4,3]
print(howSum(7, [2,4])) #None
print(howSum(8, [2,3,5])) #[2,2,2,2]
print(howSum(300, [7,14])) #Takes too long
