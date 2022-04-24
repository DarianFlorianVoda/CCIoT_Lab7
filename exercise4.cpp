/*
 A car company needs to keep track of their sales over the past few years so they store car information such as brand_, model_ and profit_.
Using std::set:
- Store all the car sales of the company (at least 10 entries);
- Were there any BMW cars sold? Display a descriptive message in both cases;
- Add productionYear_ as information that needs to be stored;
- Using std::vector, group the stored set of cars per production year;
- Display the productionYear_ that was the most profitable;
 */

#include <iostream>
#include <set>

class Trabant{
public:
    std::string brand_, model_;
    int profit_;

    Trabant(std::string b, std::string m, int prf){
        this->brand_ = b;
        this->model_ = m;
        this->profit_ = prf;
    }

    bool operator< (const Trabant & msgObj) const
    {
        std::string rightStr = msgObj.brand_ + msgObj.model_;
        std::string leftStr = this->brand_ + this->model_;
        return (leftStr < rightStr);
    }
    friend std::ostream& operator<<(std::ostream& os, const Trabant& obj);
};

std::ostream& operator<<(std::ostream& os, const Trabant& obj)
{
    os<<obj.brand_<<" :: "<<obj.model_<<" :: "<<obj.profit_<<std::endl;
    return os;
}

int main()
{

    std::set<Trabant> all_cars;
    Trabant t1 = Trabant("BMW", "M5", 5000);
    Trabant t2 = Trabant("Dacia", "RLogan", 10000);
    Trabant t3 = Trabant("Renault", "Megane", 7000);
    Trabant t4 = Trabant("Audi", "R5", 50000);
    Trabant t5 = Trabant("Tesla", "Simple", 500000);
    Trabant t6 = Trabant("Volskwagen", "Das...Auto", 100000);
    Trabant t7 = Trabant("Ford", "Fiesta", 3000);
    Trabant t8 = Trabant("Mazda", "R535", 200);
    Trabant t9 = Trabant("Volvo", "C109", 70000);
    Trabant t10 = Trabant("Subaru", "205", 80000);
    Trabant t11 = Trabant("Ferrari", "M23", 200000);
    Trabant t12 = Trabant("Lamborghini", "Gallardo", 700000);

    all_cars.insert(t1);
    all_cars.insert(t2);
    all_cars.insert(t3);
    all_cars.insert(t4);
    all_cars.insert(t5);
    all_cars.insert(t6);
    all_cars.insert(t7);
    all_cars.insert(t8);
    all_cars.insert(t9);
    all_cars.insert(t10);
    all_cars.insert(t11);
    all_cars.insert(t12);
    int k=0;
    for (const auto & all_car : all_cars) {
        if(all_car.brand_ == "BMW"){
            std::cout<<"Yes, we have a BMW, adica un vericu cu numere de bulgaria "<<all_car.model_;
            std::cout<<std::endl;
            k = 1;
        }
    }
    if(k==0){
        std::cout<<"No we don't have a vericu with BMW"<<std::endl;
    }
}