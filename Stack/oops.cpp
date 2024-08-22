#include<iostream>
#include<cstring>

using namespace std;

class Student {
    public:
        struct Info {
            char s_name[30];
            char reg_no[30];
            double marks[3];
            double avg;
        } info[3]; 

        void getinfo() {
            for (int i = 0; i < 3; i++) {
                cout << "Name: ";
                cin >> info[i].s_name;
                cout << "Reg No. : ";
                cin >> info[i].reg_no;
                for (int j = 0; j < 3; j++) {
                    cout << "Marks in Test " << j + 1 << ": ";
                    cin >> info[i].marks[j];
                }
            }
        }

        void SortMarks() {
            for (int k = 0; k < 3; k++) {
                for (int i = 0; i < 3 - 1; i++) {
                    for (int j = 0; j < 3 - i - 1; j++) {
                        if (info[k].marks[j] > info[k].marks[j + 1]) {
                            double temp = info[k].marks[j];
                            info[k].marks[j] = info[k].marks[j + 1];
                            info[k].marks[j + 1] = temp;
                        }
                    }
                }
            }
        }

        void compute_sort() {
            for (int k = 0; k < 3; k++) {
                info[k].avg = (info[k].marks[2] + info[k].marks[1]) / 2.0;
            }

            for (int i = 0; i < 3 - 1; i++) {
                for (int j = 0; j < 3 - i - 1; j++) {
                    if (info[j].avg < info[j + 1].avg) { 
                        // Swap names
                        char temp_name[30];
                        strcpy(temp_name, info[j].s_name);
                        strcpy(info[j].s_name, info[j + 1].s_name);
                        strcpy(info[j + 1].s_name, temp_name);

                        // Swap registration numbers
                        char temp_reg[30];
                        strcpy(temp_reg, info[j].reg_no);
                        strcpy(info[j].reg_no, info[j + 1].reg_no);
                        strcpy(info[j + 1].reg_no, temp_reg);

                        // Swap averages
                        double temp_avg = info[j].avg;
                        info[j].avg = info[j + 1].avg;
                        info[j + 1].avg = temp_avg;
                    }
                }
            }
        }

        void display() {
            for (int i = 0; i < 3; i++) {
                cout << "Name: " << info[i].s_name << endl;
                cout << "Average: " << info[i].avg << endl;
            }
        }
};

int main() {
    Student s;
    s.getinfo();
    s.SortMarks();
    s.compute_sort();
    s.display();
    return 0;
}
