#include "Protein.h"
#include "Sequence.h"
#include"CodonsTable.h"
#include<iostream>
using namespace std;


Protein::Protein()
{
    //ctor
}
Protein::Protein(int length,char*p,Protein_Type atype):Sequence(length,p)
{
    type=atype;

}


Protein::~Protein()
{
    //dtor
}
