#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

//Class memebers are private by default.

class student
{
public: 

    student(string name_i, int age_i, int wam_i)
    {
        name = name_i;
        age = age_i;
        wam = wam_i;
    }

    void print()
    {
        cout << "Student Name : " << this->name
             << "\nStudent age  : " << this->age
             << "\nStudent WAM  : " << this->wam 
             <<endl;
    }

    void set_name(string input){
        this->name = input;
    }

    void set_age(int input){
        this->age = input;
    }

    void set_wam(int input){
        this->wam = input;
    }

    string get_name(){
        return name;
    }

    int get_age(){
        return age;
    }

    int get_wam(){
        return wam;
    }

private:
    string name;
    int age;
    int wam;
};

int main()
{
    student Tester("I am student",12,50);
    Tester.print();
    
    cout << endl;

    Tester.set_age(30);
    Tester.set_name("Test Student");
    Tester.set_wam(100);

    Tester.print();

}