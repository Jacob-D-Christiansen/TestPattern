#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
void print_pixmap8(uint8_t *pixmap, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      uint8_t *pixel = &pixmap[4*((y * width) + x)];
      printf("#%02x%02x%02x ",
             pixel[0],
             pixel[1],
             pixel[2]);
    }
    printf("\n");
  }
}

uint8_t bar_color[] = {
    255,255,255,
    255,255,0,
    0,255,255,
    0,255,0,
    255,0,255,
    255,0,0,
    0,0,255
};

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("fail arguments");
        exit(1);
    }
    
    int width = atoi(argv[1]);
    int totalWidth = width * 7;
    int height = atoi(argv[2]);
    
    if(width <= 0 || height <= 0)
    {
        printf("fail not right size");
        exit(1);
    }
    
    uint8_t *testPattern = malloc(height * totalWidth*4);
    uint8_t *pixel = testPattern;
    int y, x;
    
    for(y = 0; y < height; y++)
    {
        for(int c = 0; c<7;c++)
        {
            for(x = 0; x < width; x++)
            {
                pixel[0] = bar_color[c*3+0];
                pixel[1] = bar_color[c*3+1];
                pixel[2] = bar_color[c*3+2];
                pixel[3] = 255;
                pixel += 4;
            }
        }
    }

    //print_pixmap8(testPattern,totalWidth,height);
    FILE *fp = fopen("testimage.data","w");
    fwrite(testPattern, height * totalWidth*4,1,fp);
    fclose(fp);
    return 0;
}
