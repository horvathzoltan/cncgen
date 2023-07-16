(GCode generated by cncgen - https://github.com/horvathzoltan/cncgen)
(type: GCode from geometry)
(input file: pi_alatet_24db.txt)
(output file: pi_alatet_24db_plot.gcode)
(created on: Sze júl. 12 12:29:58 2023)
(total time: 00:32:16.000)
(total cut: 9439.8mm)
(total length: 10642.6mm)
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
(cmd line: -i pi_alatet_24db.txt -t)
(plot cmd: -i pi_alatet_24db.txt -t -p)
(szerszám beállítás)
(set tool 1 to t1 m  d2.000 h19.000)
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

(mélység)
(belső átmérő)
(külső átmérő)
(dk: 9.8)
(h 4,4 d7.5 z1.2 c0.175 g0,0,0 np)
(h 4,4 d5 z1.2 c0.175 g0,0,0 np)
(1.sor)
(hole - helical interpolation)
(time: 0.00133333)
(helical cut)
G0 x4.600y4.900 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.0239748)
(hole - helical interpolation)
(time: 0.0239748)
(helical cut)
G0 x1.000y4.900 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x1.041y4.339 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x7.658y7.658z-0.020 i3.859 j0.561
G3 x1.041y4.339z-0.020 i-2.758 j-2.758
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x8.759y5.461 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x2.142y2.142z-0.020 i-3.859 j-0.561
G3 x8.759y5.461z-0.020 i2.758 j2.758
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 0.302183)
(hole - helical interpolation)
(time: 0.302183)
(helical cut)
G0 x4.600y17.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.32887)
(hole - helical interpolation)
(time: 0.32887)
(helical cut)
G0 x1.000y17.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x1.818y15.310 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x5.941y21.459z-0.020 i3.082 j2.390
G3 x1.818y15.310z-0.020 i-1.041 j-3.759
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x7.982y20.090 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x3.859y13.941z-0.020 i-3.082 j-2.390
G3 x7.982y20.090z-0.020 i1.041 j3.759
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 0.885434)
(hole - helical interpolation)
(time: 0.885434)
(helical cut)
G0 x4.600y30.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.910819)
(hole - helical interpolation)
(time: 0.910819)
(helical cut)
G0 x1.000y30.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x2.101y27.784 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x5.519y34.351z-0.020 i2.799 j2.716
G3 x2.101y27.784z-0.020 i-0.619 j-3.851
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x7.699y33.216 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.281y26.649z-0.020 i-2.799 j-2.716
G3 x7.699y33.216z-0.020 i0.619 j3.851
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 1.83941)
(hole - helical interpolation)
(time: 1.83941)
(helical cut)
G0 x4.600y43.300 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.86454)
(hole - helical interpolation)
(time: 1.86454)
(helical cut)
G0 x1.000y43.300 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x2.231y40.456 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x5.339y47.175z-0.020 i2.669 j2.844
G3 x2.231y40.456z-0.020 i-0.439 j-3.875
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x7.569y46.144 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.461y39.425z-0.020 i-2.669 j-2.844
G3 x7.569y46.144z-0.020 i0.439 j3.875
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 3.167)
(hole - helical interpolation)
(time: 3.167)
(helical cut)
G0 x4.600y56.100 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 3.19202)
(hole - helical interpolation)
(time: 3.19202)
(helical cut)
G0 x1.000y56.100 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x2.305y53.189 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x5.239y59.985z-0.020 i2.595 j2.911
G3 x2.305y53.189z-0.020 i-0.339 j-3.885
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x7.495y59.011 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.561y52.215z-0.020 i-2.595 j-2.911
G3 x7.495y59.011z-0.020 i0.339 j3.885
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 4.8688)
(hole - helical interpolation)
(time: 4.8688)
(helical cut)
G0 x4.600y68.900 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 4.89377)
(hole - helical interpolation)
(time: 4.89377)
(helical cut)
G0 x1.000y68.900 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x2.352y65.948 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x5.177y72.790z-0.020 i2.548 j2.952
G3 x2.352y65.948z-0.020 i-0.277 j-3.890
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x7.448y71.852 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.623y65.010z-0.020 i-2.548 j-2.952
G3 x7.448y71.852z-0.020 i0.277 j3.890
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 6.94505)
(hole - helical interpolation)
(time: 6.94505)
(helical cut)
G0 x4.600y81.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 6.96998)
(hole - helical interpolation)
(time: 6.96998)
(helical cut)
G0 x1.000y81.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x2.385y78.719 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x5.133y85.593z-0.020 i2.515 j2.981
G3 x2.385y78.719z-0.020 i-0.233 j-3.893
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x7.415y84.681 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.667y77.807z-0.020 i-2.515 j-2.981
G3 x7.415y84.681z-0.020 i0.233 j3.893
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 9.39585)
(hole - helical interpolation)
(time: 9.39585)
(helical cut)
G0 x4.600y94.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 9.42075)
(hole - helical interpolation)
(time: 9.42075)
(helical cut)
G0 x1.000y94.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x2.409y91.499 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x5.102y98.395z-0.020 i2.491 j3.001
G3 x2.409y91.499z-0.020 i-0.202 j-3.895
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x7.391y97.501 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.698y90.605z-0.020 i-2.491 j-3.001
G3 x7.391y97.501z-0.020 i0.202 j3.895
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 12.2213)
(2.sor)
(hole - helical interpolation)
(time: 12.2213)
(helical cut)
G0 x17.400y10.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 12.298)
(hole - helical interpolation)
(time: 12.298)
(helical cut)
G0 x13.800y10.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x13.831y10.493 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x21.096y11.918z-0.020 i3.869 j-0.493
G3 x13.831y10.493z-0.020 i-3.396 j-1.918
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x21.569y9.507 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x14.304y8.082z-0.020 i-3.869 j0.493
G3 x21.569y9.507z-0.020 i3.396 j1.918
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 12.6892)
(hole - helical interpolation)
(time: 12.6892)
(helical cut)
G0 x17.400y22.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 12.7165)
(hole - helical interpolation)
(time: 12.7165)
(helical cut)
G0 x13.800y22.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x13.941y21.761 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x20.092y25.881z-0.020 i3.759 j1.039
G3 x13.941y21.761z-0.020 i-2.392 j-3.081
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x21.459y23.839 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x15.308y19.719z-0.020 i-3.759 j-1.039
G3 x21.459y23.839z-0.020 i2.392 j3.081
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 13.1413)
(hole - helical interpolation)
(time: 13.1413)
(helical cut)
G0 x17.400y35.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 13.1677)
(hole - helical interpolation)
(time: 13.1677)
(helical cut)
G0 x13.800y35.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x14.220y33.839 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x19.436y39.092z-0.020 i3.480 j1.761
G3 x14.220y33.839z-0.020 i-1.736 j-3.492
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x21.180y37.361 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x15.964y32.108z-0.020 i-3.480 j-1.761
G3 x21.180y37.361z-0.020 i1.736 j3.492
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 13.916)
(hole - helical interpolation)
(time: 13.916)
(helical cut)
G0 x17.400y48.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 13.9418)
(hole - helical interpolation)
(time: 13.9418)
(helical cut)
G0 x13.800y48.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x14.436y46.265 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x19.039y52.063z-0.020 i3.264 j2.135
G3 x14.436y46.265z-0.020 i-1.339 j-3.663
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x20.964y50.535 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x16.361y44.737z-0.020 i-3.264 j-2.135
G3 x20.964y50.535z-0.020 i1.339 j3.663
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 15.0427)
(hole - helical interpolation)
(time: 15.0427)
(helical cut)
G0 x17.400y61.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 15.0683)
(hole - helical interpolation)
(time: 15.0683)
(helical cut)
G0 x13.800y61.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x14.591y58.845 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x18.784y64.946z-0.020 i3.109 j2.355
G3 x14.591y58.845z-0.020 i-1.084 j-3.746
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x20.809y63.555 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x16.616y57.454z-0.020 i-3.109 j-2.355
G3 x20.809y63.555z-0.020 i1.084 j3.746
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 16.531)
(hole - helical interpolation)
(time: 16.531)
(helical cut)
G0 x17.400y74.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 16.5564)
(hole - helical interpolation)
(time: 16.5564)
(helical cut)
G0 x13.800y74.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x14.705y71.503 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x18.607y77.793z-0.020 i2.995 j2.497
G3 x14.705y71.503z-0.020 i-0.907 j-3.793
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x20.695y76.497 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x16.793y70.207z-0.020 i-2.995 j-2.497
G3 x20.695y76.497z-0.020 i0.907 j3.793
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 18.3853)
(hole - helical interpolation)
(time: 18.3853)
(helical cut)
G0 x17.400y86.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 18.4106)
(hole - helical interpolation)
(time: 18.4106)
(helical cut)
G0 x13.800y86.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x14.790y84.203 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x18.479y90.621z-0.020 i2.910 j2.597
G3 x14.790y84.203z-0.020 i-0.779 j-3.821
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x20.610y89.397 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x16.921y82.979z-0.020 i-2.910 j-2.597
G3 x20.610y89.397z-0.020 i0.779 j3.821
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 20.6082)
(hole - helical interpolation)
(time: 20.6082)
(helical cut)
G0 x17.400y99.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 20.6334)
(hole - helical interpolation)
(time: 20.6334)
(helical cut)
G0 x13.800y99.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x14.857y96.931 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x18.382y103.440z-0.020 i2.843 j2.669
G3 x14.857y96.931z-0.020 i-0.682 j-3.840
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x20.543y102.269 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x17.018y95.760z-0.020 i-2.843 j-2.669
G3 x20.543y102.269z-0.020 i0.682 j3.840
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 23.2012)
(3.sor)
(hole - helical interpolation)
(time: 23.2012)
(helical cut)
G0 x30.200y4.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 23.2851)
(hole - helical interpolation)
(time: 23.2851)
(helical cut)
G0 x26.600y4.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x27.097y5.906 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x34.367y4.507z-0.020 i3.403 j-1.906
G3 x27.097y5.906z-0.020 i-3.867 j-0.507
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x33.903y2.094 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x26.633y3.493z-0.020 i-3.403 j1.906
G3 x33.903y2.094z-0.020 i3.867 j0.507
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 24.2688)
(hole - helical interpolation)
(time: 24.2688)
(helical cut)
G0 x30.200y16.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 24.297)
(hole - helical interpolation)
(time: 24.297)
(helical cut)
G0 x26.600y16.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x26.637y17.335 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x33.916y18.682z-0.020 i3.863 j-0.535
G3 x26.637y17.335z-0.020 i-3.416 j-1.882
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x34.363y16.265 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x27.084y14.918z-0.020 i-3.863 j0.535
G3 x34.363y16.265z-0.020 i3.416 j1.882
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 24.8029)
(hole - helical interpolation)
(time: 24.8029)
(helical cut)
G0 x30.200y29.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 24.8302)
(hole - helical interpolation)
(time: 24.8302)
(helical cut)
G0 x26.600y29.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x26.633y29.097 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x33.299y32.316z-0.020 i3.867 j0.503
G3 x26.633y29.097z-0.020 i-2.799 j-2.716
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x34.367y30.103 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x27.701y26.884z-0.020 i-3.867 j-0.503
G3 x34.367y30.103z-0.020 i2.799 j2.716
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 25.2981)
(hole - helical interpolation)
(time: 25.2981)
(helical cut)
G0 x30.200y42.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 25.3248)
(hole - helical interpolation)
(time: 25.3248)
(helical cut)
G0 x26.600y42.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x26.781y41.224 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x32.777y45.566z-0.020 i3.719 j1.176
G3 x26.781y41.224z-0.020 i-2.277 j-3.166
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x34.219y43.576 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x28.223y39.234z-0.020 i-3.719 j-1.176
G3 x34.219y43.576z-0.020 i2.277 j3.166
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 25.998)
(hole - helical interpolation)
(time: 25.998)
(helical cut)
G0 x30.200y55.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 26.0243)
(hole - helical interpolation)
(time: 26.0243)
(helical cut)
G0 x26.600y55.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x26.947y53.592 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x32.386y58.614z-0.020 i3.553 j1.608
G3 x26.947y53.592z-0.020 i-1.886 j-3.414
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x34.053y56.808 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x28.614y51.786z-0.020 i-3.553 j-1.608
G3 x34.053y56.808z-0.020 i1.886 j3.414
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 27.0247)
(hole - helical interpolation)
(time: 27.0247)
(helical cut)
G0 x30.200y68.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 27.0506)
(hole - helical interpolation)
(time: 27.0506)
(helical cut)
G0 x26.600y68.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x27.093y66.102 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x32.096y71.558z-0.020 i3.407 j1.898
G3 x27.093y66.102z-0.020 i-1.596 j-3.558
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x33.907y69.898 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x28.904y64.442z-0.020 i-3.407 j-1.898
G3 x33.907y69.898z-0.020 i1.596 j3.558
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 28.3948)
(hole - helical interpolation)
(time: 28.3948)
(helical cut)
G0 x30.200y80.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 28.4205)
(hole - helical interpolation)
(time: 28.4205)
(helical cut)
G0 x26.600y80.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x27.214y78.699 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x31.877y84.449z-0.020 i3.286 j2.101
G3 x27.214y78.699z-0.020 i-1.377 j-3.649
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x33.786y82.901 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x29.123y77.151z-0.020 i-3.286 j-2.101
G3 x33.786y82.901z-0.020 i1.377 j3.649
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 30.1176)
(hole - helical interpolation)
(time: 30.1176)
(helical cut)
G0 x30.200y93.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.300
G2 z-0.020 i0.300
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 30.1432)
(hole - helical interpolation)
(time: 30.1432)
(helical cut)
G0 x26.600y93.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.900
G2 z-0.010 i3.900
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x27.314y91.351 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x31.708y97.308z-0.020 i3.186 j2.249
G3 x27.314y91.351z-0.020 i-1.208 j-3.708
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x33.686y95.849 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x29.292y89.892z-0.020 i-3.186 j-2.249
G3 x33.686y95.849z-0.020 i1.208 j3.708
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 32.1988)
G0 z2.000 (lift up)
G0 x0.000y0.000 (travel)
(travel to safe place)

M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)
M30
(end)
