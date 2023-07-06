(GCode generated by cncgen - https://github.com/horvathzoltan/cncgen)
(type: GCode from geometry)
(input file: gomb.txt)
(output file: gomb.gcode)
(created on: K jan. 31 10:51:06 2023)
(total time: 00:07:53.000)
(total cut: 1553.67mm)
(total length: 1750.95mm)
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
G0 x0.000y0.000 (travel)
(travel to safe place)
(mestercipo cpu hátlap)
(szerszám beállítás)
(set tool 1 to t1 m  d1.500 h19.000)
(set mode to YXZ)
(change tool)
m5 (spindle stop)
G0 z2.000 (lift up)
g0 z4.000
t1 (tool select)
m6 (tool change)
(msg, change tool to Milling, diameter=1.500)
m0 (machine stop)
g0 z4.000
s50.000 (set spindle speed)
f200.000 (set feed)

(ly1: 9)
(ly2: 8.75)
(ly3: 10.75)
(hole - helical interpolation)
(time: 0.00133333)
(helical cut)
G0 x9.375y12.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.050 i2.625
G2 z-0.100 i2.625
G2 z-0.100 i2.625
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.266474)
(line)
(time: 0.266474)
(linear cut)
G0 x8.750y12.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x10.750y12.000z-0.050
G04 P100
G1 x8.750y12.000z-0.100
G04 P100
G1 x10.750y12.000z-0.100
G04 P100
G0 z2.000 (lift up)
(time: 0.304944)
(hole - helical interpolation)
(time: 0.304944)
(helical cut)
G0 x6.750y12.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.500 i5.250
G2 z-1.000 i5.250
G2 z-1.500 i5.250
G2 z-2.000 i5.250
G2 z-2.500 i5.250
G2 z-3.000 i5.250
G2 z-3.500 i5.250
G2 z-4.000 i5.250
G2 z-4.000 i5.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x7.126y13.952 (travel)
m3(spindle start)
G0 z-3.000 (lift down)
G1 z-4.000 (push)
G2 x17.250y12.000z-4.500 i4.874 j-1.952
G3 x7.126y13.952z-4.500 i-5.250 j-0.000
G1 z-4.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x16.874y10.048 (travel)
m3(spindle start)
G0 z-3.000 (lift down)
G1 z-4.000 (push)
G2 x6.750y12.000z-4.500 i-4.874 j1.952
G3 x16.874y10.048z-4.500 i5.250 j0.000
G1 z-4.000 (pull)
G0 z2.000 (lift up)
(time: 2.39539)
(hole - helical interpolation)
(time: 2.39539)
(helical cut)
G0 x6.750y27.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.500 i5.250
G2 z-1.000 i5.250
G2 z-1.500 i5.250
G2 z-2.000 i5.250
G2 z-2.500 i5.250
G2 z-2.500 i5.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 3.41782)
(hole - helical interpolation)
(time: 3.41782)
(helical cut)
G0 x5.250y27.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.500 i6.750
G2 z-1.000 i6.750
G2 z-1.500 i6.750
G2 z-2.000 i6.750
G2 z-2.500 i6.750
G2 z-2.500 i6.750
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 4.7114)
(hole - helical interpolation)
(time: 4.7114)
(helical cut)
G0 x3.750y27.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.500 i8.250
G2 z-1.000 i8.250
G2 z-1.500 i8.250
G2 z-2.000 i8.250
G2 z-2.500 i8.250
G2 z-3.000 i8.250
G2 z-3.500 i8.250
G2 z-4.000 i8.250
G2 z-4.000 i8.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x8.369y19.592 (travel)
m3(spindle start)
G0 z-3.000 (lift down)
G1 z-4.000 (push)
G2 x13.747y35.063z-4.500 i3.631 j7.408
G3 x8.369y19.592z-4.500 i-1.747 j-8.063
G1 z-4.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x15.631y34.408 (travel)
m3(spindle start)
G0 z-3.000 (lift down)
G1 z-4.000 (push)
G2 x10.253y18.937z-4.500 i-3.631 j-7.408
G3 x15.631y34.408z-4.500 i1.747 j8.063
G1 z-4.000 (pull)
G0 z2.000 (lift up)
(time: 7.87331)
G0 z2.000 (lift up)
G0 x0.000y0.000 (travel)
(travel to safe place)

M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)
M30
(end)