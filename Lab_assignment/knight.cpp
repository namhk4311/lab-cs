#include "knight.h"


int rescue = -1;
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

int knight[1000]; int event[200010]; int MaxHP = 999;
void knightcheck(string s, int &HP,int &level,int &remedy,int &maidenkiss, int &phoenixdown)
{    
    stringstream ss(s);
    ss >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
    MaxHP = HP;
}

int event1_5damage(int event, int levelIO)
{
    int k; int res;
    int event1 = 10, event2 = 15, event3 = 45, event4 = 75, event5 = 95;
    switch (event)
    {
        case 1:
        {
            res = event1*levelIO; 
        } 
        case 2:
        {
            res = event2*levelIO;
        }
        case 3:
        {
            res = event3*levelIO;
        }
        case 4:
        {
            res = event4*levelIO;
        }
        case 5:
        {
            res = event5*levelIO;
        }
    }
    return res;
}

void eventcheck(string s, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue)
{
    int eventindex = -1, k = 0;
    stringstream ss(s);
    while(ss >> eventindex) event[k++] = eventindex;
    for (int i = 0; i < k; i++)
    {
        int flagevent = -1;
        if (event[i] == 0) {rescue = 1; break;} // save the princess
        // gap cac sự kiện có ma sk tu 1 đen 5
        if (1 <= event[i] && event[i] <= 5)  
        {
            int b = (i + 1) % 10; 
            int levelIO = i + 1; // tính level của đối thủ
            (levelIO > 6) ? ((b > 5) ? b : 5) : b; 
            if (level > levelIO && level < 10) level++; //win
            else if (level == levelIO) continue; //draw
            else if (level < levelIO)  //lose
            {
                int tmp; tmp = event[i]; 
                HP = HP - event1_5damage(tmp,levelIO);
            }
            if (HP <= 0 && phoenixdown == 0) {rescue = 0; break;}
            else if (HP <=0 && phoenixdown > 0)
            {
                HP = MaxHP;
                phoenixdown--;
                continue;
            }
        } 
        //gap su kien co ma = 6
        if (event[i] == 6)  
        {
            flagevent = i + 4;
            int levelIO = i + 1;
            if (level > levelIO) 
            {
                level = level + 2; 
                if (level > 10) level = 10;
            }
            else if (level == levelIO) continue;
            else if (level < levelIO) // hiep si thua va o trang thai ti hon
            {
                int currentHP = HP;
                if (HP >= 5) HP = HP/5;
                else HP = 1;
                if (remedy >= 1)
                { 
                    remedy--;
                    HP = currentHP;
                    continue;
                }
                if (HP <= 0 && phoenixdown > 0) 
                {
                    HP = MaxHP;
                    phoenixdown--;
                    continue;
                }   
            }   
        }
        if (i == flagevent) {
            HP *= 5; 
            if (HP > MaxHP) HP = MaxHP;
        }
        //gap ma su kien co ma = 7
        if (event[i] == 7)
        {

        }
    }
    if (rescue == -1) rescue = 1; //nếu chạy hết mã sự kiện mà rescue = -1 thì đổi lại thành rescue = 1 (thành công)

}

void inputData(string file_input, int HP, int level, int remedy, int maidenkiss, int phoenixdown)
{
    ifstream ipp;
    ipp.open(file_input);
    string info, events, nfile;
    getline(ipp,info);
    getline(ipp,events);
    getline(ipp,nfile);
    knightcheck(info, HP, level, remedy, maidenkiss, phoenixdown);
    eventcheck(events, HP, level, remedy, maidenkiss, phoenixdown, rescue);
}

void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) 
{
        inputData(file_input, HP, level, remedy,maidenkiss, phoenixdown);
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
}