#include <iostream>

using namespace std;

string CensorText1(string text, string remove);
/* string CensorText2(string &text, string remove); */

int main()
{
  string text, toStrip, censoredText;

  cout << "What's the string, chief? ";
  cin >> text;
  cout << "Word. And what should be stripped from it? ";
  cin >> toStrip;

  censoredText = CensorText1(text, toStrip);

  cout << "'" << text << "'? More like '" << censoredText << "', AMIRITE?!";
  /* assert(CensorText1(test, "os") == "Ott dg"); */
}

string CensorText1(string text, string remove)
{
  int textLength = text.length();
  int removeLength = remove.length();
  string resultString;

  for (int i = 0; i < textLength; ++i) {
    char letterOfConcern = text[i];
    bool shouldBeStripped = false;

    for (int j = 0; j < removeLength; ++j) {
      char letterToStrip = remove[j];
      if (letterOfConcern == letterToStrip)
        shouldBeStripped = true;
    }

    if (!shouldBeStripped)
      resultString += letterOfConcern;
  }

  return resultString;
};
