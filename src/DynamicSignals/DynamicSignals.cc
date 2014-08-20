
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
    InternalRegisterDynamicSignal( cModule *pModule, const std::string SigName, const std::string StatisticName, const std::string TemplateName )
    {
        simsignal_t     signal_id;
        cProperty       *pStatTempProp;

        signal_id       = pModule->registerSignal( SigName.c_str() );
        pStatTempProp   = pModule->getProperties()->get( "statisticTemplate", TemplateName.c_str() );

        ev.addResultRecorders( pModule, signal_id, StatisticName.c_str(), pStatTempProp );

        return signal_id;
    }

    simsignal_t
    RegisterDynamicSignal( cModule *pModule, const std::string BaseName, const std::string SigName, const std::string TemplateName )
    {
        std::string SignalName  = BaseName + "_" + SigName;

        return  InternalRegisterDynamicSignal( pModule, SignalName, SignalName, TemplateName );
    }

    simsignal_t
    RegisterDynamicSignal( cModule *pModule, const std::string BaseName, const int ID, const std::string SigName, const std::string TemplateName )
    {
        std::stringstream ss;

        ss << BaseName << "_" << ID << "_" << SigName;

        return  InternalRegisterDynamicSignal( pModule, ss.str(), ss.str(), TemplateName );
    }

    simsignal_t
    RegisterDynamicSignal( cModule *pModule, const std::string BaseName1, const std::string BaseName2, const std::string SigName, const std::string TemplateName )
    {
        std::string SignalName  = BaseName1 + "_" + BaseName2 + "_" + SigName;

        return  InternalRegisterDynamicSignal( pModule, SignalName, SignalName, TemplateName );
    }
}



