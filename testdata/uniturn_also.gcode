(GCode generated by cncgen - https://github.com/horvathzoltan/cncgen)
(type: GCode from geometry)
(input file: uniturn_also.txt)
(output file: uniturn_also.gcode)
(created on: P júl. 7 08:53:57 2023)
(total time: 01:27:45.000)
(total cut: 25844.1mm)
(total length: 28251.1mm)
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
(szerszám beállítás)
(cmd line: -i uniturn_also.txt -t)
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
G2 z-0.100 i0.250
G2 z-0.200 i0.250
G2 z-0.300 i0.250
G2 z-0.400 i0.250
G2 z-0.500 i0.250
G2 z-0.600 i0.250
G2 z-0.700 i0.250
G2 z-0.800 i0.250
G2 z-0.900 i0.250
G2 z-1.000 i0.250
G2 z-1.100 i0.250
G2 z-1.200 i0.250
G2 z-1.300 i0.250
G2 z-1.400 i0.250
G2 z-1.500 i0.250
G2 z-1.600 i0.250
G2 z-1.700 i0.250
G2 z-1.800 i0.250
G2 z-1.900 i0.250
G2 z-2.000 i0.250
G2 z-2.100 i0.250
G2 z-2.200 i0.250
G2 z-2.300 i0.250
G2 z-2.400 i0.250
G2 z-2.500 i0.250
G2 z-2.600 i0.250
G2 z-2.700 i0.250
G2 z-2.800 i0.250
G2 z-2.800 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.192416)
(hole - helical interpolation)
(time: 0.192416)
(helical cut)
G0 x82.350y27.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.250
G2 z-0.200 i0.250
G2 z-0.300 i0.250
G2 z-0.400 i0.250
G2 z-0.500 i0.250
G2 z-0.600 i0.250
G2 z-0.700 i0.250
G2 z-0.800 i0.250
G2 z-0.900 i0.250
G2 z-1.000 i0.250
G2 z-1.100 i0.250
G2 z-1.200 i0.250
G2 z-1.300 i0.250
G2 z-1.400 i0.250
G2 z-1.500 i0.250
G2 z-1.600 i0.250
G2 z-1.700 i0.250
G2 z-1.800 i0.250
G2 z-1.900 i0.250
G2 z-2.000 i0.250
G2 z-2.100 i0.250
G2 z-2.200 i0.250
G2 z-2.300 i0.250
G2 z-2.400 i0.250
G2 z-2.500 i0.250
G2 z-2.600 i0.250
G2 z-2.700 i0.250
G2 z-2.800 i0.250
G2 z-2.800 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.397913)
(hole - helical interpolation)
(time: 0.397913)
(helical cut)
G0 x82.350y76.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.250
G2 z-0.200 i0.250
G2 z-0.300 i0.250
G2 z-0.400 i0.250
G2 z-0.500 i0.250
G2 z-0.600 i0.250
G2 z-0.700 i0.250
G2 z-0.800 i0.250
G2 z-0.900 i0.250
G2 z-1.000 i0.250
G2 z-1.100 i0.250
G2 z-1.200 i0.250
G2 z-1.300 i0.250
G2 z-1.400 i0.250
G2 z-1.500 i0.250
G2 z-1.600 i0.250
G2 z-1.700 i0.250
G2 z-1.800 i0.250
G2 z-1.900 i0.250
G2 z-2.000 i0.250
G2 z-2.100 i0.250
G2 z-2.200 i0.250
G2 z-2.300 i0.250
G2 z-2.400 i0.250
G2 z-2.500 i0.250
G2 z-2.600 i0.250
G2 z-2.700 i0.250
G2 z-2.800 i0.250
G2 z-2.800 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.597414)
(hole - helical interpolation)
(time: 0.597414)
(helical cut)
G0 x24.350y76.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.250
G2 z-0.200 i0.250
G2 z-0.300 i0.250
G2 z-0.400 i0.250
G2 z-0.500 i0.250
G2 z-0.600 i0.250
G2 z-0.700 i0.250
G2 z-0.800 i0.250
G2 z-0.900 i0.250
G2 z-1.000 i0.250
G2 z-1.100 i0.250
G2 z-1.200 i0.250
G2 z-1.300 i0.250
G2 z-1.400 i0.250
G2 z-1.500 i0.250
G2 z-1.600 i0.250
G2 z-1.700 i0.250
G2 z-1.800 i0.250
G2 z-1.900 i0.250
G2 z-2.000 i0.250
G2 z-2.100 i0.250
G2 z-2.200 i0.250
G2 z-2.300 i0.250
G2 z-2.400 i0.250
G2 z-2.500 i0.250
G2 z-2.600 i0.250
G2 z-2.700 i0.250
G2 z-2.800 i0.250
G2 z-2.800 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.80291)
(time: 0.80291)
(relé furatok)
(hole - helical interpolation)
(time: 0.80291)
(helical cut)
G0 x105.500y12.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.500
G2 z-0.200 i0.500
G2 z-0.300 i0.500
G2 z-0.400 i0.500
G2 z-0.500 i0.500
G2 z-0.600 i0.500
G2 z-0.700 i0.500
G2 z-0.800 i0.500
G2 z-0.900 i0.500
G2 z-1.000 i0.500
G2 z-1.100 i0.500
G2 z-1.200 i0.500
G2 z-1.300 i0.500
G2 z-1.400 i0.500
G2 z-1.500 i0.500
G2 z-1.600 i0.500
G2 z-1.700 i0.500
G2 z-1.800 i0.500
G2 z-1.900 i0.500
G2 z-2.000 i0.500
G2 z-2.100 i0.500
G2 z-2.200 i0.500
G2 z-2.300 i0.500
G2 z-2.400 i0.500
G2 z-2.500 i0.500
G2 z-2.600 i0.500
G2 z-2.700 i0.500
G2 z-2.800 i0.500
G2 z-2.800 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.19004)
(hole - helical interpolation)
(time: 1.19004)
(helical cut)
G0 x138.600y12.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.500
G2 z-0.200 i0.500
G2 z-0.300 i0.500
G2 z-0.400 i0.500
G2 z-0.500 i0.500
G2 z-0.600 i0.500
G2 z-0.700 i0.500
G2 z-0.800 i0.500
G2 z-0.900 i0.500
G2 z-1.000 i0.500
G2 z-1.100 i0.500
G2 z-1.200 i0.500
G2 z-1.300 i0.500
G2 z-1.400 i0.500
G2 z-1.500 i0.500
G2 z-1.600 i0.500
G2 z-1.700 i0.500
G2 z-1.800 i0.500
G2 z-1.900 i0.500
G2 z-2.000 i0.500
G2 z-2.100 i0.500
G2 z-2.200 i0.500
G2 z-2.300 i0.500
G2 z-2.400 i0.500
G2 z-2.500 i0.500
G2 z-2.600 i0.500
G2 z-2.700 i0.500
G2 z-2.800 i0.500
G2 z-2.800 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.53065)
(hole - helical interpolation)
(time: 1.53065)
(helical cut)
G0 x139.500y57.350 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.500
G2 z-0.200 i0.500
G2 z-0.300 i0.500
G2 z-0.400 i0.500
G2 z-0.500 i0.500
G2 z-0.600 i0.500
G2 z-0.700 i0.500
G2 z-0.800 i0.500
G2 z-0.900 i0.500
G2 z-1.000 i0.500
G2 z-1.100 i0.500
G2 z-1.200 i0.500
G2 z-1.300 i0.500
G2 z-1.400 i0.500
G2 z-1.500 i0.500
G2 z-1.600 i0.500
G2 z-1.700 i0.500
G2 z-1.800 i0.500
G2 z-1.900 i0.500
G2 z-2.000 i0.500
G2 z-2.100 i0.500
G2 z-2.200 i0.500
G2 z-2.300 i0.500
G2 z-2.400 i0.500
G2 z-2.500 i0.500
G2 z-2.600 i0.500
G2 z-2.700 i0.500
G2 z-2.800 i0.500
G2 z-2.800 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.87915)
(hole - helical interpolation)
(time: 1.87915)
(helical cut)
G0 x105.500y57.350 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.500
G2 z-0.200 i0.500
G2 z-0.300 i0.500
G2 z-0.400 i0.500
G2 z-0.500 i0.500
G2 z-0.600 i0.500
G2 z-0.700 i0.500
G2 z-0.800 i0.500
G2 z-0.900 i0.500
G2 z-1.000 i0.500
G2 z-1.100 i0.500
G2 z-1.200 i0.500
G2 z-1.300 i0.500
G2 z-1.400 i0.500
G2 z-1.500 i0.500
G2 z-1.600 i0.500
G2 z-1.700 i0.500
G2 z-1.800 i0.500
G2 z-1.900 i0.500
G2 z-2.000 i0.500
G2 z-2.100 i0.500
G2 z-2.200 i0.500
G2 z-2.300 i0.500
G2 z-2.400 i0.500
G2 z-2.500 i0.500
G2 z-2.600 i0.500
G2 z-2.700 i0.500
G2 z-2.800 i0.500
G2 z-2.800 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 2.22036)
(pizero furatok)
(box)
(time: 2.22036)
(hole - helical interpolation)
(time: 2.22036)
(helical cut)
G0 x115.750y70.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.250
G2 z-0.200 i0.250
G2 z-0.300 i0.250
G2 z-0.400 i0.250
G2 z-0.500 i0.250
G2 z-0.600 i0.250
G2 z-0.700 i0.250
G2 z-0.800 i0.250
G2 z-0.900 i0.250
G2 z-1.000 i0.250
G2 z-1.100 i0.250
G2 z-1.200 i0.250
G2 z-1.300 i0.250
G2 z-1.400 i0.250
G2 z-1.500 i0.250
G2 z-1.600 i0.250
G2 z-1.700 i0.250
G2 z-1.800 i0.250
G2 z-1.900 i0.250
G2 z-2.000 i0.250
G2 z-2.100 i0.250
G2 z-2.200 i0.250
G2 z-2.300 i0.250
G2 z-2.400 i0.250
G2 z-2.500 i0.250
G2 z-2.600 i0.250
G2 z-2.700 i0.250
G2 z-2.800 i0.250
G2 z-2.800 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 2.3981)
(hole - helical interpolation)
(time: 2.3981)
(helical cut)
G0 x138.750y70.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.250
G2 z-0.200 i0.250
G2 z-0.300 i0.250
G2 z-0.400 i0.250
G2 z-0.500 i0.250
G2 z-0.600 i0.250
G2 z-0.700 i0.250
G2 z-0.800 i0.250
G2 z-0.900 i0.250
G2 z-1.000 i0.250
G2 z-1.100 i0.250
G2 z-1.200 i0.250
G2 z-1.300 i0.250
G2 z-1.400 i0.250
G2 z-1.500 i0.250
G2 z-1.600 i0.250
G2 z-1.700 i0.250
G2 z-1.800 i0.250
G2 z-1.900 i0.250
G2 z-2.000 i0.250
G2 z-2.100 i0.250
G2 z-2.200 i0.250
G2 z-2.300 i0.250
G2 z-2.400 i0.250
G2 z-2.500 i0.250
G2 z-2.600 i0.250
G2 z-2.700 i0.250
G2 z-2.800 i0.250
G2 z-2.800 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 2.5803)
(hole - helical interpolation)
(time: 2.5803)
(helical cut)
G0 x138.750y128.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.250
G2 z-0.200 i0.250
G2 z-0.300 i0.250
G2 z-0.400 i0.250
G2 z-0.500 i0.250
G2 z-0.600 i0.250
G2 z-0.700 i0.250
G2 z-0.800 i0.250
G2 z-0.900 i0.250
G2 z-1.000 i0.250
G2 z-1.100 i0.250
G2 z-1.200 i0.250
G2 z-1.300 i0.250
G2 z-1.400 i0.250
G2 z-1.500 i0.250
G2 z-1.600 i0.250
G2 z-1.700 i0.250
G2 z-1.800 i0.250
G2 z-1.900 i0.250
G2 z-2.000 i0.250
G2 z-2.100 i0.250
G2 z-2.200 i0.250
G2 z-2.300 i0.250
G2 z-2.400 i0.250
G2 z-2.500 i0.250
G2 z-2.600 i0.250
G2 z-2.700 i0.250
G2 z-2.800 i0.250
G2 z-2.800 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 2.7858)
(hole - helical interpolation)
(time: 2.7858)
(helical cut)
G0 x115.750y128.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.250
G2 z-0.200 i0.250
G2 z-0.300 i0.250
G2 z-0.400 i0.250
G2 z-0.500 i0.250
G2 z-0.600 i0.250
G2 z-0.700 i0.250
G2 z-0.800 i0.250
G2 z-0.900 i0.250
G2 z-1.000 i0.250
G2 z-1.100 i0.250
G2 z-1.200 i0.250
G2 z-1.300 i0.250
G2 z-1.400 i0.250
G2 z-1.500 i0.250
G2 z-1.600 i0.250
G2 z-1.700 i0.250
G2 z-1.800 i0.250
G2 z-1.900 i0.250
G2 z-2.000 i0.250
G2 z-2.100 i0.250
G2 z-2.200 i0.250
G2 z-2.300 i0.250
G2 z-2.400 i0.250
G2 z-2.500 i0.250
G2 z-2.600 i0.250
G2 z-2.700 i0.250
G2 z-2.800 i0.250
G2 z-2.800 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 2.968)
(time: 2.968)
(rfid furatok)
(hole - helical interpolation)
(time: 2.968)
(helical cut)
G0 x84.600y122.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.500
G2 z-0.200 i0.500
G2 z-0.300 i0.500
G2 z-0.400 i0.500
G2 z-0.500 i0.500
G2 z-0.600 i0.500
G2 z-0.700 i0.500
G2 z-0.800 i0.500
G2 z-0.900 i0.500
G2 z-1.000 i0.500
G2 z-1.100 i0.500
G2 z-1.200 i0.500
G2 z-1.300 i0.500
G2 z-1.400 i0.500
G2 z-1.500 i0.500
G2 z-1.600 i0.500
G2 z-1.700 i0.500
G2 z-1.800 i0.500
G2 z-1.900 i0.500
G2 z-2.000 i0.500
G2 z-2.100 i0.500
G2 z-2.200 i0.500
G2 z-2.300 i0.500
G2 z-2.400 i0.500
G2 z-2.500 i0.500
G2 z-2.600 i0.500
G2 z-2.700 i0.500
G2 z-2.800 i0.500
G2 z-2.800 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 3.30764)
(hole - helical interpolation)
(time: 3.30764)
(helical cut)
G0 x68.700y85.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.500
G2 z-0.200 i0.500
G2 z-0.300 i0.500
G2 z-0.400 i0.500
G2 z-0.500 i0.500
G2 z-0.600 i0.500
G2 z-0.700 i0.500
G2 z-0.800 i0.500
G2 z-0.900 i0.500
G2 z-1.000 i0.500
G2 z-1.100 i0.500
G2 z-1.200 i0.500
G2 z-1.300 i0.500
G2 z-1.400 i0.500
G2 z-1.500 i0.500
G2 z-1.600 i0.500
G2 z-1.700 i0.500
G2 z-1.800 i0.500
G2 z-1.900 i0.500
G2 z-2.000 i0.500
G2 z-2.100 i0.500
G2 z-2.200 i0.500
G2 z-2.300 i0.500
G2 z-2.400 i0.500
G2 z-2.500 i0.500
G2 z-2.600 i0.500
G2 z-2.700 i0.500
G2 z-2.800 i0.500
G2 z-2.800 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 3.6529)
(b3218101 - net-box 220, vers. i)
(rögzítő furatok)
(hole - helical interpolation)
(time: 3.6529)
(helical cut)
G0 x3.500y5.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.500
G2 z-0.200 i0.500
G2 z-0.300 i0.500
G2 z-0.400 i0.500
G2 z-0.500 i0.500
G2 z-0.600 i0.500
G2 z-0.700 i0.500
G2 z-0.800 i0.500
G2 z-0.900 i0.500
G2 z-1.000 i0.500
G2 z-1.100 i0.500
G2 z-1.200 i0.500
G2 z-1.300 i0.500
G2 z-1.400 i0.500
G2 z-1.500 i0.500
G2 z-1.600 i0.500
G2 z-1.700 i0.500
G2 z-1.800 i0.500
G2 z-1.900 i0.500
G2 z-2.000 i0.500
G2 z-2.100 i0.500
G2 z-2.200 i0.500
G2 z-2.300 i0.500
G2 z-2.400 i0.500
G2 z-2.500 i0.500
G2 z-2.600 i0.500
G2 z-2.700 i0.500
G2 z-2.800 i0.500
G2 z-2.800 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 4.04053)
(hole - helical interpolation)
(time: 4.04053)
(helical cut)
G0 x123.500y5.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.500
G2 z-0.200 i0.500
G2 z-0.300 i0.500
G2 z-0.400 i0.500
G2 z-0.500 i0.500
G2 z-0.600 i0.500
G2 z-0.700 i0.500
G2 z-0.800 i0.500
G2 z-0.900 i0.500
G2 z-1.000 i0.500
G2 z-1.100 i0.500
G2 z-1.200 i0.500
G2 z-1.300 i0.500
G2 z-1.400 i0.500
G2 z-1.500 i0.500
G2 z-1.600 i0.500
G2 z-1.700 i0.500
G2 z-1.800 i0.500
G2 z-1.900 i0.500
G2 z-2.000 i0.500
G2 z-2.100 i0.500
G2 z-2.200 i0.500
G2 z-2.300 i0.500
G2 z-2.400 i0.500
G2 z-2.500 i0.500
G2 z-2.600 i0.500
G2 z-2.700 i0.500
G2 z-2.800 i0.500
G2 z-2.800 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 4.43904)
(hole - helical interpolation)
(time: 4.43904)
(helical cut)
G0 x145.500y25.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.500
G2 z-0.200 i0.500
G2 z-0.300 i0.500
G2 z-0.400 i0.500
G2 z-0.500 i0.500
G2 z-0.600 i0.500
G2 z-0.700 i0.500
G2 z-0.800 i0.500
G2 z-0.900 i0.500
G2 z-1.000 i0.500
G2 z-1.100 i0.500
G2 z-1.200 i0.500
G2 z-1.300 i0.500
G2 z-1.400 i0.500
G2 z-1.500 i0.500
G2 z-1.600 i0.500
G2 z-1.700 i0.500
G2 z-1.800 i0.500
G2 z-1.900 i0.500
G2 z-2.000 i0.500
G2 z-2.100 i0.500
G2 z-2.200 i0.500
G2 z-2.300 i0.500
G2 z-2.400 i0.500
G2 z-2.500 i0.500
G2 z-2.600 i0.500
G2 z-2.700 i0.500
G2 z-2.800 i0.500
G2 z-2.800 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 4.77741)
(hole - helical interpolation)
(time: 4.77741)
(helical cut)
G0 x145.500y169.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.500
G2 z-0.200 i0.500
G2 z-0.300 i0.500
G2 z-0.400 i0.500
G2 z-0.500 i0.500
G2 z-0.600 i0.500
G2 z-0.700 i0.500
G2 z-0.800 i0.500
G2 z-0.900 i0.500
G2 z-1.000 i0.500
G2 z-1.100 i0.500
G2 z-1.200 i0.500
G2 z-1.300 i0.500
G2 z-1.400 i0.500
G2 z-1.500 i0.500
G2 z-1.600 i0.500
G2 z-1.700 i0.500
G2 z-1.800 i0.500
G2 z-1.900 i0.500
G2 z-2.000 i0.500
G2 z-2.100 i0.500
G2 z-2.200 i0.500
G2 z-2.300 i0.500
G2 z-2.400 i0.500
G2 z-2.500 i0.500
G2 z-2.600 i0.500
G2 z-2.700 i0.500
G2 z-2.800 i0.500
G2 z-2.800 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 5.19193)
(hole - helical interpolation)
(time: 5.19193)
(helical cut)
G0 x123.500y189.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.500
G2 z-0.200 i0.500
G2 z-0.300 i0.500
G2 z-0.400 i0.500
G2 z-0.500 i0.500
G2 z-0.600 i0.500
G2 z-0.700 i0.500
G2 z-0.800 i0.500
G2 z-0.900 i0.500
G2 z-1.000 i0.500
G2 z-1.100 i0.500
G2 z-1.200 i0.500
G2 z-1.300 i0.500
G2 z-1.400 i0.500
G2 z-1.500 i0.500
G2 z-1.600 i0.500
G2 z-1.700 i0.500
G2 z-1.800 i0.500
G2 z-1.900 i0.500
G2 z-2.000 i0.500
G2 z-2.100 i0.500
G2 z-2.200 i0.500
G2 z-2.300 i0.500
G2 z-2.400 i0.500
G2 z-2.500 i0.500
G2 z-2.600 i0.500
G2 z-2.700 i0.500
G2 z-2.800 i0.500
G2 z-2.800 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 5.53029)
(hole - helical interpolation)
(time: 5.53029)
(helical cut)
G0 x3.500y189.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.100 i0.500
G2 z-0.200 i0.500
G2 z-0.300 i0.500
G2 z-0.400 i0.500
G2 z-0.500 i0.500
G2 z-0.600 i0.500
G2 z-0.700 i0.500
G2 z-0.800 i0.500
G2 z-0.900 i0.500
G2 z-1.000 i0.500
G2 z-1.100 i0.500
G2 z-1.200 i0.500
G2 z-1.300 i0.500
G2 z-1.400 i0.500
G2 z-1.500 i0.500
G2 z-1.600 i0.500
G2 z-1.700 i0.500
G2 z-1.800 i0.500
G2 z-1.900 i0.500
G2 z-2.000 i0.500
G2 z-2.100 i0.500
G2 z-2.200 i0.500
G2 z-2.300 i0.500
G2 z-2.400 i0.500
G2 z-2.500 i0.500
G2 z-2.600 i0.500
G2 z-2.700 i0.500
G2 z-2.800 i0.500
G2 z-2.800 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 5.92881)
(dugó kivágások)
(line)
(time: 5.92881)
(linear cut)
G0 x0.000y147.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x23.000y147.700z-0.100
G1 x0.000y147.700z-0.200
G1 x23.000y147.700z-0.300
G1 x0.000y147.700z-0.400
G1 x23.000y147.700z-0.500
G1 x0.000y147.700z-0.600
G1 x23.000y147.700z-0.700
G1 x0.000y147.700z-0.800
G1 x23.000y147.700z-0.900
G1 x0.000y147.700z-1.000
G1 x23.000y147.700z-1.100
G1 x0.000y147.700z-1.200
G1 x23.000y147.700z-1.300
G1 x0.000y147.700z-1.400
G1 x23.000y147.700z-1.500
G1 x0.000y147.700z-1.600
G1 x23.000y147.700z-1.700
G1 x0.000y147.700z-1.800
G1 x23.000y147.700z-1.900
G1 x0.000y147.700z-2.000
G1 x23.000y147.700z-2.100
G1 x0.000y147.700z-2.100
G0 z2.000 (lift up)
(linear cut)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x9.500y147.700z-2.200
G04 P100
G1 x0.000y147.700z-2.300
G04 P100
G1 x9.500y147.700z-2.400
G04 P100
G1 x0.000y147.700z-2.500
G04 P100
G1 x9.500y147.700z-2.600
G04 P100
G1 x0.000y147.700z-2.700
G04 P100
G1 x9.500y147.700z-2.800
G04 P100
G1 x0.000y147.700z-2.800
G04 P100
G0 z2.000 (lift up)
(linear cut)
G0 x13.500y147.700 (travel)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x23.000y147.700z-2.200
G04 P100
G1 x13.500y147.700z-2.300
G04 P100
G1 x23.000y147.700z-2.400
G04 P100
G1 x13.500y147.700z-2.500
G04 P100
G1 x23.000y147.700z-2.600
G04 P100
G1 x13.500y147.700z-2.700
G04 P100
G1 x23.000y147.700z-2.800
G04 P100
G1 x13.500y147.700z-2.800
G04 P100
G0 z2.000 (lift up)
(time: 8.18318)
(line)
(time: 8.18318)
(linear cut)
G0 x24.000y146.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x24.000y117.500z-0.100
G1 x24.000y146.700z-0.200
G1 x24.000y117.500z-0.300
G1 x24.000y146.700z-0.400
G1 x24.000y117.500z-0.500
G1 x24.000y146.700z-0.600
G1 x24.000y117.500z-0.700
G1 x24.000y146.700z-0.800
G1 x24.000y117.500z-0.900
G1 x24.000y146.700z-1.000
G1 x24.000y117.500z-1.100
G1 x24.000y146.700z-1.200
G1 x24.000y117.500z-1.300
G1 x24.000y146.700z-1.400
G1 x24.000y117.500z-1.500
G1 x24.000y146.700z-1.600
G1 x24.000y117.500z-1.700
G1 x24.000y146.700z-1.800
G1 x24.000y117.500z-1.900
G1 x24.000y146.700z-2.000
G1 x24.000y117.500z-2.100
G1 x24.000y146.700z-2.100
G0 z2.000 (lift up)
(linear cut)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x24.000y134.100z-2.200
G1 x24.000y146.700z-2.300
G1 x24.000y134.100z-2.400
G1 x24.000y146.700z-2.500
G1 x24.000y134.100z-2.600
G1 x24.000y146.700z-2.700
G1 x24.000y134.100z-2.800
G1 x24.000y146.700z-2.800
G0 z2.000 (lift up)
(linear cut)
G0 x24.000y130.100 (travel)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x24.000y117.500z-2.200
G1 x24.000y130.100z-2.300
G1 x24.000y117.500z-2.400
G1 x24.000y130.100z-2.500
G1 x24.000y117.500z-2.600
G1 x24.000y130.100z-2.700
G1 x24.000y117.500z-2.800
G1 x24.000y130.100z-2.800
G0 z2.000 (lift up)
(time: 11.039)
(line)
(time: 11.039)
(linear cut)
G0 x24.000y117.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x36.000y117.500z-0.100
G1 x24.000y117.500z-0.200
G1 x36.000y117.500z-0.300
G1 x24.000y117.500z-0.400
G1 x36.000y117.500z-0.500
G1 x24.000y117.500z-0.600
G1 x36.000y117.500z-0.700
G1 x24.000y117.500z-0.800
G1 x36.000y117.500z-0.900
G1 x24.000y117.500z-1.000
G1 x36.000y117.500z-1.100
G1 x24.000y117.500z-1.200
G1 x36.000y117.500z-1.300
G1 x24.000y117.500z-1.400
G1 x36.000y117.500z-1.500
G1 x24.000y117.500z-1.600
G1 x36.000y117.500z-1.700
G1 x24.000y117.500z-1.800
G1 x36.000y117.500z-1.900
G1 x24.000y117.500z-2.000
G1 x36.000y117.500z-2.100
G1 x24.000y117.500z-2.200
G1 x36.000y117.500z-2.300
G1 x24.000y117.500z-2.400
G1 x36.000y117.500z-2.500
G1 x24.000y117.500z-2.600
G1 x36.000y117.500z-2.700
G1 x24.000y117.500z-2.800
G1 x36.000y117.500z-2.800
G0 z2.000 (lift up)
(time: 12.2148)
(line)
(time: 12.2148)
(linear cut)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x36.000y84.000z-0.100
G1 x36.000y117.500z-0.200
G1 x36.000y84.000z-0.300
G1 x36.000y117.500z-0.400
G1 x36.000y84.000z-0.500
G1 x36.000y117.500z-0.600
G1 x36.000y84.000z-0.700
G1 x36.000y117.500z-0.800
G1 x36.000y84.000z-0.900
G1 x36.000y117.500z-1.000
G1 x36.000y84.000z-1.100
G1 x36.000y117.500z-1.200
G1 x36.000y84.000z-1.300
G1 x36.000y117.500z-1.400
G1 x36.000y84.000z-1.500
G1 x36.000y117.500z-1.600
G1 x36.000y84.000z-1.700
G1 x36.000y117.500z-1.800
G1 x36.000y84.000z-1.900
G1 x36.000y117.500z-2.000
G1 x36.000y84.000z-2.100
G1 x36.000y117.500z-2.100
G0 z2.000 (lift up)
(linear cut)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x36.000y102.750z-2.200
G1 x36.000y117.500z-2.300
G1 x36.000y102.750z-2.400
G1 x36.000y117.500z-2.500
G1 x36.000y102.750z-2.600
G1 x36.000y117.500z-2.700
G1 x36.000y102.750z-2.800
G1 x36.000y117.500z-2.800
G0 z2.000 (lift up)
(linear cut)
G0 x36.000y98.750 (travel)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x36.000y84.000z-2.200
G1 x36.000y98.750z-2.300
G1 x36.000y84.000z-2.400
G1 x36.000y98.750z-2.500
G1 x36.000y84.000z-2.600
G1 x36.000y98.750z-2.700
G1 x36.000y84.000z-2.800
G1 x36.000y98.750z-2.800
G0 z2.000 (lift up)
(time: 15.4949)
(line)
(time: 15.4949)
(linear cut)
G0 x35.000y83.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x0.000y83.000z-0.100
G1 x35.000y83.000z-0.200
G1 x0.000y83.000z-0.300
G1 x35.000y83.000z-0.400
G1 x0.000y83.000z-0.500
G1 x35.000y83.000z-0.600
G1 x0.000y83.000z-0.700
G1 x35.000y83.000z-0.800
G1 x0.000y83.000z-0.900
G1 x35.000y83.000z-1.000
G1 x0.000y83.000z-1.100
G1 x35.000y83.000z-1.200
G1 x0.000y83.000z-1.300
G1 x35.000y83.000z-1.400
G1 x0.000y83.000z-1.500
G1 x35.000y83.000z-1.600
G1 x0.000y83.000z-1.700
G1 x35.000y83.000z-1.800
G1 x0.000y83.000z-1.900
G1 x35.000y83.000z-2.000
G1 x0.000y83.000z-2.100
G1 x35.000y83.000z-2.100
G0 z2.000 (lift up)
(linear cut)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x19.500y83.000z-2.200
G1 x35.000y83.000z-2.300
G1 x19.500y83.000z-2.400
G1 x35.000y83.000z-2.500
G1 x19.500y83.000z-2.600
G1 x35.000y83.000z-2.700
G1 x19.500y83.000z-2.800
G1 x35.000y83.000z-2.800
G0 z2.000 (lift up)
(linear cut)
G0 x15.500y83.000 (travel)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x0.000y83.000z-2.200
G1 x15.500y83.000z-2.300
G1 x0.000y83.000z-2.400
G1 x15.500y83.000z-2.500
G1 x0.000y83.000z-2.600
G1 x15.500y83.000z-2.700
G1 x0.000y83.000z-2.800
G1 x15.500y83.000z-2.800
G0 z2.000 (lift up)
(time: 18.9361)
(line)
(time: 18.9361)
(linear cut)
G0 x1.000y82.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x1.000y80.000z-0.100
G04 P100
G1 x1.000y82.000z-0.200
G04 P100
G1 x1.000y80.000z-0.300
G04 P100
G1 x1.000y82.000z-0.400
G04 P100
G1 x1.000y80.000z-0.500
G04 P100
G1 x1.000y82.000z-0.600
G04 P100
G1 x1.000y80.000z-0.700
G04 P100
G1 x1.000y82.000z-0.800
G04 P100
G1 x1.000y80.000z-0.900
G04 P100
G1 x1.000y82.000z-1.000
G04 P100
G1 x1.000y80.000z-1.100
G04 P100
G1 x1.000y82.000z-1.200
G04 P100
G1 x1.000y80.000z-1.300
G04 P100
G1 x1.000y82.000z-1.400
G04 P100
G1 x1.000y80.000z-1.500
G04 P100
G1 x1.000y82.000z-1.600
G04 P100
G1 x1.000y80.000z-1.700
G04 P100
G1 x1.000y82.000z-1.800
G04 P100
G1 x1.000y80.000z-1.900
G04 P100
G1 x1.000y82.000z-2.000
G04 P100
G1 x1.000y80.000z-2.100
G04 P100
G1 x1.000y82.000z-2.200
G04 P100
G1 x1.000y80.000z-2.300
G04 P100
G1 x1.000y82.000z-2.400
G04 P100
G1 x1.000y80.000z-2.500
G04 P100
G1 x1.000y82.000z-2.600
G04 P100
G1 x1.000y80.000z-2.700
G04 P100
G1 x1.000y82.000z-2.800
G04 P100
G1 x1.000y80.000z-2.800
G04 P100
G0 z2.000 (lift up)
(time: 19.1466)
(usb hub furatai)
(körvonal)
(box)
(time: 19.1466)
(line)
(time: 19.1466)
(linear cut)
G0 x0.000y-1.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x152.000y-1.000z-0.100
G1 x0.000y-1.000z-0.200
G1 x152.000y-1.000z-0.300
G1 x0.000y-1.000z-0.400
G1 x152.000y-1.000z-0.500
G1 x0.000y-1.000z-0.600
G1 x152.000y-1.000z-0.700
G1 x0.000y-1.000z-0.800
G1 x152.000y-1.000z-0.900
G1 x0.000y-1.000z-1.000
G1 x152.000y-1.000z-1.100
G1 x0.000y-1.000z-1.200
G1 x152.000y-1.000z-1.300
G1 x0.000y-1.000z-1.400
G1 x152.000y-1.000z-1.500
G1 x0.000y-1.000z-1.600
G1 x152.000y-1.000z-1.700
G1 x0.000y-1.000z-1.800
G1 x152.000y-1.000z-1.900
G1 x0.000y-1.000z-2.000
G1 x152.000y-1.000z-2.100
G1 x0.000y-1.000z-2.100
G0 z2.000 (lift up)
(time: 30.354)
(line)
(time: 30.354)
(linear cut)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x36.000y-1.000z-2.200
G1 x0.000y-1.000z-2.300
G1 x36.000y-1.000z-2.400
G1 x0.000y-1.000z-2.500
G1 x36.000y-1.000z-2.600
G1 x0.000y-1.000z-2.700
G1 x36.000y-1.000z-2.800
G1 x0.000y-1.000z-2.800
G0 z2.000 (lift up)
(time: 31.3226)
(line)
(time: 31.3226)
(linear cut)
G0 x40.000y-1.000 (travel)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x74.000y-1.000z-2.200
G1 x40.000y-1.000z-2.300
G1 x74.000y-1.000z-2.400
G1 x40.000y-1.000z-2.500
G1 x74.000y-1.000z-2.600
G1 x40.000y-1.000z-2.700
G1 x74.000y-1.000z-2.800
G1 x40.000y-1.000z-2.800
G0 z2.000 (lift up)
(time: 32.2647)
(line)
(time: 32.2647)
(linear cut)
G0 x78.000y-1.000 (travel)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x112.000y-1.000z-2.200
G1 x78.000y-1.000z-2.300
G1 x112.000y-1.000z-2.400
G1 x78.000y-1.000z-2.500
G1 x112.000y-1.000z-2.600
G1 x78.000y-1.000z-2.700
G1 x112.000y-1.000z-2.800
G1 x78.000y-1.000z-2.800
G0 z2.000 (lift up)
(time: 33.2055)
(line)
(time: 33.2055)
(linear cut)
G0 x116.000y-1.000 (travel)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x152.000y-1.000z-2.200
G1 x116.000y-1.000z-2.300
G1 x152.000y-1.000z-2.400
G1 x116.000y-1.000z-2.500
G1 x152.000y-1.000z-2.600
G1 x116.000y-1.000z-2.700
G1 x152.000y-1.000z-2.800
G1 x116.000y-1.000z-2.800
G0 z2.000 (lift up)
(time: 34.1995)
(line)
(time: 34.1995)
(linear cut)
G0 x153.000y0.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x153.000y194.000z-0.100
G1 x153.000y0.000z-0.200
G1 x153.000y194.000z-0.300
G1 x153.000y0.000z-0.400
G1 x153.000y194.000z-0.500
G1 x153.000y0.000z-0.600
G1 x153.000y194.000z-0.700
G1 x153.000y0.000z-0.800
G1 x153.000y194.000z-0.900
G1 x153.000y0.000z-1.000
G1 x153.000y194.000z-1.100
G1 x153.000y0.000z-1.200
G1 x153.000y194.000z-1.300
G1 x153.000y0.000z-1.400
G1 x153.000y194.000z-1.500
G1 x153.000y0.000z-1.600
G1 x153.000y194.000z-1.700
G1 x153.000y0.000z-1.800
G1 x153.000y194.000z-1.900
G1 x153.000y0.000z-2.000
G1 x153.000y194.000z-2.100
G1 x153.000y0.000z-2.100
G0 z2.000 (lift up)
(time: 48.4576)
(line)
(time: 48.4576)
(linear cut)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x153.000y46.500z-2.200
G1 x153.000y0.000z-2.300
G1 x153.000y46.500z-2.400
G1 x153.000y0.000z-2.500
G1 x153.000y46.500z-2.600
G1 x153.000y0.000z-2.700
G1 x153.000y46.500z-2.800
G1 x153.000y0.000z-2.800
G0 z2.000 (lift up)
(time: 49.7063)
(line)
(time: 49.7063)
(linear cut)
G0 x153.000y50.500 (travel)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x153.000y95.000z-2.200
G1 x153.000y50.500z-2.300
G1 x153.000y95.000z-2.400
G1 x153.000y50.500z-2.500
G1 x153.000y95.000z-2.600
G1 x153.000y50.500z-2.700
G1 x153.000y95.000z-2.800
G1 x153.000y50.500z-2.800
G0 z2.000 (lift up)
(time: 50.9353)
(line)
(time: 50.9353)
(linear cut)
G0 x153.000y99.000 (travel)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x153.000y143.500z-2.200
G1 x153.000y99.000z-2.300
G1 x153.000y143.500z-2.400
G1 x153.000y99.000z-2.500
G1 x153.000y143.500z-2.600
G1 x153.000y99.000z-2.700
G1 x153.000y143.500z-2.800
G1 x153.000y99.000z-2.800
G0 z2.000 (lift up)
(time: 52.163)
(line)
(time: 52.163)
(linear cut)
G0 x153.000y147.500 (travel)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x153.000y194.000z-2.200
G1 x153.000y147.500z-2.300
G1 x153.000y194.000z-2.400
G1 x153.000y147.500z-2.500
G1 x153.000y194.000z-2.600
G1 x153.000y147.500z-2.700
G1 x153.000y194.000z-2.800
G1 x153.000y147.500z-2.800
G0 z2.000 (lift up)
(time: 53.4441)
(line)
(time: 53.4441)
(linear cut)
G0 x152.000y195.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x0.000y195.000z-0.100
G1 x152.000y195.000z-0.200
G1 x0.000y195.000z-0.300
G1 x152.000y195.000z-0.400
G1 x0.000y195.000z-0.500
G1 x152.000y195.000z-0.600
G1 x0.000y195.000z-0.700
G1 x152.000y195.000z-0.800
G1 x0.000y195.000z-0.900
G1 x152.000y195.000z-1.000
G1 x0.000y195.000z-1.100
G1 x152.000y195.000z-1.200
G1 x0.000y195.000z-1.300
G1 x152.000y195.000z-1.400
G1 x0.000y195.000z-1.500
G1 x152.000y195.000z-1.600
G1 x0.000y195.000z-1.700
G1 x152.000y195.000z-1.800
G1 x0.000y195.000z-1.900
G1 x152.000y195.000z-2.000
G1 x0.000y195.000z-2.100
G1 x152.000y195.000z-2.100
G0 z2.000 (lift up)
(time: 64.6292)
(line)
(time: 64.6292)
(linear cut)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x116.000y195.000z-2.200
G1 x152.000y195.000z-2.300
G1 x116.000y195.000z-2.400
G1 x152.000y195.000z-2.500
G1 x116.000y195.000z-2.600
G1 x152.000y195.000z-2.700
G1 x116.000y195.000z-2.800
G1 x152.000y195.000z-2.800
G0 z2.000 (lift up)
(time: 65.5978)
(line)
(time: 65.5978)
(linear cut)
G0 x112.000y195.000 (travel)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x78.000y195.000z-2.200
G1 x112.000y195.000z-2.300
G1 x78.000y195.000z-2.400
G1 x112.000y195.000z-2.500
G1 x78.000y195.000z-2.600
G1 x112.000y195.000z-2.700
G1 x78.000y195.000z-2.800
G1 x112.000y195.000z-2.800
G0 z2.000 (lift up)
(time: 66.5399)
(line)
(time: 66.5399)
(linear cut)
G0 x74.000y195.000 (travel)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x40.000y195.000z-2.200
G1 x74.000y195.000z-2.300
G1 x40.000y195.000z-2.400
G1 x74.000y195.000z-2.500
G1 x40.000y195.000z-2.600
G1 x74.000y195.000z-2.700
G1 x40.000y195.000z-2.800
G1 x74.000y195.000z-2.800
G0 z2.000 (lift up)
(time: 67.4806)
(line)
(time: 67.4806)
(linear cut)
G0 x36.000y195.000 (travel)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x0.000y195.000z-2.200
G1 x36.000y195.000z-2.300
G1 x0.000y195.000z-2.400
G1 x36.000y195.000z-2.500
G1 x0.000y195.000z-2.600
G1 x36.000y195.000z-2.700
G1 x0.000y195.000z-2.800
G1 x36.000y195.000z-2.800
G0 z2.000 (lift up)
(time: 68.4747)
(line)
(time: 68.4747)
(linear cut)
G0 x-1.000y194.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x-1.000y0.000z-0.100
G1 x-1.000y194.000z-0.200
G1 x-1.000y0.000z-0.300
G1 x-1.000y194.000z-0.400
G1 x-1.000y0.000z-0.500
G1 x-1.000y194.000z-0.600
G1 x-1.000y0.000z-0.700
G1 x-1.000y194.000z-0.800
G1 x-1.000y0.000z-0.900
G1 x-1.000y194.000z-1.000
G1 x-1.000y0.000z-1.100
G1 x-1.000y194.000z-1.200
G1 x-1.000y0.000z-1.300
G1 x-1.000y194.000z-1.400
G1 x-1.000y0.000z-1.500
G1 x-1.000y194.000z-1.600
G1 x-1.000y0.000z-1.700
G1 x-1.000y194.000z-1.800
G1 x-1.000y0.000z-1.900
G1 x-1.000y194.000z-2.000
G1 x-1.000y0.000z-2.100
G1 x-1.000y194.000z-2.100
G0 z2.000 (lift up)
(time: 82.7328)
(line)
(time: 82.7328)
(linear cut)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x-1.000y147.500z-2.200
G1 x-1.000y194.000z-2.300
G1 x-1.000y147.500z-2.400
G1 x-1.000y194.000z-2.500
G1 x-1.000y147.500z-2.600
G1 x-1.000y194.000z-2.700
G1 x-1.000y147.500z-2.800
G1 x-1.000y194.000z-2.800
G0 z2.000 (lift up)
(time: 83.9814)
(line)
(time: 83.9814)
(linear cut)
G0 x-1.000y143.500 (travel)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x-1.000y99.000z-2.200
G1 x-1.000y143.500z-2.300
G1 x-1.000y99.000z-2.400
G1 x-1.000y143.500z-2.500
G1 x-1.000y99.000z-2.600
G1 x-1.000y143.500z-2.700
G1 x-1.000y99.000z-2.800
G1 x-1.000y143.500z-2.800
G0 z2.000 (lift up)
(time: 85.2104)
(line)
(time: 85.2104)
(linear cut)
G0 x-1.000y95.000 (travel)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x-1.000y50.500z-2.200
G1 x-1.000y95.000z-2.300
G1 x-1.000y50.500z-2.400
G1 x-1.000y95.000z-2.500
G1 x-1.000y50.500z-2.600
G1 x-1.000y95.000z-2.700
G1 x-1.000y50.500z-2.800
G1 x-1.000y95.000z-2.800
G0 z2.000 (lift up)
(time: 86.4382)
(line)
(time: 86.4382)
(linear cut)
G0 x-1.000y46.500 (travel)
m3(spindle start)
G0 z-1.100 (lift down)
G1 z-2.100 (push)
G1 x-1.000y0.000z-2.200
G1 x-1.000y46.500z-2.300
G1 x-1.000y0.000z-2.400
G1 x-1.000y46.500z-2.500
G1 x-1.000y0.000z-2.600
G1 x-1.000y46.500z-2.700
G1 x-1.000y0.000z-2.800
G1 x-1.000y46.500z-2.800
G0 z2.000 (lift up)
(time: 87.7192)
(time: 87.7192)
G0 z2.000 (lift up)
G0 x0.000y0.000 (travel)
(travel to safe place)

M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)
M30
(end)
