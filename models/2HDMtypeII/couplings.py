# This file was automatically created by FeynRules 2.1.67
# Mathematica version: 9.0 for Mac OS X x86 (64-bit) (January 24, 2013)
# Date: Wed 18 Jun 2014 10:44:39


from object_library import all_couplings, Coupling

from function_library import complexconjugate, re, im, csc, sec, acsc, asec, cot



GC_1 = Coupling(name = 'GC_1',
                value = '-G',
                order = {'QCD':1})

GC_10 = Coupling(name = 'GC_10',
                 value = '-(cw*complex(0,1)*gw)',
                 order = {'QED':1})

GC_100 = Coupling(name = 'GC_100',
                  value = '(cw**2*complex(0,1)*gw**2*TH1x1*TH1x2)/2. + cw*complex(0,1)*g1*gw*sw*TH1x1*TH1x2 + (complex(0,1)*g1**2*sw**2*TH1x1*TH1x2)/2. + (cw**2*complex(0,1)*gw**2*TH2x1*TH2x2)/2. + cw*complex(0,1)*g1*gw*sw*TH2x1*TH2x2 + (complex(0,1)*g1**2*sw**2*TH2x1*TH2x2)/2.',
                  order = {'QED':2})

GC_101 = Coupling(name = 'GC_101',
                  value = '-(cw**2*complex(0,1)*g1*gw*TH1x1*TH1x2)/2. - (cw*complex(0,1)*g1**2*sw*TH1x1*TH1x2)/2. + (cw*complex(0,1)*gw**2*sw*TH1x1*TH1x2)/2. + (complex(0,1)*g1*gw*sw**2*TH1x1*TH1x2)/2. - (cw**2*complex(0,1)*g1*gw*TH2x1*TH2x2)/2. - (cw*complex(0,1)*g1**2*sw*TH2x1*TH2x2)/2. + (cw*complex(0,1)*gw**2*sw*TH2x1*TH2x2)/2. + (complex(0,1)*g1*gw*sw**2*TH2x1*TH2x2)/2.',
                  order = {'QED':2})

GC_102 = Coupling(name = 'GC_102',
                  value = '(cw**2*complex(0,1)*g1**2*TH1x1*TH1x2)/2. - cw*complex(0,1)*g1*gw*sw*TH1x1*TH1x2 + (complex(0,1)*gw**2*sw**2*TH1x1*TH1x2)/2. + (cw**2*complex(0,1)*g1**2*TH2x1*TH2x2)/2. - cw*complex(0,1)*g1*gw*sw*TH2x1*TH2x2 + (complex(0,1)*gw**2*sw**2*TH2x1*TH2x2)/2.',
                  order = {'QED':2})

GC_103 = Coupling(name = 'GC_103',
                  value = '-6*complex(0,1)*l1*TH1x1**3*TH1x2 - 9*complex(0,1)*l6*TH1x1**2*TH1x2*TH2x1 - 3*complex(0,1)*l3*TH1x1*TH1x2*TH2x1**2 - 3*complex(0,1)*l4*TH1x1*TH1x2*TH2x1**2 - 6*complex(0,1)*l5*TH1x1*TH1x2*TH2x1**2 - 3*complex(0,1)*l7*TH1x2*TH2x1**3 - 3*complex(0,1)*l6*TH1x1**3*TH2x2 - 3*complex(0,1)*l3*TH1x1**2*TH2x1*TH2x2 - 3*complex(0,1)*l4*TH1x1**2*TH2x1*TH2x2 - 6*complex(0,1)*l5*TH1x1**2*TH2x1*TH2x2 - 9*complex(0,1)*l7*TH1x1*TH2x1**2*TH2x2 - 6*complex(0,1)*l2*TH2x1**3*TH2x2',
                  order = {'QED':2})

GC_104 = Coupling(name = 'GC_104',
                  value = '(complex(0,1)*gw**2*TH1x2**2)/2. + (complex(0,1)*gw**2*TH2x2**2)/2.',
                  order = {'QED':2})

GC_105 = Coupling(name = 'GC_105',
                  value = '-2*complex(0,1)*l6*TH1x2*TH2x2 - complex(0,1)*l3*TH2x2**2',
                  order = {'QED':2})

GC_106 = Coupling(name = 'GC_106',
                  value = '-2*complex(0,1)*l1*TH1x2**2 - 2*complex(0,1)*l6*TH1x2*TH2x2 - complex(0,1)*l3*TH2x2**2 - complex(0,1)*l4*TH2x2**2 + 2*complex(0,1)*l5*TH2x2**2',
                  order = {'QED':2})

GC_107 = Coupling(name = 'GC_107',
                  value = '-(l6*TH1x2**2) - l4*TH1x2*TH2x2 - l7*TH2x2**2',
                  order = {'QED':2})

GC_108 = Coupling(name = 'GC_108',
                  value = 'l6*TH1x2**2 + l4*TH1x2*TH2x2 + l7*TH2x2**2',
                  order = {'QED':2})

GC_109 = Coupling(name = 'GC_109',
                  value = '(cw**2*complex(0,1)*gw**2*TH1x2**2)/2. + cw*complex(0,1)*g1*gw*sw*TH1x2**2 + (complex(0,1)*g1**2*sw**2*TH1x2**2)/2. + (cw**2*complex(0,1)*gw**2*TH2x2**2)/2. + cw*complex(0,1)*g1*gw*sw*TH2x2**2 + (complex(0,1)*g1**2*sw**2*TH2x2**2)/2.',
                  order = {'QED':2})

GC_11 = Coupling(name = 'GC_11',
                 value = 'cw*complex(0,1)*gw',
                 order = {'QED':1})

GC_110 = Coupling(name = 'GC_110',
                  value = '-(cw**2*complex(0,1)*g1*gw*TH1x2**2)/2. - (cw*complex(0,1)*g1**2*sw*TH1x2**2)/2. + (cw*complex(0,1)*gw**2*sw*TH1x2**2)/2. + (complex(0,1)*g1*gw*sw**2*TH1x2**2)/2. - (cw**2*complex(0,1)*g1*gw*TH2x2**2)/2. - (cw*complex(0,1)*g1**2*sw*TH2x2**2)/2. + (cw*complex(0,1)*gw**2*sw*TH2x2**2)/2. + (complex(0,1)*g1*gw*sw**2*TH2x2**2)/2.',
                  order = {'QED':2})

