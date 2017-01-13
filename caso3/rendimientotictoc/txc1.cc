#include <string.h>
#include <omnetpp.h>
#include <iostream>
using namespace omnetpp;
class Txc1 : public cSimpleModule
{
  protected:
    // The following redefined virtual function holds the algorithm.
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
// The module class needs to be registered with OMNeT++
Define_Module(Txc1);
int i=0;
int lenPkt;
void Txc1::initialize()
{
    // Initialize is called at the beginning of the simulation.
    // To bootstrap the tic-toc-tic-toc process, one of the modules needs
    // to send the first message. Let this be `tic'.
    // Am I Tic or Toc?
    if (strcmp("tic", getName()) == 0) {
        // create and send first message on gate "out". "tictocMsg" is an
        // arbitrary string which will be the name of the message object.
        cPacket *msg = new cPacket("Msg0",0,1000);
        send(msg, "out");
        lenPkt=1000;
    }
}
void Txc1::handleMessage(cMessage *msg)
{
    // The handleMessage() method is called whenever a message arrives
    // at the module. Here, we just send it to the other module, through
    // gate `out'. Because both `tic' and `toc' does the same, the message
    // will bounce between the two.
    cPacket *pkt=((cPacket *)msg);
    if(pkt->hasBitError()){
        std::cout <<"Paquete con error\n";
    }
    char message1[20];
    char message2[20];
    char message3[20];
    sprintf(message1,"Msg%d",i);
    sprintf(message2,"ACK%d",i);
    sprintf(message3,"NACK%d",i);
    /*if(pkt->hasBitError()){
                        cPacket *msg = new cPacket(message3,0,100);
                        send(msg, "out");
                    }
                    else{
                        cPacket *msg = new cPacket(message2,0,100);
                        send(msg, "out");
                    }*/
    if (strcmp("toc", getName()) == 0) {
            if (strcmp(msg->getName(),message1)==0){
                //cPacket *msg = new cPacket(message2,0,1000);
                if(pkt->hasBitError()){
                    cPacket *msg = new cPacket(message3,0,160);
                    send(msg, "out");
                }
                else{
                    cPacket *msg = new cPacket(message2,0,160);
                    send(msg, "out");
                }

                //send(msg, "out");

            }
    }

            if (strcmp("tic", getName()) == 0) {
                       if (strcmp(msg->getName(),message2)==0){
                           sprintf(message1,"Msg%d",++i);
                           lenPkt=rand()%(1500*8-50*8+1)+50*8;
                           cPacket *msg = new cPacket(message1,0,lenPkt);
                           //msg->addPar("error");
                           send(msg, "out");
                       }
                       if (strcmp(msg->getName(),message3)==0){
                           sprintf(message1,"Msg%d",i);
                           cPacket *msg = new cPacket(message1,0,lenPkt);
                           send(msg, "out");
                       }

            }
            // create and send first message on gate "out". "tictocMsg" is an
            // arbitrary string which will be the name of the message object.
           // cMessage *msg = new cMessage("ACK");
            //send(msg, "out");
            //printf("%s\n",msg->getName());


    //send(msg, "out"); // send out the message
}
