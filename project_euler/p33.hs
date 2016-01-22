xs = [ (x,y) | x <- [11..99], y <- [(x+1)..99], check x y] where
  check x y
    | x1*x2*y1*y2 == 0 = False
    | (x1 == y1) && (x2*y == y2*x) = True
    | (x2 == y1) && (x1*y == y2*x) = True
    | (x2 == y2) && (x1*y == y1*x) = True
    | (x1 == y2) && (x2*y == y1*x) = True
    | otherwise = False
    where [x1,y1] = map (\x -> div x 10) [x,y]
          [x2,y2] = map (\x -> mod x 10) [x,y]

elim (x, y) = (div x g, div y g) where g = gcd x y

ans = elim $ foldl (\(ax,ay) (x,y) -> (ax*x, ay*y)) (1,1) xs