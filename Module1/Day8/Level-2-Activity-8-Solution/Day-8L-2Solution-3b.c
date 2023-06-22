#include <stdio.h>
#include <stdlib.h>

struct Entry {
    int entry_no;
    char name[256];
    int age;
};

void delete_entry_by_entry_no(int entry_no) {
    FILE *f_read, *f_write;
    struct Entry entry;
    int i;

    f_read = fopen("data.csv", "r");
    if (f_read == NULL) {
        printf("Error opening file\n");
        return;
    }

    f_write = fopen("temp.csv", "w");
    if (f_write == NULL) {
        printf("Error opening file\n");
        return;
    }

    for (i = 0; i < 10; i++) {
        fscanf(f_read, "%d,%s,%d\n", &entry.entry_no, entry.name, &entry.age);
        if (entry.entry_no != entry_no) {
            fprintf(f_write, "%d,%s,%d\n", entry.entry_no, entry.name, entry.age);
        }
    }

    fclose(f_read);
    fclose(f_write);

    remove("data.csv");
    rename("temp.csv", "data.csv");
}

int main() {
    int entry_no;

    printf("Enter the EntryNo to delete: ");
    scanf("%d", &entry_no);

    delete_entry_by_entry_no(entry_no);

    printf("Entry deleted successfully\n");

    return 0;
}
