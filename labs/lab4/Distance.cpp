#include <iostream>

using namespace std;
#include "Distance.h"

Distance::Distance()
{
    this->feet = 0;
    this->inches = 0.0;
    init();
}

Distance::Distance(unsigned ft, double in)
{
    this->feet = ft;
    this->inches = in;
    init();
}

Distance::Distance(double in)
{
    this->feet = 0;
    this->inches = in;
    init();
}

unsigned Distance::getFeet() const
{
    if (this->feet > 4000000000)
    {
        return 4294967296 - this->feet;
    }
    
    return this->feet;

    
}

double Distance::getInches() const
{
    if (this->inches < 0)
    {
        return this->inches*-1;
    }
    return this->inches;
}

double Distance::distanceInInches() const
{
    return this->inches + (double) this->feet*12;
}

double Distance::distanceInFeet() const
{
    return (double) this->feet + this->inches/12;
}

double Distance::distanceInMeters() const
{
    return distanceInInches()*0.0254;
}

Distance Distance::operator+(const Distance &rhs) const
{
    Distance distance;
    distance.feet = this->feet + rhs.feet;
    distance.inches = this->inches + rhs.inches;
    distance.init();
    return distance;
}

Distance Distance::operator-(const Distance &rhs) const
{
    Distance distance;
    if ((distanceInInches() > rhs.distanceInInches()))
    {
        
        // distance.feet = (distanceInInches() - rhs.distanceInInches());
        double tempIn;
        tempIn = distanceInInches()-rhs.distanceInInches();
        distance.feet = (int) tempIn/12;
        distance.inches = tempIn - distance.feet*12;

        // cout<<endl<<"ooga booga"<<endl;
        // distance.feet = this->feet - rhs.feet;
        // distance.inches = this->inches - rhs.inches;
        // cout<<endl<<(double) this->feet<<endl;
        // // cout<<"oogabooga"<<(double) this->feet*12 + this->inches<<"i wuv rachel hehe"<<endl;
        // // cout<<"did you know that i wuv rachel hehehe"<<" why she sound annoyeeddd"<<rhs.distanceInInches()<<endl;
    }
    else
    {
        // distance.feet = rhs.feet - this->feet;
        // distance.inches = rhs.inches - this->inches;

        double tempIn;
        tempIn = rhs.distanceInInches()-distanceInInches();
        distance.feet = (int) tempIn/12;
        distance.inches = tempIn - distance.feet*12;
    }
    
    distance.init();
    return distance;
}

ostream & operator<<(ostream &out, const Distance &rhs)
{
    out<<rhs.feet<<"' "<<rhs.inches<<"\"";
    return out;
}

// void Distance::init()
// {
//     while (this->inches >= 12)
//     {
//         this->inches -= 12;
//         this->feet++;
//     }
//     while (this->inches < 0)
//     {
//         this->feet--;
//         this->inches += 12;
//     }
// }

// TA said
void Distance::init()
{
    this->feet = getFeet();
    this->inches = getInches();
    while (getInches() >= 12)
    {
        this->inches = getInches()- 12;
        this->feet = getFeet() + 1;
    }
    if (this->inches < 0)
    {
        this->inches = getInches()*-1;
        this->inches = getInches() - 12;
        this->feet = getFeet() + 1;
    }
}
