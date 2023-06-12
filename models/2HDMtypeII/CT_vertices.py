# This file was automatically created by FeynRules 2.1.67
# Mathematica version: 9.0 for Mac OS X x86 (64-bit) (January 24, 2013)
# Date: Wed 18 Jun 2014 10:44:40


from object_library import all_vertices, all_CTvertices, Vertex, CTVertex
import particles as P
import CT_couplings as C
import lorentz as L


V_1 = CTVertex(name = 'V_1',
               type = 'R2',
               particles = [ P.g, P.g, P.g ],
               color = [ 'f(1,2,3)' ],
               lorentz = [ L.VVV2 ],
               loop_particles = [ [ [P.b], [P.c], [P.d], [P.s], [P.t], [P.u] ], [ [P.g] ] ],
               couplings = {(0,0,0):C.R2GC_273_53,(0,0,1):C.R2GC_273_54})

V_2 = CTVertex(name = 'V_2',
               type = 'R2',
               particles = [ P.g, P.g, P.g, P.g ],
               color = [ 'd(-1,1,3)*d(-1,2,4)', 'd(-1,1,3)*f(-1,2,4)', 'd(-1,1,4)*d(-1,2,3)', 'd(-1,1,4)*f(-1,2,3)', 'd(-1,2,3)*f(-1,1,4)', 'd(-1,2,4)*f(-1,1,3)', 'f(-1,1,2)*f(-1,3,4)', 'f(-1,1,3)*f(-1,2,4)', 'f(-1,1,4)*f(-1,2,3)', 'Identity(1,2)*Identity(3,4)', 'Identity(1,3)*Identity(2,4)', 'Identity(1,4)*Identity(2,3)' ],
               lorentz = [ L.VVVV10, L.VVVV2, L.VVVV3, L.VVVV5 ],
               loop_particles = [ [ [P.b], [P.c], [P.d], [P.s], [P.t], [P.u] ], [ [P.g] ] ],
               couplings = {(2,1,0):C.R2GC_242_36,(2,1,1):C.R2GC_242_37,(0,1,0):C.R2GC_242_36,(0,1,1):C.R2GC_242_37,(4,1,0):C.R2GC_240_32,(4,1,1):C.R2GC_240_33,(3,1,0):C.R2GC_240_32,(3,1,1):C.R2GC_240_33,(8,1,0):C.R2GC_241_34,(8,1,1):C.R2GC_241_35,(7,1,0):C.R2GC_246_43,(7,1,1):C.R2GC_277_59,(6,1,0):C.R2GC_245_41,(6,1,1):C.R2GC_278_60,(5,1,0):C.R2GC_240_32,(5,1,1):C.R2GC_240_33,(1,1,0):C.R2GC_240_32,(1,1,1):C.R2GC_240_33,(11,0,0):C.R2GC_244_39,(11,0,1):C.R2GC_244_40,(10,0,0):C.R2GC_244_39,(10,0,1):C.R2GC_244_40,(9,0,1):C.R2GC_243_38,(2,2,0):C.R2GC_242_36,(2,2,1):C.R2GC_242_37,(0,2,0):C.R2GC_242_36,(0,2,1):C.R2GC_242_37,(6,2,0):C.R2GC_274_55,(6,2,1):C.R2GC_274_56,(4,2,0):C.R2GC_240_32,(4,2,1):C.R2GC_240_33,(3,2,0):C.R2GC_240_32,(3,2,1):C.R2GC_240_33,(8,2,0):C.R2GC_241_34,(8,2,1):C.R2GC_279_61,(7,2,0):C.R2GC_246_43,(7,2,1):C.R2GC_246_44,(5,2,0):C.R2GC_240_32,(5,2,1):C.R2GC_240_33,(1,2,0):C.R2GC_240_32,(1,2,1):C.R2GC_240_33,(2,3,0):C.R2GC_242_36,(2,3,1):C.R2GC_242_37,(0,3,0):C.R2GC_242_36,(0,3,1):C.R2GC_242_37,(4,3,0):C.R2GC_240_32,(4,3,1):C.R2GC_240_33,(3,3,0):C.R2GC_240_32,(3,3,1):C.R2GC_240_33,(8,3,0):C.R2GC_241_34,(8,3,1):C.R2GC_276_58,(6,3,0):C.R2GC_245_41,(6,3,1):C.R2GC_245_42,(7,3,0):C.R2GC_275_57,(7,3,1):C.R2GC_242_37,(5,3,0):C.R2GC_240_32,(5,3,1):C.R2GC_240_33,(1,3,0):C.R2GC_240_32,(1,3,1):C.R2GC_240_33})

V_3 = CTVertex(name = 'V_3',
               type = 'R2',
               particles = [ P.t__tilde__, P.b, P.h__plus__ ],
               color = [ 'Identity(1,2)' ],
               lorentz = [ L.FFS3, L.FFS5 ],
               loop_particles = [ [ [P.b, P.g, P.t] ] ],
               couplings = {(0,0,0):C.R2GC_315_80,(0,1,0):C.R2GC_293_68})

V_4 = CTVertex(name = 'V_4',
               type = 'R2',
               particles = [ P.b__tilde__, P.t, P.h__minus__ ],
               color = [ 'Identity(1,2)' ],
               lorentz = [ L.FFS3, L.FFS5 ],
               loop_particles = [ [ [P.b, P.g, P.t] ] ],
               couplings = {(0,0,0):C.R2GC_293_68,(0,1,0):C.R2GC_315_80})

