fact n = fact' n 1 where
  fact' 1 acc = acc
  fact' n acc = fact' (n - 1) (acc*n)

nums :: [Int]
nums = map read $ map (\x -> [x]) $ show $fact 100
ans = sum nums