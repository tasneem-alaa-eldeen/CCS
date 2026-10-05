# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
using namespace std;

class Students {
public:
string name;
int id;
double grade;

void print(){
    cout<<id<<" "<<name<<" "<<grade<<endl;
}

};

double totalgrade(const vector<Students>& students, int n){
    if (n==0)
    return 0;
    return students[n-1].grade+totalgrade(students, n-1);
}

 int main(){
    vector<Students> students;
    int choice;

    do {
        cout<<"====== Student Grades System ====="<<endl;
        cout<<"1. Add Student"<<endl;
        cout<<"2. Display Students"<<endl;
        cout<<"3. Linear Search by Name"<<endl;
        cout<<"4. Linear Search by ID"<<endl;
        cout<<"5. Statistics (Highest, Lowest & Average)"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;

        switch(choice){
            case 1: {
                Students s;
                cout<<"Enter ID: "<<endl;
                cin>>s.id;
                cout<<"Enter Name: "<<endl;
                cin>>s.name;
                cout<<"Enter Grade: "<<endl;
                cin>>s.grade;
                students.push_back(s);
                cout<<"Student added succesfully!"<<endl;
                break;
            }
            case 2: {
            if (students.empty()){
                cout<<"No students found!"<<endl;
            }
            else{
                for(int i =0; i<students.size()-1;i++){
                    for(int j =0;j<students.size()-i-1;j++){
                        if (students[j].grade<students[j+1].grade){
                        swap(students[j], students[j+1]);
                        }
                    }
                }
                cout<<" Rank  | ID  | Name  | Grade  "<<endl;
                cout<<"-----------------------------"<<endl;
                for(int i = 0; i<students.size(); i++){
                    cout<<(i+1);
                    if(i==0) cout<<"st  | ";
                 else if(i==1) cout<<"nd  | ";
                   else if(i==2) cout<<"rt  | ";
              else cout<<"th  | ";
                    students[i].print();
                }
            }
                   break;
            }
            case 3: {
                if (students.empty()){
                cout<<"No students to search!"<<endl;
            }
            else{
             string search_name;
             cout<<"Enter student name to search: ";
             cin>>search_name;
             int comparisons =0;
             bool found = false;
             for(int i=0;i<students.size();i++){
                comparisons++;
                if(students[i].name ==search_name){
                    cout<<" Student Found! ";
                    students[i].print();
                    found =true;
                    break;
                }
             }
             cout<<"Linear Search Comparisons: "<<comparisons<<endl;
             if (!found) cout<<"Student not found!"<<endl;
            }
            break;
            }
            case 4: {
            if (students.empty()){
                cout<<"No students to search!"<<endl;
            }
            else{
                for(int i =0; i<students.size()-1;i++){
                    for(int j =0;j<students.size()-i-1;j++){
                        if (students[j].id<students[j+1].id){
                        swap(students[j], students[j+1]);
                        }
                    }
                }
                int search_id;
                cout<<"Enter student ID to search: ";
             cin>>search_id;
             int left =0, right=students.size()-1;
             int comparisons =0;
             bool found = false;
             while(left<=right){
                comparisons++;
                int mid=left+(right-left)/2;
                if (students[mid].id==search_id){
                    cout<<" Student Found! ";
                    students[mid].print();
                    found=true;
                    break;
                }
                else if(students[mid].id<search_id){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
             }
            cout<<"Binary Search Comparisons: "<<comparisons<<endl;
             if (!found) cout<<"Student not found!"<<endl;
            }
            break;
        }
        case 5: {
            if (students.empty()) {
                    cout << "No students available!\n";
                } else {
                    double maxGrade = students[0].grade;
                    double minGrade = students[0].grade;
                    string maxName = students[0].name;
                    string minName = students[0].name;

                    for (int i = 1; i < students.size(); i++) {
                        if (students[i].grade > maxGrade) {
                            maxGrade = students[i].grade;
                            maxName = students[i].name;
                        }
                        if (students[i].grade < minGrade) {
                            minGrade = students[i].grade;
                            minName = students[i].name;
                        }
                    }

                    double total = totalgrade(students, students.size());
                    double avg = total / students.size();

                    cout << " --- Statistics --- "<<endl;
                    cout << "Highest Grade: " << maxGrade << " (Student: " << maxName << ")\n";
                    cout << "Lowest Grade: " << minGrade << " (Student: " << minName << ")\n";
                    cout << "Class Average: " << avg << endl;
                }
                break;
        }
            case 6: {
             cout<<"Exiting program..."<<endl;
             break;
        }
        default: {
             cout<<"Invalid choice, please try again."<<endl;
             break;
            }
        }
    } while(choice !=6);

    return 0;
}
