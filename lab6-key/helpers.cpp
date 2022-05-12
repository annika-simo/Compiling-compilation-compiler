#include <cassert>
#include <ios>
#include <iostream>

/*
 * new_ending
 *
 * new_ending will create a new string whose contents are the
 * same as _candidate_ except that the last _suffix_length_
 * characters are replaced with the contents of _replacement_.
 *
 * input: candidate: The string of which to modify the ending.
 *        suffix_length: The number of characters to remove from _candidate_.
 *        replacement: The string with which to replace the
 *        last _suffix_length_ characters of _candidate_.
 * output: _candidate_ with the last _suffix_length_ characters
 *         replaced with the contents of _replacement_.
 */
std::string new_ending(std::string candidate, int suffix_length,
                       std::string replacement) {
  // Use substr magic and the ability to use "+" to append
  // two strings together! We are doing some shorthand here.
  // We could easily have written this as:
  //
  // auto result = 
  //      candidate.substr(0, candidate.length() - suffix_length);
  // result.append(replacement);
  // return result;
  //
  // The substr function *does not* change the original string. The
  // append function *does* change the original string! In this case
  // that will not make a difference because our parameters are
  // pass by value. But, if our parameters were pass by reference
  // that could make a big difference.
  return candidate.substr(0, candidate.length() - suffix_length) + replacement;
}

/*
 * ends_with
 *
 * ends_with determine whether _candidate_ ends with _suffix_.
 *
 * input: candidate: The string for which to check the ending.
 *        suffix: The string to test against the ending of _candidate_.
 * output: true if _candidate_ ends with _suffix_; false, otherwise.
 */
bool ends_with(std::string candidate, std::string suffix) {
  // Check the edge cases first.
  if (candidate.length() < suffix.length()) {
    return false;
  }

  // If we are here, we are guaranteed to have a candidate
  // that is longer than a suffix. That means we can validly
  // check up to suffix.length() characters at the back of
  // _candidate_ without worrying about an out of bounds index.
  // We are even protected against the case where _suffix_'s
  // length is 0.
  // Cool!
  //
  // Our algorithm is simply to walk backwards (in parallel)
  // across each of the two strings and see if/where they
  // differ. As soon as they do, return false. Otherwise ...
  for (int i = 0; i < suffix.length(); i++) {
    if (suffix.at(suffix.length() - 1 - i) !=
        candidate.at(candidate.length() - 1 - i)) {
      return false;
    }
  }

  // there are no mismatches, so we can return true!
  return true;
}

/*
 * is_vowel
 *
 * Determine whether _c_ is a vowel. Note: 'y' is *not* a vowel.
 *
 * input: c: The character to check for "vowelness".
 * output: true, if _c_ is a vowel; false, otherwise.
 */
bool is_vowel(char c) {
  char lower_c = std::tolower(c);
  return (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' ||
          lower_c == 'o' || lower_c == 'u');
}

/*
 * is_vowel
 *
 * Determine whether _c_ is a consonant. Note: 'y' is a consonant.
 *
 * input: c: The character to check for "consonantness".
 * output: true, if _c_ is a consonant; false, otherwise.
 */
bool is_consonant(char c) { return !is_vowel(c); }

/*
 * ends_with_double_consonant
 *
 * Determine whether _str_ ends with the same two letters
 * and those letters are both consonants. If _str_ has fewer
 * than two letters, the result is false.
 *
 * input: _str_: The string to check for a double-consontant ending.
 * output: true, if the string ends in the same two letters *and*
 *         those letters are both consontants; false, otherwise.
 *         false, if the string is shorter than 2 characters long.
 */
bool ends_with_double_consonant(std::string str) {
  // First, check for the edge case.
  if (str.length() < 2) {
    return false;
  }

  // If we are here, we know that we can safely perform
  // the required "negative" indexes needed to determine
  // whether _str_ ends with a double_consonant. Notice
  // how we are using the value of the expression *directly*
  // as a return value. We could have created a variable,
  // stored the value of the expression there, and then
  // returned it. But, this is simpler.
  return is_consonant(str.at(str.length() - 1)) &&
         str.at(str.length() - 1) == str.at(str.length() - 2);
}

/*
 * count_consonants_at_front
 *
 * Count the number of consecutive consonants at the
 * start of _str_.
 *
 * input: str: The string from which to count the number of
 *        consecutive consonants at the front.
 * output: the number of consecutive consonants at
 *         the front of _str_. Note: Uses is_consonant to
 *         determine whether a character is a consonant.
 */
int count_consonants_at_front(std::string str) {
  int count = 0;
  // See documentation of count_vowels_at_back (below)
  // for a description of the rationale of the condition
  // statement here.
  while (count < str.length() && is_consonant(str.at(count))) {
    count++;
  }
  return count;
}

/*
 * count_vowels_at_back
 *
 * Count the number of consecutive vowels at the
 * end of _str_.
 *
 * input: str: The string from which to count the number of
 *        consecutive vowels at the end.
 * output: the number of consecutive consonants at
 *         the end of _str_. Note: Uses is_vowel to
 *         determine whether a character is a consonant.
 */
int count_vowels_at_back(std::string str) {
  int count = 0;
  // Walk backwards through the string and count
  // the vowels. The implementation here is tricky
  // and uses short-circuit evaluation.
  //
  // There are two parts to the condition
  // 1. Whether there are characters in _str_ left to inspect
  // 2. Whether that next character to inspect is a vowel.
  //
  // Because we are using short-circuit evaluation, if condition
  // (1) fails, then we will never attempt to check condition (2).
  // This protection keeps our index from going out of bounds.
  // Because we are using an &&, the first time that we see a
  // consontant before completely searching the entire string,
  // we will halt the loop! Nifty!
  int adjusted_str_length = str.length() - 1;
  while ((adjusted_str_length - count >= 0) &&
         is_vowel(str.at(adjusted_str_length - count))) {
    count++;
  }
  return count;
}

/*
 * ends_with_cvc
 *
 * Determine whether _str_ ends with the combination of
 * a consonant, a vowel and a consonant. If _str_ is shorter
 * than three characters, the function returns false.
 *
 * input: str: The string to test for a consonant, vowel,
 *        consonant ending.
 * output: true, if _str_ ends in a combination of a consonant,
 *         vowel and consonant. false, otherwise. If _str_ is
 *         shorter than three characters, ends_with_cvc will return
 *         false.
 */
bool ends_with_cvc(std::string str) {
  // Check for the edge case.
  if (str.length() < 3) {
    return false;
  }

  // If we are here, we are guaranteed that _str_
  // has enough characters to perform the required
  // "negative" indexes safely.
  return is_consonant(str.at(str.length() - 1)) &&
         is_vowel(str.at(str.length() - 2)) &&
         is_consonant(str.at(str.length() - 3));
}

/*
 * contains_vowel
 *
 * Determine whether _str_ contains a vowel. Note, this function
 * uses is_vowel to determine whether a character is a vowel.
 *
 * input: str: The string to test for containing a vowel.
 * output: true, if _str_ contains a vowel; false, otherwise. Note:
 *         this function uses is_vowel to determine whether a
 *         character is a vowel.
 */
bool contains_vowel(std::string str) {
  for (int i = 0; i < str.length(); i++) {
    // The first time that we see a vowel, return true.
    if (is_vowel(str.at(i))) {
      return true;
    }
  }
  // If we are here we know that we never saw a vowel!
  return false;
}
