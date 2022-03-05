#include <stdio.h>

int main() {
    float commission, value;

    printf("Enter value of trade: ");
    scanf("%f", &value);

    (value > 500000.00f) ? (commission = 255.00f + .0009f * value) : 0;
    (value < 500000.00f) ? (commission = 155.00f + .0011f * value) : 0;
    (value < 50000.00f) ? (commission = 100.00f + .0022f * value) : 0;
    (value < 20000.00f) ? (commission = 76.00f + .0034f * value) : 0;
    (value < 6250.00f) ? (commission = 56.00f + .0066f * value) : 0;
    (value < 2500.00f) ? (commission = 30.00f + .017f * value) : 0;

    (commission < 39.00f) ? (commission = 39.00f) : 0;

    printf("Commission: $%.2f\n", commission);

    return 0;
}
