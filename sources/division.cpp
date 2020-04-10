#include <iostream>
#include <sstream>
#include <string>
using namespace std;
 
const char *text =
{
  "aaaaaaaaaa aaaaaaaaaa cccc cccccccc aaaaaaaaaa aaaaaaaaaaaa aaaaaaaaaa"

};
 
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
}