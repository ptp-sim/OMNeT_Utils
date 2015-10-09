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

#ifndef NON_MOD_INIT_BASE_H
#define NON_MOD_INIT_BASE_H

// ======================================================
// Includes
// ======================================================

#include "IInitBase.h"

// ======================================================
// Types
// ======================================================

// ======================================================
// Declarations
// ======================================================

class cNonModInitBase : public IInitBase
{
    private:

    protected:

        // Resources
        cModule         *pParentModule;

    public:

        // Constructors/Destructor
        cNonModInitBase();
        cNonModInitBase( const cNonModInitBase& other );
        ~cNonModInitBase();

        // OMNeT init API
        int     numInitStages() const;
        void    initialize( int stage );

        // Module API
        void    SetParentModule( cModule *pModule );

        // Operators
        cNonModInitBase&  operator= (const cNonModInitBase& other);
};

#endif
