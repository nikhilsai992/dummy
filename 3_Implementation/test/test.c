#include "DigitalElectronicsandSystems.h"
#include "Modulation.h"
#include "ElectricCircuits.h"
#include "ResistorColorCoding.h"
#include "SignalsandSystems.h"

#include "unity.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Required by the unity test framework */
void setUp() {}
/* Required by the unity test framework */
void tearDown() {}

void test_rs(void); //EC
void test_rp(void);
void test_cs(void);
void test_cp(void);
void test_is(void);
void test_ip(void);
void test_rlcs(void);
void test_rlcp(void);
void test_rf(void);
void test_rls(void);
void test_rlp(void);
void test_rcs(void);
void test_rcp(void);
/*void test_std(void);
void test_dts(void);*/

void test_binhex(void); //DS
void test_binoct(void);
void test_octbin(void);
void test_decoct(void);
void test_octdec(void);
void test_bingray(void);
void test_bindec(void);
void test_decbin(void);
void test_binnumval(void);

void test_linearconv(void); //SS
void test_circularconv(void);
void test_crosscorr(void);
void test_autocorr(void);

void test_calValByCol(void); //RCC
void test_calRes_5_6(void);
void test_calRes_4(void);
void test_selMul(void);
void test_tolVal(void);
void test_calPPM(void);

void test_mod_power_dsbfc(void); //MOD
void test_mod_efficiency_dsbfc(void);
void test_mod_bw_dsbfc(void);
void test_mod_power_dsbsc(void);
void test_mod_efficiency_dsbsc(void);
void test_mod_bw_dsbsc(void);
void test_mod_power_ssbsc(void);
void test_mod_efficiency_ssbsc(void);
void test_mod_bw_ssbsc(void);

/* Start of the application test */
int main()
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(test_rs); //EC
    RUN_TEST(test_rp);
    RUN_TEST(test_cp);
    RUN_TEST(test_cs);
    RUN_TEST(test_is);
    RUN_TEST(test_ip);
    RUN_TEST(test_rlcs);
    RUN_TEST(test_rlcp);
    RUN_TEST(test_rls);
    RUN_TEST(test_rlp);
    RUN_TEST(test_rcs);
    RUN_TEST(test_rcp);
    RUN_TEST(test_rf);
    /*RUN_TEST(test_std);
RUN_TEST(test_dts);*/

    RUN_TEST(test_binhex); //DS
    RUN_TEST(test_binoct);
    RUN_TEST(test_octbin);
    RUN_TEST(test_decoct);
    RUN_TEST(test_octdec);
    RUN_TEST(test_bingray);
    RUN_TEST(test_bindec);
    RUN_TEST(test_decbin);
    RUN_TEST(test_binnumval);

    RUN_TEST(test_linearconv); //SS
    RUN_TEST(test_circularconv);
    RUN_TEST(test_crosscorr);
    RUN_TEST(test_autocorr);

    RUN_TEST(test_calValByCol); //RCC
    RUN_TEST(test_calRes_5_6);
    RUN_TEST(test_calRes_4);
    RUN_TEST(test_selMul);
    RUN_TEST(test_tolVal);
    RUN_TEST(test_calPPM);

    RUN_TEST(test_mod_power_dsbfc); //MOD
    RUN_TEST(test_mod_efficiency_dsbfc);
    RUN_TEST(test_mod_bw_dsbfc);
    RUN_TEST(test_mod_power_dsbsc);
    RUN_TEST(test_mod_efficiency_dsbsc);
    RUN_TEST(test_mod_bw_dsbsc);
    RUN_TEST(test_mod_power_ssbsc);
    RUN_TEST(test_mod_efficiency_ssbsc);
    RUN_TEST(test_mod_bw_ssbsc);

    /* Close the Unity Test Framework */
    return UNITY_END();
}
float aa[5] = {10, 20, 30, 40, 50};
float bb[1] = {100};
struct resofreq bbb;
struct stardelta s;

