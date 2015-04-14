#include "algo/SpherePositionAlgoResult.h"

void SpherePositionAlgoResult::Analysis()
{
    if ((data.m_angl1 > 0 ) && (data.m_angl2 < 180))
    {
        data.m_b1 = data.m_b1*(-1);
    }

    if ((data.m_angl2 > 180 ) && (data.m_angl2 < 360))
    {
        data.m_angl2 = data.m_angl2*(-1);
    }
}

