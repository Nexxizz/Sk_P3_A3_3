#include "Token_stream.h"

void Token_stream::error(std::string s) {
	throw std::runtime_error(s);
}

void Token_stream::putback(const Token& ch) {
	if (full_) error("Token buffer is already full");
	buffer_ = ch; 
	full_ = true;
}

Token Token_stream::get() {
	if (full_) { full_ = false; return buffer_; }
	char ch{ }; 
	cin >> ch;
	switch (ch) {
	case ';': // Ende eines Rechenausdrucks 
	case 'q': // Programmende 
	case '(': case ')': case '*': case '/': case '?': case '+':	case '-':
		return Token{ ch }; // jedes Zeichen ist sein eigenes Token
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9': // Zahl als Token
	{
		cin.putback(ch); // std::cin hat auch einen Puffer
		double val{ }; 
		cin >> val;
		return Token{ val };
	}
	default: error("Token invalid");
	}
}

double Token_stream::primary(Token_stream& ts)
{
	Token t3{ ts.get() };
	switch (t3.getKind())
	{
	case '9': return t3.getValue();
	case '-': return -primary(ts);
	case '+': return +primary(ts);
	case '(': {
		double d3{ expression(ts) };
		if (ts.get().getKind() != ')') error("keine rechte Klammer");
		return d3;
	}
	default: error("kein Primary");
	}
}

double Token_stream::expression(Token_stream& ts)  // "plus" und "minus" behandeln 
{
	double d1{ term(ts) };
	Token t1{};
	while (true)
	{
		t1 = ts.get();
		switch (t1.getKind())
		{
		case '+': d1 += term(ts);
			break;
		case '-': d1 -= term(ts);
			break;
		default: ts.putback(t1);
			return d1;
		}
	}
}


double Token_stream::term(Token_stream& ts) // "mal" und "geteilt durch" behandeln
{
	double d2{ primary(ts) };
	Token t2{};
	while (true)
	{
		t2 = ts.get();
		switch (t2.getKind())
		{
		case '*': d2 *= primary(ts);
			break;
		case '/': {
			double divisor{ primary(ts) };
			if (divisor == 0) error("Division durch 0");
			d2 /= divisor;
			break;
		}
		default: ts.putback(t2);
			return d2;
		}
	}
}


void Token_stream::help()
{
	cout << "Bitte geben Sie einen Ausdruck in Form von z.B.: ((8+7) * 2)/3 ein und q zum abbrechen: " << endl;
}
