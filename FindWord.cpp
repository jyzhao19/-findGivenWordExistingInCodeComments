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

class Solution
{
public:
    bool FindWord(string filename, const string& word);
private:
};

bool Solution::FindWord(string filename, const string& TheWord) {
    const int TheWordLength = TheWord.length();
    ifstream ifs(filename, ifstream::in);
    string line;

    CommentStart cs = CODE;
    while (ifs) {
        getline(ifs, line);

        for (int i = 0; i < line.length() - 1; i++) {
            if (line[i] == '"') {
                switch (cs) {
                case STRING:
                    cs = CODE; break;
                case CODE:
                    cs = STRING; break;
                }
            }

            string s = line.substr(i, 2);
            if (s == "//")
                cs = LINE_CMT;
            else if (s == "/*")
                cs = BLOCK_CMT;
            else if (s == "*/")
                cs = CODE;

            if (cs == LINE_CMT || cs == BLOCK_CMT) {
                if (i < line.length() - TheWordLength && line.substr(i, 6) == TheWord) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    Solution s = Solution();
    bool ret = s.FindWord("c:\\Users\\tony.zhao2\\Desktop\\dfd.txt", "GOOGLE"); // GOOGLE 
    cout << ret << endl;
}