GC_111 = Coupling(name = 'GC_111',
                  value = '(cw**2*complex(0,1)*g1**2*TH1x2**2)/2. - cw*complex(0,1)*g1*gw*sw*TH1x2**2 + (complex(0,1)*gw**2*sw**2*TH1x2**2)/2. + (cw**2*complex(0,1)*g1**2*TH2x2**2)/2. - cw*complex(0,1)*g1*gw*sw*TH2x2**2 + (complex(0,1)*gw**2*sw**2*TH2x2**2)/2.',
                  order = {'QED':2})

GC_112 = Coupling(name = 'GC_112',
                  value = '-6*complex(0,1)*l1*TH1x1**2*TH1x2**2 - 6*complex(0,1)*l6*TH1x1*TH1x2**2*TH2x1 - complex(0,1)*l3*TH1x2**2*TH2x1**2 - complex(0,1)*l4*TH1x2**2*TH2x1**2 - 2*complex(0,1)*l5*TH1x2**2*TH2x1**2 - 6*complex(0,1)*l6*TH1x1**2*TH1x2*TH2x2 - 4*complex(0,1)*l3*TH1x1*TH1x2*TH2x1*TH2x2 - 4*complex(0,1)*l4*TH1x1*TH1x2*TH2x1*TH2x2 - 8*complex(0,1)*l5*TH1x1*TH1x2*TH2x1*TH2x2 - 6*complex(0,1)*l7*TH1x2*TH2x1**2*TH2x2 - complex(0,1)*l3*TH1x1**2*TH2x2**2 - complex(0,1)*l4*TH1x1**2*TH2x2**2 - 2*complex(0,1)*l5*TH1x1**2*TH2x2**2 - 6*complex(0,1)*l7*TH1x1*TH2x1*TH2x2**2 - 6*complex(0,1)*l2*TH2x1**2*TH2x2**2',
                  order = {'QED':2})

GC_113 = Coupling(name = 'GC_113',
                  value = '-6*complex(0,1)*l1*TH1x1*TH1x2**3 - 3*complex(0,1)*l6*TH1x2**3*TH2x1 - 9*complex(0,1)*l6*TH1x1*TH1x2**2*TH2x2 - 3*complex(0,1)*l3*TH1x2**2*TH2x1*TH2x2 - 3*complex(0,1)*l4*TH1x2**2*TH2x1*TH2x2 - 6*complex(0,1)*l5*TH1x2**2*TH2x1*TH2x2 - 3*complex(0,1)*l3*TH1x1*TH1x2*TH2x2**2 - 3*complex(0,1)*l4*TH1x1*TH1x2*TH2x2**2 - 6*complex(0,1)*l5*TH1x1*TH1x2*TH2x2**2 - 9*complex(0,1)*l7*TH1x2*TH2x1*TH2x2**2 - 3*complex(0,1)*l7*TH1x1*TH2x2**3 - 6*complex(0,1)*l2*TH2x1*TH2x2**3',
                  order = {'QED':2})

GC_114 = Coupling(name = 'GC_114',
                  value = '-6*complex(0,1)*l1*TH1x2**4 - 12*complex(0,1)*l6*TH1x2**3*TH2x2 - 6*complex(0,1)*l3*TH1x2**2*TH2x2**2 - 6*complex(0,1)*l4*TH1x2**2*TH2x2**2 - 12*complex(0,1)*l5*TH1x2**2*TH2x2**2 - 12*complex(0,1)*l7*TH1x2*TH2x2**3 - 6*complex(0,1)*l2*TH2x2**4',
                  order = {'QED':2})

GC_115 = Coupling(name = 'GC_115',
                  value = '(gw*TH3x3)/2.',
                  order = {'QED':1})

GC_116 = Coupling(name = 'GC_116',
                  value = '-(cw*g1*gw*TH3x3)/2.',
                  order = {'QED':2})

GC_117 = Coupling(name = 'GC_117',
                  value = '(cw*g1*gw*TH3x3)/2.',
                  order = {'QED':2})

GC_118 = Coupling(name = 'GC_118',
                  value = '-(l4*TH3x3)/2.',
                  order = {'QED':2})

GC_119 = Coupling(name = 'GC_119',
                  value = '(l4*TH3x3)/2.',
                  order = {'QED':2})

GC_12 = Coupling(name = 'GC_12',
                 value = '-(cw*complex(0,1)*g1*gw)/2.',
                 order = {'QED':2})

GC_120 = Coupling(name = 'GC_120',
                  value = '-(complex(0,1)*l6*TH3x3)',
                  order = {'QED':2})

GC_121 = Coupling(name = 'GC_121',
                  value = '-3*complex(0,1)*l6*TH3x3',
                  order = {'QED':2})

GC_122 = Coupling(name = 'GC_122',
                  value = '-(complex(0,1)*l7*TH3x3)',
                  order = {'QED':2})

GC_123 = Coupling(name = 'GC_123',
                  value = '-(g1*gw*sw*TH3x3)/2.',
                  order = {'QED':2})

GC_124 = Coupling(name = 'GC_124',
                  value = '(g1*gw*sw*TH3x3)/2.',
                  order = {'QED':2})

GC_125 = Coupling(name = 'GC_125',
                  value = '-(complex(0,1)*l4*TH1x1*TH3x3)/2.',
                  order = {'QED':2})

GC_126 = Coupling(name = 'GC_126',
                  value = '-(complex(0,1)*l4*TH1x2*TH3x3)/2.',
                  order = {'QED':2})

GC_127 = Coupling(name = 'GC_127',
                  value = '(complex(0,1)*gw**2*TH3x3**2)/2.',
                  order = {'QED':2})

GC_128 = Coupling(name = 'GC_128',
                  value = '-(complex(0,1)*l3*TH3x3**2)',
                  order = {'QED':2})

GC_129 = Coupling(name = 'GC_129',
                  value = '-(l7*TH3x3**2)',
                  order = {'QED':2})

GC_13 = Coupling(name = 'GC_13',
                 value = '(complex(0,1)*gw**2)/2.',
                 order = {'QED':2})

GC_130 = Coupling(name = 'GC_130',
                  value = 'l7*TH3x3**2',
                  order = {'QED':2})

GC_131 = Coupling(name = 'GC_131',
                  value = '-3*complex(0,1)*l7*TH3x3**3',
                  order = {'QED':2})

GC_132 = Coupling(name = 'GC_132',
                  value = '-6*complex(0,1)*l2*TH3x3**4',
                  order = {'QED':2})

GC_133 = Coupling(name = 'GC_133',
                  value = '(cw*gw*TH2x1*TH3x3)/2. + (g1*sw*TH2x1*TH3x3)/2.',
                  order = {'QED':1})

