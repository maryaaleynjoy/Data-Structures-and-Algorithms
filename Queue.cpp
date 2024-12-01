#include <iostream>
#include <queue>
#include <string>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;


class Person {
public:
    string name;
    int ticket_number;

    
    Person(string name, int ticket_number) : name(name), ticket_number(ticket_number) {}

    
    void display() const {
        cout << name << " (Ticket #" << setw(3) << setfill('0') << ticket_number << ")" << endl;
    }
};


class Queue {
private:
    queue<Person> q; 

public:
    
    void enqueue(const string& name) {
        int ticket_number = q.size() + 1; 
        Person person(name, ticket_number);
        q.push(person);
        cout << name << " added to the queue with Ticket #" << setw(3) << setfill('0') << ticket_number << endl;
        cout << "Queue size: " << q.size() << endl;
    }

    
    void auto_dequeue() {
        if (!is_empty()) {
            Person front_person = q.front();
            q.pop();
            cout << "\nAfter 1 minute...\n";
            cout << "Dequeue: " << front_person.name << " received a ticket (Ticket #" << setw(3) << setfill('0') << front_person.ticket_number << ")\n";
            cout << "Queue size: " << q.size() << endl;
            peek();  
        } else {
            cout << "The queue is empty, no tickets to issue!" << endl;
        }
    }

    
    bool is_empty() const {
        return q.empty();
    }

    
    int size() const {
        return q.size();
    }

   
    void peek() const {
        if (!is_empty()) {
            Person front_person = q.front();
            cout << "Next in line: " << front_person.name << " (Ticket #" << setw(3) << setfill('0') << front_person.ticket_number << ")" << endl;
        } else {
            cout << "The queue is empty!" << endl;
        }
    }

   
    void position(const string& identifier) {
        queue<Person> temp_queue = q;
        int pos = 1;  

        while (!temp_queue.empty()) {
            Person person = temp_queue.front();
            temp_queue.pop();

            if (person.name == identifier) {
                cout << identifier << " is currently at position " << pos << " in the queue." << endl;
                return;
            }
            pos++;
        }

        cout << identifier << " not found in the queue." << endl;
    }

    void position(int ticket_number) {
        queue<Person> temp_queue = q;
        int pos = 1;  

        while (!temp_queue.empty()) {
            Person person = temp_queue.front();
            temp_queue.pop();

            if (person.ticket_number == ticket_number) {
                cout << "Ticket #" << setw(3) << setfill('0') << ticket_number << " is currently at position " << pos << " in the queue." << endl;
                return;
            }
            pos++;
        }

        cout << "Ticket #" << setw(3) << setfill('0') << ticket_number << " not found in the queue." << endl;
    }
};


int main() {
    Queue concert_queue;
    int choice;
    string name_or_ticket;

    cout << "Welcome to Olivia Rodrigo's Concert Ticketing System!" << endl;

    while (true) {
        cout << "\n1. Enqueue a person\n";
        cout << "2. Check your position in the queue\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
           
            string name;
            cout << "Enter the name: ";
            cin.ignore(); 
            getline(cin, name);
            concert_queue.enqueue(name);

           
            this_thread::sleep_for(chrono::minutes(1));
            concert_queue.auto_dequeue();
        } 
        else if (choice == 2) {
           
            cout << "Enter your name or ticket number: ";
            cin.ignore();
            getline(cin, name_or_ticket);

            
            if (isdigit(name_or_ticket[0])) {
                
                int ticket_number = stoi(name_or_ticket);
                concert_queue.position(ticket_number);
            } else {
               
                concert_queue.position(name_or_ticket);
            }
        } 
        else if (choice == 3) {

            cout << "Exiting the ticketing system. Have a great time at the concert!" << endl;
            break;
        } 
        else {
            cout << "Invalid choice. Please try again!" << endl;
        }
    }

    return 0;
}
