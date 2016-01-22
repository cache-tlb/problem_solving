import Data.List

ans = head $ filter check [1..]

check x
    | digits x /= digits (2*x) = False
    | digits x /= digits (3*x) = False
    | digits x /= digits (4*x) = False
    | digits x /= digits (5*x) = False
    | digits x /= digits (6*x) = False
    | otherwise = True
    where digits x = sort $ show x