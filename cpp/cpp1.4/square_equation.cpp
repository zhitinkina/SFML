#include <cstdio>
#include <cmath>

int main()
{
    // 1. prompt user to enter coefficients
    std::puts("Please enter a, b and c:");

    // 2. read coefficients for equation `ax^2+bx+c=0`
    float a = 0;
    float b = 0;
    float c = 0;
    std::scanf("%f %f %f", &a, &b, &c);

    if (a == 0)
    {
        std::printf("There r no roots!");
    }
    else
    {
        float deskriminant = b * b - 4 * a * c;
        if (deskriminant < 0)
        {
            std::printf("There r no roots!");
        }
        if (deskriminant == 0)
        {
            float x = -b / c;
            std::printf("x: %.2f\n", x);
        }
        if (deskriminant > 0)
        {
            deskriminant = std::sqrt(deskriminant);
            float x1 = (-b + deskriminant) / (2 * a);
            float x2 = (-b - deskriminant) / (2 * a);

            std::printf("x1: %.2f\n", x1);
            std::printf("x2: %.2f\n", x2);
        }
    }
}