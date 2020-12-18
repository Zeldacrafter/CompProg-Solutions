module Language where

data Token = TokenInt Int
           | TokenPlus
           | TokenTimes
           | TokenLParen
           | TokenRParen
           deriving (Eq,Show)

data Exp = Plus Exp Exp
         | Times Exp Exp
         | Brack Exp
         | Int Int
         deriving Show
