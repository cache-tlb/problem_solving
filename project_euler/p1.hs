-- let n = 1000 in p1 n where
p1 n = sum ([x | x <- [1..n-1], (mod x 3)==0 || (mod x 5)==0 ])