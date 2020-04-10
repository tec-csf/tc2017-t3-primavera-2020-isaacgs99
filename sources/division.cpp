/*
  The following code is from the webpage: 
  https://www.rosettacode.org/wiki/Word_wrap#C.2B.2B
*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/**
 * Text that is going to be wrapped
 *     
*/ 
const char *text =
{
  "AAAAAAAAAA AAAAAAAAAA CCCC CCCCCCCC AAAAAAAAAA AAAAAAAAAAAA AAAAAAAAAA"

};
/**
 * Wraps the text to the optimal line length
 * 
 * @param[in] text, the line length.
 * 
 * @returns the wrapped text.
*/  
string wrap(const char *text, int line_length)
{
    istringstream words(text);
    ostringstream wrapped;
    string word;
 
    if (words >> word) {
        wrapped << word;
        int space_left = line_length - word.length();
        while (words >> word) {
            if (space_left < word.length() + 1) {
                wrapped << '\n' << word;
                space_left = line_length - word.length();
            } else {
                wrapped << ' ' << word;
                space_left -= word.length() + 1;
            }
        }
    }
    return wrapped.str();
}
 
int main()
{
  int lineLength = 26; 
  cout << "Wrapped at "<<lineLength<<":\n" << wrap(text,lineLength) << "\n\n";
  cout<< "Este algoritmo tiene una complejidad O(n)"<<endl;
}