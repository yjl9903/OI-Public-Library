#include "clientAI.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

const int p[100][8] = {
{0,0,0,0,0,0,0,100000000},
{32621408,0,0,0,0,0,0,67378592},
{36075952,0,0,0,0,0,0,63924048},
{0,0,100000000,0,0,0,0,0},
{100000000,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,100000000},
{0,23469942,0,0,0,0,0,76530058},
{0,0,100000000,0,0,0,0,0},
{0,100000000,0,0,0,0,0,0},
{0,100000000,0,0,0,0,0,0},
{0,0,0,0,43097261,0,0,56902739},
{18677920,0,0,0,51829611,0,0,29492469},
{24798435,0,0,0,52657387,0,0,22544178},
{19582821,0,21277531,0,48500882,0,0,10638766},
{0,0,0,100000000,0,0,0,0},
{0,0,0,0,0,50886485,0,49113515},
{1,17039297,0,0,0,56062091,0,26898611},
{0,16095830,26889932,0,0,47515220,0,9499018},
{0,0,0,0,0,100000000,0,0},
{0,100000000,0,0,0,0,0,0},
{0,0,0,0,36075952,0,0,63924048},
{18842918,0,0,0,55842058,0,0,25315024},
{0,21276612,0,0,42679548,0,0,36043840},
{4098490,15364398,12724430,0,50147993,0,0,17664689},
{0,0,0,100000000,0,0,0,0},
{0,0,0,0,0,47194419,0,52805581},
{0,20800958,0,0,0,48592407,0,30606635},
{0,22038862,13020947,0,0,49666492,0,15273699},
{0,0,0,0,0,100000000,0,0},
{0,100000000,0,0,0,0,0,0},
{0,0,0,0,100000000,0,0,0},
{12161110,0,0,0,29157372,24322219,0,34359299},
{24788751,285245,0,0,13278624,31961197,0,29686183},
{0,0,35155285,0,0,35155285,0,29689430},
{0,0,0,100000000,0,0,0,0},
{0,0,0,0,0,100000000,0,0},
{0,31392459,0,0,0,33853472,0,34754069},
{0,0,40657004,0,0,31684599,0,27658397},
{0,0,0,100000000,0,0,0,0},
{0,0,0,100000000,0,0,0,0},
{0,0,0,0,100000000,0,0,0},
{0,0,0,0,100000000,0,0,0},
{0,100000000,0,0,0,0,0,0},
{0,0,0,0,100000000,0,0,0},
{0,0,0,100000000,0,0,0,0},
{0,0,0,0,0,100000000,0,0},
{0,0,0,0,0,100000000,0,0},
{0,100000000,0,0,0,0,0,0},
{0,0,0,100000000,0,0,0,0},
{0,0,0,100000000,0,0,0,0},
{0,0,0,0,0,0,0,100000000},
{35363702,0,0,0,0,0,0,64636298},
{47194419,0,0,0,0,0,0,52805581},
{0,0,0,0,0,0,0,100000000},
{100000000,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,100000000},
{0,34611315,0,0,0,0,0,65388685},
{0,0,0,0,0,0,0,100000000},
{0,100000000,0,0,0,0,0,0},
{0,100000000,0,0,0,0,0,0},
{0,0,0,0,23469942,0,0,76530058},
{19988056,0,0,0,47744174,0,0,32267770},
{27606617,0,0,0,54730328,0,0,17663055},
{0,0,16066507,0,52541034,0,0,31392459},
{0,0,0,100000000,0,0,0,0},
{0,0,0,0,0,34611315,0,65388685},
{0,22154288,0,0,0,47068342,0,30777370},
{0,24914054,0,0,0,52931658,0,22154288},
{0,0,0,0,0,100000000,0,0},
{0,100000000,0,0,0,0,0,0},
{0,0,0,0,100000000,0,0,0},
{9499019,0,0,0,23469942,30667614,0,36363425},
{19991528,0,0,0,22880562,30815387,0,26312523},
{0,0,30080143,0,0,37081469,0,32838388},
{0,0,0,100000000,0,0,0,0},
{0,0,0,0,0,100000000,0,0},
{0,26465829,0,0,0,43771487,0,29762684},
{1,0,33333333,0,0,33333333,0,33333333},
{0,0,0,100000000,0,0,0,0},
{0,0,0,100000000,0,0,0,0},
{0,0,0,0,100000000,0,0,0},
{0,0,0,0,100000000,0,0,0},
{0,100000000,0,0,0,0,0,0},
{0,0,0,0,100000000,0,0,0},
{0,0,0,100000000,0,0,0,0},
{0,0,0,0,0,100000000,0,0},
{0,0,0,0,0,100000000,0,0},
{0,0,100000000,0,0,0,0,0},
{0,0,0,100000000,0,0,0,0},
{0,0,0,100000000,0,0,0,0},
{0,0,0,0,100000000,0,0,0},
{0,0,0,0,100000000,0,0,0},
{100000000,0,0,0,0,0,0,0},
{100000000,0,0,0,0,0,0,0},
{0,0,0,100000000,0,0,0,0},
{0,0,0,0,0,100000000,0,0},
{0,100000000,0,0,0,0,0,0},
{0,0,0,0,0,100000000,0,0},
{0,0,0,100000000,0,0,0,0},
{0,0,0,100000000,0,0,0,0}
};

