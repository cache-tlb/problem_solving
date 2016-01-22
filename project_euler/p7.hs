ans = primes !! ind where
  ind = 10000
  primes = pgen [2..]
  pgen[] = []
  pgen (p:xs) = p : pgen [x|x <- xs, x `mod` p > 0]

--p7 = head (reverse (take 10001 (primes [2..])))

--sieve :: Int -> [Int] -> [Int]
--sieve n ls = [x | x <- ls, x `mod` n /= 0]

--primes :: [Int] -> [Int]
--primes [] = []
--primes (x:xs) = x : primes (sieve x xs)


-- below calcs fast
--isPrime n (x:xs) = (x*x > n) || (mod n x /= 0) && (isPrime n xs)
--primes = 2 : filter (\x -> isPrime x primes) [3..]

-- another, a bit slower than last one
--isPrime a = isPrimeHelper a primes

--isPrimeHelper a (p:ps)
--        | p*p > a        = True
--        | a `mod` p == 0 = False
--        | otherwise      = isPrimeHelper a ps

--primes = 2 : filter isPrime [3..]