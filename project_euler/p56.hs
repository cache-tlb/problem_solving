import Data.Char

digits n = map (\x -> ord x - 48) $ show n

xs = [a^b | a <- [1..100], b <- [1..100]]

ans = maximum $ map (sum . digits) xs