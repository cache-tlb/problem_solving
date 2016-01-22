h n = n*(2*n - 1)
t n = div (n*(n + 1)) 2
p n = div (n*(3*n - 1)) 2

ans = head [h x | x <- [144..], check $ h x] where
  check y = (t n1 == y) && (p n2 == y) where
    n1 = round $ (-1.0 + sqrt(1.0+8.0*fromIntegral(y)))/2.0
    n2 = round $ (-1.0 + sqrt(1.0+24.0*fromIntegral(y)))/6.0