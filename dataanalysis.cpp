#include "dataanalysis.h"
#include "algo/SixData.h"

CDataAnalysis::CDataAnalysis()
{

}

CDataAnalysis::~CDataAnalysis()
{

}

SixData CDataAnalysis::Analysis(SixData sixdata)
{
    if ((sixdata.m_angl1 > 0 ) && (sixdata.m_angl2 < 270))
    {
        sixdata.m_b1 = sixdata.m_b1*(-1);
    }

    if ((sixdata.m_angl2 > 0 ) && (sixdata.m_angl2 < 270))
    {
        sixdata.m_angl2 = sixdata.m_angl2*(-1);
    }
}

