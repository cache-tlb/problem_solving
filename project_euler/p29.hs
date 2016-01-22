import Data.List

xs = [a^b | a <- [2..100], b <- [2..100]]

ans = length $ nub xs