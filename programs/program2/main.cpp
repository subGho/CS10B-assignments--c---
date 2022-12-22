#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned locOfMonth;
   unsigned year;
   vector<string> listOfMonths = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

 public:
   // creates the date January 1st, 2000.
   Date();  


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;

   // makes input lowercase
   string stringToLower (string input);
   //returns index of month
   unsigned indexOfMonth (string inputMonth);
};

unsigned Date::indexOfMonth(string inputMonth) 
{
   for (unsigned int i=0; i<listOfMonths.size(); i++)
   {
      if (stringToLower(inputMonth) == listOfMonths.at(i))
      {
         // cout<<endl<<stringToLower(inputMonth)<<endl<<<<endl;
         locOfMonth = i;
         return locOfMonth;
      }
      
   }
   return 99;
}

unsigned Date::number(const string &mn) const
{
   return locOfMonth + 1;
}

string Date::name(unsigned m) const
{
   return listOfMonths.at(m-1);
}

string Date::stringToLower(string input)
{
   for (unsigned int i=0; i<input.size(); i++)
    {
      input.at(i) = tolower(input.at(i));
    }
  return input;
}

// Implement the Date member functions here

Date::Date()
{
   this->day = 1;
   this->month = 1;
   this->monthName = "January";
   this->year = 2000;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{
   if (m==2 && (isLeap(y)))
   {
      return 29;
   }
   else if (m==2)
   {
      return 28;
   }
   else if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
   {
      return 31;
   }
   else 
      return 30;
}

Date::Date(unsigned m, unsigned d, unsigned y)
{
   unsigned int daysAllowed = daysPerMonth(m, y);
   this->day = d;

   if (m>12)
   {
      this->month = 12;
      // cout<<"Invalid date values: palllaaDate corrected to "<<this->month<<"/"<<this->day<<"/"<<y<<"."<<endl;
   }
   else if (m<1)
   {
      daysAllowed = daysPerMonth(1, y);
      if (d<=daysAllowed && d>0)
      {
         this->day = 1;
         
      }
      // cout<<d<<endl;
      this->month = 1;
      //here has right date
      // cout<<"Invalid date values: Date corrected to "<<this->month<<"/"<<this->day<<"/"<<y<<"."<<endl;
   }
   else
   {
      this->month = m;
   }
   this->monthName = name(this->month);
   this->monthName.at(0) = toupper(this->monthName.at(0));
   daysAllowed = daysPerMonth(this->month, y);
   if (this->day == 0)
   {
      this->day = 1;
      // if (m<=12 && m>=1)
      // {
      //    cout<<"Invalid date values: Date corrected to "<<this->month<<"/"<<this->day<<"/"<<y<<"."<<endl;
      // }
      // cout<<"Invalid date values: Date corrected to "<<this->month<<"/"<<this->day<<"/"<<y<<"."<<endl;
   }
   else if (this->day<=daysAllowed)
   {
      // cout<<daysAllowed<<endl;
      this->day = this->day;
   }
   else
   {
      this->day = daysAllowed;
      if (m<=12 && m>=1)
      {
         // cout<<"Invalid date values: Date corrected to "<<m<<"/"<<this->day<<"/"<<y<<"."<<endl;
      }
   }
   this->year = y;

   daysAllowed = daysPerMonth(m,y);
   if (m == 0)
   {
      daysAllowed = daysPerMonth(1,y);
   }
   
   if (m<=0 || m>12 || d>daysAllowed || d<0)
   {
      cout<<"Invalid date values: Date corrected to "<<this->month<<"/"<<this->day<<"/"<<y<<"."<<endl;
   }
   
}

Date::Date(const string &mn, unsigned d, unsigned y)
{
   
   this->monthName = mn;
   this->day = d;
   this->year = y;
   unsigned temp;
   if ((indexOfMonth(mn) != 99) && (indexOfMonth(mn)>= 0))
   {
      this->month = number(mn);
      temp = this->month;
      this->monthName.at(0) = toupper(this->monthName.at(0));
      unsigned int daysAllowed = daysPerMonth(temp, y);
      if (d == 0)
      {
         this->day = 1;
         cout<<"Invalid date values: Date corrected to "<<this->month<<"/"<<this->day<<"/"<<y<<"."<<endl;
      }
      else if (d<=daysAllowed)
      {
         this->day = d;
      }
      else
      {
         this->day = daysAllowed;
         cout<<"Invalid date values: Date corrected to "<<this->month<<"/"<<this->day<<"/"<<y<<"."<<endl;
      }

   }
   else
   {
      cout<<"Invalid month name: the Date was set to 1/1/2000."<<endl;
      this->day = 1;
      this->year = 2000;
      this->month = 1;
      this->monthName = "January";
   }
   
}

bool Date::isLeap(unsigned y) const
{
   if (y % 400 == 0)
    {
        return true;
    }
    else if (y % 4 == 0)
    {
        if (y % 100 != 0)
        {
            return true;
        }
        else 
        {
        return false;
        }
    }
    else 
    {
        return false;
    }
}

void Date::printNumeric() const
{
   cout<<this->month<<"/"<<this->day<<"/"<<this->year;
}

void Date::printAlpha() const
{
   
   cout<<this->monthName<<" "<<this->day<<", "<<this->year;
}





// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
