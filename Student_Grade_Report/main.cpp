#include<bits/stdc++.h>
#include<string>
#include "courseType.h"

using namespace std;

vector <studentType> studentList;
double tutionRate;
ifstream infile;
ofstream outfile;

/*  Function for loading the students Data  */
void getStudentData(ifstream &infile, vector<studentType> &studentList){
    //local variables for this function
    string fName; //variable to store the first name
    string lName; //variable to store the last name
    int ID; //variable to store the student ID
    int noOfCourses; //variable to store the number of courses
    char isPaid; //variable to store Y/N, that is tuition paid
    bool isTuitionPaid; //variable to store true/false
    string cName; //variable to store the course name
    string cNo; //variable to store the course number
    int credits; //variable to store the course credit hours
    char grade; //variable to store the course grade
    vector<courseType> courses; //vector of objects to store course information
    
    courseType cTemp;
    studentType sTemp;

    infile>>fName;

    while(infile){
        infile>>lName>>ID>>isPaid;
        if(isPaid =='Y' || isPaid=='y')
            isTuitionPaid = true;
        else    
            isTuitionPaid = false;
        infile>>noOfCourses;
        infile.clear();
        for(int i=0;i<noOfCourses;i++){
            infile>> cName>>cNo>>credits>>grade;
            cTemp.setCourseInfo(cName, cNo, credits, grade);
            courses.push_back(cTemp);
        }

        sTemp.setInfo(fName, lName,ID, isTuitionPaid, courses);
        studentList.push_back(sTemp);

        infile>>fName;
    }//while ends here
}

/* Funtion for printing the grade reports of students*/

void printGradeReports(ostream &outfile, vector<studentType> studentList, double tutionRate){
    for(int count = 0; count<studentList.size();count++)
        studentList[count].print(outfile, tutionRate);

}




int main(){
    vector<studentType> studentList;
    double tuitionRate;
    ifstream infile;
    ofstream outfile;
    infile.open("stData.txt");
    if (!infile){
        cout << "Input file does not exist. "<< "Program terminates." << endl;
        return 1;
    }
    outfile.open("stDataOut.txt");
    infile >> tuitionRate; //get the tuition rate
    getStudentData(infile, studentList);
    printGradeReports(outfile, studentList, tuitionRate);
    return 0;
}
