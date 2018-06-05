%option noyywrap
%option nounput
%option noinput

%{
	#include "syntree.hpp"
	#include<iostream>
	#include<cstdlib>
	#include<string>
	#include<cstdio>
	using namespace std;

	#include "parser.tab.hpp"


%}



%%

[a-zA-Z_][a-zA-Z_0-9]*		{ yylval.s = new string(yytext); return id_token; }
[0-9]+								{ yylval.i = atoi(yytext); return num_token; }
[<][<]			return left_shift_token;
[>][>] 			return right_shift_token;
[-+*/;=]		return *yytext;
[ \t\n]		{ }

.	{
		cerr << "Greska,nepoznat karakter: " << *yytext << endl;
		exit(EXIT_FAILURE);
}

%%
