#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct block{
  bool bValidBit = false;
  long lBlockTag = 0;
};

//dados los valores se calcula tamaño en bits del index y del offset necesarios en la función splitAddress
class cache{
  private:
    int iTagSize, iIndexSize;
    int iNumSets, iRand, iNumBlocks, iOffsetSize;
    long lAddress, lIndex, lTag, lIndexMask;
    std::vector<std::vector<block> > vBlocks;
  public:
    long long llBlockSize;
    int iAssociativity;
    long long llCacheSize;
    void splitAddress();
    bool readAddress(long);
    //Constructor con 3 parametros
    cache(int iAssoc,long long llCSize,long long llBSize){
      llBlockSize = llBSize;
      iAssociativity = iAssoc;
      llCacheSize = llCSize;
      iNumBlocks = llCSize/llBSize;
      iNumSets = iNumBlocks/iAssoc;
      iOffsetSize = int(log2(llBSize));
      iIndexSize = int(log2(iNumSets));
      iTagSize = 32 - iIndexSize - iOffsetSize;
      vBlocks.resize(iNumSets, std::vector<block>(iAssociativity) );
    }
    //Destructor >:O
    ~cache(){}
};

//para dividir la direccion en tag, index y offset
void cache::splitAddress(){
  lIndexMask = 0;
  for(int i = 0; i < iIndexSize; i++){
    lIndexMask <<= 1; //se crea una mascara para index
    lIndexMask |= 1; //indexMask or 1
  }
  lIndex = lAddress >> (iOffsetSize);
  lIndex = lIndex & lIndexMask;
  //cout << "Address: " << lAddress << endl;
  //cout << "Index: " << lIndex << endl;
  lTag = lAddress >> (iOffsetSize+iIndexSize);
  //cout << "Tag: " << lTag << endl;
}

//despues de saber en que set estoy de acuerdo al index
bool cache::readAddress(long lAddr){
  lAddress = lAddr;
  splitAddress();
  for(int i=0; i<iAssociativity; i++){ //para buscar la cantidad de bloques
    if (vBlocks[lIndex][i].bValidBit){
      if (vBlocks[lIndex][i].lBlockTag == lTag){
        //cout << "Hit Yeah! " << endl;
        return true;
      }
    }
  }
  iRand = rand() % iAssociativity;
  vBlocks[lIndex][iRand].bValidBit = true;
  vBlocks[lIndex][iRand].lBlockTag = lTag;
  //cout << "Miss, escribiendo sobre el bloque: " << iRand << " del set: "<< lIndex << endl;
  return false;
}


//se reciben los parametros del programa
int main(int arcg, char* argv[]){

  long long llParameter[3];
  llParameter[0]=atoll(argv[1]);
  llParameter[1]=atoll(argv[2]);
  llParameter[2]=atoll(argv[3]);

  ifstream datos("aligned.trace");
	long lAddr;
	bool bHit;
	long long llTotal = 0;
	long long llHits = 0;
	long long llMisses = 0;
	double dMissRate;
  string line;

  //cantidad de accesos totales, hits y misses
  cache myCache(llParameter[0],llParameter[1],llParameter[2]);

  while ( getline (datos,line) ) {
    getline(datos,line);
    line.erase(line.begin()+8,line.end());
    istringstream(line) >> std::hex >> lAddr;
  	bHit = myCache.readAddress(lAddr);
    if(bHit){
      llHits++;
    }
    llTotal++;
  }
  cout << "Hits: " << llHits << endl;
  cout << "Total: " << llTotal << endl;
  llMisses = llTotal - llHits;
  dMissRate = (double(llMisses)/double(llTotal))*100;
  cout << "Miss Rate: " << dMissRate << endl;
}
