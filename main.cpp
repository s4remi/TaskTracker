#include <iostream>
#include "include/task_utils.h"

void printTasks(const std::vector<Task>& tasks) {
    for (const auto& task : tasks) {
        std::cout << task.id << ": " << task.title
                  << (task.completed ? " [✔ Done]" : " [ ] Pending") << std::endl;
    }
}
int main() {
    std::vector<Task> tasks;

    std::cout << "=== Creating Tasks ===" << std::endl;
    tasks.push_back(createTask(1, "Set up Google Test"));
    tasks.push_back(createTask(2, "Write some unit tests"));
    tasks.push_back(createTask(3, "Fix bugs"));
    printTasks(tasks);

    std::cout << "\n=== Marking Task 2 as Done ===" << std::endl;
    toggleComplete(tasks[1]); // Mark second task as done
    printTasks(tasks);

    std::cout << "\n=== Deleting Task 1 ===" << std::endl;
    if (deleteTask(tasks, 1)) {
        std::cout << "Task 1 deleted successfully." << std::endl;
    } else {
        std::cout << "Task 1 not found." << std::endl;
    }
    printTasks(tasks);

    std::cout << "\n=== Showing Completed Tasks Only ===" << std::endl;
    std::vector<Task> completedTasks = filterCompleted(tasks);
    printTasks(completedTasks);
    return 0;
}
