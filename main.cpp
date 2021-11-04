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
    float salary;
    unsigned int number_of_working_days;
public:
    // constructor
    personnel();
    personnel(string name, string id, string description, float salary, unsigned int number_of_working_days);
    personnel(string name, unsigned int number_of_working_days);
    personnel(const personnel& p);
    // getter
    string get_name();
    string get_id();
    string get_description();
    float get_salary();
    unsigned int get_number_of_working_days();
    // setter
    void set_name(string name);
    void set_id(string id);
    void set_description(string description);
    void set_salary(float salary);
    void set_number_of_working_days(unsigned int number_of_working_days);
    // other functions
    void auto_set();
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
personnel::personnel(string name, string id, string description, float salary, unsigned int number_of_working_days) {
    this->name = name;
    this->id = id;
    this->description = description;
    this->salary = salary;
    this->number_of_working_days = number_of_working_days;
    if (id != setup_id(name)) {
        cout << "Do you want to change this id: " << setup_id(name) << endl;
        cout << "Yes = 1" << endl;
        cout << "No  = 0" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            id = setup_id(name);
        }
        cout << endl << endl;
        cout << "your id is: " << id << endl << endl;
    }
    if (salary == -1 || description == "-1") {
        auto_set();
    }
}
personnel::personnel(string name, unsigned int number_of_working_days) {
    this->name = name;
    this->number_of_working_days = number_of_working_days;

    // type casting number_of_working_days to string   
    stringstream ss;
    ss << number_of_working_days;
    string number_of_working_days_string = ss.str();
    id = number_of_working_days_string + "" + name;
    auto_set();
}
personnel::personnel(const personnel& p) {
    description = p.description;
    salary = p.salary;
    number_of_working_days = p.number_of_working_days;
    name = "undefined";
    auto_set();
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
float personnel::get_salary() {
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
void personnel::set_salary(float salary) {
    this->salary = salary;
}
void personnel::set_number_of_working_days(unsigned int number_of_working_days) {
    this->number_of_working_days = number_of_working_days;
}
void personnel::auto_set() {
    if (number_of_working_days <= 365) {
        description = "nhan vien";
        if (salary == -1) {
            salary = 1.0;
        }
    }
    else if (number_of_working_days > 365 && number_of_working_days <= 730) {
        description = "quan ly";
        if (salary == -1) {
            salary = 1.5;
        }
    }
    else if (number_of_working_days > 730 && number_of_working_days <= 1460) {
        description = "truong phong";
        if (salary == -1) {
            salary = 2.25;
        }
    }
    else if (number_of_working_days > 1460) {
        description = "truong ban quan ly";
        if (salary == -1) {
            salary = 4.0;
        }
    }
}
void personnel::input() {
    cout << "If you don't know what to enter, enter -1 in that field" << endl << endl;
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
        cout << "Yes = 1" << endl;
        cout << "No  = 0" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            id = setup_id(name);
        }
        cout << endl << endl;
        cout << "your id is: " << id << endl << endl;
    }
    if (salary == -1 || description == "-1") {
        auto_set();
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
    personnel p1("David John", "20john", "truong phong", 1000, 20);
    personnel p2("Olivia Mary", 740);
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

    cout << " affter delete" << endl;
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


