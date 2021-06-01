#include <stdio.h>
#include <stdlib.h>

typedef struct Map {
    int** img;
    unsigned int imageSize;
    unsigned int objectNumber;
}Map;

Map* init(FILE* input) {
    Map* map = (Map*)malloc(sizeof(Map));
    fscanf(input, "%d", &map->imageSize);
    map->imageSize += 2;

    map->img = (int**)calloc(map->imageSize, sizeof(int*));
    
    for(int i = 0; i < map->imageSize; i++) {
        map->img[i] = (int*)calloc(map->imageSize, sizeof(int));
        for(int j = 0; j < map->imageSize; j++) {
            map->img[i][j] = -1;
        }
    }
    for(int i = 1; i < map->imageSize - 1; i++)
    {
        for(int j = 1; j < map->imageSize - 1; j++)
            fscanf(input, "%d", &map->img[i][j]);
    }
    return map;
}
void destroy(Map** map) {
    for(int i = 0; i < (*map)->imageSize; i++)
        free((*map)->img[i]);
    free((*map)->img);
    *map = NULL;
    printf("Image memory destroyed\n");
}

void transform(Map* map, unsigned int i, unsigned int j, int transformer) {
    if((i > 0 && i < map->imageSize - 1) && (j > 0 && j < map->imageSize - 1))
    {
        if(map->img[i][j] == 0) {
            map->img[i][j] = transformer;
            transform(map, i - 1 , j, transformer);
            transform(map, i + 1 , j, transformer);
            transform(map, i , j - 1, transformer);
            transform(map, i , j + 1, transformer);
            transform(map, i + 1 , j + 1, transformer);
            transform(map, i - 1 , j - 1, transformer);
            transform(map, i + 1 , j - 1, transformer);
            transform(map, i - 1 , j + 1, transformer);
        }
    }
}

int countObjects(Map* map) {
    int transformer = 0;
    for(int i = 1; i < map->imageSize - 1; i++)
    {
        for(int j = 1; j < map->imageSize - 1; j++)
            if(map->img[i][j] == 0) {
                transformer++;
                transform(map, i, j, transformer);
            }
    }
    return transformer;
} 

void showMap(Map* map) {
    for(int i = 0; i < map->imageSize; i++) {
        for(int j = 0; j < map->imageSize; j++) {
            if(map->img[i][j] == -1)
                printf("%d  ", map->img[i][j]);
            else
                printf("%d   ", map->img[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int testANS[5] = {0};
    int l = 0;
    char fileTemplate[] = "./tests/testX";

    FILE* input;
    for(char i = '1'; i <= '5'; i++)
    {
        fileTemplate[12] = i;
        input = fopen(fileTemplate, "r");
        Map* map = init(input);
        testANS[l] = countObjects(map);
        printf("Objects: %d", testANS[l++]);
        printf("\n");
        showMap(map);
        destroy(&map);

        fclose(input);
    }
    for(int i = 0; i < 5; i++) {
        printf("Answer for test file %d: %d objects\n", i + 1, testANS[i]);
    }
    return 0;
}