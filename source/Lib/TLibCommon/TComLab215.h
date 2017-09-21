/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TComLab215.h
 * Author: brunno
 *
 * Created on 6 de Julho de 2017, 14:12
 */

#ifndef TCOMLAB215_H
#define TCOMLAB215_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

#define EN_LAB215 1
#define EN_SAD 1
#define EN_QUANT 1
#define EN_DEQUANT 1
#define LIMIT_SAD_2 100000
#define LIMIT_SAD_4 100000
#define LIMIT_SAD_8 100000
#define LIMIT_SAD_16 100000
#define LIMIT_SAD_32 100000
#define LIMIT_SAD_64 100000
#define LIMIT_SAD_128 100000
#define LIMIT_SAD_256 100000
#define LIMIT_SAD_512 100000
#define LIMIT_SAD_1024 100000
#define LIMIT_SAD_2048 100000
#define LIMIT_SAD_4096 100000
#define LIMIT_QUANT 1000000
#define LIMIT_DEQUANT 1000000

class TComLab215 {
public:

    static ofstream files_sad_2_org[2];
    static ofstream files_sad_4_org[4];
    static ofstream files_sad_8_org[8];
    static ofstream files_sad_16_org[16];
    static ofstream files_sad_32_org[32];
    static ofstream files_sad_64_org[64];
    static ofstream files_sad_128_org[128];
    static ofstream files_sad_256_org[256];
    static ofstream files_sad_512_org[256];
    static ofstream files_sad_1024_org[256];
    static ofstream files_sad_2048_org[256];
    static ofstream files_sad_4096_org[256];

    static ofstream files_sad_2_cur[2];
    static ofstream files_sad_4_cur[4];
    static ofstream files_sad_8_cur[8];
    static ofstream files_sad_16_cur[16];
    static ofstream files_sad_32_cur[32];
    static ofstream files_sad_64_cur[64];
    static ofstream files_sad_128_cur[128];
    static ofstream files_sad_256_cur[256];
    static ofstream files_sad_512_cur[256];
    static ofstream files_sad_1024_cur[256];
    static ofstream files_sad_2048_cur[256];
    static ofstream files_sad_4096_cur[256];
    
    static ofstream files_quant_w;
    static ofstream files_quant_qcoeff;
    static ofstream files_quant_offset;
    static ofstream files_quant_qbits;
    static ofstream files_quant_mult;
    static ofstream files_quant_min;
    static ofstream files_quant_sum;
    static ofstream files_quant_shift;
    static ofstream files_quant_2scomp;
    static ofstream files_quant_clip;
    
    static ofstream files_dequant_clip1;
    static ofstream files_dequant_w;
    static ofstream files_dequant_qcoeff;
    static ofstream files_dequant_offset;
    static ofstream files_dequant_qbits;
    static ofstream files_dequant_abs;
    static ofstream files_dequant_mult;
    static ofstream files_dequant_min;
    static ofstream files_dequant_sum;
    static ofstream files_dequant_shift;
    static ofstream files_dequant_2scomp;
    static ofstream files_dequant_clip2;
    static ofstream files_dequant_ifresult;
    
    static int control_sad[12];
    static int control_quant;
    static int control_dequant;

    static int print_sad;
    static int print_quant;
    static int print_dequant;
    
    static double qp;
    
    static string inName;
    
    static void openFiles();
    static void closeFiles();
    
};

#endif /* TCOMLAB215_H */

