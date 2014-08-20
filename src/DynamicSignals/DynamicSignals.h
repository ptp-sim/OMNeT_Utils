
#ifndef DYNAMIC_SIGNALS_H_
#define DYNAMIC_SIGNALS_H_

// ======================================================
// Includes
// ======================================================

#include <omnetpp.h>

// ======================================================
// Types
// ======================================================

// ======================================================
// Declarations
// ======================================================

namespace DynamicSignals
{
    simsignal_t RegisterDynamicSignal( cModule *pModule, const std::string BaseName,                               const std::string SigName, const std::string TemplateName );
    simsignal_t RegisterDynamicSignal( cModule *pModule, const std::string BaseName,  const int         ID,        const std::string SigName, const std::string TemplateName );
    simsignal_t RegisterDynamicSignal( cModule *pModule, const std::string BaseName1, const std::string BaseName2, const std::string SigName, const std::string TemplateName );
}

#endif
