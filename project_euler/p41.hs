import Data.List
isPrime :: Int -> Bool
isPrime x = f x primes where
  f :: Int -> [Int] -> Bool
  f x (p:ps)
    | x < p^2        = True
    | x `mod` p == 0 = False
    | otherwise      = f x ps


primes :: [Int]
primes = 2:3:sieve [5] [x + y | x <- [6,12..], y <- [-1,1]] where
  sieve :: [Int] -> [Int] -> [Int]
  sieve (p:ps) xs = let (ys, zs) = span (< p^2) xs
                    in ys ++ sieve (ps ++ ys) [z | z <- zs, mod z p /= 0]


check x = sort sx == take (length sx) ['1'..] where sx = show x

ans = last $ filter check $ takeWhile (<=7654321) primes
