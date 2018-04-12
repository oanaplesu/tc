#ifndef TRANSITIONS_H_
#define TRANZITIONS_H_

bool is_zero(char c);

bool is_plus(char c);

bool is_minus(char c);

bool is_star(char c);

bool is_slash(char c);

bool is_mod(char c);

bool is_equal(char c);

bool is_less_than(char c);

bool is_greater_than(char c);

bool is_and(char c);

bool is_not(char c);

bool is_or(char c);

bool is_xor(char c);

bool is_point(char c);

bool is_separator(char c);

bool is_operator(char c);

bool is_non_token_separator(char c);

bool is_single_quote(char c);

bool is_double_quote(char c);

bool is_e(char c);

bool is_char(char c);

bool is_digit(char c);

bool is_hexa_char(char c);

bool is_escape(char c);

bool is_new_line(char c);

bool anything(char c);

bool is_letter(char c);

bool is_allowed_first_char_for_id(char c);

bool is_allowed_char_for_id(char c) ;

bool is_not_allowed_char_for_id(char c);

bool is_x(char c);

bool is_l(char c);

bool is_u(char c);

#endif /* TOKEN_H_ */

