#include "Sequence.h"

Sequence::Sequence()
{
    seq = new char ;
    seq={};
    //ctor
}
Sequence::Sequence(int length, char* se_q)
{
    this->length=length;
    seq = new char [length];
    seq=se_q;
}
Sequence::Sequence(Sequence& rhs)
{
    seq=new char[length];
    for(int i=0;i<length;i++)
         *(seq+i)=*(rhs.seq+i);

}





Sequence::~Sequence()
{
    delete seq;
    //dtor
}
