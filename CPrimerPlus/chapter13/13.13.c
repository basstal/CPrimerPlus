#include <stdio.h>
void comparison(int (*data)[30]);
int main(void)
{
    int num_pic[20][30];
    char ch_pic[20][31];
    FILE *fp, *fp_out;
    int i, j;

    fp = fopen("picture.txt", "r+");

    for (i = 0; i < 20; i++)
        for (j = 0; j < 30; j++)
            fscanf(fp, "%d ", &num_pic[i][j]);
    comparison(num_pic);
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 30; j++)
            switch (num_pic[i][j])
            {
            case 0:
                ch_pic[i][j] = ' ';
                break;
            case 1:
                ch_pic[i][j] = '.';
                break;
            case 2:
                ch_pic[i][j] = ',';
                break;
            case 3:
                ch_pic[i][j] = ':';
                break;
            case 4:
                ch_pic[i][j] = '~';
                break;
            case 5:
                ch_pic[i][j] = '*';
                break;
            case 6:
                ch_pic[i][j] = '=';
                break;
            case 7:
                ch_pic[i][j] = '%';
                break;
            case 8:
                ch_pic[i][j] = '#';
                break;
            case 9:
                ch_pic[i][j] = '@';
                break;
            }
        ch_pic[i][30] = '\0';
    }

    fp_out = fopen("new.txt", "w+");
    for (i = 0; i < 20; i++)
        fprintf(fp_out, "%s\n", ch_pic[i]);

    fclose(fp_out);
    fclose(fp);
    return 0;
}
void comparison(int (*data)[30])
{
    int i, j;

    for (i = 0; i < 20; i++)
        for (j = 0; j < 30; j++)
        {
            if (i != 0 && i != 19 && j != 0 && j != 29)
                if (data[i][j] - data[i + 1][j] > 1 && data[i][j] - data[i - 1][j] > 1 && data[i][j] - data[i][j + 1] > 1 && data[i][j] - data[i][j - 1] > 1)
                    data[i][j] = (data[i + 1][j] + data[i - 1][j] + data[i][j + 1] + data[i][j - 1]) / 4;
                else if (i == 0 && j == 0)
                    if (data[i][j] - data[i + 1][j] > 1 && data[i][j] - data[i][j + 1] > 1)
                        data[i][j] = (data[i + 1][j] + data[i][j + 1]) / 2;
                    else if (i == 0 && j == 29)
                        if (data[i][j] - data[i][j - 1] > 1 && data[i][j] - data[i + 1][j] > 1)
                            data[i][j] = (data[i][j - 1] + data[i + 1][j]) / 2;
                        else if (i == 19 && j == 0)
                            if (data[i][j] - data[i - 1][j] > 1 && data[i][j] - data[i][j + 1] > 1)
                                data[i][j] = (data[i - 1][j] + data[i][j + 1]) / 2;
                            else if (i == 19 && j == 29)
                                if (data[i][j] - data[i - 1][j] > 1 && data[i][j] - data[i][j - 1] > 1)
                                    data[i][j] = (data[i - 1][j] + data[i][j - 1]) / 2;
                                else if (i == 0)
                                    if (data[i][j] - data[i + 1][j] > 1 && data[i][j] - data[i][j + 1] > 1 && data[i][j] - data[i][j - 1] > 1)
                                        data[i][j] = (data[i + 1][j] + data[i][j - 1] + data[i][j + 1]) / 3;
                                    else if (i == 19)
                                        if (data[i][j] - data[i - 1][j] > 1 && data[i][j] - data[i][j + 1] > 1 && data[i][j] - data[i][j - 1] > 1)
                                            data[i][j] = (data[i - 1][j] + data[i][j - 1] + data[i][j + 1]) / 3;
                                        else if (j == 0)
                                            if (data[i][j] - data[i][j + 1] > 1 && data[i][j] - data[i - 1][j] > 1 && data[i][j] - data[i + 1][j] > 1)
                                                data[i][j] = (data[i][j + 1] + data[i + 1][j] + data[i - 1][j]) / 3;
                                            else if (j == 29)
                                                if (data[i][j] - data[i][j - 1] > 1 && data[i][j] - data[i - 1][j] > 1 && data[i][j] - data[i + 1][j] > 1)
                                                    data[i][j] = (data[i][j - 1] + data[i + 1][j] + data[i - 1][j]) / 3;
        }
}
