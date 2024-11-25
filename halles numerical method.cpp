
#include <iostream>
#include <cmath>
using namespace std;

// Function for which we want to find the root
double f(double x)
{
    return x*x*x - x -1;
}

// First derivative of the function
double f_prime(double x)
{
    return 3*x*x - 1;
}

// Second derivative of the function
double f_double_prime(double x)
{
    return 6*x;
}

// Halley's method to find the root
double halley(double x, double tol)
{
    double h;
    // Continue iterating until the function value is within the tolerance
    while (fabs(f(x)) >= tol)
    {
        // Calculate the Halley update
        h = x-(2 * f(x) * f_prime(x)) / (2 * pow(f_prime(x), 2) - f(x) * f_double_prime(x));
        // Update the current guess
        x = h;
    }
    return x;
}

int main()
{
    double ititial_guess = 2;       // Initial guess
    double tol = 0.0001; // Tolerance for stopping
    double root = halley(ititial_guess, tol); // Find the root using Halley's method
    cout << "Root: " << root << endl; // Output the root
    return 0;
}


