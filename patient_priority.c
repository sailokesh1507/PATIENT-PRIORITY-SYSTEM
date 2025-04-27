#include<stdio.h>
#include<stdlib.h>

struct patient {
    char name[20];
    int age;
    char case_type[20];
    int priority;
    struct patient* next;
};

struct patient* head = NULL;
struct patient* temp = NULL;

void clear_buffer() {
    while (getchar() != '\n'); // Clears any leftover characters from input
}

void appoint_patient() {
    struct patient* new_patient = (struct patient*)malloc(sizeof(struct patient));
    if (new_patient == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\n--- Appoint New Patient ---\n");
    printf("Enter patient name: ");
    scanf("%s", new_patient->name);
    clear_buffer();

    printf("Enter age: ");
    scanf("%d", &new_patient->age);
    clear_buffer();

    printf("Enter case type: ");
    scanf("%s", new_patient->case_type);
    clear_buffer();

    printf("Enter priority: ");
    scanf("%d", &new_patient->priority);
    clear_buffer();

    new_patient->next = NULL;

    if (head == NULL || new_patient->priority < head->priority) {
        new_patient->next = head;
        head = new_patient;
    } else {
        struct patient* current = head;
        while (current->next != NULL && current->next->priority <= new_patient->priority) {
            current = current->next;
        }
        new_patient->next = current->next;
        current->next = new_patient;
    }

    printf("Patient appointed successfully.\n");
}

void treat_patient() {
    if (head == NULL) {
        printf("\nNo patients to treat.\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("\n--- Treating Patient ---\n");
    printf("Name: %s\n", temp->name);
    printf("Age: %d\n", temp->age);
    printf("Case: %s\n", temp->case_type);
    printf("Priority: %d\n", temp->priority);

    free(temp);
    printf("Patient treatment complete.\n");
}

void display_records() {
    if (head == NULL) {
        printf("\nNo patients appointed.\n");
        return;
    }

    temp = head;
    printf("\n\t---- PATIENT RECORDS ----\n");
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Age: %d\n", temp->age);
        printf("Case: %s\n", temp->case_type);
        printf("Priority: %d\n", temp->priority);
        printf("-----------------------------\n");
        temp = temp->next;
    }
}

int main() {
    int choice;

    do {
        printf("\n\n\t---- OPTIONS ----\n");
        printf("1. Appoint Patient\n");
        printf("2. Treat Patient\n");
        printf("3. Display Records\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1:
                appoint_patient();
                break;
            case 2:
                treat_patient();
                break;
            case 3:
                display_records();
                break;
            case 4:
                printf("\nExiting... Have a nice day.\n");
                break;
            default:
                printf("\nInvalid Choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
