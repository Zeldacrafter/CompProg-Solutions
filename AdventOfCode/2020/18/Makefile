all: Main

Scanner.hs : Scanner.x
	alex Scanner.x

Parser1.hs : Parser1.y
	happy Parser1.y
    
Parser2.hs : Parser2.y
	happy Parser2.y

Main: Scanner.hs Parser1.hs Parser2.hs Main.hs
	ghc -dynamic --make Main
    
clean:
	rm -f Main Scanner.hs Parser1.hs Parser2.hs *.o *.hi
