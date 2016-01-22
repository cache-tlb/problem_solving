import Data.Array

chain x
  | x == 1 || x == 89 = x
  | otherwise = chain $ digiSqrSum x


digiSqrSum x = f x 0
  where f 0 acc = acc
        f x acc = f d (m*m + acc) where (d, m) = divMod x 10

bound = (1,10^7)

cache = array bound [(i, look i) | i <- range bound] where
  look x
    | x == 1 || x == 89 = x
    | otherwise = cache ! (digiSqrSum x)

xs = filter (\x -> cache ! x == 89) [1..10^7]

ans = length xs
