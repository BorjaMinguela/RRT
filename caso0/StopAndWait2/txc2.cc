
#include <string.h>
#include <omnetpp.h>
#include <iostream>
//#include <cdataratechannel.h>
#include <vector>
using namespace omnetpp;


class Txc2 : public cSimpleModule
{
  protected:
    // The following redefined virtual function holds the algorithm.
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

// The module class needs to be registered with OMNeT++
Define_Module(Txc2);
cPacket *msg;
cMessage *recep;
//cDataRateChannel canal;
int contador2;
std::vector<cPacket *> colaFuente;
void Txc2::initialize()
{
        msg = new cPacket("Msg0",0,100);
        contador2=0;
        std::cout<<"Inicio con cola";
        recep=new cMessage("recep");
        //canal=gate("out")->getTransmisisionChannel();
        //send(recep,"out");


}

void Txc2::handleMessage(cMessage *msg)
{
    if (strcmp("emisor", getName()) == 0) {
        if(strcmp("newMessage",msg->getName())==0){
            std::cout<<"Nuevo mensaje";
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
        if(strcmp("ACK",msg->getName())==0){
            /*
             * ventana++;
             * mensajesEnviados=0;
             * if(!cola.empty())
             *  send
             *
             */
        }
        if(strcmp("NACK",msg->getName())==0){
            /*
             * if(ventana>2)
             *  ventana--;
             * mensajesEnviados=0;
             * sendBuffer
             */
        }

            //else{
              //  scheduleAt(simTime()+0.1, new cMessage("recep"));
            //}
        }
    }
    /*recep=new cMessage("recep");
    send(recep,"out");
    char message[20];
    sprintf(message,"Msg%d",contador2);
    char ack[20];
    sprintf(ack,"ACK",contador2);
    char nack[20];
    sprintf(nack,"NACK%d",contador2);
    int length;
    length=rand()%(1500*8-50*8+1)+50*8;
    std::cout<<"Algo me ha llegado";
    cPacket *packet=((cPacket *)msg);
    cola.push_back(packet);
    if(strcmp(msg->getName(),ack)==0)
    {
        cPacket *salida=cola.back();
        cola.pop_back();
        //send(salida,"out");
    }*/


   /* if (strcmp("tic", getName()) == 0) {
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
