/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // strategy: flatten the given List to a vector up front. Then next and hasNext will be trivial.
        // two ways: 1. recursion; 2. iteration
        // recursion: iterate thru the first layer of list, if it is a number, directly push into the private ans; otherwise,
        // call itself to do it.
        // helper(nestedList);
        // it=res.begin();
        
        // iteration: for every element use while loop.
        deque<NestedInteger> dq;
        for (auto e: nestedList)
            dq.push_back(e);
        while(!dq.empty()) {
            auto t=dq.front(); dq.pop_front();
            if (t.isInteger())
                res.push_back(t.getInteger());
            else {
                auto l = t.getList();
                for (auto e=l.rbegin(); e!=l.rend();e++)
                    dq.push_front(*e);
            }
        }
        
        it = res.begin();
    }

    int next() {
        return *(it++);
    }

    bool hasNext() {
        if (it==res.cend())
          return false;
        return true;
    }
private:
    vector<int> res;
    vector<int>::iterator it;
    void helper(vector<NestedInteger>& v) {
      for (auto e: v) {
        if (e.isInteger())
          res.push_back(e.getInteger());
        else
          helper(e.getList());
      }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
