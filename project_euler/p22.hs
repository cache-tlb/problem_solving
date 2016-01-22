import Data.Char
import Data.List

char2Int :: Char -> Int
char2Int x
  | ord x >= ord 'a' && ord x <= ord 'z' = fromIntegral(ord x - ord 'a' + 1)
  | ord x >= ord 'A' && ord x <= ord 'Z' = fromIntegral(ord x - ord 'A' + 1)
  | otherwise = 0

strscore = foldl (\x y -> x + char2Int y) 0

main = do
    raw <- readFile "p22_names.txt"
    let names = read ("[" ++ raw ++ "]") :: [String]
    let snames = sort names
    let t = zip [1..] snames
    let score = sum $ map (\x -> (fst x) * (strscore $ snd x)) t
    putStrLn (show score)
    return ()