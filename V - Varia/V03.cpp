//Code by Katarzyna Ludwa

#include <iostream>
 
using namespace std;
 
struct Person {
    string name;
    Person* N[2];
    Person() : name("") {
        N[0] = N[1] = nullptr;
    }
    Person(string name, Person* a, Person* b) : name(name) {
        N[0] = a;
        N[1] = b;
    };
 
};
 
struct Train {
    Train* Ne;
    string name;
    Person* head = new Person();
    Train() : Ne(nullptr), name("Thead") {};
    Train(string trainName, string personName) : Ne(nullptr), name(trainName) {
        head->N[0] = head->N[1] = new Person(personName, head, head);
    }
 
    ~Train() {
        Person* next = head->N[0];
        Person* prev = head;
        while (next != head && next != nullptr) {
            Person* tmp = next;
            bool temp = next->N[0] != prev;
            next = next->N[temp];
            if (prev != head) delete prev;
            prev = tmp;
        }
    }
 
    void add_back(string personName) {
        Person* last = head->N[1];
        bool temp = (last->N[0] != head);
        head->N[1] = last->N[temp] = new Person(personName, head, last);
    }
 
    void add_front(string personName) {
        Person* first = head->N[0];
        bool temp = (first->N[0] != head);
        head->N[0] = first->N[temp] = new Person(personName, head, first);
    }
 
    void print() {
        Person* next = head->N[0];
        Person* prev = head;
        cout << '\"' << name << "\":\n";
        while (next != head->N[1]) {
            cout << next->name << "<-";
            Person* temp = next;
            next = (next->N[0] == prev) ? next->N[1] : next->N[0];
            prev = temp;
        }
        cout << next->name << "\n";
    }
 
    void reverse() {
        Person* temp = head->N[0];
        head->N[0] = head->N[1];
        head->N[1] = temp;
    }
};
 
struct Party {
    Train* trains = new Train;
 
    ~Party() {
        Train* temp = trains;
        while (temp->Ne != nullptr) {
            Train* tmp = temp->Ne;
            delete temp;
            temp = tmp;
        }
    }
 
    void add(string trainName, string personName) {
        Train* newTrain = trains;
        while (newTrain->Ne != nullptr) {
            newTrain = newTrain->Ne;
        }
 
        newTrain->Ne = new Train(trainName, personName);
    }
 
    void back(string trainName, string personName) {
        find(trainName)->add_back(personName);
    }
 
    void front(string trainName, string personName) {
        find(trainName)->add_front(personName);
    }
 
    void print(string trainName) {
        Train* train = find(trainName);
        train->print();
    }
 
    void reverse(string trainName) {
        Train* train = find(trainName);
        train->reverse();
    }
 
    void merge(string trainName1, string trainName2) {
        Train* train1 = find(trainName1);
        Train* train2 = find(trainName2);
 
        Person* last = train1->head->N[1];
        Person* first = train2->head->N[0];
 
        bool temp = last->N[0] != train1->head;
        last->N[temp] = first;
 
        temp = first->N[0] != train2->head;
        first->N[temp] = last;
 
        last = train2->head->N[1];
        temp = last->N[0] != train2->head;
        last->N[temp] = train1->head;
 
        train1->head->N[1] = last;
        train2->head->N[0] = train2->head->N[1] = nullptr;
 
        Train* tmp = trains;
        while (tmp->Ne->name != trainName2) tmp = tmp->Ne;
        tmp->Ne = train2->Ne;
        delete train2;
    }
 
    void dfront(string trainName1, string trainName2) {
        Train* train = find(trainName2);
        add(trainName1, train->head->N[0]->name);
 
        Person* person = train->head->N[0];
        bool temp = person->N[0] == train->head;
        train->head->N[0] = person->N[temp];
 
        temp = train->head->N[0]->N[0] != person;
        train->head->N[0]->N[temp] = train->head;
 
        person->N[0] = person->N[1] = nullptr;
        delete person;
 
        if (train->head->N[0] == train->head) {
            Train* tmp = trains;
            while (tmp->Ne->name != trainName2) tmp = tmp->Ne;
            tmp->Ne = train->Ne;
            delete train;
        }
    }
 
    void dback(string trainName1, string trainName2) {
        Train* train = find(trainName2);
        add(trainName1, train->head->N[1]->name);
 
        Person* person = train->head->N[1];
        bool temp = person->N[0] == train->head;
        train->head->N[1] = person->N[temp];
 
        temp = train->head->N[1]->N[0] != person;
        train->head->N[1]->N[temp] = train->head;
 
        person->N[0] = person->N[1] = nullptr;
        delete person;
 
        if (train->head->N[0] == train->head) {
            Train* tmp = trains;
            while (tmp->Ne->name != trainName2) tmp = tmp->Ne;
            tmp->Ne = train->Ne;
            delete train;
        }
    }
 
private:
    Train* find(string trainName) {
        auto train = trains;
        while (train->name != trainName) {
            train = train->Ne;
        }
        return train;
    }
};
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    int z; cin >> z;
    while (z--) {
        int n; cin >> n;
        Party party;
        while (n--) {
            string s; cin >> s;
            if (s == "NEW") {
                string Tname, Pname;
                cin >> Tname >> Pname;
 
                party.add(Tname, Pname);
            }
            else if (s == "BACK") {
                string Tname, Pname;
                cin >> Tname >> Pname;
 
                party.back(Tname, Pname);
            }
            else if (s == "FRONT") {
                string Tname, Pname;
                cin >> Tname >> Pname;
 
                party.front(Tname, Pname);
            }
            else if (s == "PRINT") {
                string Tname;
                cin >> Tname;
                party.print(Tname);
            }
            else if (s == "REVERSE") {
                string Tname;
                cin >> Tname;
                party.reverse(Tname);
            }
            else if (s == "UNION") {
                string Tname1, Tname2;
                cin >> Tname1 >> Tname2;
                party.merge(Tname1, Tname2);
            }
            else if (s == "DELFRONT") {
                string Tname1, Tname2;
                cin >> Tname1 >> Tname2;
                party.dfront(Tname1, Tname2);
            }
            else if (s == "DELBACK") {
                string Tname1, Tname2;
                cin >> Tname1 >> Tname2;
                party.dback(Tname2, Tname1);
            }
        }
    }
}
