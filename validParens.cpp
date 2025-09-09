// Check if Parenthesis set is opened and closed properly. Buffer cuts off valid parens set.
// Easy, stack implementation
class Solution {
public:
  map<char, char> rParen;
  vector<char> stack;
void customInitMap(){
    rParen[')'] = '(';
    rParen[']'] = '[';
    rParen['}'] = '{';
}

bool runner(string s) {
    for (char c : s) {
        // char c = s[i];
        if (stack.size() > 0) {
            if (stack.back() == rParen[c]) {
                stack.pop_back();
                continue;
            }
        }
        stack.push_back(c);
    }
    if (stack.size() > 0)
        return false;
    return true;
}

bool isValid(string s) {
    customInitMap();
    // delete nonbracket chars function here
    return runner(s);
}
};