V_5 = CTVertex(name = 'V_5',
               type = 'R2',
               particles = [ P.t__tilde__, P.b, P.G__plus__ ],
               color = [ 'Identity(1,2)' ],
               lorentz = [ L.FFS3, L.FFS5 ],
               loop_particles = [ [ [P.b, P.g, P.t] ] ],
               couplings = {(0,0,0):C.R2GC_289_64,(0,1,0):C.R2GC_291_66})

V_6 = CTVertex(name = 'V_6',
               type = 'R2',
               particles = [ P.b__tilde__, P.b, P.G0 ],
               color = [ 'Identity(1,2)' ],
               lorentz = [ L.FFS1 ],
               loop_particles = [ [ [P.b, P.g] ] ],
               couplings = {(0,0,0):C.R2GC_270_49})

V_7 = CTVertex(name = 'V_7',
               type = 'R2',
               particles = [ P.t__tilde__, P.t, P.G0 ],
               color = [ 'Identity(1,2)' ],
               lorentz = [ L.FFS1 ],
               loop_particles = [ [ [P.g, P.t] ] ],
               couplings = {(0,0,0):C.R2GC_290_65})

V_8 = CTVertex(name = 'V_8',
               type = 'R2',
               particles = [ P.b__tilde__, P.t, P.G__minus__ ],
               color = [ 'Identity(1,2)' ],
               lorentz = [ L.FFS3, L.FFS5 ],
               loop_particles = [ [ [P.b, P.g, P.t] ] ],
               couplings = {(0,0,0):C.R2GC_292_67,(0,1,0):C.R2GC_288_63})

V_9 = CTVertex(name = 'V_9',
               type = 'R2',
               particles = [ P.b__tilde__, P.b, P.h1 ],
               color = [ 'Identity(1,2)' ],
               lorentz = [ L.FFS2 ],
               loop_particles = [ [ [P.b, P.g] ] ],
               couplings = {(0,0,0):C.R2GC_308_76})

V_10 = CTVertex(name = 'V_10',
                type = 'R2',
                particles = [ P.t__tilde__, P.t, P.h1 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS2 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_229_29})

V_11 = CTVertex(name = 'V_11',
                type = 'R2',
                particles = [ P.b__tilde__, P.b, P.h2 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS2 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_309_77})

V_12 = CTVertex(name = 'V_12',
                type = 'R2',
                particles = [ P.t__tilde__, P.t, P.h2 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS2 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_230_30})

V_13 = CTVertex(name = 'V_13',
                type = 'R2',
                particles = [ P.t__tilde__, P.t, P.h3 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS1 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_210_5})

V_14 = CTVertex(name = 'V_14',
                type = 'R2',
                particles = [ P.b__tilde__, P.b, P.h3 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS1 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_300_69})

V_15 = CTVertex(name = 'V_15',
                type = 'R2',
                particles = [ P.u__tilde__, P.u, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.g, P.u] ] ],
                couplings = {(0,0,0):C.R2GC_223_25,(0,1,0):C.R2GC_204_1})

V_16 = CTVertex(name = 'V_16',
                type = 'R2',
                particles = [ P.c__tilde__, P.c, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.c, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_223_25,(0,1,0):C.R2GC_204_1})

V_17 = CTVertex(name = 'V_17',
                type = 'R2',
                particles = [ P.t__tilde__, P.t, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_223_25,(0,1,0):C.R2GC_204_1})

V_18 = CTVertex(name = 'V_18',
                type = 'R2',
                particles = [ P.u__tilde__, P.u, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.g, P.u] ] ],
                couplings = {(0,0,0):C.R2GC_247_45})

V_19 = CTVertex(name = 'V_19',
                type = 'R2',
                particles = [ P.c__tilde__, P.c, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.c, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_247_45})

V_20 = CTVertex(name = 'V_20',
                type = 'R2',
                particles = [ P.t__tilde__, P.t, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_247_45})

V_21 = CTVertex(name = 'V_21',
                type = 'R2',
                particles = [ P.d__tilde__, P.u, P.W__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.d, P.g, P.u] ] ],
                couplings = {(0,0,0):C.R2GC_261_47})

V_22 = CTVertex(name = 'V_22',
                type = 'R2',
                particles = [ P.s__tilde__, P.c, P.W__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.c, P.g, P.s] ] ],
                couplings = {(0,0,0):C.R2GC_261_47})

V_23 = CTVertex(name = 'V_23',
                type = 'R2',
                particles = [ P.b__tilde__, P.t, P.W__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.b, P.g, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_261_47})

V_24 = CTVertex(name = 'V_24',
                type = 'R2',
                particles = [ P.u__tilde__, P.u, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.g, P.u] ] ],
                couplings = {(0,0,0):C.R2GC_222_24,(0,1,0):C.R2GC_205_2})

V_25 = CTVertex(name = 'V_25',
                type = 'R2',
                particles = [ P.c__tilde__, P.c, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.c, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_222_24,(0,1,0):C.R2GC_205_2})

V_26 = CTVertex(name = 'V_26',
                type = 'R2',
                particles = [ P.t__tilde__, P.t, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_222_24,(0,1,0):C.R2GC_205_2})

