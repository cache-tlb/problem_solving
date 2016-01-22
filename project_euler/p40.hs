import Data.Char

str = map show [1..1000000]

ith n (x:xs) = if n <= length x then ord (x !! (n - 1)) - 48 else ith (n - (length x)) xs

xs = map (10^) [0..6]

ans = product $ map (\x -> ith x str) xs