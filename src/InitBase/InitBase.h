
#ifndef INIT_BASE_H
#define INIT_BASE_H

// ======================================================
// Includes
// ======================================================

#include <omnetpp.h>

// ======================================================
// Types
// ======================================================

typedef enum
{
    PARSE_RESOURCE_PARAMETERS  = 0,
    ALLOCATE_RESOURCES,
    INIT_HIERARCHY,
    PARSE_PARAMETERS,
    REGISTER_SIGNALS,
    INIT_INTERNAL_STATE,
    INIT_SIGNALS,
    FINISH_INIT,
    DEBUG_OUTPUT,
    NUM_INIT_STAGES
}
InitStage_t;

// ======================================================
// Declarations
// ======================================================

/*
 TODO: Remove

// Init API
void    ParseResourceParameters();
void    AllocateResources();
void    InitHierarchy();
void    ParseParameters();
void    RegisterSignals();
void    InitInternalState();
void    InitSignals();
void    FinishInit();
void    PrintDebugOutput();

void    ForwardInit( int stage );

// ------------------------------------------------------
// Initialize
// ------------------------------------------------------
void
cDummyModule::ParseResourceParameters()
{
}

void
cDummyModule::AllocateResources()
{
}

void
cDummyModule::InitHierarchy()
{
}

void
cDummyModule::ParseParameters()
{
}

void
cDummyModule::RegisterSignals()
{
}

void
cDummyModule::InitInternalState()
{
}

void
cDummyModule::InitSignals()
{
}

void
cDummyModule::FinishInit()
{
}

void
cDummyModule::PrintDebugOutput()
{
}

void
cDummyModule::ForwardInit( int stage )
{
}

// ------------------------------------------------------
// Handle messages
// ------------------------------------------------------

*/

class cInitAPI
{
    protected:

        // Initialization API
        virtual void    ParseResourceParameters()   {};
        virtual void    AllocateResources()         {};
        virtual void    InitHierarchy()             {};
        virtual void    ParseParameters()           {};
        virtual void    RegisterSignals()           {};
        virtual void    InitInternalState()         {};
        virtual void    InitSignals()               {};
        virtual void    FinishInit()                {};
        virtual void    PrintDebugOutput()          {};
};


class cModuleInitBase : public cSimpleModule, public cInitAPI
{
    private:

    protected:

        // OMNeT init API
        int     numInitStages() const;
        void    initialize( int stage );

        virtual void    ForwardInit( int stage )    {};

    public:

};

class cInitBase : public cInitAPI
{
    private:

    protected:

        // Resources
        cModule         *pParentModule;

        virtual void    ForwardInit( int stage )    {};

    public:

        cInitBase();

        // OMNeT init API
        int     numInitStages() const;
        void    initialize( int stage );

        void    SetParentModule( cModule *pModule );
};

#endif
