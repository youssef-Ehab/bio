#include "RNA.h"
#include "Protein.h"
#include "Sequence.h"
#include "DNA.h"
#include "CodonsTable.h"
#include<iostream>
using namespace std;


RNA::RNA()
{
    //constructor
}

RNA::RNA(char * seq, RNA_Type atype,int length):Sequence(length,seq)
{
    type=atype;
}
RNA::RNA(RNA& rhs)
{
    length=rhs.length;
    seq=new char [length];
    for(int i=0;i<length;i++)
        seq[i]=rhs.seq[i];
    type=rhs.type;
}
void RNA::Print() ///Function to print RNA sequence
{
    cout<<"RNA sequence is "<<endl;
    for(int i=0;i<length;i++)
        cout<<*(seq+i);
}

/// function to convert the RNA sequence back to DNA
DNA  RNA::ConvertToDNA()
        {
            char* temp=new char[length];
    for(int i=0;i<length;i++)
        temp[i]=seq[i];
    for (int i=0; i<length; i++)
    {
        if (temp[i] == 'A')
        {
            temp[i] = 'A';
        }
        else if (temp[i] == 'U')
        {
            temp[i] = 'T';
        }
        else if (temp[i] == 'G')
        {
            temp[i] = 'G';
        }
        else if (temp[i] == 'C')
        {
            temp[i] = 'C';
        }
    }

    char *temp1=new char[1];
    for (int i=0; i<length/2; i++)
    {
        temp1[0] = temp[i];
        temp[i] = temp[length-i-1];
        temp[length-i-1] = temp1[0];
    }

    cout << "mRNA Sequence: ";
    for (int i=0; i<length; i++)
        cout << temp[i];

    DNA obj(length,temp ,promoter );
    return obj;
        }

// Protein ConvertToProtein(const CodonsTable & table){
//
//
//
//
//
//
// }
//// {




 //}














RNA::~RNA()
{
    ///destructor
}
