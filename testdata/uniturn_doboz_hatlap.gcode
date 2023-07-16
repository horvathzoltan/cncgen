(GCode generated by cncgen - https://github.com/horvathzoltan/cncgen)
(type: GCode from geometry)
(input file: uniturn_doboz_hatlap.txt)
(output file: uniturn_doboz_hatlap.gcode)
(created on: K júl. 11 20:59:01 2023)
(total time: 01:32:27.000)
(total cut: 27598.8mm)
(total length: 28280.3mm)
G21 (metric units)
G90 (absolute mode)
G17 (select XY plane)
G94 (feedrate per minute)
G80 (cancel active cycles)
G54 (set work coordinate system offset)
M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)

G0 z2.000 (lift up)
G0 x100.000y-100.000 (travel)
(travel to safe place)
(cmd line: -i uniturn_doboz_hatlap.txt -t)
(plot cmd: -i uniturn_doboz_hatlap.txt -t -p)
(szerszám beállítás)
(set tool 1 to t1 m  d1.000 h19.000)
(set tool 2 to t2 m  d2.000 h19.000)
(set tool 3 to t3 m  d3.000 h19.000)
(set mode to YXZ)
(XM)
(XM)
(change tool)
m5 (spindle stop)
G0 z2.000 (lift up)
G0 x100.000y-100.000 (travel)
g0 z5.000
t1 (tool select)
m6 (tool change)
(msg, change tool to Milling, diameter=1.000)
m0 (machine stop)
g0 z5.000
s50.000 (set spindle speed)
f300.000 (set feed)

