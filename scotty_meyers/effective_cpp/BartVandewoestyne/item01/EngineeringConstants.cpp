#include "EngineeringConstants.h"

// This goes in the class implementation file
const double EngineeringConstants::FUDGE_FACTOR = 1.35

// You can't define a static member variable more than once.
// If you put variable definitions into a header,
// it is going to be defined in each translation unit where the header is included.
// Since the include guards are only affecting the compilation of one translation unit, 
// they won't help, either.