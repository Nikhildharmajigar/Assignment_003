#include <iostream>
using namespace std;

struct Node {
    int row, col, val;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    void insert(int row, int col, int val) {
        Node* temp = new Node;
        temp->row = row;
        temp->col = col;
        temp->val = val;
        temp->next = head;
        head = temp;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "(" << temp->row << ", " << temp->col << ", " << temp->val << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class SparseMatrix {
private:
    int size;
    LinkedList* matrix;
public:
    SparseMatrix(int size) {
        this->size = size;
        matrix = new LinkedList[size];
    }

    void insert(int row, int col, int val) {
        if (val != 0) {
            matrix[row].insert(row, col, val);
        }
    }

    void printMatrix() {
        for (int i = 0; i < size; i++) {
            cout << "Row " << i << ": ";
            matrix[i].printList();
        }
    }
};

int main() {
    SparseMatrix m(5);
    m.insert(0, 0, 3);
    m.insert(0, 1, 9);
    m.insert(1, 2, 19);
    m.insert(2, 2, 10);
    m.insert(3, 3, 37);
    m.insert(4, 2, -49);

    m.printMatrix();

    return 0;
}
