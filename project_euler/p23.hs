import Data.List

isPrime a = isPrimeHelper a primes
isPrimeHelper a (p:ps)
        | p*p > a        = True
        | a `mod` p == 0 = False
        | otherwise      = isPrimeHelper a ps
primes = 2 : filter isPrime [3..]

sum_pfact x = helper primes [] 0 [] x where
  helper plist@(p:ps) facts curk ks num
    | num == 1 = helper2 (p:facts) (curk:ks)
    | (mod num p) == 0 = helper plist facts (curk+1) ks (div num p)
    | curk == 0 = helper ps facts 0 ks num
    | otherwise = helper ps (p:facts) 0 (curk:ks) num
  helper2 facts ks = product $ map (\x -> sum $ map ((fst x) ^ ) [0..(snd x)]) $ zip facts ks

sum_purefact x = sum_pfact x - x

is_abundant x = sum_purefact x > x

abundant = filter is_abundant [1..n]

asum = nub $ sort [x+y | x <- abundant, y <- abundant, y >= x]
n = 28123
xs = takeWhile (<=n) asum
ans = (sum [1..n]) - (sum xs)

