isPrime a = isPrimeHelper a primes

isPrimeHelper a (p:ps)
        | p*p > a        = True
        | a `mod` p == 0 = False
        | otherwise      = isPrimeHelper a ps
primes = 2 : filter isPrime [3..]

helper n nprime total
  | (nprime * 10) < total = n
  | otherwise = helper newn (nprime + (length (filter isPrime [x1,x2,x3]))) (total+4)
  where newn = n + 2
        x1 = newn^2 - newn + 1
        x2 = x1 - newn + 1
        x3 = x2 - newn + 1

ans = helper 7 8 13