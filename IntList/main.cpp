#include <iostream>
using namespace std;
const int staerd = 20;
class IntList
{
private:
    int fylki[staerd];
    int teljari = 0;
    
public:
    void add(int i); // add fallið tekur inn breytuna i. Fylkið tekur svo gildið á i. i hækkar og fylkið fer í næsta stak.
    int getSize(); // finnur stærð fylkisins
    bool full(); // er fylkið fullt?
    
    friend void operator << (ostream& ut, IntList& right); // yfirskrifar <<. það sem er vinstrameginn við virkjan er cout'ið. það sem er hægta megin er það sem skrifast út.
    friend bool operator > (IntList& left, IntList& right); // yfirskrifa >. ef það sem er vinstramegin við virkjan er stærra en það sem er hægra megin þá return'ast true.
    friend IntList operator + (IntList& left, IntList& right); // yfirskrifa +. Það er IntList í yfirlýsingunni svo hægt sé að búa til nýtt tilvik af klasanum.
    
    
    //smiðir
    IntList(); // færibreytulaus smiður
    IntList(int fylki[], int teljari); // færibreytusmiður
};

int main()
{
    IntList list1, list2, list3, list4;   // Declare 4 integer lists
    
    for (int i = 0; i < 10; i++)          // Populate the first list
    {
        list1.add(i);
    }
    
    for (int i = 0; i < 5; i++)           // Populate the second list
    {
        list2.add(i * 2);
    }
    
    cout << list1;                        // Output the first list to the screen
    cout << list2;                        // Output the second list to the screen
    
    if (list1 > list2)
    {
        cout << "List 1 is larger than list 2" << endl;
    }
    else
    {
        cout << "List 1 is not larger than list 2" << endl;
    }
    
    list3 = list1 + list2;                // Add the first two lists
    cout << list3;                        // And output the result to the screen
    
    cout << "The size of list 3 is: " << list3.getSize() << endl;
    
    for (int i = 10; i < 25; i++)
    {
        list1.add(i);                     // Put more entries into list 1
    }
    
    cout << list1;                        // And output it
    
    if (list1.full())
    {
        cout << "List 1 is full!" << endl;
    }
    
    list4 = list3;                        // Assign the third list to the fourth
    cout << list4;
    
    return 0;
}

IntList::IntList()
{
    for(int i = 0; i < staerd; i++) // núllstill færibreytulausa smiðinn
    {
        fylki[i] = i;
    }
    teljari = 0;
}

IntList::IntList(int fyl[], int telj)
{
    for(int i = 0; i < staerd; i++) // fylli inn í færibreytusmiðinn
    {
        fylki[i] = fyl[i]; // fylkið tekur dgildi þess sem kemur inn
        telj++; // teljarinn hækkar
    }
    teljari = telj; // teljarinn tekur gildi telj.
}

void IntList::add(int i)
{
    if(i < staerd) // if-lykkja svo það sé ekki skrifað of mikið í fallið
    {
        fylki[teljari] = i; // það er forlykkja í main fallinu sem sér um að setja inn á réttann stað í fylkinu.
        teljari++;
    }
}

int IntList::getSize()
{
    return teljari; // sæki bara stærðina á fallinu frá teljaranum
}

bool IntList::full()
{
    if(teljari >= staerd) // stærð er constant of fylkið því fullt ef fylkið er stærri eða jaft og sá constant
    {
        return true;
    }
    return false;
}

void operator << (ostream& ut, IntList& right)
{
    for(int i = 0; i < right.teljari; i++) // for-lykkjan cout'ar öllu úr fylkinu
    {
        ut << right.fylki[i] << " "; // breyttum cout í ut í klasanum áðan.
    }
    ut << endl;
}

bool operator > (IntList& left, IntList& right) // ef það sem er vinstamegin er stærra skilar fallið true
{
    return left.teljari > right.teljari;
}

IntList operator + (IntList& left, IntList& right)
{
    IntList temp; // bý til nýtt tilvik af klasanum
    for(int i = 0; i < right.teljari; i++) // notum hægri því það er minna fylki
    {
        temp.fylki[i] = left.fylki[i] + right.fylki[i]; // nýja tilvikið af klasanum tekur gildið af klasanum sem er vinstamegin + hægramegin
    }
    temp.teljari = right.teljari; // teljarinn sem er hægrameginn var notaður í forlykkjunni.
    return temp;
}