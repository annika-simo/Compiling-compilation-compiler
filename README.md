# Compiling-compilation-compiler
CS1021 Lab 6

## Introduction
What's the red fruit that goes into ketchup? [You say "tomayto", I say "tomahto"](https://en.wikipedia.org/wiki/Let%27s_Call_the_Whole_Thing_Off). A professor sets their answer key to expect execution and you type execute -- you deserve the points, right? You google for *Practicing how to dribble* -- shouldn't a document titled *How to practice dribbling* appear in the search results?

[Information Retrieval](https://en.wikipedia.org/wiki/Information_retrieval) (IR) is the academic name of the field of computer science devoted to the study of how to develop search engines.  An IR system is basically a set of algorithms that turn a user's search query into a list of related materials. Although the researchers in the field of IR build systems to search many different types of material (documents, videos, songs, etc), their original goal was to develop ways to allow users to search for the few relevant documents in a large collection. They hypothesized a system that would simply list the documents in the collection in decreasing order from the most relevant to the user's query to the least relevant to the user's query. Relevancy is a subjective, qualitative metric -- they needed some way to quantify it. The researchers started out using a simple method to calculate relevancy: count the number of times that each word in a user's query appears in each of the candidate documents.

This brilliantly simple technique worked great, until it didn't. Recalling the example above, shouldn't the system count practice, if found in some candidate document as a match for practicing from the query? Of course it should. And the same is true for dribble and dribbling. There are many, many examples of cases like this in the English language where words with similar meaning have different suffixes. This realization caused IR system designers to acknowledge that they could not do a simple, literal scan for query terms in a candidate document, count up the matches, and use that number to determine relevancy.

noun_stem_383522-2.png	What did they do instead? Simple: first, strip off the pesky suffixes of every single word in the query and the candidate document and then do the simple, literal search. But what's the best way to remove the suffix from a word and pare it to its stem? In 1979/1980, (Links to an external site.) scientist Martin Porter (Links to an external site.) designed a stemming algorithm that he thought was the ideal way to lop off extraneous suffixes and reduce words to their core. To understand better the meaning of stem and suffix, here are a few examples of words before and after they are run through the *Porter Stemming Algorithm*:

| Before Porter Stemming  | After Porter Stemming |
| ------------- | ------------- |
| Execution  | Execut  |
| Translation  | Translat  |
| Grandiose  | Grandios  |
| Ambiguous  | Ambigu  |
| Ambiguity  | Ambigu  |
| Speculation  | Specul  |

Look closely as the stems of *ambiguous* and *ambiguity* -- they are the same! That's exactly what IR system designers want. Determining that *ambiguous* and *ambiguity* have the same meaning is now the product of a simple letter-by-letter comparsion because the stems are the same.

A successful implementation of the Porter Stemming Algorithm requires a significant number of helper functions. Helper functions are functions that perform operations in service of a larger, more complex function. Computer scientists "discover" helper functions when they are writing/implementing that overarching function. They recognize that they are writing certain blocks of code over and over. The developer names the operation that these blocks perform and abstracts the code into separate functions. Like any other function, a helper function improves the readability of code and reduces the likelihood of errors introduced by mistaken copy/paste.

There are 9 helper functions needed for a clean, readable implementation of the Porter Stemming Algorithm:

1. `is_vowel`
2. `is_consonant`
3. `ends_with`
4. `ends_with_double_consonant`
5. `ends_with_cvc`
6. `count_consonants_at_front`
7. `count_vowels_at_back`
8. `contains_vowel`
9. `new_ending`

Your task in this lab is to implement the specified helper functions according to the specifications given below. In doing so, you will contribute to a robust  implementation of the Porter Stemming Algorithm that will serve as the core of the BearING search engine.

Good luck!

## Program Design Task
As "they" like to say, “My code pseudo works!” Before you start writing code, please write the pseudocode or draw a flow chart for your implementation of the 9 helper functions required to complete the implementation of the *BearING* search engine.

## Program Design Requirements
Your pseudocode or flow chart must describe the entirety of the process you plan to use to meet the requirements for each helper function. You may choose to write the flow chart or the pseudocode at any level of detail but remember that this is a tool for you! Your pseudocode or flow chart must include a separate, labeled description for each of the 9 helper functions given above. For places where you must handle corner cases, you must describe in your pseudocode how you will handle those.

## Programming Task
Your programming task is to implement and document the 9 helper functions required to complete the implementation of the Porter Stemming Algorithm and the *BearING* application. In this lab you will not prompt the user for input. Your implementation will be validated by a series of unit tests.

Implement the 9 helper functions according to the following specifications:

| Name  | Parameters | Return Type | Semantics | Gotchas |
| --- | --- | --- | --- | --- |
| `is_vowel`  | a character  | `bool`  | `is_vowel` returns true when its argument is a vowel and false otherwise  | n/a  |
| `is_consonant`  | a character  | `bool`  | `is_consonant` returns true when its argument is a consonant and false otherwise | Cell  |
| `ends_with`  | two strings, *candidate* and *suffix* (in that order)  | `bool`  | If *candidate* is an empty string and *suffix* is an empty string, `ends_with` returns true. If *candidate* is an empty string and *suffix* is not an empty string, `ends_with` returns false. If *candidate* ends with *suffix*, `ends_with` returns true. Otherwise, it returns false.  | *suffix* or *candidate* may be empty strings  |
| `ends_with_double_consonant`  | a string  | `bool`  | `ends_with_double_consonant` returns true if the last two characters of the argument areboth consonants, and equal to one another. It returns false otherwise.  | The string passed as an argument may contain fewer than two characters.  |
| `ends_with_cvc`  | a string  | `bool`  | `ends_with_cvc` returns true if the last three characters of the argument are a consonant, a vowel and then a consonant (hence the name, cvc). It returns false otherwise.  | The string passed as an argument may contain fewer than three characters.  |
| `count_consonants_at_front`  | a string  | `int`  | `count_consonants_at_front` returns the number of consecutive constants at the beginning of the argument. For example, `count_consonants_at_front(std::string{"threw"})` is 3.  | The string passed as an argument may be empty.  |
| `count_vowels_at_back`  | a string  | `int`  | `count_vowels_at_back` returns the number of consecutive vowels at the end of the argument. For example, `count_vowels_at_back(std::string{"free"})` is 2.  | The string passed as an argument may be empty.  |
| `contains_vowel`  | a string  | `bool`  | `contains_vowel` returns true if there is a vowel anywhere in the argument. It returns false otherwise.  | The string passed as an argument may be empty.  |
| `new_ending`  | a string, a number and a string named *candidate*, *suffix length* and *replacement*, respectively (and in that order)  | `std::string`  | `new_ending` creates a new string from *candidate* by removing its last *suffix length* characters and replacing them with *replacement*. `new_ending` returns that new string. For example, `new_ending(std::string{"testing"}, 3, std::string{"ed"})` is "tested". You may assume that *suffix length* is always less than the length of *candidate*.  | *replacement* may be an empty string  |

You will know whether your helper functions are written correctly when all the unit tests pass. If all the unit tests pass, you will receive full points for the programming part of this lab!

Documenting functions is a very important part of a professional programmer's job. Every programming project has their own preferred format for writing comments that describe functions and their inputs/outputs. For the BearING project, we ask that your comments conform with the following format:

```cpp
/*
 * <function name>
 *
 * <short description of what the function does>
 *
 * input: <short description of all input parameters>
 * output: <short description of all output parameters
 *          and the return value>
 */
 ```
 
## Programming Requirements
If you are a Windows user, start with the skeleton .zip in this repository This skeleton provides the starting point for a successful implementation of the *BearING* search engine. If you do not use this skeleton code you will not be able to complete this lab. The first time that you run the skeleton code you will receive compiler errors. This is expected. The code will not compile until you provide at least a basic definition of the 9 helper functions specified above. 

All of your work will be done in the `helpers.cpp` file. You should not edit code in any of the other files.

You should start your work by defining each of the 9 helper functions using stubs. The stub for a function has all the same components as the actual function but has a body that performs no meaningful action. A stub implementation for a function `func` that returns a boolean and takes a single parameter -- a string -- might look like this:

```cpp
bool func(std::string p) {
  return true;
}
```

A stub implementation for a function `func` that returns a string and takes a single parameter -- a string -- might look like this:

```cpp
std::string func(std::string p) {
  return std::string{""};
}
```

Beginning this lab by implementing stubs for each of the 9 helper functions will give you the confidence that your code compiles and that your development environment is configured correctly.

As you work on the *BearING*search engine, you may make the following assumptions:
1. The vowels are a, e, i, o, and u.
2. The consonants are the letters that are not vowels.
3. The suffix length parameter of the new_ending helper function will never be longer than the length of candidate.
4. All input will be lower case -- no upper-case letters will be given.

To implement several of the helper functions, you will find it helpful to *iterate* -- go element by element -- over the individual characters in a string. Like the elements of an array, each of the characters in a string in C++ is associated with an index. The first character of a string is "at" index 0. The second character of a string is at index 1. The final character of the string is at the index n, where n is one less than the length of the string. (Remember that this is C++ and that all counting/indexing begins at 0). You can use the `at` *method* on a `std::string` *object* to access the character at a particular index. For instance,

```cpp
#include <iostream>

int main() {
  std::string str{"teasing"};
  std::cout << "str.at(0): " << str.at(0) << "\n";
  std::cout << "str.at(str.length() - 1): " << str.at(str.length() - 1) << "\n";
  return 0;
}
```

will print

```
str.at(0): t
str.at(str.length() - 1): g
```
A successful submission for this lab will include source code for 9 helper functions in `helpers.cpp` that a) pass all the unit tests included in the skeleton code *and* b) are properly documented (using comment blocks formatted according to the specifications set out above).

