#include <stdlib.h>
#include <iostream>


using namespace std;

class cache{

  private:
    int iTagSize = 0;
    int iIndexSize = 0;
    int iOffsetSize = 0;
    unsigned long ulAddress = 0;

  public:
    long lBlockSize;
    int iAssociativity;
    long lCacheSize;

    //Constructor con 3 parametros
    cache(int iAssoc,long lCSize,long lBSize){
      lBlockSize = lBSize;
      iAssociativity = iAssoc;
      lCacheSize = lCSize;
    }
    //Destructor >:O
    ~cache(){}

};

int main(int arcg, char* argv[]){

  long long llParameter[3];
  llParameter[0]=atoll(argv[1]);
  llParameter[1]=atoll(argv[2]);
  llParameter[2]=atoll(argv[3]);

  ifstream datos("aligned.trace");
	string sLine;
	unsigned long ulAddress;
	bool bHit;
	long long llTotal = 0;
	long long llHits = 0;
	long long llMisses = 0;
	double dMissRate;


}
