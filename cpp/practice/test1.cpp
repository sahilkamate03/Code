#include <iostream>
#include <string>

// Define a node in the linked list
struct BookNode {
  std::string title;
  std::string author;
  std::string ISBN;
  bool isAvailable;
  BookNode *next;
};

// Define the linked list class
class BookList {
  public:
    BookList();  // Constructor
    ~BookList();  // Destructor

    // Add a new book to the list
    void addBook(std::string title, std::string author, std::string ISBN);

    // Search for a book by title
    BookNode* searchByTitle(std::string title);

    // Search for a book by ISBN
    BookNode* searchByISBN(std::string ISBN);

    // Mark a book as available or unavailable
    void setAvailability(std::string ISBN, bool isAvailable);

  private:
    BookNode *head;  // Pointer to the first node in the list
};

// Constructor
BookList::BookList() {
  head = nullptr;
}

// Destructor
BookList::~BookList() {
  // Delete each node in the list
  BookNode *current = head;
  while (current != nullptr) {
    BookNode *next = current->next;
    delete current;
    current = next;
  }
}

// Add a new book to the list
void BookList::addBook(std::string title, std::string author, std::string ISBN) {
  // Create a new node for the book
  BookNode *newNode = new BookNode;
  newNode->title = title;
  newNode->author = author;
  newNode->ISBN = ISBN;
  newNode->isAvailable = true;
  newNode->next = nullptr;

  // Add the node to the end of the list
  BookNode *current = head;
  if (current == nullptr) {
    // The list is empty, so the new node is the first node
    head = newNode;
  } else {
    // Find the last node in the list
    while (current->next != nullptr) {
      current = current->next;
    }
    // Add the new node to the end of the list
