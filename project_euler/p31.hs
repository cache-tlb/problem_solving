import Data.Array

coins = listArray (1,8) [1,2,5,10,20,50,100,200]

bound = ((0,0),(200,8))

cache = array bound [(i, f i) | i <- range bound] where
f (0,0) = 1
f (_,0) = 0
f (tar,idx) = sum $ map (\n -> cache ! (tar - n*x , idx - 1)) [0..div tar x] where x = coins ! idx

ans = cache ! (200,8)
