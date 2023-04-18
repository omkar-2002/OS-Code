#include <bits/stdc++.h>
using namespace std;
int main()
{
    int total_head = 0;

    int initial_pos;

    int n;

    cout << "Enter the np. cylinder request queue" << endl;
    cin >> n;

    int request_queue[n];

    cout << "Enter the cylinder no. in request queue" << endl;

    for (int i = 0; i < n; i++)
    {
        cin>>request_queue[i];
    }

    cout<<"Enter the inital Position of Read write header"<<endl;

    cin>>initial_pos;


    for(int i = 0; i<n; i++)
    {
        total_head += abs(initial_pos - request_queue[i]);
        initial_pos = request_queue[i];
    }

    cout<<"Total Number of ZHead Movment :- "<<total_head<<" ";

        return 0;
}