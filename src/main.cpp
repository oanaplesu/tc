#include <iostream>
#include <sstream>
#include <stdio.h>

#include "LexicalAnalyzer.h"


int main() {
	std::cout<<"aaaceva"<<"\n";
	const char FILE_PATH[] = "test.txt";
	LexicalAnalyzer analyzer(FILE_PATH);
	Token* token;

	std::cout<<"ceva"<<"\n";

	while(token = analyzer.get_token()) {
		std::cout<< token->get_string(analyzer)<< "\n";
	}


	return 0;
}
