#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BOOKS 100
#define TITLE_SIZE 100
#define AUTHOR_SIZE 100

struct Book
{
    int sino;
    char title[TITLE_SIZE];
    char author[AUTHOR_SIZE];
    int totalCopies;
    int availableCopies;
    int borrowedCount;
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void addBook()
{
    if (bookCount >= MAX_BOOKS)
    {
        printf("Library is full.\n");
        return;
    }
    struct Book *newBook = &library[bookCount++];
    newBook->sino = bookCount;
    printf("Enter book title: ");
    getchar();
    fgets(newBook->title, TITLE_SIZE, stdin);
    newBook->title[strcspn(newBook->title, "\n")] = '\0';
    printf("Enter author name: ");
    fgets(newBook->author, AUTHOR_SIZE, stdin);
    newBook->author[strcspn(newBook->author, "\n")] = '\0';
    printf("Enter total copies: ");
    scanf("%d", &newBook->totalCopies);
    newBook->availableCopies = newBook->totalCopies;
    newBook->borrowedCount = 0;
    printf("Book added!\n");
}

void displayBooks()
{
    if (bookCount == 0)
    {
        printf("No books available.\n");
        return;
    }
    printf("SINO\t\Title\t\tAuthor\t\tTotal Copies\tAvailable Copies\n");
    for (int i = 0; i < bookCount; i++)
    {
        printf("%d\t%s\t\t%s\t\t%d\t\t%d\n", library[i].sino, library[i].title, library[i].author, library[i].totalCopies, library[i].availableCopies);
    }
}

void manageBook(const char *action)
{
    char title[TITLE_SIZE];
    char author[AUTHOR_SIZE];
    printf("Enter book title: ");
    getchar();
    fgets(title, TITLE_SIZE, stdin);
    title[strcspn(title, "\n")] = '\0';
    printf("Enter author name: ");
    fgets(author, AUTHOR_SIZE, stdin);
    author[strcspn(author, "\n")] = '\0';
    int foundBook = -1;
    for (int i = 0; i < bookCount; i++)
    {
        if (strcasecmp(library[i].title, title) == 0 && strcasecmp(library[i].author, author) == 0)
        {
            foundBook = i;
            break;
        }
    }
    if (foundBook == -1)
    {
        printf("Book not found.\n");
        return;
    }
    struct Book *book = &library[foundBook];
    if (strcmp(action, "borrow") == 0)
    {
        if (book->availableCopies > 0)
        {
            book->availableCopies--;
            book->borrowedCount++;
            time_t t = time(NULL);
            struct tm *dueDate = localtime(&t);
            dueDate->tm_mday += 14;
            mktime(dueDate);
            printf("Borrowed \"%s\" by %s. Due: %02d-%02d-%d. Available: %d\n", book->title, book->author, dueDate->tm_mday, dueDate->tm_mon + 1, dueDate->tm_year + 1900, book->availableCopies);
        }
        else
        {
            printf("No copies available.\n");
        }
    }
    else if (strcmp(action, "return") == 0)
    {
        if (book->totalCopies > book->availableCopies)
        {
            book->availableCopies++;
            book->borrowedCount--; // Decrement the global borrowed count
            printf("Returned \"%s\" by %s. Available: %d\n", book->title, book->author, book->availableCopies);
        }
        else
        {
            printf("This book was not borrowed.\n");
        }
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                manageBook("borrow");
                break;
            case 4:
                manageBook("return");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
