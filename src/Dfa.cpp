#include <stdio.h>

#include "Dfa.h"
#include "transitions.h"


Dfa::Dfa(const char *file_name) {
	transitions_list list_initial;
	list_initial.push_back(std::make_pair<>(is_zero, ZERO));
	list_initial.push_back(std::make_pair<>(is_plus, PLUS));
	list_initial.push_back(std::make_pair<>(is_minus, MINUS));
	list_initial.push_back(std::make_pair<>(is_slash, SLASH));
	list_initial.push_back(std::make_pair<>(is_mod, MOD));
	list_initial.push_back(std::make_pair<>(is_equal, EQUAL));
	list_initial.push_back(std::make_pair<>(is_less_than, LESS_THAN));
	list_initial.push_back(std::make_pair<>(is_greater_than, GREATER_THAN));
	list_initial.push_back(std::make_pair<>(is_and, AND));
	list_initial.push_back(std::make_pair<>(is_not, NOT));
	list_initial.push_back(std::make_pair<>(is_or, OR));
	list_initial.push_back(std::make_pair<>(is_xor, XOR));
	list_initial.push_back(std::make_pair<>(is_point, POINT));
	list_initial.push_back(std::make_pair<>(is_separator, SEPARATOR));
	list_initial.push_back(std::make_pair<>(is_operator, OPERATOR));
	list_initial.push_back(std::make_pair<>(is_non_token_separator, NON_TOKEN_SEPARATOR));
	list_initial.push_back(std::make_pair<>(is_allowed_first_char_for_id, IDENTIFIER));
	list_initial.push_back(std::make_pair<>(is_digit, NUMBER));
	list_initial.push_back(std::make_pair<>(is_single_quote, CHAR));
	list_initial.push_back(std::make_pair<>(is_double_quote, STRING));
	list_initial.push_back(std::make_pair<>(anything, ERROR));
	this->transitions[INITIAL] = list_initial;

	transitions_list list_identifier;
	list_identifier.push_back(std::make_pair<>(is_allowed_char_for_id, IDENTIFIER));
	list_identifier.push_back(std::make_pair<>(is_not_allowed_char_for_id, END));
	this->transitions[IDENTIFIER] = list_identifier;

	transitions_list list_plus;
	list_plus.push_back(std::make_pair<>(is_plus, OPERATOR));
	list_plus.push_back(std::make_pair<>(is_equal, OPERATOR));
	list_plus.push_back(std::make_pair<>(anything, END));
	this->transitions[PLUS] = list_plus;

	transitions_list list_minus;
	list_minus.push_back(std::make_pair<>(is_minus, OPERATOR));
	list_minus.push_back(std::make_pair<>(is_greater_than, OPERATOR));
	list_minus.push_back(std::make_pair<>(is_equal, OPERATOR));
	list_minus.push_back(std::make_pair<>(is_digit, NUMBER));
	list_minus.push_back(std::make_pair<>(anything, END));
	this->transitions[MINUS] = list_minus;

	transitions_list list_star;
	list_star.push_back(std::make_pair<>(is_equal, OPERATOR));
	list_star.push_back(std::make_pair<>(anything, END));
	this->transitions[STAR] = list_star;

	transitions_list list_slash;
	list_slash.push_back(std::make_pair<>(is_equal, OPERATOR));
	list_slash.push_back(std::make_pair<>(is_slash, SINGLE_LINE_COMMENT));
	list_slash.push_back(std::make_pair<>(is_star, MULTI_LINE_COMMENT));
	list_slash.push_back(std::make_pair<>(anything, END));
	this->transitions[SLASH] = list_slash;

	transitions_list list_mod;
	list_mod.push_back(std::make_pair<>(is_equal, OPERATOR));
	list_mod.push_back(std::make_pair<>(anything, END));
	this->transitions[MOD] = list_mod;

	transitions_list list_equal;
	list_equal.push_back(std::make_pair<>(is_equal, OPERATOR));
	list_equal.push_back(std::make_pair<>(anything, END));
	this->transitions[EQUAL] = list_equal;

	transitions_list list_less_than;
	list_less_than.push_back(std::make_pair<>(is_equal, OPERATOR));
	list_less_than.push_back(std::make_pair<>(is_less_than, SHIFT_LEFT));
	list_less_than.push_back(std::make_pair<>(anything, END));
	this->transitions[LESS_THAN] = list_less_than;

	transitions_list list_greater_than;
	list_greater_than.push_back(std::make_pair<>(is_equal, OPERATOR));
	list_greater_than.push_back(std::make_pair<>(is_greater_than, SHIFT_RIGHT));
	list_greater_than.push_back(std::make_pair<>(anything, END));
	this->transitions[GREATER_THAN] = list_greater_than;

	transitions_list list_shift_left;
	list_shift_left.push_back(std::make_pair<>(is_equal, OPERATOR));
	list_shift_left.push_back(std::make_pair<>(anything, END));
	this->transitions[SHIFT_LEFT] = list_shift_left;

	transitions_list list_shift_right;
	list_shift_right.push_back(std::make_pair<>(is_equal, OPERATOR));
	list_shift_right.push_back(std::make_pair<>(anything, END));
	this->transitions[SHIFT_RIGHT] = list_shift_right;

	transitions_list list_and;
	list_and.push_back(std::make_pair<>(is_and, OPERATOR));
	list_and.push_back(std::make_pair<>(is_equal, OPERATOR));
	list_and.push_back(std::make_pair<>(anything, END));
	this->transitions[AND] = list_and;

	transitions_list list_or;
	list_or.push_back(std::make_pair<>(is_or, OPERATOR));
	list_or.push_back(std::make_pair<>(is_equal, OPERATOR));
	list_or.push_back(std::make_pair<>(anything, END));
	this->transitions[OR] = list_or;

	transitions_list list_not;
	list_not.push_back(std::make_pair<>(is_equal, OPERATOR));
	list_not.push_back(std::make_pair<>(anything, END));
	this->transitions[NOT] = list_not;

	transitions_list list_xor;
	list_xor.push_back(std::make_pair<>(is_equal, OPERATOR));
	list_xor.push_back(std::make_pair<>(anything, END));
	this->transitions[XOR] = list_xor;

	transitions_list list_point;
	list_point.push_back(std::make_pair<>(is_digit, FLOAT_NUMBER));
	list_point.push_back(std::make_pair<>(is_allowed_char_for_id, END));
	list_point.push_back(std::make_pair<>(anything, ERROR));
	this->transitions[POINT] = list_point;

	transitions_list list_sep;
	list_sep.push_back(std::make_pair<>(anything, END));
	this->transitions[SEPARATOR] = list_sep;

	transitions_list list_non_token_sep;
	list_non_token_sep.push_back(std::make_pair<>(is_non_token_separator, NON_TOKEN_SEPARATOR));
	list_non_token_sep.push_back(std::make_pair<>(anything, END));
	this->transitions[NON_TOKEN_SEPARATOR] = list_non_token_sep;

	transitions_list list_char;
	list_char.push_back(std::make_pair<>(is_escape, CHAR_ESCAPE));
	list_char.push_back(std::make_pair<>(is_char, CHAR_CHARACTER));
	list_char.push_back(std::make_pair<>(anything, ERROR));
	this->transitions[CHAR] = list_char;

	transitions_list list_char_character;
	list_char_character.push_back(std::make_pair<>(is_single_quote, CHAR_END));
	list_char_character.push_back(std::make_pair<>(anything, ERROR));
	this->transitions[CHAR_CHARACTER] = list_char_character;

	transitions_list list_char_escape;
	list_char_escape.push_back(std::make_pair<>(is_digit, CHAR_ESCAPE_NUMBER));
	list_char_escape.push_back(std::make_pair<>(is_char, CHAR_CHARACTER));
	list_char_escape.push_back(std::make_pair<>(is_x, CHAR_ESCAPE_X));
	list_char_escape.push_back(std::make_pair<>(is_char, CHAR_CHARACTER));
	list_char_escape.push_back(std::make_pair<>(anything, ERROR));
	this->transitions[CHAR_ESCAPE] = list_char_escape;

	transitions_list list_char_escape_number;
	list_char_escape_number.push_back(std::make_pair<>(is_digit, CHAR_ESCAPE_NUMBER));
	list_char_escape_number.push_back(std::make_pair<>(is_single_quote, CHAR_END));
	list_char_escape_number.push_back(std::make_pair<>(anything, ERROR));
	this->transitions[CHAR_ESCAPE_NUMBER] = list_char_escape_number;

	transitions_list list_char_escape_x;
	list_char_escape_x.push_back(std::make_pair<>(is_hexa_char, CHAR_ESCAPE_HEX1));
	list_char_escape_x.push_back(std::make_pair<>(anything, ERROR));
	this->transitions[CHAR_ESCAPE_X] = list_char_escape_x;

	transitions_list list_char_end;
	list_char_end.push_back(std::make_pair<>(anything, END));
	this->transitions[CHAR_END] = list_char_end;

	transitions_list list_string;
	list_string.push_back(std::make_pair<>(is_double_quote, STRING_END));
	list_string.push_back(std::make_pair<>(is_escape, STRING_ESCAPE));
	list_string.push_back(std::make_pair<>(is_char, STRING));
	list_string.push_back(std::make_pair<>(anything, ERROR));
	this->transitions[STRING] = list_string;

	transitions_list list_string_escape;
	list_string_escape.push_back(std::make_pair<>(is_char, STRING));
	list_string_escape.push_back(std::make_pair<>(is_new_line, STRING));
	list_string_escape.push_back(std::make_pair<>(anything, ERROR));
	this->transitions[STRING_ESCAPE] = list_string_escape;

	transitions_list list_string_end;
	list_string_end.push_back(std::make_pair<>(anything, END));
	this->transitions[STRING_END] = list_string_end;

	transitions_list list_number;
	list_number.push_back(std::make_pair<>(is_digit, NUMBER));
	list_number.push_back(std::make_pair<>(is_point, FLOAT_NUMBER));
	list_number.push_back(std::make_pair<>(is_l, NUMBER_L));
	list_number.push_back(std::make_pair<>(is_u, NUMBER_U));
	list_number.push_back(std::make_pair<>(is_e, EXPONENT));
	list_number.push_back(std::make_pair<>(anything, END));
	this->transitions[NUMBER] = list_number;

	transitions_list list_number_l;
	list_number_l.push_back(std::make_pair<>(is_u, NUMBER_UL));
	list_number_l.push_back(std::make_pair<>(anything, END));
	this->transitions[NUMBER_L] = list_number_l;

	transitions_list list_number_u;
	list_number_u.push_back(std::make_pair<>(is_l, NUMBER_UL));
	list_number_u.push_back(std::make_pair<>(anything, END));
	this->transitions[NUMBER_U] = list_number_u;

	transitions_list list_number_ul;
	list_number_ul.push_back(std::make_pair<>(anything, END));
	this->transitions[NUMBER_UL] = list_number_ul;

	transitions_list list_float_number;
	list_float_number.push_back(std::make_pair<>(is_digit, FLOAT_NUMBER));
	list_float_number.push_back(std::make_pair<>(is_l, FLOAT_NUMBER_L));
	list_float_number.push_back(std::make_pair<>(is_e, EXPONENT));
	list_float_number.push_back(std::make_pair<>(anything, END));
	this->transitions[FLOAT_NUMBER] = list_float_number;

	transitions_list list_exponent;
	list_exponent.push_back(std::make_pair<>(is_minus, EXPONENT_VALUE));
	list_exponent.push_back(std::make_pair<>(is_plus, EXPONENT_VALUE));
	list_exponent.push_back(std::make_pair<>(is_digit, EXPONENT_VALUE));
	list_exponent.push_back(std::make_pair<>(anything, ERROR));
	this->transitions[EXPONENT] = list_exponent;

	transitions_list list_float_number_l;
	list_float_number_l.push_back(std::make_pair<>(anything, END));
	this->transitions[FLOAT_NUMBER_L] = list_exponent;

	transitions_list list_zero;
	list_zero.push_back(std::make_pair<>(is_x, HEXA));
	list_zero.push_back(std::make_pair<>(is_digit, NUMBER));
	list_zero.push_back(std::make_pair<>(anything, END));
	this->transitions[ZERO] = list_zero;

	transitions_list list_hexa;
	list_hexa.push_back(std::make_pair<>(is_hexa_char, HEXA));
	list_hexa.push_back(std::make_pair<>(anything, END));
	this->transitions[HEXA] = list_hexa;

	transitions_list list_comment;
	list_comment.push_back(std::make_pair<>(is_slash, SINGLE_LINE_COMMENT));
	list_comment.push_back(std::make_pair<>(is_star, MULTI_LINE_COMMENT));
	list_comment.push_back(std::make_pair<>(anything, ERROR));
	this->transitions[COMMENT] = list_comment;

	transitions_list list_multi_line_comment;
	list_multi_line_comment.push_back(std::make_pair<>(is_star, MULTI_LINE_COMMENT_STAR));
	list_multi_line_comment.push_back(std::make_pair<>(anything, MULTI_LINE_COMMENT));
	this->transitions[MULTI_LINE_COMMENT] = list_multi_line_comment;

	transitions_list list_multi_line_comment_star;
	list_multi_line_comment_star.push_back(std::make_pair<>(is_slash, MULTI_LINE_COMMENT_END));
	list_multi_line_comment_star.push_back(std::make_pair<>(is_star, MULTI_LINE_COMMENT_STAR));
	list_multi_line_comment_star.push_back(std::make_pair<>(anything, MULTI_LINE_COMMENT));
	this->transitions[MULTI_LINE_COMMENT_STAR] = list_multi_line_comment_star;

	transitions_list list_multi_line_comment_end;
	list_multi_line_comment_end.push_back(std::make_pair<>(anything, END));
	this->transitions[MULTI_LINE_COMMENT_END] = list_multi_line_comment_end;

	transitions_list list_single_line_comment;
	list_single_line_comment.push_back(std::make_pair<>(is_new_line, END));
	list_single_line_comment.push_back(std::make_pair<>(anything, SINGLE_LINE_COMMENT));
	this->transitions[SINGLE_LINE_COMMENT] = list_single_line_comment;

	transitions_list list_operator;
	list_operator.push_back(std::make_pair<>(anything, END));
	this->transitions[OPERATOR] = list_operator;

	this->fp = fopen(file_name, "r");
	this->file_position = 0;
}

Dfa::~Dfa()
{
	fclose(fp);
}

std::pair<Dfa::STATE, std::string> Dfa::execute()
{
	std::string token_value;
	char c;
	STATE current_state = INITIAL;

	fseek(fp, this->file_position, SEEK_SET);

	while ((c = fgetc(fp)) != EOF) {
		this->file_position++;

		auto state_transitions = transitions[current_state];

		for(auto transition : state_transitions) {
			auto transition_function = transition.first;
			auto next_state = transition.second;

			if(transition_function(c)) {
				if(next_state == ERROR){
					return std::make_pair<>(ERROR, token_value);
				}

				if(next_state == END) {
					this->file_position--;

					return std::make_pair<>(current_state, token_value);
				}

				current_state = next_state;
				token_value += c;
				break;
			}
		}
	}

	//reached the end of file
	auto state_transitions = transitions[current_state];
	for(auto transition : state_transitions) {
		auto next_state = transition.second;

		if(next_state == END) {
			return std::make_pair<>(current_state, token_value);
		}
	}

	return std::make_pair<>(ERROR, token_value);
}

bool Dfa::is_EOF()
{
	return !fp || feof(fp);
}

int Dfa::get_file_position()
{
	return this->file_position;
}
