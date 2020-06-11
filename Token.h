#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Token
{
public:
	Token(const char& ch);
	Token(const double& d);
	Token();
	char getKind();
	void setKind(char kind);
	double getValue();
	void setValue(double value);
	void print() const;
	void error(std::string s);
private:
	char kind_; // Die Tokensymbole
	double value_; // Bei Zahlen: der Wert
};

