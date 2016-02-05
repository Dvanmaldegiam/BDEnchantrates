//Black Desert enchanting simulator
//This program simulates trying to enchant a weapon at +15 or higher

#include <iostream>
#include <math.h>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <limits>
using namespace std;

int main()
{
int starting_enchant=0;
int desired_enchant=0;
int bstone_market_rate=0;
int total_cost;
int attempts=0;
double rng;
srand (time(NULL));

double enchant_rate[5]= {.2,.2,.05,.025,.02};

    cout << "enter starting enchant level(between 15 and 19)\n" << endl;
    cin>>starting_enchant;
    while(starting_enchant<15 || starting_enchant>=20 || cin.fail())
    {

        if(cin.fail())
        {
            cin.clear();
            cout<< "Invalid. Input must be numeric. \n";
            cout<< "Invalid. Input must be numeric. \n";

        }
        else if(starting_enchant<15 || starting_enchant>=20)
        {
            cout<<"Starting value must be between 15 and 19\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "enter starting enchant level\n" << endl;
        cin>>starting_enchant;
    }


    cout << "enter desired enchant level(between 16 and 20)" << endl;
    cin>>desired_enchant;

    while(desired_enchant<16 || desired_enchant>20 || cin.fail())
    {

        if(cin.fail())
        {
            cin.clear();
            cout<< "Invalid. Input must be numeric. \n";
        }
             else if(desired_enchant<16 || desired_enchant>20)
        {
            cout<<"Starting value must be between 16 and 20\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "enter desired enchant level" << endl;
        cin>>desired_enchant;

    }



    cout <<"enter Blackstone market cost" << endl;
    cin>> bstone_market_rate;

    int enchant_level=starting_enchant;
    while(enchant_level!=desired_enchant)
        {

            attempts++;
            rng=(rand()%10000)/100;

            if(rng<enchant_rate[enchant_level-15]*100)
                {
                    enchant_level++;
                }
            else if(enchant_level>15)
            {
                enchant_level-=1;

            }


        }

total_cost=attempts* bstone_market_rate;
cout<<"It took you " <<attempts <<" Blackstones to enchant your weapon to +" <<enchant_level <<endl;
cout<<"It cost you "<<total_cost <<" silver to enchant your weapon!"<<endl;




}
