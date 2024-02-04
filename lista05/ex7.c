#include <stdio.h>
#include <math.h>

double evaluatePolynomial(int n, double coefficients[], double x) {
    double result = 0.0;
    int i;
    for (i = 0; i <= n; i++)
        result += coefficients[i] * pow(x, i);
    return result;
}

double bisectionMethod(int n, double coefficients[], double a, double b, double epsilon) {
    double fa = evaluatePolynomial(n, coefficients, a);
    double fb = evaluatePolynomial(n, coefficients, b);

    if (fa * fb > 0)
        return NAN;

    double root;
    while ((b - a) > epsilon) {
        double c = (a + b) / 2;
        double fc = evaluatePolynomial(n, coefficients, c);

        if (fc == 0.0) {
            root = c;
            break;
        } else if (fa * fc < 0) {
            b = c;
        } else {
            a = c;
            fa = fc;
        }
    }

    root = (a + b) / 2;
    return root;
}

int main() {
    int n;
    int i;
    double epsilon;
    scanf("%d %lf", &n, &epsilon);

    double a, b;
    scanf("%lf %lf", &a, &b);

    double coefficients[n + 1];
    for (i = 0; i <= n; i++)
        scanf("%lf", &coefficients[i]);

    double root = bisectionMethod(n, coefficients, a, b, epsilon);
    printf("%.6lf\n", root);

    return 0;
}