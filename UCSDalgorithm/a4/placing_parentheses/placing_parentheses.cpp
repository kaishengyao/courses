#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <tuple>
#include <utility> 
#include <stdio.h>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::max;
using std::min;
using std::map;

long long eval(long long a, long long b, char op) {
//    cout << a << op << b << endl;
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

std::pair<long long, long long> MinAndMax(int i, int j, int var_size, 
    long long * mMin, long long * mMax, const vector<char>& op)
{
//    cout << " in minmax" << endl;
    long long mmin = 10000000.0;
    long long mmax = -10000000.0;
    for (int k = i; k <= j - 1; k++)
    {
        long long aval = eval(mMax[i * var_size + k], mMax[(k + 1)*var_size + j], op[k]);
        long long bval = eval(mMax[i * var_size + k], mMin[(k + 1)*var_size + j], op[k]);
        long long cval = eval(mMin[i * var_size + k], mMax[(k + 1)*var_size + j], op[k]);
        long long dval = eval(mMin[i * var_size + k], mMin[(k + 1)*var_size + j], op[k]);

        mmin = std::min<long long>(aval, mmin);
        mmin = std::min<long long>(bval, mmin);
        mmin = std::min<long long>(cval, mmin);
        mmin = std::min<long long>(dval, mmin);

        mmax = std::max<long long>(aval, mmax);
        mmax = std::max<long long>(bval, mmax);
        mmax = std::max<long long>(cval, mmax);
        mmax = std::max<long long>(dval, mmax);
    }

    std::pair<long, long> mval;
    mval = std::make_pair<long , long >(mmin, mmax);

//    cout << "mmin " << mmin << " mmax " << mmax << endl;
    return mval;
}

long long max_value(const vector<string>& obs)
{
    /// parse string to have a_0 op_0 a_1 op_1 a_2 ... 
    vector<long long> var;
    vector<char> op;
    char *cptr;
    for (auto& p : obs)
    {
        if (p == "+" || p == "-" || p == "*")
            op.push_back(p.c_str()[0]);
        else
            var.push_back(strtol(p.c_str(), &cptr, 10));
    }

//    cout << var.size() << endl;
    long long * mMin = new long long[var.size() * var.size()];
    long long * mMax = new long long[var.size() * var.size()];

    int j;
    for (int i = 0; i < var.size(); i++)
    {
        mMin[i*var.size() + i] = var[i];
        mMax[i*var.size() + i] = var[i];
    }

    int nval = var.size();/// number of variables
    for (int s = 1; s <= nval - 1; s++){ /// step
        for (int i = 0; i < nval - s; i++)
        {
            j = i + s;

            std::pair<long long, long long> minandmax;
            minandmax = MinAndMax(i, j, nval, mMin, mMax, op);

            mMin[i * nval + j] = minandmax.first;
            mMax[i * nval + j] = minandmax.second;
        }
    }

    long long ret_val = mMax[var.size()-1];

    delete mMax; 
    delete mMin;

    return ret_val;
}

std::vector<std::string> split(const std::string &s)
{
    vector<string> elems;
    int istt=0, istp;
    istp = istt;
    for (auto& p : s)
    {
        if (p != '+' && p != '-' && s[istp] != '*')
        {
            istp++;
        }
        else{
            elems.push_back(s.substr(istt, istp - istt));
            elems.push_back(s.substr(istp, 1));
            istt = istp + 1;
            istp = istt;
        }
        if (istp >= s.size())
            break;
    }
    elems.push_back(s.substr(istt, istp - istt));

    return elems;
}

long long get_maximum_value(const string &exp) {
  //write your code here
    std::vector<std::string> vstr = split(exp);
    return max_value(vstr);
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
