#include "LexicalAnalyzer.h"
#include "Token.h"

#include <string>


Token::Token(int type, int value)
{
	this->type = type;
	this->value = value;
}

std::string get_token_type_str(int token_type)
{
	switch(token_type) {
	case LexicalAnalyzer::IDENTIFIER:
		return "IDENTIFIER";
	case LexicalAnalyzer::KEYWORD:
		return "KEYWORD";
	case LexicalAnalyzer::STRING:
		return "STRING";
	case LexicalAnalyzer::CHAR:
		return "CHAR";
	case LexicalAnalyzer::INTEGER:
		return "INTEGER";
	case LexicalAnalyzer::FLOAT:
		return "FLOAT";
	case LexicalAnalyzer::HEXADECIMAL:
		return "HEXADECIMAL";
	case LexicalAnalyzer::COMMENT:
		return "COMMENT";
	case LexicalAnalyzer::WHITESPACE:
		return "WHITESPACE";
	case LexicalAnalyzer::OPERATOR:
		return "OPERATOR";
	case LexicalAnalyzer::SEPARATOR:
		return "SEPARATOR";
	case LexicalAnalyzer::ERROR:
		return "ERROR";
	case LexicalAnalyzer::INVALID_TOKEN:
	default:
		return "INVALID_TOKEN";
	}
}

std::string Token::get_string(const LexicalAnalyzer& lexical_analyzer) {
	return get_token_type_str(this->type) + " - "
			+ lexical_analyzer.get_value_from_strings_list(this->value);
}
