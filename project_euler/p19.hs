leap n
  | mod n 400 == 0 = True
  | mod n 100 == 0 = False
  | mod n 4 == 0 = True
  | otherwise = False

days n = if leap n then 366 else 365
l1 = [31,28,31,30,31,30,31,31,30,31,30,31]
l2 = [31,29,31,30,31,30,31,31,30,31,30,31]

months = foldl (\acc x-> acc ++ (if leap x then l2 else l1)) [] [1901..2000]

firstday = scanl (\acc x -> mod (acc+x) 7) 2 months

ans = length $ filter (==0) $ init firstday