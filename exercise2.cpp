#include <iostream>
#include <list>
#include<bits/stdc++.h>

/*
 * 2. David is an archeologist who is very passionate about ancient artifacts so he needs an app to keep track of all the details he is interested in and needs your help to develop it.
He would require an Artifact class to store general details such as:
• artifactType_, that can have following values: vase, jewelry, partialRelic, unkown;
• discoveryDate_;
• estimatedDateOfOrigin_;
• condition_, that can have following values: poor, mediocre, good, needSpecialHandling;
Being mostly interested in Greek and Egyptian artifacts, the following two classes are required:
• GreekArtifact, having as members: greekGod_(name of the greek god that it is related too, otherwise “none”);
• EgyptianArtifact with the following members: pharaoh_(name of the pharaoh that ruled in the time frame the artifact came from);

 With the above specifications perform the following:
- Define the class hierarchy and other necessary data structures;
- Store 10 entries (5 Greek artifacts and 5 Egyptian) in a std::list;
- Order by discoveryDate_ and print the contents;
- Using std:map store for each museum (between 3 and 5 museums) the list of artifacts they hold;

 */

struct Date
{
    int day, month, year;
};

class Artifact{
protected:
    std::string artifactType_;
    Date discoveryDate_, estimatedDateOfOrigin;
    std::string condition_;
public:
    void setType(std::string realtype) {
        if (realtype == "vase") {
            this->artifactType_ = realtype;
        } else if (realtype == "jewelry") {
            this->artifactType_ = realtype;
        } else if (realtype == "partialRelic") {
            this->artifactType_ = realtype;
        } else
            this->artifactType_ = "unknown";

    }

    void printArtefact(){
        std::cout<<"Type: "<< this->artifactType_<<std::endl;
        std::cout<<"Condition:  "<<this->condition_<<std::endl;
        std::cout<<"Discovery date: "<<this->discoveryDate_.day<<"/"<< this->discoveryDate_.month<<"/"<< this->discoveryDate_.year<<std::endl;
        std::cout<<"Estimated Origin date: "<<this->estimatedDateOfOrigin.day<<"/"<< this->estimatedDateOfOrigin.month<<"/"<< this->estimatedDateOfOrigin.year<<std::endl;
    }

    void setCond(const std::string& cond){
        if (cond == "poor") {
            this->condition_ = cond;
        } else if (cond == "mediocre") {
            this->condition_ = cond;
        } else if (cond == "good") {
            this->condition_ = cond;
        } else if(cond == "needSpecialHandling")
        {
            this->condition_ = cond;
        }
        else
            this->condition_ = "unknown";
    }

    void setDiscoverydate(int year, int month, int day){
                this->discoveryDate_.year = year;
                this->discoveryDate_.month = month;
                this->discoveryDate_.day = day;
    }

    void setorigindate(int year, int month, int day){
        this->estimatedDateOfOrigin.year = year;
        this->estimatedDateOfOrigin.month = month;
        this->estimatedDateOfOrigin.day = day;
    }

    int getyearDiscoverydate(){
        return this->discoveryDate_.year;
    }
    int getmonthDiscoverydate(){
        return this->discoveryDate_.month;
    }
    int getdayDiscoverydate(){
        return this->discoveryDate_.day;
    }

    Artifact get(std::list<Artifact> _list, int _i){
        std::list<Artifact>::iterator it = _list.begin();
        for(int i=0; i<_i; i++){
            ++it;
        }
        return *it;
    }
};

class GreekArtifact: public Artifact{
private:
    std::string greekGod;

public:
    GreekArtifact(std::string name){
        this->greekGod = name;
    }
    GreekArtifact(){
        this->greekGod = "none";
    }

    void printGreek(){
        std::cout<<"Greek god: "<< this->greekGod<<std::endl;
        this->printArtefact();
    }
};

class EgyptianArtifact: public Artifact{
private:
    std::string pharaoh_;

public:
    EgyptianArtifact(){
        this->pharaoh_="none";
    }

    EgyptianArtifact(std::string name){
        this->pharaoh_ = name;
    }

    void printEgyptian(){
        std::cout<<"Egyptian god: "<< this->pharaoh_<<std::endl;
        this->printArtefact();
    }
};

