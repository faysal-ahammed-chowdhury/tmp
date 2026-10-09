const int p = 1e9+7;
int choose[1010][1010];

void calc(){
    for ( int i = 0; i < 1010; i++ ) choose[i][0] = 1, choose[i][i] = 1;
    for ( int i = 1; i < 1010; i++ ){
        for ( int j = 1; j < 1010; j++ ){
            choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) % p;
        }
    }
}