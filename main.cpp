#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string id;
    string name;
    int score;
};

//The templates give from the question
template <class T>
T getMax(T a, T b) {
 return (a > b) ? a : b;
}
template <class T>
T getMin(T a, T b) {
 return (a < b) ? a : b;
}

map<string, Student> students;

//Function One: Add Student Info
void addStudent(){
    Student s;
    cout << "Enter student id:" << endl;
    cin >> s.id;
    cout << "Enter student name:" << endl;
    cin >> s.name;
    cout << "Enter student score:" << endl;
    cin >> s.score;

    //Check if the student id repeated or not
    if (students.count(s.id)){
        cout << "This student id already exist, do you want to overwrite it(y/n)" << endl;
        char c;
        cin >> c;
        if (c == 'y' || c == 'Y') {
            cout << "Overwite it successfully!!" << endl;
        }else if (c == 'n' || c == 'N') {
            cout << "Cancel to add it" << endl;
            return; 
        }
    }

    students [s.id] = s;
    cout << "Student " << s.name << " added successfully!!" << endl;
    cout << endl;
}

//Function Two: Print all stuents info
void printAllStuInfo(){
    if(students.empty()){
        cout << "No student right now" << endl;
        cout << endl;
        return;
    }
    cout << left << setw(12) << "Id" << setw(12) << "Name" << setw(6) << "Score" << endl;
    cout << "-------------------------------" << endl;
    for (auto& p : students){
    cout << left << setw(12) << p.second.id << setw(12) << p.second.name << setw(6) << p.second.score << endl;
    }
    cout << endl;
}

//Function Three: Sort the students from highest to lowest score
void sortByScore(){
    if(students.empty()){
        cout << "No student right now" << endl;
        cout << endl;
        return;

    }
    vector<Student> v;
    for(auto& p : students){
        v.push_back(p.second);
    }
    sort(v.begin(), v.end(), [](const Student& a, const Student& b){
        return a.score > b.score;
    });
    cout << "Sort by the score" << endl;
    cout << left << setw(7) << "Ranked" << setw(12) << "Id" << setw(12) << "Name" << setw(6) << "Score" << endl;
    cout << "-------------------------------------" << endl;
    int r =1;
        for (auto& s : v){
    cout << left << setw(7) << r++ << setw(12) << s.id << setw(12) << s.name << setw(6) << s.score << endl;
    }
    cout << endl;
}

//Function Four: Find the student
void findStudentID(){
    string std_id;
    cout << "Enter the student ID you want to find:" << endl;
    cin >> std_id;
    if(students.count(std_id)){
        Student& s = students[std_id];
        cout << endl;
        cout << "ID: " << s.id << " Name: " << s.name << " Score: " << s.score << endl;
    }else{
        cout << endl;
        cout << "Can't find the student with ID " << std_id << endl;
    }
    cout << endl;
}

//Function Five: Statistical results(using the template)
void statisticalResults(){
    if(students.empty()){
        cout << "No student right now" << endl;
        cout << endl;
        return;
    }
    vector<Student> v;
    for(auto& p : students){
        v.push_back(p.second);
    }

    double total = 0;
    int maxScore = v[0].score;
    int minScore = v[0].score;
    int pass = 0;
    int fall = 0;
    double average = 0;

    for (auto& s : v){

        total += s.score;

        //Use template function(template is automatically deduced as int)
        maxScore = getMax(maxScore,s.score);
        minScore = getMin(minScore,s.score);
        if(s.score >= 60){
            pass++;
        }else{
            fall++;
        }
    }
    average = total / v.size();

    cout << "The average score:" << average << endl;
    cout << "The highest score:" << maxScore << endl;
    cout << "The lowest score:" << minScore << endl;
    cout << "The number of people who passed:" << pass << endl;
    cout << "The number of people who didn't pass:" << fall << endl;
    cout << endl;
}

int main(){
    int choice;

    do {
        cout << "----Student Score Management System----" << endl;
        cout << "1. Add student" << endl;
        cout << "2. List all students" << endl;
        cout << "3. Sort by score" << endl;
        cout << "4. Search by id " << endl;
        cout << "5. Show statistics" << endl;
        cout << "0. Exit" << endl ;
        cout << endl << "Enter the option you want:" << endl;

        cin >> choice;
        cout << endl;

        switch (choice){
        case 1: addStudent();
            break;
        case 2: printAllStuInfo();
            break;
        case 3: sortByScore();
            break;
        case 4: findStudentID();
            break;
        case 5: statisticalResults();
            break;
        }

    }while(choice != 0);

    return 0;
}