#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cmath>

// main function, where execution starts
int main() {
    // Start measuring execution time
    auto start_time = std::chrono::high_resolution_clock::now();

    // Number of samples
    const int n = 1000000;

    // Generate random number generator and distributions
    std::random_device rd; // Seed for generating random numbers
    std::mt19937 gen(rd()); // Mersenne Twister generator
    std::uniform_real_distribution<> dist(-1.0, 1.0); // Uniform distribution from -1 to 1

    // Create vectors to hold x and y coordinates
    std::vector<double> x(n);
    std::vector<double> y(n);

    // Fill vectors x and y with random values
    for (int i = 0; i < n; ++i) {
        x[i] = dist(gen);
        y[i] = dist(gen);
    }

    // Initialize circle count
    int circle_count = 0;

    // Check each point to see if it lies within the unit circle
    for (int i = 0; i < n; ++i) {
        if (x[i] * x[i] + y[i] * y[i] <= 1.0) {
            circle_count++;
        }
    }

    // Calculate pi approximation
    double pi = 4.0 * circle_count / n;

    // Print the results
    std::cout << "The number of points out of " << n << " that fall in the circle is " << circle_count << ".\n";
    std::cout << "If we look at 4 * Ac/As, we get " << pi << " as an approximation for pi. The error is "
              << round(((pi - 3.14) / 3.14) * 100000) / 1000.0 << "%.\n";

    // Stop measuring execution time and print it
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;
    std::cout << "Execution time: " << elapsed.count() << " seconds.\n";

    return 0;
}