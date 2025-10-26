#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

/*

********************************************************************************
* Palindrome:
* A palindrome is a word, number, phrase, or sequence that reads the same forwards and backwards.
* 
* Uses of Palindromes:
* 1. **String and Data Validation**: Checking if inputs are symmetrical or meet certain criteria.
* 2. **Algorithm Practice**: Common problem in coding interviews to test recursion, iteration, and logic skills.
* 3. **Bioinformatics**: Identifying palindromic DNA sequences which have biological significance.
* 4. **Cryptography and Pattern Recognition**: Detecting symmetrical patterns in data or encrypted messages.
* 5. **Mathematics and Number Theory**: Studying numerical palindromes for interesting properties or sequences.
*
* Palindromes are important because they help in pattern detection, input validation, 
  and practicing problem-solving skills in programming.
********************************************************************************

PSEUDOCODE isPalindrome(n)

    IF right is not provided THEN
        convert word to lowercase
        remove spaces from word
        right = length(word) - 1
        left = 0

    IF left >= right THEN
        RETURN true

    IF word[left] ≠ word[right] THEN
        RETURN false 

    RETURN isPalindrome(word, left + 1, right - 1) 

end PSEUDOCODE

PSEUDOCODE isPalindrome(text):
    text ← convert text to lowercase
    text ← remove spaces and punctuation

    left ← 0
    right ← length(text) - 1

    WHILE left < right:
        IF text[left] ≠ text[right]:
            RETURN False
        left ← left + 1
        right ← right - 1

    RETURN True

end PSEUDOCODE

*/

using namespace std;

bool isPalindrome_tail_recursion(std::string word, int left = 0, int right = - 1) {

    if(right == -1) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end());
        int right = word.length() - 1;
    }

    if (left >= right) return true;

    if (word.at(left) != word.at(right)) return false;

    return isPalindrome_tail_recursion(word, left + 1, right -1);
}

bool isPalindrome_head_recursion(std::string word, int left = 0, int right = - 1) {
    if (right == -1) {
        string cleanWord = word;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end());
        right = word.length() - 1;
    }

    if (left >= right) return true;

    bool rest = isPalindrome_head_recursion(word, left + 1, right - 1);

    return rest && (word[left] == word[right]);
}

bool isPalindrome_iterative(std::string word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end());

    int left = 0;
    int right = word.length() - 1;

    while (left < right) {

        if (word[left] != word[right]) return false;

        left++;

        right--;
    }

    return true;
}


int main() {
    string word = "Race car";
    cout << isPalindrome_iterative(word) << std::endl;
    return 0;
}