#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, *v, *sol_max, s, s_max, G, nr_sol;

typedef struct Map
{
    int weight;
    int cost;
    char object[50];
}Map;

Map* arr;

int check(int k)
{
    int weight = 0;
    for (int j = 0; j < k; j++)
        weight += v[j] * arr[j].weight; //? însumăm greutățile obiectelor selectate până la pasul k
    if (weight <= G)
        return 1;   //? se verifică dacă se depășește capacitatea rucsacului
    else 
        return 0;
}

void optimal()
{
    int s = 0;
    nr_sol++;
    for (int j = 0; j < n; j++)
        s = s + v[j] * arr[j].cost;          //? se calculează câștigul din obiectele selectate
    if ((nr_sol == 0) || (s > s_max)) //? dacă s>suma maximă, soluția este mai bună
    {
        s_max = s;
        for (int j = 0; j < n; j++)
            sol_max[j] = v[j];
    }
}

void backTracking(int k)
{
    int i;
    for (i = 0; i <= 1; i++)
    {
        v[k] = i;
        if (check(k))
            if (k == n)
                optimal();
            else
                backTracking(k + 1);
    }
}

void read(char* testFile)
{
    FILE* input = fopen(testFile, "r");
    fscanf(input, "%d %d", &n, &G);

    arr = (Map*)malloc(n * sizeof(Map));
    v = (int*)calloc(n, sizeof(int));
    sol_max = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++)
        fscanf(input, "%s %d %d", arr[i].object, &arr[i].weight, &arr[i].cost);
    fclose(input);
}

void printer()
{
    nr_sol++;
    printf("Castigul maxim este %d\n", s_max);
    for (int j = 0; j < n; j++)
        if (sol_max[j])
            printf("%s G:%d C:%d\n", arr[j].object, arr[j].weight, arr[j].cost);
}

void test()
{
    char testFile[] = "./tests/testX";
    for(char i = '1'; i <= '2'; i++)
    {
        printf("\n\n");
        testFile[strlen(testFile) - 1] = i;
        read(testFile);
        backTracking(0);
        printf("ANSWER FOR TEST FILE %c\n", i);
        printer();

        //! Se eliberează memoria, se resetează variabilele la starea inițială și se pregătește programul pentru un posibil următor test
        free(arr);
        free(v);
        free(sol_max);
        s = 0;
        s_max = 0;
        nr_sol = 0;
        G = 0;
        n = 0;
    }
}

int main()
{
    test();
    printf("\n");
}