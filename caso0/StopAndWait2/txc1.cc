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

#include <string.h>
#include <omnetpp.h>
#include <iostream>
using namespace omnetpp;

/**
 * Derive the Txc1 class from cSimpleModule. In the Tictoc1 network,
 * both the `tic' and `toc' modules are Txc1 objects, created by OMNeT++
 * at the beginning of the simulation.
 */
class Txc1 : public cSimpleModule
{
  protected:
    // The following redefined virtual function holds the algorithm.
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
int contador=0;
// The module class needs to be registered with OMNeT++
Define_Module(Txc1);

void Txc1::initialize()
{
    std::cout<<"Inicio sin cola";
    // Initialize is called at the beginning of the simulation.
    // To bootstrap the tic-toc-tic-toc process, one of the modules needs
    // to send the first message. Let this be `tic'.
    // Am I Tic or Toc?
    if (strcmp("tic", getName()) == 0) {
        // create and send first message on gate "out". "tictocMsg" is an
        // arbitrary string which will be the name of the message object.
        cPacket *msg = new cPacket("Msg0",0,100);
        //send(msg, "out");
    }
}

void Txc1::handleMessage(cMessage *msg)
{
    // The handleMessage() method is called whenever a message arrives
    // at the module. Here, we just send it to the other module, through
    // gate `out'. Because both `tic' and `toc' does the same, the message
    // will bounce between the two.
    char message[20];
    sprintf(message,"Msg%d",contador);
    char ack[20];
    sprintf(ack,"ACK%d",contador);
    char nack[20];
    sprintf(nack,"NACK%d",contador);
    int length;
    length=rand()%(1500*8-50*8+1)+50*8;
    std::cout<<"Algo me ha llegado";
    /*cPacket *packet=((cPacket *)msg);
    if (strcmp("tic", getName()) == 0) {
        if((packet->hasBitError())==1)
        {
            std::cout<<"Error en el mensaje";
            //sprintf(message,"Error%d",contador);
           // msg=new cPacket(message,0,10000);
            msg=new cPacket(message,0,length);

        }
        else
        {

            if(strcmp(msg->getName(),ack)==0)
            {
                contador++;
                sprintf(message,"Msg%d",contador);
                //message=message->strcat("Msg",contador);
                msg=new cPacket(message,0,length);
            }
            else
            {
                if(strcmp(msg->getName(),nack)==0)
                 {
                    msg=new cPacket(message,0,length);

                 }
                else
                {
                    msg=new cPacket(ack,0,480);
                }
            }


        }
    }
    if (strcmp("toc", getName()) == 0) {
            if((packet->hasBitError())==1)
            {
                std::cout<<"Error en el mensaje";
                //sprintf(message,"Error%d",contador);
               // msg=new cPacket(message,0,10000);

                            msg=new cPacket(nack,0,480);

            }
            else
            {

                if(strcmp(msg->getName(),nack)==0)
                {
                    contador++;
                    sprintf(message,"Msg%d",contador);
                    //message=message->strcat("Msg",contador);
                    msg=new cPacket(ack,0,480);
                }
                else
                {

                        msg=new cPacket(ack,0,480);

                }


            }
        }*/
  //  send(msg, "out"); // send out the message
}
