/*
 * 3. A local competition is announced in New Hampshire. General School and High School students are
called to make a difference in the world by submitting a new invention to the contest and present the usage
within an open-public symposium.

Design a tuple-based database for contestants, retaining details like: fullName_, studentType_ (n.b
which in enumeration may be general or highSchool), inventionId_;

- Design a tuple-based database for evaluation, retaining details like: evaluatorName_, inventionId_ and
inventionGrading_;

- Design a tuple-based database to retain details about the invention: inventionId_ and impactArea_ (n. b.
the field of activity in which the invention is registered);

- Populate the databases with at least 5 entries by using a queue of tuples;

- Order the inventions based on the grading;

- Remove all the inventions that don’t meet the required minimal score of 60 pts.;

- Print the field of activity with most points gathered (n. b. that field of activity which has the inventions
assigned to it – with the highest score cumulated);
 */

#include <iostream>
#include <tuple>
#include <queue>

class Invention{
public:
    std::string fullName_, studentType_;
    int inventionId_;
    std::string evaluatorName_;
    int inventionGrading_;
    std::string impactArea_;
    std::tuple<std::string, std::string, int> contestant;
    std::tuple<std::string, int, int> evaluation;
    std::tuple<int, std::string> invention;

    Invention(std::string name, std::string type, int id){
        this->fullName_ = name;
        if(type == "general")
        {this->studentType_ = type;}
        else
        {
            this->studentType_ = "highSchool";
        }
        this->inventionId_ = id;
        contestant = std::make_tuple(name, type, id);
    }

    void setEvaluator(std::string name, int grade){
        this->evaluatorName_ = name;
        this->inventionGrading_ = grade;
        evaluation = std::make_tuple(name, this->inventionId_, grade);
    }

    void setDetails(std::string impact)
    {
        this->impactArea_ = impact;
        invention = std::make_tuple(this->inventionId_, impact);
    }

    std::tuple<std::string, std::string, int> getcontestant(){
        return this->contestant;
    }

    std::tuple<std::string, int, int> getevaluator(){
        return this->evaluation;
    }

    std::tuple<int, std::string> getinvention(){
        return this->invention;
    }

};

struct myComparator
{
    int operator()(const std::tuple<std::string, int, int>& tuple1,
                   const std::tuple<std::string, int, int>& tuple2)
    {
        // Second element of tuples is equal
        if (std::get<2>(tuple1) == std::get<2>(tuple2))
        {
            if (std::get<1>(tuple1) == std::get<1>(tuple2))
            {
                if (std::get<0>(tuple1) >= std::get<0>(tuple2))
                    return true;
                return false;
            }

            return std::get<1>(tuple1) >= std::get<1>(tuple2);
        }

        return std::get<2>(tuple1) >= std::get<2>(tuple2);
    }
};

// Function to print priority queue
// contents. Deliberately passing it
// call by value since we don't want
// to remove elements from the priority
// queue
void printp(std::priority_queue<std::tuple<std::string, int, int>,std::vector<std::tuple<std::string,int, int>>,myComparator>priorityQueue,
            std::priority_queue<std::tuple<std::string, std::string, int>> contester)
{
while (!priorityQueue.empty())
{
// Each element of the priority
// queue is a tuple itself
std::tuple<std::string, int, int> Tuple =
        priorityQueue.top();

std::cout << "[ ";
int contester_id = std::get<1>(Tuple);

std::cout << std::get<1>(Tuple) << ' ' <<
std::get<1>(Tuple) << ' ' <<
std::get<2>(Tuple);
std::cout << ']';
std::cout << '\n';

// Pop out the topmost tuple
priorityQueue.pop();
}
}

void removeelements(std::priority_queue<std::tuple<int,std::string> > priorityQueue){
    while (!priorityQueue.empty())
    {
        // Each element of the priority
        // queue is a tuple itself
        std::tuple<int, std::string> Tuple =
                priorityQueue.top();

        if(std::get<0>(Tuple) < 6){

        }

        std::cout << std::get<0>(Tuple) << ' ' <<std::get<1>(Tuple);
        std::cout << ']';
        std::cout << '\n';

        // Pop out the topmost tuple
        priorityQueue.pop();
    }
}

int main(){

    std::priority_queue<std::tuple<std::string, std::string, int>> contestants;
    std::priority_queue<std::tuple<int, std::string>> inventions;
    std::tuple<std::string, std::string, int> contesters;
    std::tuple<std::string, int, int> evaluaters;
    std::tuple<int, std::string> inventers;
    std::priority_queue<std::tuple<std::string,int, int>,
            std::vector<std::tuple<std::string,int, int> >,
            myComparator> evaluators;

    Invention i1 = Invention("Simon", "general", 1);
    i1.setEvaluator("Dr. Drey",  10);
    i1.setDetails("Biology");
    Invention i2 = Invention("Eliza", "highSchool", 2);
    i2.setEvaluator("Dr. Connor",  7);
    i2.setDetails("Physics");
    Invention i3 = Invention("Theodora", "other", 3);
    i3.setEvaluator("Karen",  5);
    i3.setDetails("Medicine");
    Invention i4 = Invention("Alice", "other", 6);
    i4.setEvaluator("Dr. Sick",  9);
    i4.setDetails("Mathematics");
    Invention i5 = Invention("Dorin", "general", 4);
    i5.setEvaluator("Dr. Sinca",  8);
    i5.setDetails("Geography");
    Invention i6 = Invention("Serginho", "other", 5);
    i6.setEvaluator("Marius",  10);
    i6.setDetails("History");

    contesters = i1.getcontestant();
    evaluaters = i1.getevaluator();
    inventers = i1.getinvention();
    contestants.push(contesters);
    evaluators.push(evaluaters);
    inventions.push(inventers);

    contesters = i2.getcontestant();
    evaluaters = i2.getevaluator();
    inventers = i2.getinvention();
    contestants.push(contesters);
    evaluators.push(evaluaters);
    inventions.push(inventers);

    contesters = i3.getcontestant();
    evaluaters = i3.getevaluator();
    inventers = i3.getinvention();
    contestants.push(contesters);
    evaluators.push(evaluaters);
    inventions.push(inventers);


    contesters = i4.getcontestant();
    evaluaters = i4.getevaluator();
    inventers = i4.getinvention();
    contestants.push(contesters);
    evaluators.push(evaluaters);
    inventions.push(inventers);


    contesters = i5.getcontestant();
    evaluaters = i5.getevaluator();
    inventers = i5.getinvention();
    contestants.push(contesters);
    evaluators.push(evaluaters);
    inventions.push(inventers);

    contesters = i6.getcontestant();
    evaluaters = i6.getevaluator();
    inventers = i6.getinvention();
    contestants.push(contesters);
    evaluators.push(evaluaters);
    inventions.push(inventers);

    printp(evaluators, contestants);




}