(ethernet)
(hole - helical interpolation)
(time: 0.0960117)
(helical cut)
G0 x-29.600y-135.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i11.500
G2 z-0.200 i11.500
G2 z-0.300 i11.500
G2 z-0.400 i11.500
G2 z-0.500 i11.500
G2 z-0.600 i11.500
G2 z-0.700 i11.500
G2 z-0.800 i11.500
G2 z-0.900 i11.500
G2 z-1.000 i11.500
G2 z-1.100 i11.500
G2 z-1.200 i11.500
G2 z-1.300 i11.500
G2 z-1.400 i11.500
G2 z-1.500 i11.500
G2 z-1.600 i11.500
G2 z-1.700 i11.500
G2 z-1.800 i11.500
G2 z-1.900 i11.500
G2 z-2.000 i11.500
G2 z-2.100 i11.500
G2 z-2.200 i11.500
G2 z-2.300 i11.500
G2 z-2.400 i11.500
G2 z-2.500 i11.500
G2 z-2.600 i11.500
G2 z-2.700 i11.500
G2 z-2.800 i11.500
G2 z-2.900 i11.500
G2 z-3.000 i11.500
G2 z-3.100 i11.500
G2 z-3.200 i11.500
G2 z-3.300 i11.500
G2 z-3.400 i11.500
G2 z-3.500 i11.500
G2 z-3.500 i11.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x-15.102y-123.898 (travel)
m3(spindle start)
G0 z-2.500 (lift down)
G1 z-3.500 (push)
G2 x-19.628y-146.398z-3.600 i-2.998 j-11.102
G3 x-15.102y-123.898z-3.700 i1.528 j11.398
G2 x-19.628y-146.398z-3.800 i-2.998 j-11.102
G3 x-15.102y-123.898z-3.900 i1.528 j11.398
G2 x-19.628y-146.398z-4.000 i-2.998 j-11.102
G3 x-15.102y-123.898z-4.100 i1.528 j11.398
G2 x-19.628y-146.398z-4.200 i-2.998 j-11.102
G3 x-15.102y-123.898z-4.300 i1.528 j11.398
G2 x-19.628y-146.398z-4.400 i-2.998 j-11.102
G3 x-15.102y-123.898z-4.500 i1.528 j11.398
G2 x-19.628y-146.398z-4.500 i-2.998 j-11.102
G1 z-3.500 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x-21.098y-146.102 (travel)
m3(spindle start)
G0 z-2.500 (lift down)
G1 z-3.500 (push)
G2 x-16.572y-123.602z-3.600 i2.998 j11.102
G3 x-21.098y-146.102z-3.700 i-1.528 j-11.398
G2 x-16.572y-123.602z-3.800 i2.998 j11.102
G3 x-21.098y-146.102z-3.900 i-1.528 j-11.398
G2 x-16.572y-123.602z-4.000 i2.998 j11.102
G3 x-21.098y-146.102z-4.100 i-1.528 j-11.398
G2 x-16.572y-123.602z-4.200 i2.998 j11.102
G3 x-21.098y-146.102z-4.300 i-1.528 j-11.398
G2 x-16.572y-123.602z-4.400 i2.998 j11.102
G3 x-21.098y-146.102z-4.500 i-1.528 j-11.398
G2 x-16.572y-123.602z-4.500 i2.998 j11.102
G1 z-3.500 (pull)
G0 z2.000 (lift up)
(time: 36.2665)
(usb)
(hole - helical interpolation)
(time: 36.2665)
(helical cut)
G0 x-29.600y-99.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i11.500
G2 z-0.200 i11.500
G2 z-0.300 i11.500
G2 z-0.400 i11.500
G2 z-0.500 i11.500
G2 z-0.600 i11.500
G2 z-0.700 i11.500
G2 z-0.800 i11.500
G2 z-0.900 i11.500
G2 z-1.000 i11.500
G2 z-1.100 i11.500
G2 z-1.200 i11.500
G2 z-1.300 i11.500
G2 z-1.400 i11.500
G2 z-1.500 i11.500
G2 z-1.600 i11.500
G2 z-1.700 i11.500
G2 z-1.800 i11.500
G2 z-1.900 i11.500
G2 z-2.000 i11.500
G2 z-2.100 i11.500
G2 z-2.200 i11.500
G2 z-2.300 i11.500
G2 z-2.400 i11.500
G2 z-2.500 i11.500
G2 z-2.600 i11.500
G2 z-2.700 i11.500
G2 z-2.800 i11.500
G2 z-2.900 i11.500
G2 z-3.000 i11.500
G2 z-3.100 i11.500
G2 z-3.200 i11.500
G2 z-3.300 i11.500
G2 z-3.400 i11.500
G2 z-3.500 i11.500
G2 z-3.500 i11.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x-14.578y-88.053 (travel)
m3(spindle start)
G0 z-2.500 (lift down)
G1 z-3.500 (push)
G2 x-20.168y-110.312z-3.600 i-3.522 j-10.947
G3 x-14.578y-88.053z-3.700 i2.068 j11.312
G2 x-20.168y-110.312z-3.800 i-3.522 j-10.947
G3 x-14.578y-88.053z-3.900 i2.068 j11.312
G2 x-20.168y-110.312z-4.000 i-3.522 j-10.947
G3 x-14.578y-88.053z-4.100 i2.068 j11.312
G2 x-20.168y-110.312z-4.200 i-3.522 j-10.947
G3 x-14.578y-88.053z-4.300 i2.068 j11.312
G2 x-20.168y-110.312z-4.400 i-3.522 j-10.947
G3 x-14.578y-88.053z-4.500 i2.068 j11.312
G2 x-20.168y-110.312z-4.500 i-3.522 j-10.947
G1 z-3.500 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x-21.622y-109.947 (travel)
m3(spindle start)
G0 z-2.500 (lift down)
G1 z-3.500 (push)
G2 x-16.032y-87.688z-3.600 i3.522 j10.947
G3 x-21.622y-109.947z-3.700 i-2.068 j-11.312
G2 x-16.032y-87.688z-3.800 i3.522 j10.947
G3 x-21.622y-109.947z-3.900 i-2.068 j-11.312
G2 x-16.032y-87.688z-4.000 i3.522 j10.947
G3 x-21.622y-109.947z-4.100 i-2.068 j-11.312
G2 x-16.032y-87.688z-4.200 i3.522 j10.947
G3 x-21.622y-109.947z-4.300 i-2.068 j-11.312
G2 x-16.032y-87.688z-4.400 i3.522 j10.947
G3 x-21.622y-109.947z-4.500 i-2.068 j-11.312
G2 x-16.032y-87.688z-4.500 i3.522 j10.947
G1 z-3.500 (pull)
G0 z2.000 (lift up)
(time: 63.9951)
(hdmi)
(hole - helical interpolation)
(time: 63.9951)
(helical cut)
G0 x-29.600y-63.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i11.500
G2 z-0.200 i11.500
G2 z-0.300 i11.500
G2 z-0.400 i11.500
G2 z-0.500 i11.500
G2 z-0.600 i11.500
G2 z-0.700 i11.500
G2 z-0.800 i11.500
G2 z-0.900 i11.500
G2 z-1.000 i11.500
G2 z-1.100 i11.500
G2 z-1.200 i11.500
G2 z-1.300 i11.500
G2 z-1.400 i11.500
G2 z-1.500 i11.500
G2 z-1.600 i11.500
G2 z-1.700 i11.500
G2 z-1.800 i11.500
G2 z-1.900 i11.500
G2 z-2.000 i11.500
G2 z-2.100 i11.500
G2 z-2.200 i11.500
G2 z-2.300 i11.500
G2 z-2.400 i11.500
G2 z-2.500 i11.500
G2 z-2.600 i11.500
G2 z-2.700 i11.500
G2 z-2.800 i11.500
G2 z-2.900 i11.500
G2 z-3.000 i11.500
G2 z-3.100 i11.500
G2 z-3.200 i11.500
G2 z-3.300 i11.500
G2 z-3.400 i11.500
G2 z-3.500 i11.500
G2 z-3.500 i11.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x-13.514y-52.454 (travel)
m3(spindle start)
G0 z-2.500 (lift down)
G1 z-3.500 (push)
G2 x-21.276y-74.053z-3.600 i-4.586 j-10.546
G3 x-13.514y-52.454z-3.700 i3.176 j11.053
G2 x-21.276y-74.053z-3.800 i-4.586 j-10.546
G3 x-13.514y-52.454z-3.900 i3.176 j11.053
G2 x-21.276y-74.053z-4.000 i-4.586 j-10.546
G3 x-13.514y-52.454z-4.100 i3.176 j11.053
G2 x-21.276y-74.053z-4.200 i-4.586 j-10.546
G3 x-13.514y-52.454z-4.300 i3.176 j11.053
G2 x-21.276y-74.053z-4.400 i-4.586 j-10.546
G3 x-13.514y-52.454z-4.500 i3.176 j11.053
G2 x-21.276y-74.053z-4.500 i-4.586 j-10.546
G1 z-3.500 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x-22.686y-73.546 (travel)
m3(spindle start)
G0 z-2.500 (lift down)
G1 z-3.500 (push)
G2 x-14.924y-51.947z-3.600 i4.586 j10.546
G3 x-22.686y-73.546z-3.700 i-3.176 j-11.053
G2 x-14.924y-51.947z-3.800 i4.586 j10.546
G3 x-22.686y-73.546z-3.900 i-3.176 j-11.053
G2 x-14.924y-51.947z-4.000 i4.586 j10.546
G3 x-22.686y-73.546z-4.100 i-3.176 j-11.053
G2 x-14.924y-51.947z-4.200 i4.586 j10.546
G3 x-22.686y-73.546z-4.300 i-3.176 j-11.053
G2 x-14.924y-51.947z-4.400 i4.586 j10.546
G3 x-22.686y-73.546z-4.500 i-3.176 j-11.053
G2 x-14.924y-51.947z-4.500 i4.586 j10.546
G1 z-3.500 (pull)
G0 z2.000 (lift up)
(time: 83.5236)
(tápcsatlakozó)
(hole - helical interpolation)
(time: 83.5236)
(helical cut)
G0 x-23.600y-33.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i5.500
G2 z-0.200 i5.500
G2 z-0.300 i5.500
G2 z-0.400 i5.500
G2 z-0.500 i5.500
G2 z-0.600 i5.500
G2 z-0.700 i5.500
G2 z-0.800 i5.500
G2 z-0.900 i5.500
G2 z-1.000 i5.500
G2 z-1.100 i5.500
G2 z-1.200 i5.500
G2 z-1.300 i5.500
G2 z-1.400 i5.500
G2 z-1.500 i5.500
G2 z-1.600 i5.500
G2 z-1.700 i5.500
G2 z-1.800 i5.500
G2 z-1.900 i5.500
G2 z-2.000 i5.500
G2 z-2.100 i5.500
G2 z-2.200 i5.500
G2 z-2.300 i5.500
G2 z-2.400 i5.500
G2 z-2.500 i5.500
G2 z-2.600 i5.500
G2 z-2.700 i5.500
G2 z-2.800 i5.500
G2 z-2.900 i5.500
G2 z-3.000 i5.500
G2 z-3.100 i5.500
G2 z-3.200 i5.500
G2 z-3.300 i5.500
G2 z-3.400 i5.500
G2 z-3.500 i5.500
G2 z-3.600 i5.500
G2 z-3.700 i5.500
G2 z-3.800 i5.500
G2 z-3.900 i5.500
G2 z-4.000 i5.500
G2 z-4.000 i5.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x-14.254y-29.068 (travel)
m3(spindle start)
G0 z-3.000 (lift down)
G1 z-4.000 (push)
G2 x-20.745y-37.822z-4.100 i-3.846 j-3.932
G3 x-14.254y-29.068z-4.200 i2.645 j4.822
G2 x-20.745y-37.822z-4.300 i-3.846 j-3.932
G3 x-14.254y-29.068z-4.400 i2.645 j4.822
G2 x-20.745y-37.822z-4.500 i-3.846 j-3.932
G3 x-14.254y-29.068z-4.600 i2.645 j4.822
G2 x-20.745y-37.822z-4.700 i-3.846 j-3.932
G3 x-14.254y-29.068z-4.800 i2.645 j4.822
G2 x-20.745y-37.822z-4.900 i-3.846 j-3.932
G3 x-14.254y-29.068z-5.000 i2.645 j4.822
G2 x-20.745y-37.822z-5.000 i-3.846 j-3.932
G1 z-4.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x-21.946y-36.932 (travel)
m3(spindle start)
G0 z-3.000 (lift down)
G1 z-4.000 (push)
G2 x-15.455y-28.178z-4.100 i3.846 j3.932
G3 x-21.946y-36.932z-4.200 i-2.645 j-4.822
G2 x-15.455y-28.178z-4.300 i3.846 j3.932
G3 x-21.946y-36.932z-4.400 i-2.645 j-4.822
G2 x-15.455y-28.178z-4.500 i3.846 j3.932
G3 x-21.946y-36.932z-4.600 i-2.645 j-4.822
G2 x-15.455y-28.178z-4.700 i3.846 j3.932
G3 x-21.946y-36.932z-4.800 i-2.645 j-4.822
G2 x-15.455y-28.178z-4.900 i3.846 j3.932
G3 x-21.946y-36.932z-5.000 i-2.645 j-4.822
G2 x-15.455y-28.178z-5.000 i3.846 j3.932
G1 z-4.000 (pull)
G0 z2.000 (lift up)
(time: 92.358)
G0 z2.000 (lift up)
G0 x100.000y-100.000 (travel)
(travel to safe place)

M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)
M30
(end)
