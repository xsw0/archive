#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    // auto is = [](size_t n) {
    //     auto n2 = n * 2;
    //     auto n3 = n * 3;
    //     unordered_set<size_t> s;
    //     s.insert(n % 10);
    //     s.insert(n / 10 % 10);
    //     s.insert(n / 100 % 10);
    //     s.insert(n2 % 10);
    //     s.insert(n2 / 10 % 10);
    //     s.insert(n2 / 100 % 10);
    //     s.insert(n3 % 10);
    //     s.insert(n3 / 10 % 10);
    //     s.insert(n3 / 100 % 10);
    //     return s.find(0) == s.end() && s.size() == 9;
    // };
    // for (size_t i = 100; i <= 333; i++)
    // {
    //     if (is(i))
    //     {
    //         cout << i << ' ' << i * 2 << ' ' << i * 3 << endl;
    //     }
    // }
    cout << "192 384 576\n"
         << "219 438 657\n"
         << "273 546 819\n"
         << "327 654 981\n"
         << flush;
    return 0;
}