GC_134 = Coupling(name = 'GC_134',
                  value = '-(cw*g1*TH2x1*TH3x3)/2. + (gw*sw*TH2x1*TH3x3)/2.',
                  order = {'QED':1})

GC_135 = Coupling(name = 'GC_135',
                  value = '-(complex(0,1)*l6*TH1x1**2*TH3x3) - 4*complex(0,1)*l5*TH1x1*TH2x1*TH3x3 - complex(0,1)*l7*TH2x1**2*TH3x3',
                  order = {'QED':2})

GC_136 = Coupling(name = 'GC_136',
                  value = '(cw*gw*TH2x2*TH3x3)/2. + (g1*sw*TH2x2*TH3x3)/2.',
                  order = {'QED':1})

GC_137 = Coupling(name = 'GC_137',
                  value = '-(cw*g1*TH2x2*TH3x3)/2. + (gw*sw*TH2x2*TH3x3)/2.',
                  order = {'QED':1})

GC_138 = Coupling(name = 'GC_138',
                  value = '-(complex(0,1)*l6*TH1x1*TH1x2*TH3x3) - 2*complex(0,1)*l5*TH1x2*TH2x1*TH3x3 - 2*complex(0,1)*l5*TH1x1*TH2x2*TH3x3 - complex(0,1)*l7*TH2x1*TH2x2*TH3x3',
                  order = {'QED':2})

GC_139 = Coupling(name = 'GC_139',
                  value = '-(complex(0,1)*l6*TH1x2**2*TH3x3) - 4*complex(0,1)*l5*TH1x2*TH2x2*TH3x3 - complex(0,1)*l7*TH2x2**2*TH3x3',
                  order = {'QED':2})

GC_14 = Coupling(name = 'GC_14',
                 value = '-(complex(0,1)*gw**2)',
                 order = {'QED':2})

GC_140 = Coupling(name = 'GC_140',
                  value = '-(complex(0,1)*l3*TH3x3**2) - complex(0,1)*l4*TH3x3**2 - 2*complex(0,1)*l5*TH3x3**2',
                  order = {'QED':2})

GC_141 = Coupling(name = 'GC_141',
                  value = '(cw**2*complex(0,1)*gw**2*TH3x3**2)/2. + cw*complex(0,1)*g1*gw*sw*TH3x3**2 + (complex(0,1)*g1**2*sw**2*TH3x3**2)/2.',
                  order = {'QED':2})

GC_142 = Coupling(name = 'GC_142',
                  value = '-(cw**2*complex(0,1)*g1*gw*TH3x3**2)/2. - (cw*complex(0,1)*g1**2*sw*TH3x3**2)/2. + (cw*complex(0,1)*gw**2*sw*TH3x3**2)/2. + (complex(0,1)*g1*gw*sw**2*TH3x3**2)/2.',
                  order = {'QED':2})

GC_143 = Coupling(name = 'GC_143',
                  value = '(cw**2*complex(0,1)*g1**2*TH3x3**2)/2. - cw*complex(0,1)*g1*gw*sw*TH3x3**2 + (complex(0,1)*gw**2*sw**2*TH3x3**2)/2.',
                  order = {'QED':2})

GC_144 = Coupling(name = 'GC_144',
                  value = '-(complex(0,1)*l3*TH1x1**2*TH3x3**2) - complex(0,1)*l4*TH1x1**2*TH3x3**2 + 2*complex(0,1)*l5*TH1x1**2*TH3x3**2 - 2*complex(0,1)*l7*TH1x1*TH2x1*TH3x3**2 - 2*complex(0,1)*l2*TH2x1**2*TH3x3**2',
                  order = {'QED':2})

GC_145 = Coupling(name = 'GC_145',
                  value = '-(complex(0,1)*l3*TH1x1*TH1x2*TH3x3**2) - complex(0,1)*l4*TH1x1*TH1x2*TH3x3**2 + 2*complex(0,1)*l5*TH1x1*TH1x2*TH3x3**2 - complex(0,1)*l7*TH1x2*TH2x1*TH3x3**2 - complex(0,1)*l7*TH1x1*TH2x2*TH3x3**2 - 2*complex(0,1)*l2*TH2x1*TH2x2*TH3x3**2',
                  order = {'QED':2})

GC_146 = Coupling(name = 'GC_146',
                  value = '-(complex(0,1)*l3*TH1x2**2*TH3x3**2) - complex(0,1)*l4*TH1x2**2*TH3x3**2 + 2*complex(0,1)*l5*TH1x2**2*TH3x3**2 - 2*complex(0,1)*l7*TH1x2*TH2x2*TH3x3**2 - 2*complex(0,1)*l2*TH2x2**2*TH3x3**2',
                  order = {'QED':2})

GC_147 = Coupling(name = 'GC_147',
                  value = '-(cw*g1*gw*vev)/2.',
                  order = {'QED':1})

GC_148 = Coupling(name = 'GC_148',
                  value = '(cw*g1*gw*vev)/2.',
                  order = {'QED':1})

GC_149 = Coupling(name = 'GC_149',
                  value = '-(gw**2*vev)/4.',
                  order = {'QED':1})

GC_15 = Coupling(name = 'GC_15',
                 value = 'cw**2*complex(0,1)*gw**2',
                 order = {'QED':2})

GC_150 = Coupling(name = 'GC_150',
                  value = '(gw**2*vev)/4.',
                  order = {'QED':1})

GC_151 = Coupling(name = 'GC_151',
                  value = '-(g1*gw*sw*vev)/2.',
                  order = {'QED':1})

GC_152 = Coupling(name = 'GC_152',
                  value = '(g1*gw*sw*vev)/2.',
                  order = {'QED':1})

GC_153 = Coupling(name = 'GC_153',
                  value = '-(complex(0,1)*gw**2*TH1x1*vev)/4.',
                  order = {'QED':1})

GC_154 = Coupling(name = 'GC_154',
                  value = '(complex(0,1)*gw**2*TH1x1*vev)/2.',
                  order = {'QED':1})

GC_155 = Coupling(name = 'GC_155',
                  value = '-(complex(0,1)*gw**2*TH1x2*vev)/4.',
                  order = {'QED':1})

GC_156 = Coupling(name = 'GC_156',
                  value = '(complex(0,1)*gw**2*TH1x2*vev)/2.',
                  order = {'QED':1})

GC_157 = Coupling(name = 'GC_157',
                  value = '-(complex(0,1)*l6*TH2x1*vev)',
                  order = {'QED':1})

