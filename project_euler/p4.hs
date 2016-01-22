ans = maximum ([x*y | x <- [100..999], y <- [100..999], legal (x*y)])
  where legal n = (show n) == reverse (show n)