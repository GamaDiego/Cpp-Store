#include <stdio.h>
#include <iostream>
#include <cmath>

int main() {
    //Bills and coins
    int fiftyBills = 0;
    int twentyBills = 0;
    int tenBills = 0;
    int fiveBills = 0;
    int oneBills = 0;
    int quarterCoins = 0;
    int dimeCoins = 0;
    int nickelCoins = 0;
    int pennyCoins = 0;
    float tax = 9.25f;
    float subtotal = 0;
    float total = 0;
    
    //Used structure to store my list items
    struct {
        std::string item;
        float price;
        int number = 0;         //Number of items bought
    } myItem1, myItem2, myItem3, myItem4, myItem5, myItem6, myItem7, myItem8, myItem9, myItem10;
    
    myItem1.item = "Motherboard";
    myItem1.price = 150;
    myItem2.item = "CPU";
    myItem2.price = 312;
    myItem3.item = "Graphics Card";
    myItem3.price = 799.99;
    myItem4.item = "CPU Cooler";
    myItem4.price = 65;
    myItem5.item = "RAM Sticks";
    myItem5.price = 99.99;
    myItem6.item = "SSD";
    myItem6.price = 159.99;
    myItem7.item = "Power Supply";
    myItem7.price = 120;
    myItem8.item = "Fans";
    myItem8.price = 12.99;
    myItem9.item = "Case";
    myItem9.price = 109.99;
    myItem10.item = "Sound Card";
    myItem10.price = 149.99;
    
    //Print list items and prices
    std::cout << "\nWelcome! Please select your items by typing the item number or type 0 to check out!" << std::endl;
    std::cout << "\t\t1.\t" << myItem1.item << ": $" << myItem1.price << std::endl;
    std::cout << "\t\t2.\t" << myItem2.item << ": $" << myItem2.price << std::endl;
    std::cout << "\t\t3.\t" << myItem3.item << ": $" << myItem3.price << std::endl;
    std::cout << "\t\t4.\t" << myItem4.item << ": $" << myItem4.price << std::endl;
    std::cout << "\t\t5.\t" << myItem5.item << ": $" << myItem5.price << std::endl;
    std::cout << "\t\t6.\t" << myItem6.item << ": $" << myItem6.price << std::endl;
    std::cout << "\t\t7.\t" << myItem7.item << ": $" << myItem7.price << std::endl;
    std::cout << "\t\t8.\t" << myItem8.item << ": $" << myItem8.price << std::endl;
    std::cout << "\t\t9.\t" << myItem9.item << ": $" << myItem9.price << std::endl;
    std::cout << "\t\t10.\t" << myItem10.item << ": $" << myItem10.price << std::endl;
    std::cout << "" << std::endl;
    
    //While loop that allows user to keep shopping until 0 is input
    bool flag = false;
    while (flag == false) {
        int itemNumber;
        std::cin >> itemNumber;
        if (itemNumber == 1) {
            myItem1.number++;
            std::cout << "\t\tYou added 1 Motherboard to your cart" << std::endl;
            subtotal = subtotal + myItem1.price;
            continue;
        }
        if (itemNumber == 2) {
            myItem2.number++;
            std::cout << "\t\tYou added 1 CPU to your cart" << std::endl;
            subtotal = subtotal + myItem2.price;
            continue;
        }
        if (itemNumber == 3) {
            myItem3.number++;
            std::cout << "\t\tYou added 1 Graphics Card to your cart" << std::endl;
            subtotal = subtotal + myItem3.price;
            continue;
        }
        if (itemNumber == 4) {
            myItem4.number++;
            std::cout << "\t\tYou added 1 CPU Cooler to your cart" << std::endl;
            subtotal = subtotal + myItem4.price;
            continue;
        }
        if (itemNumber == 5) {
            myItem5.number++;
            std::cout << "\t\tYou added 1 RAM Stick to your cart" << std::endl;
            subtotal = subtotal + myItem5.price;
            continue;
        }
        if (itemNumber == 6) {
            myItem6.number++;
            std::cout << "\t\tYou added 1 SSD to your cart" << std::endl;
            subtotal = subtotal + myItem6.price;
            continue;
        }
        if (itemNumber == 7) {
            myItem7.number++;
            std::cout << "\t\tYou added 1 Power Supply to your cart" << std::endl;
            subtotal = subtotal + myItem7.price;
            continue;
        }
        if (itemNumber == 8) {
            myItem8.number++;
            std::cout << "\t\tYou added 1 Fan to your cart" << std::endl;
            subtotal = subtotal + myItem8.price;
            continue;
        }
        if (itemNumber == 9) {
            myItem9.number++;
            std::cout << "\t\tYou added 1 Case to your cart" << std::endl;
            subtotal = subtotal + myItem9.price;
            continue;
        }
        if (itemNumber == 10) {
            myItem10.number++;
            std::cout << "\t\tYou added 1 Sound Card to your cart" << std::endl;
            subtotal = subtotal + myItem10.price;
            continue;
        }
        if (itemNumber == 0) {
            std::cout << "\t\tThank you for shopping with us!" << std::endl;
            flag = true;
        }
        /*if (itemNumber < 0) {
            std::cout << "\t\tPlease enter a valid number" << std::endl;
            continue;
        }*/
    }
    
    total = (subtotal * (tax / 100)) + subtotal;
    //Round total amount up to 2 decimals
    //total = std::ceil(total * 100.0) / 100.0;
    total = round(total * 100) / 100;
    
    std::cout << "\nThe total amount due is $" << total << std::endl;
    
    std::cout << "Enter the amount paid:" << std::endl;
    
    float moneyPaid;
    std::cin >> moneyPaid;
    //Enters while loop if user enters less money than the amount due
    while (moneyPaid < total) {
        std::cout << "Please enter a valid amount of money (higher than " << total << ")" << std::endl;
        std::cin >> moneyPaid;
    }
    
    float remainingBalance = moneyPaid - total;
    remainingBalance = round(remainingBalance * 100) / 100;
    
    std::cout << "\nYou paid $" << moneyPaid << " and your change is: $" << remainingBalance << std::endl;
    
    /* Calculate the amount of bills and coins */
    while (remainingBalance >= 50) {
        remainingBalance = remainingBalance - 50;
        fiftyBills++;
    }
    while (remainingBalance >= 20) {
        remainingBalance = remainingBalance - 20;
        twentyBills++;
    }
    while (remainingBalance >= 10) {
        remainingBalance = remainingBalance - 10;
        tenBills++;
    }
    while (remainingBalance >= 5) {
        remainingBalance = remainingBalance - 5;
        fiveBills++;
    }
    while (remainingBalance >= 1) {
        remainingBalance = remainingBalance - 1;
        oneBills++;
    }
    while (remainingBalance >= 0.25) {
        remainingBalance = remainingBalance - 0.25;
        quarterCoins++;
    }
    while (remainingBalance >= 0.10) {
        remainingBalance = remainingBalance - 0.10;
        dimeCoins++;
    }
    while (remainingBalance >= 0.05) {
        remainingBalance = remainingBalance - 0.05;
        nickelCoins++;
    }
    while (remainingBalance >= 0.01) {
        remainingBalance = remainingBalance - 0.01;
        pennyCoins++;
    }
    
    /* Print out the results */
    if (fiftyBills > 0) {
        std::cout << fiftyBills << " $50 bills, ";
    }
    if (twentyBills > 0) {
        std::cout << twentyBills << " $20 bills, ";
    }
    if (tenBills > 0) {
        std::cout << tenBills << " $10 bills, ";
    }
    if (fiveBills > 0) {
        std::cout << fiveBills << " $5 bills, ";
    }
    if (oneBills > 0) {
        std::cout << oneBills << " $1 bills, ";
    }
    if (quarterCoins == 1) {
        std::cout << quarterCoins << " quarter, ";
    } else if (quarterCoins > 1) {
        std::cout << quarterCoins << " quarters, ";
    }
    if (dimeCoins == 1) {
        std::cout << dimeCoins << " dime, ";
    } else if (dimeCoins > 1) {
        std::cout << dimeCoins << " dimes, ";
    }
    if (nickelCoins == 1) {
        std::cout << nickelCoins << " nickel, ";
    } else if (nickelCoins >= 1) {
        std::cout << nickelCoins << " nickels, ";
    }
    if (pennyCoins == 1) {
        std::cout << pennyCoins << " penny." << std::endl;
    } else if (pennyCoins >= 1) {
        std::cout << pennyCoins << " pennies." << std::endl;
    }
    
    //Ask users if they want a receipt
    std::cout << "Would you like your receipt? (Y/N)" << std::endl;
    bool receipt;
    char answer;
    std::cin >> answer;
    
    if (toupper(answer) == 'Y') {
        receipt = true;
    } else {
        receipt = false;
    }
    
    //Print receipt if user wants a receipt
    if (receipt == true) {
        std::cout << "\n\n\t\t\t\tRECEIPT" << std::endl;
        std::cout << "\t------------------------------" << std::endl;
        std::cout << "ITEMS BOUGHT:" << std::endl;
        if (myItem1.number > 0) {
            std::cout << myItem1.item << " x" << myItem1.number << " ($" << (myItem1.price * myItem1.number) << ")" << std::endl;
        }
        if (myItem2.number > 0) {
            std::cout << myItem2.item << " x" << myItem2.number << " ($" << (myItem2.price * myItem2.number) << ")" << std::endl;
        }
        if (myItem3.number > 0) {
            std::cout << myItem3.item << " x" << myItem3.number << " ($" << (myItem3.price * myItem3.number) << ")" << std::endl;
        }
        if (myItem4.number > 0) {
            std::cout << myItem4.item << " x" << myItem4.number << " ($" << (myItem4.price * myItem4.number) << ")" << std::endl;
        }
        if (myItem5.number > 0) {
            std::cout << myItem5.item << " x" << myItem5.number << " ($" << (myItem5.price * myItem5.number) << ")" << std::endl;
        }
        if (myItem6.number > 0) {
            std::cout << myItem6.item << " x" << myItem6.number << " ($" << (myItem6.price * myItem6.number) << ")" << std::endl;
        }
        if (myItem7.number > 0) {
            std::cout << myItem7.item << " x" << myItem7.number << " ($" << (myItem7.price * myItem7.number) << ")" << std::endl;
        }
        if (myItem8.number > 0) {
            std::cout << myItem8.item << " x" << myItem8.number << " ($" << (myItem8.price * myItem8.number) << ")" << std::endl;
        }
        if (myItem9.number > 0) {
            std::cout << myItem9.item << " x" << myItem9.number << " ($" << (myItem9.price * myItem9.number) << ")" << std::endl;
        }
        if (myItem10.number > 0) {
            std::cout << myItem10.item << " x" << myItem10.number << " ($" << (myItem10.price * myItem10.number) << ")" << std::endl;
        }
        std::cout << "\t------------------------------" << std::endl;
        std::cout << "SUBTOTAL: $" << subtotal << std::endl;
        std::cout << "TAX: " << tax << "% ($" << (subtotal * (tax / 100)) << ")" << std::endl;
        std::cout << "TOTAL: $" << total << std::endl;
    }
}
