isPrime a
  | a < 2 = False
  | otherwise = isPrimeHelper a primes
isPrimeHelper a (p:ps)
  | p*p > a = True
  | a `mod` p == 0 = False
  | otherwise = isPrimeHelper a ps
primes = 2 : filter isPrime [3..]

ndigits x = ndigitsAux x 0 where
  ndigitsAux x acc
    | x == 0 = acc
    | otherwise = ndigitsAux (div x 10) (acc+1)

trunk x = trunkAux (10^(ndigits x - 1)) x [] [] where
  trunkAux den x acc1 acc2
    | den < 10 = (acc1, acc2)
    | otherwise = trunkAux (div den 10) x ((div x den):acc1) ((mod x den):acc2)

xs = take 11 $ filter check $ dropWhile (<10) primes

ans = sum xs

check x = checkAux $ trunk x where
  checkAux ([], []) = True
  checkAux (x1:xs1, x2:xs2)
    | isPrime x1 && isPrime x2 = checkAux (xs1, xs2)
    | otherwise = False
