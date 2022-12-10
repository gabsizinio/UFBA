#include <iostream>

using namespace std;

int main(){
    int v1[5];
    int v2[5];
    int s1 = 0, s2 = 0, s3 = 0;

    for(int i = 0; i < 5; i++){
        cin >> v1[i];
    }
    for(int k = 0; k < 5; k++){
        cin >> v2[k];
    }
    for(int l = 0; l < 5; l++){
        for(int a = 0; a < 5; a++){
            if(v1[l] == v2[a]){
                s1 += 1;
            }
        }
        if(s1 == 0){
            s2 += v1[l];
        }else{
            s3 += v1[l];
        }
        s1 = 0;
    }

    cout << s2 << endl;
    cout << s3 << endl;



    return 0;
}