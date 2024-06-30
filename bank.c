#include <stdio.h>

struct account {
    int account_number;
    float balance;
};

void create_account(struct account *a) {
    printf("Enter account number: ");
    scanf("%d", &a->account_number);
    printf("Enter initial balance: ");
    scanf("%f", &a->balance);
}

void deposit(struct account *a) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if(amount<=0)
    {printf(" Invalid \n");
    return;}
    a->balance += amount;
    printf("Balance updated: %.2f\n", a->balance);
}

void withdraw(struct account *a) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if( amount <=0)
    {printf("Amount should be Greater Than 1 \n");
    return;}
     if (a->balance >= amount) {
        a->balance -= amount;
        printf("Balance updated: %.2f\n", a->balance);
    } else {
        printf("Insufficient balance\n");
    }
}

void display_balance(struct account *a) {
    printf("Account number: %d\n", a->account_number);
    printf("Balance: %.2f\n", a->balance);
}

int main() {
    struct account a;
    create_account(&a);
    int choice;
    while (1) {
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Display balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                deposit(&a);
                break;
            case 2:
                withdraw(&a);
                break;
            case 3:
                display_balance(&a);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}