//////////////////////////////////////////////////////EC
void test_rs(void)
{
    TEST_ASSERT_EQUAL(150, riscp(5, aa));
    TEST_ASSERT_EQUAL(100, riscp(1, bb));
}
void test_rp(void)
{
    TEST_ASSERT_EQUAL(4.38, ripcs(5, aa));
    TEST_ASSERT_EQUAL(100, ripcs(1, bb));
}
void test_cs(void)
{
    TEST_ASSERT_EQUAL(4.38, ripcs(5, aa));
    TEST_ASSERT_EQUAL(100, ripcs(1, bb));
}
void test_cp(void)
{
    TEST_ASSERT_EQUAL(150, riscp(5, aa));
    TEST_ASSERT_EQUAL(100, riscp(1, bb));
}
void test_is(void)
{
    TEST_ASSERT_EQUAL(150, riscp(5, aa));
    TEST_ASSERT_EQUAL(100, riscp(1, bb));
}
void test_ip(void)
{
    TEST_ASSERT_EQUAL(4.38, ripcs(5, aa));
    TEST_ASSERT_EQUAL(100, ripcs(1, bb));
}
void test_rlcs(void)
{
    TEST_ASSERT_EQUAL(628.3965, RLCS(10, 10, 10, 10));
}
void test_rlcp(void)
{
    TEST_ASSERT_EQUAL(0.0016, RLCP(10, 10, 10, 10));
    TEST_ASSERT_EQUAL(0, RLCP(0, 10, 10, 10));
}
void test_rf(void)
{
    bbb.c = 10;
    bbb.l = 10;
    TEST_ASSERT_EQUAL(0.015913, resfreq(bbb));
}
void test_rls(void)
{
    TEST_ASSERT_EQUAL(628.3965, RLCS(10, 10, 10, 10));
    TEST_ASSERT_EQUAL(0, RLCS(0, 0, 10, 10));
}
void test_rlp(void)
{
    TEST_ASSERT_EQUAL(9.998734, RLP(10, 10, 10));
    TEST_ASSERT_EQUAL(0, RLP(0, 10, 0));
}
void test_rcs(void)
{
    TEST_ASSERT_EQUAL(628.3965, RLCS(10, 10, 10, 10));
    TEST_ASSERT_EQUAL(0, RLCS(0, 10, 0, 0));
}
void test_rcp(void)
{
    TEST_ASSERT_EQUAL(0.001591, RCP(10, 10, 10));
    TEST_ASSERT_EQUAL(0, RCP(0, 10, 10));
}
/*void test_std(void)
{
    s.res1=3.3;s.res2=3.3;s.res3=3.3;
    TEST_ASSERT_EQUAL(s,star_delta(10,10,10));
}
void test_dts(void)
{
    s.res1=30;s.res2=30;s.res3=30;
    TEST_ASSERT_EQUAL(s,delta_star(10,10,10));
}*/
//////////////////////////////////////////////////////////DS
void test_binhex(void)
{
    TEST_ASSERT_EQUAL(60, binToHexa(111100));
    TEST_ASSERT_EQUAL(5, binToHexa(101));
    TEST_ASSERT_EQUAL(13, binToHexa(1101));
    TEST_ASSERT_EQUAL(821, binToHexa(1100110101));
    TEST_ASSERT_EQUAL(58, binToHexa(111010));
}
void test_binoct(void)
{
    TEST_ASSERT_EQUAL(24, binToOcta(10100));
    TEST_ASSERT_EQUAL(145, binToOcta(1100101));
    TEST_ASSERT_EQUAL(5, binToOcta(101));
}
void test_octbin(void)
{
    TEST_ASSERT_EQUAL(101001, octaToBin(51));
    TEST_ASSERT_EQUAL(110111, octaToBin(67));
    TEST_ASSERT_EQUAL(111, octaToBin(7));
}
void test_decoct(void)
{
    TEST_ASSERT_EQUAL(13, decToOcta(11));
    TEST_ASSERT_EQUAL(104, decToOcta(68));
    TEST_ASSERT_EQUAL(217, decToOcta(143));
}
void test_octdec(void)
{
    TEST_ASSERT_EQUAL(41, octaToDec(51));
    TEST_ASSERT_EQUAL(10, octaToDec(12));
    TEST_ASSERT_EQUAL(86, octaToDec(126));
}
void test_bingray(void)
{
    TEST_ASSERT_EQUAL(111, binToGray(101));
    TEST_ASSERT_EQUAL(110010, binToGray(100011));
    TEST_ASSERT_EQUAL(100100, binToGray(111000));
}
void test_bindec(void)
{
    TEST_ASSERT_EQUAL(10, binToDec(1010));
    TEST_ASSERT_EQUAL(101, binToDec(1100101));
    TEST_ASSERT_EQUAL(26, binToDec(11010));
}
void test_decbin(void)
{
    TEST_ASSERT_EQUAL(10001, decToBin(17));
    TEST_ASSERT_EQUAL(10001111, decToBin(143));
    TEST_ASSERT_EQUAL(1001, decToBin(9));
}
void test_binnumval(void)
{
    TEST_ASSERT_EQUAL(1, binaryNumberValidator(1010));
    TEST_ASSERT_EQUAL(1, binaryNumberValidator(1110));
    TEST_ASSERT_EQUAL(0, binaryNumberValidator(1234));
    TEST_ASSERT_EQUAL(0, binaryNumberValidator(1108));
}
////////////////////////////////////////////////////////////////////////SS
int a[5] = {1, 1, 2, 3, 1};
int b[4] = {1, 4, 5, 2};
int c[6] = {2, 2, 3, 1, 4, 1};
int d[5] = {1, 2, 3, 2, 1};

