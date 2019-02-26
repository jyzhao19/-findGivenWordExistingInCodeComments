enum STATE {
  
};

class Solution {
public:
    int calculate(string s) {
        stack<int> s;
        for (auto c: s) {
          if (c==' ')
            continue;
          if (isdigit(c))
            s.push(c-'0');
        }
    }
};
