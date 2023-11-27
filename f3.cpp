#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace::std;

class student{
    public:
    string student_id;
    string student_name;
    int tution_fee;
    string c1, c2, c3;

    public:
    student(string std_id, string std_name, int t_fee, string c1, string c2, string c3){

        this->student_id = std_id;
        this->student_name = std_name;
        this->tution_fee = t_fee;
        this->c1 = c1;
        this->c2 = c2;
        this->c3 = c3;

    }

    public:
    student(){}


    public:
    string get_Student_id(){
        return this->student_id;
    }

    void set_Student_id(string std_id){
        this->student_id = std_id;
    }

    void print_Student_id(){
        cout<< this->student_id<< endl;
    }

    string get_Student_name(){
        return this->student_name;
    }

    void set_Student_name(string std_name){
        this->student_id = std_name;
    }

    void print_Student_name(){
        cout<< this->student_name << endl;
    }

    int get_tution_fee(){
        return this->tution_fee;
    }

    void set_tution_fee(int t_fee){
        this->tution_fee = t_fee;
    }

    string get_c1(){
        return this->c1;
    }

    void set_c1(string t){
        this->c1 = t;
    }

    string get_c2(){
        return this->c2;
    }

    void set_c2(string t){
        this->c2 = t;
    }

    string get_c3(){
        return this->c3;
    }

    void set_c3(string t){
        this->c3 = t;
    }
    
    void print_student(ofstream&  OutFile){

        cout << this->student_id << " "
         << this->student_name << " "
         << this->tution_fee << " "
         << this->c1 << " "
         << this->c2 << " "
         << this->c3 << endl;

         OutFile << this->student_id << " "
         << this->student_name << " "
         << this->tution_fee << " "
         << this->c1 << " "
         << this->c2 << " "
         << this->c3 << endl;

    }

    void print_sd_id_name(ofstream&  OutFile){
        cout << this->student_id << " "
         << this->student_name << endl;

        OutFile << this->student_id << " "
         << this->student_name << endl;

        
    }

};


class employee{
    public:
    string employee_id, employee_name;
    int pay;

    employee(){}


    employee(string emp_id, string emp_name, int p){
        this->employee_id = emp_id;
        this->employee_name = emp_name;
        this->pay = p;
    }

    public:
    string get_employee_id(){
        return this->employee_id;
    }

    void set_employee_id(string emp_id){
        this->employee_id = emp_id;
    }

    string get_employee_name(){
        return this->employee_name;
    }

    void set_employee_name(string emp_name){
        this->employee_id = emp_name;
    }

    void set_pay(int p){
        this->pay = p;
    }

    int get_pay(){
        return this->pay;
    }

    void print_emp_id_p(ofstream&  OutFile){
        OutFile << this->employee_id << " " << this->pay << endl;
        cout<< this->employee_id << " " << this->pay << endl;
    }

};


class instructor: public employee{

    public:
    string c_name;

    instructor(){}

    instructor(employee e, string s){
        this->c_name = s;
        this->employee_id = e.employee_id;
        this->pay = e.pay;
        this->employee_name = e.employee_name;

    }

    instructor(string id, string course){
        this->employee_id = id;
        this->c_name = course;
    }

    public:
    string get_inst_id(){
        return this->employee_id;
    }

    void set_inst_id(string i_id){
        this->employee_id = i_id;
    }

    string get_c_name(){
        return this->c_name;
    }

    void set_c_name(string cn){
        this->c_name = cn;
    }

    string get_emp_name(){
        return this->employee_name;
    }

    void set_emp_name(string s){
        this->employee_name = s;
    }

    void print_instructor(){
        cout<< this->employee_id << " "
        << this->pay << " "
        << this->employee_name << " "
        << this->c_name << endl;
    }

};


class teachingAssistant: public student, public instructor{

    public:
    vector<string> course;

    teachingAssistant(){}

    teachingAssistant(instructor inst, student s){

        course.push_back(inst.get_c_name());
        this->student_id = s.get_Student_id();
        this->student_name = s.get_Student_name();
        this->tution_fee = s.get_tution_fee();
        this->c1 = s.get_c1();
        this->c2 = s.get_c2();
        this->c3 = s.get_c3();

    }

    teachingAssistant(string c, student s){

        course.push_back(c);
        this->student_id = s.get_Student_id();
        this->student_name = s.get_Student_name();
        this->tution_fee = s.get_tution_fee();
        this->c1 = s.get_c1();
        this->c2 = s.get_c2();
        this->c3 = s.get_c3();

    }

    void add_course(string s){
        this->course.push_back(s);
    }

    string get_std_id(){
       return this->student_id;
    }

