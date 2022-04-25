/*
 Alex is enrolled within multiple academic programs. He is both a bachelor and a master student (n. b. having his L.L.B. diploma exam this year as well as finishing his Software Engineering 1st year of master). He needs a little bit of help with his exam preparation scheduling. He works on action points of interest, each one with its key features: importance_ (which in enumeration may be: critical, high, medium and low), difficulty_ (which in enumeration may be: high, medium and low), type_ (which in enumeration may be: final or intermediary – n. b. final being the flag for diploma exams and intermediary being the flag for year-round exams).
Using std::list:
- Store the exams (at least 10 entries – 4 bachelor diploma exams and 6 master exams);
- Add priority_ field (n. b. type of your choice) and compute the priority_ by reporting the exam importance_ to its difficulty_;
- Sort the list in descending order by priority_;
- Display all the exams;
 */

#include <iostream>
#include <list>

class Schedule{
public:
    std::string importance_, difficulty, type_, name;
    int priority_;
    Schedule(std::string name, std::string imp, std::string dif, std::string typ){
        if(imp == "critical" || imp == "high" || imp == "medium" || imp == "low"){
            this->importance_ = imp;
        }
        if(dif == "high" || dif == "medium" || dif == "low"){
            this->difficulty = dif;
        }
        if(typ == "final" || typ =="intermediary"){
            this->type_ = typ;
        }
        this->name = name;
    }

    void computePriority(){
        if(this->importance_ == "critical"){
            if(this->difficulty == "high"){
                this->priority_ = 12;
            }
            else
                if(this->difficulty == "medium"){
                    this->priority_ = 11;
                }
                else
                    if(this->difficulty == "low"){
                        this->priority_ = 10;
                    }
        }
        else
            if(this->importance_ == "high"){
                if(this->difficulty == "high"){
                    this->priority_ = 9;
                }
                else
                if(this->difficulty == "medium"){
                    this->priority_ = 8;
                }
                else
                if(this->difficulty == "low"){
                    this->priority_ = 7;
                }
            }
            else
                if(this->importance_ == "medium"){
                    if(this->difficulty == "high"){
                        this->priority_ = 6;
                    }
                    else
                    if(this->difficulty == "medium"){
                        this->priority_ = 5;
                    }
                    else
                    if(this->difficulty == "low"){
                        this->priority_ = 4;
                    }
                }
                if(this->importance_ == "low"){
                    if(this->difficulty == "high"){
                        this->priority_ = 3;
                    }
                    else
                    if(this->difficulty == "medium"){
                        this->priority_ = 2;
                    }
                    else
                    if(this->difficulty == "low"){
                        this->priority_ = 1;
                    }
                }
    }

    bool operator< (const Schedule & msgObj) const
    {
        std::string rightStr = msgObj.name + msgObj.importance_ + msgObj.difficulty;
        std::string leftStr = msgObj.name + msgObj.importance_ + msgObj.difficulty;
        return (leftStr < rightStr);
    }
    friend std::ostream& operator<<(std::ostream& os, const Schedule& obj);
};

std::ostream& operator<<(std::ostream& os, const Schedule& obj)
{
    os << obj.name << " " << obj.importance_ << " " << obj.difficulty << " " << obj.priority_ << std::endl;
    return os;
}
int main(){
    std::list<Schedule> exams;

    Schedule s1 = Schedule("CCIoT", "critical", "high", "final");
    Schedule s2 = Schedule("IS", "high", "medium", "final");
    Schedule s3 = Schedule("MSI", "medium", "medium", "final");
    Schedule s4 = Schedule("Thesis", "medium", "low", "final");
    Schedule s5 = Schedule("Data Mining", "critical", "high", "intermediary");
    Schedule s6 = Schedule("Machine Learning", "high", "high", "intermediary");
    Schedule s7 = Schedule("Introduction to DS", "high", "low", "intermediary");
    Schedule s8 = Schedule("Data Analysis", "medium", "low", "intermediary");
    Schedule s9 = Schedule("Big Data", "critical", "medium", "intermediary");
    Schedule s10 = Schedule("Data Viz", "low", "medium", "intermediary");

    s1.computePriority();
    s2.computePriority();
    s3.computePriority();
    s4.computePriority();
    s5.computePriority();
    s6.computePriority();
    s7.computePriority();
    s8.computePriority();
    s9.computePriority();
    s10.computePriority();

    exams.push_back(s1);
    exams.push_back(s2);
    exams.push_back(s3);
    exams.push_back(s4);
    exams.push_back(s5);
    exams.push_back(s6);
    exams.push_back(s7);
    exams.push_back(s8);
    exams.push_back(s9);
    exams.push_back(s10);

    exams.sort([](const Schedule & s1, const Schedule & s2)
                       {
                           if(s1.priority_ == s2.priority_)
                               return s1.difficulty > s2.difficulty;
                           return s1.priority_ > s2.priority_;
                       });

    for(auto i:exams){
        std::cout<<i;
    }





}