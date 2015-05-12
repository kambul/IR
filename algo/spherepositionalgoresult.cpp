#include "algo/SpherePositionAlgoResult.h"

void SpherePositionAlgoResult::Analysis()
{
    if ((data.m_angl1 >= 0 ) && (data.m_angl1 <= 180)) //|| ((data.m_angl1 > 18 ) && (data.m_angl1 < 180)))
    {

    }
    else
    {
        data.m_b1 = data.m_b1*(-1);
    }
/*
    if (((data.m_angl2 > 90 ) && (data.m_angl2 < 180)) || ((data.m_angl2 > 269 ) && (data.m_angl2 < 360)))
    {

    }
    else
    {
        data.m_b1 = data.m_b1*(-1);
    }
    */
}

