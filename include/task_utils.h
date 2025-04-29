#pragma once
#include "task.h"
#include <vector>


Task createTask(int id, const std::string& title);
void toggleComplete(Task& task);
bool deleteTask(std::vector<Task>& tasks, int id);
std::vector<Task> filterCompleted(const std::vector<Task>& tasks);