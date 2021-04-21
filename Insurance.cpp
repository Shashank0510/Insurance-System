#include<iostream>
#include<iomanip>
#include <ctime>
#include<stdlib.h>
#include <fstream>
#include <string>
#include<windows.h>
#include <stdexcept>

using namespace std;
ofstream myfile;
ofstream policy;
string myText;

class insurance_buyer
{
private:
    int option;
    string name;
    string  pan;
    string address ;
    string contact;
    long income;
    int age;
    string insured_name ;
    float premium;
    int policy_code;
    long m_amount;
    time_t now = time(0);
    static int count;
    long policy_number;
    string get_policy;
    int i;
public:
      void menu(int n)
    {   for(i=0; i<n; i++)
        cout<<"Enter your name: "<<endl;
        std::getline(std::cin >> std::ws,name);
        cout<<"\t\tWelcome Mr./Mrs. "<<name<<endl;
        cout<<"\t\tHow can I help you ?"<<endl;
        for(; ; )
        {
            cout<<"\t\t\t\t"<<"1.Buy an Policy"<<endl<<"\t\t\t\t"<<"2.Enquire about an policies available"<<endl<<"\t\t\t\t"<<"3.Get my policy details"<<endl<<"\t\t\t\t"<<"4.Exit"<<endl<<"\t\t\t\t"<<"5.Main Menu"<<endl;
            cout<<"Enter your choice:"<<" ";
            cin>>option;
            switch(option)
            {
                case 1:get_data(n);
                       displaydata(n);
                       break;
                case 2:policy_details(n);
                       break;
                case 3:get_my_policy(n);
                       break;
                case 4:exit(0);
                case 5:return;
                default:cout<<"Please enter the write option\n"<<endl;
                        break;
            }
        }
    }
    void get_data(int n)
    {
      for(i=0; i<n; i++)
      cout<<"--------------------------------------------------------------------------------------------------"<<endl;
      cout<<"Insurance is a subject of matter risk. Please read all scheme related documents thoroughly."<<endl;
      cout<<"--------------------------------------------------------------------------------------------------"<<endl;

      cout<<"Enter your name:"<<" ";
      std::getline(std::cin >> std::ws,name);
      cout<<"Enter your PAN:"<<" ";
      std::getline(std::cin >> std::ws,pan);
      cout<<"Enter your Address:"<<" ";
        std::getline(std::cin >> std::ws,address);
      cout<<"Enter your Contact Number:"<<" ";
      std::getline(std::cin >> std::ws,contact);
      cout<<"Minimum monthly income is 50000"<<endl;
      cout<<"Enter your Monthly Income:"<<" ";
      cin>>income;
      cout<<"Enter your Insured_Name:"<<" ";
        std::getline(std::cin >> std::ws,insured_name);
      cout<<"Enter your Policy_code(Refer Policies Available):"<<" ";
      cin>>policy_code;
      if(policy_code==1)
      {
          cout<<"Minimum age is 18."<<endl;
      }
      if(policy_code==2)
      {
          cout<<"Minimum age is 24."<<endl;

      }
      if(policy_code==3)
      {
          cout<<"Minimum age is 22."<<endl;
      }
      cout<<"Enter your age:"<<" ";
      cin>>age;
      policy_number=++count;

      cout<<"--------------------------------------------------------------------------------------------------"<<endl;



}
  void displaydata(int n)
    {
        for(i=0; i<n; i++)
        cout<<"Please check your details\n";
        cout<<"--------------------------------------------------------------------------------------------------"<<endl;
            cout<<"Name:    "<<name<<"\n";
            cout<<"Pan:     "<<pan<<"\n";
            cout<<"Address: "<<address<<"\n";
            cout<<"Contact: "<<contact<<"\n";
            cout<<"Monthly Income:  "<<income<<"\n";
            cout<<"Insured name:"<<insured_name<<"\n";
            cout<<"Age:"<<age<<endl;
            cout<<"Policy number: "<<policy_number<<endl;

            if(policy_code==1 && age<50 && age>=18 && income>=50000)
            {
                premium=0.05*income;
                cout<<"Policy Type :"<<"Life Insurance"<<endl;
                cout<<"Premium per_month :"<<premium<<endl;
                m_amount=premium*12*19+(premium*0.04);
                cout<<"Maturity amount:"<<m_amount<<endl;
                cout<<"Number of years of premium payment : "<<19<<endl;
                tm *ltm = localtime(&now);
                cout<<"Policy creation date:"<<1+ltm->tm_hour<<":"<<1+ltm->tm_min<<":"<<1+ltm->tm_sec<<" "<<ltm->tm_mday<<" "<<1+ltm->tm_mon<<" "<<1900+ltm->tm_year<<endl;
                cout<<"Maturity date:"<<ltm->tm_mday<<" "<<1+ltm->tm_mon<<" "<<1900+ltm->tm_year+20<<endl;

            }
            else if(policy_code==2 && age<50 && age>=24 && income>=50000)
            {
                premium=0.07*income;
                cout<<"Policy Type :"<<"Retirement Insurance"<<endl;
                cout<<"Premium per_month :"<<premium<<endl;
                m_amount=premium*12*14+(premium*0.05);
                cout<<"Maturity amount:"<<m_amount<<endl;
                cout<<"Number of years of premium payment : "<<14<<endl;
                tm *ltm = localtime(&now);
                cout<<"Policy creation date:"<<1+ltm->tm_hour<<":"<<1+ltm->tm_min<<":"<<1+ltm->tm_sec<<" "<<ltm->tm_mday<<" "<<1+ltm->tm_mon<<" "<<1900+ltm->tm_year<<endl;
                cout<<"Maturity date:"<<ltm->tm_mday<<" "<<1+ltm->tm_mon<<" "<<1900+ltm->tm_year+15<<endl;
            }
            else if(policy_code==3 && age<=50 && age>=22 && income>=50000)
            {
                premium=0.08*income;
                cout<<"Policy Type :"<<"General Insurance"<<endl;
                cout<<"Premium per_month :"<<premium<<endl;
                m_amount=premium*12*9+(premium*0.07);
                cout<<"Maturity amount:"<<m_amount<<endl;
                cout<<"Number of years of premium payment : "<<9<<endl;
                tm *ltm = localtime(&now);
                cout<<"Policy creation date:"<<1+ltm->tm_hour<<":"<<1+ltm->tm_min<<":"<<1+ltm->tm_sec<<" "<<ltm->tm_mday<<" "<<1+ltm->tm_mon<<" "<<1900+ltm->tm_year<<endl;
                cout<<"Maturity date:"<<ltm->tm_mday<<" "<<1+ltm->tm_mon<<" "<<1900+ltm->tm_year+10<<"\n"<<endl;
            }
        cout<<"--------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Press C to confirm your details or Press M to return to Menu"<<endl;
        char temp_choice;
        cin>>temp_choice;
        cout<<"--------------------------------------------------------------------------------------------------"<<endl;

        for(i=0; i<n; i++)

        if(temp_choice=='C' && age>=18 && income>=50000)
        {
           cout<<"The copy of the insurance document is available on desktop"<<endl;
           SetCurrentDirectory("C:\\Users\\Shashank Kadiwal\\Desktop");
           myfile.open("Insurance.txt");




        if (myfile.is_open())
        {
            myfile<<"Name:    "<<name<<"\n";
            myfile<<"Pan:     "<<pan<<"\n";
            myfile<<"Address: "<<address<<"\n";
            myfile<<"Contact: "<<contact<<"\n";
            myfile<<"Monthly Income:  "<<income<<"\n";
            myfile<<"Insured name:"<<insured_name<<"\n";
            myfile<<"Age:"<<age<<endl;
            myfile<<"Policy number :"<<policy_number<<endl;

            if(policy_code==1 && income>50000)
            {
                premium=0.05*income;
                myfile<<"Policy Type :"<<"Life Insurance"<<endl;
                myfile<<"Premium per_month :"<<premium<<endl;
                m_amount=premium*12*19+(premium*0.04);
                myfile<<"Maturity amount:"<<m_amount<<endl;
                myfile<<"Number of years of premium payment : "<<19<<endl;
                tm *ltm = localtime(&now);
                myfile<<"Policy creation date:"<<1+ltm->tm_hour<<":"<<1+ltm->tm_min<<":"<<1+ltm->tm_sec<<" "<<ltm->tm_mday<<" "<<1+ltm->tm_mon<<" "<<1900+ltm->tm_year<<endl;
                myfile<<"Maturity date:"<<ltm->tm_mday<<" "<<1+ltm->tm_mon<<" "<<1900+ltm->tm_year+20<<endl;

            }
            else if(policy_code==2  && income>50000)
            {
                premium=0.07*income;
                myfile<<"Policy Type :"<<"Retirement Insurance"<<endl;
                myfile<<"Premium per_month :"<<premium<<endl;
                m_amount=premium*12*14+(premium*0.05);
                myfile<<"Maturity amount:"<<m_amount<<endl;
                myfile<<"Number of years of premium payment : "<<14<<endl;
                tm *ltm = localtime(&now);
                myfile<<"Policy creation date:"<<1+ltm->tm_hour<<":"<<1+ltm->tm_min<<":"<<1+ltm->tm_sec<<" "<<ltm->tm_mday<<" "<<1+ltm->tm_mon<<" "<<1900+ltm->tm_year<<endl;
                myfile<<"Maturity date:"<<ltm->tm_mday<<" "<<1+ltm->tm_mon<<" "<<1900+ltm->tm_year+15<<endl;
            }
            else if(policy_code==3  && income>50000)
            {
                premium=0.08*income;
                myfile<<"Policy Type :"<<"Medical Insurance"<<endl;
                myfile<<"Premium per_month :"<<premium<<endl;
                m_amount=premium*12*9+(premium*0.07);
                myfile<<"Maturity amount:"<<m_amount<<endl;
                myfile<<"Number of years of premium payment : "<<9<<endl;
                tm *ltm = localtime(&now);
                myfile<<"Policy creation date:"<<1+ltm->tm_hour<<":"<<1+ltm->tm_min<<":"<<1+ltm->tm_sec<<" "<<ltm->tm_mday<<" "<<1+ltm->tm_mon<<" "<<1900+ltm->tm_year<<endl;
                myfile<<"Maturity date:"<<ltm->tm_mday<<" "<<1+ltm->tm_mon<<" "<<1900+ltm->tm_year+10<<"\n"<<endl;
            }


         cout<<"--------------------------------------------------------------------------------------------------"<<endl;
        }
        myfile.close();
        }
        else if(temp_choice=='M'){
                menu(n);
        }
        else
        {
            cout<<"Sorry,we cannot process your request as one of the conditions are not met.Please read the policy documents. "<<endl;

            exit(0);
        }
        cout<<"Thank you for visiting us."<<endl;
    }
    void policy_details(int n)
    {
         for(i=0; i<n; i++)
         cout<<"The copy of the policy details document is available on desktop"<<endl;
         cout<<"Thank you for visiting us."<<endl;
         SetCurrentDirectory("C:\\Users\\Shashank Kadiwal\\Desktop");
         policy.open("Policy_Docs.txt");
         if (policy.is_open())
          policy<<"Life Insurance"<<endl;
          policy<<"Life insurance is a contract between an insurer and a policy holder in which the insurer guarantees payment of a death benefit to named beneficiaries when insured dies"<<endl;
          policy<<"Premium amount: "<<"5% of monthly income"<<endl;
          policy<<"Number of years premium amount to be paid: "<<19<<endl;
          policy<<"Minimum age to invest "<<18<<endl;
          policy<<"Policy code: "<<1<<endl;
          policy<<"Maturity time: "<<20<<" years"<<endl;
          policy<<"--------------------------------------------------------------------------------------------------"<<endl;
          policy<<"Retirement Insurance"<<endl;
          policy<<"Retirement insurance is a contract between an insurer and a policy holder in which the insurer guarantees payment of a retirement benefit to named beneficiaries when insured retires."<<endl;
          policy<<"Premium amount: "<<"7% of monthly income"<<endl;
          policy<<"Number of years premium amount to be paid: "<<9<<endl;
          policy<<"Minimum age to invest "<<24<<endl;
          policy<<"Policy code: "<<2<<endl;
          policy<<"Maturity time: "<<15<<" years"<<endl;
          policy<<"--------------------------------------------------------------------------------------------------"<<endl;
          policy<<"Medical Insurance"<<endl;
          policy<<"Medical Insurance is a contract between an insurer and a policy holder in which the insurer guarantees payment of a medical benefit to named beneficiaries when insured is medically ill."<<endl;
          policy<<"Number of years premium amount to be paid: "<<9<<endl;
          policy<<"Minimum age to invest "<< 25<<endl;
          policy<<"Policy code: "<<3<<endl;
          policy<<"Maturity time: "<<10<<" years"<<endl;
          policy.close();
          }
     void get_my_policy(int n)
     {
            SetCurrentDirectory("C:\\Users\\Shashank Kadiwal\\Desktop");
            ifstream fin( "Insurance.txt" );
            cout<<"Enter the 6-digit policy number"<<endl;
            std::getline(std::cin >> std::ws,get_policy);
            string line;
            SetCurrentDirectory("C:\\Users\\Shashank Kadiwal\\Desktop");
            ifstream MyReadFile("Insurance.txt");
            while( getline( fin, line ) )
         {
            if( line.find( get_policy ) != string::npos )
            {

              while (getline (MyReadFile, myText))
              {
                 cout << myText<<endl;
              }


            }
         }
        }
};
int insurance_buyer::count=100000;
class admin : public insurance_buyer
{
private:
    string admin_name;
    string passcode;
public:
    void getinfo()
    {

        cout<<"Enter Admin Pin:"<<endl;
        cin>>passcode;
        if(passcode=="1234")
        {
            admin_name="User1";

        }
        else if(passcode=="12345")
        {

            admin_name="User2";
        }
        else
        {
            cout<<"Please enter the correct Admin Pin"<<endl;
            getinfo();
        }
    }
void admin_menu()
    {
        cout<<"\t\t"<<"Welcome Mr."<<admin_name<<endl;
        cout<<"\t\tHow can I help you ?"<<endl;
        int admin_choice;
        for(;;){
        cout<<"\t\t\t\t"<<"1.Read the list of insurance documents"<<endl<<"\t\t\t\t"<<"2.Main Menu"<<endl<<"\t\t\t\t"<<"3.Exit"<<endl;
        cout<<"Enter your choice :"<<endl;
        cin>>admin_choice;
        if(admin_choice==1)
        {
            SetCurrentDirectory("C:\\Users\\Shashank Kadiwal\\Desktop");
            ifstream MyReadFile("Insurance.txt");
            while (getline (MyReadFile, myText))
            {
                cout << myText<<endl;
            }
            MyReadFile.close();
        }
        if(admin_choice==1)
        {

         ifstream MyReadFile("Insurance.txt");
         if (MyReadFile.fail()) {

            cout<<"No records Found"<<endl;
        }
        }


        if(admin_choice==2)
        {
            return;
        }
        if(admin_choice==3)
        {
            exit(0);
        }
    }
    }



};
int main()
{
    int choice;
    for( ;;)
    {

        cout<<"\t\t"<<"-------------------- ABC Insurance Pvt.LTD --------------------"<<endl;
        cout<<"\t\t"<<"1.Administration  Login"<<endl;
        cout<<"\t\t"<<"2.User"<<endl;
        cout<<"\t\t"<<"3.Exit"<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>choice;
        if (choice==1)
        {
            admin a1;

            a1.getinfo();
            a1.admin_menu();
        }
        else if(choice==2)
        {    for( ;;){
            insurance_buyer cust1[10];
            int n;
            int i;
            cout<<"Enter number of customers"<<endl;
            cin>>n;
            for(i=0; i<n; i++)
            {
                 cust1[i].menu( n);

            }

        }



        }
        else
        {
            exit(0);
        }

    }
    return 0;
}