V_27 = CTVertex(name = 'V_27',
                type = 'R2',
                particles = [ P.d__tilde__, P.d, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.d, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_225_27,(0,1,0):C.R2GC_206_3})

V_28 = CTVertex(name = 'V_28',
                type = 'R2',
                particles = [ P.s__tilde__, P.s, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.g, P.s] ] ],
                couplings = {(0,0,0):C.R2GC_225_27,(0,1,0):C.R2GC_206_3})

V_29 = CTVertex(name = 'V_29',
                type = 'R2',
                particles = [ P.b__tilde__, P.b, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_225_27,(0,1,0):C.R2GC_206_3})

V_30 = CTVertex(name = 'V_30',
                type = 'R2',
                particles = [ P.d__tilde__, P.d, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.d, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_247_45})

V_31 = CTVertex(name = 'V_31',
                type = 'R2',
                particles = [ P.s__tilde__, P.s, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.g, P.s] ] ],
                couplings = {(0,0,0):C.R2GC_247_45})

V_32 = CTVertex(name = 'V_32',
                type = 'R2',
                particles = [ P.b__tilde__, P.b, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_247_45})

V_33 = CTVertex(name = 'V_33',
                type = 'R2',
                particles = [ P.u__tilde__, P.d, P.W__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.d, P.g, P.u] ] ],
                couplings = {(0,0,0):C.R2GC_261_47})

V_34 = CTVertex(name = 'V_34',
                type = 'R2',
                particles = [ P.c__tilde__, P.s, P.W__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.c, P.g, P.s] ] ],
                couplings = {(0,0,0):C.R2GC_261_47})

V_35 = CTVertex(name = 'V_35',
                type = 'R2',
                particles = [ P.t__tilde__, P.b, P.W__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.b, P.g, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_261_47})

V_36 = CTVertex(name = 'V_36',
                type = 'R2',
                particles = [ P.d__tilde__, P.d, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.d, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_224_26,(0,1,0):C.R2GC_207_4})

V_37 = CTVertex(name = 'V_37',
                type = 'R2',
                particles = [ P.s__tilde__, P.s, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.g, P.s] ] ],
                couplings = {(0,0,0):C.R2GC_224_26,(0,1,0):C.R2GC_207_4})

V_38 = CTVertex(name = 'V_38',
                type = 'R2',
                particles = [ P.b__tilde__, P.b, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_224_26,(0,1,0):C.R2GC_207_4})

V_39 = CTVertex(name = 'V_39',
                type = 'R2',
                particles = [ P.u__tilde__, P.u ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF1 ],
                loop_particles = [ [ [P.g, P.u] ] ],
                couplings = {(0,0,0):C.R2GC_248_46})

