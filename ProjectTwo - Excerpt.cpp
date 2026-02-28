//============================================================================
// Name        : ProjectTwo - Excerpt.cpp
// Author      : John Brandolini
// Version     : 1.0
// Copyright   : Copyright   2026 SNHU COCE
// Description : Project 2 - Excerpt (Sort and Display Course List code only)
//               Several lines were removed for clarity and to prevent use as 
//               boilerplate for other student assignments.  Redacted code will
//               be indicated by three dots, e.g. ...
//============================================================================


#include <iostream>
#include <time.h>
...
#include <string>

...

using namespace std;

/**
 * Define a structure containing data members and methods to
 * represent a course
 */
struct Course {
    
    ...
    
    /**
    * displays the course on a single line, followed by an end of line character
    */
    void display() {
        std::cout << this->courseNumber << ", " <<
            this->courseTitle << std::endl;
    }

    ...

};

/**
 * Defines a structure containing data members and methods to
 * implement a binary search tree's node
 */
 // Internal structure for tree node
struct Node {
    Course course;
    Node* left;
    Node* right;
    
    ...

};

//============================================================================
// Binary Search Tree class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a binary search tree
 */
class BinarySearchTree {

private:
    Node* root;

    ...

    void inOrder(Node* node);

    ...

public:

    void InOrder();
    ...    
};

...

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
    // Traverse "in order" from root
    inOrder(root);
}

...

/**
 *  Recursively traverses tree in order, meaning recursively traverses left first, displays course, then recursively traverses right
 *
 *  @param node Node to be traversed recursively from
 */
void BinarySearchTree::inOrder(Node* node) {
    if (node != nullptr) { // Only do this if not null
        // Recursively traverse left node in order
        inOrder(node->left);
        // Print the current nodes course to the screen using the display function
        node->course.display();
        // Recursively traverse right node in order
        inOrder(node->right);
    }
}

...

/**
 * Display Course List
 *
 * @param bst Binary search tree to load courses into
 * @param debug boolean indicating whether or not to display debug information
 */
static void displayCourseList(BinarySearchTree* bst, bool debug) {
    // Define a timer variable
    clock_t ticks;

    // Initialize a timer variable before displaying the courses
    ticks = clock();

    std::cout << "Here is a sample schedule:" << std::endl << std::endl;
    bst->InOrder();

    if (debug) {
        // Calculate elapsed time and display result
        ticks = clock() - ticks; // current clock ticks minus starting clock ticks
        std::cout << std::endl << "time: " << ticks << " clock ticks" << endl;
        std::cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << std::endl;
    }
}

/**
 * Gets a numeric value, discarding invalid input and retrying until a valid value is provided
 *
 * @returns valid number from standard input via cin
 */
static int getValidChoice() {
    int num;
    while (true) {
        if (std::cin >> num) {
            // Input was successful, break the loop
            break;
        }
        else {
            // Input failed
            std::cout << "Invalid input. Please try again." << std::endl;
            // Clear the error state flag
            std::cin.clear();
            // Discard the input buffer up to the newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return num;
}


int main(int argc, char* argv[])
{
    ...

    // Define a binary search tree to hold all the courses
    BinarySearchTree* bst;
    bst = new BinarySearchTree();

    int choice = 0;
    std::cout << "Welcome to the course planner." << std::endl;
    bool debug = false;
    
    while (choice != 9) {
        std::cout << std::endl;
        ...
        std::cout << "  2. Print Course List." << std::endl;
        ...
        std::cout << "  9. Exit" << std::endl;
        std::cout << "What would you like to do? ";

        choice = getValidChoice();

        switch (choice) {

        ...

        case 2:
            // Display the Course List
            displayCourseList(bst, debug);
            break;

	...

        case 9:
            break;

        default:
            std::cout << choice << " is not a valid option." << std::endl;
            break;

        }
    }

    cout << "Thank you for using the course planner!" << endl;

    return 0;
}