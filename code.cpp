#include <bits/stdc++.h>
using namespace std;

static bool lineWin(const array<string,3>& b, char c){
    // rows
    for(int i=0;i<3;i++) if(b[i][0]==c && b[i][1]==c && b[i][2]==c) return true;
    // cols
    for(int j=0;j<3;j++) if(b[0][j]==c && b[1][j]==c && b[2][j]==c) return true;
    // diagonals
    if(b[0][0]==c && b[1][1]==c && b[2][2]==c) return true;
    if(b[0][2]==c && b[1][1]==c && b[2][0]==c) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<string,3> b;
    for(int i=0;i<3;i++){
        if(!(cin>>b[i])) return 0; // no input
        if((int)b[i].size()!=3){
            cout<<"invalid\n";
            return 0;
        }
    }

    int cx=0, co=0, cd=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            char ch=b[i][j];
            if(ch=='x') cx++;
            else if(ch=='o') co++;
            else if(ch=='-') cd++;
            else { cout<<"invalid\n"; return 0; }
        }
    }

    // basic count validity: x starts, so cx==co or cx==co+1
    auto counts_valid = [&](){ return (cx==co) || (cx==co+1); };
    bool winX=lineWin(b,'x');
    bool winO=lineWin(b,'o');

    // invalid if counts impossible
    if(co>cx || cx>co+1){ cout<<"invalid\n"; return 0; }

    // both cannot win
    if(winX && winO){ cout<<"invalid\n"; return 0; }

    if(winX){
        // x must have just moved
        if(cx==co+1) cout<<"win\n"; else cout<<"invalid\n";
        return 0;
    }
    if(winO){
        // o must have just moved
        if(cx==co) cout<<"lose\n"; else cout<<"invalid\n";
        return 0;
    }

    // no one wins
    if(!counts_valid()){ cout<<"invalid\n"; return 0; }
    if(cd==0) cout<<"tie\n"; else cout<<"ongoing\n";
    return 0;
}

