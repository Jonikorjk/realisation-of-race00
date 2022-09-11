void mx_printchar(char c);

void mx_cube(int n) {
    if (n <= 1)
        return;

    int len_i = 3 + n + n / 2;
    int len_j = 2 * n + n / 2 + 1 + 2;
    char s[len_i][len_j];
    int slash_shift = 0;

    for (int i = 0; i < len_i; i++)
        for (int j = 0; j < len_j; j++)
            s[i][j] = ' ';

    for (int i = 0; i < len_i; i++) {
        for (int j = 0; j < len_j; j++) {
            if (i == 0 
                || i == n / 2 + 1 
                || i == len_i - 1) {
                if (i == 0) {
                    if (j < n / 2 + 1) {
                        s[i][j] = ' ';
                        continue;
                    }
                    if (j == n / 2 + 1 || j == len_j - 1)
                        s[i][j] = '+';
                    else
                        s[i][j] = '-';
                } 
                else if (j <= n * 2 + 1) {
                    if (j == 0 || j == n * 2 + 1)
                        s[i][j] = '+';
                    else
                        s[i][j] = '-';
                }
            }
            else if (i < n / 2 + 1) { 
                if (j < n / 2) {
                    s[i][j] = ' ';
                    continue;
                }
                s[i][j - slash_shift] = '/';
                s[i][j + n * 2 + 1 - slash_shift] = '/';
                s[i + n + 1][j + n * 2 + 1 - slash_shift] = '/';
                s[i + n + 1][j + n * 2 + 1 - slash_shift + 1] = '\0';
                slash_shift++;
                break;
            } 
            else { 
                if (i > n / 2 + 1 && i < len_i - 1) {
                    s[i][0] = '|';
                    s[i][n * 2 + 1] = '|';
                    s[i - n / 2 - 1][len_j - 1] = '|';
                }
            }

            if (i > n / 2 + 1 && i < 2 * n + 1)
                s[n + 1][len_j - 1] = '+';
        }
    }

    int temp_pr = 0;

    for (int i = 0; i < len_i; i++) {
        for (int j = 0; j < len_j - temp_pr; j++)
            mx_printchar(s[i][j]);
        mx_printchar('\n');
        if (i >= 1 + n) {
            temp_pr++;
        }
    }
}

