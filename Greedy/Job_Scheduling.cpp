/*
Interval Scheduling Algorithm OR Job Scheduling Algorithm : 
Given a set of n intervals S = {(starti, endj) |1 ≤ i ≤ n}.
 Let us assume that we want to find a maximum subset S′ of S such that no pair of
intervals in S′ overlaps. Check whether the following algorithm works or not.
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Job
{
public:
    string job_id;
    int start_time;
    int end_time;
};

void insert(Job* j,int l)
{
    for(int i=0; i<l; i++)
    {
        j[i].job_id = "JOB_" +to_string(i+1);
        cout<<j[i].job_id<<" : "<<endl;
        cout<<"Enter the start time of "<< j[i].job_id<<" : ";
        cin >> j[i].start_time;
        while (j[i].start_time < 0)
        {
            cout<<"An invalid start time has been entered!"<<endl;
            cout<<"Please re-enter the start time (start time must be greater than zero) : ";
            cin>>j[i].end_time;
        }
        cout<<"Enter the end time of "<< j[i].job_id<<" : ";
        cin >> j[i].end_time;
        while(j[i].end_time < j[i].start_time)
        {
            cout<<"An invalid end time has been entered!"<<endl;
            cout<<"Please re-enter the end time (end time must be greater than start time) : ";
            cin>>j[i].end_time;
        }
    }
}

void display(Job* j,int l)
{
    for(int i=0; i<l; i++)
    {
        cout<<"Job id : "<< j[i].job_id<<endl;
        cout<<"start time : "<< j[i].start_time<<endl;
        cout<<"end time : "<< j[i].end_time<<endl;
    }
}

void display(vector<Job*> j)
{
    for(int i = 0; i< j.size();i++)
    {
        cout<<j[i]-> job_id<<" : "<<"( "<<j[i]-> start_time<<" , "<<j[i]-> end_time<<" );"<<endl;
    }
}

bool compare_endtime(Job j1, Job j2)
{
    return (j1.end_time < j2.end_time);
}

vector<Job*> schedule(Job* job,int len)
{
	sort(job,job+len,compare_endtime);
	display(job,len);
    vector<Job*> j;
    j.push_back(job++);
    for(int i=1; i<len; i++)
    {
        if(job -> start_time >= j.back() -> end_time)
        {
            j.push_back(job);
        }
        job++;
    }
    return j;
}

int main()
{
    int num;
    cout << "Enter Numbers of jobes : ";
    cin >> num;
    Job jobes[num];
    insert(jobes,num);
    vector<Job*> schedule_jobes = schedule(jobes,num);
    cout<<"Scheduled JObs is as follows :"<<endl;
    display(schedule_jobes);
    return 0;
}
