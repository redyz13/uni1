#include <stdio.h>

float calculate_commission(float rate, float quote, float value);

int main() {
    float commission, value;

    printf("Enter value of trade: ");
    scanf("%f", &value);

    if(value < 2500.00f) {
        commission = calculate_commission (30.00f, .017f, value);
    }
    else if(value < 6250.00f) {
        commission = calculate_commission(56.00f, .0066f, value);
    }
    else if(value < 20000.00f) {
        commission = calculate_commission(76.00f, .0034f, value) ;
    }
    else if(value < 50000.00f) {
        commission = calculate_commission(100.00f, .0022f, value) ;
    }
    else if(value < 500000.00f){
     commission = calculate_commission(155.00f, .0011f, value);   
    }
    else {
        commission = calculate_commission(255.00f, .0009f, value);
    }

    if(commission < 39.00f) {
        commission = 39.00f;
    }

    printf("Commission: $%.2f\n", commission);

    return 0;
}

float calculate_commission(float rate, float quote, float value) {
    return (rate + quote * value);
}