## Critical Thinking Task
[Time is money](https://en.wikipedia.org/wiki/Time_is_money_(aphorism)), as they say. But, perhaps it is really better to think about money and time as two sides of the same coin (sorry for the pun!). Think of a scenario where you are out with your friends on a weeknight having dinner. You have a test the next day so you are in some hurry to get home to study after you finish eating. As you debate whether to walk home, take transit or call a Lyft, you consider the following:
1. Walking home will take the longest, but will cost the least.
2. Even though you may have to wait for the next bus/shuttle, using transit will be faster than walking but will be (relatively speaking) more expensive than walking.
3. Using Lyft will get you home fast but will cost the most.

In whatever decision you make there will be a tradeoff between time and money.

Tradeoffs occur all the time in computer science and software development. One of the most common tradeoffs faced by software developers is time against space -- a software developer is faced with the choice of whether to use an algorithm that runs fast (time) but uses lots of memory (space) or one that runs slowly but uses very little memory. In making a decision about which version of the algorithm to employ, the developer must consider their available resources (Is their software running on a giant server or the chip on a watch?), the impact on the user (Will their software fail to do the job correctly if it is too slow? For example, what would happen if a lane-departure system didn't activate corrective steering action immediately after detecting the car drifting into the other lane?), the cost of implementation (in terms of how hard it is to understand the algorithm, debug the code in the future, make improvements in the next version), etc.

Your job in this critical thinking task is to describe another fundamental tradeoff that you think is common in computer science and provide three (3) metrics that a software developer can use to make a decision when faced with such a dilemma.

## Critical Thinking Requirement
In no more than 500 words, describe another fundamental tradeoff that you think is common in computer science and describe three (3) metrics that a software developer can use to make a decision when faced with such a dilemma. You may, but are not required to, use external references to help you build your response. If you decide to use material from outside the class, it is your responsibility to properly document your references. Failure to do so is a violation of this course's policy on academic honesty and will result in severe consequences. If you need help generating the proper documentation in such cases, please contact us!

Here is a model answer to help you formulate your submission:

> Software developers often face the fundamental tradeoff between time and space -- it is usually the case that the faster an algorithm runs, the more memory it will require (and vice versa). Deciding between two algorithms that accomplish the same task -- one that is fast but uses lots of memory and one that is slow but conserves space -- is not easy. A developer can consider these factors when faced with this dilemma:
> 
> Use case: The developer can consider whether it is important to the end user for the algorithm to compute its results quickly. For instance, when the software will be controlling systems that interact with the physical world (autopilot, self-driving car, robot, etc), timely reaction to physical stimuli is more important than the amount of space required to generate that reaction.
> 
> Market: The developer can consider where this application will be used. If the software is for deployment on a cell phone, favoring the algorithm that uses less memory is the right choice. But, if the software is for deployment on a supercomputer, time is of the essence.
> 
> Organizational cost: If the algorithm that is faster but sips memory is more complicated than the algorithm that is slower but guzzles RAM, debugging and maintaining the former will be more expensive and time consuming than the latter. 

## Deliverables
1. The pseudocode describing the algorithms you used to implement the 9 helper functions required to complete the BearING search engine in PDF format (named `design.pdf`).
2. The C++ source code for the helper functions required for successful operation of the BearING application (named `helpers.cpp`).
3. The response to the Critical Thinking prompts in PDF format (named `tradeoff.pdf`)

## Related Learning Objectives
1. Writing boolean expressions using relational and logical operators
2. Using if-statements to implement selective program execution
3. Using algorithmic thinking to design programs
4. Write syntactically correct for/while loops
5. Identify the components of for/while loops
6. Use each of the three types of loops in the appropriate situation
7. Use methods on objects

## Credits
stem by Marek Polakovic from the Noun Project

