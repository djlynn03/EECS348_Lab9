#include <stdlib.h>
#include <stdio.h>


int possibleScores(int score)
{
    for (int a = 0; a < score; a++)
    {
        for (int b = 0; b < score; b++)
        {
            for (int c = 0; c < score; c++)
            {
                for (int d = 0; d < score; d++)
                {
                    for (int e = 0; e < score; e++)
                    {
                        if ((a * 8) + (b * 7) + (c * 6) + (d * 3) + (e * 2) == score)
                        {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt, %d Safety\n", a, b, c, d, e);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    while (1)
    {
        int score = 0;
        printf("Enter 0 or 1 to STOP\nEnter the NFL Score: ");
        scanf("%d", &score);
        if (score <= 1)
        {
            return 0;
        }
        possibleScores(score);
    }
}
