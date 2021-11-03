#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

// create a class for the personnel
class personnel {
private:
    string name;
    string id;
    string description;
    unsigned int salary;
    unsigned int number_of_working_days;
public:
    // constructor
    personnel();
    personnel(string name, string id, string description, unsigned int salary, unsigned int number_of_working_days);
    personnel(string name, unsigned int number_of_working_days);
    personnel(const personnel& p);
    // getter
    string get_name();
    string get_id();
    string get_description();
    unsigned int get_salary();
    unsigned int get_number_of_working_days();
    // setter
    void set_name(string name);
    void set_id(string id);
    void set_description(string description);
    void set_salary(unsigned int salary);
    void set_number_of_working_days(unsigned int number_of_working_days);
    // other functions
    void input();
    string setup_id(string name);
    void print();
    ~personnel();
};
personnel::personnel() {
    name = "undefined";
    id = "undefined";
    description = "undefined";
    salary = 0;
    number_of_working_days = 0;
}
personnel::personnel(string name, string id, string description, unsigned int salary, unsigned int number_of_working_days) {
    this->name = name;
    this->id = id;
    this->description = description;
    this->salary = salary;
    this->number_of_working_days = number_of_working_days;
}
personnel::personnel(string name, unsigned int number_of_working_days) {
    this->name = name;
    this->number_of_working_days = number_of_working_days;

    // type casting number_of_working_days to string   
    stringstream ss;
    ss << number_of_working_days;
    string number_of_working_days_string = ss.str();
    id = number_of_working_days_string + "" + name;
    description = "undefined";
    salary = 0;
}
personnel::personnel(const personnel& p) {
    description = p.description;
    salary = p.salary;
    number_of_working_days = p.number_of_working_days;
    name = "undefined";
    id = "undefined";
}
string personnel::get_name() {
    return name;
}
string personnel::get_id() {
    return id;
}
string personnel::get_description() {
    return description;
}
unsigned int personnel::get_salary() {
    return salary;
}
unsigned int personnel::get_number_of_working_days() {
    return number_of_working_days;
}
void personnel::set_name(string name) {
    this->name = name;
}
void personnel::set_id(string id) {
    this->id = id;
}
void personnel::set_description(string description) {
    this->description = description;
}
void personnel::set_salary(unsigned int salary) {
    this->salary = salary;
}
void personnel::set_number_of_working_days(unsigned int number_of_working_days) {
    this->number_of_working_days = number_of_working_days;
}
void personnel::input() {
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter id: ";
    getline(cin, id);
    cout << "Enter description: ";
    getline(cin, description);
    cout << "Enter salary: ";
    cin >> salary;
    cin.ignore();
    cout << "Enter number of working days: ";
    cin >> number_of_working_days;
    cout << endl << endl;
    if (id != setup_id(name)) {
        cout << "Do you want to change this id: " << setup_id(name) << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            id = setup_id(name);
        }
        else {
            cout << "your id is: " << id << endl;
        }
    }
}
string personnel::setup_id(string name) {
    // getting online last name
    string last_name = name.substr(name.find_last_of(" ") + 1);
    stringstream ss;
    ss << number_of_working_days;
    string number_of_working_days_string = ss.str();
    string temp_id = number_of_working_days_string + "" + last_name;
    return temp_id;
}
void personnel::print() {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Description: " << description << endl;
    cout << "Salary: " << salary << endl;
    cout << "Number of working days: " << number_of_working_days << endl;
}
personnel::~personnel() {
    name = "undefined";
    id = "undefined";
    description = "undefined";
    salary = 0;
    number_of_working_days = 0;
}
int main() {
    system("color 0a");
    system("cls");
    personnel p1("David John", "20john", "Programmer", 100000, 20);
    personnel p2("Olivia Mary", 20);
    personnel p3(p1);
    personnel p4;

    p4.input();

    p4.print();
    cout << endl;
    p1.print();
    cout << endl;
    p2.print();
    cout << endl;
    p3.print();
    cout << endl;
    cout << endl;

    p4.~personnel();
    p3.~personnel();
    p2.~personnel();
    p1.~personnel();

    p4.print();
    cout << endl;
    p1.print();
    cout << endl;
    p2.print();
    cout << endl;
    p3.print();
    cout << endl;
    cout << endl;
    
    return 0;
}


