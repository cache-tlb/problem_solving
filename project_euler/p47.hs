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

hasNFactor x limit = helper x primes 0 where
  helper x (p:ps) acc
    | acc > limit = False
    | x == 1 = if acc == limit then True else False
    | x `mod` p == 0 = helper (helper2 x p) ps (acc+1)
    | otherwise = helper x ps acc
  helper2 x p
    | x `mod` p /= 0 = x
    | otherwise = helper2 (x `div` p) p

nums = [2..]

xs = filter (\x -> hasNFactor x 4) nums

ans = helper xs where
  helper l@(x1:x2:x3:x4:_) = if (x1+1==x2)&&(x2+1==x3)&&(x3+1==x4) then x1 else helper (tail l)