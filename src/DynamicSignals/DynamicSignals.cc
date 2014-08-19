
// ======================================================
// Includes
// ======================================================

#include "DynamicSignals.h"

// ======================================================
// Definitions
// ======================================================

// ======================================================
// Types
// ======================================================

// ======================================================
// Variables
// ======================================================

// ======================================================
// Declarations
// ======================================================

// ======================================================
// Definitions
// ======================================================

namespace DynamicSignals
{
    simsignal_t
    InternalRegisterDynamicSignal( cModule *pModule, std::string SigName, std::string StatisticName, const char *pSigName )
    {
        simsignal_t     signal_id;
        cProperty       *pStatTempProp;

        signal_id       = pModule->registerSignal( SigName.c_str() );
        pStatTempProp   = pModule->getProperties()->get( "statisticTemplate", pSigName );

        ev.addResultRecorders( pModule, signal_id, StatisticName.c_str(), pStatTempProp );

        return signal_id;
    }

    simsignal_t
    RegisterDynamicSignal( cModule *pModule, const char *pBaseName, const int ID, const char *pSigName )
    {
        std::stringstream ss;

        ss << pBaseName << "_" << ID << "_" << pSigName;

        std::string SigName         = ss.str();
        std::string StatisticName   = SigName;

        return  InternalRegisterDynamicSignal( pModule, SigName, StatisticName, pSigName );
    }

    simsignal_t
    RegisterDynamicSignal( cModule *pModule, const char *pBaseName1, const char *pBaseName2, int ID, const char *pSigName )
    {
        std::stringstream ss;

        ss << pBaseName1 << "_" << pBaseName2 << "_" << pSigName;

        std::string SigName         = ss.str();
        std::string StatisticName   = SigName;

        return  InternalRegisterDynamicSignal( pModule, SigName, StatisticName, pSigName );
    }
}



