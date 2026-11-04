#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <algorithm>
using namespace std;
class Student{
    private:
    string enrollnumber;
    string name;
    string branch;
    string semester;
    float cgpa=0.0f;
    string email;
    string phonenumber;
    public:

    //unparameterised
    Student()=default;

    //parameterised
    Student(string enroll, string n, string b,string sem, float gpa, string mail,string phone) :
    enrollnumber(enroll),
    name(n),
    branch(b),
    semester(sem),
    cgpa(gpa),
    email(mail),
    phonenumber(phone) {}

    //get
    string getEnrollnumber()const {
        return enrollnumber;
    }
    string getName()const{
        return name;
    }
    string getBranch()const{
        return branch;
    }
    string getSemester()const{
        return semester;
    }
    float getCGPA()const{
        return cgpa;
    }
    string getEmail()const{
        return email;
    }
    string getPhone()const{
        return phonenumber;
    }

    //setters

    void setName(const string& n){
        if(!n.empty()) name=n;
    }
    void setBranch(const string& b){
        if(!b.empty()) branch=b;
    }
    void setSemester(const string& sem){
        if(!sem.empty()) semester=sem;
    }
    bool setCGPA(float gpa){
        if (gpa >= 0.0f && gpa <= 10.0f) {
            cgpa = gpa;
            return true;
        }
        return false;
    }
    void setEmail(const string& mail){
        if(!mail.empty()) email=mail;
    }
    void setPhone(const string& phone){
        if(!phone.empty()) phonenumber=phone;
    }

    //CSV generate

    string toCSV()const{
        return enrollnumber+","+name+","+branch+","+semester+","+to_string(cgpa)+","+email+","+phonenumber;
    }

    //object Polulation

    static bool fromCSV(const string& line, Student& student){
        stringstream ss(line);
        string enroll,name,branch,semester,gpaStr,email,phone;
       if(getline(ss,enroll,',')&&
         (getline(ss,name,','))&&
         (getline(ss,branch,','))&&
         (getline(ss,semester,','))&&
         (getline(ss,gpaStr,','))&&
         (getline(ss,email,','))&&
         (getline(ss,phone,','))){
            try{
                float cgpa=stof(gpaStr);
                student=Student(enroll,name,branch,semester,cgpa,email,phone);
                return true;
            }catch(...){
                return false;
            }
         }
         return false;
    }
}