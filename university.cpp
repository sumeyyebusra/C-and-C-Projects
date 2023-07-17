#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

class UniversityMember{
    private:
    int ID;
    string fullName;
    string startingDate;

    public:
    void setData(int ID, string fullName, string startingDate){
        this->ID = ID;
        this->fullName = fullName;
        this->startingDate = startingDate;
    }

    int getID(){
        return ID;
    }

    string getFullName(){
        return fullName;
    }

    string getStartingDate(){
        return startingDate;
    }
};

class Course{
    private:
    string semester;
    string ID;
    string preCourse;
    int numOfHomework;
    int numOfProjects;
    int perOfHomework;
    int perOfFinal;
    int perOfProjects;
    int perOfMidterm;

    public: 
    string getID(){
        return ID;
    }

    string getPreq(){
        return preCourse;
    }
   
    void printCourse(){
        cout << "\nSemester: " << semester << "\nID: " << ID << "\nPrerequisite courses: " << preCourse
        << "\nNumber of homeworks: " << numOfHomework << "\nNumber of prejects: " << numOfProjects <<
        "\nPercentage of the homeworks: " << perOfHomework << "\nPercentage of the final: " << perOfFinal
        << "\nPercentage of the projects: " << perOfProjects << "\nPercentage of the midterm: " << perOfMidterm;
    }

    void setFromDept(string semester, string ID, string preCourse){
        this->semester = semester;
        this->ID = ID;
        this->preCourse = preCourse;
    }

    void setFromInst(int numOfHomework, int numOfProjects, int perOfHomework, int perOfFinal, int perOfProjects, int perOfMidterm){
        this->numOfHomework = numOfHomework;
        this->numOfProjects = numOfProjects;
        this->perOfHomework = perOfHomework;
        this->perOfFinal = perOfFinal;
        this->perOfProjects = perOfProjects;
        this->perOfMidterm = perOfMidterm;
    }
};

class Instructor : public UniversityMember{
    private:
    string dept;
    bool fullTime;
    int numOfJournal;
    int numOfConference;
    vector<Course> coursesOffered;
    string labName;

    public:
    void setInst(int ID, string fullName, string startingDate, bool fullTime, int numOfJournal, int numOfConference, string labName){
        UniversityMember::setData(ID, fullName, startingDate);
        this->fullTime = fullTime;
        this->numOfJournal = numOfJournal;
        this->numOfConference = numOfConference;
        this->labName = labName;
    }

    void setDept(string deptName){
        dept = deptName;
    }

    string getDept(){
        return dept;
    }

    void printInst(){
        cout << "\nFull name: " << UniversityMember::getFullName() << "\nID: " << UniversityMember::getID() << "\nStarting date: " << UniversityMember::getStartingDate()
        << "\nDepartment: " << dept << "\nFull time: " << fullTime << "\nNumber of journal papers: " << numOfJournal
        << "\nNumber of conference papers: " << numOfConference << "\nName of the laboratory: " << labName;
    }

    void addCourse(Course& courseName, int numOfHomework, int numOfProjects, int perOfHomework, int perOfFinal, int perOfProjects, int perOfMidterm){
        courseName.setFromInst(numOfHomework, numOfProjects, perOfHomework, perOfFinal, perOfProjects, perOfMidterm);
        coursesOffered.push_back(courseName);
    }

    void removeCourse(Course courseName){
        vector<Course>::iterator it;
        for(it = coursesOffered.begin(); it != coursesOffered.end(); it++){
            if((*it).getID() == courseName.getID())
                coursesOffered.erase(it);
        }
    }

    void printCoursesOffered(){
        vector<Course>::iterator it;
        for(it = coursesOffered.begin(); it != coursesOffered.end(); it++)
            cout << (*it).getID() << " , ";
        cout << endl;
    }

    void incraseJournalPaper(){
        numOfJournal++;
    }

    void increaseConferencePaper(){
        numOfConference++;
    }

