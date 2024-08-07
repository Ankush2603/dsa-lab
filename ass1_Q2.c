#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct SavingsAccount {
    char accountHolderName[50];
    int accountNumber;
    float balance;
};

const float MIN_BALANCE = 1000.0;

void deposit(struct SavingsAccount *account, float amount) {
    account->balance += amount;
    printf("Rs. %.2f deposited successfully!\n", amount);
}

void withdraw(struct SavingsAccount *account, float amount) {
    if (account->balance - amount >= MIN_BALANCE) {
        account->balance -= amount;
        printf("Rs. %.2f withdrawn successfully!\n", amount);
    } else {
        printf("Insufficient balance to withdraw Rs. %.2f\n", amount);
    }
}

void calculateAndDepositInterest(struct SavingsAccount *account, float annualInterestRate) {
    float interest = (account->balance * annualInterestRate) / 100.0;
    account->balance += interest;
    printf("Interest of Rs. %.2f deposited to account %d\n", interest, account->accountNumber);
}

int main() {
    srand(time(NULL));

    const int numAccounts = 10;
    struct SavingsAccount accounts[numAccounts];

    for (int i = 0; i < numAccounts; ++i) {
        sprintf(accounts[i].accountHolderName, "Account Holder %d", i + 1);
        accounts[i].accountNumber = i + 1;
        accounts[i].balance = rand() % 99001 + 1000;
    }

    float annualInterestRate = 5.0;

    float totalInterestPaid = 0.0;
    for (int i = 0; i < numAccounts; ++i) {
        calculateAndDepositInterest(&accounts[i], annualInterestRate);
        totalInterestPaid += (accounts[i].balance - (accounts[i].balance / (1 + (annualInterestRate/100))));
    }

    printf("\nTotal interest paid to all accounts in one year: Rs. %.2f\n", totalInterestPaid);

    return 0;
}
