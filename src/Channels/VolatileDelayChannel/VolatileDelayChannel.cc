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

#include "VolatileDelayChannel.h"

Define_Channel(cVolatileDelayChannel);

void
cVolatileDelayChannel::initialize()
{
    cChannel::initialize();

    pDelayPar = &par( "delay" );

    EV << "Delay: " << pDelayPar->detailedInfo() << endl;
    EV << "Delay.isVolatile(): " << pDelayPar->isVolatile() << endl;
}

void
cVolatileDelayChannel::processMessage(cMessage *msg, simtime_t t, result_t& result)
{
    result.delay = pDelayPar->doubleValue();
}

bool
cVolatileDelayChannel::isTransmissionChannel() const
{
    return false;
}

double
cVolatileDelayChannel::getNominalDatarate() const
{
    return 0.0;
}

simtime_t
cVolatileDelayChannel::calculateDuration(cMessage *msg) const
{
    return SIMTIME_ZERO;
}

simtime_t
cVolatileDelayChannel::getTransmissionFinishTime() const
{
    return SIMTIME_ZERO;
}

bool
cVolatileDelayChannel::isBusy() const
{
    return false;
}

void
cVolatileDelayChannel::forceTransmissionFinishTime(simtime_t t)
{
}
