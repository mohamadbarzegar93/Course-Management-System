#include <iostream>

using namespace std;

class Person // Base Class - Parent Class
{
protected:
    string firstname;
    string surname;
    string email;
    char type;
public:
    Person(string f, string s, string e) : firstname(f), surname(s), email(e)
    {
        cout << firstname << " " << surname << ", Email " << email << endl;
    }
    string get_email()
    {
        return email;
    }
    /*void whoAmI()
    {
        cout << "I'm a person." << endl;
    }*/

};

class Student : public Person // Derived Class - Child Class
{
private:
    int matriculation_number;
    string university;
public:
    static int n_courses; //Number of enrolled courses of each student
    Student (string f, string s, string e, int mn, string u) : Person (f,s,e), matriculation_number(mn), university (u)
{
    type = 'S';
    cout<<"Matriculation number: "<<matriculation_number<<" University: "<<university<<endl;
}
    string get_university() //Accessing university to check for outside students
    {
        return university;
    }

};

class Lecturer : public Person // Derived Class - Child Class
{
private:
    string academic_title;
public:
    Lecturer (string f, string s, string e, string a_t) : Person (f,s,e), academic_title(a_t)
    {
    type = 'L';
    cout<<"Academic Title "<<academic_title<<endl;
    }
    /*void display() {
        cout << "Lecturer: " << academic_title << " " << firstname << " " << surname << ", Email: " << email << endl;
    }
*/
    string getAcademicTitle()  //function to access academic title
    {
        return academic_title;
    }


};


/*class Operator : public Person
{
private:
    int passcode;
    string operator_number;
public:
    Operator (string f, string s, int p, string o_n) : Person (f,s), passcode(p), operator_number(o_n)
    {
    type = 'o';
    cout<<"Operator "<<operator_number<<" . Please enter your password: "<<endl;
    int passcode1;
    bool authorized;
    cin >>passcode1;
    authorized = (passcode1==passcode);
    }


};
*/
class Course
{
private:
    string course_name;
    string lecturer;
    string enrolled_students [10];
public:
    Course (string c_n, string l) : course_name (c_n), lecturer (l)
    static int n_enrolled;
    //static string enrolled_students [10];

    void add_student()
    {
        if (n_enrolled==10){
            cout<<"The course has no further free place"<<endl;
        }
        uni = Student.get_university;
        while (n_enrolled<11)
        {
            for (int i=0; i<n_enrolled; i++) {
                if (enrolled_students[i] == Student.email) {
                    cout<<"The student is already enrolled in this course!"<<endl;
                    break;
                }
            }
            if (uni!= "THD" && Student.n_courses == 1) {
                cout<<"You have already reached the maximum number of courses"<<endl;
            }
            else {
                cout<<"You have enrolled to this course!"<<endl;
                n_enrolled+=1;
                Student.Email = enrolled_students[n_enrolled];
            }
        }

    }

    void show_participants() //function to check courses with their taking place status
    {
        for (int i=0; i<10; i++)
        {
            if (n_enrolled <4)
            {
                cout<<"List of participants for the "<<course_name<<" : (Course will not take place)"<<endl;
                cout<<enrolled_students[i]<<", ";
            } else if (n_enrolled>3 && n_enrolled <10){
                cout<<"List of participants for the "<<course_name<<endl;
                cout<<enrolled_students[i]<<", ";
            }

        }



    }
    void show_free_courses() //function to output those courses taking place
    {
        cout<<"Course with free place: "<<endl;
        if (n_enrolled <10)
        {
            cout<<"Course "<<course_name<<" Number of free places"<< (10-n_enrolled)<<"Lecturer: "<<lecturer<<endl; //????Academic Title?

        }
    }
    void notify_members() //function for notifying those enrolled to the courses not meeting participant requirements
    {
        if (n_enrolled<3)
        {
            cout<<"The course "<<course_name<<" does not meet the minimum attendees; the following students should be notified "<<Student.show_particpants<<endl;
        }

    }
    string getCourseName() {
        return course_name;
    }
    void displayCourse() {
        cout << "Course: " << course_name <<"\tLecturer: "<<lecturer<<endl;
        if (participant_count < 4) {
            cout << "Course will not take place.\n";
        }
        //show_participants();
    bool Full_course() {
        return participant_count >= 10;
    }

    int freeSpots() {
        return 10 - n_enrolled;
    }


};

int main()
{
    Lecturer lecturer1("Peter", "Faber","peter.faber@th-deg,de", "Prof. Dr. ");
    Lecturer lecturer2("Herbert", "Fisher", "herbert.fischer@th-deg.de", "Prof. Dr.-Ing.");
    Lecturer lecturer3("Rudi", "Buss", "rudi.buss@th-deg.de", "Dr.");


    Course programming("Programming", lecturer1);
    Course databases("Databases", lecturer2);
    Course software_engineering("Software Engineering", lecturer3);

    Course courses[3] = {
        Course programming, Course database, Course software_engineering
};

    int input=0;
    do {
        cout << "Main Menu: "<<endl;
        cout << "1. Registration for a course"<<endl;
        cout << "2. Output of one or all courses with data of the participants"<<endl;
        cout << "3. Output of all courses that are not fully booked yet"<<endl;
        cout << "4. End of program"<<endl;
        cin >> choice;

        switch (input)
        {
            case 1:
                cout<<"Available courses:"<<endl;
                for (int i = 0; i<3; i++)
                {
                    cout<<i+1<<". "<<course[i].getCourseName<<ebdl;
                }
                int course_index;
                cout "Select course number: ";
                cin >> course_index;
                if (course_index < 1 || course_index > 3) //Checking user input for courses
                {
                    cout << "Invalid course number. Select course number: ";
                    cin >> course_index;
                };
                string first_name, last_name, email, uni;
                int matr_nr;
                cout << "First name: "; cin >> first_name;
                cout << "Surname: "; cin >> last_name;
                cout << "Email: "; cin >> email;
                cout << "University: "; cin >> uni;
                cout << "Matriculation Number: "; cin >> matr_nr;
                Student s(first_name, last_name, email, matr_nr, uni);
                s.add_student();

        case 2:
                for (int i = 0; i<3; i++)
                {
                    course[i].displayCourse();
                    cout<<endl;
                }
        case 3:
                cout << "Courses with free places:\n";
                for (int i = 0; i < 3; i++)
                    {
                    if (!courses[i].Full_course()) {
                        cout << courses[i].getCourseName() << " | Free Places: " << courses[i].freeSpots();
                        }

                    }

        case 4:
                cout << "Notifying students of canceled courses: "<<endl;
                 for (int i = 0; i<3; i++)
                {
                    course[i].notify_members();
                    cout<<endl;
                }

            }

            } while (input!=4);

    return 0;
}
};
