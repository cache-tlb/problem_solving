import Data.List

isPrime :: Int -> Bool
isPrime x | x < 2 = False
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

select _ [] = [[]]
select 0 _ = [[]]
select k xs = [x:p | x <- xs, p <- select (k - 1) (removeFirst x xs)] where
    removeFirst x [] = []
    removeFirst x (y:ys)
        | x == y = ys
        | otherwise = y : removeFirst x ys

ps = takeWhile (<10000) $ dropWhile (<1000) primes

isPerm x y = (sort $ show x) == (sort $ show y)

ans = [(x,y,z) | x <- ps, y <- ps, y > x, isPerm x y, let z = 2*y - x, isPerm x z, isPrime z]
