#include "transitions.h"


bool is_zero(char c) {
	return c == '0';
}

bool is_plus(char c) {
	return c == '+';
}

bool is_minus(char c) {
	return c == '-';
}

bool is_star(char c) {
	return c == '*';
}

bool is_slash(char c) {
	return c == '/';
}

bool is_mod(char c) {
	return c == '%';
}

bool is_equal(char c) {
	return c == '=';
}

bool is_less_than(char c) {
	return c == '<';
}

bool is_greater_than(char c) {
	return c == '>';
}

bool is_and(char c) {
	return c == '&';
}

bool is_not(char c) {
	return c == '!';
}

bool is_or(char c) {
	return c == '|';
}

bool is_xor(char c) {
	return c == '^';
}

bool is_point(char c) {
	return c == '.';
}

bool is_separator(char c) {
	switch(c) {
		case ';':
		case ',':
		case '{':
		case '}':
		case ']':
		case ')':
		case '(':
		case '[':
			return true;
		default :
			return false;
	}
}

bool is_operator(char c) {
	switch(c) {
		case ':':
		case '?':
			return true;
		default :
			return false;
	}
}

bool is_non_token_separator(char c) {
	switch(c) {
		case '\n':
		case '\t':
		case ' ':
			return true;
		default :
			return false;
	}
}

bool is_single_quote(char c) {
	return c == '\'';
}

bool is_double_quote(char c) {
	return c == '\"';
}

bool is_e(char c) {
	return c == 'e';
}

bool is_char(char c) {
	return c >= 32 and c <= 126;
}

bool is_digit(char c) {
	return c >= '0' && c <= '9';
}

bool is_hexa_char(char c) {
	return is_digit(c) || ('a' <= c && c <= 'f');
}

bool is_escape(char c) {
	return c == '\\';
}

bool is_new_line(char c) {
	return c == '\n';
}

bool anything(char c) {
	return true;
}

bool is_letter(char c) {
    return ('a' <= c && c<= 'z') || ('A' <= c  && c <= 'Z');
}

bool is_allowed_first_char_for_id(char c) {
    return is_letter(c) || c == '_';
}

bool is_allowed_char_for_id(char c) {
    return is_allowed_first_char_for_id(c) || is_digit(c);
}

bool is_not_allowed_char_for_id(char c) {
    return !is_allowed_char_for_id(c);
}

bool is_x(char c) {
	return c == 'x';
}

bool is_l(char c) {
	return c == 'l';
}

bool is_u(char c) {
	return c == 'u';
}
