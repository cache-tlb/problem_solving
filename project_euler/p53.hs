fact 0 = 1
fact n = product [1..n]
c n k = div (fact n) ((fact k)*(fact (n - k)))
ans = length $ filter (> 1000000) [c n k | n <- [1..100], k <- [0..n]]