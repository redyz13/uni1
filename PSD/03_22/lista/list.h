typedef struct Node *Node;

Node newNode(int x);
int getValue(Node n);
void printList(Node head);
void addEnd(Node *head, int x);
void addFront(Node *head, int x);