V_40 = CTVertex(name = 'V_40',
                type = 'R2',
                particles = [ P.c__tilde__, P.c ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF1 ],
                loop_particles = [ [ [P.c, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_248_46})

V_41 = CTVertex(name = 'V_41',
                type = 'R2',
                particles = [ P.t__tilde__, P.t ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF2, L.FF3, L.FF4, L.FF5 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_284_62,(0,2,0):C.R2GC_284_62,(0,1,0):C.R2GC_248_46,(0,3,0):C.R2GC_248_46})

V_42 = CTVertex(name = 'V_42',
                type = 'R2',
                particles = [ P.d__tilde__, P.d ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF1 ],
                loop_particles = [ [ [P.d, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_248_46})

V_43 = CTVertex(name = 'V_43',
                type = 'R2',
                particles = [ P.s__tilde__, P.s ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF1 ],
                loop_particles = [ [ [P.g, P.s] ] ],
                couplings = {(0,0,0):C.R2GC_248_46})

V_44 = CTVertex(name = 'V_44',
                type = 'R2',
                particles = [ P.b__tilde__, P.b ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF2, L.FF3, L.FF4, L.FF5 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_266_48,(0,2,0):C.R2GC_266_48,(0,1,0):C.R2GC_248_46,(0,3,0):C.R2GC_248_46})

V_45 = CTVertex(name = 'V_45',
                type = 'R2',
                particles = [ P.g, P.g ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VV1, L.VV2, L.VV3 ],
                loop_particles = [ [ [P.b] ], [ [P.b], [P.c], [P.d], [P.s], [P.t], [P.u] ], [ [P.g] ], [ [P.t] ] ],
                couplings = {(0,0,2):C.R2GC_272_52,(0,1,0):C.R2GC_213_6,(0,1,3):C.R2GC_213_7,(0,2,1):C.R2GC_271_50,(0,2,2):C.R2GC_271_51})

V_46 = CTVertex(name = 'V_46',
                type = 'R2',
                particles = [ P.g, P.g, P.h1 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVS1 ],
                loop_particles = [ [ [P.b] ], [ [P.t] ] ],
                couplings = {(0,0,0):C.R2GC_306_72,(0,0,1):C.R2GC_306_73})

V_47 = CTVertex(name = 'V_47',
                type = 'R2',
                particles = [ P.g, P.g, P.h2 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVS1 ],
                loop_particles = [ [ [P.b] ], [ [P.t] ] ],
                couplings = {(0,0,0):C.R2GC_307_74,(0,0,1):C.R2GC_307_75})

V_48 = CTVertex(name = 'V_48',
                type = 'R2',
                particles = [ P.g, P.g, P.W__minus__, P.W__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVVV2, L.VVVV3, L.VVVV5 ],
                loop_particles = [ [ [P.b, P.t], [P.c, P.s], [P.d, P.u] ] ],
                couplings = {(0,0,0):C.R2GC_231_31,(0,1,0):C.R2GC_231_31,(0,2,0):C.R2GC_231_31})

V_49 = CTVertex(name = 'V_49',
                type = 'R2',
                particles = [ P.g, P.g, P.Z, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVVV2, L.VVVV3, L.VVVV5 ],
                loop_particles = [ [ [P.b], [P.d], [P.s] ], [ [P.c], [P.t], [P.u] ] ],
                couplings = {(0,0,0):C.R2GC_219_18,(0,0,1):C.R2GC_219_19,(0,1,0):C.R2GC_219_18,(0,1,1):C.R2GC_219_19,(0,2,0):C.R2GC_219_18,(0,2,1):C.R2GC_219_19})

V_50 = CTVertex(name = 'V_50',
                type = 'R2',
                particles = [ P.a, P.g, P.g, P.Z ],
                color = [ 'Identity(2,3)' ],
                lorentz = [ L.VVVV2, L.VVVV3, L.VVVV5 ],
                loop_particles = [ [ [P.b], [P.d], [P.s] ], [ [P.c], [P.t], [P.u] ] ],
                couplings = {(0,0,0):C.R2GC_220_20,(0,0,1):C.R2GC_220_21,(0,1,0):C.R2GC_220_20,(0,1,1):C.R2GC_220_21,(0,2,0):C.R2GC_220_20,(0,2,1):C.R2GC_220_21})

V_51 = CTVertex(name = 'V_51',
                type = 'R2',
                particles = [ P.a, P.a, P.g, P.g ],
                color = [ 'Identity(3,4)' ],
                lorentz = [ L.VVVV2, L.VVVV3, L.VVVV5 ],
                loop_particles = [ [ [P.b], [P.d], [P.s] ], [ [P.c], [P.t], [P.u] ] ],
                couplings = {(0,0,0):C.R2GC_221_22,(0,0,1):C.R2GC_221_23,(0,1,0):C.R2GC_221_22,(0,1,1):C.R2GC_221_23,(0,2,0):C.R2GC_221_22,(0,2,1):C.R2GC_221_23})

V_52 = CTVertex(name = 'V_52',
                type = 'R2',
                particles = [ P.g, P.g, P.g, P.Z ],
                color = [ 'd(1,2,3)', 'f(1,2,3)' ],
                lorentz = [ L.VVVV1, L.VVVV2, L.VVVV3, L.VVVV5 ],
                loop_particles = [ [ [P.b], [P.d], [P.s] ], [ [P.c], [P.t], [P.u] ] ],
                couplings = {(1,0,0):C.R2GC_216_12,(1,0,1):C.R2GC_216_13,(0,1,0):C.R2GC_215_10,(0,1,1):C.R2GC_215_11,(0,2,0):C.R2GC_215_10,(0,2,1):C.R2GC_215_11,(0,3,0):C.R2GC_215_10,(0,3,1):C.R2GC_215_11})

V_53 = CTVertex(name = 'V_53',
                type = 'R2',
                particles = [ P.a, P.g, P.g, P.g ],
                color = [ 'd(2,3,4)', 'f(2,3,4)' ],
                lorentz = [ L.VVVV1, L.VVVV2, L.VVVV3, L.VVVV5 ],
                loop_particles = [ [ [P.b], [P.d], [P.s] ], [ [P.c], [P.t], [P.u] ] ],
                couplings = {(1,0,0):C.R2GC_218_16,(1,0,1):C.R2GC_218_17,(0,1,0):C.R2GC_217_14,(0,1,1):C.R2GC_217_15,(0,2,0):C.R2GC_217_14,(0,2,1):C.R2GC_217_15,(0,3,0):C.R2GC_217_14,(0,3,1):C.R2GC_217_15})

V_54 = CTVertex(name = 'V_54',
                type = 'R2',
                particles = [ P.g, P.g, P.G0, P.G0 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVSS1 ],
                loop_particles = [ [ [P.b] ], [ [P.t] ] ],
                couplings = {(0,0,0):C.R2GC_214_8,(0,0,1):C.R2GC_214_9})

V_55 = CTVertex(name = 'V_55',
                type = 'R2',
                particles = [ P.g, P.g, P.G__minus__, P.G__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVSS1 ],
                loop_particles = [ [ [P.b, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_228_28})

V_56 = CTVertex(name = 'V_56',
                type = 'R2',
                particles = [ P.g, P.g, P.G__minus__, P.h__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVSS1 ],
                loop_particles = [ [ [P.b, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_310_78})

V_57 = CTVertex(name = 'V_57',
                type = 'R2',
                particles = [ P.g, P.g, P.G__plus__, P.h__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVSS1 ],
                loop_particles = [ [ [P.b, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_311_79})

V_58 = CTVertex(name = 'V_58',
                type = 'R2',
                particles = [ P.g, P.g, P.h__minus__, P.h__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVSS1 ],
                loop_particles = [ [ [P.b, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_320_89})

V_59 = CTVertex(name = 'V_59',
                type = 'R2',
                particles = [ P.g, P.g, P.h1, P.h1 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVSS1 ],
                loop_particles = [ [ [P.b] ], [ [P.t] ] ],
                couplings = {(0,0,0):C.R2GC_316_81,(0,0,1):C.R2GC_316_82})

V_60 = CTVertex(name = 'V_60',
                type = 'R2',
                particles = [ P.g, P.g, P.h1, P.h2 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVSS1 ],
                loop_particles = [ [ [P.b] ], [ [P.t] ] ],
                couplings = {(0,0,0):C.R2GC_317_83,(0,0,1):C.R2GC_317_84})

V_61 = CTVertex(name = 'V_61',
                type = 'R2',
                particles = [ P.g, P.g, P.h2, P.h2 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVSS1 ],
                loop_particles = [ [ [P.b] ], [ [P.t] ] ],
                couplings = {(0,0,0):C.R2GC_318_85,(0,0,1):C.R2GC_318_86})

V_62 = CTVertex(name = 'V_62',
                type = 'R2',
                particles = [ P.g, P.g, P.G0, P.h3 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVSS1 ],
                loop_particles = [ [ [P.b] ], [ [P.t] ] ],
                couplings = {(0,0,0):C.R2GC_305_70,(0,0,1):C.R2GC_305_71})

V_63 = CTVertex(name = 'V_63',
                type = 'R2',
                particles = [ P.g, P.g, P.h3, P.h3 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVSS1 ],
                loop_particles = [ [ [P.b] ], [ [P.t] ] ],
                couplings = {(0,0,0):C.R2GC_319_87,(0,0,1):C.R2GC_319_88})

V_64 = CTVertex(name = 'V_64',
                type = 'UV',
                particles = [ P.g, P.g, P.g ],
                color = [ 'f(1,2,3)' ],
                lorentz = [ L.VVV1, L.VVV2, L.VVV3 ],
                loop_particles = [ [ [P.b] ], [ [P.c], [P.d], [P.s], [P.u] ], [ [P.g] ], [ [P.ghG] ], [ [P.t] ] ],
                couplings = {(0,1,0):C.UVGC_273_40,(0,1,1):C.UVGC_273_41,(0,1,4):C.UVGC_273_42,(0,2,2):C.UVGC_234_1,(0,0,3):C.UVGC_235_2})

V_65 = CTVertex(name = 'V_65',
                type = 'UV',
                particles = [ P.g, P.g, P.g, P.g ],
                color = [ 'd(-1,1,3)*d(-1,2,4)', 'd(-1,1,3)*f(-1,2,4)', 'd(-1,1,4)*d(-1,2,3)', 'd(-1,1,4)*f(-1,2,3)', 'd(-1,2,3)*f(-1,1,4)', 'd(-1,2,4)*f(-1,1,3)', 'f(-1,1,2)*f(-1,3,4)', 'f(-1,1,3)*f(-1,2,4)', 'f(-1,1,4)*f(-1,2,3)', 'Identity(1,2)*Identity(3,4)', 'Identity(1,3)*Identity(2,4)', 'Identity(1,4)*Identity(2,3)' ],
                lorentz = [ L.VVVV10, L.VVVV2, L.VVVV3, L.VVVV5 ],
                loop_particles = [ [ [P.b] ], [ [P.b], [P.c], [P.d], [P.s], [P.t], [P.u] ], [ [P.c], [P.d], [P.s], [P.u] ], [ [P.g] ], [ [P.ghG] ], [ [P.t] ] ],
                couplings = {(2,1,3):C.UVGC_241_7,(2,1,4):C.UVGC_241_6,(0,1,3):C.UVGC_241_7,(0,1,4):C.UVGC_241_6,(4,1,3):C.UVGC_240_4,(4,1,4):C.UVGC_240_5,(3,1,3):C.UVGC_240_4,(3,1,4):C.UVGC_240_5,(8,1,3):C.UVGC_241_6,(8,1,4):C.UVGC_241_7,(7,1,0):C.UVGC_277_54,(7,1,2):C.UVGC_277_55,(7,1,3):C.UVGC_277_56,(7,1,4):C.UVGC_277_57,(7,1,5):C.UVGC_277_58,(6,1,0):C.UVGC_277_54,(6,1,2):C.UVGC_277_55,(6,1,3):C.UVGC_278_59,(6,1,4):C.UVGC_278_60,(6,1,5):C.UVGC_277_58,(5,1,3):C.UVGC_240_4,(5,1,4):C.UVGC_240_5,(1,1,3):C.UVGC_240_4,(1,1,4):C.UVGC_240_5,(11,0,3):C.UVGC_244_10,(11,0,4):C.UVGC_244_11,(10,0,3):C.UVGC_244_10,(10,0,4):C.UVGC_244_11,(9,0,3):C.UVGC_243_8,(9,0,4):C.UVGC_243_9,(2,2,3):C.UVGC_241_7,(2,2,4):C.UVGC_241_6,(0,2,3):C.UVGC_241_7,(0,2,4):C.UVGC_241_6,(6,2,0):C.UVGC_274_43,(6,2,3):C.UVGC_274_44,(6,2,4):C.UVGC_274_45,(6,2,5):C.UVGC_274_46,(4,2,3):C.UVGC_240_4,(4,2,4):C.UVGC_240_5,(3,2,3):C.UVGC_240_4,(3,2,4):C.UVGC_240_5,(8,2,0):C.UVGC_279_61,(8,2,2):C.UVGC_279_62,(8,2,3):C.UVGC_279_63,(8,2,4):C.UVGC_279_64,(8,2,5):C.UVGC_279_65,(7,2,1):C.UVGC_245_12,(7,2,3):C.UVGC_246_14,(7,2,4):C.UVGC_246_15,(5,2,3):C.UVGC_240_4,(5,2,4):C.UVGC_240_5,(1,2,3):C.UVGC_240_4,(1,2,4):C.UVGC_240_5,(2,3,3):C.UVGC_241_7,(2,3,4):C.UVGC_241_6,(0,3,3):C.UVGC_241_7,(0,3,4):C.UVGC_241_6,(4,3,3):C.UVGC_240_4,(4,3,4):C.UVGC_240_5,(3,3,3):C.UVGC_240_4,(3,3,4):C.UVGC_240_5,(8,3,0):C.UVGC_276_49,(8,3,2):C.UVGC_276_50,(8,3,3):C.UVGC_276_51,(8,3,4):C.UVGC_276_52,(8,3,5):C.UVGC_276_53,(6,3,1):C.UVGC_245_12,(6,3,3):C.UVGC_245_13,(6,3,4):C.UVGC_243_8,(7,3,0):C.UVGC_274_43,(7,3,3):C.UVGC_275_47,(7,3,4):C.UVGC_275_48,(7,3,5):C.UVGC_274_46,(5,3,3):C.UVGC_240_4,(5,3,4):C.UVGC_240_5,(1,3,3):C.UVGC_240_4,(1,3,4):C.UVGC_240_5})

V_66 = CTVertex(name = 'V_66',
                type = 'UV',
                particles = [ P.t__tilde__, P.b, P.h__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS3, L.FFS5 ],
                loop_particles = [ [ [P.b, P.g] ], [ [P.b, P.g, P.t] ], [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_315_97,(0,0,2):C.UVGC_315_98,(0,0,1):C.UVGC_315_99,(0,1,0):C.UVGC_293_88,(0,1,2):C.UVGC_293_89,(0,1,1):C.UVGC_293_90})

V_67 = CTVertex(name = 'V_67',
                type = 'UV',
                particles = [ P.b__tilde__, P.t, P.h__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS3, L.FFS5 ],
                loop_particles = [ [ [P.b, P.g] ], [ [P.b, P.g, P.t] ], [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_293_88,(0,0,2):C.UVGC_293_89,(0,0,1):C.UVGC_293_90,(0,1,0):C.UVGC_315_97,(0,1,2):C.UVGC_315_98,(0,1,1):C.UVGC_315_99})

V_68 = CTVertex(name = 'V_68',
                type = 'UV',
                particles = [ P.t__tilde__, P.b, P.G__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS3, L.FFS5 ],
                loop_particles = [ [ [P.b, P.g] ], [ [P.b, P.g, P.t] ], [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_289_78,(0,0,2):C.UVGC_289_79,(0,0,1):C.UVGC_289_80,(0,1,0):C.UVGC_291_82,(0,1,2):C.UVGC_291_83,(0,1,1):C.UVGC_291_84})

V_69 = CTVertex(name = 'V_69',
                type = 'UV',
                particles = [ P.b__tilde__, P.b, P.G0 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS1 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_270_33})

V_70 = CTVertex(name = 'V_70',
                type = 'UV',
                particles = [ P.t__tilde__, P.t, P.G0 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS1 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_290_81})

V_71 = CTVertex(name = 'V_71',
                type = 'UV',
                particles = [ P.b__tilde__, P.t, P.G__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS3, L.FFS5 ],
                loop_particles = [ [ [P.b, P.g] ], [ [P.b, P.g, P.t] ], [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_292_85,(0,0,2):C.UVGC_292_86,(0,0,1):C.UVGC_292_87,(0,1,0):C.UVGC_288_75,(0,1,2):C.UVGC_288_76,(0,1,1):C.UVGC_288_77})

V_72 = CTVertex(name = 'V_72',
                type = 'UV',
                particles = [ P.b__tilde__, P.b, P.h1 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS6 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_312_94})

V_73 = CTVertex(name = 'V_73',
                type = 'UV',
                particles = [ P.t__tilde__, P.t, P.h1 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS6 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_294_91})

V_74 = CTVertex(name = 'V_74',
                type = 'UV',
                particles = [ P.b__tilde__, P.b, P.h2 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS6 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_313_95})

V_75 = CTVertex(name = 'V_75',
                type = 'UV',
                particles = [ P.t__tilde__, P.t, P.h2 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS6 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_295_92})

V_76 = CTVertex(name = 'V_76',
                type = 'UV',
                particles = [ P.t__tilde__, P.t, P.h3 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS4 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_296_93})

V_77 = CTVertex(name = 'V_77',
                type = 'UV',
                particles = [ P.b__tilde__, P.b, P.h3 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS4 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_314_96})

V_78 = CTVertex(name = 'V_78',
                type = 'UV',
                particles = [ P.t__tilde__, P.t, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_287_74,(0,1,0):C.UVGC_282_68})

V_79 = CTVertex(name = 'V_79',
                type = 'UV',
                particles = [ P.u__tilde__, P.u, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1, L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.b] ], [ [P.c], [P.d], [P.s], [P.u] ], [ [P.g] ], [ [P.ghG] ], [ [P.g, P.u] ], [ [P.t] ] ],
                couplings = {(0,0,4):C.UVGC_247_16,(0,1,0):C.UVGC_249_18,(0,1,1):C.UVGC_249_19,(0,1,2):C.UVGC_249_20,(0,1,3):C.UVGC_249_21,(0,1,5):C.UVGC_249_22,(0,1,4):C.UVGC_249_23,(0,2,0):C.UVGC_249_18,(0,2,1):C.UVGC_249_19,(0,2,2):C.UVGC_249_20,(0,2,3):C.UVGC_249_21,(0,2,5):C.UVGC_249_22,(0,2,4):C.UVGC_249_23})

V_80 = CTVertex(name = 'V_80',
                type = 'UV',
                particles = [ P.c__tilde__, P.c, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1, L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.b] ], [ [P.c], [P.d], [P.s], [P.u] ], [ [P.c, P.g] ], [ [P.g] ], [ [P.ghG] ], [ [P.t] ] ],
                couplings = {(0,0,2):C.UVGC_247_16,(0,1,0):C.UVGC_249_18,(0,1,1):C.UVGC_249_19,(0,1,3):C.UVGC_249_20,(0,1,4):C.UVGC_249_21,(0,1,5):C.UVGC_249_22,(0,1,2):C.UVGC_249_23,(0,2,0):C.UVGC_249_18,(0,2,1):C.UVGC_249_19,(0,2,3):C.UVGC_249_20,(0,2,4):C.UVGC_249_21,(0,2,5):C.UVGC_249_22,(0,2,2):C.UVGC_249_23})

V_81 = CTVertex(name = 'V_81',
                type = 'UV',
                particles = [ P.t__tilde__, P.t, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1, L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.b] ], [ [P.c], [P.d], [P.s], [P.u] ], [ [P.g] ], [ [P.ghG] ], [ [P.g, P.t] ], [ [P.t] ] ],
                couplings = {(0,0,4):C.UVGC_247_16,(0,1,0):C.UVGC_249_18,(0,1,1):C.UVGC_249_19,(0,1,2):C.UVGC_249_20,(0,1,3):C.UVGC_249_21,(0,1,5):C.UVGC_249_22,(0,1,4):C.UVGC_281_67,(0,2,0):C.UVGC_249_18,(0,2,1):C.UVGC_249_19,(0,2,2):C.UVGC_249_20,(0,2,3):C.UVGC_249_21,(0,2,5):C.UVGC_249_22,(0,2,4):C.UVGC_281_67})

V_82 = CTVertex(name = 'V_82',
                type = 'UV',
                particles = [ P.d__tilde__, P.u, P.W__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.d, P.g], [P.g, P.u] ], [ [P.d, P.g, P.u] ] ],
                couplings = {(0,0,0):C.UVGC_261_24,(0,0,1):C.UVGC_261_25})

V_83 = CTVertex(name = 'V_83',
                type = 'UV',
                particles = [ P.s__tilde__, P.c, P.W__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.c, P.g], [P.g, P.s] ], [ [P.c, P.g, P.s] ] ],
                couplings = {(0,0,0):C.UVGC_261_24,(0,0,1):C.UVGC_261_25})

V_84 = CTVertex(name = 'V_84',
                type = 'UV',
                particles = [ P.b__tilde__, P.t, P.W__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.b, P.g] ], [ [P.b, P.g, P.t] ], [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_283_69,(0,0,2):C.UVGC_283_70,(0,0,1):C.UVGC_261_25})

V_85 = CTVertex(name = 'V_85',
                type = 'UV',
                particles = [ P.t__tilde__, P.t, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_285_72,(0,1,0):C.UVGC_286_73})

V_86 = CTVertex(name = 'V_86',
                type = 'UV',
                particles = [ P.b__tilde__, P.b, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_269_32,(0,1,0):C.UVGC_265_28})

V_87 = CTVertex(name = 'V_87',
                type = 'UV',
                particles = [ P.d__tilde__, P.d, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1, L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.b] ], [ [P.c], [P.d], [P.s], [P.u] ], [ [P.d, P.g] ], [ [P.g] ], [ [P.ghG] ], [ [P.t] ] ],
                couplings = {(0,0,2):C.UVGC_247_16,(0,1,0):C.UVGC_249_18,(0,1,1):C.UVGC_249_19,(0,1,3):C.UVGC_249_20,(0,1,4):C.UVGC_249_21,(0,1,5):C.UVGC_249_22,(0,1,2):C.UVGC_249_23,(0,2,0):C.UVGC_249_18,(0,2,1):C.UVGC_249_19,(0,2,3):C.UVGC_249_20,(0,2,4):C.UVGC_249_21,(0,2,5):C.UVGC_249_22,(0,2,2):C.UVGC_249_23})

V_88 = CTVertex(name = 'V_88',
                type = 'UV',
                particles = [ P.s__tilde__, P.s, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1, L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.b] ], [ [P.c], [P.d], [P.s], [P.u] ], [ [P.g] ], [ [P.ghG] ], [ [P.g, P.s] ], [ [P.t] ] ],
                couplings = {(0,0,4):C.UVGC_247_16,(0,1,0):C.UVGC_249_18,(0,1,1):C.UVGC_249_19,(0,1,2):C.UVGC_249_20,(0,1,3):C.UVGC_249_21,(0,1,5):C.UVGC_249_22,(0,1,4):C.UVGC_249_23,(0,2,0):C.UVGC_249_18,(0,2,1):C.UVGC_249_19,(0,2,2):C.UVGC_249_20,(0,2,3):C.UVGC_249_21,(0,2,5):C.UVGC_249_22,(0,2,4):C.UVGC_249_23})

V_89 = CTVertex(name = 'V_89',
                type = 'UV',
                particles = [ P.b__tilde__, P.b, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1, L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.b] ], [ [P.b, P.g] ], [ [P.c], [P.d], [P.s], [P.u] ], [ [P.g] ], [ [P.ghG] ], [ [P.t] ] ],
                couplings = {(0,0,1):C.UVGC_247_16,(0,1,0):C.UVGC_249_18,(0,1,2):C.UVGC_249_19,(0,1,3):C.UVGC_249_20,(0,1,4):C.UVGC_249_21,(0,1,5):C.UVGC_249_22,(0,1,1):C.UVGC_264_27,(0,2,0):C.UVGC_249_18,(0,2,2):C.UVGC_249_19,(0,2,3):C.UVGC_249_20,(0,2,4):C.UVGC_249_21,(0,2,5):C.UVGC_249_22,(0,2,1):C.UVGC_264_27})

