#include <iostream>

using namespace std;

void loopArray(int array[]);

int main()
{
    int array[]={1,2,3,4,5,6,7,8,9};
    loopArray(array);
     
}

void loopArray(int array[]){
    for(int i=0;i<9;i++)
    {
        cout<<"Element #"<<i<<" : "<<array[i]<<endl;
    }
}