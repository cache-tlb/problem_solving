import Data.List.Split
import Data.Array
main = do
  raw <- readFile "p81_matrix.txt"
  let str = init $ splitOneOf ",\n" raw
  let numlist = map read str ::[Int]
  let n = 80
  let mat = chunksOf n numlist
  let maxVal = maximum numlist
  let bounds' = ((-1,-1),(n,n))
  let ans = cache ! (n-1, n-1) where
        cache = array bounds' [(idx, f idx) | idx <- range bounds']
        f (0, 0) = mat !! 0 !! 0
        f (i, j) | j < 0 || i < 0 = maxVal*n
                 | otherwise = min (cache ! (i - 1, j)) (cache ! (i, j - 1)) + (mat !! i !! j)
  print ans
  return ()