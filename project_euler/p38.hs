--tri = scanl1 (+) [1..9]

--ys = zip [2..9] $ tail tri
import Data.List
xs = [s | x <- [1..9999], y <- [2..9],let s = str x y, sort s == "123456789"] where
  str x y = foldl1 (++) (map show $ map (*x) [1..y])

ans = maximum xs