void mx_printchar(char c);

void mx_pyramid(int n) {
    if (n < 1 || n % 2 != 0)
        return;
    
    int j = n - 1; 
    int c = 1; 
    int q = 0; 
    for (int i = 1; i <= n; i++) {
        for (int k = j; k > 0; k--) 
            mx_printchar(' ');
        
        if (i >= 1 && i <= n / 2) {
            if (i == 1) {
                mx_printchar('/');
                mx_printchar('\\');
            }
            else {
                mx_printchar('/');

                for (int i = 0; i < 2 * q + 1; i++) 
                    mx_printchar(' '); 

                mx_printchar('\\');

                for (int i = 0; i < c; i++) 
                    mx_printchar(' ');

                mx_printchar('\\');
                q++;
                c++;
            }
        }

        if (i > n / 2 && i <= n) {
            mx_printchar('/');

            if (i == n) {
                for (int i = 0; i < 2 * q + 1; i++) 
                    mx_printchar('_');
            }
            else {
                for (int i = 0; i < 2 * q + 1; i++) 
                    mx_printchar(' '); 
            }

            mx_printchar('\\');

            for (int i = c; i > 1; i--) 
                mx_printchar(' ');

            mx_printchar('|');
            q++;
            c--;
        }  

        j--;
        mx_printchar('\n');
    }
}

