# 📌 Study Tracker CLI (C)

A menu-driven CLI task manager built in C supporting full CRUD operations with persistent file storage.

---

## 🚀 Features
- Add tasks  
- View tasks  
- Mark tasks as completed  
- Edit tasks  
- Delete tasks  
- Persistent storage using file handling  

---

## 🛠 Tech Stack
- C
- File Handling
- Command Line Interface (CLI)

---

## ▶️ How to Run

```bash
gcc main.c -o tracker
.\tracker.exe
```
##📂 Project Structure
study-tracker-cli/
│── main.c
│── README.md
│── .gitignore

## ⚙️ Implementation Details
- Tasks stored using structures in C
- Data persisted using file I/O (`fopen`, `fprintf`, `fscanf`)
- Menu-driven control flow using loops and switch-case

##🧪 Example Run
1
Enter task: Study DSA

2
1. [PENDING] Study DSA

3
Enter task id: 1

2
1. [DONE] Study DSA
   
##💡 Key Features
Menu-driven CLI system
CRUD operations implemented from scratch
Persistent data storage using tasks.txt
Simple and efficient design

##⚠️ Notes
tasks.txt is generated automatically for storing tasks locally
Not included in Git

##📈 Future Improvements
Add priority levels
Add due dates
Search/filter tasks
Improve UI
👤 Author

Yash

