#include<bits/stdc++.h>
using namespace std;
int new_account(){
    int name,govt_id,pan_details;
    cout<<"enter name: "<<endl;
    cout<<"enter aadhaar no: "<<endl;
    cout<<"enter pan no: "<<endl;
    cout<<"details verified... :)";
    cout<<"Account created successfully: ";
    cout<<"Your A/c No: "<<rand() % 100000;
    cout<<"Thank You ";
}
int deposit_or_withdrawal(){
    //Code will be added soon... :)
}
int balance_inquiry(){
    //Code will be added soon... :)
}
int transaction_history(){
    //Code will be added soon... :)
}
int pin_authentication(){
    //Code will be added soon... :)
}
int main(){ 
    cout<<"\t\nWelcome to Model Bank\n\n";
    int op;
    cout<<"User Operations: "<<endl;
    cout<<"1.create a new account"<<endl;
    cout<<"2.Deposit/withdrawal"<<endl;
    cout<<"3.Balance inquiry"<<endl;
    cout<<"4.Transaction History"<<endl;
    cout<<"5.pin authentication"<<endl;
    cout<<"Enter the No Of Operation: "<<endl;
    cin>>op;
    switch(op){
        case 1:
            new_account();
            break;
        case 2:
            deposit_or_withdrawal();
            break;
        case 3:
            balance_inquiry();
            break;
        case 4:
            transaction_history();
            break;
        case 5:
            pin_authentication();
            break;
        defauilt:
            cout<<"Invalid Operation";

    }
}