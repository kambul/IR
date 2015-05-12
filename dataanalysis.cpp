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
    if (((sixdata.m_angl1 > 0 ) && (sixdata.m_angl1 < 90)) || ((sixdata.m_angl1 > 90 ) && (sixdata.m_angl1 < 180)))
    {

    }
    else
    {
        sixdata.m_b1 = sixdata.m_b1*(-1);
    }

    if (((sixdata.m_angl2 > 90 ) && (sixdata.m_angl2 < 180)) || ((sixdata.m_angl2 > 269 ) && (sixdata.m_angl2 < 360)))
    {

    }
    else
    {
        sixdata.m_b1 = sixdata.m_b1*(-1);
    }


}

