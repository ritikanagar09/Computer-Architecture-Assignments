#include "learning_gem5/part2/vector_operations.hh"
#include <vector>
#include <cmath>
#include <iostream>

#include "base/trace.hh"

#include "debug/VECTORS.hh"
#include "debug/ADDRESULT.hh"
#include "debug/DOTRESULT.hh"
#include "debug/NORMALIZE.hh"

#include "debug/BONUS.hh"

using std::vector;



vector<int> vect1 {1,2,3,4};
vector<int> vect2 {0,5,6,7};
vector<int>addRes(4,0);// 4 mera size ho jaaye ----sare value intialyy 0 ho jaaye 
vector<double>normRes1;
vector<double>normRes2;


namespace gem5
{

VectorOperations::VectorOperations(const VectorOperationsParams &params) :
    SimObject(params), vectoradd([this]{ event1();}, name()), vectorDotProduct([this]{ event2();}, name()), normalizeVector([this]{ event3();}, name())
 {   
   
    DPRINTF(VECTORS, "\nIntial Vectors: \n vect1 {1,2,3,4} \n vect2 {0,5,6,7}\n");


 }


void
VectorOperations::event1()
{   
    

    for(int i=0;i<4;i++){
        intt result=vec1[i]+vect2[i];
        //addRes.push_back(result);
        addRes[i]=result;
        
    }


    DPRINTF(ADDRESULT, "\nRESULTANT VECTOR FROM VECTOR ADDITION:\n result= {%d,%d,%d,%d}\n", addRes.at(0), 
                                                            addRes.at(1), addRes.at(2), addRes.at(3));

}


void
VectorOperations::event2()
{   
    int result=0;

    for(int i=0;i<4;i++){
        result+=vect1[i]*vect2[i];
        
    }

    DPRINTF(DOTRESULT, "RESULTANT FROM DOT PRODUCT:%d", result);

}



void
VectorOperations::event3()
{   
    

    double v1,v2=0;
    
    for(int i=0;i<4;i++){
        v1+= vect1[i]*vect1[i];
    }

    for(int i=0;i<4;i++){
       v2+= vect2[i]*vect2[i]; 
    }



    v1=sqrt(v1);
    v2=sqrt(v2);

    for(int i=0;i<4;i++){
        normRes1.push_back(vect1[i]/v1);
        normRes2.push_back(vect2[i]/v2);
    }



    DPRINTF(NORMALIZE, "first Vector= {%f,%f,%f,%f}\n second Vector: {%f,%f,%f,%f} \n", 
                                        normRes1.at(0), normRes1.at(1), normRes1.at(2), normRes1.at(3), normRes2.at(0), normRes2.at(1), normRes2.at(2), normRes2.at(3));
}



void
VectorOperations::startup()
{
    

    schedule(vectoradd, 100);
    schedule(vectorDotProduct, 1000);
    schedule(normalizeVector, 10000);
    
}

} 



