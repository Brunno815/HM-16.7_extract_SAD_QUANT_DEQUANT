/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TComLab215.cpp
 * Author: brunno
 * 
 * Created on 6 de Julho de 2017, 14:12
 */

#include "TComLab215.h"

ofstream TComLab215::files_sad_2_org[2];
ofstream TComLab215::files_sad_4_org[4];
ofstream TComLab215::files_sad_8_org[8];
ofstream TComLab215::files_sad_16_org[16];
ofstream TComLab215::files_sad_32_org[32];
ofstream TComLab215::files_sad_64_org[64];
ofstream TComLab215::files_sad_128_org[128];
ofstream TComLab215::files_sad_256_org[256];
ofstream TComLab215::files_sad_512_org[256];
ofstream TComLab215::files_sad_1024_org[256];
ofstream TComLab215::files_sad_2048_org[256];
ofstream TComLab215::files_sad_4096_org[256];

ofstream TComLab215::files_sad_2_cur[2];
ofstream TComLab215::files_sad_4_cur[4];
ofstream TComLab215::files_sad_8_cur[8];
ofstream TComLab215::files_sad_16_cur[16];
ofstream TComLab215::files_sad_32_cur[32];
ofstream TComLab215::files_sad_64_cur[64];
ofstream TComLab215::files_sad_128_cur[128];
ofstream TComLab215::files_sad_256_cur[256];
ofstream TComLab215::files_sad_512_cur[256];
ofstream TComLab215::files_sad_1024_cur[256];
ofstream TComLab215::files_sad_2048_cur[256];
ofstream TComLab215::files_sad_4096_cur[256];

ofstream TComLab215::files_quant_w;
ofstream TComLab215::files_quant_qcoeff;
ofstream TComLab215::files_quant_offset;
ofstream TComLab215::files_quant_qbits;
ofstream TComLab215::files_quant_mult;
ofstream TComLab215::files_quant_min;
ofstream TComLab215::files_quant_sum;
ofstream TComLab215::files_quant_shift;
ofstream TComLab215::files_quant_2scomp;
ofstream TComLab215::files_quant_clip;

ofstream TComLab215::files_dequant_clip1;
ofstream TComLab215::files_dequant_w;
ofstream TComLab215::files_dequant_qcoeff;
ofstream TComLab215::files_dequant_offset;
ofstream TComLab215::files_dequant_qbits;
ofstream TComLab215::files_dequant_abs;
ofstream TComLab215::files_dequant_mult;
ofstream TComLab215::files_dequant_min;
ofstream TComLab215::files_dequant_sum;
ofstream TComLab215::files_dequant_shift;
ofstream TComLab215::files_dequant_2scomp;
ofstream TComLab215::files_dequant_clip2;
ofstream TComLab215::files_dequant_ifresult;

int TComLab215::control_sad[12];
int TComLab215::control_quant;
int TComLab215::control_dequant;

int TComLab215::print_sad;
int TComLab215::print_quant;
int TComLab215::print_dequant;

double TComLab215::qp;

string TComLab215::inName;

