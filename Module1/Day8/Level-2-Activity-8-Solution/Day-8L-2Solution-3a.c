#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delete_entry_by_entry_no(int entry_no) {
    FILE *f_read, *f_write;
    char line[1024];

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

    while (fgets(line, sizeof(line), f_read)) {
        int current_entry_no;
        sscanf(line, "%d", &current_entry_no);
        if (current_entry_no != entry_no) {
            fputs(line, f_write);
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