GC_158 = Coupling(name = 'GC_158',
                  value = '-(complex(0,1)*l6*TH2x2*vev)',
                  order = {'QED':1})

GC_159 = Coupling(name = 'GC_159',
                  value = '-(complex(0,1)*l4*TH3x3*vev)/2.',
                  order = {'QED':1})

GC_16 = Coupling(name = 'GC_16',
                 value = '-2*cw**2*complex(0,1)*gw**2',
                 order = {'QED':2})

GC_160 = Coupling(name = 'GC_160',
                  value = '-(cw*gw**2*vev)/4. - (g1*gw*sw*vev)/4.',
                  order = {'QED':1})

GC_161 = Coupling(name = 'GC_161',
                  value = '(cw*gw**2*vev)/4. - (g1*gw*sw*vev)/4.',
                  order = {'QED':1})

GC_162 = Coupling(name = 'GC_162',
                  value = '-(cw*gw**2*vev)/4. + (g1*gw*sw*vev)/4.',
                  order = {'QED':1})

GC_163 = Coupling(name = 'GC_163',
                  value = '(cw*gw**2*vev)/4. + (g1*gw*sw*vev)/4.',
                  order = {'QED':1})

GC_164 = Coupling(name = 'GC_164',
                  value = '-(cw*g1*gw*vev)/4. - (gw**2*sw*vev)/4.',
                  order = {'QED':1})

GC_165 = Coupling(name = 'GC_165',
                  value = '(cw*g1*gw*vev)/4. - (gw**2*sw*vev)/4.',
                  order = {'QED':1})

GC_166 = Coupling(name = 'GC_166',
                  value = '-(cw*g1*gw*vev)/4. + (gw**2*sw*vev)/4.',
                  order = {'QED':1})

GC_167 = Coupling(name = 'GC_167',
                  value = '(cw*g1*gw*vev)/4. + (gw**2*sw*vev)/4.',
                  order = {'QED':1})

GC_168 = Coupling(name = 'GC_168',
                  value = '-(cw**2*complex(0,1)*gw**2*TH1x1*vev)/4. - (cw*complex(0,1)*g1*gw*sw*TH1x1*vev)/2. - (complex(0,1)*g1**2*sw**2*TH1x1*vev)/4.',
                  order = {'QED':1})

GC_169 = Coupling(name = 'GC_169',
                  value = '(cw**2*complex(0,1)*gw**2*TH1x1*vev)/2. + cw*complex(0,1)*g1*gw*sw*TH1x1*vev + (complex(0,1)*g1**2*sw**2*TH1x1*vev)/2.',
                  order = {'QED':1})

GC_17 = Coupling(name = 'GC_17',
                 value = '-(complex(0,1)*I1a33)',
                 order = {'QED':1})

GC_170 = Coupling(name = 'GC_170',
                  value = '(cw**2*complex(0,1)*g1*gw*TH1x1*vev)/4. + (cw*complex(0,1)*g1**2*sw*TH1x1*vev)/4. - (cw*complex(0,1)*gw**2*sw*TH1x1*vev)/4. - (complex(0,1)*g1*gw*sw**2*TH1x1*vev)/4.',
                  order = {'QED':1})

GC_171 = Coupling(name = 'GC_171',
                  value = '-(cw**2*complex(0,1)*g1*gw*TH1x1*vev)/2. - (cw*complex(0,1)*g1**2*sw*TH1x1*vev)/2. + (cw*complex(0,1)*gw**2*sw*TH1x1*vev)/2. + (complex(0,1)*g1*gw*sw**2*TH1x1*vev)/2.',
                  order = {'QED':1})

GC_172 = Coupling(name = 'GC_172',
                  value = '-(cw**2*complex(0,1)*g1**2*TH1x1*vev)/4. + (cw*complex(0,1)*g1*gw*sw*TH1x1*vev)/2. - (complex(0,1)*gw**2*sw**2*TH1x1*vev)/4.',
                  order = {'QED':1})

GC_173 = Coupling(name = 'GC_173',
                  value = '(cw**2*complex(0,1)*g1**2*TH1x1*vev)/2. - cw*complex(0,1)*g1*gw*sw*TH1x1*vev + (complex(0,1)*gw**2*sw**2*TH1x1*vev)/2.',
                  order = {'QED':1})

GC_174 = Coupling(name = 'GC_174',
                  value = '-(cw**2*complex(0,1)*gw**2*TH1x2*vev)/4. - (cw*complex(0,1)*g1*gw*sw*TH1x2*vev)/2. - (complex(0,1)*g1**2*sw**2*TH1x2*vev)/4.',
                  order = {'QED':1})

GC_175 = Coupling(name = 'GC_175',
                  value = '(cw**2*complex(0,1)*gw**2*TH1x2*vev)/2. + cw*complex(0,1)*g1*gw*sw*TH1x2*vev + (complex(0,1)*g1**2*sw**2*TH1x2*vev)/2.',
                  order = {'QED':1})

GC_176 = Coupling(name = 'GC_176',
                  value = '(cw**2*complex(0,1)*g1*gw*TH1x2*vev)/4. + (cw*complex(0,1)*g1**2*sw*TH1x2*vev)/4. - (cw*complex(0,1)*gw**2*sw*TH1x2*vev)/4. - (complex(0,1)*g1*gw*sw**2*TH1x2*vev)/4.',
                  order = {'QED':1})

GC_177 = Coupling(name = 'GC_177',
                  value = '-(cw**2*complex(0,1)*g1*gw*TH1x2*vev)/2. - (cw*complex(0,1)*g1**2*sw*TH1x2*vev)/2. + (cw*complex(0,1)*gw**2*sw*TH1x2*vev)/2. + (complex(0,1)*g1*gw*sw**2*TH1x2*vev)/2.',
                  order = {'QED':1})

GC_178 = Coupling(name = 'GC_178',
                  value = '-(cw**2*complex(0,1)*g1**2*TH1x2*vev)/4. + (cw*complex(0,1)*g1*gw*sw*TH1x2*vev)/2. - (complex(0,1)*gw**2*sw**2*TH1x2*vev)/4.',
                  order = {'QED':1})

GC_179 = Coupling(name = 'GC_179',
                  value = '(cw**2*complex(0,1)*g1**2*TH1x2*vev)/2. - cw*complex(0,1)*g1*gw*sw*TH1x2*vev + (complex(0,1)*gw**2*sw**2*TH1x2*vev)/2.',
                  order = {'QED':1})

