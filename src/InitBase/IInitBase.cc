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

// ======================================================
// Includes
// ======================================================

#include "IInitBase.h"

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
// Initialize
// ------------------------------------------------------
int
IInitBase::numInitStages() const
{
    return static_cast<int>(InitStage::NUM_INIT_STAGES);
}

void
IInitBase::initialize( int stage )
{
    InitStage initStage = static_cast<InitStage>(stage);

    switch( initStage )
    {
        case InitStage::PARSE_RESOURCE_PARAMETERS:      ParseResourceParameters();  break;
        case InitStage::ALLOCATE_RESOURCES:             AllocateResources();        break;
        case InitStage::INIT_HIERARCHY:                 InitHierarchy();            break;
        case InitStage::PARSE_PARAMETERS:               ParseParameters();          break;
        case InitStage::REGISTER_SIGNALS:               RegisterSignals();          break;
        case InitStage::INIT_INTERNAL_STATE:            InitInternalState();        break;
        case InitStage::INIT_SIGNALS:                   InitSignals();              break;
        case InitStage::FINISH_INIT:                    FinishInit();               break;
        case InitStage::DEBUG_OUTPUT:                   PrintDebugOutput();
                                                        break;

        default:                                        throw cRuntimeError( "Unexpected init stage" );
                                                        break;
    }

    switch( initStage )
    {
            case InitStage::PARSE_RESOURCE_PARAMETERS:  // Do not forward initial stages
            case InitStage::ALLOCATE_RESOURCES:
            case InitStage::INIT_HIERARCHY:
                                                        break;

            case InitStage::PARSE_PARAMETERS:           ForwardInit( static_cast<int>(InitStage::PARSE_RESOURCE_PARAMETERS) );
                                                        ForwardInit( static_cast<int>(InitStage::ALLOCATE_RESOURCES       ) );
                                                        ForwardInit( static_cast<int>(InitStage::INIT_HIERARCHY           ) );
                                                                // Fall-through
            default:                                    ForwardInit( stage );
    }
}
