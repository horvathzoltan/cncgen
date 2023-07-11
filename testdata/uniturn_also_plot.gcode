(GCode generated by cncgen - https://github.com/horvathzoltan/cncgen)
(type: GCode from geometry)
(input file: uniturn_also.txt)
(output file: uniturn_also_plot.gcode)
(created on: K júl. 11 14:29:50 2023)
(total time: 00:07:50.000)
(total cut: 1903.13mm)
(total length: 4154.8mm)
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
(uniturn mérőállomás alsó szerelőlap)
(cmd line: -i uniturn_also.txt -t)
(plot cmd: -i uniturn_also.txt -t -p)
(szerszám beállítás)
(set tool 1 to t1 m  d2.000 h19.000)
(set tool 2 to t2 m  d3.000 h19.000)
(set tool 3 to t3 m  d4.000 h19.000)
(set mode to YXZ)
(change tool)
m5 (spindle stop)
G0 z2.000 (lift up)
g0 z5.000
t1 (tool select)
m6 (tool change)
(msg, change tool to Milling, diameter=2.000)
m0 (machine stop)
g0 z5.000
s50.000 (set spindle speed)
f300.000 (set feed)

(pi3b furatok)
(m2: 24.599999999999994)
(box)
(time: 0.00133333)
(hole - helical interpolation)
(time: 0.00133333)
(helical cut)
G0 x24.350y27.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.250
G2 z-0.020 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.0414812)
(hole - helical interpolation)
(time: 0.0414812)
(helical cut)
G0 x82.350y27.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.250
G2 z-0.020 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.0960433)
(hole - helical interpolation)
(time: 0.0960433)
(helical cut)
G0 x82.350y76.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.250
G2 z-0.020 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.14461)
(hole - helical interpolation)
(time: 0.14461)
(helical cut)
G0 x24.350y76.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.250
G2 z-0.020 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.199172)
(time: 0.199172)
(relé furatok)
(hole - helical interpolation)
(time: 0.199172)
(helical cut)
G0 x105.500y12.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.294141)
(hole - helical interpolation)
(time: 0.294141)
(helical cut)
G0 x138.600y12.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.342593)
(hole - helical interpolation)
(time: 0.342593)
(helical cut)
G0 x139.500y57.350 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.398939)
(hole - helical interpolation)
(time: 0.398939)
(helical cut)
G0 x105.500y57.350 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.447989)
(pizero furatok)
(box)
(time: 0.447989)
(hole - helical interpolation)
(time: 0.447989)
(helical cut)
G0 x115.750y70.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.250
G2 z-0.020 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.474798)
(hole - helical interpolation)
(time: 0.474798)
(helical cut)
G0 x138.750y70.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.250
G2 z-0.020 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.506061)
(hole - helical interpolation)
(time: 0.506061)
(helical cut)
G0 x138.750y128.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.250
G2 z-0.020 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.560623)
(hole - helical interpolation)
(time: 0.560623)
(helical cut)
G0 x115.750y128.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.250
G2 z-0.020 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.591887)
(time: 0.591887)
(rfid furatok)
(h 117.4,85.1 d3 z2.8 c0.1)
(9h 80.6,69.2)
(b3218101 - net-box 220, vers. i)
(rögzítő furatok)
(hole - helical interpolation)
(time: 0.591887)
(helical cut)
G0 x3.500y5.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.729253)
(hole - helical interpolation)
(time: 0.729253)
(helical cut)
G0 x123.500y5.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.835608)
(hole - helical interpolation)
(time: 0.835608)
(helical cut)
G0 x145.500y25.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.881818)
(hole - helical interpolation)
(time: 0.881818)
(helical cut)
G0 x145.500y169.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.00417)
(hole - helical interpolation)
(time: 1.00417)
(helical cut)
G0 x123.500y189.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.05038)
(hole - helical interpolation)
(time: 1.05038)
(helical cut)
G0 x3.500y189.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.15674)
(dugó kivágások)
(line)
(time: 1.15674)
(linear cut)
G0 x0.000y147.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x23.000y147.700z-0.010
G1 x0.000y147.700z-0.010
G0 z2.000 (lift up)
(linear cut)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x9.500y147.700z-0.020
G04 P100
G1 x0.000y147.700z-0.020
G04 P100
G0 z2.000 (lift up)
(linear cut)
G0 x13.500y147.700 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x23.000y147.700z-0.020
G04 P100
G1 x13.500y147.700z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.48955)
(line)
(time: 1.48955)
(linear cut)
G0 x24.000y146.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x24.000y117.500z-0.010
G1 x24.000y146.700z-0.010
G0 z2.000 (lift up)
(linear cut)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x24.000y134.100z-0.020
G1 x24.000y146.700z-0.020
G0 z2.000 (lift up)
(linear cut)
G0 x24.000y130.100 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x24.000y117.500z-0.020
G1 x24.000y130.100z-0.020
G0 z2.000 (lift up)
(time: 1.88657)
(line)
(time: 1.88657)
(linear cut)
G0 x24.000y117.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x36.000y117.500z-0.020
G1 x24.000y117.500z-0.020
G0 z2.000 (lift up)
(time: 1.98042)
(line)
(time: 1.98042)
(linear cut)
G0 x36.000y117.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x36.000y84.000z-0.010
G1 x36.000y117.500z-0.010
G0 z2.000 (lift up)
(linear cut)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x36.000y102.750z-0.020
G1 x36.000y117.500z-0.020
G0 z2.000 (lift up)
(linear cut)
G0 x36.000y98.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x36.000y84.000z-0.020
G1 x36.000y98.750z-0.020
G0 z2.000 (lift up)
(time: 2.43715)
(line)
(time: 2.43715)
(linear cut)
G0 x35.000y83.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x0.000y83.000z-0.010
G1 x35.000y83.000z-0.010
G0 z2.000 (lift up)
(linear cut)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x19.500y83.000z-0.020
G1 x35.000y83.000z-0.020
G0 z2.000 (lift up)
(linear cut)
G0 x15.500y83.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x0.000y83.000z-0.020
G1 x15.500y83.000z-0.020
G0 z2.000 (lift up)
(time: 2.91687)
(line)
(time: 2.91687)
(linear cut)
G0 x1.000y82.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x1.000y80.000z-0.020
G04 P100
G1 x1.000y82.000z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 2.94533)
(usb hub furatai)
(körvonal)
(box)
(time: 2.94533)