GC_18 = Coupling(name = 'GC_18',
                 value = 'complex(0,1)*I2a33',
                 order = {'QED':1})

GC_180 = Coupling(name = 'GC_180',
                  value = '-(l6*TH1x1*vev) - (l4*TH2x1*vev)/2.',
                  order = {'QED':1})

GC_181 = Coupling(name = 'GC_181',
                  value = 'l6*TH1x1*vev + (l4*TH2x1*vev)/2.',
                  order = {'QED':1})

GC_182 = Coupling(name = 'GC_182',
                  value = '-2*complex(0,1)*l1*TH1x1*vev - complex(0,1)*l6*TH2x1*vev',
                  order = {'QED':1})

GC_183 = Coupling(name = 'GC_183',
                  value = '-(complex(0,1)*l3*TH1x1*vev) - complex(0,1)*l7*TH2x1*vev',
                  order = {'QED':1})

GC_184 = Coupling(name = 'GC_184',
                  value = '-6*complex(0,1)*l1*TH1x1**3*vev - 9*complex(0,1)*l6*TH1x1**2*TH2x1*vev - 3*complex(0,1)*l3*TH1x1*TH2x1**2*vev - 3*complex(0,1)*l4*TH1x1*TH2x1**2*vev - 6*complex(0,1)*l5*TH1x1*TH2x1**2*vev - 3*complex(0,1)*l7*TH2x1**3*vev',
                  order = {'QED':1})

GC_185 = Coupling(name = 'GC_185',
                  value = '-(l6*TH1x2*vev) - (l4*TH2x2*vev)/2.',
                  order = {'QED':1})

GC_186 = Coupling(name = 'GC_186',
                  value = 'l6*TH1x2*vev + (l4*TH2x2*vev)/2.',
                  order = {'QED':1})

GC_187 = Coupling(name = 'GC_187',
                  value = '-2*complex(0,1)*l1*TH1x2*vev - complex(0,1)*l6*TH2x2*vev',
                  order = {'QED':1})

GC_188 = Coupling(name = 'GC_188',
                  value = '-(complex(0,1)*l3*TH1x2*vev) - complex(0,1)*l7*TH2x2*vev',
                  order = {'QED':1})

GC_189 = Coupling(name = 'GC_189',
                  value = '-6*complex(0,1)*l1*TH1x1**2*TH1x2*vev - 6*complex(0,1)*l6*TH1x1*TH1x2*TH2x1*vev - complex(0,1)*l3*TH1x2*TH2x1**2*vev - complex(0,1)*l4*TH1x2*TH2x1**2*vev - 2*complex(0,1)*l5*TH1x2*TH2x1**2*vev - 3*complex(0,1)*l6*TH1x1**2*TH2x2*vev - 2*complex(0,1)*l3*TH1x1*TH2x1*TH2x2*vev - 2*complex(0,1)*l4*TH1x1*TH2x1*TH2x2*vev - 4*complex(0,1)*l5*TH1x1*TH2x1*TH2x2*vev - 3*complex(0,1)*l7*TH2x1**2*TH2x2*vev',
                  order = {'QED':1})

GC_19 = Coupling(name = 'GC_19',
                 value = 'complex(0,1)*I3a33',
                 order = {'QED':1})

GC_190 = Coupling(name = 'GC_190',
                  value = '-6*complex(0,1)*l1*TH1x1*TH1x2**2*vev - 3*complex(0,1)*l6*TH1x2**2*TH2x1*vev - 6*complex(0,1)*l6*TH1x1*TH1x2*TH2x2*vev - 2*complex(0,1)*l3*TH1x2*TH2x1*TH2x2*vev - 2*complex(0,1)*l4*TH1x2*TH2x1*TH2x2*vev - 4*complex(0,1)*l5*TH1x2*TH2x1*TH2x2*vev - complex(0,1)*l3*TH1x1*TH2x2**2*vev - complex(0,1)*l4*TH1x1*TH2x2**2*vev - 2*complex(0,1)*l5*TH1x1*TH2x2**2*vev - 3*complex(0,1)*l7*TH2x1*TH2x2**2*vev',
                  order = {'QED':1})

GC_191 = Coupling(name = 'GC_191',
                  value = '-6*complex(0,1)*l1*TH1x2**3*vev - 9*complex(0,1)*l6*TH1x2**2*TH2x2*vev - 3*complex(0,1)*l3*TH1x2*TH2x2**2*vev - 3*complex(0,1)*l4*TH1x2*TH2x2**2*vev - 6*complex(0,1)*l5*TH1x2*TH2x2**2*vev - 3*complex(0,1)*l7*TH2x2**3*vev',
                  order = {'QED':1})

GC_192 = Coupling(name = 'GC_192',
                  value = '-(complex(0,1)*l6*TH1x1*TH3x3*vev) - 2*complex(0,1)*l5*TH2x1*TH3x3*vev',
                  order = {'QED':1})

GC_193 = Coupling(name = 'GC_193',
                  value = '-(complex(0,1)*l6*TH1x2*TH3x3*vev) - 2*complex(0,1)*l5*TH2x2*TH3x3*vev',
                  order = {'QED':1})

GC_194 = Coupling(name = 'GC_194',
                  value = '-(complex(0,1)*l3*TH1x1*TH3x3**2*vev) - complex(0,1)*l4*TH1x1*TH3x3**2*vev + 2*complex(0,1)*l5*TH1x1*TH3x3**2*vev - complex(0,1)*l7*TH2x1*TH3x3**2*vev',
                  order = {'QED':1})

GC_195 = Coupling(name = 'GC_195',
                  value = '-(complex(0,1)*l3*TH1x2*TH3x3**2*vev) - complex(0,1)*l4*TH1x2*TH3x3**2*vev + 2*complex(0,1)*l5*TH1x2*TH3x3**2*vev - complex(0,1)*l7*TH2x2*TH3x3**2*vev',
                  order = {'QED':1})

GC_196 = Coupling(name = 'GC_196',
                  value = '-(yb/cmath.sqrt(2))',
                  order = {'QED':1})

GC_197 = Coupling(name = 'GC_197',
                  value = 'yt/cmath.sqrt(2)',
                  order = {'QED':1})

GC_198 = Coupling(name = 'GC_198',
                  value = '-ytau',
                  order = {'QED':1})

GC_199 = Coupling(name = 'GC_199',
                  value = 'ytau',
                  order = {'QED':1})

GC_2 = Coupling(name = 'GC_2',
                value = 'complex(0,1)*G',
                order = {'QCD':1})

