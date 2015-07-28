#include <iostream>

using namespace std;

void insertionSort(int list[],int size)
{
    for(int i=1;i<size;i++)
    {
        int currentElement=list[i];
        int k;
        for(k=i-1;k>=0&&list[k]>currentElement;k-- )
        {
            list[k+1]=list[k];
        }
        list[k+1]=currentElement;
    }
}


int main()
{
    int size;

    cout<<"enter size:";
    cin>> size;

    int list[size];

    cout<<"\nenter elements:\n";

    for(int i=0;i<size;i++)
    {
        cin>>list[i];
    }

    insertionSort(list,size);

    cout<<"\nsorted:\n";

    for(int i=0;i<size;i++)
    {
        cout<<list[i]<<"\t";
    }

    return 0;
}