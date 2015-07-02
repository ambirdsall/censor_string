#include <iostream>
#include <cassert>

using namespace std;

string CensorText1(string text, string remove);
string CensorText2(string &text, string remove);
string CensorText3(string &text, string remove);

int main()
{
  string nonDestructiveText   = "Oh, thirty hot dogs.",
         destructiveText1     = "Oh, thirty hot dogs.",
         destructiveText2     = "Oh, thirty hot dogs.",
         toStrip              = "t dO",
         result               = "h,hiryhoogs.";

  // CensorText1 should return censored string without changing input string
  assert(CensorText1(nonDestructiveText, toStrip) == result);
  assert(nonDestructiveText != result);

  // CensorText2 should return censored string and change input string
  assert(CensorText2(destructiveText1, toStrip) == result);
  assert(destructiveText1 == result);

  // CensorText3 should behave the same as CensorText2
  assert(CensorText3(destructiveText2, toStrip) == result);
  assert(destructiveText2 == result);

  cout << "No bugs found!\n";
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

string CensorText2(string &text, string remove)
{
  int i = 0;
  int removeLength = remove.length();

  while (i < text.length()) {
    char letterOfConcern = text[i];
    bool shouldBeStripped = false;

    for (int j = 0; j < removeLength; ++j) {
      char letterToStrip = remove[j];

      if (letterOfConcern == letterToStrip)
        shouldBeStripped = true;
    }

    if (shouldBeStripped)
      text.erase(text.begin() + i);
    else
      ++i;
  }

  return text;
};

string CensorText3(string &text, string remove)
{
  return text = CensorText1(text, remove);
};
