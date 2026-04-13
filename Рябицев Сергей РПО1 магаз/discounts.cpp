#include "discounts.h"
#include <iostream>

double TotalSumDiscount(double& totalSum) {
    if (totalSum >= 75000.0) {
        std::cout << "\nСкидка при сумме чека от 75000 руб. - скидка 18%!\n";
        return totalSum * 0.82;
    }
    else if (totalSum >= 35000.0) {
        std::cout << "\nСкидка при сумме чека от 35000 руб. - скидка 12%!\n";
        return totalSum * 0.88;
    }
    return totalSum;
}

double QuantityDiscount(double& totalSum) {
    extern size_t checkSize;
    if (checkSize >= 4) {
        std::cout << "\nСкидка за покупку 4 и более разных товаров - скидка 15%!\n";
        return totalSum * 0.85;
    }
    else if (checkSize >= 2) {
        std::cout << "\nСкидка за покупку 2 и более разных товаров - скидка 8%!\n";
        return totalSum * 0.92;
    }
    return totalSum;
}

double Discounts(double& totalSum) {
    double discountedSum = totalSum;
    discountedSum = TotalSumDiscount(discountedSum);
    discountedSum = QuantityDiscount(discountedSum);
    if (discountedSum < 0) {
        discountedSum = 0;
    }
    return discountedSum;
}