V_90 = CTVertex(name = 'V_90',
                type = 'UV',
                particles = [ P.u__tilde__, P.d, P.W__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.d, P.g], [P.g, P.u] ], [ [P.d, P.g, P.u] ] ],
                couplings = {(0,0,0):C.UVGC_261_24,(0,0,1):C.UVGC_261_25})

V_91 = CTVertex(name = 'V_91',
                type = 'UV',
                particles = [ P.c__tilde__, P.s, P.W__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.c, P.g], [P.g, P.s] ], [ [P.c, P.g, P.s] ] ],
                couplings = {(0,0,0):C.UVGC_261_24,(0,0,1):C.UVGC_261_25})

V_92 = CTVertex(name = 'V_92',
                type = 'UV',
                particles = [ P.t__tilde__, P.b, P.W__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.b, P.g] ], [ [P.b, P.g, P.t] ], [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_283_69,(0,0,2):C.UVGC_283_70,(0,0,1):C.UVGC_261_25})

V_93 = CTVertex(name = 'V_93',
                type = 'UV',
                particles = [ P.b__tilde__, P.b, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_267_30,(0,1,0):C.UVGC_268_31})

V_94 = CTVertex(name = 'V_94',
                type = 'UV',
                particles = [ P.u__tilde__, P.u ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF1, L.FF3, L.FF5 ],
                loop_particles = [ [ [P.g, P.u] ] ],
                couplings = {(0,0,0):C.UVGC_248_17,(0,1,0):C.UVGC_236_3,(0,2,0):C.UVGC_236_3})

