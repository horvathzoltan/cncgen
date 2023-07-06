(GCode generated by cncgen - https://github.com/horvathzoltan/cncgen)
(type: GCode from geometry)
(input file: uniturn_relay_szerelolap.txt)
(output file: uniturn_relay_szerelolap.gcode)
(created on: H febr. 20 11:21:10 2023)
(total time: 03:40:06.000)
(total cut: 43637.7mm)
(total length: 46509.9mm)
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
(2mm polikarbonát lemez)
(xy0 a ja saroknál)
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

(pi, pizero felső furatok)
(pi3b furatok)
(box)
(time: 0.00133333)
(hole - helical interpolation)
(time: 0.00133333)
(helical cut)
G0 x89.000y120.000 (travel)
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
(time: 0.307789)
(hole - helical interpolation)
(time: 0.307789)
(helical cut)
G0 x138.000y120.000 (travel)
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
(time: 0.547328)
(hole - helical interpolation)
(time: 0.547328)
(helical cut)
G0 x138.000y178.000 (travel)
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
(time: 0.792863)
(hole - helical interpolation)
(time: 0.792863)
(helical cut)
G0 x89.000y178.000 (travel)
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
(time: 1.0324)
(time: 1.0324)
(pizero furatok)
(box)
(time: 1.0324)
(hole - helical interpolation)
(time: 1.0324)
(helical cut)
G0 x115.000y15.000 (travel)
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
(time: 1.3493)
(hole - helical interpolation)
(time: 1.3493)
(helical cut)
G0 x138.000y15.000 (travel)
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
(time: 1.57153)
(hole - helical interpolation)
(time: 1.57153)
(helical cut)
G0 x138.000y73.000 (travel)
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
(time: 1.81707)
(hole - helical interpolation)
(time: 1.81707)
(helical cut)
G0 x115.000y73.000 (travel)
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
(time: 2.0393)
(time: 2.0393)
(b3218101 - net-box 220, vers. i)
(rögzítő furatok)
(hole - helical interpolation)
(time: 2.0393)
(helical cut)
G0 x3.250y5.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.750
G2 z-0.400 i0.750
G2 z-0.600 i0.750
G2 z-0.800 i0.750
G2 z-1.000 i0.750
G2 z-1.200 i0.750
G2 z-1.400 i0.750
G2 z-1.600 i0.750
G2 z-1.800 i0.750
G2 z-2.000 i0.750
G2 z-2.200 i0.750
G2 z-2.200 i0.750
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 2.4275)
(hole - helical interpolation)
(time: 2.4275)
(helical cut)
G0 x123.250y5.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.750
G2 z-0.400 i0.750
G2 z-0.600 i0.750
G2 z-0.800 i0.750
G2 z-1.000 i0.750
G2 z-1.200 i0.750
G2 z-1.400 i0.750
G2 z-1.600 i0.750
G2 z-1.800 i0.750
G2 z-2.000 i0.750
G2 z-2.200 i0.750
G2 z-2.200 i0.750
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 2.80849)
(hole - helical interpolation)
(time: 2.80849)
(helical cut)
G0 x145.250y25.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.750
G2 z-0.400 i0.750
G2 z-0.600 i0.750
G2 z-0.800 i0.750
G2 z-1.000 i0.750
G2 z-1.200 i0.750
G2 z-1.400 i0.750
G2 z-1.600 i0.750
G2 z-1.800 i0.750
G2 z-2.000 i0.750
G2 z-2.200 i0.750
G2 z-2.200 i0.750
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 3.12933)
(hole - helical interpolation)
(time: 3.12933)
(helical cut)
G0 x145.250y169.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.750
G2 z-0.400 i0.750
G2 z-0.600 i0.750
G2 z-0.800 i0.750
G2 z-1.000 i0.750
G2 z-1.200 i0.750
G2 z-1.400 i0.750
G2 z-1.600 i0.750
G2 z-1.800 i0.750
G2 z-2.000 i0.750
G2 z-2.200 i0.750
G2 z-2.200 i0.750
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 3.52632)
(hole - helical interpolation)
(time: 3.52632)
(helical cut)
G0 x123.250y189.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.750
G2 z-0.400 i0.750
G2 z-0.600 i0.750
G2 z-0.800 i0.750
G2 z-1.000 i0.750
G2 z-1.200 i0.750
G2 z-1.400 i0.750
G2 z-1.600 i0.750
G2 z-1.800 i0.750
G2 z-2.000 i0.750
G2 z-2.200 i0.750
G2 z-2.200 i0.750
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 3.84716)
(hole - helical interpolation)
(time: 3.84716)
(helical cut)
G0 x3.250y189.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.750
G2 z-0.400 i0.750
G2 z-0.600 i0.750
G2 z-0.800 i0.750
G2 z-1.000 i0.750
G2 z-1.200 i0.750
G2 z-1.400 i0.750
G2 z-1.600 i0.750
G2 z-1.800 i0.750
G2 z-2.000 i0.750
G2 z-2.200 i0.750
G2 z-2.200 i0.750
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 4.22815)
(dugó kivágások)
(box)
(time: 4.22815)
(line)
(time: 4.22815)
(linear cut)
G0 x2.500y72.750 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x12.500y72.750z-0.200
G1 x2.500y72.750z-0.400
G1 x12.500y72.750z-0.600
G1 x2.500y72.750z-0.800
G1 x12.500y72.750z-1.000
G1 x2.500y72.750z-1.200
G1 x12.500y72.750z-1.400
G1 x2.500y72.750z-1.600
G1 x12.500y72.750z-1.800
G1 x2.500y72.750z-2.000
G1 x12.500y72.750z-2.200
G1 x2.500y72.750z-2.200
G04 P100
G0 z2.000 (lift up)
(time: 4.91424)
(line)
(time: 4.91424)
(linear cut)
G0 x14.250y74.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x14.250y163.500z-0.200
G1 x14.250y74.500z-0.400
G1 x14.250y163.500z-0.600
G1 x14.250y74.500z-0.800
G1 x14.250y163.500z-1.000
G1 x14.250y74.500z-1.200
G1 x14.250y163.500z-1.400
G1 x14.250y74.500z-1.600
G1 x14.250y163.500z-1.800
G1 x14.250y74.500z-2.000
G1 x14.250y163.500z-2.200
G1 x14.250y74.500z-2.200
G0 z2.000 (lift up)
(time: 10.2707)
(line)
(time: 10.2707)
(linear cut)
G0 x12.500y165.250 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x2.500y165.250z-0.200
G1 x12.500y165.250z-0.400
G1 x2.500y165.250z-0.600
G1 x12.500y165.250z-0.800
G1 x2.500y165.250z-1.000
G1 x12.500y165.250z-1.200
G1 x2.500y165.250z-1.400
G1 x12.500y165.250z-1.600
G1 x2.500y165.250z-1.800
G1 x12.500y165.250z-2.000
G1 x2.500y165.250z-2.200
G1 x12.500y165.250z-2.200
G04 P100
G0 z2.000 (lift up)
(time: 10.9398)
(arc)
(time: 10.9398)
(circular_arc cut)
G0 x14.250y74.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x12.500y72.750z-0.200 i-1.750 j0.000
G3 x14.250y74.500z-0.400 i0.000 j1.750
G2 x12.500y72.750z-0.600 i-1.750 j0.000
G3 x14.250y74.500z-0.800 i0.000 j1.750
G2 x12.500y72.750z-1.000 i-1.750 j0.000
G3 x14.250y74.500z-1.200 i0.000 j1.750
G2 x12.500y72.750z-1.400 i-1.750 j0.000
G3 x14.250y74.500z-1.600 i0.000 j1.750
G2 x12.500y72.750z-1.800 i-1.750 j0.000
G3 x14.250y74.500z-2.000 i0.000 j1.750
G2 x12.500y72.750z-2.200 i-1.750 j0.000
G3 x14.250y74.500z-2.200 i0.000 j1.750
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 18.9276)
(arc)
(time: 18.9276)
(circular_arc cut)
G0 x12.500y165.250 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x14.250y163.500z-0.200 i0.000 j-1.750
G3 x12.500y165.250z-0.400 i-1.750 j0.000
G2 x14.250y163.500z-0.600 i0.000 j-1.750
G3 x12.500y165.250z-0.800 i-1.750 j0.000
G2 x14.250y163.500z-1.000 i0.000 j-1.750
G3 x12.500y165.250z-1.200 i-1.750 j0.000
G2 x14.250y163.500z-1.400 i0.000 j-1.750
G3 x12.500y165.250z-1.600 i-1.750 j0.000
G2 x14.250y163.500z-1.800 i0.000 j-1.750
G3 x12.500y165.250z-2.000 i-1.750 j0.000
G2 x14.250y163.500z-2.200 i0.000 j-1.750
G3 x12.500y165.250z-2.200 i-1.750 j0.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 51.5287)
(arc)
(time: 51.5287)
(circular_arc cut)
G0 x2.500y165.250 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x0.750y167.000z-0.200 i0.000 j1.750
G3 x2.500y165.250z-0.400 i1.750 j0.000
G2 x0.750y167.000z-0.600 i0.000 j1.750
G3 x2.500y165.250z-0.800 i1.750 j0.000
G2 x0.750y167.000z-1.000 i0.000 j1.750
G3 x2.500y165.250z-1.200 i1.750 j0.000
G2 x0.750y167.000z-1.400 i0.000 j1.750
G3 x2.500y165.250z-1.600 i1.750 j0.000
G2 x0.750y167.000z-1.800 i0.000 j1.750
G3 x2.500y165.250z-2.000 i1.750 j0.000
G2 x0.750y167.000z-2.200 i0.000 j1.750
G3 x2.500y165.250z-2.200 i1.750 j0.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 89.9743)
(arc)
(time: 89.9743)
(circular_arc cut)
G0 x0.750y71.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x2.500y72.750z-0.200 i1.750 j0.000
G3 x0.750y71.000z-0.400 i0.000 j-1.750
G2 x2.500y72.750z-0.600 i1.750 j0.000
G3 x0.750y71.000z-0.800 i0.000 j-1.750
G2 x2.500y72.750z-1.000 i1.750 j0.000
G3 x0.750y71.000z-1.200 i0.000 j-1.750
G2 x2.500y72.750z-1.400 i1.750 j0.000
G3 x0.750y71.000z-1.600 i0.000 j-1.750
G2 x2.500y72.750z-1.800 i1.750 j0.000
G3 x0.750y71.000z-2.000 i0.000 j-1.750
G2 x2.500y72.750z-2.200 i1.750 j0.000
G3 x0.750y71.000z-2.200 i0.000 j-1.750
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 100.053)
(time: 100.053)
(trafó furatok)
(hole - helical interpolation)
(time: 100.053)
(helical cut)
G0 x53.200y17.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.800
G2 z-0.400 i0.800
G2 z-0.600 i0.800
G2 z-0.800 i0.800
G2 z-1.000 i0.800
G2 z-1.200 i0.800
G2 z-1.400 i0.800
G2 z-1.600 i0.800
G2 z-1.800 i0.800
G2 z-2.000 i0.800
G2 z-2.200 i0.800
G2 z-2.200 i0.800
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 100.423)
(hole - helical interpolation)
(time: 100.423)
(helical cut)
G0 x53.200y72.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.800
G2 z-0.400 i0.800
G2 z-0.600 i0.800
G2 z-0.800 i0.800
G2 z-1.000 i0.800
G2 z-1.200 i0.800
G2 z-1.400 i0.800
G2 z-1.600 i0.800
G2 z-1.800 i0.800
G2 z-2.000 i0.800
G2 z-2.200 i0.800
G2 z-2.200 i0.800
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 100.779)
(körvonal)
(box)
(time: 100.779)
(line)
(time: 100.779)
(linear cut)
G0 x4.250y-0.750 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x147.750y-0.750z-0.200
G1 x4.250y-0.750z-0.400
G1 x147.750y-0.750z-0.600
G1 x4.250y-0.750z-0.800
G1 x147.750y-0.750z-1.000
G1 x4.250y-0.750z-1.200
G1 x147.750y-0.750z-1.400
G1 x4.250y-0.750z-1.600
G1 x147.750y-0.750z-1.800
G1 x4.250y-0.750z-1.800
G0 z2.000 (lift up)
(time: 108.021)
(line)
(time: 108.021)
(linear cut)
m3(spindle start)
G0 z-0.800 (lift down)
G1 z-1.800 (push)
G1 x38.375y-0.750z-2.000
G1 x4.250y-0.750z-2.200
G1 x38.375y-0.750z-2.400
G1 x4.250y-0.750z-2.500
G1 x38.375y-0.750z-2.500
G0 z2.000 (lift up)
(time: 108.884)
(line)
(time: 108.884)
(linear cut)
G0 x41.875y-0.750 (travel)
m3(spindle start)
G0 z-0.800 (lift down)
G1 z-1.800 (push)
G1 x74.250y-0.750z-2.000
G1 x41.875y-0.750z-2.200
G1 x74.250y-0.750z-2.400
G1 x41.875y-0.750z-2.500
G1 x74.250y-0.750z-2.500
G0 z2.000 (lift up)
(time: 109.706)
(line)
(time: 109.706)
(linear cut)
G0 x77.750y-0.750 (travel)
m3(spindle start)
G0 z-0.800 (lift down)
G1 z-1.800 (push)
G1 x110.125y-0.750z-2.000
G1 x77.750y-0.750z-2.200
G1 x110.125y-0.750z-2.400
G1 x77.750y-0.750z-2.500
G1 x110.125y-0.750z-2.500
G0 z2.000 (lift up)
(time: 110.529)
(line)
(time: 110.529)
(linear cut)
G0 x113.625y-0.750 (travel)
m3(spindle start)
G0 z-0.800 (lift down)
G1 z-1.800 (push)
G1 x147.750y-0.750z-2.000
G1 x113.625y-0.750z-2.200
G1 x147.750y-0.750z-2.400
G1 x113.625y-0.750z-2.500
G1 x147.750y-0.750z-2.500
G0 z2.000 (lift up)
(time: 111.396)
(line)
(time: 111.396)
(linear cut)
G0 x152.750y4.250 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x152.750y189.750z-0.200
G1 x152.750y4.250z-0.400
G1 x152.750y189.750z-0.600
G1 x152.750y4.250z-0.800
G1 x152.750y189.750z-1.000
G1 x152.750y4.250z-1.200
G1 x152.750y189.750z-1.400
G1 x152.750y4.250z-1.600
G1 x152.750y189.750z-1.800
G1 x152.750y4.250z-1.800
G0 z2.000 (lift up)
(time: 120.684)
(line)
(time: 120.684)
(linear cut)
m3(spindle start)
G0 z-0.800 (lift down)
G1 z-1.800 (push)
G1 x152.750y48.875z-2.000
G1 x152.750y4.250z-2.200
G1 x152.750y48.875z-2.400
G1 x152.750y4.250z-2.500
G1 x152.750y48.875z-2.500
G0 z2.000 (lift up)
(time: 121.809)
(line)
(time: 121.809)
(linear cut)
G0 x152.750y52.375 (travel)
m3(spindle start)
G0 z-0.800 (lift down)
G1 z-1.800 (push)
G1 x152.750y95.250z-2.000
G1 x152.750y52.375z-2.200
G1 x152.750y95.250z-2.400
G1 x152.750y52.375z-2.500
G1 x152.750y95.250z-2.500
G0 z2.000 (lift up)
(time: 122.894)
(line)
(time: 122.894)
(linear cut)
G0 x152.750y98.750 (travel)
m3(spindle start)
G0 z-0.800 (lift down)
G1 z-1.800 (push)
G1 x152.750y141.625z-2.000
G1 x152.750y98.750z-2.200
G1 x152.750y141.625z-2.400
G1 x152.750y98.750z-2.500
G1 x152.750y141.625z-2.500
G0 z2.000 (lift up)
(time: 123.98)
(line)
(time: 123.98)
(linear cut)
G0 x152.750y145.125 (travel)
m3(spindle start)
G0 z-0.800 (lift down)
G1 z-1.800 (push)
G1 x152.750y189.750z-2.000
G1 x152.750y145.125z-2.200
G1 x152.750y189.750z-2.400
G1 x152.750y145.125z-2.500
G1 x152.750y189.750z-2.500
G0 z2.000 (lift up)
(time: 125.109)
(line)
(time: 125.109)
(linear cut)
G0 x147.750y194.750 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x4.250y194.750z-0.200
G1 x147.750y194.750z-0.400
G1 x4.250y194.750z-0.600
G1 x147.750y194.750z-0.800
G1 x4.250y194.750z-1.000
G1 x147.750y194.750z-1.200
G1 x4.250y194.750z-1.400
G1 x147.750y194.750z-1.600
G1 x4.250y194.750z-1.800
G1 x147.750y194.750z-1.800
G0 z2.000 (lift up)
(time: 132.297)
(line)
(time: 132.297)
(linear cut)
m3(spindle start)
G0 z-0.800 (lift down)
G1 z-1.800 (push)
G1 x113.625y194.750z-2.000
G1 x147.750y194.750z-2.200
G1 x113.625y194.750z-2.400
G1 x147.750y194.750z-2.500
G1 x113.625y194.750z-2.500
G0 z2.000 (lift up)
(time: 133.16)
(line)
(time: 133.16)
(linear cut)
G0 x110.125y194.750 (travel)
m3(spindle start)
G0 z-0.800 (lift down)
G1 z-1.800 (push)
G1 x77.750y194.750z-2.000
G1 x110.125y194.750z-2.200
G1 x77.750y194.750z-2.400
G1 x110.125y194.750z-2.500
G1 x77.750y194.750z-2.500
G0 z2.000 (lift up)
(time: 133.982)
(line)
(time: 133.982)
(linear cut)
G0 x74.250y194.750 (travel)
m3(spindle start)
G0 z-0.800 (lift down)
G1 z-1.800 (push)
G1 x41.875y194.750z-2.000
G1 x74.250y194.750z-2.200
G1 x41.875y194.750z-2.400
G1 x74.250y194.750z-2.500
G1 x41.875y194.750z-2.500
G0 z2.000 (lift up)
(time: 134.805)
(line)
(time: 134.805)
(linear cut)
G0 x38.375y194.750 (travel)
m3(spindle start)
G0 z-0.800 (lift down)
G1 z-1.800 (push)
G1 x4.250y194.750z-2.000
G1 x38.375y194.750z-2.200
G1 x4.250y194.750z-2.400
G1 x38.375y194.750z-2.500
G1 x4.250y194.750z-2.500
G0 z2.000 (lift up)
(time: 135.672)
(line)
(time: 135.672)
(linear cut)
G0 x-0.750y189.750 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x-0.750y4.250z-0.200
G1 x-0.750y189.750z-0.400
G1 x-0.750y4.250z-0.600
G1 x-0.750y189.750z-0.800
G1 x-0.750y4.250z-1.000
G1 x-0.750y189.750z-1.200
G1 x-0.750y4.250z-1.400
G1 x-0.750y189.750z-1.600
G1 x-0.750y4.250z-1.800
G1 x-0.750y189.750z-1.800
G0 z2.000 (lift up)
(time: 144.96)
(line)
(time: 144.96)
(linear cut)
m3(spindle start)
G0 z-0.800 (lift down)
G1 z-1.800 (push)
G1 x-0.750y145.125z-2.000
G1 x-0.750y189.750z-2.200
G1 x-0.750y145.125z-2.400
G1 x-0.750y189.750z-2.500
G1 x-0.750y145.125z-2.500
G0 z2.000 (lift up)
(time: 146.085)
(line)
(time: 146.085)
(linear cut)
G0 x-0.750y141.625 (travel)
m3(spindle start)
G0 z-0.800 (lift down)
G1 z-1.800 (push)
G1 x-0.750y98.750z-2.000
G1 x-0.750y141.625z-2.200
G1 x-0.750y98.750z-2.400
G1 x-0.750y141.625z-2.500
G1 x-0.750y98.750z-2.500
G0 z2.000 (lift up)
(time: 147.17)
(line)
(time: 147.17)
(linear cut)
G0 x-0.750y95.250 (travel)
m3(spindle start)
G0 z-0.800 (lift down)
G1 z-1.800 (push)
G1 x-0.750y52.375z-2.000
G1 x-0.750y95.250z-2.200
G1 x-0.750y52.375z-2.400
G1 x-0.750y95.250z-2.500
G1 x-0.750y52.375z-2.500
G0 z2.000 (lift up)
(time: 148.255)
(line)
(time: 148.255)
(linear cut)
G0 x-0.750y48.875 (travel)
m3(spindle start)
G0 z-0.800 (lift down)
G1 z-1.800 (push)
G1 x-0.750y4.250z-2.000
G1 x-0.750y48.875z-2.200
G1 x-0.750y4.250z-2.400
G1 x-0.750y48.875z-2.500
G1 x-0.750y4.250z-2.500
G0 z2.000 (lift up)
(time: 149.384)
(arc)
(time: 149.384)
(circular_arc cut)
G0 x152.750y4.250 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x147.750y-0.750z-0.200 i-5.000 j0.000
G3 x152.750y4.250z-0.400 i0.000 j5.000
G2 x147.750y-0.750z-0.600 i-5.000 j0.000
G3 x152.750y4.250z-0.800 i0.000 j5.000
G2 x147.750y-0.750z-1.000 i-5.000 j0.000
G3 x152.750y4.250z-1.200 i0.000 j5.000
G2 x147.750y-0.750z-1.400 i-5.000 j0.000
G3 x152.750y4.250z-1.600 i0.000 j5.000
G2 x147.750y-0.750z-1.800 i-5.000 j0.000
G3 x152.750y4.250z-2.000 i0.000 j5.000
G2 x147.750y-0.750z-2.200 i-5.000 j0.000
G3 x152.750y4.250z-2.400 i0.000 j5.000
G2 x147.750y-0.750z-2.500 i-5.000 j0.000
G3 x152.750y4.250z-2.500 i0.000 j5.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 175.597)
(arc)
(time: 175.597)
(circular_arc cut)
G0 x147.750y194.750 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x152.750y189.750z-0.200 i0.000 j-5.000
G3 x147.750y194.750z-0.400 i-5.000 j0.000
G2 x152.750y189.750z-0.600 i0.000 j-5.000
G3 x147.750y194.750z-0.800 i-5.000 j0.000
G2 x152.750y189.750z-1.000 i0.000 j-5.000
G3 x147.750y194.750z-1.200 i-5.000 j0.000
G2 x152.750y189.750z-1.400 i0.000 j-5.000
G3 x147.750y194.750z-1.600 i-5.000 j0.000
G2 x152.750y189.750z-1.800 i0.000 j-5.000
G3 x147.750y194.750z-2.000 i-5.000 j0.000
G2 x152.750y189.750z-2.200 i0.000 j-5.000
G3 x147.750y194.750z-2.400 i-5.000 j0.000
G2 x152.750y189.750z-2.500 i0.000 j-5.000
G3 x147.750y194.750z-2.500 i-5.000 j0.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 186.831)
(arc)
(time: 186.831)
(circular_arc cut)
G0 x-0.750y189.750 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x4.250y194.750z-0.200 i5.000 j0.000
G3 x-0.750y189.750z-0.400 i0.000 j-5.000
G2 x4.250y194.750z-0.600 i5.000 j0.000
G3 x-0.750y189.750z-0.800 i0.000 j-5.000
G2 x4.250y194.750z-1.000 i5.000 j0.000
G3 x-0.750y189.750z-1.200 i0.000 j-5.000
G2 x4.250y194.750z-1.400 i5.000 j0.000
G3 x-0.750y189.750z-1.600 i0.000 j-5.000
G2 x4.250y194.750z-1.800 i5.000 j0.000
G3 x-0.750y189.750z-2.000 i0.000 j-5.000
G2 x4.250y194.750z-2.200 i5.000 j0.000
G3 x-0.750y189.750z-2.400 i0.000 j-5.000
G2 x4.250y194.750z-2.500 i5.000 j0.000
G3 x-0.750y189.750z-2.500 i0.000 j-5.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 218.406)
(arc)
(time: 218.406)
(circular_arc cut)
G0 x4.250y-0.750 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x-0.750y4.250z-0.200 i0.000 j5.000
G3 x4.250y-0.750z-0.400 i5.000 j0.000
G2 x-0.750y4.250z-0.600 i0.000 j5.000
G3 x4.250y-0.750z-0.800 i5.000 j0.000
G2 x-0.750y4.250z-1.000 i0.000 j5.000
G3 x4.250y-0.750z-1.200 i5.000 j0.000
G2 x-0.750y4.250z-1.400 i0.000 j5.000
G3 x4.250y-0.750z-1.600 i5.000 j0.000
G2 x-0.750y4.250z-1.800 i0.000 j5.000
G3 x4.250y-0.750z-2.000 i5.000 j0.000
G2 x-0.750y4.250z-2.200 i0.000 j5.000
G3 x4.250y-0.750z-2.400 i5.000 j0.000
G2 x-0.750y4.250z-2.500 i0.000 j5.000
G3 x4.250y-0.750z-2.500 i5.000 j0.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 220.099)
(time: 220.099)
G0 z2.000 (lift up)
G0 x0.000y0.000 (travel)
(travel to safe place)

M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)
M30
(end)