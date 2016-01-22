list1 = ["","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]
list2 = ["","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"]

say x
  | x <= 19 = list1 !! x
  | x <= 99 = (list2 !! (div x 10)) ++ (say $ mod x 10)
  | x <= 999 = (list1 !! (div x 100)) ++ "hundred" ++ ( if (mod x 100)==0 then "" else (++) "and" $ say $ mod x 100)
  | x == 1000 = "onethousand"
  | otherwise = ""

ans = sum $ map length $ map say [1..1000]