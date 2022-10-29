#include <iostream>

template<typename R, typename ... Args>
auto Y = [](auto &&f) {
  return [&](auto &&g) { return g(g); }(
      [&](auto &&g) -> std::function<R(Args...)> {
        return f(
            [&](Args &&... args) -> R {
              return g(g)(std::forward<Args...>(args...));
            }
        );
      }
  );
};

int main() {
  auto fact = [](auto self) {
    return [=](int n) -> int {
      return n == 0 ? 1 : n * self(n - 1);
    };
  };
  std::cout << Y<int, int>(fact)(5) << std::endl;

  return 0;
}
