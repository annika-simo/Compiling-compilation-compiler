#include <cassert>
#include <ios>
#include <iostream>

/*
 * is_vowel
 *
 * returns true when its argument is a vowel and false otherwise
 *
 * input: char
 * output: bool
 */

bool is_vowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}
	else {
		return false;
	}
}

/*
 * is_consonant
 *
 * returns true when its argument is a consonant and false otherwise
 *
 * input: char
 * output: bool
 */

bool is_consonant(char c) {
	if (c == 'b' || c == 'c' || c == 'd' || c == 'f' || c == 'g' || c == 'h' || c == 'j' ||
		c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'p' || c == 'q' || c == 'r' ||
		c == 's' || c == 't' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z') {
		return true;
	}
	else {
		return false;
	}
}

/*
 * ends_with
 *
 * returns true if candidate is an empty string and suffix is an empty string or if 
 * candidate ends with suffix and returns false if candidate is an empty string and 
 * suffix is not an empty string. Otherwise, it returns false.
 *
 * input: two strings (candidate, suffix)
 * output: bool
 */

bool ends_with(std::string candidate, std::string suffix) {
	if (candidate == "" && suffix == "") {
		return true;
	}
	else if (suffix == "" && candidate != "") {
		return true;
	}
	else if (candidate == "") {
		return false;
	}
	else {
		int len = 0;
		if (suffix.length() < candidate.length()) {
			len = suffix.length();
		}
		else {
			return false;
		}
		for (int i = len - 1; i > 0; i--) {
			if (suffix.at(suffix.length() - i) != candidate.at(candidate.length() - i)) {
				return false;
			}
			return true;
		}
	}
}

/*
 * ends_with_double_consonant
 *
 * returns true if the last two characters in the argument are the 
 * same consonant and false otherwise
 *
 * input: string
 * output: bool
 */

bool ends_with_double_consonant(std::string str) {
	if (str.length() < 2) {
		return false;
	}

	if ((is_consonant((str.at(str.length() - 1)))) && (str.at(str.length() - 1)) == (str.at(str.length() - 2))) {
		return true;
	}
	else {
		return false;
	}
}

/*
 * ends_with_cvc
 *
 * returns true if the last three characters in the argument are a consonant,
 * a vowel, then a consonant and false otherwise
 *
 * input: string
 * output: bool
 */

bool ends_with_cvc(std::string str) {
	if (str.length() < 3) {
		return false;
	}
	if (is_consonant((str.at(str.length() - 1))) && is_vowel((str.at(str.length() - 2))) && is_consonant((str.at(str.length() - 3)))) {
		return true;
	}
	else {
		return false;
	}
}

/*
 * count_consonants_at_front
 *
 * returns the number of consecutive consonants at the beginning of the argument
 *
 * input: string
 * output: int
 */

int count_consonants_at_front(std::string str) {
	int n;

	n = 0;
	if (str.length() == 0) {
		return 0;
	}

	while (n < str.length() && is_consonant(str.at(n))) {
		n += 1;
	}

	return n;
}

/*
 * count_vowels_at_back
 *
 * returns the number of consecutive vowel at the end of the argument
 *
 * input: string
 * output: int
 */

int count_vowels_at_back(std::string str) {
	int n;

	n = 0;

	while (n < str.length() && is_vowel(str.at(str.length()-(n+1)))) {
		n += 1;
	}

	return n;
}

/*
 * contains_vowel
 *
 * returns true if there is atleast one vowel anywhere in the argument and
 * false otherewise
 *
 * input: string
 * output: bool
 */

bool contains_vowel(std::string str) {
	int i;

	if (str == "") {
		return false;
	}

	for (i = 0; i < str.length(); ++i) {
		if (is_vowel(str.at(i))) {
			return true;
		}
	}
	return false;
}

/*
 * new_ending
 *
 * creates a new string from candidate by removing its last suffix length 
 * characters and replacing them with replacement. new_ending returns that 
 * new string.
 *
 * input: three strings (candidate, suffixLength, suffix)
 * output: string
 */

std::string new_ending(std::string candidate, int suffixLength, std::string replacement) {
	int len = candidate.length();
	return candidate.replace(len-suffixLength, suffixLength,replacement);
}
