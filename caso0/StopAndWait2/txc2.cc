
#include <string.h>
#include <omnetpp.h>
#include <iostream>
//#include <cdataratechannel.h>
#include <vector>
#include <deque>
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
//std::vector<cPacket *> colaFuente;
std::deque<cPacket *> colaFuente;
std::deque<cPacket *> buffer;
//omnetpp::cChannel canal;
int ventana;
int mensajesEnviados;

void Txc2::initialize()
{
        msg = new cPacket("Msg0",0,100);
        contador2=0;
        std::cout<<"Inicio con cola";
        recep=new cMessage("recep");
        ventana=1;
        mensajesEnviados=0;
        //canal=gate("out")->getTransmissionChannel();
        //send(recep,"out");


}

void Txc2::handleMessage(cMessage *msg)
{
    char message1[20];
    char message2[20];
    char message3[20];
    sprintf(message1,"Msg%d",contador2);
    sprintf(message2,"ACK%d",contador2);
    sprintf(message3,"NACK%d",contador2);
    if(strcmp("newMessage",msg->getName())==0){
            std::cout<<"Nuevo mensaje";
            sprintf(message1,"Msg%d",++contador2);
            int lenPkt=rand()%(1500*8-50*8+1)+50*8;
            cPacket *msg = new cPacket(message1,0,lenPkt);
            colaFuente.push_back(msg);
            if(mensajesEnviados<ventana){
                buffer.push_back(msg);
                cPacket *msg = colaFuente.front();
                colaFuente.pop_front();
                send(msg,"out");
                mensajesEnviados++;
            }
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
            buffer.clear();
            ventana++;
            mensajesEnviados=0;
            if(!colaFuente.empty()){
                cPacket *msg = colaFuente.front();
                buffer.push_back(msg);
                colaFuente.pop_front();
                send(msg,"out");
                mensajesEnviados++;
            }
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
//}