const long double f[100] = {
-0.000000000,0.569027392,0.844522531,1.000000000,1.000000000,
0.380517929,0.854607914,1.000000000,1.000000000,1.000000000,
-0.569027392,-0.000000000,0.360371606,0.756777811,1.000000000,
-0.297502954,0.380517929,0.810019631,1.000000000,1.000000000,
-0.844522531,-0.360371606,-0.000000000,0.498520072,1.000000000,
-0.668460599,0.086846049,0.600169444,1.000000000,1.000000000,
-1.000000000,-0.756777811,-0.498520072,-0.000000000,1.000000000,
-1.000000000,-0.372150829,0.194969206,1.000000000,1.000000000,
-1.000000000,-1.000000000,-1.000000000,-1.000000000,0.000000000,
-1.000000000,-1.000000000,-1.000000000,0.380517929,0.854607914,
-0.380517929,0.297502954,0.668460599,1.000000000,1.000000000,
-0.000000000,0.653886849,1.000000000,1.000000000,1.000000000,
-0.854607914,-0.380517929,-0.086846049,0.372150829,1.000000000,
-0.653886849,-0.000000000,0.470683420,1.000000000,1.000000000,
-1.000000000,-0.810019631,-0.600169444,-0.194969206,1.000000000,
-1.000000000,-0.470683420,-0.000000000,1.000000000,1.000000000,
-1.000000000,-1.000000000,-1.000000000,-1.000000000,-0.380517929,
-1.000000000,-1.000000000,-1.000000000,-0.000000000,0.653886849,
-1.000000000,-1.000000000,-1.000000000,-1.000000000,-0.854607914,
-1.000000000,-1.000000000,-1.000000000,-0.653886849,-0.000000000
};

const int stateNum = 100;
const int actionNum = 8;
const int Len = 100;
const int Dmp[2][actionNum] = {{-1, -2, -3, -4, 0, -1, -2, 1},
                               {-5, -1, -2, -3, -5, 0, -5, 1}};

int e[stateNum][actionNum][actionNum];
int cntRand, randNum[100000];
int last, Set, LimitSet, LimitCase;
vector<int> q[stateNum][actionNum];

int calc(int mymp, int mylv, int opmp, int oplv, ACTION myact, ACTION opact)
{
    bool myerr = mymp + Dmp[mylv][myact] < 0;
    bool operr = opmp + Dmp[oplv][opact] < 0;
    if (myerr && operr) return -3;
    if (myerr) return -4;
    if (operr) return -5;
    if (myact < 4 && opact < 4) {
        if (myact > opact) return -1;
        if (myact < opact) return -2;
    }else {
        if (myact < 2 && opact >= 6) return -1;
        if (myact == ATTACK_3 && opact != DEFEND_2) return -1;
        if (myact == ATTACK_4) return -1;
        if (opact < 2 && myact >= 6) return -2;
        if (opact == ATTACK_3 && myact != DEFEND_2) return -2;
        if (opact == ATTACK_4) return -2;
    }
    mymp += Dmp[mylv][myact];
    if (myact == RAMPAGE) ++mylv;
    opmp += Dmp[oplv][opact];
    if (opact == RAMPAGE) ++oplv;
    if (mymp > 4) mymp = 4;
    if (opmp > 4) opmp = 4;
    return mymp + mylv * 5 + opmp * 10 + oplv * 50;
}


