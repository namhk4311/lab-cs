#include "knight.h"

const int inf = 2e9 +7;
int event[200010]; int MaxHP = 999, MaxLevel = 10, MaxRemedy = 99, MaxMaidenkiss = 99, MaxPhoenixdown = 99; 
string file_pack[3];

void Lowercase(string &pack)
{
    for (int i = 0; i < pack.length(); i++)
    {
        if ('A' <= pack[i] && pack[i] <= 'Z') pack[i] = pack[i] - 'A' + 'a';
    }
}

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) 
{
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

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
            break; 
        } 
        case 2:
        {
            res = event2*levelIO;
            break;
        }
        case 3:
        {
            res = event3*levelIO;
            break;
        }
        case 4:
        {
            res = event4*levelIO;
            break;
        }
        case 5:
        {
            res = event5*levelIO;
            break;
        }
    }
    return res;
}

//truong hop HP la so nguyen to
bool checkHPisprime(int HP) //Lancelot
{
    if (HP == 1) return false;
    else if (HP == 2) return true;
    else {
        for (int i = 2; i <= HP/2 + 1; i++)
        {
            if (HP % i == 0) return false;
        }
    }
    return true;
}

int fibonacci(int n)
{
    if (n < 2 && n > 0) return 1;
    if (n == 0) return 0;
    else return fibonacci(n - 1) + fibonacci(n - 2); 
}

int Fibocheck(int HP)
{
    int n = 0, res = 0;
    while (fibonacci(n) < HP && HP > 1)
    {
        res = fibonacci(n++);
    }
    if (HP == 1) res = 1;
    return res; 
}

bool checkmountUPshape(int a[], int k)
{
    int cntup = 1;
    for (int i = 0; i < k; i++)
    {
        if (a[i] < a[i + 1] && i + 1 != k) cntup++;
    }
    if (cntup == k) {return true;}
    return false;
}

bool checkmountDOWNshape(int a[], int k)
{
    int cntdown = 1;
     for (int i = 0; i < k; i++)
    {
        if (a[i] > a[i + 1] && i + 1 != k) cntdown++;
    }
    if (cntdown == k) {return true;}
    return false;
}

void check_Mush_Ghost(int event13, int &HP)
{
    int lengthofindex13 = log10(event13) + 1;
    int arr[100];
    for (int i = lengthofindex13 - 1; i >= 0; i--){
        arr[i] = event13 % 10;
        event13 = event13/10;
    }
    int tmp = arr[0]*10 + arr[1];
    if (tmp == 13)
    {
        int n2 = -1, numn2[100]; int maxi = -1, mini = -1, maxValue = -inf, minValue = inf; 
        ifstream docfilemush;
        docfilemush.open(file_pack[2]); int cnt = 0, cnt_of_numn2 = 0;
            string numstring[250], stringn2;  
            docfilemush >> n2;
            docfilemush >> stringn2;
            for (int i = 0; i < stringn2.length(); i++)
            {
                if (stringn2[i] != ',') numstring[cnt] += stringn2[i];
                else cnt++;                              
            }
            for (int i = 0; i <= cnt; i++)
            {
                stringstream(numstring[i]) >> numn2[cnt_of_numn2++];
            }
            for (int i = 0; i < cnt_of_numn2; i++)
            {
                if (numn2[i] >= maxValue)
                {
                    maxValue = numn2[i];
                    if (i > maxi) maxi = i;
                }
                if (numn2[i] <= minValue)
                {
                    minValue = numn2[i];
                    if (i > mini) mini = i;
                }
            }
            for (int i = 2; i < lengthofindex13; i++) //bat dau check chuoi theo su kien arr[i] 
            {   
                if (arr[i] == 1)
                {
                    HP = HP - (maxi + mini);
                }
                if (arr[i] == 2)
                {
                    int mtx = -2, mti = -3;
                    if (checkmountUPshape(numn2,cnt_of_numn2))
                    {
                        mtx = numn2[cnt_of_numn2];
                        mti = cnt_of_numn2 - 1;
                        HP = HP - (mtx + mti);
                    }        
                    else if (checkmountDOWNshape(numn2,cnt_of_numn2))
                    {
                        mtx = numn2[0];
                        mti = 0;
                        HP = HP - (mtx + mti);
                    }
                    else 
                    {
                        HP = HP - (mtx + mti);
                    }
                }
                if (arr[i] == 3)
                {
                    int maxValue2 = -inf, minValue2 = inf, maxi2 = inf, mini2 = inf;
                    for (int t = 0; t < cnt_of_numn2; t++)
                    {
                        if (numn2[t] < 0) {numn2[t] = -numn2[t];}
                        numn2[t] = (17*numn2[t] + 9)%257;        
                    }
                    for (int t = 0; t < cnt_of_numn2; t++)
                    {
                        if (numn2[t] >= maxValue2) 
                        {
                            maxValue2 = numn2[t];
                            if (t < maxi2) maxi2 = t;
                        }
                        if (numn2[t] <= minValue2) 
                        {
                            minValue2 = numn2[t];
                            if (t < mini2) mini2 = t;
                        }
                    }
                    HP = HP - (maxi2 + mini2);
                }
                if (arr[i] == 4)
                {
                    int maxValue2 = -inf, minValue2 = inf, max2_3x = -inf, max2_3i = inf, flagsuccess = 0;
                    for (int t = 0; t < cnt_of_numn2; t++)
                    {
                        if (numn2[t] < 0) {numn2[t] = -numn2[t];}
                        numn2[t] = (17*numn2[t] + 9)%257;        
                    }
                    for (int t = 0; t < 3; t++)
                    {
                        if (numn2[t] >= maxValue2) 
                        {
                            maxValue2 = numn2[t];
                        }
                        if (numn2[t] <= minValue2) 
                        {
                            minValue2 = numn2[t];
                        }
                    }
                    for (int t = 0; t < 3; t++)
                    {
                        if (numn2[t] != maxValue2 && numn2[t] >= max2_3x)
                        {
                            max2_3x = numn2[t];
                            if (max2_3i > t) max2_3i = t;
                            flagsuccess++;
                        }
                    }
                    if (!flagsuccess) {max2_3x = -5; max2_3i = -7;} 
                    HP = HP - (max2_3x + max2_3i);
                }
            }
        docfilemush.close();
    }
}