bool compare(Artifact d1, Artifact d2)
{
    // All cases when true should be returned
    if (d1.getyearDiscoverydate() < d2.getyearDiscoverydate())
        return true;
    if (d1.getyearDiscoverydate() == d2.getyearDiscoverydate() && d1.getmonthDiscoverydate() < d2.getmonthDiscoverydate())
        return true;
    if (d1.getyearDiscoverydate() == d2.getyearDiscoverydate() && d1.getmonthDiscoverydate() == d2.getmonthDiscoverydate() &&
        d1.getdayDiscoverydate() < d2.getdayDiscoverydate())
        return true;

    // If none of the above cases satisfy, return false
    return false;
}

// Function to sort array arr[0..n-1] of dates
//void sortDates(Date arr[], int n)
//{
//    // Calling in-built sort function.
//    // First parameter array beginning,
//    // Second parameter - array ending,
//    // Third is the custom compare function
//    sort(arr, arr+n, compare);
//}

int main(){

    std::list<Artifact> artifacts;
    GreekArtifact g1 = GreekArtifact("Zeus");
    g1.setorigindate(1110,2,3);
    g1.setDiscoverydate(2022,10,5);
    g1.setCond("good");
    g1.setType("vase");
    GreekArtifact g2 = GreekArtifact("Athena");
    g2.setorigindate(100,2,3);
    g2.setDiscoverydate(2021,10,5);
    g2.setCond("poor");
    g2.setType("jewelry");
    GreekArtifact g3 = GreekArtifact("Socrates");
    g3.setorigindate(500,2,3);
    g3.setDiscoverydate(2010,9,5);
    g3.setCond("good");
    g3.setType("partialRelic");
    GreekArtifact g4 = GreekArtifact("Platon");
    g4.setorigindate(1500,2,3);
    g4.setDiscoverydate(2000,10,5);
    g4.setCond("mediocre");
    g4.setType("unknown");
    GreekArtifact g5 = GreekArtifact("Dionisos");
    g5.setorigindate(700,2,3);
    g5.setDiscoverydate(2020,5,5);
    g5.setCond("good");
    g5.setType("vase");
    EgyptianArtifact e1 = EgyptianArtifact("Ra");
    e1.setorigindate(200,2,3);
    e1.setDiscoverydate(2022,10,5);
    e1.setCond("good");
    e1.setType("vase");
    EgyptianArtifact e2 = EgyptianArtifact("Eleusius");
    e2.setorigindate(500,1,7);
    e2.setDiscoverydate(2021,2,4);
    e2.setCond("good");
    e2.setType("vase");
    EgyptianArtifact e3 = EgyptianArtifact("Tutankhamon");
    e3.setorigindate(500,2,3);
    e3.setDiscoverydate(2019,8,3);
    e3.setCond("good");
    e3.setType("jewelry");
    EgyptianArtifact e4 = EgyptianArtifact("Isis");
    e4.setorigindate(800,3,1);
    e4.setDiscoverydate(2022,6,3);
    e4.setCond("poor");
    e4.setType("partialRelic");
    EgyptianArtifact e5 = EgyptianArtifact("Osiris");
    e5.setorigindate(155,5,4);
    e5.setDiscoverydate(2022,9,3);
    e5.setCond("needSpecialHandling");
    e5.setType("unknown");

    artifacts.push_back(g1);
    artifacts.push_back(g2);
    artifacts.push_back(g3);
    artifacts.push_back(g4);
    artifacts.push_back(g5);
    artifacts.push_back(e1);
    artifacts.push_back(e2);
    artifacts.push_back(e3);
    artifacts.push_back(e4);
    artifacts.push_back(e5);

    artifacts.sort(compare);

    for(auto it: artifacts){
        it.printArtefact();
        std::cout<<std::endl;
    }

    std::map<std::string,std::list<Artifact>> museums;
    std::_List_iterator<Artifact> it = artifacts.begin();
    // Advance the iterator by 2 positions,
    std::advance(it, 5);
    museums["Acropolis Museum"] = std::list<Artifact>(artifacts.begin(), it);
    std::advance(it, 1);
    museums["The Egyptian Museum"] = std::list<Artifact>(it,artifacts.end());
    museums["GreekoEgyptian Museum"] = std::list<Artifact>(artifacts.begin(),artifacts.end());

    for(auto it = museums.begin(); it != museums.end(); ++it)
    {
        std::cout <<"Name: "<<it->first<< std::endl;

        for(auto jt: artifacts){
            jt.printArtefact();
            std::cout<<std::endl;
        }
    }

}