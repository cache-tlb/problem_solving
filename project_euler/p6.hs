ans = sum2 - sum1 where
  n = 100
  xs = [1..n]
  sum1 = sum (map (^2) xs)
  sum2 = (sum xs) ^ 2