bool findMerlin(string s, string s1){
    for (int i = 0; i < s.length(); i++)
    {
        int j = 0; string tmp;
        while (j < s1.length()) 
        {
            tmp += s[i+j];
            j++;
        }
        if (tmp == s1) 
        {
            return true;
        }
    }
    return false;
}

void eventcheck(string s, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue, string file_pack[])
{
    int eventindex = -1, k = 0, currentLevel = -1, currentHP = -1; bool flagencounterevent19 = false, flagencounterevent18 = false, flagintial = false, flag999 = false;
    int flagevent6 = -1, flagevent7 = -1;
    bool Lancelot = false;
    stringstream ss(s);
    while(ss >> eventindex) event[k++] = eventindex;
    if (checkHPisprime(HP)) {Lancelot = true;}
    for (int i = 0; i < k; i++)
    {       
        if (HP == 999 && !flagintial)
        {
            flagintial = true;
            flag999 = true;
        }
        if (HP <= 0) {rescue = 0; break;}

        if (i == flagevent6) 
        {
            HP *= 5; 
            if (HP > MaxHP) HP = MaxHP;
        }

        if (i == flagevent7) //sau khi bien thanh ech qua 3 su kien thi quay ve binh thuong
        {
            level = currentLevel;
        }

        if (event[i] == 0) {rescue = 1; break;} // save the princess
        // gap cac su kien co ma tu 1 đen 5
        if (1 <= event[i] && event[i] <= 5)  
        {
            if (flag999 || Lancelot) {level++; continue;}
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
        //gap ma su kien = 6
        if (event[i] == 6)  
        { 
            if (flag999 || Lancelot) {level++; continue;}
            if (i < flagevent7) continue; //bi bien thanh ech ma gap Shaman thi bo qua
            int levelIO = i + 1;
            if (level > levelIO) 
            {
                level = level + 2; 
                if (level > 10) level = 10;
            }
            else if (level == levelIO) continue;
            else if (level < levelIO) // hiep si thua va o trang thai ti hon (giu nguyen current HP va MaxHP)
            {
                flagevent6 = i + 4;
                currentHP = HP;
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
        //gap ma su kien = 7 (Vajsh)
        if (event[i] == 7)
        {
            if (flag999 || Lancelot) {level++; continue;}
            if (i < flagevent6) continue; //bi bien thanh ti hon ma gap Vajsh thi bo qua
            int levelIO = i + 1;
            if (level > levelIO) 
            {
                level = level + 2;
                if (level > 10) level = 10;
            }
            else if (level == levelIO) continue;
            else if (level < levelIO) 
            {
                currentLevel = level;
                flagevent7 == i + 4;
                level = 1;
                if (maidenkiss > 0)
                {
                    maidenkiss--;
                    level = currentLevel;
                }
            }
        }
        if (event[i] == 11) //Nhat dc nam MushMario 
        {            
            int n1 = ((level + phoenixdown) % 5 + 1) * 3, intial = 99, s1 = 0;
            for (int i = 1; i <= n1; i++)
            {
                s1 += intial;
                intial -= 2;
            }
            HP = HP + (s1 % 100);
            int checkPrimeHP = HP; bool flag = false;
            if (checkPrimeHP == 1) {checkPrimeHP = 2;}
            else if (checkPrimeHP == 2) {checkPrimeHP = 3;}
            else {
                while (flag != true)
                {
                    int cntcheck = 0;
                    flag = true;
                    for (int i = 2; i <= checkPrimeHP/2 + 1; i++) 
                    {
                        if(checkPrimeHP % i == 0) flag = false;
                        cntcheck++;
                    }
                    if (cntcheck == 0) flag = false;
                    checkPrimeHP++;
                }
            }
            HP = checkPrimeHP;
            if (HP > MaxHP) HP = MaxHP;
        }
        if (event[i] == 12) 
        {
            Fibocheck(HP);
        }
        
        check_Mush_Ghost(event[i],HP);
        // check lai event 15,16,17 co su dung lien khong
        if (event[i] == 15 && remedy < MaxRemedy)
        {
            remedy++;
        }
        if (event[i] == 16 && maidenkiss < MaxMaidenkiss)
        {
            maidenkiss++;
        }
        if (event[i] == 17 && phoenixdown < MaxPhoenixdown)
        {
            phoenixdown++;
        }
        if (event[i] == 19 && !flagencounterevent19)
        {   
            flagencounterevent19 = true; bool lootRemedy = false, lootMaidenkiss = false;
            int r1, c1, pack1[100][100]; 
            ifstream fileap;
            fileap.open(file_pack[1]);
                fileap >> r1;
                fileap >> c1;
                for (int r = 0; r < r1; r++)
                {
                    for (int c = 0; c < c1; c++)
                    {
                        fileap >> pack1[r][c];
                    }
                }
            
                for (int r = 0; r < r1; r++) //check loot
                {
                    int loot = 0;
                    for (int c = 0; c < c1; c++)
                    {
                        if (loot > 3) break;
                        else if (pack1[r][c] == 16)
                        { 
                            remedy++; lootRemedy = true;
                            loot++;
                        }
                        else if (pack1[r][c] == 17)
                        {
                            maidenkiss++; lootMaidenkiss = true;
                            loot++;
                        }
                        else if (pack1[r][c] == 18)
                        {
                            phoenixdown++;
                            loot++;
                        }
                    }
                }
                if (i < flagevent6 && lootRemedy)
                {
                    remedy--; flagevent6 = -1; HP = currentHP; 
                }

                //con truong hop cua phoenixdown

                if (i < flagevent7 && lootMaidenkiss) 
                {
                    maidenkiss--; flagevent7 = -1; level = currentLevel;
                }
        }
        if (event[i] == 99)
        {
            if (flag999 || (Lancelot && level >= 8) || level >= 10)
            {
                level = 10;
            }
            else {rescue = 0; break;}
        }   
        if (event[i] == 18 && !flagencounterevent18)
        {
            flagencounterevent18 = true;
            ifstream fileMerlin;
            fileMerlin.open(file_pack[0]);
                int n9, t = 1; 
                fileMerlin >> n9;
                while (t <= n9)
                {
                    string packstring;
                    fileMerlin >> packstring;
                    if (findMerlin(packstring,"Merlin") || findMerlin(packstring,"merlin")) HP += 3;
                    else {
                        Lowercase(packstring);
                        for (int k = 0; k < packstring.length(); i++)
                        {                        
                            if (packstring[i] == 'm'||packstring[i] == 'e' ||packstring[i] == 'r' || packstring[i] == 'l' || packstring[i] == 'i' || packstring[i] == 'n')
                            {
                                HP += 2;
                            }
                        }
                    }
                    if (HP > MaxHP) HP = MaxHP;
                    t++;
                }    
            fileMerlin.close();
        }
    }
    
    if (k == flagevent6) 
    {
        HP *= 5; 
        if (HP > MaxHP) HP = MaxHP;
    }
    
    if (k == flagevent7) 
    {
        level = currentLevel;
    }
    if (rescue == -1) rescue = 1; //nếu chạy hết mã sự kiện mà rescue = -1 thì đổi lại thành rescue = 1 (thành công)
}

void filecheck(string s)
{
    string tmp[10]; int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ',') file_pack[cnt] += s[i];
        else cnt++;
    }
}

void inputData(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue)
{
    rescue = -1;
    ifstream ipp;
    ipp.open(file_input);
    string info, events, nfile;
    getline(ipp,info);
    getline(ipp,events);
    getline(ipp,nfile);
    knightcheck(info, HP, level, remedy, maidenkiss, phoenixdown);
    filecheck(nfile);
    eventcheck(events, HP, level, remedy, maidenkiss, phoenixdown, rescue, file_pack);
    ipp.close();
}

void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) 
{
        inputData(file_input, HP, level, remedy,maidenkiss, phoenixdown, rescue);
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
}