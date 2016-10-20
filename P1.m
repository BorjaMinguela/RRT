(* ::Package:: *)

(* ::Title:: *)
(*Caso 1: Modelos de colas para an\[AAcute]lisis de rendimiento*)
(*Simulaci\[OAcute]n de una cola M/M/1 y estudio de estad\[IAcute]sticos de inter\[EAcute]s*)
(**)


(* ::Text:: *)
(*Desarrollar un sistema generador de n\[UAcute]meros aleatorios basado en un generador lineal*)
(*congruencial mixto que siga una distribuci\[OAcute]n uniforme entre[0, 1].*)


(* ::Input:: *)
(*Module[{RndNumber=4406,a=314159269,c=453806245,m=2^31},RandomData[]:=N[(RndNumber=Mod[(a RndNumber+c),m])/(m-1)]];*)
(*RandomExp[rate_]:=(-Log[RandomData[]]/rate)//N;*)


(* ::Input:: *)
(*RandomData[]*)


(* ::Input:: *)
(*lambda=100*)
(*ro=0.8  (*landa/mu*)*)


(* ::Input:: *)
(*Histogram[Table[RandomData[],{100000}],20,"PDF"]*)


(* ::Input:: *)
(*Histogram[Table[RandomExp[100],{50000}],60,"PDF"]*)


(* ::Input:: *)
(*nmax= 1000;*)


(* ::Input:: *)
(*InterArrivalsTime=Table[RandomExp[10],{nmax}];*)


(* ::Input:: *)
(*ServiceTime=Table[RandomExp[100],{nmax}];*)


(* ::Input:: *)
(**)


(* ::Input:: *)
(*AcumSeries[serie_]:=Module[{acum=0}, acum+=#&/@serie]*)
(*(*AcumSeries[serie_]:=Module[{acum=0}, Map[(acum+=#)&,serie]]*)*)
(*InterArrivals=Table[RandomExp[100],{nmax}];*)


(* ::Input:: *)
(*ArrivalsTime=AcumSeries[InterArrivals];*)
(*ListPlot[ArrivalsTime[[100;;120]]]*)


(* ::Input:: *)
(**)


(* ::Input:: *)
(*ServiceTime = Table[RandomExp[ro*lambda],nmax];*)


(* ::Input:: *)
(*FifoSchedulling[arrivals_,service_]:=Module[{n,checkTime},n=1;checkTime=arrivals[[1]];*)
(*(If[checkTime>=#,checkTime+=service[[n++]],checkTime=#+service[[n++]]])&/@arrivals]*)
(**)


DepartureTime=FifoSchedulling[ArrivalsTime,ServiceTime];
ListPlot[DepartureTime]
