#include <bits/stdc++.h>
using namespace std;

string data = "Pjmu mu b amtjfo rfsr. Mr jbu cffi fiaowtrfg cw rjf uvcurmrvrmqi amtjfo. Wqv bof xfow nvahw. Rjf amtjfo jbu cffi coqhfi";


int main(){
	int count[36];

	for (int i=0; i<36; i++) count[i] = 0;
	for (int i=0; i<data.length(); i++){
		if(data[i] == 'a' || data[i] == 'A') count[1]++;
		if(data[i] == 'b' || data[i] == 'B') count[2]++;
		if(data[i] == 'c' || data[i] == 'C') count[3]++;
		if(data[i] == 'd' || data[i] == 'D') count[4]++;
		if(data[i] == 'e' || data[i] == 'E') count[5]++;
		if(data[i] == 'f' || data[i] == 'F') count[6]++;
		if(data[i] == 'g' || data[i] == 'G') count[7]++;
		if(data[i] == 'h' || data[i] == 'H') count[8]++;
		if(data[i] == 'i' || data[i] == 'I') count[9]++;
		if(data[i] == 'j' || data[i] == 'J') count[10]++;
		if(data[i] == 'k' || data[i] == 'K') count[11]++;
		if(data[i] == 'l' || data[i] == 'L') count[12]++;
		if(data[i] == 'm' || data[i] == 'M') count[13]++;
		if(data[i] == 'n' || data[i] == 'N') count[14]++;
		if(data[i] == 'o' || data[i] == 'O') count[15]++;
		if(data[i] == 'p' || data[i] == 'P') count[16]++;
		if(data[i] == 'q' || data[i] == 'Q') count[17]++;
		if(data[i] == 'r' || data[i] == 'R') count[18]++;
		if(data[i] == 's' || data[i] == 'S') count[19]++;
		if(data[i] == 't' || data[i] == 'T') count[20]++;
		if(data[i] == 'u' || data[i] == 'U') count[21]++;
		if(data[i] == 'v' || data[i] == 'V') count[22]++;
		if(data[i] == 'w' || data[i] == 'W') count[23]++;
		if(data[i] == 'x' || data[i] == 'X') count[24]++;
		if(data[i] == 'y' || data[i] == 'Y') count[25]++;
		if(data[i] == 'z' || data[i] == 'Z') count[26]++;
	}

	 cout << "a" << count[1] << endl;
	 cout << "b" << count[2] << endl;
	 cout << "c" << count[3] << endl;
	 cout << "d" << count[4] << endl;
	 cout << "e" << count[5] << endl;
	 cout << "f" << count[6] << endl;
	 cout << "g" << count[7] << endl;
	 cout << "h" << count[8] << endl;
	 cout << "i" << count[9] << endl;
	 cout << "j" << count[10] << endl;
	 cout << "k" << count[11] << endl;
	 cout << "l" << count[12] << endl;
	 cout << "m" << count[13] << endl;
	 cout << "n" << count[14] << endl;
	 cout << "o" << count[15] << endl;
	 cout << "p" << count[16] << endl;
	 cout << "q" << count[17] << endl;
	 cout << "r" << count[18] << endl;
	 cout << "s" << count[19] << endl;
	 cout << "t" << count[20] << endl;
	 cout << "u" << count[21] << endl;
	 cout << "v" << count[22] << endl;
	 cout << "w" << count[23] << endl;
	 cout << "x" << count[24] << endl;
	 cout << "y" << count[25] << endl;
	 cout << "z" << count[26] << endl;
}