#include <process.h>
#include <math.h>

#include "matrix.h"
#include "state.h"

#define pi 3.14159265359

int main(int argc, char *argv[])
{
    MATRIX_TYPE _Rot2_ofCam1[3][3] = {cos(31.3997/(180.0/pi)), cos(98.4211/(180.0/pi)), cos(120.0000/(180.0/pi)),
                                      cos(98.4211/(180.0/pi)), cos(31.3997/(180.0/pi)), cos(120.0000/(180.0/pi)),
                                      cos(60.0000/(180.0/pi)), cos(60.0000/(180.0/pi)), cos(45.00000/(180.0/pi))}; // 生成相机2相对于相机1的旋转矩阵
    int row = sizeof(_Rot2_ofCam1) / sizeof(_Rot2_ofCam1[0]);
    int column = sizeof(_Rot2_ofCam1[0]) / sizeof(_Rot2_ofCam1[0][0]);
    Matrix *Rot2_ofCam1 = Matrix_gen(row, column, _Rot2_ofCam1);

    MATRIX_TYPE _p_B[3][1] = {1500, 600, 1200}; // 生成相机2相对于相机1的旋转矩阵
    row = sizeof(_p_B) / sizeof(_p_B[0]);
    column = sizeof(_p_B[0]) / sizeof(_p_B[0][0]);
    Matrix *p_B = Matrix_gen(row, column, _p_B);

    MATRIX_TYPE _Rot_ofCam1[3][3] = {0,0,-1,
                                     0,1,0,
                                     1,0,0}; // 生成相机2相对于相机1的旋转矩阵
    row = sizeof(_Rot_ofCam1) / sizeof(_Rot_ofCam1[0]);
    column = sizeof(_Rot_ofCam1[0]) / sizeof(_Rot_ofCam1[0][0]);
    Matrix *Rot_ofCam1 = Matrix_gen(row, column, _Rot_ofCam1);

    M_print(Rot2_ofCam1);
    M_print(p_B);

    Matrix *mat_3 = M_mul(Rot2_ofCam1, p_B);
    M_print(mat_3);

    Matrix *mat_4 = M_mul(Rot_ofCam1, p_B);
    M_print(mat_4);

    system("pause");
    /* code */
    return 0;
}
