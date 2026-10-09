const int MAX = 1e5+100; 
bool v[MAX];
int sp[MAX];
void spf(){
	for (int i = 2; i < MAX; i += 2)	sp[i] = 2;
	for (int i = 3; i < MAX; i += 2){
		if (!v[i]){
			sp[i] = i;
			for (int j = i; (j*i) < MAX; j += 2){
				if (!v[j*i])	v[j*i] = true, sp[j*i] = i;
			}
		}
	}
}