(GCode generated by cncgen - https://github.com/horvathzoltan/cncgen)
(type: GCode from geometry)
(input file: uniturn_also.txt)
(output file: uniturn_also.gcode)
(created on: Sze júl. 12 08:27:25 2023)
(total time: 02:13:06.000)
(total cut: 39136.5mm)
(total length: 43127.3mm)
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
(box)
(time: 0.00133333)
(hole - helical interpolation)
(time: 0.00133333)
(helical cut)
G0 x76.750y11.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.250
G2 z-0.400 i0.250
G2 z-0.600 i0.250
G2 z-0.800 i0.250
G2 z-1.000 i0.250
G2 z-1.200 i0.250
G2 z-1.400 i0.250
G2 z-1.600 i0.250
G2 z-1.800 i0.250
G2 z-2.000 i0.250
G2 z-2.200 i0.250
G2 z-2.200 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.129004)
(hole - helical interpolation)
(time: 0.129004)
(helical cut)
G0 x134.750y11.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.250
G2 z-0.400 i0.250
G2 z-0.600 i0.250
G2 z-0.800 i0.250
G2 z-1.000 i0.250
G2 z-1.200 i0.250
G2 z-1.400 i0.250
G2 z-1.600 i0.250
G2 z-1.800 i0.250
G2 z-2.000 i0.250
G2 z-2.200 i0.250
G2 z-2.200 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.243657)
(hole - helical interpolation)
(time: 0.243657)
(helical cut)
G0 x134.750y60.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.250
G2 z-0.400 i0.250
G2 z-0.600 i0.250
G2 z-0.800 i0.250
G2 z-1.000 i0.250
G2 z-1.200 i0.250
G2 z-1.400 i0.250
G2 z-1.600 i0.250
G2 z-1.800 i0.250
G2 z-2.000 i0.250
G2 z-2.200 i0.250
G2 z-2.200 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.352314)
(hole - helical interpolation)
(time: 0.352314)
(helical cut)
G0 x76.750y60.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.250
G2 z-0.400 i0.250
G2 z-0.600 i0.250
G2 z-0.800 i0.250
G2 z-1.000 i0.250
G2 z-1.200 i0.250
G2 z-1.400 i0.250
G2 z-1.600 i0.250
G2 z-1.800 i0.250
G2 z-2.000 i0.250
G2 z-2.200 i0.250
G2 z-2.200 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.466967)
(time: 0.466967)
(relé furatok)
(box)
(time: 0.466967)
(hole - helical interpolation)
(time: 0.466967)
(helical cut)
G0 x59.000y80.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.500
G2 z-0.400 i0.500
G2 z-0.600 i0.500
G2 z-0.800 i0.500
G2 z-1.000 i0.500
G2 z-1.200 i0.500
G2 z-1.400 i0.500
G2 z-1.600 i0.500
G2 z-1.800 i0.500
G2 z-2.000 i0.500
G2 z-2.200 i0.500
G2 z-2.200 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.623408)
(hole - helical interpolation)
(time: 0.623408)
(helical cut)
G0 x92.100y80.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.500
G2 z-0.400 i0.500
G2 z-0.600 i0.500
G2 z-0.800 i0.500
G2 z-1.000 i0.500
G2 z-1.200 i0.500
G2 z-1.400 i0.500
G2 z-1.600 i0.500
G2 z-1.800 i0.500
G2 z-2.000 i0.500
G2 z-2.200 i0.500
G2 z-2.200 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.784078)
(hole - helical interpolation)
(time: 0.784078)
(helical cut)
G0 x92.100y124.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.500
G2 z-0.400 i0.500
G2 z-0.600 i0.500
G2 z-0.800 i0.500
G2 z-1.000 i0.500
G2 z-1.200 i0.500
G2 z-1.400 i0.500
G2 z-1.600 i0.500
G2 z-1.800 i0.500
G2 z-2.000 i0.500
G2 z-2.200 i0.500
G2 z-2.200 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.952538)
(hole - helical interpolation)
(time: 0.952538)
(helical cut)
G0 x59.000y124.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.500
G2 z-0.400 i0.500
G2 z-0.600 i0.500
G2 z-0.800 i0.500
G2 z-1.000 i0.500
G2 z-1.200 i0.500
G2 z-1.400 i0.500
G2 z-1.600 i0.500
G2 z-1.800 i0.500
G2 z-2.000 i0.500
G2 z-2.200 i0.500
G2 z-2.200 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.11321)
(time: 1.11321)
(pizero furatok)
(box)
(time: 1.11321)
(hole - helical interpolation)
(time: 1.11321)
(helical cut)
G0 x122.750y70.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.250
G2 z-0.400 i0.250
G2 z-0.600 i0.250
G2 z-0.800 i0.250
G2 z-1.000 i0.250
G2 z-1.200 i0.250
G2 z-1.400 i0.250
G2 z-1.600 i0.250
G2 z-1.800 i0.250
G2 z-2.000 i0.250
G2 z-2.200 i0.250
G2 z-2.200 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.24502)
(hole - helical interpolation)
(time: 1.24502)
(helical cut)
G0 x145.750y70.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.250
G2 z-0.400 i0.250
G2 z-0.600 i0.250
G2 z-0.800 i0.250
G2 z-1.000 i0.250
G2 z-1.200 i0.250
G2 z-1.400 i0.250
G2 z-1.600 i0.250
G2 z-1.800 i0.250
G2 z-2.000 i0.250
G2 z-2.200 i0.250
G2 z-2.200 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.33637)
(hole - helical interpolation)
(time: 1.33637)
(helical cut)
G0 x145.750y128.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.250
G2 z-0.400 i0.250
G2 z-0.600 i0.250
G2 z-0.800 i0.250
G2 z-1.000 i0.250
G2 z-1.200 i0.250
G2 z-1.400 i0.250
G2 z-1.600 i0.250
G2 z-1.800 i0.250
G2 z-2.000 i0.250
G2 z-2.200 i0.250
G2 z-2.200 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.45102)
(hole - helical interpolation)
(time: 1.45102)
(helical cut)
G0 x122.750y128.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.250
G2 z-0.400 i0.250
G2 z-0.600 i0.250
G2 z-0.800 i0.250
G2 z-1.000 i0.250
G2 z-1.200 i0.250
G2 z-1.400 i0.250
G2 z-1.600 i0.250
G2 z-1.800 i0.250
G2 z-2.000 i0.250
G2 z-2.200 i0.250
G2 z-2.200 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.54238)
(time: 1.54238)
(alátámasztás)
(hole - helical interpolation)
(time: 1.54238)
(helical cut)
G0 x66.500y71.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.500
G2 z-0.400 i0.500
G2 z-0.600 i0.500
G2 z-0.800 i0.500
G2 z-1.000 i0.500
G2 z-1.200 i0.500
G2 z-1.400 i0.500
G2 z-1.600 i0.500
G2 z-1.800 i0.500
G2 z-2.000 i0.500
G2 z-2.200 i0.500
G2 z-2.200 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.73458)
(hole - helical interpolation)
(time: 1.73458)
(helical cut)
G0 x79.500y143.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.500
G2 z-0.400 i0.500
G2 z-0.600 i0.500
G2 z-0.800 i0.500
G2 z-1.000 i0.500
G2 z-1.200 i0.500
G2 z-1.400 i0.500
G2 z-1.600 i0.500
G2 z-1.800 i0.500
G2 z-2.000 i0.500
G2 z-2.200 i0.500
G2 z-2.200 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.92194)
(b3218101 - net-box 220, vers. i)
(rögzítő furatok)
(hole - helical interpolation)
(time: 1.92194)
(helical cut)
G0 x3.500y5.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.500
G2 z-0.400 i0.500
G2 z-0.600 i0.500
G2 z-0.800 i0.500
G2 z-1.000 i0.500
G2 z-1.200 i0.500
G2 z-1.400 i0.500
G2 z-1.600 i0.500
G2 z-1.800 i0.500
G2 z-2.000 i0.500
G2 z-2.200 i0.500
G2 z-2.200 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 2.16554)
(hole - helical interpolation)
(time: 2.16554)
(helical cut)
G0 x123.500y5.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.500
G2 z-0.400 i0.500
G2 z-0.600 i0.500
G2 z-0.800 i0.500
G2 z-1.000 i0.500
G2 z-1.200 i0.500
G2 z-1.400 i0.500
G2 z-1.600 i0.500
G2 z-1.800 i0.500
G2 z-2.000 i0.500
G2 z-2.200 i0.500
G2 z-2.200 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 2.38412)
(hole - helical interpolation)
(time: 2.38412)
(helical cut)
G0 x145.500y25.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.500
G2 z-0.400 i0.500
G2 z-0.600 i0.500
G2 z-0.800 i0.500
G2 z-1.000 i0.500
G2 z-1.200 i0.500
G2 z-1.400 i0.500
G2 z-1.600 i0.500
G2 z-1.800 i0.500
G2 z-2.000 i0.500
G2 z-2.200 i0.500
G2 z-2.200 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 2.54255)
(hole - helical interpolation)
(time: 2.54255)
(helical cut)
G0 x145.500y169.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.500
G2 z-0.400 i0.500
G2 z-0.600 i0.500
G2 z-0.800 i0.500
G2 z-1.000 i0.500
G2 z-1.200 i0.500
G2 z-1.400 i0.500
G2 z-1.600 i0.500
G2 z-1.800 i0.500
G2 z-2.000 i0.500
G2 z-2.200 i0.500
G2 z-2.200 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 2.77712)
(hole - helical interpolation)
(time: 2.77712)
(helical cut)
G0 x123.500y189.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.500
G2 z-0.400 i0.500
G2 z-0.600 i0.500
G2 z-0.800 i0.500
G2 z-1.000 i0.500
G2 z-1.200 i0.500
G2 z-1.400 i0.500
G2 z-1.600 i0.500
G2 z-1.800 i0.500
G2 z-2.000 i0.500
G2 z-2.200 i0.500
G2 z-2.200 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 2.93555)
(hole - helical interpolation)
(time: 2.93555)
(helical cut)
G0 x3.500y189.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.500
G2 z-0.400 i0.500
G2 z-0.600 i0.500
G2 z-0.800 i0.500
G2 z-1.000 i0.500
G2 z-1.200 i0.500
G2 z-1.400 i0.500
G2 z-1.600 i0.500
G2 z-1.800 i0.500
G2 z-2.000 i0.500
G2 z-2.200 i0.500
G2 z-2.200 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 3.15412)
(dugó kivágások)
(box)
(time: 3.15412)
(line)
(time: 3.15412)
(linear cut)
G0 x3.000y47.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x51.000y47.000z-0.200
G1 x3.000y47.000z-0.400
G1 x51.000y47.000z-0.600
G1 x3.000y47.000z-0.800
G1 x51.000y47.000z-1.000
G1 x3.000y47.000z-1.200
G1 x51.000y47.000z-1.400
G1 x3.000y47.000z-1.500
G1 x51.000y47.000z-1.500
G0 z2.000 (lift up)
(time: 4.69514)
(line)
(time: 4.69514)
(linear cut)
G0 x3.000y47.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x25.000y47.000z-1.700
G1 x3.000y47.000z-1.900
G1 x25.000y47.000z-2.100
G1 x3.000y47.000z-2.200
G1 x25.000y47.000z-2.200
G0 z2.000 (lift up)
(time: 5.10171)
(line)
(time: 5.10171)
(linear cut)
G0 x29.000y47.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x51.000y47.000z-1.700
G1 x29.000y47.000z-1.900
G1 x51.000y47.000z-2.100
G1 x29.000y47.000z-2.200
G1 x51.000y47.000z-2.200
G0 z2.000 (lift up)
(time: 5.47973)
(line)
(time: 5.47973)
(linear cut)
G0 x55.000y51.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x55.000y151.000z-0.200
G1 x55.000y51.000z-0.400
G1 x55.000y151.000z-0.600
G1 x55.000y51.000z-0.800
G1 x55.000y151.000z-1.000
G1 x55.000y51.000z-1.200
G1 x55.000y151.000z-1.400
G1 x55.000y51.000z-1.500
G1 x55.000y151.000z-1.500
G0 z2.000 (lift up)
(time: 8.49006)
(line)
(time: 8.49006)
(linear cut)
G0 x55.000y51.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x55.000y82.333z-1.700
G1 x55.000y51.000z-1.900
G1 x55.000y82.333z-2.100
G1 x55.000y51.000z-2.200
G1 x55.000y82.333z-2.200
G0 z2.000 (lift up)
(time: 9.0868)
(line)
(time: 9.0868)
(linear cut)
G0 x55.000y86.333 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x55.000y115.667z-1.700
G1 x55.000y86.333z-1.900
G1 x55.000y115.667z-2.100
G1 x55.000y86.333z-2.200
G1 x55.000y115.667z-2.200
G0 z2.000 (lift up)
(time: 9.58704)
(line)
(time: 9.58704)
(linear cut)
G0 x55.000y119.667 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x55.000y151.000z-1.700
G1 x55.000y119.667z-1.900
G1 x55.000y151.000z-2.100
G1 x55.000y119.667z-2.200
G1 x55.000y151.000z-2.200
G0 z2.000 (lift up)
(time: 10.1206)
(line)
(time: 10.1206)
(linear cut)
G0 x51.000y155.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x3.000y155.000z-0.200
G1 x51.000y155.000z-0.400
G1 x3.000y155.000z-0.600
G1 x51.000y155.000z-0.800
G1 x3.000y155.000z-1.000
G1 x51.000y155.000z-1.200
G1 x3.000y155.000z-1.400
G1 x51.000y155.000z-1.500
G1 x3.000y155.000z-1.500
G0 z2.000 (lift up)
(time: 11.571)
(line)
(time: 11.571)
(linear cut)
G0 x51.000y155.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x29.000y155.000z-1.700
G1 x51.000y155.000z-1.900
G1 x29.000y155.000z-2.100
G1 x51.000y155.000z-2.200
G1 x29.000y155.000z-2.200
G0 z2.000 (lift up)
(time: 11.9775)
(line)
(time: 11.9775)
(linear cut)
G0 x25.000y155.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x3.000y155.000z-1.700
G1 x25.000y155.000z-1.900
G1 x3.000y155.000z-2.100
G1 x25.000y155.000z-2.200
G1 x3.000y155.000z-2.200
G0 z2.000 (lift up)
(time: 12.3555)
(arc)
(time: 12.3555)
(circular_arc cut)
G0 x55.000y51.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x51.000y47.000z-0.200 i-4.000 j0.000
G3 x55.000y51.000z-0.400 i0.000 j4.000
G2 x51.000y47.000z-0.600 i-4.000 j0.000
G3 x55.000y51.000z-0.800 i0.000 j4.000
G2 x51.000y47.000z-1.000 i-4.000 j0.000
G3 x55.000y51.000z-1.200 i0.000 j4.000
G2 x51.000y47.000z-1.400 i-4.000 j0.000
G3 x55.000y51.000z-1.600 i0.000 j4.000
G2 x51.000y47.000z-1.800 i-4.000 j0.000
G3 x55.000y51.000z-2.000 i0.000 j4.000
G2 x51.000y47.000z-2.200 i-4.000 j0.000
G3 x55.000y51.000z-2.200 i0.000 j4.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 13.0238)
(arc)
(time: 13.0238)
(circular_arc cut)
G0 x51.000y155.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x55.000y151.000z-0.200 i0.000 j-4.000
G3 x51.000y155.000z-0.400 i-4.000 j0.000
G2 x55.000y151.000z-0.600 i0.000 j-4.000
G3 x51.000y155.000z-0.800 i-4.000 j0.000
G2 x55.000y151.000z-1.000 i0.000 j-4.000
G3 x51.000y155.000z-1.200 i-4.000 j0.000
G2 x55.000y151.000z-1.400 i0.000 j-4.000
G3 x51.000y155.000z-1.600 i-4.000 j0.000
G2 x55.000y151.000z-1.800 i0.000 j-4.000
G3 x51.000y155.000z-2.000 i-4.000 j0.000
G2 x55.000y151.000z-2.200 i0.000 j-4.000
G3 x51.000y155.000z-2.200 i-4.000 j0.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 27.4469)
(arc)
(time: 27.4469)
(circular_arc cut)
G0 x3.000y155.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x-1.000y159.000z-0.200 i0.000 j4.000
G3 x3.000y155.000z-0.400 i4.000 j0.000
G2 x-1.000y159.000z-0.600 i0.000 j4.000
G3 x3.000y155.000z-0.800 i4.000 j0.000
G2 x-1.000y159.000z-1.000 i0.000 j4.000
G3 x3.000y155.000z-1.200 i4.000 j0.000
G2 x-1.000y159.000z-1.400 i0.000 j4.000
G3 x3.000y155.000z-1.600 i4.000 j0.000
G2 x-1.000y159.000z-1.800 i0.000 j4.000
G3 x3.000y155.000z-2.000 i4.000 j0.000
G2 x-1.000y159.000z-2.200 i0.000 j4.000
G3 x3.000y155.000z-2.200 i4.000 j0.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 52.053)
(arc)
(time: 52.053)
(circular_arc cut)
G0 x-1.000y43.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x3.000y47.000z-0.200 i4.000 j0.000
G3 x-1.000y43.000z-0.400 i0.000 j-4.000
G2 x3.000y47.000z-0.600 i4.000 j0.000
G3 x-1.000y43.000z-0.800 i0.000 j-4.000
G2 x3.000y47.000z-1.000 i4.000 j0.000
G3 x-1.000y43.000z-1.200 i0.000 j-4.000
G2 x3.000y47.000z-1.400 i4.000 j0.000
G3 x-1.000y43.000z-1.600 i0.000 j-4.000
G2 x3.000y47.000z-1.800 i4.000 j0.000
G3 x-1.000y43.000z-2.000 i0.000 j-4.000
G2 x3.000y47.000z-2.200 i4.000 j0.000
G3 x-1.000y43.000z-2.200 i0.000 j-4.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 56.079)
(time: 56.079)
(box)
(time: 56.079)
(line)
(time: 56.079)
(linear cut)
G0 x3.000y21.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x17.000y21.000z-0.200
G1 x3.000y21.000z-0.400
G1 x17.000y21.000z-0.600
G1 x3.000y21.000z-0.800
G1 x17.000y21.000z-1.000
G1 x3.000y21.000z-1.200
G1 x17.000y21.000z-1.400
G1 x3.000y21.000z-1.500
G1 x17.000y21.000z-1.500
G0 z2.000 (lift up)
(time: 56.5203)
(line)
(time: 56.5203)
(linear cut)
G0 x3.000y21.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x8.000y21.000z-1.700
G04 P100
G1 x3.000y21.000z-1.900
G04 P100
G1 x8.000y21.000z-2.100
G04 P100
G1 x3.000y21.000z-2.200
G04 P100
G1 x8.000y21.000z-2.200
G04 P100
G0 z2.000 (lift up)
(time: 56.6211)
(line)
(time: 56.6211)
(linear cut)
G0 x12.000y21.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x17.000y21.000z-1.700
G04 P100
G1 x12.000y21.000z-1.900
G04 P100
G1 x17.000y21.000z-2.100
G04 P100
G1 x12.000y21.000z-2.200
G04 P100
G1 x17.000y21.000z-2.200
G04 P100
G0 z2.000 (lift up)
(time: 56.7158)
(line)
(time: 56.7158)
(linear cut)
G0 x21.000y25.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x21.000y43.000z-0.200
G1 x21.000y25.000z-0.400
G1 x21.000y43.000z-0.600
G1 x21.000y25.000z-0.800
G1 x21.000y43.000z-1.000
G1 x21.000y25.000z-1.200
G1 x21.000y43.000z-1.400
G1 x21.000y25.000z-1.500
G1 x21.000y43.000z-1.500
G0 z2.000 (lift up)
(time: 57.2662)
(line)
(time: 57.2662)
(linear cut)
G0 x21.000y25.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x21.000y32.000z-1.700
G04 P100
G1 x21.000y25.000z-1.900
G04 P100
G1 x21.000y32.000z-2.100
G04 P100
G1 x21.000y25.000z-2.200
G04 P100
G1 x21.000y32.000z-2.200
G04 P100
G0 z2.000 (lift up)
(time: 57.4029)
(line)
(time: 57.4029)
(linear cut)
G0 x21.000y36.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x21.000y43.000z-1.700
G04 P100
G1 x21.000y36.000z-1.900
G04 P100
G1 x21.000y43.000z-2.100
G04 P100
G1 x21.000y36.000z-2.200
G04 P100
G1 x21.000y43.000z-2.200
G04 P100
G0 z2.000 (lift up)
(time: 57.5309)
(arc)
(time: 57.5309)
(circular_arc cut)
G0 x21.000y25.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x17.000y21.000z-0.200 i-4.000 j0.000
G3 x21.000y25.000z-0.400 i0.000 j4.000
G2 x17.000y21.000z-0.600 i-4.000 j0.000
G3 x21.000y25.000z-0.800 i0.000 j4.000
G2 x17.000y21.000z-1.000 i-4.000 j0.000
G3 x21.000y25.000z-1.200 i0.000 j4.000
G2 x17.000y21.000z-1.400 i-4.000 j0.000
G3 x21.000y25.000z-1.600 i0.000 j4.000
G2 x17.000y21.000z-1.800 i-4.000 j0.000
G3 x21.000y25.000z-2.000 i0.000 j4.000
G2 x17.000y21.000z-2.200 i-4.000 j0.000
G3 x21.000y25.000z-2.200 i0.000 j4.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 58.1531)
(arc)
(time: 58.1531)
(circular_arc cut)
G0 x21.000y43.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x25.000y47.000z-0.200 i4.000 j0.000
G3 x21.000y43.000z-0.400 i0.000 j-4.000
G2 x25.000y47.000z-0.600 i4.000 j0.000
G3 x21.000y43.000z-0.800 i0.000 j-4.000
G2 x25.000y47.000z-1.000 i4.000 j0.000
G3 x21.000y43.000z-1.200 i0.000 j-4.000
G2 x25.000y47.000z-1.400 i4.000 j0.000
G3 x21.000y43.000z-1.600 i0.000 j-4.000
G2 x25.000y47.000z-1.800 i4.000 j0.000
G3 x21.000y43.000z-2.000 i0.000 j-4.000
G2 x25.000y47.000z-2.200 i4.000 j0.000
G3 x21.000y43.000z-2.200 i0.000 j-4.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 60.0683)

