n = 500

ans = head $ filter (\x -> (fact_num x) > n) tri_num

tri_num = tail $ scanl (+) 0 [1..]

isPrime a = isPrimeHelper a primes

isPrimeHelper a (p:ps)
        | p*p > a        = True
        | a `mod` p == 0 = False
        | otherwise      = isPrimeHelper a ps
primes = 2 : filter isPrime [3..]

fact_num n = fact_helper 0 primes 1 n
  where
    fact_helper cur_k plist acc num
      | hd > num = acc * (cur_k + 1)
      | (mod num hd) == 0 = fact_helper (cur_k + 1) plist acc (div num hd)
      | otherwise = fact_helper 0 (tail plist) (acc * (cur_k + 1)) num
      where hd = head plist