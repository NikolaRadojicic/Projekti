PROGRAM = optim
CC = g++
CPPFLAGS = -Wall -std=c++11

$(PROGRAM) : parser.tab.o lex.yy.o syntree.o 
	$(CC) $(CPPFLAGS) -o  $@ $^

syntree.o : syntree.cpp syntree.hpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

parser.tab.o : parser.tab.cpp parser.tab.hpp syntree.hpp 
	$(CC) $(CPPFLAGS) -c -o $@ $<

lex.yy.o : lex.yy.c parser.tab.hpp syntree.hpp 
	$(CC) $(CPPFLAGS) -c -o $@ $< 

parser.tab.cpp parser.tab.hpp : parser.ypp
	bison -d -v $<

lex.yy.c : lexer.lex
	flex $<

.PHONY : clean

clean :
	rm -rf optim *.yy.* *.tab.* *.output *.o rezultat.txt
