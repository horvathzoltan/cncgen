(GCode generated by cncgen - https://github.com/horvathzoltan/cncgen)
(type: GCode from geometry)
(input file: pi_alatet_8db_15.txt)
(output file: pi_alatet_8db_15_plot.gcode)
(created on: K júl. 11 21:15:03 2023)
(total time: 00:09:54.000)
(total cut: 2901.36mm)
(total length: 3259.97mm)
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
(raspberry pi alátét 24 db)
(cmd line: -i pi_alatet_8db_15.txt -t)
(plot cmd: -i pi_alatet_8db_15.txt -t -p)
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
f300.000 (set feed)

(mélység)
(belső átmérő)
(külső átmérő)
(dk: 8.8)
(h 4,4 d7.5 z1.2 c0.175 g0,0,0 np)
(h 4,4 d5 z1.2 c0.175 g0,0,0 np)
(1.sor)
(hole - helical interpolation)
(time: 0.00133333)
(helical cut)
G0 x3.925y4.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.475
G2 z-0.020 i0.475
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.0307811)
(hole - helical interpolation)
(time: 0.0307811)
(helical cut)
G0 x0.750y4.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x0.905y3.348 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x6.981y6.981z-0.020 i3.495 j1.052
G3 x0.905y3.348z-0.020 i-2.581 j-2.581
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x7.895y5.452 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x1.819y1.819z-0.020 i-3.495 j-1.052
G3 x7.895y5.452z-0.020 i2.581 j2.581
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 0.29278)
(hole - helical interpolation)
(time: 0.29278)
(helical cut)
G0 x3.925y14.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.475
G2 z-0.020 i0.475
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.324619)
(hole - helical interpolation)
(time: 0.324619)
(helical cut)
G0 x0.750y14.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x1.798y11.640 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x5.480y17.686z-0.020 i2.602 j2.560
G3 x1.798y11.640z-0.020 i-1.080 j-3.486
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x7.002y16.760 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x3.320y10.714z-0.020 i-2.602 j-2.560
G3 x7.002y16.760z-0.020 i1.080 j3.486
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 0.788668)
(hole - helical interpolation)
(time: 0.788668)
(helical cut)
G0 x3.925y24.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.475
G2 z-0.020 i0.475
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.819377)
(hole - helical interpolation)
(time: 0.819377)
(helical cut)
G0 x0.750y24.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x2.121y21.149 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x5.058y27.590z-0.020 i2.279 j2.851
G3 x2.121y21.149z-0.020 i-0.658 j-3.590
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x6.679y26.851 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x3.742y20.410z-0.020 i-2.279 j-2.851
G3 x6.679y26.851z-0.020 i0.658 j3.590
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 1.57237)
(hole - helical interpolation)
(time: 1.57237)
(helical cut)
G0 x3.925y33.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.475
G2 z-0.020 i0.475
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.60282)
(hole - helical interpolation)
(time: 1.60282)
(helical cut)
G0 x0.750y33.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x2.272y30.835 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.871y37.419z-0.020 i2.128 j2.965
G3 x2.272y30.835z-0.020 i-0.471 j-3.619
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x6.528y36.765 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x3.929y30.181z-0.020 i-2.128 j-2.965
G3 x6.528y36.765z-0.020 i0.471 j3.619
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 2.64669)
(hole - helical interpolation)
(time: 2.64669)
(helical cut)
G0 x3.925y43.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.475
G2 z-0.020 i0.475
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 2.67705)
(hole - helical interpolation)
(time: 2.67705)
(helical cut)
G0 x0.750y43.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x2.358y40.575 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.766y47.232z-0.020 i2.042 j3.025
G3 x2.358y40.575z-0.020 i-0.366 j-3.632
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x6.442y46.625 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.034y39.968z-0.020 i-2.042 j-3.025
G3 x6.442y46.625z-0.020 i0.366 j3.632
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 4.01225)
(hole - helical interpolation)
(time: 4.01225)
(helical cut)
G0 x3.925y53.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.475
G2 z-0.020 i0.475
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 4.04255)
(hole - helical interpolation)
(time: 4.04255)
(helical cut)
G0 x0.750y53.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x2.414y50.338 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.700y57.038z-0.020 i1.986 j3.062
G3 x2.414y50.338z-0.020 i-0.300 j-3.638
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x6.386y56.462 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.100y49.762z-0.020 i-1.986 j-3.062
G3 x6.386y56.462z-0.020 i0.300 j3.638
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 5.66926)
(hole - helical interpolation)
(time: 5.66926)
(helical cut)
G0 x3.925y63.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.475
G2 z-0.020 i0.475
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 5.69952)
(hole - helical interpolation)
(time: 5.69952)
(helical cut)
G0 x0.750y63.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x2.453y60.113 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.654y66.841z-0.020 i1.947 j3.087
G3 x2.453y60.113z-0.020 i-0.254 j-3.641
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x6.347y66.287 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.146y59.559z-0.020 i-1.947 j-3.087
G3 x6.347y66.287z-0.020 i0.254 j3.641
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 7.61782)
(hole - helical interpolation)
(time: 7.61782)
(helical cut)
G0 x3.925y73.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.475
G2 z-0.020 i0.475
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 7.64806)
(hole - helical interpolation)
(time: 7.64806)
(helical cut)
G0 x0.750y73.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x2.482y69.895 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.620y76.643z-0.020 i1.918 j3.105
G3 x2.482y69.895z-0.020 i-0.220 j-3.643
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x6.318y76.105 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.180y69.357z-0.020 i-1.918 j-3.105
G3 x6.318y76.105z-0.020 i0.220 j3.643
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 9.858)
G0 z2.000 (lift up)
G0 x0.000y0.000 (travel)
(travel to safe place)

M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)
M30
(end)