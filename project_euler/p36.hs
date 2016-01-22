palindromic x = (x == rev) && (head x)/=0 && (head rev)/=0
  where rev = reverse x


base x b = reverse $ baseAux x b
baseAux x b
  | x == 0 = []
  | otherwise = (mod x b) : (baseAux (div x b) b)

ans = sum cand
cand = [x | x <- [1..999999], (palindromic (base x 2)) && (palindromic (base x 10))]
