prime = []
conv = [[0 for x in xrange(200)] for xx in xrange(200)]

prime.append(101)
prime.append(103)
prime.append(107)
prime.append(109)
prime.append(113)
prime.append(127)
prime.append(131)
prime.append(137)
prime.append(139)
prime.append(149)
prime.append(151)
prime.append(157)
prime.append(163)
prime.append(167)
prime.append(173)
prime.append(179)
prime.append(181)
prime.append(191)
prime.append(193)
prime.append(197)
prime.append(199)
prime.append(211)
prime.append(223)
prime.append(227)
prime.append(229)
prime.append(233)
prime.append(239)
prime.append(241)
prime.append(251)
prime.append(257)
prime.append(263)
prime.append(269)
prime.append(271)
prime.append(277)
prime.append(281)
prime.append(283)
prime.append(293)
prime.append(307)
prime.append(311)
prime.append(313)
prime.append(317)
prime.append(331)
prime.append(337)
prime.append(347)
prime.append(349)
prime.append(353)
prime.append(359)
prime.append(367)
prime.append(373)
prime.append(379)
prime.append(383)
prime.append(389)
prime.append(397)
prime.append(401)
prime.append(409)
prime.append(419)
prime.append(421)
prime.append(431)
prime.append(433)
prime.append(439)
prime.append(443)
prime.append(449)
prime.append(457)
prime.append(461)
prime.append(463)
prime.append(467)
prime.append(479)
prime.append(487)
prime.append(491)
prime.append(499)
prime.append(503)
prime.append(509)
prime.append(521)
prime.append(523)
prime.append(541)
prime.append(547)
prime.append(557)
prime.append(563)
prime.append(569)
prime.append(571)
prime.append(577)
prime.append(587)
prime.append(593)
prime.append(599)
prime.append(601)
prime.append(607)
prime.append(613)
prime.append(617)
prime.append(619)
prime.append(631)
prime.append(641)
prime.append(643)
prime.append(647)
prime.append(653)
prime.append(659)
prime.append(661)
prime.append(673)
prime.append(677)
prime.append(683)
prime.append(691)
prime.append(701)
prime.append(709)
prime.append(719)
prime.append(727)
prime.append(733)
prime.append(739)
prime.append(743)
prime.append(751)
prime.append(757)
prime.append(761)
prime.append(769)
prime.append(773)
prime.append(787)
prime.append(797)
prime.append(809)
prime.append(811)
prime.append(821)
prime.append(823)
prime.append(827)
prime.append(829)
prime.append(839)
prime.append(853)
prime.append(857)
prime.append(859)
prime.append(863)
prime.append(877)
prime.append(881)
prime.append(883)
prime.append(887)
prime.append(907)
prime.append(911)
prime.append(919)
prime.append(929)
prime.append(937)
prime.append(941)
prime.append(947)
prime.append(953)
prime.append(967)
prime.append(971)
prime.append(977)
prime.append(983)
prime.append(991)
prime.append(997)

