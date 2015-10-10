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

#include "SubmoduleInitBase.h"

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
// Constructors/Destructor
// ------------------------------------------------------
cSubmoduleInitBase::cSubmoduleInitBase()
{
    this->pParentModule = nullptr;
}

cSubmoduleInitBase::cSubmoduleInitBase( const cSubmoduleInitBase& other )
{
    this->pParentModule = other.pParentModule;
}

cSubmoduleInitBase::~cSubmoduleInitBase()
{
}

// ------------------------------------------------------
// Initialize
// ------------------------------------------------------
int
cSubmoduleInitBase::numInitStages() const
{
    return IInitBase::numInitStages();
}

void
cSubmoduleInitBase::initialize( int stage )
{
    IInitBase::initialize( stage );
}

// ------------------------------------------------------
// Module API
// ------------------------------------------------------
void
cSubmoduleInitBase::SetParentModule( cModule *pModule )
{
    this->pParentModule = pModule;
}

// ------------------------------------------------------
// Operators
// ------------------------------------------------------
cSubmoduleInitBase&
cSubmoduleInitBase::operator= (const cSubmoduleInitBase& other)
{
    this->pParentModule = other.pParentModule;

    // By convention, always return *this
    return *this;
}
