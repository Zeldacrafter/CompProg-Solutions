{
module Scanner (scan) where

import Language
}

%wrapper "basic"

$digit = 0-9
$alpha = [a-zA-Z]

tokens :-

  $white+                       ;
  $digit+                       { \s -> TokenInt (read s) }
  \+                            { \s -> TokenPlus }
  \*                            { \s -> TokenTimes }
  \(                            { \s -> TokenLParen }
  \)                            { \s -> TokenRParen }

{

-- The token type:

scan = alexScanTokens

}