GC_20 = Coupling(name = 'GC_20',
                 value = '-(complex(0,1)*I4a33)',
                 order = {'QED':1})

GC_200 = Coupling(name = 'GC_200',
                  value = '-(ytau/cmath.sqrt(2))',
                  order = {'QED':1})

GC_201 = Coupling(name = 'GC_201',
                  value = '(TH3x3*ymt/cmath.tan(beta))/vev',
                  order = {'QED':1})

GC_202 = Coupling(name = 'GC_202',
                  value = '-((complex(0,1)*TH2x1*ymt/cmath.tan(beta))/vev) - (complex(0,1)*TH1x1*yt)/cmath.sqrt(2)',
                  order = {'QED':1})

GC_203 = Coupling(name = 'GC_203',
                  value = '-((complex(0,1)*TH2x2*ymt/cmath.tan(beta))/vev) - (complex(0,1)*TH1x2*yt)/cmath.sqrt(2)',
                  order = {'QED':1})

GC_21 = Coupling(name = 'GC_21',
                 value = 'I5a33',
                 order = {'QED':1})

GC_22 = Coupling(name = 'GC_22',
                 value = '-I6a33',
                 order = {'QED':1})

GC_23 = Coupling(name = 'GC_23',
                 value = 'I7a33',
                 order = {'QED':1})

GC_24 = Coupling(name = 'GC_24',
                 value = '-I8a33',
                 order = {'QED':1})

GC_25 = Coupling(name = 'GC_25',
                 value = '-4*complex(0,1)*l1',
                 order = {'QED':2})

GC_26 = Coupling(name = 'GC_26',
                 value = '-6*complex(0,1)*l1',
                 order = {'QED':2})

GC_27 = Coupling(name = 'GC_27',
                 value = '-4*complex(0,1)*l2',
                 order = {'QED':2})

GC_28 = Coupling(name = 'GC_28',
                 value = '-(complex(0,1)*l3)',
                 order = {'QED':2})

GC_29 = Coupling(name = 'GC_29',
                 value = '-(complex(0,1)*l3) - complex(0,1)*l4',
                 order = {'QED':2})

GC_297 = Coupling(name = 'GC_297',
                  value = '-((TH3x3*ymb*cmath.tan(beta))/vev)',
                  order = {'QED':1})

GC_298 = Coupling(name = 'GC_298',
                  value = '-((complex(0,1)*ymtau*cmath.sqrt(2)*cmath.tan(beta))/vev)',
                  order = {'QED':1})

GC_299 = Coupling(name = 'GC_299',
                  value = '-((TH3x3*ymtau*cmath.tan(beta))/vev)',
                  order = {'QED':1})

GC_3 = Coupling(name = 'GC_3',
                value = 'complex(0,1)*G**2',
                order = {'QCD':2})

GC_30 = Coupling(name = 'GC_30',
                 value = '4*complex(0,1)*l5',
                 order = {'QED':2})

GC_301 = Coupling(name = 'GC_301',
                  value = '-((complex(0,1)*TH1x1*yb)/cmath.sqrt(2)) - (complex(0,1)*TH2x1*ymb*cmath.tan(beta))/vev',
                  order = {'QED':1})

GC_302 = Coupling(name = 'GC_302',
                  value = '-((complex(0,1)*TH1x2*yb)/cmath.sqrt(2)) - (complex(0,1)*TH2x2*ymb*cmath.tan(beta))/vev',
                  order = {'QED':1})

GC_303 = Coupling(name = 'GC_303',
                  value = '-((complex(0,1)*TH1x1*ytau)/cmath.sqrt(2)) - (complex(0,1)*TH2x1*ymtau*cmath.tan(beta))/vev',
                  order = {'QED':1})

GC_304 = Coupling(name = 'GC_304',
                  value = '-((complex(0,1)*TH1x2*ytau)/cmath.sqrt(2)) - (complex(0,1)*TH2x2*ymtau*cmath.tan(beta))/vev',
                  order = {'QED':1})

GC_31 = Coupling(name = 'GC_31',
                 value = '-2*l6',
                 order = {'QED':2})

GC_32 = Coupling(name = 'GC_32',
                 value = '-l6',
                 order = {'QED':2})

GC_33 = Coupling(name = 'GC_33',
                 value = 'l6',
                 order = {'QED':2})

GC_34 = Coupling(name = 'GC_34',
                 value = '2*l6',
                 order = {'QED':2})

GC_35 = Coupling(name = 'GC_35',
                 value = '-2*l7',
                 order = {'QED':2})

GC_36 = Coupling(name = 'GC_36',
                 value = '2*l7',
                 order = {'QED':2})

GC_37 = Coupling(name = 'GC_37',
                 value = '(complex(0,1)*g1*sw)/3.',
                 order = {'QED':1})

GC_38 = Coupling(name = 'GC_38',
                 value = '(-2*complex(0,1)*g1*sw)/3.',
                 order = {'QED':1})

GC_39 = Coupling(name = 'GC_39',
                 value = 'complex(0,1)*g1*sw',
                 order = {'QED':1})

GC_4 = Coupling(name = 'GC_4',
                value = '-(cw*complex(0,1)*g1)/3.',
                order = {'QED':1})

GC_40 = Coupling(name = 'GC_40',
                 value = '-(complex(0,1)*gw*sw)',
                 order = {'QED':1})

GC_41 = Coupling(name = 'GC_41',
                 value = 'complex(0,1)*gw*sw',
                 order = {'QED':1})

GC_42 = Coupling(name = 'GC_42',
                 value = '(complex(0,1)*g1*gw*sw)/2.',
                 order = {'QED':2})

GC_43 = Coupling(name = 'GC_43',
                 value = '-2*cw*complex(0,1)*gw**2*sw',
                 order = {'QED':2})

GC_44 = Coupling(name = 'GC_44',
                 value = 'complex(0,1)*gw**2*sw**2',
                 order = {'QED':2})

GC_45 = Coupling(name = 'GC_45',
                 value = '-(cw*complex(0,1)*gw)/2. - (complex(0,1)*g1*sw)/6.',
                 order = {'QED':1})

GC_46 = Coupling(name = 'GC_46',
                 value = '(cw*complex(0,1)*gw)/2. - (complex(0,1)*g1*sw)/6.',
                 order = {'QED':1})

GC_47 = Coupling(name = 'GC_47',
                 value = '-(cw*complex(0,1)*gw)/2. + (complex(0,1)*g1*sw)/2.',
                 order = {'QED':1})

