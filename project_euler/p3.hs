ans = helper primes n
  where primes = [n | n<-[2..], not $ elem n [j*k | j<-[2..n-1], k<-[2..min j (n`div`j)]]]
        n = 600851475143

helper cand n
  | hd >= n = n
  | (mod n hd) == 0 = helper cand (div n hd)
  | otherwise = helper (tail cand) n
  where hd = head cand

