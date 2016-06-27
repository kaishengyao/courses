#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using std::cout;
using std::vector;
using std::endl;

struct Bracket {
    Bracket(int type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {

    std::vector<int> verr; 
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push(Bracket(next, position));
        }

        if (next == ')' || next == ']' || next == '}') {
            if (opening_brackets_stack.size() == 0)
                verr.push_back(position);
            else{
                Bracket tb = opening_brackets_stack.top();
                if (!tb.Matchc(next))
                    verr.push_back(position);
                else
                    opening_brackets_stack.pop();
            }
        }
    }

    if (verr.size() == 0 && opening_brackets_stack.size() == 0)
        cout << "Success" << endl;
    else{
        if (verr.size() > 0)
            cout << verr[0] + 1 << endl;
        else if (opening_brackets_stack.size() > 0)
            cout << opening_brackets_stack.top().position + 1 << endl;
    }
    
    return 0;
}
