
![Build and Test](https://github.com/s4remi/TaskTracker/actions/workflows/cross-platform-ci.yml/badge.svg)


# Task Tracker (C++)

A lightweight, procedural-style task tracking application written in C++.  
This project demonstrates core C++ concepts such as struct-based design, function modularity, and unit testing with Google Test.

---

## 📚 Features
- Add new tasks
- Mark tasks as completed
- Delete tasks by ID
- Filter completed tasks
- Simple CLI display of tasks
- Full unit testing coverage using Google Test

---

## 🛠 Technologies Used
- C++20
- CMake (build system)
- Google Test (unit testing, integrated via FetchContent)
- CLion IDE (development)

---

## 🧰 Project Structure

task_tracker/ <br>
├── include/ # Header files (task.h, task_utils.h) <br>
├── src/ # Implementation files (task_utils.cpp)<br>
├── test/ # Google Test unit tests (task_tests.cpp) <br>
├── main.cpp # CLI entry point <br>
├── CMakeLists.txt # Build configuration <br>
└── .gitignore # Git ignore rules<br>


---

##  Build Instructions (Terminal)

### Prerequisites
- CMake 3.16+ installed
- C++17/20 compatible compiler (GCC, Clang, or MSVC)

### Build and Run
```bash
# Clone the project
git clone https://github.com/yourusername/task-tracker-cpp.git
cd task-tracker-cpp

# Create a build directory
mkdir build
cd build

# Configure the project
cmake ..

# Build the project
make

# Run the main application
./task_manager

# Run unit tests
./task_tests
