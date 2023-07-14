#include <iostream>
#include <stack>

using namespace std;

void reverseString(std::string &expn);
void replaceParanthesis(std::string &a);
std::string infixToPostfix(std::string &expn);


std::string infixToPrefix(std::string expn)
{
    reverseString(expn);
    replaceParanthesis(expn);
    expn = infixToPostfix(expn);
    reverseString(expn);
    return expn;
}
void replaceParanthesis(std::string &a)
{
    int lower = 0;
    int upper = a.size() - 1;
    while (lower <= upper)
    {
        if (a[lower] == '(')
        {
            a[lower] = ')';
        }
        else if (a[lower] == ')')
        {
            a[lower] = '(';
        }
        lower++;
    }
}
void reverseString(std::string &expn)
{
    int lower = 0;
    int upper = expn.size() - 1;
    char tempChar;
    while (lower < upper)
    {
        tempChar = expn[lower];
        expn[lower] = expn[upper];
        expn[upper] = tempChar;
        lower++;
        upper--;
    }
}

 int precedence(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

std::string infixToPostfix(std::string &expn)
{
    std::stack<char> stk;
    std::string output = "";
    char out;
    for (auto ch : expn)
    {
        if (ch <= '9' && ch >= '0')
        {
            output = output + ch;
        }
        else
        {
            switch (ch)
            {
                case '+' : case '-' : case '*' : case '/' : case '%' : case '^' : while (stk.empty() == false && precedence(ch) <= precedence(stk.top()))
                {
                    out = stk.top();
                    stk.pop();
                    output = output + " " + out;
                }
                stk.push(ch);
                output = output + " ";
                break;
            case '(':
                stk.push(ch);
                break;
            case ')':
                while (stk.empty() == false && (out = stk.top()) != '(')
                {
                    stk.pop();
                    output = output + " " + out + " ";
                }
                if (stk.empty() == false && (out = stk.top()) == '(')
                    stk.pop();
                break;
            }
        }
    }
    while(stk.empty() == false)
    {
        out = stk.top();
        stk.pop();
        output = output + out + " ";
    }
    return output;
}
int main()
{
    std::string expn = "10+((3))*5/(16-4)";
    std::string value = infixToPrefix(expn);
    std::cout << "Infix Expn: " << expn << std::endl;
    std::cout << "Prefix Expn: " << value << std::endl;
    expn = "(A+B^C)*D+E^5";
    cout << infixToPrefix(expn) << endl;
    return 0;
}
