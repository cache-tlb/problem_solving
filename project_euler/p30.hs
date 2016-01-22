n = 10^7

digits n = (map read $ map (\x -> [x]) $ show n) :: [Int]

ans = sum $ filter (\x -> x == (sum $ map (^5) $ digits x)) [2..n]