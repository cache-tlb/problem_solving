ans = sum ([x | x <- xs, (mod x 2)==0])
      where xs = takeWhile (< 4000000) fibs1
            fibs1 = 1 : 2 : zipWith (+) fibs1 (tail fibs1)