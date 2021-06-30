#include<bits/stdc++.h>
#include "courseType.h"

using namespace std;

int main(){
    courseType c;
    //std::ostream c;
    c.setCourseInfo("Riyaz", "B.Tech", 'A', 10);
    c.print(std::cout,true);
    cout<<" Credits: "<<c.getCredits()<<endl;
    cout<<"Testingggggggggggggggggggggggggggggggg";



    return 0;
}


