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
    void print();
    void delete_personnel();
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
void personnel::print() {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Description: " << description << endl;
    cout << "Salary: " << salary << endl;
    cout << "Number of working days: " << number_of_working_days << endl;
}
void personnel::delete_personnel() {
    name = "";
    id = "";
    description = "";
    salary = 0;
    number_of_working_days = 0;
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
    personnel p1("John", "20john", "Programmer", 100000, 20);
    personnel p2("Mary", 20);
    personnel p3(p1);
    p1.print();
    cout << endl;
    p2.print();
    cout << endl;
    p3.print();

    cout << endl << "affter delete_personnel: " << endl << endl;
    p1.delete_personnel();
    p1.print();
    cout << endl;
    p2.delete_personnel();
    p2.print();
    cout << endl;
    p3.delete_personnel();
    p3.print();
    cout << endl;
    return 0;
}


