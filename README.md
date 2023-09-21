# Library Management System

This C++ program is a simple library management system that allows you to manage books and users. You can add books, search for books by prefix, print a list of users who borrowed a specific book, sort the library by ID or name, add users, and manage user book borrowing and returning.

## Usage

1. Compile and run the program.
2. Use the menu to select one of the following options:
   - Add a Book
   - Search Books by Prefix
   - Print Users Who Borrowed a Book
   - Print Library by ID
   - Print Library by Name
   - Add a User
   - User Borrow Book
   - User Return Book
   - Print Users
   - Exit

## Features

### 1. Add a Book

You can add a book to the library by providing its ID, name, and quantity. Books are stored in an array.

### 2. Search Books by Prefix

You can search for books by entering a prefix. The program will display all book names that match the prefix.

### 3. Print Users Who Borrowed a Book

Enter the book's name, and the program will display the names of users who have borrowed that book.

### 4. Print Library by ID

This option allows you to print the library's contents sorted by book ID.

### 5. Print Library by Name

This option allows you to print the library's contents sorted by book name.

### 6. Add a User

You can add a user to the system by providing their name and ID.

### 7. User Borrow Book

Users can borrow books by entering their name and the book's name. The program checks if the book is available and updates the book's borrowing count and quantity.

### 8. User Return Book

Users can return books by entering their name and the book's name. The program checks if the user has borrowed the book and updates the book's borrowing count and quantity.

### 9. Print Users

This option displays a list of users and the IDs of the books they have borrowed.

## Notes

- The program can handle up to 10 books and 10 users.
- Book and user information is stored in separate structures.
- Books are sorted by ID or name before printing.
- Users can borrow and return books, and the program tracks book quantities and user borrowing records.

Enjoy using this simple library management system!
