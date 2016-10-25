(* ::Package:: *)

(* ::Input:: *)
(*Parte primera (referencia Armando)*)


(* ::Input:: *)
(*Needs["drawTx`"];*)


(* ::Input:: *)
(**)


(* ::Input:: *)
(*Module[{RndNumber = 4406,a=314159269,c=453806245,m=2^31},*)
(*RandomData[]:=N[(RndNumber =Mod[(a RndNumber+c),m])/(m-1)];*)
(*RandomExp[rate_]:=(-Log[RandomData[]]/rate);*)
(*GetRndNumber[]:=RndNumber*)
(*]*)


(* ::Input:: *)
(**)
(*Module[*)
(*{tp=0.01,tack=0.05,winMod=8,nsec=0},*)
(*SetIniPar[tP_,tAck_,nSec_]:=*)
(*(tp=tP;tack=tAck;nsec=nSec;SetIniParDraw[tp,tack];{tp,tack,winMod});*)
(*GetIniPar[]:=*)
(*{tp,tack,winMod};*)
(*PacketArrivalsGenTimePeriod[lambdaArr_ (*aqui es donde se ejecuta el randomexp*) ,muServ_(*deberia ser tiempo, no mu*),lastTime_,iniTime_:0](*funcion para generar la llegada de paquetes en el rango de simulacion. Ha construido paquetes con una tasa landa acumulativa*):=NestWhileList[ {(acumTime+=lambdaArr),muServ,nsec++,0,0}&,{acumTime=iniTime+lambdaArr,muServ,nsec++,0,0},(#[[1]] <lastTime )&]*)
(*;*)
(*SetAttributes[PacketArrivalsGenTimePeriod,HoldAll];*)
(**)
(**)
(*FifoPacketTxSW[arrivals_,pcomb_]:=*)
(*Module[{checkTime,nrTx},checkTime=arrivals[[1,1]];*)
(**)
(*SetCheckTimeSW[time_]:=(checkTime=time);*)
(**)
(*GetDepartureSW[arr_]:=*)
(*Module[{ret=arr[[1]]},*)
(*(If[checkTime>=arr[[1]],ret=checkTime;checkTime+=arr[[2]],*)
(*checkTime=arr[[1]]+arr[[2]]];*)
(*checkTime+=2 tp+tack;*)
(*ret)*)
(*];(*sin tener encuenta retransmisiones*)*)
(*(*con retransmisiones*)*)
(*GetPacketRTxSW[pck_,perror_]:=*)
(*({GetDepartureSW[pck],pck[[2]],pck[[3]],*)
(*(*si hay error*)If[RandomData[]<=perror,1,0],pck[[5]]+1});*)
(**)
(*Flatten[*)
(*Map[*)
(*(NestWhileList[*)
(*(GetPacketRTxSW[#,pcomb]&),*)
(*GetPacketRTxSW[#,pcomb],(#[[4]]==1)&])&,arrivals],1]*)
(*];*)
(*LaunchSimTxSW[tasa_,tp_,p_,time_,lambda_]:=(SetIniPar[tp,0,0];FifoPacketTxSW[PacketArrivalsGenTimePeriod[tasa,lambda,time,0],p]);*)
(*SetAttributes[LaunchSimTxSW,HoldAll];*)
(*](*fin del module ppal*)*)
(**)
(**)


(* ::Input:: *)
(**)
(*SetIniPar[0.01,0,0]; (*Modifica parametros de la libreria (la inicializa)*)*)
(**)
(*PacketsTx=FifoPacketTxSW[PacketArrivalsGenTimePeriod(*generacion de paquetes de llegdas*)[RandomExp[1.5](*depende de Ti y ro*),*)
(*RandomExp[2.5],20,0],.2](* Array que quiero construir con paquetes*)*)
(**)


(* ::Input:: *)
(*Manipulate[*)
(*Show[DrawWin[tw,ww,10],(*Dibuja el marco de la ventana*)*)
(* Map[(DrawPacketTx[#])&,SelectPacketInWin[PacketsTx] (*selecciona los paquetes que van a entrar en la ventana*)]]*)
(**)
(*,{tw,0,30},{ww*)
(*(*ancho de ventana*),0.01,10}*)
(*]*)


(* ::Input:: *)
(*Parte segunda *)


(* ::Input:: *)
(*SetIniPar[0.01,0,0];*)


(* ::Input:: *)
(*ListaPaquetes=FifoPacketTxSW[PacketArrivalsGenTimePeriod[RandomExp[1.5],RandomExp[2.5],2000,0],.2];*)
(**)


(* ::Input:: *)
(*ListaPaquetes*)


(* ::Input:: *)
(*ThMaximo[lstpacket_]:=Last[lstpacket][[3]]/Last[lstpacket][[1]];*)


(* ::Input:: *)
(*ThMaximo[ListaPaquetes]*)


(* ::Input:: *)
(*ThList=Map[(#[[3]]/#[[1]])&,ListaPaquetes];*)


(* ::Input:: *)
(*ThListFn[lstpacket_]:=Map[#[[3]]/#[[1]]&,lstpacket];*)


(* ::Input:: *)
(*ListPlot[ThListFn[ListaPaquetes]]*)


(* ::Input:: *)
(*Tt=Last[ListaPaquetes[[1]]+0.05(*tack*)];*)


(* ::Input:: *)
(*FactorA=Tt/Last[ListaPaquetes[[1]]];(*a=Tt/ti*)*)


(* ::Input:: *)
(*ThA[lstpkt_,p_,a_]:=(1-p)/(a*Last[lstpkt[[1]]]);*)


(* ::Input:: *)
(*Manipulate[Plot[(1-p)/(a tI),{p,0,1}],{a,1,8,1},{tI(*tiempo insercion*),0.01,0.1},{ro,0.1,1},{p,0,1}]*)
