#include <iostream>
#include <string>
using namespace std;

struct Moneybundle 
{
    string serialnumber;
    string currencytype;
    int billcount[3]; 
    Moneybundle* next;
};
class Moneystack {
private:
    Moneybundle* top;

public:
    Moneystack() {
    top= NULL;
}
void push(string serial , string currency, int bills[3]) {
        Moneybundle* newnode = new Moneybundle;
        newnode->serialnumber= serial;
        newnode->currencytype = currency;

        for (int i = 0; i< 3;i++)
            newnode->billcount[i] = bills[i];

        newnode->next = top;
        top = newnode;

        cout << "Money bundle added.\n";
    }
Moneybundle* pop() {
    if (top == NULL) {
        cout << "No money in safe!\n";
        return NULL;
}

    Moneybundle* temp= top;
    top = top->next;
    return temp;
}

void display() {
if (top ==NULL) {
cout << "Safe is empty.\n";
return;
}

Moneybundle* current = top;
cout << "\n--- Money Stack ---\n";

while (current != NULL) {
cout << "Serial: " << current->serialnumber;
cout << ", Currency: " << current->currencytype;
cout << ", [100s: " << current->billcount[0];
cout<< ", 50s: " << current->billcount[1];
cout<< ", 20s: " << current->billcount[2] << "]\n";

            current = current->next;
        }
    }
};

struct Customer {
    string customername;
    string transactiontype;
};

class Circularqueue {
private:
    Customer arr[5];
    int front;
    int rear;
    int count;

public:
    Circularqueue() {
        front = 0;
        rear= -1;
        count = 0;
    }
void enqueue(string name , string type) {
if (count ==5) {
cout << "Queue is full!\n";
return;
}

rear = (rear + 1) % 5;
arr[rear].customername = name;
arr[rear].transactiontype = type;
count++;
cout << "Customer added to queue.\n";
}
    Customer dequeue() {
        Customer empty = {"", ""};

if (count== 0) {
cout << "Queue is empty!\n";
return empty;
}

Customer temp = arr[front];
front = (front + 1) % 5;
count--;

return temp;
}

bool isEmpty() {
return count == 0;
    }

void display() {
    if (count == 0) {
        cout << "No customers waiting.\n";
        return;
}
cout << "\n--- Customer Queue ---\n";
    for (int i = 0; i < count; i++) {
        int index = (front + i) % 5;
        cout << arr[index].customername
             << " (" << arr[index].transactiontype << ")\n";
        }
    }
};

int main() {
    Moneystack safe;
Circularqueue queue;
    int bills1[3] = {10, 5, 2};
    int bills2[3] = {7, 3, 1};

    safe.push("A123", "TL", bills1);
    safe.push("B456", "USD", bills2);
queue.enqueue("Ali", "Withdraw");
queue.enqueue("Ayse", "Deposit");
safe.display();
queue.display();

cout << "\n--- Processing Transaction ---\n";
if (!queue.isEmpty()) {
        Customer c = queue.dequeue();
        Moneybundle* m = safe.pop();

        if (m != NULL) {
            cout << c.customername << " served using bundle "
     << m->serialnumber << endl;
delete m;
}
}
safe.display();
queue.display();

return 0;
}