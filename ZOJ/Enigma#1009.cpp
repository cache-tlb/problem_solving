#include<iostream>
#include<string>
using namespace std;
void ROT(int rot[],int m)
{
    rot[0]++;
    if(rot[0] >= m){
        rot[0] %= m;
        rot[1]++;
    }
    if(rot[1] >= m){
        rot[1] %= m;
        rot[2]++;
    }
    if(rot[2] >= m){
        rot[2] %= m;
    }            
}
int main()
{
    int m;
    int cnt = 1;
    while(cin >> m){
        if(m == 0) break;
        if(cnt > 1) cout <<endl;
        string rotor;
        int shift[3][26];
        int shiftr[3][26];
        for(int i = 0; i < 3; i++){
            cin >> rotor;
            for(int j = 0; j < m; j++){
                shift[i][j] = rotor[j] - 'A' - j;
                shiftr[i][ j+shift[i][j] ] = -shift[i][j];
            }    
        }
        /*for(int i = 0; i < 3; i++){
            for(int j = 0; j < m; j++){
                cout << shiftr[i][j] << ' ';
            }
            cout << endl;
        }*/
        cout << "Enigma " << cnt << ":" <<endl;
        int n;
        cin >> n;
        
        while(n--){
            string text;
            cin >> text;
            int len = text.length();
            int rot[3] = {};
            string ans;
            for(int i = 0; i < len; i++){
                char ctext = text[i];
                char a = ctext + shiftr[2][ (ctext-'A'-rot[2]+m)%m ];
                if(a < 'A') a += m;
                else if(a - 'A' >= m) a -= m;
                ctext = a;
                //cout << a << ' ';
                a = ctext + shiftr[1][ (ctext-'A'-rot[1]+m)%m ];
                if(a < 'A') a += m;
                else if(a - 'A' >= m) a -= m;
                //cout << a << ' ';
                ctext = a;
                a = ctext + shiftr[0][ (ctext-'A'-rot[0]+m)%m ];
                ROT(rot,m);
                if(a < 'A') a += m;
                else if(a - 'A' >= m) a -= m;
                //cout << a << endl;
                ans.push_back((char)(a - 'A' + 'a'));
            }
            cout << ans << endl;
        }
        cnt++;
        //cout << endl;
    }            
    return 0;
}
