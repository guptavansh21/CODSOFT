import os

# Task list ko store karne ke liye ek simple list
tasks = []

def show_menu():
    """Menu options display karega"""
    print("\n--- TODO LIST APP (CODSOFT) ---")
    print("1. Add Task")
    print("2. View Tasks")
    print("3. Mark Task as Done")
    print("4. Delete Task")
    print("5. Exit")

def view_tasks():
    """Saare tasks ko list karega status ke saath"""
    print("\n--- YOUR TASKS ---")
    if not tasks:
        print("Empty List! Koi task add karo.")
    else:
        for index, task in enumerate(tasks):
            status = "[x]" if task['completed'] else "[ ]"
            print(f"{index + 1}. {status} {task['title']}")

def add_task():
    """Naya task add karega"""
    title = input("Enter task name: ")
    tasks.append({"title": title, "completed": False})
    print("✅ Task added successfully!")

def mark_done():
    """Task ko completed mark karega"""
    view_tasks()
    if tasks:
        try:
            task_num = int(input("\nEnter task number to mark done: "))
            if 1 <= task_num <= len(tasks):
                tasks[task_num - 1]['completed'] = True
                print("✅ Task marked as completed!")
            else:
                print("❌ Invalid number!")
        except ValueError:
            print("❌ Please enter a valid number.")

def delete_task():
    """Task ko delete karega"""
    view_tasks()
    if tasks:
        try:
            task_num = int(input("\nEnter task number to delete: "))
            if 1 <= task_num <= len(tasks):
                removed = tasks.pop(task_num - 1)
                print(f"🗑️ Task '{removed['title']}' deleted!")
            else:
                print("❌ Invalid number!")
        except ValueError:
            print("❌ Please enter a valid number.")

def main():
    while True:
        show_menu()
        choice = input("Enter your choice (1-5): ")

        if choice == '1':
            add_task()
        elif choice == '2':
            view_tasks()
        elif choice == '3':
            mark_done()
        elif choice == '4':
            delete_task()
        elif choice == '5':
            print("Exiting... Bye! 👋")
            break
        else:
            print("❌ Invalid choice, try again.")

if __name__ == "__main__":
    main()