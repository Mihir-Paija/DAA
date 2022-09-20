/*
Fractional Knapsack problem : 
Given set S of  items x1: x2, ...,xn (items we might want to
carry in our backpack) with associated weights w1,w2, ... , wn and benefit values b1, b2, …,bn,
how can we maximize the total benefit considering that we are subject to an absolute
weight limit W?
Objective : maximize Σ bi(xi/wi) ;(for all i in S)
Constaint: Σ xi  <= W ;(for all i in S)
*/
#include<bits/stdc++.h>
using namespace std;

class Item
{
    public:
    int item_number;
    int benefit;
    int weight;
    int x=0;
    double bpw; //benefit per weight (benefit/weight)
};


void insert(Item* itm,int len)
{
    for(int i=0; i<len; i++)
    {
        itm[i].item_number = (i+1)*100 + (i+1)*10 +  (i+1);
        cout<<itm[i].item_number<<" : "<<endl;
        cout<<"Enter the benefit of "<< itm[i].item_number<<" : ";
        cin >> itm[i].benefit;
        while (itm[i].benefit < 0)
        {
            cout<<"An invalid benefit has been entered!"<<endl;
            cout<<"Please re-enter the benefit (benefit must be greater than zero) : ";
            cin>> itm[i].benefit;
        }
        cout<<"Enter the weight of "<< itm[i].item_number<<" : ";
        cin >> itm[i].weight;
        while(itm[i].weight < 0)
        {
            cout<<"An invalid weight has been entered!"<<endl;
            cout<<"Please re-enter the weight (weight must be greater than zero) : ";
            cin>>itm[i].weight;
        }
        itm[i].bpw = itm[i].benefit/itm[i].weight;
    }
}

void display(Item* itm,int len)
{
    for(int i=0; i<len ; i++)
    {
        cout<<"Item number : "<< itm[i].item_number<<endl;
        cout<<"Item Benefit : "<< itm[i].benefit<<endl;
        cout<<"Item Weight : "<< itm[i].weight<<endl;
    }
}
void display_knapsack(Item* itm,int len)
{
    int B=0;
    cout<<"Item number (amount of that itmen in kanpsack)"<<endl;
    for(int i=0; i<len ; i++)
    {
        if(itm[i].x != 0)
        {
            cout<< itm[i].item_number <<" ("<<itm[i].x<<")"<<endl;
            B += (itm[i].x * itm[i].bpw);
        }
    }
    cout<<"Total Benefit is : "<<B<<endl;
}

int compare_bpw (const void* x,const void * y)
{
    Item* a =(Item *)x;
    Item* b =(Item *)y;
    return (b->bpw - a->bpw);
}

void Fractional_Knapsack(Item* itm,int len,int W)
{
    qsort(itm,len,sizeof(Item),compare_bpw);
    // display(itm,len);
    int w = W;
    int i=0;
    while(w>0 || i>len)
    {
        itm[i].x = min(itm[i].weight,w);
        w = w - min(itm[i].weight,w);
        i++;
    }
}

int main()
{
    int num,W;
    cout<<"Enter number of items : ";
    cin >> num;
    Item* items = new Item[num];
    insert(items,num);
    cout<<"Enter Total Weight of Knapsack : ";
    cin >> W;
    Fractional_Knapsack(items,num,W);
    cout<<"Knapsack Solution is as follows : "<<endl;
    display_knapsack(items,num);
    return 0;
}