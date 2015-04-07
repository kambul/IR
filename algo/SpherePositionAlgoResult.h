#ifndef SPHEREPOSITIONALGORESULT_H
#define SPHEREPOSITIONALGORESULT_H
#include "algo/SixData.h"

#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

class SpherePositionAlgoResult
{
public:
   bool    success;
   SixData data;
};

#endif
