#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

void setColor(int text, int background)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, background * 16 + text);
}

// Cost
const int cost_p_man = 100;
const int cost_p_equipment = 1000;

// Allocating global variable
int numproject = 0;
const int p = 100;

// Project info structure
struct project
{
    string name;
    // Start time
    int startdate;
    int startmonth;
    int startyear;
    // End time
    int enddate;
    int endmonth;
    int endyear;
    // Resources
    double fund;
    int manpower;
    int equipment;
    double profit;
};

// Functions
void createproject(struct project pr[], int *index);
double prof(double fnd, int man, int eqpmnt);
void displayproject(struct project proj[], int *n);
void printproject(struct project array[], int pos);
void sort_b_profit(struct project pr[], int length);
void displayproject_profit(struct project pro[], int *n);
void sortactivity(struct project projct[], int l);

int main()
{
    system("color F0");

    // Set text color to black
    setColor(0, 15);

    cout << "\n\n\n\n"
         << endl;
    cout << "===============================================" << endl;
    cout << "||          Project Management Tool          ||" << endl;
    cout << "===============================================" << endl;

    int choice;
    struct project projects[p];

    while (1)
    {
        cout << "------------------------------------" << endl;
        cout << "|          Menu                    |" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Create Project" << endl;
        cout << "2. Display Projects" << endl;
        cout << "3. Display Projects (Sorted by Profit)" << endl;
        cout << "4. Select Project Based on Finish Time" << endl;
        cout << "0. Exit" << endl;
        cout << "------------------------------------" << endl;

        cout << "Select task: ";
        cin >> choice;

        cout << "------------------------------------" << endl;
        cout << "\n\n"
             << endl;

        switch (choice)
        {
        case 1:
            createproject(projects, &numproject);
            break;
        case 2:
            displayproject(projects, &numproject);
            break;
        case 3:
            displayproject_profit(projects, &numproject);
            break;
        case 4:
            sortactivity(projects, numproject);
            break;
        case 0:
            cout << "         Thank you for working with us         " << endl;
            cout << "===============================================" << endl;
            return 0;
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }
}

double prof(double fnd, int man, int eqpmnt)
{
    return fnd - ((man * cost_p_man) + (eqpmnt * cost_p_equipment));
}

void createproject(struct project pr[], int *index)
{
    cout << "------------------------------------" << endl;
    cout << "|       Project Information        |" << endl;
    cout << "------------------------------------" << endl;
    if (*index < p)
    {
        struct project newproject;
        cout << "Project name: ";
        cin.ignore();
        getline(cin, newproject.name);
        cout << "Fund: ";
        cin >> newproject.fund;
        cout << "Start Date (DD MM YYYY): ";
        cin >> newproject.startdate >> newproject.startmonth >> newproject.startyear;
        cout << "End Date (DD MM YYYY): ";
        cin >> newproject.enddate >> newproject.endmonth >> newproject.endyear;
        cout << "Manpower: ";
        cin >> newproject.manpower;
        cout << "Equipment: ";
        cin >> newproject.equipment;

        newproject.profit = prof(newproject.fund, newproject.manpower, newproject.equipment);
        cout << "\n-------------------" << endl;
        cout << "Profit= $" << newproject.profit << endl;
        cout << "-------------------" << endl;

        if (newproject.profit > 0)
        {
            pr[*index] = newproject;
            (*index)++;
            cout << "\nProject added\n\n\n"
                 << endl;
        }
        else
        {
            cout << "\nProject cannot be added due to less fund\n\n\n"
                 << endl;
        }
    }
    else
        cout << "Project cannot be added due to insufficient slot" << endl;
}

void printproject(struct project array[], int pos)
{
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "            Project Name: " << array[pos].name << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Start Time: " << array[pos].startdate << "/" << array[pos].startmonth << "/" << array[pos].startyear << endl;
    cout << "End Time: " << array[pos].enddate << "/" << array[pos].endmonth << "/" << array[pos].endyear << endl;
    cout << "Fund: $" << array[pos].fund << endl;
    cout << "Manpower: " << array[pos].manpower << endl;
    cout << "Equipment: " << array[pos].equipment << endl;
    cout << "Profit: $" << array[pos].profit << endl;
    cout << "--------------------------------------------------------------------------" << endl;
}

void displayproject(struct project proj[], int *n)
{
    cout << "------------------------------------" << endl;
    cout << "|           All Projects:          |" << endl;
    cout << "------------------------------------" << endl;

    for (int i = 0; i < *n; i++)
        printproject(proj, i);
}

void sort_b_profit(struct project pr[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int max_idx = i;
        for (int j = i + 1; j < length; j++)
        {
            if (pr[max_idx].profit < pr[j].profit)
                max_idx = j;
        }
        if (max_idx != i)
            swap(pr[max_idx], pr[i]);
    }
}

void displayproject_profit(struct project pro[], int *n)
{
    struct project clone[p];
    for (int i = 0; i < *n; i++)
    {
        clone[i] = pro[i];
    }

    sort_b_profit(clone, *n);

    for (int i = 0; i < *n; i++)
        printproject(clone, i);
}

void sortactivity(struct project projct[], int l)
{
    sort(projct, projct + l, [](const project &a, const project &b)
         {
        if (a.endyear != b.endyear)
            return a.endyear < b.endyear;
        else if (a.endmonth != b.endmonth)
            return a.endmonth < b.endmonth;
        else
            return a.enddate < b.enddate; });

    cout << "\n\n------------------------------------" << endl;
    cout << "|        Selected Projects         |" << endl;
    cout << "------------------------------------\n"
         << endl;

    int count = 0;
    double total_prof = 0;

    int last_endyear = 0, last_endmonth = 0, last_enddate = 0;

    for (int i = 0; i < l; i++)
    {
        if (projct[i].startyear > last_endyear ||
            (projct[i].startyear == last_endyear && projct[i].startmonth > last_endmonth) ||
            (projct[i].startyear == last_endyear && projct[i].startmonth == last_endmonth && projct[i].startdate > last_enddate))
        {
            printproject(projct, i);
            total_prof += projct[i].profit;
            last_endyear = projct[i].endyear;
            last_endmonth = projct[i].endmonth;
            last_enddate = projct[i].enddate;
            count++;
        }
    }

    cout << "\n\nNumber of selected projects: " << count << endl;
    cout << "\n---------------------------------------------" << endl;
    cout << "Total Profit from selected projects: $" << total_prof << endl;
    cout << "---------------------------------------------\n"
         << endl;
}
