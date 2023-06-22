#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Entry {
    int entry_no;
    char name[256];
    int age;
};

void update_entry_by_entry_no(int entry_no, char *new_name, int new_age) {
    FILE *f_read, *f_write;
    struct Entry entry;

    f_read = fopen("data.csv", "r");
    if (f_read == NULL) {
        printf("Error opening file\n");
        return;
    }

    f_write = fopen("temp.csv", "w");
    if (f_write == NULL) {
        printf("Error opening file\n");
        fclose(f_read);
        return;
    }

    while (fscanf(f_read, "%d,%[^,],%d\n", &entry.entry_no, entry.name, &entry.age) == 3) {
        if (entry.entry_no == entry_no) {
            strcpy(entry.name, new_name);
            entry.age = new_age;
        }
        fprintf(f_write, "%d,%s,%d\n", entry.entry_no, entry.name, entry.age);
    }

    fclose(f_read);
    fclose(f_write);

    remove("data.csv");
    rename("temp.csv", "data.csv");
}

int main() {
    int entry_no;
    char new_name[256];
    int new_age;

    printf("Enter the EntryNo to update: ");
    scanf("%d", &entry_no);

    printf("Enter the new name: ");
    scanf("%s", new_name);

    printf("Enter the new age: ");
    scanf("%d", &new_age);

    update_entry_by_entry_no(entry_no, new_name, new_age);

    printf("Entry updated successfully\n");

    return 0;
}