GC_48 = Coupling(name = 'GC_48',
                 value = '(cw*complex(0,1)*gw)/2. + (complex(0,1)*g1*sw)/2.',
                 order = {'QED':1})

GC_49 = Coupling(name = 'GC_49',
                 value = '(cw*complex(0,1)*g1)/6. - (complex(0,1)*gw*sw)/2.',
                 order = {'QED':1})

GC_5 = Coupling(name = 'GC_5',
                value = '(2*cw*complex(0,1)*g1)/3.',
                order = {'QED':1})

GC_50 = Coupling(name = 'GC_50',
                 value = '-(cw*complex(0,1)*g1)/2. - (complex(0,1)*gw*sw)/2.',
                 order = {'QED':1})

GC_51 = Coupling(name = 'GC_51',
                 value = '(cw*complex(0,1)*g1)/6. + (complex(0,1)*gw*sw)/2.',
                 order = {'QED':1})

GC_52 = Coupling(name = 'GC_52',
                 value = '-(cw*complex(0,1)*g1)/2. + (complex(0,1)*gw*sw)/2.',
                 order = {'QED':1})

GC_53 = Coupling(name = 'GC_53',
                 value = '(cw**2*complex(0,1)*gw**2)/2. - cw*complex(0,1)*g1*gw*sw + (complex(0,1)*g1**2*sw**2)/2.',
                 order = {'QED':2})

GC_54 = Coupling(name = 'GC_54',
                 value = '(cw**2*complex(0,1)*gw**2)/2. + cw*complex(0,1)*g1*gw*sw + (complex(0,1)*g1**2*sw**2)/2.',
                 order = {'QED':2})

GC_55 = Coupling(name = 'GC_55',
                 value = '(cw**2*complex(0,1)*g1*gw)/2. - (cw*complex(0,1)*g1**2*sw)/2. + (cw*complex(0,1)*gw**2*sw)/2. - (complex(0,1)*g1*gw*sw**2)/2.',
                 order = {'QED':2})

GC_56 = Coupling(name = 'GC_56',
                 value = '-(cw**2*complex(0,1)*g1*gw)/2. - (cw*complex(0,1)*g1**2*sw)/2. + (cw*complex(0,1)*gw**2*sw)/2. + (complex(0,1)*g1*gw*sw**2)/2.',
                 order = {'QED':2})

GC_57 = Coupling(name = 'GC_57',
                 value = '(cw**2*complex(0,1)*g1**2)/2. - cw*complex(0,1)*g1*gw*sw + (complex(0,1)*gw**2*sw**2)/2.',
                 order = {'QED':2})

GC_58 = Coupling(name = 'GC_58',
                 value = '(cw**2*complex(0,1)*g1**2)/2. + cw*complex(0,1)*g1*gw*sw + (complex(0,1)*gw**2*sw**2)/2.',
                 order = {'QED':2})

GC_59 = Coupling(name = 'GC_59',
                 value = '-(gw*TH1x1)/2.',
                 order = {'QED':1})

GC_6 = Coupling(name = 'GC_6',
                value = '-(cw*complex(0,1)*g1)',
                order = {'QED':1})

GC_60 = Coupling(name = 'GC_60',
                 value = '-(cw*g1*gw*TH1x1)/2.',
                 order = {'QED':2})

GC_61 = Coupling(name = 'GC_61',
                 value = '(cw*g1*gw*TH1x1)/2.',
                 order = {'QED':2})

GC_62 = Coupling(name = 'GC_62',
                 value = '-(g1*gw*sw*TH1x1)/2.',
                 order = {'QED':2})

GC_63 = Coupling(name = 'GC_63',
                 value = '(g1*gw*sw*TH1x1)/2.',
                 order = {'QED':2})

GC_64 = Coupling(name = 'GC_64',
                 value = '-(cw*gw*TH1x1)/2. - (g1*sw*TH1x1)/2.',
                 order = {'QED':1})

GC_65 = Coupling(name = 'GC_65',
                 value = '(cw*g1*TH1x1)/2. - (gw*sw*TH1x1)/2.',
                 order = {'QED':1})

GC_66 = Coupling(name = 'GC_66',
                 value = '-(gw*TH1x2)/2.',
                 order = {'QED':1})

GC_67 = Coupling(name = 'GC_67',
                 value = '-(cw*g1*gw*TH1x2)/2.',
                 order = {'QED':2})

GC_68 = Coupling(name = 'GC_68',
                 value = '(cw*g1*gw*TH1x2)/2.',
                 order = {'QED':2})

GC_69 = Coupling(name = 'GC_69',
                 value = '-(g1*gw*sw*TH1x2)/2.',
                 order = {'QED':2})

GC_7 = Coupling(name = 'GC_7',
                value = '-(complex(0,1)*gw)/2.',
                order = {'QED':1})

GC_70 = Coupling(name = 'GC_70',
                 value = '(g1*gw*sw*TH1x2)/2.',
                 order = {'QED':2})

GC_71 = Coupling(name = 'GC_71',
                 value = '-(cw*gw*TH1x2)/2. - (g1*sw*TH1x2)/2.',
                 order = {'QED':1})

GC_72 = Coupling(name = 'GC_72',
                 value = '(cw*g1*TH1x2)/2. - (gw*sw*TH1x2)/2.',
                 order = {'QED':1})

GC_73 = Coupling(name = 'GC_73',
                 value = '-(complex(0,1)*gw*TH2x1)/2.',
                 order = {'QED':1})

GC_74 = Coupling(name = 'GC_74',
                 value = '(complex(0,1)*gw*TH2x1)/2.',
                 order = {'QED':1})

GC_75 = Coupling(name = 'GC_75',
                 value = '(cw*complex(0,1)*g1*gw*TH2x1)/2.',
                 order = {'QED':2})

GC_76 = Coupling(name = 'GC_76',
                 value = '(complex(0,1)*l4*TH2x1)/2.',
                 order = {'QED':2})

GC_77 = Coupling(name = 'GC_77',
                 value = '-(complex(0,1)*g1*gw*sw*TH2x1)/2.',
                 order = {'QED':2})

GC_78 = Coupling(name = 'GC_78',
                 value = '-(complex(0,1)*l3*TH1x1**2) - 2*complex(0,1)*l7*TH1x1*TH2x1',
                 order = {'QED':2})

GC_79 = Coupling(name = 'GC_79',
                 value = '(complex(0,1)*gw**2*TH1x1**2)/2. + (complex(0,1)*gw**2*TH2x1**2)/2.',
                 order = {'QED':2})

