
// ======================================================
// Includes
// ======================================================

#include "InitBase.h"

#include <omnetpp.h>

// ======================================================
// Types
// ======================================================

// ======================================================
// Constants
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

// ------------------------------------------------------
// Initialize (cModuleBase)
// ------------------------------------------------------
int
cModuleInitBase::numInitStages() const
{
    return NUM_INIT_STAGES;
}

void
cModuleInitBase::initialize( int stage )
{
    switch( stage )
    {
        case PARSE_RESOURCE_PARAMETERS:     ParseResourceParameters();  break;
        case ALLOCATE_RESOURCES:            AllocateResources();        break;
        case INIT_HIERARCHY:                InitHierarchy();            break;
        case PARSE_PARAMETERS:              ParseParameters();          break;
        case REGISTER_SIGNALS:              RegisterSignals();          break;
        case INIT_INTERNAL_STATE:           InitInternalState();        break;
        case INIT_SIGNALS:                  InitSignals();              break;
        case FINISH_INIT:                   FinishInit();               break;
        case DEBUG_OUTPUT:                  if( GetEnableDebugOutput() )
                                            {
                                                PrintDebugOutput();
                                            }
                                            break;
    }

    ForwardInit( stage );
}

// ------------------------------------------------------
// Initialize (cInitBase)
// ------------------------------------------------------
int
cInitBase::numInitStages() const
{
    return NUM_INIT_STAGES;
}

void
cInitBase::initialize( int stage )
{
    switch( stage )
    {
        case PARSE_RESOURCE_PARAMETERS:     ParseResourceParameters();  break;
        case ALLOCATE_RESOURCES:            AllocateResources();        break;
        case INIT_HIERARCHY:                InitHierarchy();            break;
        case PARSE_PARAMETERS:              ParseParameters();          break;
        case REGISTER_SIGNALS:              RegisterSignals();          break;
        case INIT_INTERNAL_STATE:           InitInternalState();        break;
        case INIT_SIGNALS:                  InitSignals();              break;
        case FINISH_INIT:                   FinishInit();               break;
        case DEBUG_OUTPUT:                  if( GetEnableDebugOutput() )
                                            {
                                                PrintDebugOutput();
                                            }
                                            break;
    }

    ForwardInit( stage );
}
