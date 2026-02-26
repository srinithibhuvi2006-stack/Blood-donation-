#include <stdio.h>
#include <string.h>

struct Donor {
    int id;
    char name[50];
    int age;
    char bloodGroup[5];
    char phone[15];
};

/* Preloaded 5 Donors */
struct Donor donors[100] = {
    {101, "Ravi Kumar", 25, "O+", "9876543210"},
    {102, "Suresh Babu", 30, "A+", "9123456780"},
    {103, "Priya Sharma", 22, "B+", "9988776655"},
    {104, "Anita Das", 28, "AB+", "9090909090"},
    {105, "Karthik Raj", 35, "O-", "9345678901"}
};

int count = 5;

/* Function to show donor ID list */
void showDonorList() {
    printf("\n===== Donor ID List =====\n");

    for (int i = 0; i < count; i++) {
        printf("ID: %d   | Name: %s\n", donors[i].id, donors[i].name);
    }
}

/* Function to show full details when ID selected */
void viewDonorDetails() {
    int selectedID;
    int found = 0;

    showDonorList();

    printf("\nEnter Donor ID to view full details: ");
    scanf("%d", &selectedID);

    for (int i = 0; i < count; i++) {
        if (donors[i].id == selectedID) {
            printf("\n===== Full Donor Details =====\n");
            printf("ID: %d\n", donors[i].id);
            printf("Name: %s\n", donors[i].name);
            printf("Age: %d\n", donors[i].age);
            printf("Blood Group: %s\n", donors[i].bloodGroup);
            printf("Phone: %s\n", donors[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nDonor ID not found!\n");
    }
}

/* Main Function */
int main() {
    int choice;

    do {
        printf("\n===== Blood Bank Management System =====");
        printf("\n1. View Donor List (Select ID to see details)");
        printf("\n2. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewDonorDetails();
                break;
            case 2:
                printf("\nExiting Program...\n");
                break;
            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 2);

    return 0;
}