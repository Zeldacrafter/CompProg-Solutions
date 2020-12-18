{
module Parser1 where
import Scanner
import Language
}

%name parse1
%tokentype { Token }
%error { parseError }

%token
    int { TokenInt $$ }
    '+' { TokenPlus }
    '*' { TokenTimes }
    '(' { TokenLParen }
    ')' { TokenRParen }

%left '*' '+'

%%

Exp : Exp '+' Exp            { Plus $1 $3 }
    | Exp '*' Exp            { Times $1 $3 }
    | '(' Exp ')'            { $2 }
    | int                    { Int $1 }

{

parseError :: [Token] -> a
parseError _ = error "Parse error"

}
