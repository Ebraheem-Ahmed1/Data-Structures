#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <ctime>
#include <string>
#include <fstream>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <vector>

using namespace std;

template <class A>
struct Node {
    A data;
    Node *next;
};

template <class A>
class list_ {
private:
    Node<A> *head;
public:
    list_() {
        head = NULL;
    }
    void add(A Data) {
        Node<A> *node = new Node<A>;
        node->data = Data;
        node->next = NULL;
        if (head == NULL) { head = node; }
        else { node = node->next; }
    }
    void remove() {
        for (auto i = head->next; i != NULL; i = i->next) {
            if (i->next == NULL) { delete i; }
        }
    }
};

template <class T>
class stack_{
private:
    list<T> a;
public:
    void push(T data) {
        a.push_back(data);
    }
    void pop() {
        a.pop_back();
    }
    T top() {
        return *a.end();
    }
    bool is_empty() {
        return a.empty();
    }
    bool search(T data) {
        for (auto i = a.begin(); i != a.end(); i++) {
            if (*i == data) {
                cout << "found" << endl;
                return true;
            }
        }
        cout << "not found" << endl;
        return false;
    }
    void print() {
        for (auto i = a.begin(); i != a.end(); i++) {
             cout<<*i<<" ";    
        }
    }
};

template <class E>
class queue_ {
private:
    list<E> a;
public:
    void add(E data) {
        a.push_back(data);
    }
    void remove() {
        a.pop_front();
    }
    bool is_empty() {
        return a.empty();
    }
    bool search(E data) {
        for (auto i = a.begin(); i != a.end(); i++) {
            if (*i == data) {
                cout << "found" << endl;
                return true;
            }
        }
        cout << "not found" << endl;
        return false;
    }
    void print() {
        for (auto i = a.begin(); i != a.end(); i++) {
            cout << *i << " ";
        }
    }
};

template <class B>
class disjoint_set {
private:
    B *set;
    int *id, n;
public:
    disjoint_set(int n) {
        set = new B[n];
        id = new int[n];
        this->n = n;
        make_set();
    }
    void make_set() {
        for (int i = 0; i < n; i++) {
            id[i] = i;
        }
    }
    void set_elements() {
        for (int i = 0; i < n; i++) {
            cin >> set[i];
        }
    }
    int find(int x) {
        if (id[x] != x)
            id[x] = find(id[x]);
        return id[x];
    }
    bool connected(B p, B q) {
        int root1 = find(p);
        int root2 = find(q);
        return root1 == root2;
    }
    int unify(B p, B q) {
        int root1 = find(p);
        int root2 = find(q);
        while (root1 != id[root1])
            root1 = id[root1];
        while (root2 != id[root2])
            root2 = id[root2];
        if (root1 == root2)
            return 0;
        return id[root1] > id[root2] ? id[root2] = id[root1] : id[root1] = id[root2];
    }
};

class BST {
    struct TNode {
        int data;
        TNode* left;
        TNode* right;
    };
private:
    TNode *root;
public:
    BST() {
        root = NULL;
    }
    TNode *digLeft(TNode *r) {
        while(r->left!=NULL)
           r = r->left;
        return r;
    }
    TNode *digRight(TNode *r) {
        while(r->right!=NULL)
           r = r->right;
        return r;
    }
    bool add(int Data) {
        TNode *node = new TNode;
        node->data = Data;
        node->left = NULL;
        node->right = NULL;
        if (search(Data) != 0)
            return false;
        while (true) {
            if (root == NULL) {
                root = node;
                return true;
            }
            else if (Data > root->data)
                root = root->right;
            else if (Data < root->data)
                root = root->left;
        }
    }
    TNode *search(int Data) {
        while (true) {
            if (root == NULL)
                return 0;
            else if (root->data == Data)
                return root;
            else if (Data > root->data)
                root = root->right;
            else if (Data < root->data)
                root = root->left;
        }
    }
    bool remove(int Data) {
        if (search(Data) == 0)
            return false;
        else {
            TNode* R = search(Data);
            if (R->left == NULL) {
                R = R->right;
                delete R;
            }
            else if (R->right == NULL) {
                R = R->left;
                delete R;
            }
            else {
                TNode* S = R->right;
                S = digLeft(S);
                R->data = S->data;
                delete S;
            }
            return true;
        }
    }
};

float calculator() {
    int n, m;
    cout << "enter a number: ";
    cin >> n;
    cout << "\nenter another: ";
    cin >> m;
    cout << "\nChoose Operation: \n";
    cout << "(+) (-) (*) (/) (DivisionRest) \n";
    string operation;
    cin >> operation;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "invalid input , pls re-enter an operation: \n";
        cin >> operation;
        if (cin.fail()) {
            cout << "invalid input";
        }
    }
    if (operation == "+")
        return n + m;
    else if (operation == "-")
        return n - m;
    else if (operation == "*")
        return n * m;
    else if (operation == "/")
        return n / m;
    else if (operation == "DivisionRest")
        return n % m;
    else
        cout << "invalid input";
}

int factorial(int n) {
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    std::cout << "Hello World!, I'm a new programmer called Ebraheem\n";

    

    return 0;
}