void test_linearconv(void)
{
    TEST_ASSERT_EQUAL(8, linear_conv1(5, 4, a, b));
    TEST_ASSERT_EQUAL(10, linear_conv1(5, 6, a, c));
}

void test_circularconv(void)
{
    TEST_ASSERT_EQUAL(5, circular_conv(5, 4, a, b));
    TEST_ASSERT_EQUAL(6, circular_conv(5, 6, a, c));
}

void test_crosscorr(void)
{
    TEST_ASSERT_EQUAL(8, cross_corr(5, 4, a, b));
    TEST_ASSERT_EQUAL(10, cross_corr(5, 6, a, c));
}

void test_autocorr(void)
{
    TEST_ASSERT_EQUAL(9, auto_corr(5, d));
    TEST_ASSERT_EQUAL(9, auto_corr(5, a));
}
///////////////////////////////////////////////////////////////////////RCC
  
void test_calValByCol(void)
{
    TEST_ASSERT_EQUAL(2,calValByCol("red"));
    TEST_ASSERT_EQUAL(9,calValByCol("white"));
    TEST_ASSERT_EQUAL(-1,calValByCol("sunday"));

}
void test_calRes_5_6(void)
{
    TEST_ASSERT_EQUAL(145,calRes_5_6(1,4,5));
    TEST_ASSERT_EQUAL(432,calRes_5_6(4,3,2));
    
}
void test_calRes_4(void)
{
    TEST_ASSERT_EQUAL(19,calRes_4(1,9));
    TEST_ASSERT_EQUAL(82,calRes_4(8,2));
   
}
void test_selMul(void)
{
    TEST_ASSERT_EQUAL(1000,selMul(3));
    TEST_ASSERT_EQUAL(10,selMul(1));
    TEST_ASSERT_EQUAL(-1,selMul(15));
    
}
void test_tolVal(void)
{
    TEST_ASSERT_EQUAL(2,tolVal(2));
    TEST_ASSERT_EQUAL(0.5,tolVal(5));
    TEST_ASSERT_EQUAL(-1,tolVal(19));
    
}
void test_calPPM(void)
{
    TEST_ASSERT_EQUAL(0,calPPM(6));
    TEST_ASSERT_EQUAL(-1,calPPM(33));
    TEST_ASSERT_EQUAL(15,calPPM(3));
}
//////////////////////////////////////////////////////////////////MOD
void test_mod_power_dsbfc(void)
{
    TEST_ASSERT_EQUAL(3275, mod_power_dsbfc(100,90,2));
    TEST_ASSERT_EQUAL(5025, mod_power_dsbfc(10,100,1));
    TEST_ASSERT_EQUAL(216.88, mod_power_dsbfc(15,65,10));
    TEST_ASSERT_EQUAL(-1, mod_power_dsbfc(42,-23,4));
}
void test_mod_efficiency_dsbfc(void)
{
    TEST_ASSERT_EQUAL(1.96, mod_efficiency_dsbfc(10,50));
    TEST_ASSERT_EQUAL(15.25, mod_efficiency_dsbfc(15,25));
    TEST_ASSERT_EQUAL(66.67, mod_efficiency_dsbfc(32,16));
    TEST_ASSERT_EQUAL(1.66, mod_efficiency_dsbfc(4.5,24.5));
}
void test_mod_bw_dsbfc(void)
{
    TEST_ASSERT_EQUAL(200, mod_bw_dsbfc(100));
    TEST_ASSERT_EQUAL(89, mod_bw_dsbfc(44.5));
    TEST_ASSERT_EQUAL(353.6, mod_bw_dsbfc(176.8));
    TEST_ASSERT_EQUAL(0, mod_bw_dsbfc(0));
}
void test_mod_power_dsbsc(void)
{
    TEST_ASSERT_EQUAL(911250, mod_power_dsbsc(45,60,2));
    TEST_ASSERT_EQUAL(62500, mod_power_dsbsc(10,50,1));
    TEST_ASSERT_EQUAL(16758.79, mod_power_dsbsc(65.5,12.5,10));
    TEST_ASSERT_EQUAL(-1, mod_power_dsbsc(-20,42,1));
}
void test_mod_efficiency_dsbsc(void)
{
    TEST_ASSERT_EQUAL(50, mod_efficiency_dsbsc(20,60));
    TEST_ASSERT_EQUAL(50, mod_efficiency_dsbsc(46,92));
    TEST_ASSERT_EQUAL(-1, mod_efficiency_dsbsc(-12,22));
    TEST_ASSERT_EQUAL(50, mod_efficiency_dsbsc(10,50));
}
void test_mod_bw_dsbsc(void)
{
    TEST_ASSERT_EQUAL(31, mod_bw_dsbsc(15.5));
    TEST_ASSERT_EQUAL(62, mod_bw_dsbsc(31));
    TEST_ASSERT_EQUAL(-1, mod_bw_dsbsc(-22));
    TEST_ASSERT_EQUAL(90, mod_bw_dsbsc(45));
}
void test_mod_power_ssbsc(void)
{
    TEST_ASSERT_EQUAL(29161.13, mod_power_ssbsc(42,23,4));
    TEST_ASSERT_EQUAL(22500, mod_power_ssbsc(10,60,2));
    TEST_ASSERT_EQUAL(8379.39, mod_power_ssbsc(65.5,12.5,10));
    TEST_ASSERT_EQUAL(-2, mod_power_ssbsc(41,22,0));
}
void test_mod_efficiency_ssbsc(void)
{
    TEST_ASSERT_EQUAL(100, mod_efficiency_ssbsc(20,60,2));
    TEST_ASSERT_EQUAL(100, mod_efficiency_ssbsc(41,66,6));
    TEST_ASSERT_EQUAL(-1, mod_efficiency_ssbsc(-2,12,7));
    TEST_ASSERT_EQUAL(100, mod_efficiency_ssbsc(24,62,10));
}
void test_mod_bw_ssbsc(void)
{
    TEST_ASSERT_EQUAL(44, mod_bw_ssbsc(44));
    TEST_ASSERT_EQUAL(1000, mod_bw_ssbsc(1000));
    TEST_ASSERT_EQUAL(1432, mod_bw_ssbsc(1432));
    TEST_ASSERT_EQUAL(-1, mod_bw_ssbsc(-41));
}
///////////////////////////////////////////////
////////////////////////////////////////////////////////////
