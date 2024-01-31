(GCode generated by cncgen - https://github.com/horvathzoltan/cncgen)
(type: GCode from geometry)
(input file: hammond_doboz_tap2.txt)
(output file: hammond_doboz_tap2.gcode)
(created on: Sze jan. 31 10:17:27 2024)
(total time: 00:31:21.000)
(total cut: 19458.8mm)
(total length: 19736mm)
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
(uniturn mérőállomás táp szerelőlap)
(cmd line: -i hammond_doboz_tap2.txt -t)
(plot cmd: -i hammond_doboz_tap2.txt -t -p)
(szerszám beállítás)
(set tool 1 to t1 m  d2.000 h19.000)
(set tool 2 to t2 m  d3.000 h19.000)
(set mode to YXZ)
(change tool)
m5 (spindle stop)
G0 z2.000 (lift up)
g0 z4.000
t1 (tool select)
m6 (tool change)
(msg, change tool to Milling, diameter=2.000)
m0 (machine stop)
g0 z4.000
(fúrás fogásmélység egy menetben)
(vágás fogásmélység egy menetben)
(anyagvastagság)
(gap méretek)
(körvonal)
(box)
(time[min]: 0.00133333)
(line: border 1 ba1,ja1)
(time[min]: 0.00133333)
(linear cut)
G0 x1.200y0.200 (travel)
m3 s50.000 (set spindle speed, spindle start)
f700.000 (set feed)
G0 z1.400 (lift down)
G1 z0.200 (push)
G1 x107.800y0.200z0.050
G1 x1.200y0.200z-0.100
G1 x107.800y0.200z-0.250
G1 x1.200y0.200z-0.400
G1 x107.800y0.200z-0.550
G1 x1.200y0.200z-0.700
G1 x107.800y0.200z-0.850
G1 x1.200y0.200z-1.000
G1 x107.800y0.200z-1.150
G1 x1.200y0.200z-1.300
G1 x107.800y0.200z-1.450
G1 x1.200y0.200z-1.500
G1 x107.800y0.200z-1.500
G0 z2.000 (lift up)
(time[min]: 1.9855)
(line: gap 1 ba1,ja1 slice:1)
(time[min]: 1.9855)
(linear cut)
G0 x1.200y0.200 (travel)
G0 z-0.300 (lift down)
G1 z-1.500 (push)
G1 x35.583y0.200z-1.650
G4 P500
G1 x1.200y0.200z-1.800
G4 P500
G1 x35.583y0.200z-1.950
G4 P500
G1 x1.200y0.200z-2.100
G4 P500
G1 x35.583y0.200z-2.250
G4 P500
G1 x1.200y0.200z-2.400
G4 P500
G1 x35.583y0.200z-2.550
G4 P500
G1 x1.200y0.200z-2.700
G4 P500
G1 x35.583y0.200z-2.850
G4 P500
G1 x1.200y0.200z-3.000
G4 P500
G1 x35.583y0.200z-3.100
G4 P500
G1 x1.200y0.200z-3.100
G4 P500
G0 z2.000 (lift up)
(time[min]: 2.68158)
(line: gap 1 ba1,ja1 slice:2)
(time[min]: 2.68158)
(linear cut)
G0 x37.883y0.200 (travel)
G0 z-0.300 (lift down)
G1 z-1.500 (push)
G1 x71.117y0.200z-1.650
G4 P500
G1 x37.883y0.200z-1.800
G4 P500
G1 x71.117y0.200z-1.950
G4 P500
G1 x37.883y0.200z-2.100
G4 P500
G1 x71.117y0.200z-2.250
G4 P500
G1 x37.883y0.200z-2.400
G4 P500
G1 x71.117y0.200z-2.550
G4 P500
G1 x37.883y0.200z-2.700
G4 P500
G1 x71.117y0.200z-2.850
G4 P500
G1 x37.883y0.200z-3.000
G4 P500
G1 x71.117y0.200z-3.100
G4 P500
G1 x37.883y0.200z-3.100
G4 P500
G0 z2.000 (lift up)
(time[min]: 3.35794)
(line: gap 1 ba1,ja1 slice:last)
(time[min]: 3.35794)
(linear cut)
G0 x73.417y0.200 (travel)
G0 z-0.300 (lift down)
G1 z-1.500 (push)
G1 x107.800y0.200z-1.650
G4 P500
G1 x73.417y0.200z-1.800
G4 P500
G1 x107.800y0.200z-1.950
G4 P500
G1 x73.417y0.200z-2.100
G4 P500
G1 x107.800y0.200z-2.250
G4 P500
G1 x73.417y0.200z-2.400
G4 P500
G1 x107.800y0.200z-2.550
G4 P500
G1 x73.417y0.200z-2.700
G4 P500
G1 x107.800y0.200z-2.850
G4 P500
G1 x73.417y0.200z-3.000
G4 P500
G1 x107.800y0.200z-3.100
G4 P500
G1 x73.417y0.200z-3.100
G4 P500
G0 z2.000 (lift up)
(time[min]: 4.05403)
(line: border 2 ja2,jf2)
(time[min]: 4.05403)
(linear cut)
G0 x108.800y1.200 (travel)
G0 z1.400 (lift down)
G1 z0.200 (push)
G1 x108.800y157.800z0.050
G1 x108.800y1.200z-0.100
G1 x108.800y157.800z-0.250
G1 x108.800y1.200z-0.400
G1 x108.800y157.800z-0.550
G1 x108.800y1.200z-0.700
G1 x108.800y157.800z-0.850
G1 x108.800y1.200z-1.000
G1 x108.800y157.800z-1.150
G1 x108.800y1.200z-1.300
G1 x108.800y157.800z-1.450
G1 x108.800y1.200z-1.500
G1 x108.800y157.800z-1.500
G0 z2.000 (lift up)
(time[min]: 6.96676)
(line: gap 2 ja2,jf2 slice:1)
(time[min]: 6.96676)
(linear cut)
G0 x108.800y1.200 (travel)
G0 z-0.300 (lift down)
G1 z-1.500 (push)
G1 x108.800y52.250z-1.650
G4 P500
G1 x108.800y1.200z-1.800
G4 P500
G1 x108.800y52.250z-1.950
G4 P500
G1 x108.800y1.200z-2.100
G4 P500
G1 x108.800y52.250z-2.250
G4 P500
G1 x108.800y1.200z-2.400
G4 P500
G1 x108.800y52.250z-2.550
G4 P500
G1 x108.800y1.200z-2.700
G4 P500
G1 x108.800y52.250z-2.850
G4 P500
G1 x108.800y1.200z-3.000
G4 P500
G1 x108.800y52.250z-3.100
G4 P500
G1 x108.800y1.200z-3.100
G4 P500
G0 z2.000 (lift up)
(time[min]: 7.94855)
(line: gap 2 ja2,jf2 slice:2)
(time[min]: 7.94855)
(linear cut)
G0 x108.800y54.550 (travel)
G0 z-0.300 (lift down)
G1 z-1.500 (push)
G1 x108.800y104.450z-1.650
G4 P500
G1 x108.800y54.550z-1.800
G4 P500
G1 x108.800y104.450z-1.950
G4 P500
G1 x108.800y54.550z-2.100
G4 P500
G1 x108.800y104.450z-2.250
G4 P500
G1 x108.800y54.550z-2.400
G4 P500
G1 x108.800y104.450z-2.550
G4 P500
G1 x108.800y54.550z-2.700
G4 P500
G1 x108.800y104.450z-2.850
G4 P500
G1 x108.800y54.550z-3.000
G4 P500
G1 x108.800y104.450z-3.100
G4 P500
G1 x108.800y54.550z-3.100
G4 P500
G0 z2.000 (lift up)
(time[min]: 8.91063)
(line: gap 2 ja2,jf2 slice:last)
(time[min]: 8.91063)
(linear cut)
G0 x108.800y106.750 (travel)
G0 z-0.300 (lift down)
G1 z-1.500 (push)
G1 x108.800y157.800z-1.650
G4 P500
G1 x108.800y106.750z-1.800
G4 P500
G1 x108.800y157.800z-1.950
G4 P500
G1 x108.800y106.750z-2.100
G4 P500
G1 x108.800y157.800z-2.250
G4 P500
G1 x108.800y106.750z-2.400
G4 P500
G1 x108.800y157.800z-2.550
G4 P500
G1 x108.800y106.750z-2.700
G4 P500
G1 x108.800y157.800z-2.850
G4 P500
G1 x108.800y106.750z-3.000
G4 P500
G1 x108.800y157.800z-3.100
G4 P500
G1 x108.800y106.750z-3.100
G4 P500
G0 z2.000 (lift up)
(time[min]: 9.89243)
(line: border 3 jf3,bf3)
(time[min]: 9.89243)
(linear cut)
G0 x107.800y158.800 (travel)
G0 z1.400 (lift down)
G1 z0.200 (push)
G1 x1.200y158.800z0.050
G1 x107.800y158.800z-0.100
G1 x1.200y158.800z-0.250
G1 x107.800y158.800z-0.400
G1 x1.200y158.800z-0.550
G1 x107.800y158.800z-0.700
G1 x1.200y158.800z-0.850
G1 x107.800y158.800z-1.000
G1 x1.200y158.800z-1.150
G1 x107.800y158.800z-1.300
G1 x1.200y158.800z-1.450
G1 x107.800y158.800z-1.500
G1 x1.200y158.800z-1.500
G0 z2.000 (lift up)
(time[min]: 11.8766)
(line: gap 3 jf3,bf3 slice:1)
(time[min]: 11.8766)
(linear cut)
G0 x107.800y158.800 (travel)
G0 z-0.300 (lift down)
G1 z-1.500 (push)
G1 x73.417y158.800z-1.650
G4 P500
G1 x107.800y158.800z-1.800
G4 P500
G1 x73.417y158.800z-1.950
G4 P500
G1 x107.800y158.800z-2.100
G4 P500
G1 x73.417y158.800z-2.250
G4 P500
G1 x107.800y158.800z-2.400
G4 P500
G1 x73.417y158.800z-2.550
G4 P500
G1 x107.800y158.800z-2.700
G4 P500
G1 x73.417y158.800z-2.850
G4 P500
G1 x107.800y158.800z-3.000
G4 P500
G1 x73.417y158.800z-3.100
G4 P500
G1 x107.800y158.800z-3.100
G4 P500
G0 z2.000 (lift up)
(time[min]: 12.5727)
(line: gap 3 jf3,bf3 slice:2)
(time[min]: 12.5727)
(linear cut)
G0 x71.117y158.800 (travel)
G0 z-0.300 (lift down)
G1 z-1.500 (push)
G1 x37.883y158.800z-1.650
G4 P500
G1 x71.117y158.800z-1.800
G4 P500
G1 x37.883y158.800z-1.950
G4 P500
G1 x71.117y158.800z-2.100
G4 P500
G1 x37.883y158.800z-2.250
G4 P500
G1 x71.117y158.800z-2.400
G4 P500
G1 x37.883y158.800z-2.550
G4 P500
G1 x71.117y158.800z-2.700
G4 P500
G1 x37.883y158.800z-2.850
G4 P500
G1 x71.117y158.800z-3.000
G4 P500
G1 x37.883y158.800z-3.100
G4 P500
G1 x71.117y158.800z-3.100
G4 P500
G0 z2.000 (lift up)
(time[min]: 13.249)
(line: gap 3 jf3,bf3 slice:last)
(time[min]: 13.249)
(linear cut)
G0 x35.583y158.800 (travel)
G0 z-0.300 (lift down)
G1 z-1.500 (push)
G1 x1.200y158.800z-1.650
G4 P500
G1 x35.583y158.800z-1.800
G4 P500
G1 x1.200y158.800z-1.950
G4 P500
G1 x35.583y158.800z-2.100
G4 P500
G1 x1.200y158.800z-2.250
G4 P500
G1 x35.583y158.800z-2.400
G4 P500
G1 x1.200y158.800z-2.550
G4 P500
G1 x35.583y158.800z-2.700
G4 P500
G1 x1.200y158.800z-2.850
G4 P500
G1 x35.583y158.800z-3.000
G4 P500
G1 x1.200y158.800z-3.100
G4 P500
G1 x35.583y158.800z-3.100
G4 P500
G0 z2.000 (lift up)
(time[min]: 13.9451)
(line: border 4 bf4,ba4)
(time[min]: 13.9451)
(linear cut)
G0 x0.200y157.800 (travel)
G0 z1.400 (lift down)
G1 z0.200 (push)
G1 x0.200y1.200z0.050
G1 x0.200y157.800z-0.100
G1 x0.200y1.200z-0.250
G1 x0.200y157.800z-0.400
G1 x0.200y1.200z-0.550
G1 x0.200y157.800z-0.700
G1 x0.200y1.200z-0.850
G1 x0.200y157.800z-1.000
G1 x0.200y1.200z-1.150
G1 x0.200y157.800z-1.300
G1 x0.200y1.200z-1.450
G1 x0.200y157.800z-1.500
G1 x0.200y1.200z-1.500
G0 z2.000 (lift up)
(time[min]: 16.8579)
(line: gap 4 bf4,ba4 slice:1)
(time[min]: 16.8579)
(linear cut)
G0 x0.200y157.800 (travel)
G0 z-0.300 (lift down)
G1 z-1.500 (push)
G1 x0.200y106.750z-1.650
G4 P500
G1 x0.200y157.800z-1.800
G4 P500
G1 x0.200y106.750z-1.950
G4 P500
G1 x0.200y157.800z-2.100
G4 P500
G1 x0.200y106.750z-2.250
G4 P500
G1 x0.200y157.800z-2.400
G4 P500
G1 x0.200y106.750z-2.550
G4 P500
G1 x0.200y157.800z-2.700
G4 P500
G1 x0.200y106.750z-2.850
G4 P500
G1 x0.200y157.800z-3.000
G4 P500
G1 x0.200y106.750z-3.100
G4 P500
G1 x0.200y157.800z-3.100
G4 P500
G0 z2.000 (lift up)
(time[min]: 17.8396)
(line: gap 4 bf4,ba4 slice:2)
(time[min]: 17.8396)
(linear cut)
G0 x0.200y104.450 (travel)
G0 z-0.300 (lift down)
G1 z-1.500 (push)
G1 x0.200y54.550z-1.650
G4 P500
G1 x0.200y104.450z-1.800
G4 P500
G1 x0.200y54.550z-1.950
G4 P500
G1 x0.200y104.450z-2.100
G4 P500
G1 x0.200y54.550z-2.250
G4 P500
G1 x0.200y104.450z-2.400
G4 P500
G1 x0.200y54.550z-2.550
G4 P500
G1 x0.200y104.450z-2.700
G4 P500
G1 x0.200y54.550z-2.850
G4 P500
G1 x0.200y104.450z-3.000
G4 P500
G1 x0.200y54.550z-3.100
G4 P500
G1 x0.200y104.450z-3.100
G4 P500
G0 z2.000 (lift up)
(time[min]: 18.8017)
(line: gap 4 bf4,ba4 slice:last)
(time[min]: 18.8017)
(linear cut)
G0 x0.200y52.250 (travel)
G0 z-0.300 (lift down)
G1 z-1.500 (push)
G1 x0.200y1.200z-1.650
G4 P500
G1 x0.200y52.250z-1.800
G4 P500
G1 x0.200y1.200z-1.950
G4 P500
G1 x0.200y52.250z-2.100
G4 P500
G1 x0.200y1.200z-2.250
G4 P500
G1 x0.200y52.250z-2.400
G4 P500
G1 x0.200y1.200z-2.550
G4 P500
G1 x0.200y52.250z-2.700
G4 P500
G1 x0.200y1.200z-2.850
G4 P500
G1 x0.200y52.250z-3.000
G4 P500
G1 x0.200y1.200z-3.100
G4 P500
G1 x0.200y52.250z-3.100
G4 P500
G0 z2.000 (lift up)
(time[min]: 19.7835)
(time[min]: 19.7835)
(bekarcolás)
(box)
(time[min]: 19.7835)
(hole::1_ba)
(helical interpolation)
(time[min]: 19.7835)
(helical cut)
G0 x-6.250y-1.000 (travel)
G0 z1.400 (lift down)
G1 z0.200 (push)
G2 z0.050 i5.250
G2 z-0.100 i5.250
G2 z-0.250 i5.250
G2 z-0.400 i5.250
G2 z-0.550 i5.250
G2 z-0.700 i5.250
G2 z-0.850 i5.250
G2 z-1.000 i5.250
G2 z-1.150 i5.250
G2 z-1.300 i5.250
G2 z-1.450 i5.250
G2 z-1.600 i5.250
G2 z-1.750 i5.250
G2 z-1.900 i5.250
G2 z-2.050 i5.250
G2 z-2.200 i5.250
G2 z-2.350 i5.250
G2 z-2.500 i5.250
G2 z-2.600 i5.250
G2 z-2.600 i5.250
G1 z0.200 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
(compensate cut: 0.15 -> 0.0643173)
(compensate feed: 700 -> 720)
G0 x-5.666y1.407 (travel)
f720.000 (set feed)
G0 z-1.400 (lift down)
G1 z-2.600 (push)
(peck)
G2 x4.250y-1.000z-2.664 i4.666 j-2.407
G0 z-1.400
G4 P489
G1 z-2.664
G3 x-5.666y1.407z-2.729 i-5.250 j-0.000
G0 z-1.400
G4 P478
G1 z-2.729
G2 x4.250y-1.000z-2.793 i4.666 j-2.407
G0 z-1.400
G4 P468
G1 z-2.793
G3 x-5.666y1.407z-2.857 i-5.250 j-0.000
G0 z-1.400
G4 P457
G1 z-2.857
G2 x4.250y-1.000z-2.922 i4.666 j-2.407
G0 z-1.400
G4 P446
G1 z-2.922
G3 x-5.666y1.407z-2.986 i-5.250 j-0.000
G0 z-1.400
G4 P436
G1 z-2.986
G2 x4.250y-1.000z-3.050 i4.666 j-2.407
G0 z-1.400
G4 P425
G1 z-3.050
G3 x-5.666y1.407z-3.100 i-5.250 j-0.000
G0 z-1.400
G4 P417
G1 z-3.100
G2 x4.250y-1.000z-3.100 i4.666 j-2.407
G0 z-1.400
G4 P417
G1 z-3.100
G1 z-2.600 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
(compensate cut: 0.15 -> 0.0643173)
(compensate feed: 700 -> 720)
G0 x3.666y-3.407 (travel)
G0 z-1.400 (lift down)
G1 z-2.600 (push)
(peck)
G2 x-6.250y-1.000z-2.664 i-4.666 j2.407
G0 z-1.400
G4 P489
G1 z-2.664
G3 x3.666y-3.407z-2.729 i5.250 j0.000
G0 z-1.400
G4 P478
G1 z-2.729
G2 x-6.250y-1.000z-2.793 i-4.666 j2.407
G0 z-1.400
G4 P468
G1 z-2.793
G3 x3.666y-3.407z-2.857 i5.250 j0.000
G0 z-1.400
G4 P457
G1 z-2.857
G2 x-6.250y-1.000z-2.922 i-4.666 j2.407
G0 z-1.400
G4 P446
G1 z-2.922
G3 x3.666y-3.407z-2.986 i5.250 j0.000
G0 z-1.400
G4 P436
G1 z-2.986
G2 x-6.250y-1.000z-3.050 i-4.666 j2.407
G0 z-1.400
G4 P425
G1 z-3.050
G3 x3.666y-3.407z-3.100 i5.250 j0.000
G0 z-1.400
G4 P417
G1 z-3.100
G2 x-6.250y-1.000z-3.100 i-4.666 j2.407
G0 z-1.400
G4 P417
G1 z-3.100
G1 z-2.600 (pull)
G0 z2.000 (lift up)
(time[min]: 21.1623)
(hole::2_ja)
(helical interpolation)
(time[min]: 21.1623)
(helical cut)
G0 x104.750y-1.000 (travel)
f700.000 (set feed)
G0 z1.400 (lift down)
G1 z0.200 (push)
G2 z0.050 i5.250
G2 z-0.100 i5.250
G2 z-0.250 i5.250
G2 z-0.400 i5.250
G2 z-0.550 i5.250
G2 z-0.700 i5.250
G2 z-0.850 i5.250
G2 z-1.000 i5.250
G2 z-1.150 i5.250
G2 z-1.300 i5.250
G2 z-1.450 i5.250
G2 z-1.600 i5.250
G2 z-1.750 i5.250
G2 z-1.900 i5.250
G2 z-2.050 i5.250
G2 z-2.200 i5.250
G2 z-2.350 i5.250
G2 z-2.500 i5.250
G2 z-2.600 i5.250
G2 z-2.600 i5.250
G1 z0.200 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
(compensate cut: 0.15 -> 0.0643173)
(compensate feed: 700 -> 720)
G0 x105.334y1.407 (travel)
f720.000 (set feed)
G0 z-1.400 (lift down)
G1 z-2.600 (push)
(peck)
G2 x115.250y-1.000z-2.664 i4.666 j-2.407
G0 z-1.400
G4 P489
G1 z-2.664
G3 x105.334y1.407z-2.729 i-5.250 j-0.000
G0 z-1.400
G4 P478
G1 z-2.729
G2 x115.250y-1.000z-2.793 i4.666 j-2.407
G0 z-1.400
G4 P468
G1 z-2.793
G3 x105.334y1.407z-2.857 i-5.250 j-0.000
G0 z-1.400
G4 P457
G1 z-2.857
G2 x115.250y-1.000z-2.922 i4.666 j-2.407
G0 z-1.400
G4 P446
G1 z-2.922
G3 x105.334y1.407z-2.986 i-5.250 j-0.000
G0 z-1.400
G4 P436
G1 z-2.986
G2 x115.250y-1.000z-3.050 i4.666 j-2.407
G0 z-1.400
G4 P425
G1 z-3.050
G3 x105.334y1.407z-3.100 i-5.250 j-0.000
G0 z-1.400
G4 P417
G1 z-3.100
G2 x115.250y-1.000z-3.100 i4.666 j-2.407
G0 z-1.400
G4 P417
G1 z-3.100
G1 z-2.600 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
(compensate cut: 0.15 -> 0.0643173)
(compensate feed: 700 -> 720)
G0 x114.666y-3.407 (travel)
G0 z-1.400 (lift down)
G1 z-2.600 (push)
(peck)
G2 x104.750y-1.000z-2.664 i-4.666 j2.407
G0 z-1.400
G4 P489
G1 z-2.664
G3 x114.666y-3.407z-2.729 i5.250 j0.000
G0 z-1.400
G4 P478
G1 z-2.729
G2 x104.750y-1.000z-2.793 i-4.666 j2.407
G0 z-1.400
G4 P468
G1 z-2.793
G3 x114.666y-3.407z-2.857 i5.250 j0.000
G0 z-1.400
G4 P457
G1 z-2.857
G2 x104.750y-1.000z-2.922 i-4.666 j2.407
G0 z-1.400
G4 P446
G1 z-2.922
G3 x114.666y-3.407z-2.986 i5.250 j0.000
G0 z-1.400
G4 P436
G1 z-2.986
G2 x104.750y-1.000z-3.050 i-4.666 j2.407
G0 z-1.400
G4 P425
G1 z-3.050
G3 x114.666y-3.407z-3.100 i5.250 j0.000
G0 z-1.400
G4 P417
G1 z-3.100
G2 x104.750y-1.000z-3.100 i-4.666 j2.407
G0 z-1.400
G4 P417
G1 z-3.100
G1 z-2.600 (pull)
G0 z2.000 (lift up)
(time[min]: 22.5412)
(hole::3_jf)
(helical interpolation)
(time[min]: 22.5412)
(helical cut)
G0 x104.750y160.000 (travel)
f700.000 (set feed)
G0 z1.400 (lift down)
G1 z0.200 (push)
G2 z0.050 i5.250
G2 z-0.100 i5.250
G2 z-0.250 i5.250
G2 z-0.400 i5.250
G2 z-0.550 i5.250
G2 z-0.700 i5.250
G2 z-0.850 i5.250
G2 z-1.000 i5.250
G2 z-1.150 i5.250
G2 z-1.300 i5.250
G2 z-1.450 i5.250
G2 z-1.600 i5.250
G2 z-1.750 i5.250
G2 z-1.900 i5.250
G2 z-2.050 i5.250
G2 z-2.200 i5.250
G2 z-2.350 i5.250
G2 z-2.500 i5.250
G2 z-2.600 i5.250
G2 z-2.600 i5.250
G1 z0.200 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
(compensate cut: 0.15 -> 0.0643173)
(compensate feed: 700 -> 720)
G0 x105.334y162.407 (travel)
f720.000 (set feed)
G0 z-1.400 (lift down)
G1 z-2.600 (push)
(peck)
G2 x115.250y160.000z-2.664 i4.666 j-2.407
G0 z-1.400
G4 P489
G1 z-2.664
G3 x105.334y162.407z-2.729 i-5.250 j0.000
G0 z-1.400
G4 P478
G1 z-2.729
G2 x115.250y160.000z-2.793 i4.666 j-2.407
G0 z-1.400
G4 P468
G1 z-2.793
G3 x105.334y162.407z-2.857 i-5.250 j0.000
G0 z-1.400
G4 P457
G1 z-2.857
G2 x115.250y160.000z-2.922 i4.666 j-2.407
G0 z-1.400
G4 P446
G1 z-2.922
G3 x105.334y162.407z-2.986 i-5.250 j0.000
G0 z-1.400
G4 P436
G1 z-2.986
G2 x115.250y160.000z-3.050 i4.666 j-2.407
G0 z-1.400
G4 P425
G1 z-3.050
G3 x105.334y162.407z-3.100 i-5.250 j0.000
G0 z-1.400
G4 P417
G1 z-3.100
G2 x115.250y160.000z-3.100 i4.666 j-2.407
G0 z-1.400
G4 P417
G1 z-3.100
G1 z-2.600 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
(compensate cut: 0.15 -> 0.0643173)
(compensate feed: 700 -> 720)
G0 x114.666y157.593 (travel)
G0 z-1.400 (lift down)
G1 z-2.600 (push)
(peck)
G2 x104.750y160.000z-2.664 i-4.666 j2.407
G0 z-1.400
G4 P489
G1 z-2.664
G3 x114.666y157.593z-2.729 i5.250 j0.000
G0 z-1.400
G4 P478
G1 z-2.729
G2 x104.750y160.000z-2.793 i-4.666 j2.407
G0 z-1.400
G4 P468
G1 z-2.793
G3 x114.666y157.593z-2.857 i5.250 j0.000
G0 z-1.400
G4 P457
G1 z-2.857
G2 x104.750y160.000z-2.922 i-4.666 j2.407
G0 z-1.400
G4 P446
G1 z-2.922
G3 x114.666y157.593z-2.986 i5.250 j0.000
G0 z-1.400
G4 P436
G1 z-2.986
G2 x104.750y160.000z-3.050 i-4.666 j2.407
G0 z-1.400
G4 P425
G1 z-3.050
G3 x114.666y157.593z-3.100 i5.250 j0.000
G0 z-1.400
G4 P417
G1 z-3.100
G2 x104.750y160.000z-3.100 i-4.666 j2.407
G0 z-1.400
G4 P417
G1 z-3.100
G1 z-2.600 (pull)
G0 z2.000 (lift up)
(time[min]: 23.92)
(hole::4_bf)
(helical interpolation)
(time[min]: 23.92)
(helical cut)
G0 x-6.250y160.000 (travel)
f700.000 (set feed)
G0 z1.400 (lift down)
G1 z0.200 (push)
G2 z0.050 i5.250
G2 z-0.100 i5.250
G2 z-0.250 i5.250
G2 z-0.400 i5.250
G2 z-0.550 i5.250
G2 z-0.700 i5.250
G2 z-0.850 i5.250
G2 z-1.000 i5.250
G2 z-1.150 i5.250
G2 z-1.300 i5.250
G2 z-1.450 i5.250
G2 z-1.600 i5.250
G2 z-1.750 i5.250
G2 z-1.900 i5.250
G2 z-2.050 i5.250
G2 z-2.200 i5.250
G2 z-2.350 i5.250
G2 z-2.500 i5.250
G2 z-2.600 i5.250
G2 z-2.600 i5.250
G1 z0.200 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
(compensate cut: 0.15 -> 0.0643173)
(compensate feed: 700 -> 720)
G0 x-5.666y162.407 (travel)
f720.000 (set feed)
G0 z-1.400 (lift down)
G1 z-2.600 (push)
(peck)
G2 x4.250y160.000z-2.664 i4.666 j-2.407
G0 z-1.400
G4 P489
G1 z-2.664
G3 x-5.666y162.407z-2.729 i-5.250 j0.000
G0 z-1.400
G4 P478
G1 z-2.729
G2 x4.250y160.000z-2.793 i4.666 j-2.407
G0 z-1.400
G4 P468
G1 z-2.793
G3 x-5.666y162.407z-2.857 i-5.250 j0.000
G0 z-1.400
G4 P457
G1 z-2.857
G2 x4.250y160.000z-2.922 i4.666 j-2.407
G0 z-1.400
G4 P446
G1 z-2.922
G3 x-5.666y162.407z-2.986 i-5.250 j0.000
G0 z-1.400
G4 P436
G1 z-2.986
G2 x4.250y160.000z-3.050 i4.666 j-2.407
G0 z-1.400
G4 P425
G1 z-3.050
G3 x-5.666y162.407z-3.100 i-5.250 j0.000
G0 z-1.400
G4 P417
G1 z-3.100
G2 x4.250y160.000z-3.100 i4.666 j-2.407
G0 z-1.400
G4 P417
G1 z-3.100
G1 z-2.600 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
(compensate cut: 0.15 -> 0.0643173)
(compensate feed: 700 -> 720)
G0 x3.666y157.593 (travel)
G0 z-1.400 (lift down)
G1 z-2.600 (push)
(peck)
G2 x-6.250y160.000z-2.664 i-4.666 j2.407
G0 z-1.400
G4 P489
G1 z-2.664
G3 x3.666y157.593z-2.729 i5.250 j0.000
G0 z-1.400
G4 P478
G1 z-2.729
G2 x-6.250y160.000z-2.793 i-4.666 j2.407
G0 z-1.400
G4 P468
G1 z-2.793
G3 x3.666y157.593z-2.857 i5.250 j0.000
G0 z-1.400
G4 P457
G1 z-2.857
G2 x-6.250y160.000z-2.922 i-4.666 j2.407
G0 z-1.400
G4 P446
G1 z-2.922
G3 x3.666y157.593z-2.986 i5.250 j0.000
G0 z-1.400
G4 P436
G1 z-2.986
G2 x-6.250y160.000z-3.050 i-4.666 j2.407
G0 z-1.400
G4 P425
G1 z-3.050
G3 x3.666y157.593z-3.100 i5.250 j0.000
G0 z-1.400
G4 P417
G1 z-3.100
G2 x-6.250y160.000z-3.100 i-4.666 j2.407
G0 z-1.400
G4 P417
G1 z-3.100
G1 z-2.600 (pull)
G0 z2.000 (lift up)
(time[min]: 25.2988)
(time[min]: 25.2988)
(hole)
(helical interpolation)
(time[min]: 25.2988)
(helical cut)
G0 x-6.250y79.500 (travel)
f700.000 (set feed)
G0 z1.400 (lift down)
G1 z0.200 (push)
G2 z0.050 i5.250
G2 z-0.100 i5.250
G2 z-0.250 i5.250
G2 z-0.400 i5.250
G2 z-0.550 i5.250
G2 z-0.700 i5.250
G2 z-0.850 i5.250
G2 z-1.000 i5.250
G2 z-1.150 i5.250
G2 z-1.300 i5.250
G2 z-1.450 i5.250
G2 z-1.600 i5.250
G2 z-1.750 i5.250
G2 z-1.900 i5.250
G2 z-2.050 i5.250
G2 z-2.200 i5.250
G2 z-2.350 i5.250
G2 z-2.500 i5.250
G2 z-2.600 i5.250
G2 z-2.600 i5.250
G1 z0.200 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
(compensate cut: 0.15 -> 0.0643173)
(compensate feed: 700 -> 720)
G0 x-5.666y81.907 (travel)
f720.000 (set feed)
G0 z-1.400 (lift down)
G1 z-2.600 (push)
(peck)
G2 x4.250y79.500z-2.664 i4.666 j-2.407
G0 z-1.400
G4 P489
G1 z-2.664
G3 x-5.666y81.907z-2.729 i-5.250 j0.000
G0 z-1.400
G4 P478
G1 z-2.729
G2 x4.250y79.500z-2.793 i4.666 j-2.407
G0 z-1.400
G4 P468
G1 z-2.793
G3 x-5.666y81.907z-2.857 i-5.250 j0.000
G0 z-1.400
G4 P457
G1 z-2.857
G2 x4.250y79.500z-2.922 i4.666 j-2.407
G0 z-1.400
G4 P446
G1 z-2.922
G3 x-5.666y81.907z-2.986 i-5.250 j0.000
G0 z-1.400
G4 P436
G1 z-2.986
G2 x4.250y79.500z-3.050 i4.666 j-2.407
G0 z-1.400
G4 P425
G1 z-3.050
G3 x-5.666y81.907z-3.100 i-5.250 j0.000
G0 z-1.400
G4 P417
G1 z-3.100
G2 x4.250y79.500z-3.100 i4.666 j-2.407
G0 z-1.400
G4 P417
G1 z-3.100
G1 z-2.600 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
(compensate cut: 0.15 -> 0.0643173)
(compensate feed: 700 -> 720)
G0 x3.666y77.093 (travel)
G0 z-1.400 (lift down)
G1 z-2.600 (push)
(peck)
G2 x-6.250y79.500z-2.664 i-4.666 j2.407
G0 z-1.400
G4 P489
G1 z-2.664
G3 x3.666y77.093z-2.729 i5.250 j0.000
G0 z-1.400
G4 P478
G1 z-2.729
G2 x-6.250y79.500z-2.793 i-4.666 j2.407
G0 z-1.400
G4 P468
G1 z-2.793
G3 x3.666y77.093z-2.857 i5.250 j0.000
G0 z-1.400
G4 P457
G1 z-2.857
G2 x-6.250y79.500z-2.922 i-4.666 j2.407
G0 z-1.400
G4 P446
G1 z-2.922
G3 x3.666y77.093z-2.986 i5.250 j0.000
G0 z-1.400
G4 P436
G1 z-2.986
G2 x-6.250y79.500z-3.050 i-4.666 j2.407
G0 z-1.400
G4 P425
G1 z-3.050
G3 x3.666y77.093z-3.100 i5.250 j0.000
G0 z-1.400
G4 P417
G1 z-3.100
G2 x-6.250y79.500z-3.100 i-4.666 j2.407
G0 z-1.400
G4 P417
G1 z-3.100
G1 z-2.600 (pull)
G0 z2.000 (lift up)
(time[min]: 26.6776)
(hole)
(helical interpolation)
(time[min]: 26.6776)
(helical cut)
G0 x104.750y79.500 (travel)
f700.000 (set feed)
G0 z1.400 (lift down)
G1 z0.200 (push)
G2 z0.050 i5.250
G2 z-0.100 i5.250
G2 z-0.250 i5.250
G2 z-0.400 i5.250
G2 z-0.550 i5.250
G2 z-0.700 i5.250
G2 z-0.850 i5.250
G2 z-1.000 i5.250
G2 z-1.150 i5.250
G2 z-1.300 i5.250
G2 z-1.450 i5.250
G2 z-1.600 i5.250
G2 z-1.750 i5.250
G2 z-1.900 i5.250
G2 z-2.050 i5.250
G2 z-2.200 i5.250
G2 z-2.350 i5.250
G2 z-2.500 i5.250
G2 z-2.600 i5.250
G2 z-2.600 i5.250
G1 z0.200 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
(compensate cut: 0.15 -> 0.0643173)
(compensate feed: 700 -> 720)
G0 x105.334y81.907 (travel)
f720.000 (set feed)
G0 z-1.400 (lift down)
G1 z-2.600 (push)
(peck)
G2 x115.250y79.500z-2.664 i4.666 j-2.407
G0 z-1.400
G4 P489
G1 z-2.664
G3 x105.334y81.907z-2.729 i-5.250 j0.000
G0 z-1.400
G4 P478
G1 z-2.729
G2 x115.250y79.500z-2.793 i4.666 j-2.407
G0 z-1.400
G4 P468
G1 z-2.793
G3 x105.334y81.907z-2.857 i-5.250 j0.000
G0 z-1.400
G4 P457
G1 z-2.857
G2 x115.250y79.500z-2.922 i4.666 j-2.407
G0 z-1.400
G4 P446
G1 z-2.922
G3 x105.334y81.907z-2.986 i-5.250 j0.000
G0 z-1.400
G4 P436
G1 z-2.986
G2 x115.250y79.500z-3.050 i4.666 j-2.407
G0 z-1.400
G4 P425
G1 z-3.050
G3 x105.334y81.907z-3.100 i-5.250 j0.000
G0 z-1.400
G4 P417
G1 z-3.100
G2 x115.250y79.500z-3.100 i4.666 j-2.407
G0 z-1.400
G4 P417
G1 z-3.100
G1 z-2.600 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
(compensate cut: 0.15 -> 0.0643173)
(compensate feed: 700 -> 720)
G0 x114.666y77.093 (travel)
G0 z-1.400 (lift down)
G1 z-2.600 (push)
(peck)
G2 x104.750y79.500z-2.664 i-4.666 j2.407
G0 z-1.400
G4 P489
G1 z-2.664
G3 x114.666y77.093z-2.729 i5.250 j0.000
G0 z-1.400
G4 P478
G1 z-2.729
G2 x104.750y79.500z-2.793 i-4.666 j2.407
G0 z-1.400
G4 P468
G1 z-2.793
G3 x114.666y77.093z-2.857 i5.250 j0.000
G0 z-1.400
G4 P457
G1 z-2.857
G2 x104.750y79.500z-2.922 i-4.666 j2.407
G0 z-1.400
G4 P446
G1 z-2.922
G3 x114.666y77.093z-2.986 i5.250 j0.000
G0 z-1.400
G4 P436
G1 z-2.986
G2 x104.750y79.500z-3.050 i-4.666 j2.407
G0 z-1.400
G4 P425
G1 z-3.050
G3 x114.666y77.093z-3.100 i5.250 j0.000
G0 z-1.400
G4 P417
G1 z-3.100
G2 x104.750y79.500z-3.100 i-4.666 j2.407
G0 z-1.400
G4 P417
G1 z-3.100
G1 z-2.600 (pull)
G0 z2.000 (lift up)
(time[min]: 28.0565)
(rögzítő furatok)
(táp 12v - furat táv 55mm)
(hole)
(helical interpolation)
(time[min]: 28.0565)
(compensate cut: 0.07 -> 0.0314159)
(compensate feed: 700 -> 720)
(predrill)
G0 x28.800y49.000 (travel)
G0 z1.400 (lift down)
G1 z0.200 (push)
G98 G83 z-3.100 r1.400 q0.031
(premill)
(helical cut)
(compensate cut: 0.07 -> 0.0376991)
(compensate feed: 700 -> 720)
G0 z2.000 (lift up)
G0 x28.200y49.000 (travel)
G0 z1.400 (lift down)
G1 z0.200 (push)
G2 z0.162 i0.600
G2 z0.125 i0.600
G2 z0.087 i0.600
G2 z0.049 i0.600
G2 z0.012 i0.600
G2 z-0.026 i0.600
G2 z-0.064 i0.600
G2 z-0.102 i0.600
G2 z-0.139 i0.600
G2 z-0.177 i0.600
G2 z-0.215 i0.600
G2 z-0.252 i0.600
G2 z-0.290 i0.600
G2 z-0.328 i0.600
G2 z-0.365 i0.600
G2 z-0.403 i0.600
G2 z-0.441 i0.600
G2 z-0.479 i0.600
G2 z-0.516 i0.600
G2 z-0.554 i0.600
G2 z-0.592 i0.600
G2 z-0.629 i0.600
G2 z-0.667 i0.600
G2 z-0.705 i0.600
G2 z-0.742 i0.600
G2 z-0.780 i0.600
G2 z-0.818 i0.600
G2 z-0.856 i0.600
G2 z-0.893 i0.600
G2 z-0.931 i0.600
G2 z-0.969 i0.600
G2 z-1.006 i0.600
G2 z-1.044 i0.600
G2 z-1.082 i0.600
G2 z-1.119 i0.600
G2 z-1.157 i0.600
G2 z-1.195 i0.600
G2 z-1.233 i0.600
G2 z-1.270 i0.600
G2 z-1.308 i0.600
G2 z-1.346 i0.600
G2 z-1.383 i0.600
G2 z-1.421 i0.600
G2 z-1.459 i0.600
G2 z-1.496 i0.600
G2 z-1.534 i0.600
G2 z-1.572 i0.600
G2 z-1.610 i0.600
G2 z-1.647 i0.600
G2 z-1.685 i0.600
G2 z-1.723 i0.600
G2 z-1.760 i0.600
G2 z-1.798 i0.600
G2 z-1.836 i0.600
G2 z-1.873 i0.600
G2 z-1.911 i0.600
G2 z-1.949 i0.600
G2 z-1.987 i0.600
G2 z-2.024 i0.600
G2 z-2.062 i0.600
G2 z-2.100 i0.600
G2 z-2.137 i0.600
G2 z-2.175 i0.600
G2 z-2.213 i0.600
G2 z-2.250 i0.600
G2 z-2.288 i0.600
G2 z-2.326 i0.600
G2 z-2.364 i0.600
G2 z-2.401 i0.600
G2 z-2.439 i0.600
G2 z-2.477 i0.600
G2 z-2.514 i0.600
G2 z-2.552 i0.600
G2 z-2.590 i0.600
G2 z-2.627 i0.600
G2 z-2.665 i0.600
G2 z-2.703 i0.600
G2 z-2.741 i0.600
G2 z-2.778 i0.600
G2 z-2.816 i0.600
G2 z-2.854 i0.600
G2 z-2.891 i0.600
G2 z-2.929 i0.600
G2 z-2.967 i0.600
G2 z-3.004 i0.600
G2 z-3.042 i0.600
G2 z-3.080 i0.600
G2 z-3.100 i0.600
G2 z-3.100 i0.600
G1 z0.200 (pull)
G0 z2.000 (lift up)
(time[min]: 28.7152)
(hole)
(helical interpolation)
(time[min]: 28.7152)
(compensate cut: 0.07 -> 0.0314159)
(compensate feed: 700 -> 720)
(predrill)
G0 x83.800y49.000 (travel)
G0 z1.400 (lift down)
G1 z0.200 (push)
G98 G83 z-3.100 r1.400 q0.031
(premill)
(helical cut)
(compensate cut: 0.07 -> 0.0376991)
(compensate feed: 700 -> 720)
G0 z2.000 (lift up)
G0 x83.200y49.000 (travel)
G0 z1.400 (lift down)
G1 z0.200 (push)
G2 z0.162 i0.600
G2 z0.125 i0.600
G2 z0.087 i0.600
G2 z0.049 i0.600
G2 z0.012 i0.600
G2 z-0.026 i0.600
G2 z-0.064 i0.600
G2 z-0.102 i0.600
G2 z-0.139 i0.600
G2 z-0.177 i0.600
G2 z-0.215 i0.600
G2 z-0.252 i0.600
G2 z-0.290 i0.600
G2 z-0.328 i0.600
G2 z-0.365 i0.600
G2 z-0.403 i0.600
G2 z-0.441 i0.600
G2 z-0.479 i0.600
G2 z-0.516 i0.600
G2 z-0.554 i0.600
G2 z-0.592 i0.600
G2 z-0.629 i0.600
G2 z-0.667 i0.600
G2 z-0.705 i0.600
G2 z-0.742 i0.600
G2 z-0.780 i0.600
G2 z-0.818 i0.600
G2 z-0.856 i0.600
G2 z-0.893 i0.600
G2 z-0.931 i0.600
G2 z-0.969 i0.600
G2 z-1.006 i0.600
G2 z-1.044 i0.600
G2 z-1.082 i0.600
G2 z-1.119 i0.600
G2 z-1.157 i0.600
G2 z-1.195 i0.600
G2 z-1.233 i0.600
G2 z-1.270 i0.600
G2 z-1.308 i0.600
G2 z-1.346 i0.600
G2 z-1.383 i0.600
G2 z-1.421 i0.600
G2 z-1.459 i0.600
G2 z-1.496 i0.600
G2 z-1.534 i0.600
G2 z-1.572 i0.600
G2 z-1.610 i0.600
G2 z-1.647 i0.600
G2 z-1.685 i0.600
G2 z-1.723 i0.600
G2 z-1.760 i0.600
G2 z-1.798 i0.600
G2 z-1.836 i0.600
G2 z-1.873 i0.600
G2 z-1.911 i0.600
G2 z-1.949 i0.600
G2 z-1.987 i0.600
G2 z-2.024 i0.600
G2 z-2.062 i0.600
G2 z-2.100 i0.600
G2 z-2.137 i0.600
G2 z-2.175 i0.600
G2 z-2.213 i0.600
G2 z-2.250 i0.600
G2 z-2.288 i0.600
G2 z-2.326 i0.600
G2 z-2.364 i0.600
G2 z-2.401 i0.600
G2 z-2.439 i0.600
G2 z-2.477 i0.600
G2 z-2.514 i0.600
G2 z-2.552 i0.600
G2 z-2.590 i0.600
G2 z-2.627 i0.600
G2 z-2.665 i0.600
G2 z-2.703 i0.600
G2 z-2.741 i0.600
G2 z-2.778 i0.600
G2 z-2.816 i0.600
G2 z-2.854 i0.600
G2 z-2.891 i0.600
G2 z-2.929 i0.600
G2 z-2.967 i0.600
G2 z-3.004 i0.600
G2 z-3.042 i0.600
G2 z-3.080 i0.600
G2 z-3.100 i0.600
G2 z-3.100 i0.600
G1 z0.200 (pull)
G0 z2.000 (lift up)
(time[min]: 29.374)
(táp 5vv - furat táv 55mm)
(hole)
(helical interpolation)
(time[min]: 29.374)
(compensate cut: 0.07 -> 0.0314159)
(compensate feed: 700 -> 720)
(predrill)
G0 x20.000y122.000 (travel)
G0 z1.400 (lift down)
G1 z0.200 (push)
G98 G83 z-3.100 r1.400 q0.031
(premill)
(helical cut)
(compensate cut: 0.07 -> 0.0376991)
(compensate feed: 700 -> 720)
G0 z2.000 (lift up)
G0 x19.400y122.000 (travel)
G0 z1.400 (lift down)
G1 z0.200 (push)
G2 z0.162 i0.600
G2 z0.125 i0.600
G2 z0.087 i0.600
G2 z0.049 i0.600
G2 z0.012 i0.600
G2 z-0.026 i0.600
G2 z-0.064 i0.600
G2 z-0.102 i0.600
G2 z-0.139 i0.600
G2 z-0.177 i0.600
G2 z-0.215 i0.600
G2 z-0.252 i0.600
G2 z-0.290 i0.600
G2 z-0.328 i0.600
G2 z-0.365 i0.600
G2 z-0.403 i0.600
G2 z-0.441 i0.600
G2 z-0.479 i0.600
G2 z-0.516 i0.600
G2 z-0.554 i0.600
G2 z-0.592 i0.600
G2 z-0.629 i0.600
G2 z-0.667 i0.600
G2 z-0.705 i0.600
G2 z-0.742 i0.600
G2 z-0.780 i0.600
G2 z-0.818 i0.600
G2 z-0.856 i0.600
G2 z-0.893 i0.600
G2 z-0.931 i0.600
G2 z-0.969 i0.600
G2 z-1.006 i0.600
G2 z-1.044 i0.600
G2 z-1.082 i0.600
G2 z-1.119 i0.600
G2 z-1.157 i0.600
G2 z-1.195 i0.600
G2 z-1.233 i0.600
G2 z-1.270 i0.600
G2 z-1.308 i0.600
G2 z-1.346 i0.600
G2 z-1.383 i0.600
G2 z-1.421 i0.600
G2 z-1.459 i0.600
G2 z-1.496 i0.600
G2 z-1.534 i0.600
G2 z-1.572 i0.600
G2 z-1.610 i0.600
G2 z-1.647 i0.600
G2 z-1.685 i0.600
G2 z-1.723 i0.600
G2 z-1.760 i0.600
G2 z-1.798 i0.600
G2 z-1.836 i0.600
G2 z-1.873 i0.600
G2 z-1.911 i0.600
G2 z-1.949 i0.600
G2 z-1.987 i0.600
G2 z-2.024 i0.600
G2 z-2.062 i0.600
G2 z-2.100 i0.600
G2 z-2.137 i0.600
G2 z-2.175 i0.600
G2 z-2.213 i0.600
G2 z-2.250 i0.600
G2 z-2.288 i0.600
G2 z-2.326 i0.600
G2 z-2.364 i0.600
G2 z-2.401 i0.600
G2 z-2.439 i0.600
G2 z-2.477 i0.600
G2 z-2.514 i0.600
G2 z-2.552 i0.600
G2 z-2.590 i0.600
G2 z-2.627 i0.600
G2 z-2.665 i0.600
G2 z-2.703 i0.600
G2 z-2.741 i0.600
G2 z-2.778 i0.600
G2 z-2.816 i0.600
G2 z-2.854 i0.600
G2 z-2.891 i0.600
G2 z-2.929 i0.600
G2 z-2.967 i0.600
G2 z-3.004 i0.600
G2 z-3.042 i0.600
G2 z-3.080 i0.600
G2 z-3.100 i0.600
G2 z-3.100 i0.600
G1 z0.200 (pull)
G0 z2.000 (lift up)
(time[min]: 30.0328)
(hole)
(helical interpolation)
(time[min]: 30.0328)
(compensate cut: 0.07 -> 0.0314159)
(compensate feed: 700 -> 720)
(predrill)
G0 x35.900y122.000 (travel)
G0 z1.400 (lift down)
G1 z0.200 (push)
G98 G83 z-3.100 r1.400 q0.031
(premill)
(helical cut)
(compensate cut: 0.07 -> 0.0376991)
(compensate feed: 700 -> 720)
G0 z2.000 (lift up)
G0 x35.300y122.000 (travel)
G0 z1.400 (lift down)
G1 z0.200 (push)
G2 z0.162 i0.600
G2 z0.125 i0.600
G2 z0.087 i0.600
G2 z0.049 i0.600
G2 z0.012 i0.600
G2 z-0.026 i0.600
G2 z-0.064 i0.600
G2 z-0.102 i0.600
G2 z-0.139 i0.600
G2 z-0.177 i0.600
G2 z-0.215 i0.600
G2 z-0.252 i0.600
G2 z-0.290 i0.600
G2 z-0.328 i0.600
G2 z-0.365 i0.600
G2 z-0.403 i0.600
G2 z-0.441 i0.600
G2 z-0.479 i0.600
G2 z-0.516 i0.600
G2 z-0.554 i0.600
G2 z-0.592 i0.600
G2 z-0.629 i0.600
G2 z-0.667 i0.600
G2 z-0.705 i0.600
G2 z-0.742 i0.600
G2 z-0.780 i0.600
G2 z-0.818 i0.600
G2 z-0.856 i0.600
G2 z-0.893 i0.600
G2 z-0.931 i0.600
G2 z-0.969 i0.600
G2 z-1.006 i0.600
G2 z-1.044 i0.600
G2 z-1.082 i0.600
G2 z-1.119 i0.600
G2 z-1.157 i0.600
G2 z-1.195 i0.600
G2 z-1.233 i0.600
G2 z-1.270 i0.600
G2 z-1.308 i0.600
G2 z-1.346 i0.600
G2 z-1.383 i0.600
G2 z-1.421 i0.600
G2 z-1.459 i0.600
G2 z-1.496 i0.600
G2 z-1.534 i0.600
G2 z-1.572 i0.600
G2 z-1.610 i0.600
G2 z-1.647 i0.600
G2 z-1.685 i0.600
G2 z-1.723 i0.600
G2 z-1.760 i0.600
G2 z-1.798 i0.600
G2 z-1.836 i0.600
G2 z-1.873 i0.600
G2 z-1.911 i0.600
G2 z-1.949 i0.600
G2 z-1.987 i0.600
G2 z-2.024 i0.600
G2 z-2.062 i0.600
G2 z-2.100 i0.600
G2 z-2.137 i0.600
G2 z-2.175 i0.600
G2 z-2.213 i0.600
G2 z-2.250 i0.600
G2 z-2.288 i0.600
G2 z-2.326 i0.600
G2 z-2.364 i0.600
G2 z-2.401 i0.600
G2 z-2.439 i0.600
G2 z-2.477 i0.600
G2 z-2.514 i0.600
G2 z-2.552 i0.600
G2 z-2.590 i0.600
G2 z-2.627 i0.600
G2 z-2.665 i0.600
G2 z-2.703 i0.600
G2 z-2.741 i0.600
G2 z-2.778 i0.600
G2 z-2.816 i0.600
G2 z-2.854 i0.600
G2 z-2.891 i0.600
G2 z-2.929 i0.600
G2 z-2.967 i0.600
G2 z-3.004 i0.600
G2 z-3.042 i0.600
G2 z-3.080 i0.600
G2 z-3.100 i0.600
G2 z-3.100 i0.600
G1 z0.200 (pull)
G0 z2.000 (lift up)
(time[min]: 30.6915)
(hole)
(helical interpolation)
(time[min]: 30.6915)
(compensate cut: 0.07 -> 0.0314159)
(compensate feed: 700 -> 720)
(predrill)
G0 x75.000y122.000 (travel)
G0 z1.400 (lift down)
G1 z0.200 (push)
G98 G83 z-3.100 r1.400 q0.031
(premill)
(helical cut)
(compensate cut: 0.07 -> 0.0376991)
(compensate feed: 700 -> 720)
G0 z2.000 (lift up)
G0 x74.400y122.000 (travel)
G0 z1.400 (lift down)
G1 z0.200 (push)
G2 z0.162 i0.600
G2 z0.125 i0.600
G2 z0.087 i0.600
G2 z0.049 i0.600
G2 z0.012 i0.600
G2 z-0.026 i0.600
G2 z-0.064 i0.600
G2 z-0.102 i0.600
G2 z-0.139 i0.600
G2 z-0.177 i0.600
G2 z-0.215 i0.600
G2 z-0.252 i0.600
G2 z-0.290 i0.600
G2 z-0.328 i0.600
G2 z-0.365 i0.600
G2 z-0.403 i0.600
G2 z-0.441 i0.600
G2 z-0.479 i0.600
G2 z-0.516 i0.600
G2 z-0.554 i0.600
G2 z-0.592 i0.600
G2 z-0.629 i0.600
G2 z-0.667 i0.600
G2 z-0.705 i0.600
G2 z-0.742 i0.600
G2 z-0.780 i0.600
G2 z-0.818 i0.600
G2 z-0.856 i0.600
G2 z-0.893 i0.600
G2 z-0.931 i0.600
G2 z-0.969 i0.600
G2 z-1.006 i0.600
G2 z-1.044 i0.600
G2 z-1.082 i0.600
G2 z-1.119 i0.600
G2 z-1.157 i0.600
G2 z-1.195 i0.600
G2 z-1.233 i0.600
G2 z-1.270 i0.600
G2 z-1.308 i0.600
G2 z-1.346 i0.600
G2 z-1.383 i0.600
G2 z-1.421 i0.600
G2 z-1.459 i0.600
G2 z-1.496 i0.600
G2 z-1.534 i0.600
G2 z-1.572 i0.600
G2 z-1.610 i0.600
G2 z-1.647 i0.600
G2 z-1.685 i0.600
G2 z-1.723 i0.600
G2 z-1.760 i0.600
G2 z-1.798 i0.600
G2 z-1.836 i0.600
G2 z-1.873 i0.600
G2 z-1.911 i0.600
G2 z-1.949 i0.600
G2 z-1.987 i0.600
G2 z-2.024 i0.600
G2 z-2.062 i0.600
G2 z-2.100 i0.600
G2 z-2.137 i0.600
G2 z-2.175 i0.600
G2 z-2.213 i0.600
G2 z-2.250 i0.600
G2 z-2.288 i0.600
G2 z-2.326 i0.600
G2 z-2.364 i0.600
G2 z-2.401 i0.600
G2 z-2.439 i0.600
G2 z-2.477 i0.600
G2 z-2.514 i0.600
G2 z-2.552 i0.600
G2 z-2.590 i0.600
G2 z-2.627 i0.600
G2 z-2.665 i0.600
G2 z-2.703 i0.600
G2 z-2.741 i0.600
G2 z-2.778 i0.600
G2 z-2.816 i0.600
G2 z-2.854 i0.600
G2 z-2.891 i0.600
G2 z-2.929 i0.600
G2 z-2.967 i0.600
G2 z-3.004 i0.600
G2 z-3.042 i0.600
G2 z-3.080 i0.600
G2 z-3.100 i0.600
G2 z-3.100 i0.600
G1 z0.200 (pull)
G0 z2.000 (lift up)
(time[min]: 31.3503)
(táp 5vv - furat táv 55mm)
(körbevágás)
G0 z2.000 (lift up)
G0 x0.000y0.000 (travel)
(travel to safe place)

M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)
M30
(end)
