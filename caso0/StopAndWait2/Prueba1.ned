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

package stopandwait;

import ned.DatarateChannel;

import ned.IdealChannel;


simple Txc2
{
    gates:
        //input in;
        input inFuente;
        //output out;
}

//
// TODO documentation
//
network Network
{
    @display("bgb=389,190");
    submodules:
        fuente: Fuente2 {
            @display("p=66,87");
        }
        emisor: Txc2 {
            @display("p=169.75002,80.51");
        }
    connections:
        //emisor.out --> DatarateChannel {  per = default(0.4); datarate = default(10000bps); } --> toc.in;
        //toc.out --> DatarateChannel {  per = default(0.4); datarate = default(10000bps); } --> tic.in;
        fuente.out --> IdealChannel --> emisor.inFuente;
}