void TComLab215::openFiles(){
    
    //string sizes[4] = {8,16,32,64};
    for(int i = 0; i < 12; i++){
        TComLab215::control_sad[i] = 0;
    }
    
    TComLab215::control_quant = 0;
    TComLab215::control_dequant = 0;
    
    std::stringstream sstr;

    string name;
    
    int a = system("mkdir -p OUTPUT_SAD");
    
    printf("%d\n", a);
    
    a = system("mkdir -p OUTPUT_QUANT");
    a = system("mkdir -p OUTPUT_DEQUANT");
    
    string name_video = TComLab215::inName.substr(21, TComLab215::inName.size() - 25);
    
#if EN_SAD || EN_QUANT || EN_DEQUANT
    if(TComLab215::print_sad != 0){
        a = system(("mkdir -p OUTPUT_SAD/" + name_video).c_str());
    }
    
    if(TComLab215::print_quant != 0){
        a = system(("mkdir -p OUTPUT_QUANT/" + name_video).c_str());
    }
    
    if(TComLab215::print_dequant != 0){
        a = system(("mkdir -p OUTPUT_DEQUANT/" + name_video).c_str());
    }
#endif
    
#if EN_SAD
    
    if(TComLab215::print_sad == 2){
        a = system(("mkdir -p OUTPUT_SAD/" + name_video + "/2").c_str());
        
        for(int i = 0; i < 2; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/2/org" + sstr.str() + ".txt";
            //cout << name << endl;
            TComLab215::files_sad_2_org[i].open(name.c_str(),std::ofstream::out);
        }
    }
    
    if(TComLab215::print_sad == 4){
        a = system(("mkdir -p OUTPUT_SAD/" + name_video + "/4").c_str());
        for(int i = 0; i < 4; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/4/org" + sstr.str() + ".txt";
            //cout << name << endl;
            TComLab215::files_sad_4_org[i].open(name.c_str(),std::ofstream::out);
        }
    }
    
    if(TComLab215::print_sad == 8){
        a = system(("mkdir -p OUTPUT_SAD/" + name_video + "/8").c_str());
        for(int i = 0; i < 8; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/8/org" + sstr.str() + ".txt";
            //cout << name << endl;
            TComLab215::files_sad_8_org[i].open(name.c_str(),std::ofstream::out);
        }
    }
        
    if(TComLab215::print_sad == 16){
        a = system(("mkdir -p OUTPUT_SAD/" + name_video + "/16").c_str());
        for(int i = 0; i < 16; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/16/org" + sstr.str() + ".txt";
            TComLab215::files_sad_16_org[i].open(name.c_str());
        }
    }
    
    if(TComLab215::print_sad == 32){
        a = system(("mkdir -p OUTPUT_SAD/" + name_video + "/32").c_str());
        for(int i = 0; i < 32; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/32/org" + sstr.str() + ".txt";
            TComLab215::files_sad_32_org[i].open(name.c_str());
        }
    }
    
    if(TComLab215::print_sad == 64){
        a = system(("mkdir -p OUTPUT_SAD/" + name_video + "/64").c_str());
        for(int i = 0; i < 64; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/64/org" + sstr.str() + ".txt";
            TComLab215::files_sad_64_org[i].open(name.c_str());
        }
    }
    
    if(TComLab215::print_sad == 128){
        a = system(("mkdir -p OUTPUT_SAD/" + name_video + "/128").c_str());
        for(int i = 0; i < 128; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/128/org" + sstr.str() + ".txt";
            TComLab215::files_sad_128_org[i].open(name.c_str());
        }
    }
    
    if(TComLab215::print_sad == 256){
        a = system(("mkdir -p OUTPUT_SAD/" + name_video + "/256").c_str());
        for(int i = 0; i < 256; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/256/org" + sstr.str() + ".txt";
            TComLab215::files_sad_256_org[i].open(name.c_str());
        }
    }
    
    if(TComLab215::print_sad == 512){
        a = system(("mkdir -p OUTPUT_SAD/" + name_video + "/512").c_str());
        for(int i = 0; i < 256; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/512/org" + sstr.str() + ".txt";
            TComLab215::files_sad_512_org[i].open(name.c_str());
        }
    }
    
    if(TComLab215::print_sad == 1024){
        a = system(("mkdir -p OUTPUT_SAD/" + name_video + "/1024").c_str());
        for(int i = 0; i < 256; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/1024/org" + sstr.str() + ".txt";
            TComLab215::files_sad_1024_org[i].open(name.c_str());
        }
    }
    
    if(TComLab215::print_sad == 2048){
        a = system(("mkdir -p OUTPUT_SAD/" + name_video + "/2048").c_str());
        for(int i = 0; i < 256; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/2048/org" + sstr.str() + ".txt";
            TComLab215::files_sad_2048_org[i].open(name.c_str());
        }
    }

    if(TComLab215::print_sad == 4096){
        a = system(("mkdir -p OUTPUT_SAD/" + name_video + "/4096").c_str());
        for(int i = 0; i < 256; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/4096/org" + sstr.str() + ".txt";
            TComLab215::files_sad_4096_org[i].open(name.c_str());
        }
    }
 
    if(TComLab215::print_sad == 2){
        for(int i = 0; i < 2; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/2/cur" + sstr.str() + ".txt";
            //cout << name << endl;
            TComLab215::files_sad_2_cur[i].open(name.c_str(),std::ofstream::out);
        }
    }
    
    if(TComLab215::print_sad == 4){
        for(int i = 0; i < 4; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/4/cur" + sstr.str() + ".txt";
            //cout << name << endl;
            TComLab215::files_sad_4_cur[i].open(name.c_str(),std::ofstream::out);
        }
    }
    
    if(TComLab215::print_sad == 8){
        for(int i = 0; i < 8; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/8/cur" + sstr.str() + ".txt";
            //cout << name << endl;
            TComLab215::files_sad_8_cur[i].open(name.c_str(),std::ofstream::out);
        }
    }
        
    if(TComLab215::print_sad == 16){
        for(int i = 0; i < 16; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/16/cur" + sstr.str() + ".txt";
            TComLab215::files_sad_16_cur[i].open(name.c_str());
        }
    }
    
    if(TComLab215::print_sad == 32){
        for(int i = 0; i < 32; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/32/cur" + sstr.str() + ".txt";
            TComLab215::files_sad_32_cur[i].open(name.c_str());
        }
    }
    
    if(TComLab215::print_sad == 64){
        for(int i = 0; i < 64; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/64/cur" + sstr.str() + ".txt";
            TComLab215::files_sad_64_cur[i].open(name.c_str());
        }
    }
    
    if(TComLab215::print_sad == 128){
        for(int i = 0; i < 128; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/128/cur" + sstr.str() + ".txt";
            TComLab215::files_sad_128_cur[i].open(name.c_str());
        }
    }
    
    if(TComLab215::print_sad == 256){
        for(int i = 0; i < 256; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/256/cur" + sstr.str() + ".txt";
            TComLab215::files_sad_256_cur[i].open(name.c_str());
        }
    }
    
    if(TComLab215::print_sad == 512){
        for(int i = 0; i < 256; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/512/cur" + sstr.str() + ".txt";
            TComLab215::files_sad_512_cur[i].open(name.c_str());
        }
    }
    
    if(TComLab215::print_sad == 1024){
        for(int i = 0; i < 256; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/1024/cur" + sstr.str() + ".txt";
            TComLab215::files_sad_1024_cur[i].open(name.c_str());
        }
    }
    
    if(TComLab215::print_sad == 2048){
        for(int i = 0; i < 256; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/2048/cur" + sstr.str() + ".txt";
            TComLab215::files_sad_2048_cur[i].open(name.c_str());
        }
    }

    if(TComLab215::print_sad == 4096){
        for(int i = 0; i < 256; i++){
            sstr.str("");
            sstr << i;
            name = "OUTPUT_SAD/" + name_video + "/4096/cur" + sstr.str() + ".txt";
            TComLab215::files_sad_4096_cur[i].open(name.c_str());
        }
    }
    
#endif
    
#if EN_QUANT
    
    if(TComLab215::print_quant == 1){
        sstr.str("");
        sstr << int(TComLab215::qp);
        
        a = system(("mkdir -p OUTPUT_QUANT/" + name_video + "/" + sstr.str()).c_str());
        
        name = "OUTPUT_QUANT/" + name_video + "/" + sstr.str() + "/files_quant_w.txt";
        cout << name << endl;
        TComLab215::files_quant_w.open(name.c_str(),std::ofstream::out);
        
        name = "OUTPUT_QUANT/" + name_video + "/" + sstr.str() + "/files_quant_qcoeff.txt";
        cout << name << endl;
        TComLab215::files_quant_qcoeff.open(name.c_str(),std::ofstream::out);
        
        name = "OUTPUT_QUANT/" + name_video + "/" + sstr.str() + "/files_quant_offset.txt";
        cout << name << endl;
        TComLab215::files_quant_offset.open(name.c_str(),std::ofstream::out);
        
        name = "OUTPUT_QUANT/" + name_video + "/" + sstr.str() + "/files_quant_qbits.txt";
        cout << name << endl;
        TComLab215::files_quant_qbits.open(name.c_str(),std::ofstream::out);
      
        name = "OUTPUT_QUANT/" + name_video + "/" + sstr.str() + "/files_quant_mult.txt";
        cout << name << endl;
        TComLab215::files_quant_mult.open(name.c_str(),std::ofstream::out);
        
        name = "OUTPUT_QUANT/" + name_video + "/" + sstr.str() + "/files_quant_min.txt";
        cout << name << endl;
        TComLab215::files_quant_min.open(name.c_str(),std::ofstream::out);
        
        name = "OUTPUT_QUANT/" + name_video + "/" + sstr.str() + "/files_quant_sum.txt";
        cout << name << endl;
        TComLab215::files_quant_sum.open(name.c_str(),std::ofstream::out);
        
        name = "OUTPUT_QUANT/" + name_video + "/" + sstr.str() + "/files_quant_shift.txt";
        cout << name << endl;
        TComLab215::files_quant_shift.open(name.c_str(),std::ofstream::out);
        
        name = "OUTPUT_QUANT/" + name_video + "/" + sstr.str() + "/files_quant_2scomp.txt";
        cout << name << endl;
        TComLab215::files_quant_2scomp.open(name.c_str(),std::ofstream::out);
        
        name = "OUTPUT_QUANT/" + name_video + "/" + sstr.str() + "/files_quant_clip.txt";
        cout << name << endl;
        TComLab215::files_quant_clip.open(name.c_str(),std::ofstream::out);
    }
    
#endif
    
#if EN_DEQUANT
    
    if(TComLab215::print_dequant == 1){
        sstr.str("");
        sstr << int(TComLab215::qp);
        
        a = system(("mkdir -p OUTPUT_DEQUANT/" + name_video + "/" + sstr.str()).c_str());
        
        name = "OUTPUT_DEQUANT/" + name_video + "/" + sstr.str() + "/files_dequant_clip1.txt";
        cout << name << endl;
        TComLab215::files_dequant_clip1.open(name.c_str(),std::ofstream::out);
        
        name = "OUTPUT_DEQUANT/" + name_video + "/" + sstr.str() + "/files_dequant_w.txt";
        cout << name << endl;
        TComLab215::files_dequant_w.open(name.c_str(),std::ofstream::out);
        
        name = "OUTPUT_DEQUANT/" + name_video + "/" + sstr.str() + "/files_dequant_qcoeff.txt";
        cout << name << endl;
        TComLab215::files_dequant_qcoeff.open(name.c_str(),std::ofstream::out);
        
        name = "OUTPUT_DEQUANT/" + name_video + "/" + sstr.str() + "/files_dequant_offset.txt";
        cout << name << endl;
        TComLab215::files_dequant_offset.open(name.c_str(),std::ofstream::out);
        
        name = "OUTPUT_DEQUANT/" + name_video + "/" + sstr.str() + "/files_dequant_qbits.txt";
        cout << name << endl;
        TComLab215::files_dequant_qbits.open(name.c_str(),std::ofstream::out);
/*        
        name = "OUTPUT_DEQUANT/" + name_video + "/" + sstr.str() + "/files_dequant_abs.txt";
        cout << name << endl;
        TComLab215::files_dequant_abs.open(name.c_str(),std::ofstream::out);
*/        
        name = "OUTPUT_DEQUANT/" + name_video + "/" + sstr.str() + "/files_dequant_mult.txt";
        cout << name << endl;
        TComLab215::files_dequant_mult.open(name.c_str(),std::ofstream::out);
/*        
        name = "OUTPUT_DEQUANT/" + name_video + "/" + sstr.str() + "/files_dequant_min.txt";
        cout << name << endl;
        TComLab215::files_dequant_min.open(name.c_str(),std::ofstream::out);
*/        
        name = "OUTPUT_DEQUANT/" + name_video + "/" + sstr.str() + "/files_dequant_sum.txt";
        cout << name << endl;
        TComLab215::files_dequant_sum.open(name.c_str(),std::ofstream::out);
        
        name = "OUTPUT_DEQUANT/" + name_video + "/" + sstr.str() + "/files_dequant_shift.txt";
        cout << name << endl;
        TComLab215::files_dequant_shift.open(name.c_str(),std::ofstream::out);
/*        
        name = "OUTPUT_DEQUANT/" + name_video + "/" + sstr.str() + "/files_dequant_2scomp.txt";
        cout << name << endl;
        TComLab215::files_dequant_2scomp.open(name.c_str(),std::ofstream::out);
*/        
        name = "OUTPUT_DEQUANT/" + name_video + "/" + sstr.str() + "/files_dequant_clip2.txt";
        cout << name << endl;
        TComLab215::files_dequant_clip2.open(name.c_str(),std::ofstream::out);
        
        name = "OUTPUT_DEQUANT/" + name_video + "/" + sstr.str() + "/files_dequant_ifresult.txt";
        cout << name << endl;
        TComLab215::files_dequant_ifresult.open(name.c_str(),std::ofstream::out);
    }
    
#endif
    
}

