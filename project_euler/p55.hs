getPalindrome x = helper x 0 10 where
  helper x acc base
    | x == 0 = acc
    | otherwise = helper (div x base) (acc*base + (mod x base)) base

isPalindromic x = x == getPalindrome x

isLychrel x limit = helper (x + getPalindrome x) limit where
  helper x limit
    | limit < 0 = True
    | x == getPalindrome x = False
    | otherwise = helper (x + getPalindrome x) (limit - 1)

ans = length cand
cand = filter (\x -> (isLychrel x 49)) [1..10000]