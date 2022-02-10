#include<conio.h>
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

// Mini Project - ATM
// -> check balance
// ->cash withdrawl
// ->usder details
// ->update mobile no.

class atm 
{
private:
    long int account_no;
    string name;
    int PIN;
    double balance;
    string  mobile_no;
public:
    void setData (
           long int accont_no_a,
           string name_a,
           int PIN_a,
           double balance_a,
           string mobile_no_a
    )
    {
        account_no = accont_no_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_no = mobile_no_a;
    }
    long int getAccountNo()
    {
        return account_no;
    }
    string getName()
    {
        return name;
    }
    int getPIN()
    {
        return PIN;
    }
    double getBalance()
    {
    return balance;
    }   
    string getMobile_no()
    {
        return mobile_no;
    }
  void setMobile(string mob_prv,string mob_new)
  {
      if(mob_prv != mob_new)
      {
          mobile_no = mob_new;
          cout<<endl<<"Successfully Updated Mobile no.";
          _getch();
      }
  }
  void cashWithdraw(int amount_a)
  {
      if(amount_a>0&& amount_a<balance)
      {
          balance-=amount_a;
          cout<<endl<<"Please Collect Your Cash - ";
          cout<<endl<<"Available Balance : "<<balance;
          _getch();
      }
  else{
      cout<<endl<<"Invalid Input or Insufficient Balance !!!!";
      _getch();
     }
  }
};

int main()
{
    int choice =0, enterPIN;
    long int enterAccountNo;
    system("cls");
     atm user1;
    user1.setData(1234567,"Rahul",111,45000.90,"8938803106");
    do{
        system("cls");
        cout<<endl<<"** Welcome to Bisht's ATM **"<<endl;
        cout<<endl<<"Enter Account No. -> ";
        cin>>enterAccountNo;
        cout<<endl<<"Enter PIN -> ";
        cin>>enterPIN;
        if((enterAccountNo==user1.getAccountNo())&&(enterPIN==user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo,newMobileNo;
                system("cls");
                // user interface
                cout<<endl<<"** Welcome to Bisht's ATM **";
                cout<<endl<<"Select Option"; 
                cout<<endl<<"1. Check Balance";
                cout<<endl<<"2. Cash Withdraw";
                cout<<endl<<"3. Show User Details";
                cout<<endl<<"4. Update Mobie no.";
                cout<<endl<<"5. Exit"<<endl;
                cin>>choice;
                switch(choice)
                {
                    case 1:
                    cout<<endl<<"Your Bank balance is : "<<user1.getBalance();
                    _getch();
                    break;

                    case 2:
                    cout<<endl<<"Enrer the amount - ";
                    cin>>amount;
                    user1.cashWithdraw(amount);
                    break;
                    case 3:
                    cout<<endl<<"User Detil are :- ";
                    cout<<endl<<"-> Account no - "<<user1.getAccountNo();
                    cout<<endl<<"-> Name - "<<user1.getName();
                    cout<<endl<<"-> Balance - "<<user1.getBalance();
                    cout<<endl<<"-> Mobile No. - "<<user1.getMobile_no();
                    _getch();
                    break;

                    case 4:
                    cout<<endl<<"Enter old Mobile No. - ";
                    cin>>oldMobileNo;

                    cout<<endl<<"Enter New Mobile No.- ";
                    cin>>newMobileNo;

                    user1.setMobile(oldMobileNo,newMobileNo);
                    break;

                    case 5:
                    exit(0);

                    default:
                    cout<<endl<<"Enter Valid Data !!!!";
                }
            } while ( 1/* condition */);
        }
        else
        {
            cout<<endl<<"User Daetails are Invalid !!!!";
            _getch();
        }
    }while(1);
    return 0;
}
