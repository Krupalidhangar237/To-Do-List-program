#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to store each task with its status
struct Task {
    string description;
    bool isCompleted;
};

// Function to add a task
void addTask(vector<Task> &tasks) {
    string taskDesc;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, taskDesc);
    tasks.push_back({taskDesc, false});
    cout << "Task added successfully!\n";
}

// Function to view tasks
void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to show.\n";
        return;
    }

    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description << " ["
             << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
    }
}
// Function to mark a task as completed
void markTaskCompleted(vector<Task> &tasks) {
    int taskNumber;
    viewTasks(tasks);

    if (!tasks.empty()) {
        cout << "Enter task number to mark as completed: ";
        cin >> taskNumber;

        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].isCompleted = true;
            cout << "Task marked as completed.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }
}

// Function to remove a task
void removeTask(vector<Task> &tasks) {
    int taskNumber;
    viewTasks(tasks);

    if (!tasks.empty()) {
        cout << "Enter task number to remove: ";
        cin >> taskNumber;

        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task removed.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }
}
// Main menu
void showMenu() {
    cout << "\n--- TO-DO LIST MENU ---\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        showMenu();
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addTask(tasks);
            break;
        case 2:
            viewTasks(tasks);
            break;
        case 3:
            markTaskCompleted(tasks);
            break;
        case 4:
            removeTask(tasks);
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);
    return 0;
}
