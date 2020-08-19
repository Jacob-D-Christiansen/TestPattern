#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        print("fail arguments");
        exit(1);
    }
    
    int width = atoi(argv[1]);
    int totalWidth = width * 7;
    int height = atoi(argv[2]);
    
    if(width <= 0 || height <= 0)
    {
        print("fail not right size");
        exit(1);
    }
    
    testPattern = malloc(sizeof(uint32_t) * height * totalWidth);
    int y, x;
    
    for(y = 0; y < height; y++)
    {
        for(x = 0; x < width; x++)
        {
            
        }
    }
}
