#include <iostream>
#include <fstream>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"


using namespace std;

int main()
{
    DNA d;
    RNA r;
    Protein p;
    char*file;
    string filename;
    string loaded;
    int convertORlcs;
    int length;
    int insideLCS;
    int insideConversion;
    int zero;
    cout << "Enter the length of your sequence"<<endl;
    cin >> length;
    char *str1 =(char*)malloc(sizeof(char) * length);
    char *str2 =(char*)malloc(sizeof(char) * length);
     cout << "1) Load sequence from file"<<endl;
     cout<<" 2) Enter the sequence"<<endl;
    cin >> insideConversion;

    if(insideConversion==1)
    {
        cout << "1) load RNA "<<endl;
        cout << "2) load DNA "<<endl;
        cout << "3) load Protein"<<endl;
        cin>>insideConversion;
        if(insideConversion==1)
        {
            cout << "Enter the name of the file "<<endl;  // load from file
            cin >> filename;
            loaded_file = r1.LoadSequenceFromFile(filename);
        }
        else if(insideConversion==2)
        {
            cout << "Enter the name of the file "<<endl;  // load from file
            cin >> filename;
            loaded_file = d1.LoadSequenceFromFile(filename);
        }
        else if(insideConversion==3)
        {
            cout << "Enter the name of the file "<<endl;  // load from file
            cin >> filename;
            loaded_file = p1.LoadSequenceFromFile(filename);
        }
    }
    else if(insideConversion==2)
    {
        cout << "Enter  your sequence "<<endl;
        cin >> str1;
    }


    cout << "1) conversion"<<endl;
    cout << "2) LCS "<<endl;
    cin >> convertORlcs;

    if(convertORlcs==1)
    {
        cout << "1) DNA to RNA"<<endl;
        cout << "2) DNA to Protein "<<endl;
        cout << "3) RNA to DNA"<<endl;
        cout << "n4) RNA to Protein"<<endl;
        cout << "n5) Protein to RNA "endl;
        cin >> insideConversion;

        if(insideConversion==1)
        {
            RNA r2;
            try {

            DNA d2(str1,length,tail);
            r2 = d2.ConvertToRNA();
            cout << r2;
            }
            catch (DNA::wrongSequence) {
                cout << "wrong sequence" << endl;
                exit(1) ;
            }

            cout << "If you want to enter save your sequence enter 0"<<endl;
            cin >> zero;
            if(zero == 0)
            {
                cout << "Enter the name of the file "<<endl;  // load from file
                cin >> filename;

                toFile = r2.seq;
                r2.SaveSequenceToFile(toFile,filename);
            }
            else
                return 0;
        }
        else if(insideConversion==2)
        {
            string x;
            Protein p6 ;
            try {
                DNA d7(str1,length,tail);
                x = d7.convertToProtein();
                cout << x << endl;

            }
            catch (DNA::wrongSequence) {
                cout << " wrong sequence " << endl;
                exit(1) ;
            }
            for (int i=0 ; i< x.length();  i++)
            {
                p6.seq[i] = x[i];
            }


            cout << "If you want to enter save your sequence enter 0"<<endl;
            cin >> zero;
            if(zero == 0)
            {
                cout << "Enter the name of the file "<<endl;  // load from file
                cin >> filename;


                toFile = p6.seq;
                p6.SaveSequenceToFile(toFile,filename);
            }
            else
                return 0;


        }
        else if(insideConversion==3)
        {
           DNA d3;
           try {
           RNA r3(str1 , length ,mRNA);
           d3 = r3.ConvertToDNA();
           cout << d3;
           }
           catch (RNA::wrongSequence) {
                cout << " wrong sequence " << endl;
                exit(1) ;
            }
            cout << "If you want to enter save your sequence enter 0"<<endl;
            cin >> zero;
            if(zero == 0)
            {
                cout << "Enter the name of the file "<<endl;  // load from file
                cin >> filename;

                toFile = d3.seq;
                d3.SaveSequenceToFile(toFile,filename);
            }
            else
                return 0;
        }
        else if(insideConversion==4)
        {
            Protein p2;
            try {
            RNA r4(str1,length,mRNA) ;
            p2 = r4.convertfromRNAtoProtin();
            cout << p2;
            }
            catch (RNA::wrongSequence) {
                cout << " wrong sequence " << endl;
                exit(1) ;
            }
            cout << "If you want to enter save your sequence enter 0"<<endl;
            cin >> zero;
            if(zero == 0)
            {
                cout << "Enter the name of the file "<<endl;  // load from file
                cin >> filename;

                toFile = p2.seq;
                p2.SaveSequenceToFile(toFile,filename);
            }
            else
                return 0;
        }

        else if(insideConversion==5)
        {
            RNA r5;
            try {
            Protein p3(str1,length,TF);
            r5 = p3.convertProteintoRNA();
            cout << r5;
            }
            catch (Protein::wrongSequence) {
                cout << " wrong sequence " << endl;
                exit(1) ;
            }
            cout << "If you want to enter save your sequence enter 0"<<endl;
            cin >> zero;
            if(zero == 0)
            {
                cout << "Enter the name of the file "<<endl;  // load from file
                cin >> filename;

                toFile = r5.seq;
                r5.SaveSequenceToFile(toFile,filename);
            }
            else
                return 0;
        }

    }
    else if(convertORlcs==2)
    {
        cout << "Enter  your second  sequence "<<endl;
        cin >> str2;

        cout << "1) Normal "<<endl;
        cout << "2)Local"<<endl;
        cout << "3)Global"<<endl;
        cin >> insideLCS;

        if(insideLCS==1)
        {

        }
        else if(insideLCS==2)
        {

        }
        else if(insideLCS==3)
        {

        }


    }

    return 0;
}
