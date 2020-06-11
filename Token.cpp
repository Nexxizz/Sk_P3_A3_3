#include "Token.h"

Token::Token(const char& ch) : kind_{ ch }, value_{ 0.0 }
{}
Token::Token(const double& d) : kind_{ '9' }, value_{ d }
{}
Token::Token() : Token{ 0.0 }
{}

char Token::getKind()
{
	return kind_;
}

void Token::setKind(char kind)
{
	kind_ = kind;
}

double Token::getValue()
{
	return value_;
}

void Token::setValue(double value)
{
	value_ = value;
}

void Token::print() const {
	if (kind_ == '9')
		cout << value_;
	else cout << kind_;
}

void Token::error(std::string s) {
	throw std::runtime_error(s);
}