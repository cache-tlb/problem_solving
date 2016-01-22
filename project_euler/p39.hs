import Data.List

xs = zip (map (\x -> length (nsolutions x)) lst) lst where lst = [12..1000]

nsolutions s = [a | a <- [1..div s 3], (a*a)`mod`(s-a)==0, let b = div (s - a - div (a*a) (s-a)) 2, b > a]
--nsolutions s = [a | a <- [1..div s 3], b <- [a..div s 2], let c = s - a - b, (a*a)+(b*b)==(c*c)]

ans = maximum xs