fibs3 = 0 : scanl (+) 1 fibs3

t = zip [0..] fibs3

ndigit x = length $ show x

lst = dropWhile (\x -> (ndigit $ snd x) < 1000) t

ans = fst $ head lst