V_95 = CTVertex(name = 'V_95',
                type = 'UV',
                particles = [ P.c__tilde__, P.c ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF1, L.FF3, L.FF5 ],
                loop_particles = [ [ [P.c, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_248_17,(0,1,0):C.UVGC_236_3,(0,2,0):C.UVGC_236_3})

V_96 = CTVertex(name = 'V_96',
                type = 'UV',
                particles = [ P.t__tilde__, P.t ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF2, L.FF3, L.FF4, L.FF5 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_284_71,(0,2,0):C.UVGC_284_71,(0,1,0):C.UVGC_280_66,(0,3,0):C.UVGC_280_66})

V_97 = CTVertex(name = 'V_97',
                type = 'UV',
                particles = [ P.d__tilde__, P.d ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF1, L.FF3, L.FF5 ],
                loop_particles = [ [ [P.d, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_248_17,(0,1,0):C.UVGC_236_3,(0,2,0):C.UVGC_236_3})

V_98 = CTVertex(name = 'V_98',
                type = 'UV',
                particles = [ P.s__tilde__, P.s ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF1, L.FF3, L.FF5 ],
                loop_particles = [ [ [P.g, P.s] ] ],
                couplings = {(0,0,0):C.UVGC_248_17,(0,1,0):C.UVGC_236_3,(0,2,0):C.UVGC_236_3})

V_99 = CTVertex(name = 'V_99',
                type = 'UV',
                particles = [ P.b__tilde__, P.b ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF2, L.FF3, L.FF4, L.FF5 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_266_29,(0,2,0):C.UVGC_266_29,(0,1,0):C.UVGC_263_26,(0,3,0):C.UVGC_263_26})

V_100 = CTVertex(name = 'V_100',
                 type = 'UV',
                 particles = [ P.g, P.g ],
                 color = [ 'Identity(1,2)' ],
                 lorentz = [ L.VV1, L.VV3 ],
                 loop_particles = [ [ [P.b] ], [ [P.g] ], [ [P.ghG] ], [ [P.t] ] ],
                 couplings = {(0,0,0):C.UVGC_272_36,(0,0,1):C.UVGC_272_37,(0,0,2):C.UVGC_272_38,(0,0,3):C.UVGC_272_39,(0,1,0):C.UVGC_271_34,(0,1,3):C.UVGC_271_35})

