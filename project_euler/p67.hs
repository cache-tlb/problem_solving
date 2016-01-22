import Data.List.Split
import Data.Array
main = do
  raw <- readFile "p67_triangle.txt"
  let str = init $ splitOneOf " \n" raw
  let numlist = map read str ::[Int]
  let mat = helper [1..100] numlist where
        helper [] list = []
        helper (car:cdr) list = (take car list):(helper cdr $ drop car list)
  let idxs = foldr (\x acc-> zip [x,x..] [0..x] ++ acc) [] [0..99]
  let bounds' = ((-1,-1),(99,99))
  let ans = maximum (elems cache) where
        cache = array bounds' [(idx, f idx) | idx <- range bounds']
        f (i, j) | j < 0 || j > i || i < 0 = 0
                 | otherwise = (mat !! i !! j) + max (f2 (i - 1) (j - 1)) (f2 (i - 1) j)
        f2 i j = cache ! (i, j)
  print ans
  return ()