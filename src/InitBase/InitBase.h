//
// Copyright (c) 2013-2015, Wolfgang Wallner (wolfgang-wallner@gmx.at)
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of Vienna University of Technology nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

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
