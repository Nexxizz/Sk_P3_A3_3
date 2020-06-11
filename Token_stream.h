#pragma once
#include "Token.h"

class Token_stream
{
public:
	void error(std::string s);
	Token get(); // Token aus std::cin erzeugen
	void putback(const Token& ch);
	double primary(Token_stream& ts);
	double expression(Token_stream& ts);
	double term(Token_stream& ts);
	void help();
private:
	bool full_; // Ist ein Token im Puffer?
	Token buffer_; // Trick: Platz, um ein Token zu puffern 
};

