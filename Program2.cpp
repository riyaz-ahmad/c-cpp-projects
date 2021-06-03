#include<bits/stdc++.h>

using namespace std;

int main(){
    cout<<"--------------Program Based on Newtons's Second Law------------------------"<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;

    float force, mass, acceleration;
    int choice;
    cout<<"*************CHOICES*************\n 1. Force(N) \n 2. Mass (kg) \n 3. Acceleration(m/s^2 \n 4. Exit"<<endl;
    cout<<"What you want to compute ";
    cin>>choice;
    while(choice != 4){
        switch(choice){
            case 1:
                cout<<"Enter mass: ";
                cin>>mass;
                cout<<"Enter acceleration: ";
                cin>>acceleration;
                force = mass*acceleration;
                cout<<"Force: "<<force<<"N"<<endl;
                break;
            case 2:
                cout<<"Enter force: ";
                cin>>force;
                cout<<"Enter acceleration: ";
                cin>>acceleration;
                mass = force/ acceleration;
                cout<<"Mass: "<<mass<<"KG"<<endl;
                break;
            case 3:
                cout<<"Enter force: ";
                cin>>force;
                cout<<"Enter mass: ";
                cin>>mass;
                acceleration = force/mass;
                cout<<"Acceleration: "<<acceleration<<"m/s^2"<<endl;
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<"Enter the correct choice"<<endl;
                break;
            }
            cout<<"What you want to compute ";
            cin>>choice;
    }
    return 0;
}