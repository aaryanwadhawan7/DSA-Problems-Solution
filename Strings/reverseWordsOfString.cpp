#include <iostream>
using namespace std;

// c  a  r , s  t  a  r
//    ij        j  i

void reverse(string &str, int start, int end)
{
    while (start < end)
    {
        // swap start and end character
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

// "  Hello  World  "
//          st
void removeTrailingSpaces(string &str)
{
    string res;

    int st = 0;
    if (st < str.length() && str[st] == ' ')
    {
        st++;
    }

    int i = st;
    while (i < str.length())
    {
        if (str[i] != ' ')
        {
            // add char to res string
            res = res + str[i];
        }
        else if (!res.empty() && res.back() != ' ')
        {
            res.push_back(' ');
        }
        i++;
    }


    // Remove trailing space
    if (!res.empty() && res.back() == ' ')
    {
        res.pop_back();
    }

    str = res;
}

string reverseStringWords(string &str)
{
    // fn to remove trailing spaces from the starting and ending if exists
    removeTrailingSpaces(str);

    int st = 0;

    // Pass-1
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            // reverse the word
            reverse(str, st, i - 1);
            st = i + 1;
        }
    }

    reverse(str, st, str.length() - 1);

    // Pass-2
    reverse(str, 0, str.length() - 1);

    return str;
}

int main()
{
    string str = "the sky is blue";

    // eht yks si eulb => Reverse each word of the string while traversing (Pass 1)
    // blue is sky is the => Reverse the whole string (Pass 2)

    string checkSpaces = "  Hello  World  ";
    removeTrailingSpaces(checkSpaces);
    cout << checkSpaces << endl;

    string res = reverseStringWords(str);
    cout << res << endl;

    return 0;
}