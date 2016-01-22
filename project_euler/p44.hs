pen x = div (x*(3*x-1)) 2
pens = map pen [1..]
short_ps = take 3000 pens

isPen y = n*(3*n-1)==2*y where n = nth y
nth y = round ((sqrt(1.0 + 24.0*fromIntegral(y)) + 1.0) / 6.0)


ans = minimum [b - a | b <- short_ps, a <- takeWhile (<b) short_ps, isPen(b-a), isPen(b+a)]