#include <iostream>
#include "Token.h"
#include "Token_stream.h"

using std::cout;
using std::endl;
using std::cerr;

int main() try {
	Token tok{};
	Token_stream ts{}; // Standardkonstruktor?!
	while (cin)
	{
		cout << "> "; // Prompt
		tok = ts.get();
		if (tok.getKind() == '?') { ts.help(); continue; };
		if (tok.getKind() == ';') continue;
		if (tok.getKind() == 'q') break;
		ts.putback(tok);
		cout << "= " << ts.expression(ts) << endl;
	}
	return 0;
}
catch (std::exception& e) {
	cerr << "Ausnahme: " << e.what() << endl;
	return -2;
}
catch (...) {
	cerr << "Unbekannte Ausnahme" << endl;
	return -1;
}