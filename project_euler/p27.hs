import Data.List
import Data.Ord
isPrime a
  | a < 2 = False
  | otherwise = isPrimeHelper a primes
isPrimeHelper a (p:ps)
  | p*p > a = True
  | a `mod` p == 0 = False
  | otherwise = isPrimeHelper a ps
primes = 2 : filter isPrime [3..]

xs = [(n,(a*b)) | b <- (takeWhile (<999) primes), a <- [-999..999], isPrime (1 + a + b), let n = helper a b 1]
helper a b n
  | isPrime (n*n + (a*n) + b) = helper a b (n + 1)
  | otherwise = n - 1

ans = maximumBy (comparing fst) xs
