#include "../include/task_utils.h"

// Create a task with given id and title
Task createTask(int id, const std::string& title) {
    return Task{id, title, false};
}

// Toggle completion status
void toggleComplete(Task& task) {
    task.completed = !task.completed;
}

// Delete task by ID
bool deleteTask(std::vector<Task>& tasks, int id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            tasks.erase(it);
            return true;
        }
    }
    return false;
}

// Return completed tasks only
std::vector<Task> filterCompleted(const std::vector<Task>& tasks) {
    std::vector<Task> result;
    for (const auto& task : tasks) {
        if (task.completed) {
            result.push_back(task);
        }
    }
    return result;
}
