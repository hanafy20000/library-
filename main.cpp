#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
  int id;
  string title;
  string author;
  bool available;

public:
  // Constructor to initialize available status to true
  Book() : available(true) {}

  // Setter methods
  void setID(int id)
  {
    this->id = id;
  }

  void setTitle(string title)
  {
    this->title = title;
  }

  void setAuthor(string author)
  {
    this->author = author;
  }

  void setAvailable(bool available)
  {
    this->available = available;
  }

  //* Getter methods
  int getID()
  {
    return id;
  }

  string getTitle()
  {
    return title;
  }

  string getAuthor()
  {
    return author;
  }

  bool isAvailable()
  {
    return available;
  }
};

class Library
{
private:
  static  const int MAX_BOOKS = 100;
  Book *books[MAX_BOOKS];
  int numBooks = 0;

public:
  // Method to add a book to the library
  void addBook()
  {
    if (numBooks < MAX_BOOKS)
    {
      Book *newBook = new Book();
      int id;
      string title;
      string author;

      //* Input book details from user
      cout << "Enter Book ID : ";
      cin >> id;
      newBook->setID(id);

      cout << "Enter Book Title : ";
      cin >> title;
      newBook->setTitle(title);

      cout << "Enter Book Author : ";
      cin >> author;
      newBook->setAuthor(author);

      newBook->setAvailable(true);

      // Add the new book to the array of books in the library
      books[numBooks] = newBook;
      numBooks++;
      cout << "Book added successfully" << endl;
    }
    else
    {
      cout << "Library is full Cannot add more books" << endl;
    }
  }

  //* Method to remove a book from the library based on its ID
  void removeBook(int id)
  {
    for (int i = 0; i < numBooks; i++)
    {
      if (books[i]->getID() == id)
      {
        delete books[i];
        for (int j = i; j < numBooks - 1; j++)
        {
          books[j] = books[j + 1];
        }
        numBooks--;
        cout << "Book removed successfully" << endl;
        return;
      }
    }
    cout << "Book not found" << endl;
  }

  // Method to update a specific book by its ID
  void updateBook(int id)
  {
    for (int i = 0; i < numBooks; i++)
    {
      if (books[i]->getID() == id)
      {
        int newId;
        string newTitle;
        string newAuthor;

        cout << "Enter new details for the book :" << endl;
        cout << "Enter new ID : ";
        cin >> newId;
        cout << "Enter new Title : ";
        cin >> newTitle;
        cout << "Enter new Author : ";
        cin >> newAuthor;
        //* Set the new values for the book
        books[i]->setID(newId);
        books[i]->setTitle(newTitle);
        books[i]->setAuthor(newAuthor);

        cout << "Book updated successfully" << endl;
        return;
      }
    }
    cout << "Book not found" << endl;
  }

  // Method to borrow a book from the library based on its ID
  void borrowBook(int id)
  {
    for (int i = 0; i < numBooks; i++)
    {
      if (books[i]->getID() == id)
      {
        if (books[i]->isAvailable())
        {
          books[i]->setAvailable(false);
          cout << "Book borrowed successfully" << endl;
        }
        else
        {
          cout << "Book is already borrowed" << endl;
        }
        return;
      }
    }
    cout << "Book not found" << endl;
  }

  // Method to return a book to the library based on its ID
  void returnBook(int id)
  {
    for (int i = 0; i < numBooks; i++)
    {
      if (books[i]->getID() == id)
      {
        if (books[i]->isAvailable() == false)
        {
          books[i]->setAvailable(true);
          cout << "Book returned successfully" << endl;
        }
        else
        {
          cout << "Book is already available" << endl;
        }
        return;
      }
    }
    cout << "Book not found" << endl;
  }

  // Method to display all available books in the library
  void displayAvailableBooks()
  {
    if (numBooks > 0)
    {
      cout << "Available Books :" << endl;
      for (int i = 0; i < numBooks; i++)
      {
        if (books[i]->isAvailable())
        {
          cout << "ID : " << books[i]->getID() << " | Title : " << books[i]->getTitle() << " | Author : " << books[i]->getAuthor() << endl;
        }
      }
      cout << "==================" << endl;
    }
    else
    {
      cout << "Library is empty" << endl;
    }
  }
};

// Main function to interact with the library
int main()
{
  Library library;

  int choice;
  int id;
  // do something
  do
  {
    // Display menu options
    cout << "Menu:\n";
    cout<<"1. Add a new book " << endl;
    cout << "2. Remove a book " << endl;
    cout << "3. Borrow a book " << endl;
    cout << "4. Return a book " << endl;
    cout << "5. Display all available books " << endl;
    cout << "6. Update a book " << endl;
    cout << "7. Exit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      library.addBook();
      break;


    case 2:
      cout << "Enter Book ID to remove: ";
      cin >> id;
      library.removeBook(id);
      break;


    case 3:
      cout << "Enter Book ID to borrow: ";
      cin >> id;
      library.borrowBook(id);
      break;


    case 4:
      cout << "Enter Book ID to return: ";
      cin >> id;
      library.returnBook(id);
      break;
    case 5:


      library.displayAvailableBooks();
      break;
    case 6:


      cout << "Enter Book ID to Update : ";
      cin >> id;
      library.updateBook(id);
      break;
    case 7:


      cout << "Exiting program" << endl;
      break;
    default:
      cout << "Invalid choice Please try again" << endl;
    }
  }
  while (choice != 7);

  return 0;
}



