#define _CRT_SECURE_NO_WARNINGS 
#include    <stdlib.h>
#include    <stdio.h>
#include    <math.h>
#include    "cglec.h"

void Yoko(Image img,  int y1, int y2, int xh, int g)
{ /* この部分をプログラム */

    int x, y;

   for (y = y1; y < y2; y++)
   {
         x = xh;
         *(img.Data + x * img.Ny + y) = g;
        
   }
}
void Tate(Image img, int x1, int x2, int yh, int g)
{ /* この部分をプログラム */

    int x, y;

    for (x = x1; x < x2; x++)
    {
        y = yh;
        *(img.Data + x * img.Ny + y) = g;

    }
}


void Oudoiro(Image imgR, Image imgG, Image imgB, int x0, int y0)
{ /* この部分をプログラム */

    int x, y;
    int xx = ((500 - 300) / 12);
    int yy = ((500 - 200) / 16);
    int x1 = 150 + (xx * x0);
    int y1 = 100 + (yy * y0);
    int x2 = 150 + (xx * (x0 + 1));
    int y2 = 100 + (yy * (y0 + 1));
    for (y = y1 + 1; y < y2; y++)
    {
        for (x = x1 + 1; x < x2; x++)
        {
            *(imgR.Data + x * imgR.Ny + y) = 102;
            *(imgG.Data + x * imgG.Ny + y) = 102;
            *(imgB.Data + x * imgB.Ny + y) = 0;
        }

    }
}
void Akairo(Image imgR, Image imgG, Image imgB, int x0, int y0)
{ /* この部分をプログラム */

    int x, y;
    int xx = ((500 - 300) / 12);
    int yy = ((500 - 200) / 16);
    int x1 = 150 + (xx * x0);
    int y1 = 100 + (yy * y0);
    int x2 = 150 + (xx * (x0 + 1));
    int y2 = 100 + (yy * (y0 + 1));
    for (y = y1 + 1; y < y2; y++)
    {
        for (x = x1 + 1; x < x2; x++)
        {
            *(imgR.Data + x * imgR.Ny + y) = 204;
            *(imgG.Data + x * imgG.Ny + y) = 51;
            *(imgB.Data + x * imgB.Ny + y) = 0;
        }

    }
}