    int isOffered(Course courseName){
        vector<Course>::iterator it;
        for(it = coursesOffered.begin(); it != coursesOffered.end(); it++){
            if((*it).getID() == courseName.getID())
                return 1;
        }
        return 0;
    }

    bool getFullTime(){
        if (fullTime)
            return true;
        return false;
    }
};

class Student : public UniversityMember{
    private:
    vector<string> coursesTaken;
    map<string,int> coursesCompleted;
    float GPA;

    public:
    enum studentGrade {freshman=1, sophomore, junior, senior} grade;

    void setStudent(int ID, string fullName, string startingDate, float GPA, studentGrade grade){
        UniversityMember::setData(ID, fullName, startingDate);
        this->GPA = GPA;
        this->grade = grade;
    }

    void addCourse(Course course, int courseGrade){
        coursesTaken.push_back(course.getID());
        if(courseGrade > 50)
            coursesCompleted[course.getID()] = courseGrade;
    }

    int getGPA(){
        return GPA;
    }

    void printStudent(){
        cout << "\nStudent name: " << UniversityMember::getFullName() << "\nID: " << UniversityMember::getID() << "\nStarting date: " << UniversityMember::getStartingDate() 
        << "\nGPA: " << GPA;
    }

    void printTranscript(){
        for(auto it = coursesTaken.begin(); it != coursesTaken.end(); it++){
            auto itr = coursesCompleted.find((*it));
            if(itr  == coursesCompleted.end()){
                cout << "Course: " << (*it) << " Grade: FAILED";
                cout << "\n";
            }
            else{
                cout << "Course: " << (*it) << " Grade: " << (*itr).second;
                cout << "\n";
            }
        }
        cout << endl;
    }

    int getGrade(){
        if(grade == 1)
            return freshman;
        else if(grade == 2)
            return sophomore;
        else if(grade == 3)
            return junior;
        else if(grade == 4)
            return senior;
    }

    vector<string> getFailedCourses(){
        vector<string> coursesFailed;
        for(auto it = coursesTaken.begin(); it != coursesTaken.end(); it++){
            auto itr = coursesCompleted.find((*it));
            if(itr  == coursesCompleted.end()){
                coursesFailed.push_back((*it));
            }
        }
        return coursesFailed;
    }
};


class Faculty{
    private:
    string name;
    map<string,vector<string>> departments;
    map<string,vector<Instructor>> facultyMembers;
    map<string,vector<Course>> coursesOffered;
    
    public:
    void setFaculty(string name){
        this->name = name;
    }

    int getNumOfDepartment(){
        int deptCount = 0;
        for(auto& depts : departments){
            for(auto& d : depts.second)
                deptCount++;
        }
        return deptCount;
    }

    int getNumOfTotal(){
        int memberCount = 0;
        for(auto& member : facultyMembers){
            for(auto& m : member.second)
                memberCount++;
        }
        return memberCount;
    }

    map<string,vector<Course>> getCoursesOffered(){
        return coursesOffered;
    }
    

    void addDepartment(string facultyName, string deptName){
        name = facultyName;
        if(departments.find(name) == departments.end())
            departments[name] = vector<string>();
        departments[name].push_back(deptName);
    }

    void removeDepartment(string deptName){
        for(auto& depts : departments) {
            vector<string>::iterator it;
            for(it = depts.second.begin(); it != depts.second.end(); it++){
                if((*it) == deptName){
                    depts.second.erase(it);
                    break;
                }
            }
        }
    }

    void addMember(Instructor inst){
        if(facultyMembers.find(inst.getDept()) == facultyMembers.end())
            facultyMembers[inst.getDept()] = vector<Instructor>();
        facultyMembers[inst.getDept()].push_back(inst);
    }

    void removeMember(Instructor inst){
        for(auto& mem : facultyMembers) {
            vector<Instructor>::iterator it;
            for(it = mem.second.begin(); it != mem.second.end(); it++){
                if((*it).getID() == inst.getID()){
                    mem.second.erase(it);
                    break;
                }
            }
        }
    }

