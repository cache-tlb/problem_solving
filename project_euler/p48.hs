s = sum $ map (\x -> x^x) [1..1000]
ans = mod s (10^10)