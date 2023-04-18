#include <iostream>
#include <string.h>
#include <vector>
#include <stdexcept>

using namespace std;

const int MAX_PROCESSES = 100;
const int MAX_RESOURCES = 100;

int allocated[MAX_PROCESSES][MAX_RESOURCES];

int max_need[MAX_PROCESSES][MAX_RESOURCES];

int need[MAX_PROCESSES][MAX_RESOURCES];

int available[MAX_RESOURCES];

int num_processes, num_resources;

vector<int> safe_sequence;

void print_safe_sequence()
{
    for (int i = 0; i < safe_sequence.size(); i++)
    {
        cout << "P" << safe_sequence[i] << " ";
    }
    cout << endl;
}

bool is_safe(int process_id)
{
    for (int i = 0; i < num_resources; i++)
    {
        if (need[process_id][i] > available[i])
        {
            return false;
        }
    }
    return true;
}

bool find_safe_sequence(bool marked[])
{
    bool found_safe_sequence = false;
    for (int i = 0; i < num_processes; i++)
    {
        if (!marked[i] && is_safe(i))
        {
            marked[i] = true;
            for (int j = 0; j < num_resources; j++)
            {
                available[j] += allocated[i][j];
            }
            safe_sequence.push_back(i);
            if (find_safe_sequence(marked))
            {
                found_safe_sequence = true;
            }
            safe_sequence.pop_back();
            for (int j = 0; j < num_resources; j++)
            {
                available[j] -= allocated[i][j];
            }
            marked[i] = false;
        }
    }
    if (!found_safe_sequence)
    {
        if (safe_sequence.size() == num_processes)
        {
            print_safe_sequence();
            return true;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    try
    {
        cout << "Enter the number of processes: ";
        cin >> num_processes;
        if (num_processes <= 0)
        {
            throw invalid_argument("Invalid number of processes");
        }

        cout << "Enter the number of resources: ";
        cin >> num_resources;
        if (num_resources <= 0)
        {
            throw invalid_argument("Invalid number of resources");
        }

        cout << "Enter the allocation matrix:\n";
        for (int i = 0; i < num_processes; i++)
        {
            for (int j = 0; j < num_resources; j++)
            {
                cin >> allocated[i][j];
            }
        }

        cout << "Enter the maximum need matrix:\n";
        for (int i = 0; i < num_processes; i++)
        {
            for (int j = 0; j < num_resources; j++)
            {
                cin >> max_need[i][j];
                need[i][j] = max_need[i][j] - allocated[i][j];
            }
        }

        cout << "Enter the available resources:\n";
        for (int i = 0; i < num_resources; i++)
        {
            cin >> available[i];
            if (available[i] < 0)
            {
                throw invalid_argument("Invalid available resources");
            }
        }

        bool marked[num_processes];
        memset(marked, false, sizeof(marked));

        cout << "Safe sequences are:\n";
        find_safe_sequence(marked);
    }
    catch (const invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}