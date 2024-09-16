#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool isCompleted;

    Task(std::string desc) : description(desc), isCompleted(false) {}
};
void displayMenu() {
    std::cout << "\nTo-Do List Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Delete Task\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}
void addTask(std::vector<Task>& tasks) {
    std::string taskDescription;
    std::cout << "Enter task description: ";
    std::cin.ignore(); 
    std::getline(std::cin, taskDescription);
    tasks.push_back(Task(taskDescription));
    std::cout << "Task added successfully!\n";
}
void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to display.\n";
        return;
    }
    std::cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description << " ["
                  << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";

    }

}
void markTaskCompleted(std::vector<Task>& tasks) {
    int taskNumber;
    viewTasks(tasks);
    if (tasks.empty()) return;


    std::cout << "Enter the task number to mark as completed: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].isCompleted = true;
        std::cout << "Task marked as completed!\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}


void deleteTask(std::vector<Task>& tasks) {
    int taskNumber;
    viewTasks(tasks);
    
    if (tasks.empty()) return;

    std::cout << "Enter the task number to delete: ";
    std::cin >> taskNumber;


    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + (taskNumber - 1));
        std::cout << "Task deleted successfully!\n";
    } else {
    
        std::cout << "Invalid task number.\n";
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

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
                deleteTask(tasks);
                break;
            case 5:
                std::cout << "Exiting To-Do List Manager.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

