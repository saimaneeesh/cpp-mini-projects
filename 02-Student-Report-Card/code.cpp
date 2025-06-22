#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class Student {
    private:
    string name;
    int rollNumber;

public:
    void input(){
        cout << "Enter your name here: ";
        cin.ignore(); 
        getline(cin, name);  
        cout << "Enter your roll number here: ";
        cin >> rollNumber;  
    }

    void display(){
        cout << "your name is  "<< name << endl;
        cout << "your roll number is  "<< rollNumber << endl;
    }

    string getName() const {
        return name;
    }
    int getRollNo() const{
        return rollNumber;
    }
};

class ReportCard {
    private:
        vector<string> subjectNames;
        vector<int> marks;
        float avg;
        char grade;
        Student student; 

public:
    void inputMarks(){
        student.input();
        int subjectCount;
        cout << "Enter number of subjects: ";
        cin >> subjectCount;

        while (subjectCount <= 0 || subjectCount > 10) {
            cout << "Please enter a valid number of subjects (1-10): ";
            cin >> subjectCount;
        }

        marks.resize(subjectCount);
        subjectNames.resize(subjectCount); 

        for(int i = 0; i < subjectCount; i++){
            cout << " Enter name for Subject " << (i + 1) << ": ";
            cin >> subjectNames[i];
        }
        cout << "enter the subject marks ";

        for(int i = 0; i < subjectCount; i++){
            do {
                cout << " Enter Subject " << (i + 1) << " Marks Here (0-100): ";
                cin >> marks[i];
            } while(marks[i] < 0 || marks[i] > 100);
        }
    }
    void calculateAvg(){
        avg = 0;
        for(int i = 0; i < marks.size(); i++){
            avg += marks[i];
        }
        avg = avg/marks.size();
    }
    void calculateGrade(){
        if(avg >= 90){
                grade = 'S';
        }
        else if(avg >= 80 && avg < 90){
                grade = 'A';
        }
        else if(avg >= 70 && avg < 80){
                grade = 'B';
        }
        else if(avg >= 60 && avg < 70){
                grade = 'C';
        }
        else if(avg >= 50 && avg < 60){
                grade = 'D';
        }
        else {
                grade = 'F';
        }
    }
    void displayReport(){
      student.display();
      cout << "Average is " << avg << endl;
      cout << "grade is " << grade << endl;
      cout << "Subjects and Marks:\n";
      for(int i = 0; i < marks.size(); i++){
        cout << subjectNames[i] << ": " << marks[i] << " ";
      }
    }

    void saveToFile(const string& filename) const{
        ofstream outputFile(filename);
        if(!outputFile){
            cerr << "error: unable to open file for writting. \n";
            return;
        }
        outputFile << " Student Report Card \n";
        outputFile << "Name: " << student.getName() << endl;
        outputFile << "Roll Number: " << student.getRollNo() << endl;
        outputFile << "SubjectName & Marks: \n";
        for(int i = 0; i < marks.size(); i++){
            outputFile << subjectNames[i] << ": " << marks[i] << " ";
        }
        outputFile << "\nAverage: " << avg << "\nGrade: " << grade << endl;
        outputFile.close();
        cout << "Report saved to " << filename << endl;

    }

};

int main(){
    ReportCard myreport;
    myreport.inputMarks();
    myreport.calculateAvg();
    myreport.calculateGrade();
    myreport.displayReport();
    myreport.saveToFile("Report.txt");
}
