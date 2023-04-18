#include <bits/stdc++.h>
using namespace std;

struct PageTable
{

    int frame_no;
    bool valid;
};

bool isPagePresent(struct PageTable PT[], int page)
{
    if (PT[page].valid == 1)
    {
        return true;
    }

    return false;
}

void printFrame(int frame[], int no_of_frames)
{

    for (int i = 0; i < no_of_frames; i++)
    {
        cout << frame[i] << " ";
    }
    cout << endl;
}

void updatePageTable(struct PageTable PT[], int page, int fr_no, int status)
{
    PT[page].valid = status;

    PT[page].frame_no = fr_no;
}

int main()
{
    int no_of_frames, page_fault = 0, currrent = 0;
    int n;
    bool flag = false;

    cout << "Enter the number of pages" << endl;
    cin >> n;

    // create a reference string array

    int reference_string[n];

    cout << "Enter the reference string : " << endl;
    for (int j = 0; j < n; j++)
    {
        cin >> reference_string[j];
    }

    cout << "Enter the bo, of frames you want to procesas" << endl;
    cin >> no_of_frames;

    int frame[no_of_frames];

    for (int j = 0; j < no_of_frames; j++)
    {
        frame[j] = -1;
    }

    struct PageTable PT[50];

    for (int j = 0; j < n; j++)
    {
        PT[j].valid = 0;
    }

    for (int j = 0; j < n; j++)
    {

        if (!(isPagePresent(PT, reference_string[j])))
        {
            page_fault++;

            if (flag == false && currrent < no_of_frames)
            {
                frame[currrent] = reference_string[j];
                printFrame(frame, no_of_frames);
                updatePageTable(PT, reference_string[j], currrent, 1);

                currrent = currrent + 1;

                if (currrent == no_of_frames)
                {
                    currrent = 0;
                    flag = true;
                }
            }

            else
            {
                updatePageTable(PT, frame[currrent], -1, 0);
                frame[currrent] = reference_string[j];
                printFrame(frame, no_of_frames);
                updatePageTable(PT, reference_string[j], currrent, 1);

                currrent = (currrent + 1) % no_of_frames;
            }
        }
    }
    cout << "Total page fault" << page_fault << "" << endl;
    // cout<<"Total page fault"<<page_fault<<""<<endl;

    return 0;
}