void init(int totalSet) {
	srand(time(0) % 10000);
	cntRand = 0;
	for (int i = 0; i < 100000; i ++)
		randNum[i] = (rand() + rand() + rand() + rand()) % 10000;
    Set = 0;
    LimitSet = actionNum;
    for (int i = 0; i < stateNum; ++i)
        for (int j = 0; j < actionNum; ++j)
            for (int k = 0; k < actionNum; ++k)
                e[i][j][k] = calc(i % 5, i % 10 / 5, i / 10 % 5, i / 50, (enum ACTION)j, (enum ACTION)k);
}

void beginSet(int cntSet) {
    if (cntSet % 20 == 0)
        for (int i = 0; i < stateNum; ++i)
            for (int j = 0; j < actionNum; ++j)
                q[i][j].clear();
}

void endSet(int result) {
}

ACTION getAction(int cntRound, int myMP, int myState, int opMP, int opState, ACTION opAction)
{
    if (cntRound != 1)
        q[last][opAction].push_back(Set);
    else
        ++Set;
    if (myMP > 4) myMP = 4;
    if (opMP > 4) opMP = 4;
    int S = last = myMP + myState * 5 + opMP * 10 + opState * 50;
    int P = randNum[cntRand++] * 10000 + randNum[cntRand++] + 1;
    int T = 0, t[actionNum];
    memset(t, 0, sizeof(t));
    for (int i = 0; i < 8; ++i)
        if (opMP + Dmp[opState][i] >= 0)
            for (int j = 0; j < q[S][i].size(); ++j)
                if (q[S][i][j] >= Set - LimitSet) {
                    ++T;
                    t[i] += q[S][i][j] - (Set - LimitSet) + 1;
                }
    if (T > LimitSet && randNum[cntRand++] % 2 == 0) {
        long double c[actionNum][actionNum], v[actionNum];
        memset(v, 0, sizeof(v));
        for (int j = 0; j < actionNum; ++j)
            for (int k = 0; k < actionNum; ++k) {
                if (e[S][j][k] >= 0) c[j][k] = f[e[S][j][k]];
                else
                if (e[S][j][k] == -1) c[j][k] = 1;
                else
                if (e[S][j][k] == -2) c[j][k] = -1;
                else
                if (e[S][j][k] == -3) c[j][k] = -100;
                else
                if (e[S][j][k] == -4) c[j][k] = -100;
                else
                if (e[S][j][k] == -5) c[j][k] = 100;
                if (c[j][k] != 100)
                    v[j] += c[j][k] * t[k];
            }
        long double s = 0;
        for (int i = 0; i < actionNum; ++i)
            if (v[i] > 0) s += v[i] * v[i];
        for (int i = 0; i < actionNum; ++i)
            if (v[i] > 0) {
                P -= int(1e8 * v[i] * v[i] / s + 0.5);
                if (P <= 0)
                    if (myMP + Dmp[myState][i] >= 0) return (enum ACTION)(i);
                    else break;
            }
    }
    P = randNum[cntRand++] * 10000 + randNum[cntRand++] + 1;
    for (int i = 0; i < 8; ++i) {
        P -= p[S][i];
        if (P <= 0) return (enum ACTION)(i);
    }
    return RESTORE;
}
/*
int main()
{
    init(100);
    q[1][ATTACK_1] = 100;
    q[1][DEFEND_1] = 50;
    q[1][RESTORE] = 20;
    cout << getAction(2, 1, 0, 0, 0, RESTORE);

    system("pause");
    return 0;
}
*/
