//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "fuente.h"
#include <string.h>
#include <omnetpp.h>
#include <iostream>
#include <random>

using namespace omnetpp;
class Fuente2 : public cSimpleModule{
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
Define_Module(Fuente2);
cMessage *nMessage;

void Fuente2::initialize()
{
    std::exponential_distribution<> rng (par("interArrivalTime"));

    scheduleAt(0, new cMessage("newJobTimer"));
}

void Fuente2::handleMessage(cMessage *msg)
{
    nMessage=new cMessage("newMessage");
    send(nMessage,"out");
    scheduleAt(simTime() + par("interArrivalTime").doubleValue(), msg);

}

