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
};
class StudentManager{
    private:
    vector<Student> students;
    const string filename="students.csv";

    int findindexbyenroll(const string& enrollnumber)const{
        for(size_t i=0;i<students.size();++i){
            if(students[i].getEnrollnumber()==enrollnumber){
                return static_cast <int>(i);
            }
        }
        return -1;
    }

    public:
    StudentManager(){
        loadFromFile();
    }

    ~StudentManager(){
        saveToFile();
    }

    bool addStudent(const Student& student){
        if(findindexbyenroll(student.getEnrollnumber())!=-1){
            return false;
        }
        students.push_back(student);
        saveToFile();
        return true;
    }

    void displayall()const{
        if(students.empty()){
            cout<<"\n No Records found.\n";
            return;
        }
       cout << "\n" << string(110, '-') << "\n";
        cout << left 
                  << setw(12) << "Roll Number"
                  << setw(18) << "Name"
                  << setw(15) << "Branch"
                  << setw(10) << "Semester"
                  << setw(8)  << "CGPA" 
                  << setw(18) <<"Email"
                  << setw(13) <<"Phone Number"<<"\n";
        cout << string(110, '-') << "\n";

         for (const auto& s : students) {
            cout << left 
                      << setw(12) << s.getEnrollnumber()
                      << setw(18) << s.getName()
                      << setw(15) << s.getBranch()
                      << setw(10) << s.getSemester()
                      << fixed << setprecision(2) << setw(8) << s.getCGPA()
                      << setw(18) << s.getEmail()
                      << setw(13) << s.getPhone() <<"\n";
        }
        cout << string(110, '-') << "\n";
    }

    bool searchStudent(const string& enrollNumber) const {
        int idx = findindexbyenroll(enrollNumber);
        if (idx == -1) return false;

        const auto& s = students[idx];
        cout << "\n---------- Student Record Found ----------"
                  << "\nRoll Number : " << s.getEnrollnumber()
                  << "\nName        : " << s.getName()
                  << "\nBranch      : " << s.getBranch()
                  << "\nSemester    : " << s.getSemester()
                  << "\nCGPA        : " << fixed << setprecision(2) << s.getCGPA()
                  << "\n--------------------------------------\n";
        return true;
    }

    bool updateStudent(const string& rollNumber, const string& newName, 
                       const string& newBranch, const string& newSem, float newGpa,
                       const string& newemail, const string& newphone) {
        int idx = findindexbyenroll(rollNumber);
        if (idx == -1) return false;

        students[idx].setName(newName);
        students[idx].setBranch(newBranch);
        students[idx].setSemester(newSem);
        students[idx].setCGPA(newGpa);
        students[idx].setEmail(newemail);
        students[idx].setPhone(newphone);
        saveToFile();
        return true;
    }

    bool deleteStudent(const std::string& rollNumber) {
        int idx = findindexbyenroll(rollNumber);
        if (idx == -1) return false;

        students.erase(students.begin() + idx);
        saveToFile();
        return true;
    }

     void saveToFile() const {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error opening file for writing: " << filename << "\n";
            return;
        }
        for (const auto& s : students) {
            outFile << s.toCSV() << "\n";
        }
    }

    void loadFromFile() {
        students.clear();
        ifstream inFile(filename);
        if (!inFile) return; // File does not exist yet

        string line;
        while (getline(inFile, line)) {
            if (line.empty()) continue;
            Student s;
            if (Student::fromCSV(line, s)) {
                students.push_back(s);
            }
        }
    }
};

