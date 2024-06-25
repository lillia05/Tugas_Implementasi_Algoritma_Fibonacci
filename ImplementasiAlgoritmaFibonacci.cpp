#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip> 

using namespace std;
using namespace std::chrono;

long long fibonacci_recursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

long long fibonacci_dp(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    vector<long long> fib(n + 1, 0);
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

void measure_execution_time() {
    vector<int> n_values = {10, 25, 30, 40, 50};

    cout << left << setw(5) << "n"
         << setw(20) << "Hasil Rekursif"
         << setw(25) << "Waktu Rekursif (ms)"
         << setw(20) << "Hasil DP"
         << setw(20) << "Waktu DP (ms)" << endl;

    for (int n : n_values) {
        auto start = high_resolution_clock::now();
        long long result_recursive = fibonacci_recursive(n);
        auto end = high_resolution_clock::now();
        auto recursive_duration = duration_cast<milliseconds>(end - start).count();

        start = high_resolution_clock::now();
        long long result_dp = fibonacci_dp(n);
        end = high_resolution_clock::now();
        auto dp_duration = duration_cast<milliseconds>(end - start).count();

        cout << left << setw(5) << n
             << setw(20) << result_recursive
             << setw(25) << recursive_duration
             << setw(20) << result_dp
             << setw(20) << dp_duration << endl;
    }
}

int main() {
    measure_execution_time();
    return 0;
}
