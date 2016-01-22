 quitely ok
import Data.List
main = print $ maximumBy (\a b -> compare (snd a) (snd b)) collatzip

collatzip = zip [10..1000000] (map length $ map collatz_chain [10..1000000])

collatz_chain :: Integer -> [Integer]
collatz_chain 1 = [1]
collatz_chain n | even n = n : (collatz_chain $ div n 2)
                | otherwise = n : (collatz_chain $ 3 * n + 1)


-- run out of memory
--import Data.Foldable

--collatz :: Int -> (Int,Int)
--collatz orig = collatz' orig 1
--  where collatz' n l | n == 1    = (l,orig)
--                     | even n    = collatz' (n`div`2) (l+1)
--                     | otherwise = collatz' (3*n+1) (l+1)

--main = print . snd . foldl' (flip $ max . collatz) (1,1) $ [2..999999]