#include <cstdio>
#include <cmath>

int main()
{
    // 1. prompt user to enter coefficients
    std::puts("please enter a and b for 'ax^2+bx+c=0':");

    // 2. read coefficients for equation `ax^2+bx+c=0`
    float a = 0;
    float b = 0;
    float c = 0;
    std::scanf("%f %f %f", &a, &b, &c);

    if (a == 0)
    {
        std::printf("kornei net!");
    }
    else
    {
        float Deskriminant = b * b - 4 * a * c;
        if (Deskriminant < 0)
        {
            std::puts("kornei net!");
        }
        if (Deskriminant == 0)
        {
            float x = -b / c;
            std::printf("answer: %.2f\n", x);
        }
        if (Deskriminant > 0)
        {
            Deskriminant = sqrt(Deskriminant);
            float x1 = (-b + Deskriminant) / (2 * a);
            float x2 = (-b - Deskriminant) / (2 * a);

            std::printf("answer1: %.2f\n", x1);
            std::printf("answer2: %.2f\n", x2);
        }
    }
}