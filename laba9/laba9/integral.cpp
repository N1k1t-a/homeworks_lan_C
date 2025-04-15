#include "integral.h"
#include <cmath>
#include <iostream>

double trapezoidal_rule_by_cos(double a, double b, double eps) {
    int n = 2; 
    double h = (b - a) / n;
    double prev_integral = 0.0;
    double integral = (cos(a) + cos(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        integral += cos(x);
    }

    integral *= h;


    while (fabs(integral - prev_integral) > eps) {
        prev_integral = integral;  
        n *= 2;  
        h = (b - a) / n;
        integral = (cos(a) + cos(b)) / 2.0;

        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            integral += cos(x);
        }

        integral *= h;
    }

    return integral;
}


double trapezoidal_rule_by_sin(double a, double b, double eps) {
    int n = 2; 
    double h = (b - a) / n;
    double prev_integral = 0.0;
    double integral = (sin(a) + sin(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        integral += sin(x);
    }

    integral *= h;


    while (fabs(integral - prev_integral) > eps) {
        prev_integral = integral;  
        n *= 2;  
        h = (b - a) / n;
        integral = (sin(a) + sin(b)) / 2.0;

        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            integral += sin(x);
        }

        integral *= h;
    }

    return integral;
}
