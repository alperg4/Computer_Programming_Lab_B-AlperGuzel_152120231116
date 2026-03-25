#include <iostream>
#include <string>

using namespace std;

struct Node {
    string songTitle;
    Node* next;
};

class Playlist {
private:
Node* head;

public:

Playlist() {
head = nullptr;
}

    void addSong(string title) {
        Node* newNode = new Node();
        newNode->songTitle = title;
        newNode->next = head;
        head = newNode;
        cout <<  title << " Song added\n";
    }

void searchSong(string title) {
    Node* current = head;
    while (current != nullptr) {
    if (current->songTitle == title) {
        cout << "Found: '" << title << " Exist\n";
                return;
            }
            current = current->next;
        }
        cout << "Not Found: " << title << " Doesn't exist\n";
    }

void listSongs() {
    if (head == nullptr) {
    cout << "Playlist empty\n";
return;}

        Node* current = head;
        int order = 1;

cout << "\n--- Playlist ---\n";
    while (current != nullptr) {
        cout << order << ". " << current->songTitle << "\n";
        current = current->next;
        order++;
        }
        cout << "---------------------\n";
    }
};

int main() {
    Playlist myPlaylist;
    int choice;
    string songName;

    do {
        cout << "\n=== Playlist menu ===\n";
        cout << "1. Add song\n";
        cout << "2. Search song\n";
        cout << "3. List\n";
        cout << "4. Exit\n";
        cout << "Choose (1-4): ";
        
        if (!(cin >> choice)) {
            cout << "Please enter valid number\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Name of the new song: ";
                getline(cin, songName);
                myPlaylist.addSong(songName);
                break;
            case 2:
                cout << "Song's name? ";
                getline(cin, songName);
                myPlaylist.searchSong(songName);
                break;
            case 3:
                myPlaylist.listSongs();
                break;
            case 4:
                cout << "exiting program\n";
                break;
            default:
                cout << "Please enter valid number\n";
        }
    } while (choice != 4);

    return 0;
}