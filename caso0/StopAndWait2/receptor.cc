
#include <string.h>
#include <omnetpp.h>
#include <iostream>
//#include <cdataratechannel.h>
#include <vector>
#include <deque>
using namespace omnetpp;


class Receptor : public cSimpleModule
{
  protected:
    // The following redefined virtual function holds the algorithm.
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

// The module class needs to be registered with OMNeT++
Define_Module(Receptor);
cPacket *msg2;
//cDataRateChannel canal;
//std::vector<cPacket *> colaFuente;
//std::deque<cPacket *> colaReceptor;
int ventana2;
int mensajesRecibidos;
void Receptor::initialize()
{
        std::cout<<"Inicio con cola";
        ventana2=1;
        mensajesRecibidos=0;
        //canal=gate("out")->getTransmisisionChannel();
        //send(recep,"out");


}

void Receptor::handleMessage(cMessage *msg)
{
    cPacket *pkt=((cPacket *)msg);
    std::cout <<"Mensaje recibido en el recpetor\n";
    if(pkt->hasBitError()){
        cPacket *msg = new cPacket("NACK",0,160);
        send(msg, "out");
        mensajesRecibidos=0;
        if(ventana2<2)
            ventana2--;
    }
    else{
        mensajesRecibidos++;
        if(ventana2==mensajesRecibidos){
            cPacket *msg = new cPacket("ACK",0,160);
            send(msg, "out");
            ventana2++;
            mensajesRecibidos=0;
        }
    }
    /*char message1[20];
    char message2[20];
    char message3[20];
    sprintf(message1,"Msg%d",contador3);
    sprintf(message2,"ACK%d",contador3);
    sprintf(message3,"NACK%d",contador3);
    if(strcmp("newMessage",msg->getName())==0){
        std::cout<<"Nuevo mensaje";
        sprintf(message1,"Msg%d",++contador3);
        int lenPkt=rand()%(1500*8-50*8+1)+50*8;
        cPacket *msg2 = new cPacket(message1,0,lenPkt);
        colaReceptor.push_back(msg2);
        if(mensajesRecibidos<ventana2){

            mensajesRecibidos++;
            contador3++;
        }*/
        /*Añadir mensaje a la cola
         * if(mensajesEnviados<ventana)
         *  send
         *
         */



        /*if (!colaFuente.empty()){
            cPacket *salida=colaFuente.back();
            colaFuente.pop_back();
            send(salida,"out");
        */}


    //if(strcmp("ACK",msg->getName())==0){
        /*
         * ventana++;
         * mensajesEnviados=0;
         * if(!cola.empty())
         *  send
         *
         */
    //}
    //if(strcmp("NACK",msg->getName())==0){
        /*
         * if(ventana>2)
         *  ventana--;
         * mensajesEnviados=0;
         * sendBuffer
         */
    //}
//}
