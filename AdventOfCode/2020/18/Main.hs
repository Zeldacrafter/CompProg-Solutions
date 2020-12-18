module Main where

import Language
import Scanner
import Parser1
import Parser2

import Data.List.Split

eval :: Exp -> Int
eval (Int   v)     = v
eval (Plus  e1 e2) = (eval e1) + (eval e2)
eval (Times e1 e2) = (eval e1) * (eval e2)
    
getRes1 :: String -> Int
getRes1  = eval . parse1 . scan

getRes2 :: String -> Int
getRes2  = eval . parse2 . scan

main = do
    allInp <- getContents
    let input = filter (/= "") $ splitOn "\n" allInp
    print . sum $ getRes1 <$> input
    print . sum $ getRes2 <$> input