(line)
(time: 2.94533)
(linear cut)
G0 x0.000y-1.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x36.000y-1.000z-0.020
G1 x0.000y-1.000z-0.020
G0 z2.000 (lift up)
(time: 3.24604)
(line)
(time: 3.24604)
(linear cut)
G0 x40.000y-1.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x74.000y-1.000z-0.020
G1 x40.000y-1.000z-0.020
G0 z2.000 (lift up)
(time: 3.50476)
(line)
(time: 3.50476)
(linear cut)
G0 x78.000y-1.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x112.000y-1.000z-0.020
G1 x78.000y-1.000z-0.020
G0 z2.000 (lift up)
(time: 3.76214)
(line)
(time: 3.76214)
(linear cut)
G0 x116.000y-1.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x152.000y-1.000z-0.020
G1 x116.000y-1.000z-0.020
G0 z2.000 (lift up)
(time: 4.03287)

(line)
(time: 4.03287)
(linear cut)
G0 x153.000y0.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x153.000y46.500z-0.020
G1 x153.000y0.000z-0.020
G0 z2.000 (lift up)
(time: 4.37293)
(line)
(time: 4.37293)
(linear cut)
G0 x153.000y50.500 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x153.000y95.000z-0.020
G1 x153.000y50.500z-0.020
G0 z2.000 (lift up)
(time: 4.70864)
(line)
(time: 4.70864)
(linear cut)
G0 x153.000y99.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x153.000y143.500z-0.020
G1 x153.000y99.000z-0.020
G0 z2.000 (lift up)
(time: 5.04303)
(line)
(time: 5.04303)
(linear cut)
G0 x153.000y147.500 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x153.000y194.000z-0.020
G1 x153.000y147.500z-0.020
G0 z2.000 (lift up)
(time: 5.39074)

(line)
(time: 5.39074)
(linear cut)
G0 x152.000y195.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x116.000y195.000z-0.020
G1 x152.000y195.000z-0.020
G0 z2.000 (lift up)
(time: 5.6678)
(line)
(time: 5.6678)
(linear cut)
G0 x112.000y195.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x78.000y195.000z-0.020
G1 x112.000y195.000z-0.020
G0 z2.000 (lift up)
(time: 5.92652)
(line)
(time: 5.92652)
(linear cut)
G0 x74.000y195.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x40.000y195.000z-0.020
G1 x74.000y195.000z-0.020
G0 z2.000 (lift up)
(time: 6.1839)
(line)
(time: 6.1839)
(linear cut)
G0 x36.000y195.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x0.000y195.000z-0.020
G1 x36.000y195.000z-0.020
G0 z2.000 (lift up)
(time: 6.45463)

(line)
(time: 6.45463)
(linear cut)
G0 x-1.000y194.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x-1.000y147.500z-0.020
G1 x-1.000y194.000z-0.020
G0 z2.000 (lift up)
(time: 6.79469)
(line)
(time: 6.79469)
(linear cut)
G0 x-1.000y143.500 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x-1.000y99.000z-0.020
G1 x-1.000y143.500z-0.020
G0 z2.000 (lift up)
(time: 7.13041)
(line)
(time: 7.13041)
(linear cut)
G0 x-1.000y95.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x-1.000y50.500z-0.020
G1 x-1.000y95.000z-0.020
G0 z2.000 (lift up)
(time: 7.46479)
(line)
(time: 7.46479)
(linear cut)
G0 x-1.000y46.500 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x-1.000y0.000z-0.020
G1 x-1.000y46.500z-0.020
G0 z2.000 (lift up)
(time: 7.8125)
(time: 7.8125)
G0 z2.000 (lift up)
G0 x0.000y0.000 (travel)
(travel to safe place)

M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)
M30
(end)
