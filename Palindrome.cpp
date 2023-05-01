//created by Muna S on 03/10/2023
/*
 * pallindrome: checks a string to see if it is a pallindrome.
 *
 *  Examples:
 *
 *  Able was I 'ere I saw Elba.
 *  Madam, I'm Adam.
 *  A man, a plan, a canal, Panama.
 *  Racecar
 *
 *  First, create a clean version of the string.
 *      - convert all characters to lower case.
 *      - remove all punctuation.
 *
 *  Second, create a reverse version of the string.
 *   - use reverse and swap from our lab assignment
 *   so first make a copy of the string and pass in
 *   the copy to reverse.
 *
 *  Third
 *      - compare the two strings
 *          if they are the same, palindrome.
 *          else, not palindrome.
 */
#include <vector>
#include <iostream>
#include <string>
// ToDo: Add include files.
using namespace std;

string removePunct(string str);

// Function: removePunct
// Precondition: a string that may or may not have punctuation.
// Postcondition: returns a (possibly shorter) string with punctuation removed.
string convertToLower(string str);

// Precondition: a string that may have mixed case in it.
// Postcondition: returns a lowercase string
string reverse(string str);
// Precondition: a string to be reversed
// Postcondition: returns a string that is the reverse of the input string.

void display(vector<string> vstrings);
// Precondition: a vector of strings to print
// Postcondition: strings are printed one per line.

bool isPalindrome(string str);
// Precondition: a string to be tested
// Postcondition: returns a bool that is true if the input is a palindrome returns false otherwise.

int main() {
    // ToDo: Declare two vectors of strings to save the input strings: palindromes, not_palindromes.
    vector<string> palindromes, not_palindromes;
    // ToDo: Implement a loop to read in the palindrome strings using getline until
    // the user quits. The user will enter the word "quit" to exit the loop.
    string s;
    while (getline(cin, s) && s != "quit") {
        // ToDo: In the loop, call the isPalindrome function on the input string and
        // store it in the palindromes vector if true and the notPalindromes vector if false.
        if (isPalindrome(s)) {
            palindromes.push_back(s);
        } else {
            not_palindromes.push_back(s);
        }
    }
    // ToDo: After exiting the loop, print the list of palindromes under a Palindrome
    // heading and the list that are not palindromes under a Not Palindrome heading.
    cout << "Palindrome" << endl;
    display(palindromes);

    cout << "Not Palindrome" << endl;
    display(not_palindromes);
    // The display function should print a tab character before printing the string.
    return 0;
}

string removePunct(string str) {
    string result;
    for (int i = 0; i < str.size(); ++i) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            result += str[i];
        }
    }
    return result;  //**removePunct function takes a string input and returns a new string with all non-alphabetic characters removed
}

string convertToLower(string str) {
    string result;
    char ch;
    for (int i = 0; i < str.size(); ++i) {
        ch = str[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a';
        }
        result += ch;
    }
    return result;    //** convertToLower function takes a string and returns a new string with all uppercase characters converted to Lcase
}

string reverse(string str) {
    string result;
    for (int i = 0; i < str.size(); ++i) {
        result = str[i] + result;
    }
    return result;  //takes a string & returns string in reverse orda
}

void display(vector<string> vstrings) {
    for (int i = 0; i < vstrings.size(); ++i) {
        cout << "\t" << vstrings[i] << endl;  //**display function takes a vector of strings vstrings as an input parameter and outputs each element of the vector
    }
}

bool isPalindrome(string str) {
    return convertToLower(removePunct(str)) == reverse(convertToLower(removePunct(str)));
}   // **isPalindrome function takes a string input, removes all non-alphabetic characters, converts all uppercase characters to lowercase, and returns bool T if the string is same (when reversed).
