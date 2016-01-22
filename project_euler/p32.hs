import Data.List

xs = [x*y | x <- [1..(100000)], y <- [(x+1)..(div 100000 x)], check x y] where
  check x y = sort ((show x)++(show y)++(show (x*y))) == "123456789"

ans = sum $ nub xs