#ifndef __LEARNING_GEM5_HELLO_OBJECT_HH__
#define __LEARNING_GEM5_HELLO_OBJECT_HH__

#include "params/VectorOperations.hh"
#include "sim/sim_object.hh"

namespace gem5
{

class VectorOperations : public SimObject
{ 
  private:
    
    void vectorAdd();
    void vectorDotProduct();
    void normalizeVector();
    
    void bonus();

    
    EventFunctionWrapper ev1;
    EventFunctionWrapper ev2;
    EventFunctionWrapper ev3;
    EventFunctionWrapper ev4;
    
  public:
    VectorOperations(const VectorOperationsParams &p);

    void startup();
};

} // namespace gem5

#endif // __LEARNING_GEM5_HELLO_OBJECT_HH__