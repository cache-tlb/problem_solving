import Data.Char
import Data.Array
n = 10^6
digits n = map (\x -> ord x - 48) $ show n

table = array (0,9) [(i, f i) | i <- [0..9]]
  where f 0 = 1
        f i = product [1..i]

xs = [10..n]

ans = sum $ filter (\x -> (==) x $ sum $ map (table !) $ digits x) xs
