
isPrime a = isPrimeHelper a primes
isPrimeHelper a (p:ps)
  | p*p > a = True
  | a `mod` p == 0 = False
  | otherwise = isPrimeHelper a ps
primes = 2 : filter isPrime [3..]


ndigits x = ndigitsAux x 0 where
  ndigitsAux x acc
    | x == 0 = acc
    | otherwise = ndigitsAux (div x 10) (acc+1)

shiftList x = shiftListAux n x [] where
  n = ndigits x
  big = 10^(n-1)
  shiftListAux 0 _ acc = acc
  shiftListAux c x acc = shiftListAux (c - 1) cur (cur:acc) where
    cur = (mod x big)*10 + (div x big)

xs = filter check $ takeWhile (< 1000000) primes
check x = check_helper $ shiftList x where
  check_helper [] = True
  check_helper (x:xs) = if (isPrime x) then (check_helper xs) else False

ans = length xs
