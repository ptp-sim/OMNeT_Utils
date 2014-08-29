
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

class cModuleInitBase : public cSimpleModule
{
    private:

    protected:

        // OMNeT init API
        int     numInitStages() const;
        void    initialize( int stage );

        // Initialization API
        virtual void    ParseResourceParameters()   {};
        virtual void    AllocateResources()         {};
        virtual void    InitHierarchy()             {};
        virtual void    ParseParameters()           {};
        virtual void    RegisterSignals()           {};
        virtual void    InitInternalState()         {};
        virtual void    InitSignals()               {};
        virtual void    FinishInit()                {};
        virtual bool    GetEnableDebugOutput()      { return false; };
        virtual void    PrintDebugOutput()          {};

        virtual void    ForwardInit( int stage )    {};

    public:

};

class cInitBase
{
    private:

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
        virtual bool    GetEnableDebugOutput()      { return false; };
        virtual void    PrintDebugOutput()          {};

        virtual void    ForwardInit( int stage )    {};

    public:

        // OMNeT init API
        int     numInitStages() const;
        void    initialize( int stage );
};

#endif