(arc)
(time: 60.0683)
(circular_arc cut)
G0 x-1.000y17.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x3.000y21.000z-0.200 i4.000 j0.000
G3 x-1.000y17.000z-0.400 i0.000 j-4.000
G2 x3.000y21.000z-0.600 i4.000 j0.000
G3 x-1.000y17.000z-0.800 i0.000 j-4.000
G2 x3.000y21.000z-1.000 i4.000 j0.000
G3 x-1.000y17.000z-1.200 i0.000 j-4.000
G2 x3.000y21.000z-1.400 i4.000 j0.000
G3 x-1.000y17.000z-1.600 i0.000 j-4.000
G2 x3.000y21.000z-1.800 i4.000 j0.000
G3 x-1.000y17.000z-2.000 i0.000 j-4.000
G2 x3.000y21.000z-2.200 i4.000 j0.000
G3 x-1.000y17.000z-2.200 i0.000 j-4.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 61.5328)
(time: 61.5328)
(usb hub furatai)
(körvonal)
(box)
(time: 61.5328)
(line)
(time: 61.5328)
(linear cut)
G0 x4.000y-1.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x148.000y-1.000z-0.200
G1 x4.000y-1.000z-0.400
G1 x148.000y-1.000z-0.600
G1 x4.000y-1.000z-0.800
G1 x148.000y-1.000z-1.000
G1 x4.000y-1.000z-1.200
G1 x148.000y-1.000z-1.400
G1 x4.000y-1.000z-1.500
G1 x148.000y-1.000z-1.500
G0 z2.000 (lift up)
(time: 65.8717)
(line)
(time: 65.8717)
(linear cut)
G0 x4.000y-1.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x38.000y-1.000z-1.700
G1 x4.000y-1.000z-1.900
G1 x38.000y-1.000z-2.100
G1 x4.000y-1.000z-2.200
G1 x38.000y-1.000z-2.200
G0 z2.000 (lift up)
(time: 66.5422)
(line)
(time: 66.5422)
(linear cut)
G0 x42.000y-1.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x74.000y-1.000z-1.700
G1 x42.000y-1.000z-1.900
G1 x74.000y-1.000z-2.100
G1 x42.000y-1.000z-2.200
G1 x74.000y-1.000z-2.200
G0 z2.000 (lift up)
(time: 67.0869)
(line)
(time: 67.0869)
(linear cut)
G0 x78.000y-1.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x110.000y-1.000z-1.700
G1 x78.000y-1.000z-1.900
G1 x110.000y-1.000z-2.100
G1 x78.000y-1.000z-2.200
G1 x110.000y-1.000z-2.200
G0 z2.000 (lift up)
(time: 67.6316)
(line)
(time: 67.6316)
(linear cut)
G0 x114.000y-1.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x148.000y-1.000z-1.700
G1 x114.000y-1.000z-1.900
G1 x148.000y-1.000z-2.100
G1 x114.000y-1.000z-2.200
G1 x148.000y-1.000z-2.200
G0 z2.000 (lift up)
(time: 68.2096)
(line)
(time: 68.2096)
(linear cut)
G0 x153.000y4.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x153.000y190.000z-0.200
G1 x153.000y4.000z-0.400
G1 x153.000y190.000z-0.600
G1 x153.000y4.000z-0.800
G1 x153.000y190.000z-1.000
G1 x153.000y4.000z-1.200
G1 x153.000y190.000z-1.400
G1 x153.000y4.000z-1.500
G1 x153.000y190.000z-1.500
G0 z2.000 (lift up)
(time: 73.8008)
(line)
(time: 73.8008)
(linear cut)
G0 x153.000y4.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x153.000y48.500z-1.700
G1 x153.000y4.000z-1.900
G1 x153.000y48.500z-2.100
G1 x153.000y4.000z-2.200
G1 x153.000y48.500z-2.200
G0 z2.000 (lift up)
(time: 74.6743)
(line)
(time: 74.6743)
(linear cut)
G0 x153.000y52.500 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x153.000y95.000z-1.700
G1 x153.000y52.500z-1.900
G1 x153.000y95.000z-2.100
G1 x153.000y52.500z-2.200
G1 x153.000y95.000z-2.200
G0 z2.000 (lift up)
(time: 75.394)
(line)
(time: 75.394)
(linear cut)
G0 x153.000y99.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x153.000y141.500z-1.700
G1 x153.000y99.000z-1.900
G1 x153.000y141.500z-2.100
G1 x153.000y99.000z-2.200
G1 x153.000y141.500z-2.200
G0 z2.000 (lift up)
(time: 76.1137)
(line)
(time: 76.1137)
(linear cut)
G0 x153.000y145.500 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x153.000y190.000z-1.700
G1 x153.000y145.500z-1.900
G1 x153.000y190.000z-2.100
G1 x153.000y145.500z-2.200
G1 x153.000y190.000z-2.200
G0 z2.000 (lift up)
(time: 76.8667)
(line)
(time: 76.8667)
(linear cut)
G0 x148.000y195.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x4.000y195.000z-0.200
G1 x148.000y195.000z-0.400
G1 x4.000y195.000z-0.600
G1 x148.000y195.000z-0.800
G1 x4.000y195.000z-1.000
G1 x148.000y195.000z-1.200
G1 x4.000y195.000z-1.400
G1 x148.000y195.000z-1.500
G1 x4.000y195.000z-1.500
G0 z2.000 (lift up)
(time: 81.1979)
(line)
(time: 81.1979)
(linear cut)
G0 x148.000y195.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x114.000y195.000z-1.700
G1 x148.000y195.000z-1.900
G1 x114.000y195.000z-2.100
G1 x148.000y195.000z-2.200
G1 x114.000y195.000z-2.200
G0 z2.000 (lift up)
(time: 81.8684)
(line)
(time: 81.8684)
(linear cut)
G0 x110.000y195.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x78.000y195.000z-1.700
G1 x110.000y195.000z-1.900
G1 x78.000y195.000z-2.100
G1 x110.000y195.000z-2.200
G1 x78.000y195.000z-2.200
G0 z2.000 (lift up)
(time: 82.4131)
(line)
(time: 82.4131)
(linear cut)
G0 x74.000y195.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x42.000y195.000z-1.700
G1 x74.000y195.000z-1.900
G1 x42.000y195.000z-2.100
G1 x74.000y195.000z-2.200
G1 x42.000y195.000z-2.200
G0 z2.000 (lift up)
(time: 82.9578)
(line)
(time: 82.9578)
(linear cut)
G0 x38.000y195.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x4.000y195.000z-1.700
G1 x38.000y195.000z-1.900
G1 x4.000y195.000z-2.100
G1 x38.000y195.000z-2.200
G1 x4.000y195.000z-2.200
G0 z2.000 (lift up)
(time: 83.5358)
(line)
(time: 83.5358)
(linear cut)
G0 x-1.000y190.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x-1.000y4.000z-0.200
G1 x-1.000y190.000z-0.400
G1 x-1.000y4.000z-0.600
G1 x-1.000y190.000z-0.800
G1 x-1.000y4.000z-1.000
G1 x-1.000y190.000z-1.200
G1 x-1.000y4.000z-1.400
G1 x-1.000y190.000z-1.500
G1 x-1.000y4.000z-1.500
G0 z2.000 (lift up)
(time: 89.127)
(line)
(time: 89.127)
(linear cut)
G0 x-1.000y190.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x-1.000y145.500z-1.700
G1 x-1.000y190.000z-1.900
G1 x-1.000y145.500z-2.100
G1 x-1.000y190.000z-2.200
G1 x-1.000y145.500z-2.200
G0 z2.000 (lift up)
(time: 90.0005)
(line)
(time: 90.0005)
(linear cut)
G0 x-1.000y141.500 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x-1.000y99.000z-1.700
G1 x-1.000y141.500z-1.900
G1 x-1.000y99.000z-2.100
G1 x-1.000y141.500z-2.200
G1 x-1.000y99.000z-2.200
G0 z2.000 (lift up)
(time: 90.7202)
(line)
(time: 90.7202)
(linear cut)
G0 x-1.000y95.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x-1.000y52.500z-1.700
G1 x-1.000y95.000z-1.900
G1 x-1.000y52.500z-2.100
G1 x-1.000y95.000z-2.200
G1 x-1.000y52.500z-2.200
G0 z2.000 (lift up)
(time: 91.4399)
(line)
(time: 91.4399)
(linear cut)
G0 x-1.000y48.500 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x-1.000y4.000z-1.700
G1 x-1.000y48.500z-1.900
G1 x-1.000y4.000z-2.100
G1 x-1.000y48.500z-2.200
G1 x-1.000y4.000z-2.200
G0 z2.000 (lift up)
(time: 92.1929)
(arc)
(time: 92.1929)
(circular_arc cut)
G0 x153.000y4.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x148.000y-1.000z-0.200 i-5.000 j0.000
G3 x153.000y4.000z-0.400 i0.000 j5.000
G2 x148.000y-1.000z-0.600 i-5.000 j0.000
G3 x153.000y4.000z-0.800 i0.000 j5.000
G2 x148.000y-1.000z-1.000 i-5.000 j0.000
G3 x153.000y4.000z-1.200 i0.000 j5.000
G2 x148.000y-1.000z-1.400 i-5.000 j0.000
G3 x153.000y4.000z-1.600 i0.000 j5.000
G2 x148.000y-1.000z-1.800 i-5.000 j0.000
G3 x153.000y4.000z-2.000 i0.000 j5.000
G2 x148.000y-1.000z-2.200 i-5.000 j0.000
G3 x153.000y4.000z-2.200 i0.000 j5.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 107.426)
(arc)
(time: 107.426)
(circular_arc cut)
G0 x148.000y195.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x153.000y190.000z-0.200 i0.000 j-5.000
G3 x148.000y195.000z-0.400 i-5.000 j0.000
G2 x153.000y190.000z-0.600 i0.000 j-5.000
G3 x148.000y195.000z-0.800 i-5.000 j0.000
G2 x153.000y190.000z-1.000 i0.000 j-5.000
G3 x148.000y195.000z-1.200 i-5.000 j0.000
G2 x153.000y190.000z-1.400 i0.000 j-5.000
G3 x148.000y195.000z-1.600 i-5.000 j0.000
G2 x153.000y190.000z-1.800 i0.000 j-5.000
G3 x148.000y195.000z-2.000 i-5.000 j0.000
G2 x153.000y190.000z-2.200 i0.000 j-5.000
G3 x148.000y195.000z-2.200 i-5.000 j0.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 113.894)
(arc)
(time: 113.894)
(circular_arc cut)
G0 x-1.000y190.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x4.000y195.000z-0.200 i5.000 j0.000
G3 x-1.000y190.000z-0.400 i0.000 j-5.000
G2 x4.000y195.000z-0.600 i5.000 j0.000
G3 x-1.000y190.000z-0.800 i0.000 j-5.000
G2 x4.000y195.000z-1.000 i5.000 j0.000
G3 x-1.000y190.000z-1.200 i0.000 j-5.000
G2 x4.000y195.000z-1.400 i5.000 j0.000
G3 x-1.000y190.000z-1.600 i0.000 j-5.000
G2 x4.000y195.000z-1.800 i5.000 j0.000
G3 x-1.000y190.000z-2.000 i0.000 j-5.000
G2 x4.000y195.000z-2.200 i5.000 j0.000
G3 x-1.000y190.000z-2.200 i0.000 j-5.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 132.098)
(arc)
(time: 132.098)
(circular_arc cut)
G0 x4.000y-1.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x-1.000y4.000z-0.200 i0.000 j5.000
G3 x4.000y-1.000z-0.400 i5.000 j0.000
G2 x-1.000y4.000z-0.600 i0.000 j5.000
G3 x4.000y-1.000z-0.800 i5.000 j0.000
G2 x-1.000y4.000z-1.000 i0.000 j5.000
G3 x4.000y-1.000z-1.200 i5.000 j0.000
G2 x-1.000y4.000z-1.400 i0.000 j5.000
G3 x4.000y-1.000z-1.600 i5.000 j0.000
G2 x-1.000y4.000z-1.800 i0.000 j5.000
G3 x4.000y-1.000z-2.000 i5.000 j0.000
G2 x-1.000y4.000z-2.200 i0.000 j5.000
G3 x4.000y-1.000z-2.200 i5.000 j0.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 133.111)
(time: 133.111)
G0 z2.000 (lift up)
G0 x0.000y0.000 (travel)
(travel to safe place)

M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)
M30
(end)