    void printCoursesOffered(){
        for(auto& course : coursesOffered){
            for(auto& c : course.second)
                cout << c.getID() << " ";
        }
    }

    void printFacultyMember(){
        for(auto& member : facultyMembers){
            for(auto& m : member.second)
                cout << m.getFullName() << " ";
        }
        cout << endl;
    }

    int getNumOfFull(){
        int countFull = 0;
        for(auto& member : facultyMembers){
            for(auto& m : member.second){
                if(m.getFullTime())
                    countFull++;
            }
        }
        return countFull;
    }

    int getNumOfAdjunct(){
        int countAdj = 0;
        for(auto& member : facultyMembers){
            for(auto& m : member.second){
                if(m.getFullTime() == false)
                    countAdj++;
            }
        }
        return countAdj;
    }
};


class Department : public Faculty{
    private:
    string deptName;
    string facName;
    vector<Student> students;
    string nameOfHead;
    vector<string> coursesOffered;
    map<string,string> coursesWithPreq;
    vector<string> facultyMembers;

    public:
    void addCourse(Course& courseName, string semester, string ID, string preCourse){
        courseName.setFromDept(semester, ID, preCourse);
        coursesOffered.push_back(courseName.getID());
        coursesWithPreq[courseName.getID()] = courseName.getPreq();
    }

    void removeCourse(Course course){
        vector<string>::iterator it;
        for(it = coursesOffered.begin(); it != coursesOffered.end(); it++){
            if((*it) == course.getID())
                coursesOffered.erase(it);
        }
    }

    void addFacultyMember(Instructor& facultyMember){
        facultyMember.setDept(deptName);
        facultyMembers.push_back(facultyMember.getFullName());
        Faculty::addMember(facultyMember);
    }

    void removeFacultyMember(UniversityMember facultyMember){
        vector<string>::iterator it;
        for(it = facultyMembers.begin(); it != facultyMembers.end(); it++){
            if((*it) == facultyMember.getFullName())
                facultyMembers.erase(it);
        }
    }

    void setDepartmant(string deptName,string facultyName,string headOfDept){
        Faculty::addDepartment(facultyName, deptName);
        this -> deptName = deptName;
        nameOfHead = headOfDept;        
    }

    string getDeptName(){
        return deptName;
    }

    void printCoursesOffered(){
        for(auto it = coursesOffered.begin(); it != coursesOffered.end(); it++)
            cout << (*it) << " ";
        cout << endl;
    }

    void printFacultyMember(){
        for(auto it = facultyMembers.begin(); it != facultyMembers.end(); it++)
            cout << (*it) << " ";
        cout << endl;
    }

    void findCourse(string course){
        for(auto it = coursesOffered.begin(); it != coursesOffered.end(); it++){
            if ((*it) == course)
                cout << course << "is one of the courses of" << deptName << endl;
        }
    }
    
    void findFacultyMember(string member){
        for(auto it = facultyMembers.begin(); it != facultyMembers.end(); it++){
            if ((*it) == member)
                cout << member << "is a member of" << deptName << endl;
        }
    }

    void getCoursesWithPreq(){
        for (auto it = coursesWithPreq.begin(); it != coursesWithPreq.end(); it++)
            cout << "Course: " << (*it).first << "Prerequisite of the Course: " << (*it).second << "\n";
    }

    string getCoursesBy(string instName){
        map<string,vector<Course>> courses = Faculty::getCoursesOffered();
        for (auto& it : courses){
            if (it.first == instName){
                for (auto& itr: it.second)
                    return (itr).getID();
            }
        }
    }

    void printCoursesBy(string instName){
        map<string,vector<Course>> courses = Faculty::getCoursesOffered();
        for (auto& it : courses){
            if (it.first == instName){
                for (auto& itr: it.second)
                    cout << (itr).getID() << " ";
            }
        }
    }

