-- unbelievable !!!

upper = 1000000

answer50 = snd $ f primes (1, 2) where

  f :: [Int] -> (Int, Int) -> (Int, Int)
  f ps y@(i, _) = let xs = zip [1..] $ takeWhile (< upper) $ scanl1 (+) ps
                  in if length xs <= i then y
                                       else f (tail ps) (g xs y)

  g :: [(Int, Int)] -> (Int, Int) -> (Int, Int)
  g xs y@(i, _) = let xs' = filter (isPrime.snd) $ dropWhile ((<= i).fst) xs
                  in if xs' == [] then y
                                  else last xs'


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
