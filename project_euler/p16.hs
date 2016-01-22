n = 2^1000
nums = (map read (map (\x -> [x]) (show n))) :: [Int]
ans = sum nums