    void print_ta(){
        cout << this->student_id << " " 
        << this->student_name << " "
        << this->c1 << " "
        << this->c2 << " "
        << this->c3 << " "
        << "Courses Taught: ";

        for (int i = 0; i < this->course.size(); i++)
        {
            cout << this->course.at(i) << " ";
        }
        
        cout << endl;
        
    }


};
void q4(vector<student> s, ofstream&  OutFile){
    cout << "A4" << endl;
    OutFile << "A4" << endl;
    for (int i = 0; i < s.size(); i++)
    {
        s[i].print_student(OutFile);
    }
    cout << endl;
    OutFile << endl;

}

void q2(vector<student> s, vector<instructor> inst, ofstream&  OutFile){

    cout << "A2" << endl;
    OutFile << "A2" << endl;
    
    for (int i = 0; i < inst.size(); i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            
            if (inst[i].get_employee_id() == s[j].get_Student_id())
            {
                cout << inst[i].get_employee_id() << " "
                << inst[i].get_employee_name() << " "
                << inst[i].get_c_name() << endl;

                OutFile << inst[i].get_employee_id() << " "
                << inst[i].get_employee_name() << " "
                << inst[i].get_c_name() << endl;
            }
            

        }
        
    }

    cout << endl;
    OutFile << endl;
    
}

void q1(vector<employee> e, ofstream&  OutFile)
{
    OutFile << "A1" << endl;
    cout << "A1" << endl;

    for (int i = 0; i < e.size(); i++)
    {
        e.at(i).print_emp_id_p(OutFile);
    }
    
    cout << "" << endl;
    OutFile << endl;
}

void q3(vector<student> sd, vector<employee> emp, ofstream&  OutFile)
{
    cout << "A3" << endl;
    OutFile << "A3" << endl;

    bool check = false;
   for (int i = 0; i < sd.size(); i++)
    {

        for (int j = 0; j < emp.size(); j++)
        {
            if (sd[i].get_Student_id() == emp[j].get_employee_id())
            {
                check = true;
                break;

            }
        }
        
        if(check == true){
            check = false;
            continue;
        }else{
            sd[i].print_sd_id_name( OutFile);
        }
        
    }
    cout << "" << endl;
    OutFile << endl;
}

vector<teachingAssistant> input_teachingAssistant(vector<teachingAssistant> ta, vector<instructor> t, vector<student> s)
{
    for (int i = 0; i < t.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            if (t[i].get_inst_id() == s[j].get_Student_id()) {
                ta.push_back(teachingAssistant(t[i], s[j]));
                break;
            }
        }
    }

    return ta;
}

vector<instructor> input_instructor(vector<instructor> inst, vector<employee> e){

    for (int i = 0; i <= inst.size() - 1; i++)
    {
        for (int j = 0; j <= e.size() - 1; j++)
        {
            if(inst.at(i).get_inst_id() == e.at(j).get_employee_id()){

                inst.at(i).set_emp_name(e.at(j).get_employee_name());
                inst.at(i).set_pay(e.at(j).get_pay());

            }
        }
        

    }

    return inst;
    
}

int main(int argc, char const *argv[]){

    vector<student> STUDENT;
    vector<employee> EMPLOYEE;
    vector<instructor> INSTRUCTOR;
    vector<teachingAssistant> TA;


   if (argc < 5)
   {
    cout << "All input output files not specified" << endl;
    return 0;
   }


    ifstream inputEmp(argv[1]);
    string line1;


    while (getline(inputEmp,line1))
    {
        istringstream ss(line1);
        string emp_name, emp_id;
        int pay;


        getline(ss,emp_id,',');
        getline(ss,emp_name,',');
        ss >> pay;
        EMPLOYEE.push_back(employee(emp_id,emp_name,pay));
        


    }


   ifstream inputSD(argv[2]);
   string line2;

    while (getline(inputSD,line2))
    {
        istringstream ss(line2);
        string std_name, std_id,c1,c2,c3;
        int fee;


        getline(ss,std_id,',');
        getline(ss,std_name,',');
        ss >> fee;
        getline(ss,c1,',');
        getline(ss,c2,',');
        getline(ss,c3,'\n');
        STUDENT.push_back(student(std_id,std_name,fee,c1,c2,c3));

    }

    ifstream inputIN(argv[3]);
    string line3;

    while (getline(inputIN,line3))
    {
        istringstream ss(line3);
        string inst_id, course;


        getline(ss,inst_id,',');
        getline(ss,course,'\n');
        INSTRUCTOR.push_back(instructor(inst_id,course));

    }  

    INSTRUCTOR = input_instructor(INSTRUCTOR, EMPLOYEE);
    TA = input_teachingAssistant(TA, INSTRUCTOR, STUDENT);

    ofstream OutFile(argv[4]);

    q1(EMPLOYEE, OutFile);
    q2(STUDENT, INSTRUCTOR, OutFile);
    q3(STUDENT,EMPLOYEE, OutFile); 
    q4(STUDENT, OutFile);

    OutFile.close();
    
    return 0;

}