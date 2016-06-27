#include <iostream>
#include <string>
#include <vector>

using std::string;
using namespace std;
typedef unsigned long long ull;

static const size_t multiplier = 2;
static const size_t prime = 500007;
//static const size_t prime = 1000000007;
//static const size_t prime = 100007;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

ull poly_hash(const char* s_begin, size_t s_len) {
    unsigned long long hash = 0;
    for (int i = s_len - 1; i >= 0; --i)
        hash = (hash * multiplier + (int)*(s_begin + i)) % prime;
    return hash;
}

ull deal_with_negative(long long a, ull prime)
{
    return (a % prime + prime) % prime;
}

vector<ull> precompute_hashes(const string& t, const size_t& pattern_length)
{
    vector<ull> hash_values;

    if (pattern_length > t.size())
        return hash_values;

    hash_values.resize(t.size() - pattern_length + 1);
    ull hash = 0;
    ull hash_idx = t.size() - pattern_length; 
    hash_values[hash_idx] = poly_hash(&t[hash_idx], pattern_length);
    ull y = 1;
    for (size_t i = 1; i <= pattern_length; i++)
        y = (y * multiplier) % prime;
  
    for (int i = static_cast<int> (t.size() - pattern_length - 1); i >= 0; --i)
    {
        ull tl = t[i] - y * t[i + pattern_length] + hash_values[i + 1] * multiplier;
        tl = deal_with_negative(tl, prime); 
        hash_values[i] = tl;
//        if (hash_values[i] != poly_hash(&t[i], pattern_length))
//        {
//            cout << "wrong at " << i << " hash = " << hash_values[i] << " but poly_hash = " << poly_hash(&t[i], pattern_length) << endl;
//        }
    }

    return hash_values;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

/*std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    for (size_t i = 0; i + s.size() <= t.size(); ++i)
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    return ans;
}
*/

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    ull hash_of_pattern = poly_hash(&s[0], s.size());
    vector<ull> hashes = precompute_hashes(t, s.size());
    for (size_t i = 0; i < t.size() - s.size() + 1; i++)
    {
        if (hash_of_pattern != hashes[i])
            continue;
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
