# libman
#Library Management System

##Overview

This project is a simple Library Management System written in C. It allows you to manage a collection of books, including adding new books, borrowing, and returning them. It also tracks the total number of copies and available copies for each book.

##Features

1. Add a Book: Input book details like title, author, and total copies. Each book is assigned a unique Serial Number (SINO).


2. Display Books: View a list of all available books, showing their title, author, total copies, and the number of available copies.


3. Borrow a Book: Borrow a book by specifying its title and author. The system decreases the available copies and provides a 14-day due date.


4. Return a Book: Return a borrowed book by specifying its title and author, which increases the available copies.


5. Simple Input: Input for books is limited to title and author to manage the library without user-specific data.



##Structure

Book Structure:

Serial Number (SINO)

Title

Author

Total Copies

Available Copies

Borrowed Count



##Files

library.c: The main program file containing all functionality such as adding books, borrowing, returning, and displaying the book collection.


##How to Run

Prerequisites

C Compiler: You need a C compiler (like GCC) installed to compile the project.

Terminal: A terminal or command prompt to run the compiled program.


##Instructions

1. Clone or download the project files.


2. Open the terminal and navigate to the folder containing the project file.


3. Compile the C program using the following command:

gcc -o library library.c


4. Run the compiled program:

./library



##Usage

Once you run the program, a menu will appear with the following options:

Add Book: Add a new book to the library.

Display Books: Display all the books in the library with details like title, author, total copies, and available copies.

Borrow Book: Borrow a book by specifying its title and author. The program will provide a due date (14 days from borrowing).

Return Book: Return a borrowed book by providing the title and author.

Exit: Close the program.


Example Output

Library Management System
1. Add Book
2. Display Books
3. Borrow Book
4. Return Book
5. Exit
Enter your choice: 2
SINO    Title           Author          Total Copies    Available Copies
1       The Alchemist    Paulo Coelho    10              10

##Future Improvements

Adding user management to track which users have borrowed books.

Implementing a system for fines based on due dates.

Expanding the search functionality to find books more efficiently.
