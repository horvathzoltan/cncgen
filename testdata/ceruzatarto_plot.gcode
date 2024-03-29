(GCode generated by cncgen - https://github.com/horvathzoltan/cncgen)
(type: GCode from geometry)
(input file: ceruzatarto.txt)
(output file: ceruzatarto_plot.gcode)
(created on: K júl. 11 11:54:14 2023)
(total time: 00:14:42.000)
(total cut: 2881.36mm)
(total length: 3341.33mm)
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
(ceruzatarto plottolashoz)
(szerszám beállítás)
(set tool 1 to t1 m  d1.500 h19.000)
(set mode to YXZ)
(change tool)
m5 (spindle stop)
G0 z2.000 (lift up)
g0 z5.000
t1 (tool select)
m6 (tool change)
(msg, change tool to Milling, diameter=1.500)
m0 (machine stop)
g0 z5.000
s50.000 (set spindle speed)
f200.000 (set feed)

(box)
(time: 0.00133333)

(line)
(time: 0.00133333)
(linear cut)
G0 x0.000y-10.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x33.250y-10.750z-0.020
G1 x0.000y-10.750z-0.020
G0 z2.000 (lift up)
(time: 0.348144)
(line)
(time: 0.348144)
(linear cut)
G0 x36.750y-10.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x70.000y-10.750z-0.020
G1 x36.750y-10.750z-0.020
G0 z2.000 (lift up)
(time: 0.712201)

(line)
(time: 0.712201)
(linear cut)
G0 x70.000y10.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x36.750y10.750z-0.020
G1 x70.000y10.750z-0.020
G0 z2.000 (lift up)
(time: 1.07815)
(line)
(time: 1.07815)
(linear cut)
G0 x33.250y10.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x0.000y10.750z-0.020
G1 x33.250y10.750z-0.020
G0 z2.000 (lift up)
(time: 1.44221)

(line)
(time: 1.44221)
(linear cut)
G0 x-0.750y10.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x-0.750y1.750z-0.020
G04 P100
G1 x-0.750y10.000z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.55444)
(line)
(time: 1.55444)
(linear cut)
G0 x-0.750y-1.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x-0.750y-10.000z-0.020
G04 P100
G1 x-0.750y-1.750z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.65191)
(time: 1.65191)
(hole - helical interpolation)
(time: 1.65191)
(helical cut)
G0 x85.750y0.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i12.250
G2 z-0.010 i12.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x85.913y1.991 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x110.250y0.000z-0.020 i12.087 j-1.991
G3 x85.913y1.991z-0.020 i-12.250 j-0.000
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x110.087y-1.991 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x85.750y-0.000z-0.020 i-12.087 j1.991
G3 x110.087y-1.991z-0.020 i12.250 j0.000
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 9.9806)
(arc)
(time: 9.9806)
(circular_arc cut)
G0 x70.000y10.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x70.000y-10.000z-0.020 i28.000 j-10.000
G3 x70.000y10.000z-0.020 i28.000 j10.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 13.617)
(hole - helical interpolation)
(time: 13.617)
(helical cut)
G0 x5.750y0.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i4.250
G2 z-0.010 i4.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x6.212y1.927 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x14.250y0.000z-0.020 i3.788 j-1.927
G3 x6.212y1.927z-0.020 i-4.250 j-0.000
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x13.788y-1.927 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x5.750y-0.000z-0.020 i-3.788 j1.927
G3 x13.788y-1.927z-0.020 i4.250 j0.000
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 14.7027)
G0 z2.000 (lift up)
G0 x0.000y0.000 (travel)
(travel to safe place)

M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)
M30
(end)
