#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum CommentStart
{
  CODE = 0,
  LINE_CMT,
  BLOCK_CMT,
  STRING,
};

class FindWord
{
public:
  FindWord(string filename, string word);
private:
};

FindWord::FindWord(string filename, const string TheWord) {
  const int TheWordLength = TheWord.length();
  ifstream ifs(filename, ifstream::in);
  string line;
  
  CommentStart cs = CODE;
  while(ifs) {
    getline(ifs, line);
    
    for (int i=0; i<line.length()-1; i++) {
      if (line[i] == '"') {
        switch (cs) {
          case STRING:
            cs = CODE; break;
          case CODE:
            cs = STRING; break;
        }
      }
      
      string s = line.substr(i, 2);
      switch (s) {
        case "//":
          cs = LINE_CMT; break;
        case "/*":
          cs = BLOCK_CMT; break;
        case "*/":
          cs = CODE; break;
      }

      if (cs == LINE_CMT || cs == BLOCK_CMT) {
        if (i<line.length()-TheWordLength && line.substr(i, 6) == TheWord) {
          return true;
        }
      }
    }
  }
  return false;
}
