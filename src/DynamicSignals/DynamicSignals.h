
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
    simsignal_t RegisterDynamicSignal( cModule *pModule, const char *pBaseName, const int ID, const char *pSigName );
    simsignal_t RegisterDynamicSignal( cModule *pModule, const char *pBaseName1, const char *pBaseName2, int ID, const char *pSigName );
}

#endif
