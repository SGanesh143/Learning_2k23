#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LogEntry {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
};

void update_entry_by_entry_no(int entry_no, char *new_name, int new_age) {
    FILE *file;
    struct LogEntry entry;

    file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    FILE *tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL) {
        printf("Error opening file\n");
        fclose(file);
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d,%[^,],%f,%d,%d,%s",
               &entry.entryNo, entry.sensorNo, &entry.temperature,
               &entry.humidity, &entry.light, entry.timestamp);

        if (entry.entryNo == entry_no) {
         
            strncpy(entry.sensorNo, new_name, sizeof(entry.sensorNo));
            entry.humidity = new_age;
        }

        fprintf(tempFile, "%d,%s,%.1f,%d,%d,%s\n",
                entry.entryNo, entry.sensorNo, entry.temperature,
                entry.humidity, entry.light, entry.timestamp);
    }

   
    fclose(file);
    fclose(tempFile);

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
