#include<bits/stdc++.h>
using namespace std;
int findCloseCylinder(int request_queue[], int initial_pos, bool visited[], int n)
{
    int min = INT_MAX; 
    int min_index = -1;

    for(int i = 0; i<n; i++)
    {
        if(visited[i] == false && abs(initial_pos - request_queue[i])<min)
        {
            min = abs(initial_pos - request_queue[i]);
            min_index = i;        }
    }

    return min_index;

}
int SSTF(int request_queue[], int initial_pos, bool visited[], int seek_seq[], int n)
{

    int i = 0; 
    int completed = 0;
    int total_head = 0;


    while(completed != n)
    {
        int min_index = findCloseCylinder(request_queue, initial_pos, visited, n);

        total_head += abs(initial_pos - request_queue[min_index]);
        initial_pos = request_queue[min_index];
        seek_seq[i++] = request_queue[min_index];
        visited[min_index] = 1;
        completed++;
    }

    return total_head;

}
int main()
{


    int total_cylinder, total_head_movement, initial_pos,n;

    cout<<"Enter the Total Number of cylinder in HDD"<<endl;

    cin>>total_cylinder;

    if(total_cylinder <= 0)
    {
        cout<<"Must greater than 0";
        exit(0);
    }

    cout<<"Enter the no. of cylinder in request queue"<<endl;

    cin>>n;

    int request_queue[n];
    int seek_sequence[n];

    cout<<"Enter the number of cylinder no. in request queue"<<endl;

    for(int i = 0; i<n; i++)
    {
        cin>>request_queue[i];
    }

    cout<<"enter the inital Position of RW head"<<endl;
    cin>>initial_pos;

    bool visited[total_cylinder] = {0};

    // if()

    total_head_movement = SSTF(request_queue, initial_pos, visited, seek_sequence, n);

    cout<<total_head_movement<<"";

 return 0;
}