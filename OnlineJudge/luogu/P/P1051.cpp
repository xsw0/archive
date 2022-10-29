#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n;
    cin >> n;
    int maximum = -1;
    string top_name;
    int tot_bonus = 0;
    while (n--) {
        string name;
        int final_score, eval_score, paper_num;
        char is_official, is_remote;
        cin >> name >> final_score >> eval_score >> is_official >> is_remote >>
            paper_num;
        int bonus = 0;
        if (final_score > 80 && paper_num > 0) bonus += 8000;
        if (final_score > 85 && eval_score > 80) bonus += 4000;
        if (final_score > 90) bonus += 2000;
        if (final_score > 85 && is_remote == 'Y') bonus += 1000;
        if (eval_score > 80 && is_official == 'Y') bonus += 850;
        if (bonus > maximum) {
            maximum = bonus;
            top_name = name;
        }
        tot_bonus += bonus;
    }
    cout << top_name << "\n" << maximum << "\n" << tot_bonus << endl;

    return 0;
}
