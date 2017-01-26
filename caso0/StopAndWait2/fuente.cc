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

using namespace omnetpp;
class Fuente : public cSimpleModule{
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
Define_Module(Fuente);
std::vector<cPacket *> colaFuente;
void Fuente::initialize()
{
    //SourceBase::initialize();
    //startTime = par("startTime");
   // stopTime = par("stopTime");
    //numJobs = par("numMsgs");

    // schedule the first message timer for start time
    scheduleAt(0, new cMessage("newJobTimer"));
}

void Fuente::handleMessage(cMessage *msg)
{
    if(strcmp("recep",msg->getName())==0){
        if (!colaFuente.empty()){
            cPacket *salida=colaFuente.back();
            colaFuente.pop_back();
            send(salida,"out");
        }
        else{
            scheduleAt(simTime()+0.1, new cMessage("recep"));
        }
    }
    else{
        char message[20];
        int contador=0;
            sprintf(message,"Msg%d",contador);
            int length;
                length=rand()%(1500*8-50*8+1)+50*8;
        ASSERT(msg->isSelfMessage());

        //if ((numJobs < 0 || numJobs > jobCounter) && (stopTime < 0 || stopTime > simTime())) {
            // reschedule the timer for the next message
            scheduleAt(simTime() + par("interArrivalTime").doubleValue(), msg);
        //scheduleAt(simTime() + 2, msg);

            cPacket *job = new cPacket(message,0,length);
            contador++;
            colaFuente.push_back(job);
            //send(job, "out");
        //}
        //else {
            // finished
          //  delete msg;
        //}
    }
}

