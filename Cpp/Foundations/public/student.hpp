/* Here I have an include guard.
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class student
{
public: 
    student(std::string name_i, int age_i, double wam_i);
    ~student();

    std::string get_name();
    int get_age();
    double get_wam();

    void set_name(std::string new_name);
    void set_age(int new_age);
    void set_wam(double new_wam);

private:
    std::string name;
    int age;
    double wam;

};

#endif
