#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>

using namespace std;



string fileName;
vector<double> dataAngles;
vector<double> dataCoefs;
double reqFlightAngle;

void readData(const string &fileName, vector<double> &dataAngles, vector<double> &dataCoefs);
double interpolation(double reqFlightAngle, const vector<double> &dataAngles, const vector<double> &dataCoefs);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);


struct FlightInfo
{
    double inputFlightAngle;
    double inputLiftCoef;
};

int main(int argc, char *argv[]) 
{

    fileName = argv[1];
    readData(fileName, dataAngles, dataCoefs);
    // if (!isOrdered(dataAngles))
    //     reorder(dataAngles, dataCoefs);
    // else
    //     isOrdered(dataAngles);

    isOrdered(dataAngles);
    reorder(dataAngles,dataCoefs);

    


    // //test output for cout in terminal
    // for (int i=0; i<dataAngles.size(); i++)
    //     cout<<dataAngles.at(i)<<" ";
    // cout<<endl;
    // for (int i=0; i<dataCoefs.size(); i++)
    //     cout<<dataCoefs.at(i)<<" ";
    // //end of test output for cout in terminal

    string response;

    while (response != "No")
    {
        cout<<endl<<"Enter an angle to calculate flight lift coefficient: ";
        cin>>reqFlightAngle;
        cout<<endl<<interpolation(reqFlightAngle, dataAngles, dataCoefs)<<endl;
        cout<<"Would you like to enter another angle? ";
        cin>>response;
    }

    

    

}

void readData(const string &fileName, vector<double> &dataAngles, vector<double> &dataCoefs)
{
    ifstream inFS;
    inFS.open(fileName);
    if (!inFS.is_open())
   {
      cout<<"Error opening "<<fileName<<endl;
      exit(1);
   }

    FlightInfo entry;
    inFS>>entry.inputFlightAngle;
    while(!inFS.eof())
    {
        inFS>>entry.inputLiftCoef;
        dataAngles.push_back(entry.inputFlightAngle);
        dataCoefs.push_back(entry.inputLiftCoef);
        inFS>>entry.inputFlightAngle;
    }
   ofstream outFS;
   outFS.close();
}


int dataIndex = 0;




double interpolation(double reqFlightAngle, const vector<double> &dataAngles, const vector<double> &dataCoefs)
{
    int temp;
    int angleBel = 0;
    int angleAbov = 1;

    double a, b, c;
    double fa, fb, fc;
    if (count(dataAngles.begin(), dataAngles.end(), reqFlightAngle))
    {
        dataIndex = find(dataAngles.begin(), dataAngles.end(), reqFlightAngle) - dataAngles.begin();
        return dataCoefs.at(dataIndex);
    }
    else
    {
        temp = fabs(dataAngles.at(0) - dataAngles.at(1));
        for (unsigned int i=0; i<dataAngles.size()-1; i++)
        {
            if (reqFlightAngle > dataAngles.at(i) && reqFlightAngle < dataAngles.at(i+1))
            {
                if ((fabs(dataAngles.at(i) - dataAngles.at(i+1)))<=temp)
                {
                temp = fabs(dataAngles.at(i) - dataAngles.at(i+1));
                angleBel = i;
                angleAbov = i+1;
                }
            }
        }
    }
    a = dataAngles.at(angleBel);
    fa = dataCoefs.at(angleBel);
    b = reqFlightAngle;
    // fb = 
    c = dataAngles.at(angleAbov);
    fc = dataCoefs.at(angleAbov);

    fb = fa + ((b-a)/(c-a))*(fc-fa);
    // cout<<fa<<" "<<fc<<endl;
    return fb;
    
}

bool isOrdered(const vector<double> &dataAngles)
{
    
    if (dataAngles.size() == 0)
    {
        return true;
    }
    for (unsigned int i=0; i<dataAngles.size()-1; i++)
    {
        

        if (dataAngles.at(i) > dataAngles.at(i+1))
        {
            return false;
        }
        
    }
    return true;
}

void reorder(vector<double> &dataAngles, vector<double> &dataCoefs)
{

    if (dataAngles.size() == 0)
    {
        exit(1);
    }
    unsigned int minInd;

        for (unsigned int i=0; i<dataAngles.size()-1; i++)
        {

            minInd = i;

            for (unsigned int j=i+1; j<dataAngles.size(); j++)
            {
            
                if (dataAngles.at(j) < dataAngles.at(minInd))
                {
                    minInd = j;


                }

                
            }
            if (minInd != i)
                {
                    double tempAngle = dataAngles.at(minInd);
                    dataAngles.at(minInd) = dataAngles.at(i);
                    dataAngles.at(i) = tempAngle;

                    double tempCoef = dataCoefs.at(minInd);
                    dataCoefs.at(minInd) = dataCoefs.at(i);
                    dataCoefs.at(i) = tempCoef;
                }
        }
}