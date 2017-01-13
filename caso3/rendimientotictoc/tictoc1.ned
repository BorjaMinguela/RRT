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

package rendimientotictoc;
import ned.DatarateChannel;


simple Txc1
{
    gates:
        input in;
        output out;
}
//
// Two instances (tic and toc) of Txc1 connected both ways.
// Tic and toc will pass messages to one another.
//
network Tictoc1
{
    @display("bgb=312,225");
    types:
    submodules:
        tic: Txc1 {
            @display("p=101,74");
        }
        toc: Txc1 {
            @display("p=221,170");
        }
    connections:
        tic.out --> DatarateChannel {  delay = default(0ms); datarate = default(1000bps); per = default(0.5); } --> toc.in;
        toc.out --> DatarateChannel {  delay = default(0ms); datarate = default(1000bps); per = default(0.5); } --> tic.in;
}