void Hadairo(Image imgR, Image imgG, Image imgB, int x0, int y0)
{ /* この部分をプログラム */

    int x, y;
    int xx = ((500 - 300) / 12);
    int yy = ((500 - 200) / 16);
    int x1 = 150 + (xx * x0);
    int y1 = 100 + (yy * y0);
    int x2 = 150 + (xx * (x0 + 1));
    int y2 = 100 + (yy * (y0 + 1));
    for (y = y1 + 1; y < y2; y++)
    {
        for (x = x1 + 1; x < x2; x++)
        {
            *(imgR.Data + x * imgR.Ny + y) = 255;
            *(imgG.Data + x * imgG.Ny + y) = 165;
            *(imgB.Data + x * imgB.Ny + y) = 0;
        }

    }
}
int main(void)
{
        int Nx=500, Ny=500,x,y,x1,x2,y1,y2,xx,yy;
        unsigned char* r = (unsigned char*)malloc(sizeof(unsigned char) * Nx * Nx);
        unsigned char* g = (unsigned char*)malloc(sizeof(unsigned char) * Nx * Nx);
        unsigned char* b = (unsigned char*)malloc(sizeof(unsigned char) * Nx * Nx);
        if ((r == NULL) || (b == NULL) || (g == NULL))
        {
            printf("メモリエラー"); exit(0);
        }
        Image imgR = { (unsigned char*)b, Nx, Ny };
        Image imgG = { (unsigned char*)r, Nx, Ny };
        Image imgB = { (unsigned char*)g, Nx, Ny };

        //全部白にする
        CglSetAll(imgR, 255);
        CglSetAll(imgG, 255);
        CglSetAll(imgB, 255);

        //塗るマスの左下、右下
        x1 = 150, x2=350;
        y1 = 100, y2 = 400;

        //一マスのおおきさ
        xx = ((Nx - 300) / 12);
        yy = ((Ny - 200) / 16);

        //マス目
        for (x = x1; x < x2; x = x+xx) {
            Yoko(imgG, y1-10, y2+3, x, 0);
            Yoko(imgB, y1 - 10, y2 +3, x, 0);
            Yoko(imgR, y1 - 10, y2 +3, x, 0);
        }
        for (y = y1;y < y2; y = y + yy) {
            Tate(imgG, x1 - 10, x2 + 3, y, 0);
            Tate(imgB, x1 - 10, x2 + 3, y, 0);
            Tate(imgR, x1 - 10, x2 + 3, y, 0);
        }
        
        //Oudoiro(imgR, imgG, imgB, x1, x1 + xx, y1, y1 + yy);
        //Oudoiro(imgR, imgG, imgB, x1+(xx*1), x1 + (xx*2), y1, y1 + yy);


        //下から塗っていく
        int i;
        for (i = 0; i < 12; i++) {
            if (i < 4 || i>7) {
                Oudoiro(imgR, imgG, imgB, i, 0);
            }
        }

        for (i = 0; i < 12; i++) {
            if ((i>0&&i<4)||(i>7&&i<11)) {
                Oudoiro(imgR, imgG, imgB, i, 1);
            }
        }

        for (i = 0; i < 12; i++) {
            if ((i > 1 && i < 5) || (i > 6 && i < 10)) {
                Akairo(imgR, imgG, imgB, i, 2);
            }
        }
        
        for (i = 0; i < 12; i++) {
            if (i > 1 && i<10) {
                Akairo(imgR, imgG, imgB, i, 3);
            }
            if (i == 0 || i == 1 || i == 10 || i == 11) {
                Hadairo(imgR, imgG, imgB, i, 3);
            }
        }

        for (i = 0; i < 12; i++) {
            if (i > 2 && i < 9) {
                Akairo(imgR, imgG, imgB, i, 4);
            }
            if (i<3||i>8) {
                Hadairo(imgR, imgG, imgB, i, 4);
            }
        }

        for (i = 0; i < 12; i++) {
            if (i==3||i==5||i==6||i==8) {
                Akairo(imgR, imgG, imgB, i, 5);
            }
            if (i<2||i>9||i==4||i==7) {
                Hadairo(imgR, imgG, imgB, i, 5);
            }
            if (i == 2 || i == 9) {
                Oudoiro(imgR, imgG, imgB, i, 5);
            }
        }

        for (i = 0; i < 12; i++) {
            if (i > 3 && i < 8) {
                Akairo(imgR, imgG, imgB, i, 6);
            }
            if (i < 4 || i>7) {
                Oudoiro(imgR, imgG, imgB, i, 6);
            }
        }

        for (i = 0; i < 12; i++) {
            
            if(i>0&&i<11)
            Oudoiro(imgR, imgG, imgB, i, 7);
            if (i == 4 || i == 7) {
                Akairo(imgR, imgG, imgB, i, 7);
            }
            
        }

        for (i = 0; i < 12; i++) {

            if (i > 1 && i < 8)
                Oudoiro(imgR, imgG, imgB, i, 8);
            if (i == 4) {
                Akairo(imgR, imgG, imgB, i, 8);
            }

        }

        for (i = 0; i < 12; i++) {

            if (i > 2 && i < 10)
                Hadairo(imgR, imgG, imgB, i, 9);

        }

        for (i = 0; i < 12; i++) {

            if (i > 0 && i<11)
                Oudoiro(imgR, imgG, imgB, i, 10);
            if (i>2&&i<7) {
                Hadairo(imgR, imgG, imgB, i, 10);
            }

        }

        for (i = 0; i < 12; i++) {

            if (i > 1) {
                Hadairo(imgR, imgG, imgB, i, 11);
            }
            if (i==1||i==3||i==4||i==8) {
                Oudoiro(imgR, imgG, imgB, i, 11);
            }
        }

        for (i = 0; i < 12; i++) {

            if (i > 1&&i<11) {
                Hadairo(imgR, imgG, imgB, i, 12);
            }
            if (i == 1 || i == 3 || i == 7) {
                Oudoiro(imgR, imgG, imgB, i, 12);
            }
        }

        for (i = 0; i < 12; i++) {

            if (i > 1 && i <8) {
                Oudoiro(imgR, imgG, imgB, i, 13);
            }
            if (i == 5 || i == 6 || i == 8) {
                Hadairo(imgR, imgG, imgB, i, 13);
            }
        }

        for (i = 0; i < 12; i++) {

            if (i > 1 && i < 11) {
                Akairo(imgR, imgG, imgB, i, 14);
            }
        }

        for (i = 0; i < 12; i++) {

            if (i > 2 && i < 8) {
                Akairo(imgR, imgG, imgB, i, 15);
            }

        }
        CglSaveColorBMP(imgR, imgG, imgB, "Graphics.bmp");
        free(r); free(g); free(b);
}
