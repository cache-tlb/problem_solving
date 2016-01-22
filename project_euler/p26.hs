cyclelen x
  | x == 1 = 0
  | mod x 2 == 0 = cyclelen $ div x 2
  | mod x 5 == 0 = cyclelen $ div x 5
  | otherwise = head $ filter (\y -> mod (10^y - 1) x == 0) [1..]

ans = maximum $ zip (map cyclelen [1..999]) [1..999]