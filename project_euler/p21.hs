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

amicable 1 = 1
amicable x = (sum_pfact x) - x

ans = sum $ filter (\x -> let y = amicable x in (y /= x) && (x == amicable y)) [1..10000]