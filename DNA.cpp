#include "DNA.h"
#include "Sequence.h"
#include "RNA.h"
#include<iostream>
using namespace std;


DNA::DNA()
{
    startIndex=0;
    endIndex=0;
    //Default constructor
}
DNA::DNA(int length,char* se_q,DNA_Type atype):Sequence(length,se_q)///Constructor
{
    type=atype;
}
DNA::DNA(DNA& rhs)
{
  length=rhs.length;
  seq=new char[length];
  for(int i=0;i<length;i++)
        seq[i]=rhs.seq[i];
  this->type=type;
}
void DNA::BuildComplementaryStrand()
      /// Function that converts each A to T, each T to A, each C to G, and
        /// each G to C. Then reverse the resulting sequence to make the second strand.
{
    int x,y;
    cout<<"Enter your first index and end index "<<endl;
    cin>>x;
    cin>>y;
    if(x==-1|| y==-1)
    {
        startIndex=0;
        endIndex=length;

        for(int i=startIndex;i<endIndex;i++)
    {
        if(*(seq+i)=='A')
            *(seq+i)='T';
        else if(*(seq+i)=='T')
                *(seq+i)='A';
        else if(*(seq+i)=='C')
            *(seq+i)='G';
        else if(*(seq+i)=='G')
            *(seq+i)='C';

    }
     int j=endIndex;
    char*seq1=new char[length];
    for(int i=startIndex;i<endIndex;i++)
    {
        seq1[i]=seq[j];
        j--;
     }
     for(int i=0;i<endIndex;i++)
    {

        seq[i]=seq1[i];

    }

    }
    else
    {
        startIndex=x;
        endIndex=y;
        for(int i=startIndex;i<endIndex;i++)
    {
        if(*(seq+i)=='A')
            *(seq+i)='T';
        else if(*(seq+i)=='T')
                *(seq+i)='A';
        else if(*(seq+i)=='C')
            *(seq+i)='G';
        else if(*(seq+i)=='G')
            *(seq+i)='C';

    }

     int j=endIndex;
    char*seq1=new char[length];
    for(int i=startIndex;i<endIndex;i++)
    {
        seq1[i]=seq[j];
        j--;
     }
     for(int i=0;i<endIndex;i++)
    {

        seq[i]=seq1[i];

    }


    }

}
void DNA::Print(){ ///Function to print DNA sequence to the user...
cout<<"The DNA Sequence from 3' to 5' is : "<<endl;
for(int i=0;i<length;i++)
    cout<<*(seq+i);
cout<<"The DNA sequence from 5' to 3' is "<<endl;
BuildComplementaryStrand();
for(int i=0;i<length;i++)
    cout<<*(seq+i);
if(this->type == 0)
    {
        cout<<" \nThe type of DNA is Promoter." << endl;
    }
else if(this->type == 1)
    {
        cout<<" \nThe type of DNA is Motif." << endl;
    }
else if(this->type == 2)
    {
        cout<<" \nThe type of DNA is nail." << endl;
    }
else if(this->type == 3)
    {
        cout<<" \nThe type of DNA is noncoding." << endl;
    }
else
    {
        cout<<" \nThis type is undefined." << endl;
    }


}
/**
* function to convert the DNA sequence to RNA sequence
* It starts by building the complementary_strand of the current
* DNA sequence (starting from the startIndex to the endIndex), then,
* it builds the RNA corresponding to that complementary_strand.
**/
RNA DNA::ConvertToRNA()
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
        else if (temp[i] == 'T')
        {
            temp[i] = 'U';
        }
        else if (temp[i] == 'G')
        {
            temp[i] = 'C';
        }
        else if (temp[i] == 'C')
        {
            temp[i] = 'G';
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

    RNA obj(temp , mRNA,length);
    return obj;

}






DNA::~DNA()
{
    ///destructor
}
