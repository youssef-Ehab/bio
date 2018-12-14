#ifndef PROTEIN_H
#define PROTEIN_H
#include "Sequence.h"
#include "DNA.h"
#include "CodonsTable.h"


enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
  	private:
        Protein_Type type;
      public:
 	 	// constructors and destructor
 	 	Protein();
 	 	Protein(int length,char * p,Protein_Type atype);
 	 	~Protein();
 	 	// return an array of DNA sequences that can possibly
                // generate that pr111otein sequence
           DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);
};
#endif // PROTEIN_H