GC_8 = Coupling(name = 'GC_8',
                value = '(complex(0,1)*gw)/2.',
                order = {'QED':1})

GC_80 = Coupling(name = 'GC_80',
                 value = '-2*complex(0,1)*l6*TH1x1*TH2x1 - complex(0,1)*l3*TH2x1**2',
                 order = {'QED':2})

GC_81 = Coupling(name = 'GC_81',
                 value = '-2*complex(0,1)*l1*TH1x1**2 - 2*complex(0,1)*l6*TH1x1*TH2x1 - complex(0,1)*l3*TH2x1**2 - complex(0,1)*l4*TH2x1**2 + 2*complex(0,1)*l5*TH2x1**2',
                 order = {'QED':2})

GC_82 = Coupling(name = 'GC_82',
                 value = '-(l6*TH1x1**2) - l4*TH1x1*TH2x1 - l7*TH2x1**2',
                 order = {'QED':2})

GC_83 = Coupling(name = 'GC_83',
                 value = 'l6*TH1x1**2 + l4*TH1x1*TH2x1 + l7*TH2x1**2',
                 order = {'QED':2})

GC_84 = Coupling(name = 'GC_84',
                 value = '(cw**2*complex(0,1)*gw**2*TH1x1**2)/2. + cw*complex(0,1)*g1*gw*sw*TH1x1**2 + (complex(0,1)*g1**2*sw**2*TH1x1**2)/2. + (cw**2*complex(0,1)*gw**2*TH2x1**2)/2. + cw*complex(0,1)*g1*gw*sw*TH2x1**2 + (complex(0,1)*g1**2*sw**2*TH2x1**2)/2.',
                 order = {'QED':2})

GC_85 = Coupling(name = 'GC_85',
                 value = '-(cw**2*complex(0,1)*g1*gw*TH1x1**2)/2. - (cw*complex(0,1)*g1**2*sw*TH1x1**2)/2. + (cw*complex(0,1)*gw**2*sw*TH1x1**2)/2. + (complex(0,1)*g1*gw*sw**2*TH1x1**2)/2. - (cw**2*complex(0,1)*g1*gw*TH2x1**2)/2. - (cw*complex(0,1)*g1**2*sw*TH2x1**2)/2. + (cw*complex(0,1)*gw**2*sw*TH2x1**2)/2. + (complex(0,1)*g1*gw*sw**2*TH2x1**2)/2.',
                 order = {'QED':2})

GC_86 = Coupling(name = 'GC_86',
                 value = '(cw**2*complex(0,1)*g1**2*TH1x1**2)/2. - cw*complex(0,1)*g1*gw*sw*TH1x1**2 + (complex(0,1)*gw**2*sw**2*TH1x1**2)/2. + (cw**2*complex(0,1)*g1**2*TH2x1**2)/2. - cw*complex(0,1)*g1*gw*sw*TH2x1**2 + (complex(0,1)*gw**2*sw**2*TH2x1**2)/2.',
                 order = {'QED':2})

GC_87 = Coupling(name = 'GC_87',
                 value = '-6*complex(0,1)*l1*TH1x1**4 - 12*complex(0,1)*l6*TH1x1**3*TH2x1 - 6*complex(0,1)*l3*TH1x1**2*TH2x1**2 - 6*complex(0,1)*l4*TH1x1**2*TH2x1**2 - 12*complex(0,1)*l5*TH1x1**2*TH2x1**2 - 12*complex(0,1)*l7*TH1x1*TH2x1**3 - 6*complex(0,1)*l2*TH2x1**4',
                 order = {'QED':2})

GC_88 = Coupling(name = 'GC_88',
                 value = '-(complex(0,1)*gw*TH2x2)/2.',
                 order = {'QED':1})

GC_89 = Coupling(name = 'GC_89',
                 value = '(complex(0,1)*gw*TH2x2)/2.',
                 order = {'QED':1})

GC_9 = Coupling(name = 'GC_9',
                value = '(complex(0,1)*gw)/cmath.sqrt(2)',
                order = {'QED':1})

GC_90 = Coupling(name = 'GC_90',
                 value = '(cw*complex(0,1)*g1*gw*TH2x2)/2.',
                 order = {'QED':2})

GC_91 = Coupling(name = 'GC_91',
                 value = '(complex(0,1)*l4*TH2x2)/2.',
                 order = {'QED':2})

GC_92 = Coupling(name = 'GC_92',
                 value = '-(complex(0,1)*g1*gw*sw*TH2x2)/2.',
                 order = {'QED':2})

GC_93 = Coupling(name = 'GC_93',
                 value = '-(complex(0,1)*l3*TH1x1*TH1x2) - complex(0,1)*l7*TH1x2*TH2x1 - complex(0,1)*l7*TH1x1*TH2x2',
                 order = {'QED':2})

GC_94 = Coupling(name = 'GC_94',
                 value = '-(complex(0,1)*l3*TH1x2**2) - 2*complex(0,1)*l7*TH1x2*TH2x2',
                 order = {'QED':2})

GC_95 = Coupling(name = 'GC_95',
                 value = '(complex(0,1)*gw**2*TH1x1*TH1x2)/2. + (complex(0,1)*gw**2*TH2x1*TH2x2)/2.',
                 order = {'QED':2})

GC_96 = Coupling(name = 'GC_96',
                 value = '-(complex(0,1)*l6*TH1x2*TH2x1) - complex(0,1)*l6*TH1x1*TH2x2 - complex(0,1)*l3*TH2x1*TH2x2',
                 order = {'QED':2})

GC_97 = Coupling(name = 'GC_97',
                 value = '-2*complex(0,1)*l1*TH1x1*TH1x2 - complex(0,1)*l6*TH1x2*TH2x1 - complex(0,1)*l6*TH1x1*TH2x2 - complex(0,1)*l3*TH2x1*TH2x2 - complex(0,1)*l4*TH2x1*TH2x2 + 2*complex(0,1)*l5*TH2x1*TH2x2',
                 order = {'QED':2})

GC_98 = Coupling(name = 'GC_98',
                 value = '-(l6*TH1x1*TH1x2) - (l4*TH1x2*TH2x1)/2. - (l4*TH1x1*TH2x2)/2. - l7*TH2x1*TH2x2',
                 order = {'QED':2})

GC_99 = Coupling(name = 'GC_99',
                 value = 'l6*TH1x1*TH1x2 + (l4*TH1x2*TH2x1)/2. + (l4*TH1x1*TH2x2)/2. + l7*TH2x1*TH2x2',
                 order = {'QED':2})

