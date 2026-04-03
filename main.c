#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Task {
    int id;
    char title[100];
    int completed;
};

struct Task tasks[MAX];
int count = 0;

// Load tasks from file
void loadTasks() {
    FILE *fp = fopen("tasks.txt", "r");
    if (fp == NULL) return;

    while (fscanf(fp, "%d %[^\n] %d\n",
                  &tasks[count].id,
                  tasks[count].title,
                  &tasks[count].completed) != EOF) {
        count++;
    }
    fclose(fp);
}

// Save tasks to file
void saveTasks() {
    FILE *fp = fopen("tasks.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %d\n",
                tasks[i].id,
                tasks[i].title,
                tasks[i].completed);
    }
    fclose(fp);
}

// Add task
void addTask() {
    printf("Enter task: ");
    getchar();
    fgets(tasks[count].title, 100, stdin);
    tasks[count].title[strcspn(tasks[count].title, "\n")] = 0;

    tasks[count].id = count + 1;
    tasks[count].completed = 0;

    count++;
    saveTasks();
}

// View tasks
void viewTasks() {
    printf("\nTasks:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. [%s] %s\n",
               tasks[i].id,
               tasks[i].completed ? "DONE" : "PENDING",
               tasks[i].title);
    }
}

// Mark complete
void completeTask() {
    int id;
    printf("Enter task id: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (tasks[i].id == id) {
            tasks[i].completed = 1;
            break;
        }
    }
    saveTasks();
}

void deleteTask() {
    int id;
    printf("Enter task id to delete: ");
    scanf("%d", &id);

    int found = 0;

    for (int i = 0; i < count; i++) {
        if (tasks[i].id == id) {
            found = 1;

            for (int j = i; j < count - 1; j++) {
                tasks[j] = tasks[j + 1];
            }

            count--;
            printf("Task deleted.\n");
            break;
        }
    }

    if (!found)
        printf("Task not found.\n");

    saveTasks();
}

void editTask() {
    int id;
    printf("Enter task id to edit: ");
    scanf("%d", &id);
    getchar(); // clear buffer

    for (int i = 0; i < count; i++) {
        if (tasks[i].id == id) {
            printf("Enter new task: ");
            fgets(tasks[i].title, 100, stdin);
            tasks[i].title[strcspn(tasks[i].title, "\n")] = 0;

            printf("Task updated.\n");
            saveTasks();
            return;
        }
    }

    printf("Task not found.\n");
}


// Menu
int main() {
    int choice;
    loadTasks();

    while (1) {
        printf("\n1. Add Task\n2. View Tasks\n3. Complete Task\n4. Delete Task\n5. Edit Task\n6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
    case 1: addTask(); break;
    case 2: viewTasks(); break;
    case 3: completeTask(); break;
    case 4: deleteTask(); break;
    case 5: editTask(); break;
    case 6: exit(0);
    default: printf("Invalid choice\n");
}
    }
}