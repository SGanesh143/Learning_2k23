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

int main() {
  FILE *file;
  struct LogEntry entries[100];
  int numEntries = 0;
  int entryNoToUpdate;


  file = fopen("data.csv", "r");
  if (file == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  char line[100];
  while (fgets(line, sizeof(line), file)) {
  
    char *fields[6];
    int n = 0;
    fields[n++] = strtok(line, ",");
    while (fields[n] != NULL) {
      fields[n++] = strtok(NULL, ",");
    }


    struct LogEntry entry;
    entry.entryNo = atoi(fields[0]);
    strcpy(entry.sensorNo, fields[1]);
    entry.temperature = atof(fields[2]);
    entry.humidity = atoi(fields[3]);
    entry.light = atoi(fields[4]);
    strcpy(entry.timestamp, fields[5]);

    entries[numEntries++] = entry;
  }

  
  printf("Enter the EntryNo to update: ");
  scanf("%d", &entryNoToUpdate);

  
  int entryFound = 0;
  for (int i = 0; i < numEntries; i++) {
    if (entries[i].entryNo == entryNoToUpdate) {
   
      entries[i].temperature = 25.0;  
      entryFound = 1;
      break;
    }
  }


  fclose(file);

  if (entryFound) {
    
    file = fopen("data.csv", "w");
    if (file == NULL) {
      printf("Error opening file.\n");
      exit(1);
    }


    for (int i = 0; i < numEntries; i++) {
      fprintf(file, "%d,%s,%.1f,%d,%d,%s\n",
              entries[i].entryNo, entries[i].sensorNo, entries[i].temperature,
              entries[i].humidity, entries[i].light, entries[i].timestamp);
    }

 
    fclose(file);

    printf("Entry updated successfully.\n");
  } 
  else 
  {
    printf("Entry with EntryNo %d not found.\n", entryNoToUpdate);
  }

  return 0;
}
