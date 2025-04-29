#include <gtest/gtest.h>
#include "../include/task_utils.h"

TEST(TaskUtilsTest, CreateTaskSetsFieldsCorrectly) {
    Task t = createTask(1, "Write tests");
    EXPECT_EQ(t.id, 1);
    EXPECT_EQ(t.title, "Write tests");
    EXPECT_FALSE(t.completed);
}

TEST(TaskUtilsTest, ToggleCompleteWorks) {
    Task t = createTask(2, "Test toggle");
    toggleComplete(t);
    EXPECT_TRUE(t.completed);
    toggleComplete(t);
    EXPECT_FALSE(t.completed);
}

TEST(TaskUtilsTest, DeleteTaskRemovesCorrectly) {
    std::vector<Task> tasks = {
            createTask(1, "One"),
            createTask(2, "Two")
    };
    bool removed = deleteTask(tasks, 1);
    EXPECT_TRUE(removed);
    ASSERT_EQ(tasks.size(), 1);
    EXPECT_EQ(tasks[0].id, 2);
}

TEST(TaskUtilsTest, FilterCompletedReturnsOnlyDoneTasks) {
    std::vector<Task> tasks = {
            createTask(1, "One"),
            createTask(2, "Two")
    };
    toggleComplete(tasks[1]);
    auto done = filterCompleted(tasks);
    ASSERT_EQ(done.size(), 1);
    EXPECT_EQ(done[0].id, 2);
}
