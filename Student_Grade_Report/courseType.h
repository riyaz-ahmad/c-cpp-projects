#include<bits\stdc++.h>
#include<string.h>
using namespace std;
/*
    *class CourseType
        *This class is used to set the components of the course
        *it also provides us the information about the courses

*/
class courseType{
    string courseName;// data member for storing course name
    string courseNo;// data member for storing course number
    char courseGrade;// data member for storing course grades
    int courseCredits;// data member for storing course credits

    public:
        //Function to set the course information
        void setCourseInfo(string cName, string cNo, char cGrades, int cCredits);

        //Function to print the course information
        void print(ostream &outp, bool isGrade);

        //function for gettint credits
        int getCredits();

        //function for getting the course number
        void getCourseNumber(string &cNo);

        //function for getting grade
        char getGrade();

        //constructor
        courseType(string cName = "", string cNo = "", char grade = '*', int credits = 0);

        //overloading the opeartors
        bool operator==(const courseType&) const;
        bool operator!=(const courseType&) const;
        bool operator<=(const courseType&) const;
        bool operator<(const courseType&) const;
        bool operator>=(const courseType&) const;
        bool operator>(const courseType&) const;

};

void courseType :: setCourseInfo(string cName, string cNo, char cGrades, int cCredits){
    courseName = cName;
    courseNo = cNo;
    courseGrade = cGrades;
    courseCredits = cCredits;  
}

void courseType :: print(ostream &outp, bool isGrade){
    outp << left;
    outp << setw(8)<<courseNo<< " ";
    outp << setw(15)<<courseName<<" ";
    outp.unsetf(ios::left);
    outp<< setw(3) << courseCredits << " ";
    if(isGrade)
        outp << setw(4) << courseGrade<<endl;
    else
        outp << setw(4) << "***"<<endl;

}

int courseType :: getCredits(){
    return courseCredits;
}

void courseType :: getCourseNumber(string &cNo){
    cNo = courseNo;    
}

char courseType :: getGrade(){
    return courseGrade;
} 

courseType::courseType(string cName, string cNo, char grade, int credits){
    setCourseInfo(cName, cNo, grade, credits);
}

bool courseType::operator==(const courseType& right) const
{
return (courseNo == right.courseNo);
}
bool courseType::operator!=(const courseType& right) const
{
return (courseNo != right.courseNo);
}
bool courseType::operator<=(const courseType& right) const
{
return (courseNo <= right.courseNo);
}
bool courseType::operator<(const courseType& right) const
{
return (courseNo < right.courseNo);
}
bool courseType::operator>=(const courseType& right) const
{
return (courseNo >= right.courseNo);
}
bool courseType::operator>(const courseType& right) const
{
return (courseNo > right.courseNo);
}




/*  *class person type starts here 
    *used to set the name and get name of students
*/

class personType{

    public:
    string firstName;
    string lastName;
    void print() const;
    void setName(string first, string last);
    personType& setFirstName(string first);
    personType& setLastName(string last);string getFirstName() const;
    string getFirstName() ;
    string getLastName() ;
    personType(string first = "", string last = ""){ firstName = first; lastName = last;}

};

void personType :: print() const{
    cout<<firstName<< " "<<lastName;
}

void personType :: setName(string first, string last){
    firstName = first;
    lastName = last;
}

string personType :: getFirstName()  {
    return firstName;
}

string personType :: getLastName(){
    return lastName;
}

personType& personType :: setFirstName(string first){
    firstName = first;
    return *this;
}

personType& personType :: setLastName(string last){
    lastName = last;
    return *this;
}

/*
    * studentType class
    *This class provides all the details of a student currently enrolled in the courseType
*/

class studentType : public personType{
    int sId;//data member for storing the value of stident id
    int numberOfCourses;//dsata member for storing the value of number opf courses a student is enrolled
    bool isTutionPaid;//this member stores the information is tution fee paid by the student
    vector<courseType> coursesEnrolled; //vector of the courses in which a student is enrolled

    public:
    //member function for setting the student information
    void setInfo(string, string, int, bool, vector<courseType>);

    //member function for printing the grade report
    void print(ostream &out, double tutionRate);

    //member function to return the credit hours a stuent is enolled in
    int getHoursEnrolled();

    //function for getting the gpa of a student
     double getGpa();

    //default constructor
    studentType();

    //function for returning the tution fee
    double billingAmount(double tutuionRate);

};

void studentType:: setInfo(string fname, string lname, int id, bool isTPaid, vector<courseType> courses){
    setName(fname, lname);
    sId = id;
    isTutionPaid = isTPaid;
    numberOfCourses = courses.size();
    coursesEnrolled = courses;
    sort(coursesEnrolled.begin(), coursesEnrolled.end());
}

void studentType :: print(ostream &outp, double tutionrate){
    outp<<"Student Name: " << personType::getFirstName()<<" " <<personType::getLastName()<<endl;
    outp<<"Student Id: "<<sId<<endl;
    outp<<"Number of courses enrolled: "<<numberOfCourses<<endl;
    outp<<left;
    outp<<"Course Numner: "<<setw(15)<<" Course Name: "<<setw(8)<<" Credits"<< setw(6)<<" Grades"<<endl;
    outp.unsetf(ios::left); //used to clear the format flags of iostream
    for (int i = 0; i < numberOfCourses; i++)
        coursesEnrolled[i].print(outp, isTutionPaid);
    outp<<endl;
    outp<<"Total number of credit hours: "<<getHoursEnrolled()<<endl;
    /*To output the GPA and billing amount in a fixed decimal format
    with the decimal point and trailing zeros, set the necessary flag. Also,
    set the precision to two decimal places.
    */
    outp<<fixed<<showpoint<<setprecision(2);
    if(isTutionPaid)
        outp<<"Midstream GPA: "<< getGpa()<<endl;
    else{
        outp<<"*** Grades are being held for not paying the tution fee***"<<endl;
        outp<<"Amount Due: Rs"<<billingAmount(tutionrate)<<endl;
    }
    outp << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    outp << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;

}

int studentType:: getHoursEnrolled(){
    int totalCredits;
    for(int i=0; i<numberOfCourses;i++)
        totalCredits += coursesEnrolled[i].getCredits();
    return totalCredits;
}

double studentType::billingAmount(double tutionRate){
    return tutionRate*getHoursEnrolled();
}

double studentType::getGpa(){
    double sum = 0.0;
    for(int i = 0; i< numberOfCourses; i++){
        switch(coursesEnrolled[i].getGrade()){
            case 'A':
                sum += coursesEnrolled[i].getCredits() * 4;
                break;
            case 'B':
                sum += coursesEnrolled[i].getCredits() * 3;
                break;
            case 'C':
                sum += coursesEnrolled[i].getCredits() * 2;
                break;
            case 'D':
                sum += coursesEnrolled[i].getCredits() * 1;
                break;
            case 'F':
                break;
          /*  default:
                cout<<"Inavlid Course Grade"<<endl;*/
        }
    }
    if(getHoursEnrolled() != 0)
        return sum/getHoursEnrolled();
    else   
        return 0;
}


studentType::studentType(){
numberOfCourses = 0;
sId = 0;
isTutionPaid = false;
}