    int getNumOfStudents(){
        int count = 0;
        for (auto it = students.begin(); it != students.end(); it++)
            count++;
        return count;
    }

    void addStudent(Student student){
        students.push_back(student);
    }

    void removeStudent(Student student){
        for (auto it = students.begin(); it != students.end(); it++){
            if ((*it).getID() == student.getID())
                students.erase(it);
        }
    }

    void printFreshmanStudents(){
        int count = 0;
        for (auto it = students.begin(); it != students.end(); it++){
            if ((*it).getGrade() == 1){
                cout << (*it).getFullName() << " " << (*it).getID();
                count++;
            }
        }
        cout << endl << "Total number of freshman students: " << count << endl;
    }

    void printSophomoreStudents(){
        int count = 0;
        for (auto it = students.begin(); it != students.end(); it++){
            if ((*it).getGrade() == 2){
                cout << (*it).getFullName() << " " << (*it).getID();
                count++;
            }
        }
        cout << endl << "Total number of sophomore students: " << count << endl;
    }

    void printJuniorStudents(){
        int count = 0;
        for (auto it = students.begin(); it != students.end(); it++){
            if ((*it).getGrade() == 3){
                cout << (*it).getFullName() << " " << (*it).getID();
                count++;
            }
        }
        cout << endl << "Total number of junior students:  " << count << endl;
    }

    void printSeniorStudents(){
        int count = 0;
        for (auto it = students.begin(); it != students.end(); it++){
            if ((*it).getGrade() == 4){
                cout << (*it).getFullName() << " " << (*it).getID();
                count++;
            }
        }
        cout << endl << "Total number of senior students: " << count << endl;
    }
};

int main(){
    Faculty facultyEng;
    facultyEng.setFaculty("Faculty of Engineering");

    Department deptSoftware;
    deptSoftware.setDepartmant("Software Engineering","Faculty of Engineering","Funda Özdemir");

    Department deptComp;
    deptComp.setDepartmant("Computer Engineering","Faculty of Engineering","Mustafa Mısır");

    Instructor inst1;
    inst1.setInst(123,"Buse Yilmaz","April 2018",true,100,10,"lab1");

    Instructor inst2;
    inst2.setInst(456,"Ahmet Ates","May 2017",false,200,5,"lab2");

    Student stu1;
    Student::studentGrade gr = Student::junior;
    stu1.setStudent(190701100,"Esra Sevinc","September 2019",3.5,gr);
    deptSoftware.addStudent(stu1);
    
    Student stu2;
    Student::studentGrade gr2 = Student::senior;
    stu2.setStudent(190701052,"Sumeyye Sirim","September 2019",3.5,gr2);
    deptComp.addStudent(stu2);

    deptSoftware.addFacultyMember(inst1);
    deptComp.addFacultyMember(inst2);
    
    Course algorithms;
    deptSoftware.addCourse(algorithms,"FALL","YAZ202","YAZ201");
    Course programming;
    deptComp.addCourse(programming,"SPRING","COE202","COE201");

    stu1.addCourse(algorithms,75);
    stu2.addCourse(programming,30);
    stu1.addCourse(programming,100);
    stu2.addCourse(algorithms,60);

    inst1.addCourse(algorithms,10,5,10,40,20,30);
    inst2.addCourse(programming,2,3,10,40,20,30);

    cout << "ALGORITHM COURSE INFORMATION";
    algorithms.printCourse();
    cout << "\n \n";

    cout << "INSTRUCTOR INFORMATION";
    inst1.printInst();
    cout << endl << endl;
    cout << "STUDENT INFORMATION";
    stu1.printStudent();
    cout << endl << endl;
    cout << "STUDENT TRANSCRIPT" << endl;
    stu1.printTranscript();
    cout << "SENIOR STUDENTS"<< endl;
    deptComp.printSeniorStudents();
    
    return 0;
} 