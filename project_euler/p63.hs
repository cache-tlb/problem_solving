import Data.List

nDigits:: Integer -> Int
nDigits = length . show

ans = length $ nub [y | e <- [1..100], x <- [1..100], let y = e^x, nDigits y == x]