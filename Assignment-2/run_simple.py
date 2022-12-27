# import the m5 (gem5) library created when gem5 is built
import m5
# import all of the SimObjects
from m5.objects import *

# set up the root SimObject and start the simulation
root = Root(full_system = False)

# Create an instantiation of the simobject you created
root.hello = VectorOperations()

# instantiate all of the objects we've created above
m5.instantiate()

print("Beginning Vector Operations simulation!")
exit_event = m5.simulate()
print('Exiting @ tick %i because %s' % (m5.curTick(), exit_event.getCause()))