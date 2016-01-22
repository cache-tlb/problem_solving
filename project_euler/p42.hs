import Data.Char

char2Int :: Char -> Int
char2Int x
  | ord x >= ord 'A' && ord x <= ord 'Z' = ord x - ord 'A' + 1
  | ord x >= ord 'a' && ord x <= ord 'z' = ord x - ord 'a' + 1
  | otherwise = 0

str2Int = foldl (\acc x -> acc + (char2Int x)) 0

isTriangle x = n*(n+1)==2*x where n = round $ (sqrt $ fromIntegral (8*x+1) - 1.0)/2.0

main = do
  raw <- readFile "p42_words.txt"
  let strs = read ("["++raw++"]") :: [String]
  let xs = map str2Int strs
  print $ length $ filter isTriangle xs
  return ()