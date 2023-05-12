//Muhanned Hasan 2200000776
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Structure to represent a product
struct Product {
    char name[10];
    float unitPrice;
    float kiloPrice;
};

// Array of products
struct Product products[] = {
    {"peach", 1.15, 5.99},
    {"pear", 0.99, 4.99},
    {"plum", 1.50, 4.50}
};

// Function to find the index of a product in the array based on the product number
int find_part(int number) {
    int size = sizeof(products) / sizeof(products[0]);
    for (int i = 0; i < size; i++) {
        if (i + 1 == number) {
            return i;
        }
    }
    return -1;
}

// Function to calculate the total price of a product
float totalPrice(float amount, float listPrice) {
    return amount * listPrice;
}

// Function to apply discount on the total price based on the quantity
float discount(float total, int amount) {
    float discountPercentage = 0.0;
    if (amount >= 2 && amount <= 4) {
        discountPercentage = 0.05;
    }
    else if (amount >= 5 && amount <= 9) {
        discountPercentage = 0.10;
    }
    else if (amount > 10) {
        discountPercentage = 0.15;
    }
    return total - (total * discountPercentage);
}

int main() {
    char choice;
    float payment = 0.0;

    do {
        int productNumber, quantity;
        int amountType;
        float total;

        printf("Enter the product number (1 for peach, 2 for pear, 3 for plum): ");
        scanf("%d", &productNumber);

        printf("Enter 1 for amount, 2 for kilogram: ");
        scanf("%d", &amountType);

        if (amountType == 1) {
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            int index = find_part(productNumber);
            if (index != -1) {
                total = totalPrice(quantity, products[index].unitPrice);
                total = discount(total, quantity);
                payment += total;
                printf("\nThe total is $%.2f\n\n", total);
            }
            else {
                printf("\nInvalid product number!\n\n");
            }
        }
        else if (amountType == 2) {
            float kilograms;
            printf("How many kilograms: ");
            scanf("%f", &kilograms);
            int index = find_part(productNumber);
            if (index != -1) {
                total = totalPrice(kilograms, products[index].kiloPrice);
                payment += total;
                printf("\nThe total is $%.2f\n\n", total);
            }
            else {
                printf("\nInvalid product number!\n\n");
            }
        }

        printf("Do you want to buy something else? (Y/N): ");
        scanf(" %c", &choice);
        printf("\n");
    } while (choice == 'Y' || choice == 'y');

    printf("You must pay $%.2f\n", payment);

    return 0;
}

