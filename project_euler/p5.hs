ans = foldl (\x y -> (div (x * y)  (gcd x y))) 1 xs where xs = [1..20]
