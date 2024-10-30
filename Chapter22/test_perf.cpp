#include <chrono>
#include <iostream>

long long fibonacci(int  n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main()
{

    std::cout << "Test recursive perf" << std::endl;

    int  n = 45;
    auto      st{std::chrono::high_resolution_clock::now()};
    long long res = fibonacci(n);
    auto      ed{std::chrono::high_resolution_clock::now()};

    auto      diff{ed - st};
    std::cout << "Res: " << res << " cost: " << std::chrono::duration_cast<std::chrono::milliseconds>(diff) << std::endl;

    return 0;
}