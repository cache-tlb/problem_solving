n = 2000000
ans = sum $ takeWhile (< n) primes

isPrime a = isPrimeHelper a primes

isPrimeHelper a (p:ps)
        | p*p > a        = True
        | a `mod` p == 0 = False
        | otherwise      = isPrimeHelper a ps

primes = 2 : filter isPrime [3..]
