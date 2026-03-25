#include <iostream>
#include <string>
using namespace std;

struct Page {
    string url;
    string title;
    int accesstime[3]; 
    Page *next = nullptr;
    Page *prev = nullptr;
};

Page* head = nullptr;
Page* current = nullptr;

void visit(string u, string t, int h,int m,int s) {
    Page* newpage = new Page;
    newpage->url = u;
    newpage->title = t;
    newpage->accesstime[0] = h;
    newpage->accesstime[1] = m;
    newpage->accesstime[2] = s;

    if (head == nullptr) {
        head = newpage;
        current = head;
    } else {
        current->next = newpage;
        newpage->prev = current;
        current = newpage;
    }
    cout << "Visited: "<< t << endl;
}
void goBack() {
    if (current && current->prev) {
        current = current->prev;
        cout << "Moved back current: " << current->title << endl;
    } else {
        cout << "No previous page" << endl;
    }
}

void goForward() {
    if (current && current->next) {
        current = current->next;
        cout << "Moved forward      Current: " << current->title << endl;
    } else {
        cout << "No next page in history!" << endl;
    }
}

void deleteentry() {
    if (!current) return;

    Page* todelete = current;
    cout << "Deleting page: " << todelete->title << endl;

if (todelete->prev) todelete->prev->next = todelete->next;
if (todelete->next)todelete->next->prev =todelete->prev;
if (todelete== head) head= todelete->next;
if(todelete->prev) current= todelete->prev;
else current =todelete->next;
delete todelete;
}
void displayHistory(){
    cout << "\n--- BROWSER HISTORY ---" << endl;
    for (Page* temp = head; temp != nullptr; temp = temp->next) {
        if (temp == current) cout << " [ACTIVE] -> ";
        else cout << "           ";
        cout << temp->title << " (" << temp->url << ") | Time: ";
        for (int i =0; i < 3;i++) {
            if(temp->accesstime[i] < 10) cout <<"0"; 
            cout << temp->accesstime[i] << (i < 2 ? ":" :"");
        }
      cout << endl;
    }
 cout << "-----------------------\n";
}

int main() {
visit("google.com", "Google", 14, 0, 5);
visit("github.com", "Github", 14, 10, 30);
visit("openai.com", "Openai", 14,15, 45);
displayHistory();
goBack();        
deleteentry();      
displayHistory();

string command;
cout << "Type EXIT to exit: ";
cin >> command;

if (command == "EXIT") {
    Page* temp = head;
    while (temp != nullptr) {
        Page* nextNode = temp->next;
    delete temp;
        temp = nextNode;
}
cout << "All memory cleared. Program terminated." << endl;
}

return 0;
}