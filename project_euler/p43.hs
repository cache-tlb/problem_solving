perms [] = [0]
perms xs = [p*10 + x | x <- xs, p <- perms (removeFirst x xs)] where
  removeFirst x [] = []
  removeFirst x (y:ys)
    | x == y = ys
    | otherwise = y : removeFirst x ys

nums = perms [0..9]

xs = filter check nums

ans = sum xs

primes = reverse [2,3,5,7,11,13,17]

check x = helper x primes where
  helper x [] = True
  helper x (p:ps) = if (mod (mod x 1000) p)/=0 then False
                    else helper (div x 10) ps