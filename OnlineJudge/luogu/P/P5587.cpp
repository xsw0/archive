#include "bits/stdc++.h"

using namespace std;

string back(const string &s) {
    string result;
    for (auto c : s) {
        if (c == '<') {
            if (!result.empty()) { result.pop_back(); }
        } else {
            result.push_back(c);
        }
    }
    return result;
}

size_t rate(const string &text, const string &input) {
    size_t count = 0;
    string text_back = back(text);
    string input_back = back(input);
    size_t min_size = min(text_back.size(), input_back.size());
    for (size_t i = 0; i < min_size; ++i) {
        if (text_back[i] == input_back[i]) ++count;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<string> text;
    string line;
    while (getline(cin, line) && line != "EOF") { text.emplace_back(line); }

    size_t index = 0;
    size_t count = 0;
    while (getline(cin, line) && line != "EOF") {
        if (index < text.size()) {
            count += rate(text[index], line);
            ++index;
        }
    }
    size_t time;
    cin >> time;
    cout << static_cast<unsigned>((count / (time / 60.0)) + 0.5) << endl;

    return 0;
}