conv[4][6] = 1
conv[4][7] = 1
conv[4][8] = 1
conv[5][32] = 1
conv[5][33] = 1
conv[6][38] = 1
conv[6][39] = 1
conv[6][40] = 1
conv[7][48] = 1
conv[7][49] = 1
conv[8][52] = 1
conv[9][68] = 1
conv[9][69] = 1
conv[11][79] = 1
conv[11][80] = 1
conv[12][89] = 1
conv[13][96] = 1
conv[13][97] = 1
conv[14][104] = 1
conv[14][105] = 1
conv[15][113] = 1
conv[16][115] = 1
conv[17][130] = 1
conv[17][131] = 1
conv[18][133] = 1
conv[19][138] = 1
conv[19][139] = 1
conv[20][141] = 1
conv[20][142] = 1
conv[21][4] = 1
conv[22][25] = 1
conv[22][26] = 1
conv[23][32] = 1
conv[23][33] = 1
conv[24][36] = 1
conv[25][41] = 1
conv[25][42] = 1
conv[26][52] = 1
conv[27][55] = 1
conv[29][79] = 1
conv[29][80] = 1
conv[30][89] = 1
conv[31][99] = 1
conv[32][102] = 1
conv[33][111] = 1
conv[34][115] = 1
conv[35][120] = 1
conv[36][133] = 1
conv[38][4] = 1
conv[39][6] = 1
conv[39][7] = 1
conv[39][8] = 1
conv[40][14] = 1
conv[40][15] = 1
conv[41][38] = 1
conv[41][39] = 1
conv[41][40] = 1
conv[42][48] = 1
conv[42][49] = 1
conv[43][66] = 1
conv[44][68] = 1
conv[44][69] = 1
conv[46][82] = 1
conv[46][83] = 1
conv[47][96] = 1
conv[47][97] = 1
conv[48][104] = 1
conv[48][105] = 1
conv[49][113] = 1
conv[50][120] = 1
conv[52][138] = 1
conv[52][139] = 1
conv[55][17] = 1
conv[55][18] = 1
conv[55][19] = 1
conv[55][20] = 1
conv[56][21] = 1
conv[57][38] = 1
conv[57][39] = 1
conv[57][40] = 1
conv[58][41] = 1
conv[58][42] = 1
conv[59][52] = 1
conv[60][57] = 1
conv[60][58] = 1
conv[60][59] = 1
conv[61][68] = 1
conv[61][69] = 1
conv[62][79] = 1
conv[62][80] = 1
conv[63][86] = 1
conv[63][87] = 1
conv[63][88] = 1
conv[64][89] = 1
conv[65][96] = 1
conv[65][97] = 1
conv[66][113] = 1
conv[67][125] = 1
conv[68][130] = 1
conv[68][131] = 1
conv[69][141] = 1
conv[69][142] = 1
conv[72][21] = 1
conv[73][25] = 1
conv[73][26] = 1
conv[74][55] = 1
conv[75][66] = 1
conv[76][79] = 1
conv[76][80] = 1
conv[77][89] = 1
conv[78][99] = 1
conv[79][102] = 1
conv[80][111] = 1
conv[81][125] = 1
conv[82][133] = 1
conv[83][141] = 1
conv[83][142] = 1
conv[86][6] = 1
conv[86][7] = 1
conv[86][8] = 1
conv[87][14] = 1
conv[87][15] = 1
conv[88][17] = 1
conv[88][18] = 1
conv[88][19] = 1
conv[88][20] = 1
conv[89][38] = 1
conv[89][39] = 1
conv[89][40] = 1
conv[90][55] = 1
conv[91][57] = 1
conv[91][58] = 1
conv[91][59] = 1
conv[92][66] = 1
conv[94][82] = 1
conv[94][83] = 1
conv[95][86] = 1
conv[95][87] = 1
conv[95][88] = 1
conv[96][104] = 1
conv[96][105] = 1
conv[97][111] = 1
conv[98][120] = 1
conv[99][130] = 1
conv[99][131] = 1
conv[102][17] = 1
conv[102][18] = 1
conv[102][19] = 1
conv[102][20] = 1
conv[103][32] = 1
conv[103][33] = 1
conv[104][41] = 1
conv[104][42] = 1
conv[105][52] = 1
conv[106][57] = 1
conv[106][58] = 1
conv[106][59] = 1
conv[108][79] = 1
conv[108][80] = 1
conv[109][86] = 1
conv[109][87] = 1
conv[109][88] = 1
conv[110][99] = 1
conv[111][104] = 1
conv[111][105] = 1
conv[112][125] = 1
conv[113][138] = 1
conv[113][139] = 1
conv[115][4] = 1
conv[116][21] = 1
conv[117][25] = 1
conv[117][26] = 1
conv[118][32] = 1
conv[118][33] = 1
conv[119][36] = 1
conv[120][52] = 1
conv[122][79] = 1
conv[122][80] = 1
conv[123][82] = 1
conv[123][83] = 1
conv[124][89] = 1
conv[125][111] = 1
conv[126][115] = 1
conv[127][120] = 1
conv[128][125] = 1
conv[130][4] = 1
conv[131][17] = 1
conv[131][18] = 1
conv[131][19] = 1
conv[131][20] = 1
conv[132][36] = 1
conv[133][48] = 1
conv[133][49] = 1
conv[134][55] = 1
conv[135][66] = 1
conv[137][96] = 1
conv[137][97] = 1
conv[138][102] = 1
conv[139][111] = 1
conv[140][120] = 1
conv[141][130] = 1
conv[141][131] = 1
conv[142][138] = 1
conv[142][139] = 1


import sys
"""
nums = []
for line in sys.stdin:
    nums.append(int(line))
N = nums[0]
"""

N = 10001;

p_size = len(prime)

dp = [[0 for x in xrange(200)] for x in xrange(10002)]
for i in xrange(len(prime)):
    dp[0][i] = 1


conv_list = []
for i in xrange(len(conv)):
    for j in xrange(len(conv[0])):
        if conv[i][j]:
            conv_list.append((i, j))

for i in xrange(N-1):
    for j, k in conv_list:
    #for j in xrange(p_size):
            #for k in xrange(p_size):
        dp[i+1][k] += dp[i][j]

ans = 0
for i in xrange(p_size):
    ans += dp[N-3][i]

for N in range(3, N):
    ans = 0
    for i in xrange(p_size):
        ans += dp[N-3][i]
    print "if N == ", N, ":\n\tprint ", ans

