#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to store each task
struct Task {
    string description;
    bool completed;
};

// Global vector to store tasks
vector<Task> todoList;

// Function to add a task
void addTask() {
    string taskDesc;
    cout << "Enter the task description: ";
    cin.ignore();
    getline(cin, taskDesc);
    Task newTask = {taskDesc, false};
    todoList.push_back(newTask);
    cout << "Task added successfully!\n";
}

// Function to view tasks
void viewTasks() {
    if (todoList.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < todoList.size(); i++) {
        cout << i + 1 << ". [" << (todoList[i].completed ? "✔" : " ") << "] "
             << todoList[i].description << "\n";
    }
}

// Function to mark a task as done
void markTaskDone() {
    int taskNum;
    cout << "Enter task number to mark as done: ";
    cin >> taskNum;
    if (taskNum < 1 || taskNum > todoList.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    todoList[taskNum - 1].completed = true;
    cout << "Task marked as done.\n";
}

// Function to delete a task
void deleteTask() {
    int taskNum;
    cout << "Enter task number to delete: ";
    cin >> taskNum;
    if (taskNum < 1 || taskNum > todoList.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    todoList.erase(todoList.begin() + taskNum - 1);
    cout << "Task deleted successfully.\n";
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n--- TO-DO LIST MENU ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTaskDone(); break;
            case 4: deleteTask(); break;
            case 5: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
