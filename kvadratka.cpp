#include <stdio.h>
#include <math.h>

enum RET_VALUES {
    ZERO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 100,
};

int double_is_equal(double a, double b) {
    const double epsilon = 1e-6;
    return(fabs(a - b) <= epsilon);
}

int solve_linear_eq(double b, double c, double *answer){
    if (double_is_equal(b, 0)) {
        if (double_is_equal(c, 0)){
            return INF_ROOTS;
        }
        else {
            return ZERO_ROOTS;
        }
    }
    else {
        double x = 0;
        x = -c/b;
        *answer = x;
        return ONE_ROOT;
    }


}

int solve_quadratic_eq(double a, double b, double c, double *ans1, double *ans2) {
    double D = 0;
    D = b*b - 4*a*c;
    if (double_is_equal(D, 0)) {
        double x = 0;
        x = -b/(2*a);
        *ans1 = x;
        return ONE_ROOT;
    }
    else {
        if (D < 0) {
            return ZERO_ROOTS;
        }
        else {
            double x1 = 0, x2 = 0;
            x1 = (-b + sqrt(D))/2/a;
            x2 = (-b-sqrt(D))/2/a;
            *ans1 = x1;
            *ans2 = x2;
            return TWO_ROOTS;
        }
    }
}

int main(){
    double a = 0, b = 0, c = 0;
    printf("Please enter the coefficients of the equation you want to solve\n");
    int read_number = scanf("%lg %lg %lg", &a, &b, &c);

    while (read_number != 3){
        printf("Invalid coefficients! Try again!\n");

        while (getchar() != '\n'){
            continue;
        }

        read_number = scanf("%lg %lg %lg", &a, &b, &c);
    }

    double x1 = 0, x2 = 0;

    if (double_is_equal(a, 0)) {
        int linear_nroots = solve_linear_eq(b, c, &x1);

        switch (linear_nroots) {
            case INF_ROOTS:
                printf("Infinite number of roots!\n");
                break;
            case ONE_ROOT:
                printf("One root: %f\n", x1);
                break;
            case ZERO_ROOTS:
                printf("No roots!\n");
                break;
            default:
                printf("ERROR: Unexpected number of roots: %d\n", linear_nroots);
                break;
        }

    }
    else {
        int quad_nroots = solve_quadratic_eq(a, b, c, &x1, &x2);
        switch (quad_nroots){
            case TWO_ROOTS:
                printf("Two roots: %f, %f\n", x1, x2);
                break;
            case ONE_ROOT:
                printf("One root: %f\n", x1);
                break;
            case ZERO_ROOTS:
                printf("No roots!\n");
                break;
            default:
                printf("ERROR: Unexpected number of roots: %d\n", quad_nroots);
        }
   }
}