void TComLab215::closeFiles(){
    
#if EN_SAD

    if(TComLab215::print_sad == 8){
        for(int i = 0; i < 8; i++){
            TComLab215::files_sad_8_org[i].close();
            TComLab215::files_sad_8_cur[i].close();
        }
    }

    if(TComLab215::print_sad == 16){
        for(int i = 0; i < 16; i++){
            TComLab215::files_sad_16_org[i].close();
            TComLab215::files_sad_16_cur[i].close();
        }
    }
    
    if(TComLab215::print_sad == 32){
        for(int i = 0; i < 32; i++){
            TComLab215::files_sad_32_org[i].close();
            TComLab215::files_sad_32_cur[i].close();
        }
    }
    
    if(TComLab215::print_sad == 64){
        for(int i = 0; i < 64; i++){
            TComLab215::files_sad_64_org[i].close();
            TComLab215::files_sad_64_cur[i].close();
        }
    }
    
    if(TComLab215::print_sad == 128){
        for(int i = 0; i < 128; i++){
            TComLab215::files_sad_128_org[i].close();
            TComLab215::files_sad_128_cur[i].close();
        }
    }
    
    if(TComLab215::print_sad == 256){
        for(int i = 0; i < 256; i++){
            TComLab215::files_sad_256_org[i].close();
            TComLab215::files_sad_256_cur[i].close();
        }
    }
    
    if(TComLab215::print_sad == 512){
        for(int i = 0; i < 256; i++){
            TComLab215::files_sad_512_org[i].close();
            TComLab215::files_sad_512_cur[i].close();
        }
    }
    
    if(TComLab215::print_sad == 1024){
        for(int i = 0; i < 256; i++){
            TComLab215::files_sad_1024_org[i].close();
            TComLab215::files_sad_1024_cur[i].close();
        }
    }
    
    if(TComLab215::print_sad == 2048){
        for(int i = 0; i < 256; i++){
            TComLab215::files_sad_2048_org[i].close();
            TComLab215::files_sad_2048_cur[i].close();
        }
    }

    if(TComLab215::print_sad == 4096){
        for(int i = 0; i < 256; i++){
            TComLab215::files_sad_4096_org[i].close();
            TComLab215::files_sad_4096_cur[i].close();
        }
    }
    
#endif
    
#if EN_QUANT
    
    if(TComLab215::print_quant == 1){
        TComLab215::files_quant_w.close();
        TComLab215::files_quant_qcoeff.close();
        TComLab215::files_quant_offset.close();
        TComLab215::files_quant_qbits.close();
        TComLab215::files_quant_mult.close();
        TComLab215::files_quant_min.close();
        TComLab215::files_quant_sum.close();
        TComLab215::files_quant_shift.close();
        TComLab215::files_quant_2scomp.close();
        TComLab215::files_quant_clip.close();
    }
    
#endif
    
#if EN_DEQUANT
    
    if(TComLab215::print_dequant == 1){
        TComLab215::files_dequant_clip1.close();
        TComLab215::files_dequant_w.close();
        TComLab215::files_dequant_qcoeff.close();
        TComLab215::files_dequant_offset.close();
        TComLab215::files_dequant_qbits.close();
//        TComLab215::files_dequant_abs.close();
        TComLab215::files_dequant_mult.close();
//        TComLab215::files_dequant_min.close();
        TComLab215::files_dequant_sum.close();
        TComLab215::files_dequant_shift.close();
//        TComLab215::files_dequant_2scomp.close();
        TComLab215::files_dequant_clip2.close();
        TComLab215::files_dequant_ifresult.close();
    }
    
#endif
    
}