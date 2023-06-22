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

void swap(struct LogEntry *a, struct LogEntry *b) {
    struct LogEntry temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening data file.\n");
        return 1;
    }

    struct LogEntry logEntries[100];
    int numEntries = 0;

    char line[100];
    int entryCount = 0;

    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) != NULL) {
        struct LogEntry entry;
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,]",
               &entry.entryNo, entry.sensorNo, &entry.temperature,
               &entry.humidity, &entry.light, entry.timestamp);
        logEntries[entryCount] = entry;
        entryCount++;

        if (entryCount >= 100) {
            printf("Maximum number of entries exceeded.\n");
            break;
        }
    }

    numEntries = entryCount;

    fclose(file);

    
    for (int i = 0; i < numEntries - 1; i++) {
        for (int j = 0; j < numEntries - i - 1; j++) {
            if (logEntries[j].temperature < logEntries[j + 1].temperature) {
                swap(&logEntries[j], &logEntries[j + 1]);
            }
        }
    }

   
    file = fopen("data_sorted.csv", "w");
    if (file == NULL) {
        printf("Error creating sorted data file.\n");
        return 1;
    }

    fprintf(file, "EntryNo,sensorNo,Temperature,Humidity,Light,Timestamp\n");
    for (int i = 0; i < numEntries; i++) {
        fprintf(file, "%d,%s,%.1f,%d,%d,%s\n",
                logEntries[i].entryNo, logEntries[i].sensorNo,
                logEntries[i].temperature, logEntries[i].humidity,
                logEntries[i].light, logEntries[i].timestamp);
    }

    fclose(file);

    printf("Data sorted and written to data_sorted.csv.\n");

    return 0;
}
