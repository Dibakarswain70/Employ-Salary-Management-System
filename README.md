# Employ-Salary-Management-System
Employee Salary Management System (C Program)

This project is a menu-driven Employee Salary Management System written in the C programming language. It allows users to efficiently manage employee salary records using file handling. The system is easy to use, lightweight, and runs on any C compiler.

Features

Add Employee: Store employee details including salary components.

Automatic Salary Calculation: Computes Gross Salary (Basic + HRA + DA).

View All Employees: Displays all saved employee records.

Search Employee: Find an employee by their ID.

Delete Employee: Remove a record safely using a temporary file mechanism.

Persistent Storage: Uses a binary file (employee.dat) to save data permanently.

Technologies Used

C Programming Language

File Handling (fopen, fwrite, fread, etc.)

Structures (struct Employee)

Menu-driven console interface

How to Run

Copy the source code into a .c file (e.g., employee_system.c)

Compile using any C compiler:

gcc employee_system.c -o employee_system


Run the program:

./employee_system

Use Cases

Small businesses managing payroll

Academic projects

Learning C file handling and structures
