#include "knight.h"

/* DISPLAY DATA */
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

/* 5 FUNCTIONS FOR MUSH GHOST */ 
// FIRST FUNCTION //
// The second largest number in 3 first numbers
int max(int mg1[]){
    int firstMax, secondMax;
    firstMax = mg1[1] > mg1[0]? mg1[1] : mg1[0];
    secondMax = mg1[1] + mg1[0] - firstMax;
    if (mg1[2] > firstMax){
        secondMax = firstMax;
    } 
    else if (mg1[2] > secondMax && mg1[2] != firstMax){
        secondMax = mg1[2];
    }
    return secondMax;
}
// SECOND FUNCTION //
// Last position of max in untransformed sequence
int vtmax(int mg[], int n2){
    int p = 0, max = mg[0];
    for (int i = 1; i < n2; i++){
        if (mg[i] > max){
            max = mg[i];
            p = i;
        }
    } 
    for (int i = n2-1; i >= 0; i--){
        if (mg[i]==max){
            p = i;
            break;
        }
    }
    return p;
}
// THIRD FUNCTION //
// Last position of min in untransformed sequence
int vtmin(int mg[],int n2){
    int p = 0, min = mg[0];
    for (int i = 1; i < n2; i++){
        if (mg[i] < min){
            min = mg[i];
            p = i;
        }
    }  
    for (int i = n2-1; i >= 0; i--){
        if (mg[i] == min){
            p = i;
            break;
        }
    }
    return p;
}
// FOURTH FUNCTION //
// Last position of max in transformed sequence
int vtmax3(int mg1[],int n2){
    int p = 0, max = mg1[0];
    for (int i = 1; i < n2; i++){
        if (mg1[i]>max){
            max = mg1[i];
            p = i;
        }
    }
    for (int i = 0; i < n2; i++){
        if (mg1[i] == max){
            p = i;
            break;
        }
    }
    return p;
}
//FIFTH FUNCTION //
// Last position of min in untransformed sequence
int vtmin3(int mg1[],int n2){
    int p = 0, min = mg1[0];
    for (int i = 1; i < n2; i++){
        if (mg1[i] < min){
            min = mg1[i];
            p = i;
        }
    }
    for (int i = 0; i < n2; i++){
        if (mg1[i] == min){
            p = i;
            break;
        }
    }
    return p;
}

/* CHECK STRING FOR MERLIN EVENT */
// Whole "Merlin" in string
int substring(string s, string s1){   
    int j = 0, count = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == s1[j]){
            count++;
            j++;
        }
        else{   
            if (count == s1.length()){
                return 1;
            }
            count = 0;
            j = 0;
        }
    }
    if (count == s1.length()){
        return 1;
    }
    else{
        return 0;
    }
}

/* CHECK PRIME NUMBER */
bool prime(int n) {
    if (n < 2){
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if (n%i == 0){
            return false;
        }
    }
    return true;
}

/* SUM OF N1 GREATEST 2-DIGITS ODD NUMBERS */
// FOR EVENT 11 - MARIO MUSH //
int s1(int n1){
    int sum = 0;
    int n = 101;
    for (int i = 0; i < n1; i++){
        sum += (n-2);
        n -= 2;
    }
    return sum;
}

/* FIBONACCI */
// FOR EVENT 12 - FIBONACCI MUSH //
int fibo(int n){ 
    if (n == 1){
        return 1;
    }
    int f[100], m;
    f[0] = 1;
    f[1] = 1;
    int i = 1;
    while (f[i] < n){
        i++; 
        f[i] = f[i-1] + f[i-2];
        m = f[i]; 
    }
    m = f[i-1];
    return m;
}

/* COUNTING DAMAGE */
// FOR EVENT 1 TO 5 //
double damage(int n, int levelO){
    double damage;
    if (n == 1){
        damage =  1*levelO*10;
    }
    else if (n == 2){
        damage = 1.5*levelO*10;
    } 
    else if (n == 3){
        damage = 4.5*levelO*10;
    }
    else if (n == 4){
        damage = 7.5*levelO*10;
    }
    else if (n == 5){
        damage = 9.5*levelO*10;
    }
    return damage;
}

/* COUNTING FROG/SMALL TRANSFORMATION TURNS */
// FOR EVENT 6, 7 AND RELATED EVENTS //
void turn(int & count, bool & small, int & HP, int & maxHP, bool & frog, int & level, int & LV){
    count++;
    if (count == 3){
        count = 0;
        if (small == true){
            small = false;
            HP = HP*5;
            if (HP > maxHP){
                HP = maxHP;
            }
        }
        if (frog == true){
            frog = false;
            level = LV;
        }                  
    }
}

/* ARTHUR */
bool arthur(int & maxHP){
    if (maxHP == 999){
        return true;
    }
    return false ;
}

/* LANCELOT */
bool lancelot(int & maxHP){
    if (prime(maxHP) == true){
        return true;
    }
    return false;
}
/* EVENT 0 IS DIRECTLY ADDED IN FUNCTION adventureToKoopa */
// KNGHT RESCUE PRINCESS SUCCESSFULLY //

/* EVENT 1 TO EVENT 5 */
// MADBEAR (1), BANDIT (1.5), LORDLUPIN (4.5), ELF (7.5), TROLL (9.5) //
void event1to5(int & tam, int & HP, int & level, int & phoenixdown, int & rescue, int & maxHP, int n, int levelO, int b, int i, bool & small){
    if (arthur(maxHP) == true){
        if (level <= 9){
            level++;
        }
    }
    else if (lancelot(maxHP) == true){
        if (level<=9){
            level++;
        }
    }
    else{
        b = i % 10;
        levelO = i > 6?(b > 5?b : 5) : b;
        if (level > levelO){
            if (level <= 9){
                level++;
            }
        }   
        else if (level < levelO){
            HP = HP - damage(tam, levelO);
            if (HP <= 0){
                if (phoenixdown > 0){
                    if (small == true){
                        small = false;
                    } 
                    HP = maxHP;
                    phoenixdown--;
                }
                else{
                    rescue = 0;
                } 
            }
            else{
                rescue = -1;
            }
        }
        else{
            rescue = -1;
        }
    }
}

/* EVENT 6 */
// SHAMAN WITCH - KNIGHT BECOME SMALL IF LOSING //
void event6(int & HP, int & maxHP, int & level, int & remedy, int & rescue,int levelO,bool &small,int b,int i){
    if (arthur(maxHP) == true){
        if (level <= 8){
            level += 2;
        }
        else if (level==9){
            level++;
        }
    }
    else if (lancelot(maxHP) == true){
        if (level <= 8){
            level += 2;
        }
        else if (level==9){
            level++;
        }
    }
    else{
        b = i % 10;
        levelO = i > 6?(b > 5?b : 5) : b;
        small = false;
        if (level > levelO){
            if (level <= 8){
                level += 2;
            }
            else if (level==9){
                level++; 
            }
        }
        else if (level < levelO){
            small = true;
            if (remedy > 0){
                remedy--;
                small = false;
            }
            else if (remedy == 0){   
                if (HP < 5){
                    HP = 1;
                }     
                else{
                    HP = HP/5;
                }
            }
        }
    }
}

/* EVENT 7 */
// SIREN VAJSH - KNIGHT BECOME FROG IF LOSING //
void event7(int & maxHP, int & LV, int & level, int & maidenkiss, int & rescue, int levelO, bool & frog, int b, int i){
    if (arthur(maxHP) == true){
        if (level <= 8){
            level += 2;
        }
        else if (level==9){
            level++;
        }
    }
    else if (lancelot(maxHP)==true){
        if (level <= 8){
            level += 2;
        }
        else if (level==9){
            level++;
        }
    }
    else{
        b = i % 10;
        levelO = i > 6? (b > 5? b : 5) : b;
        frog = false;
        if (level > levelO){
            if (level <= 8){
                level += 2;
            }
            else if (level==9){
                level++;
            }
        }  
        else if (level < levelO){
            frog = true;
            LV = level;
            level = 1;
            if (maidenkiss > 0){
                level = LV;
                maidenkiss--;
                frog = false;
            }
        }
    }
}

/* EVENT 11 */
// MARIO MUSH //
void event11(int & HP, int & level, int & phoenixdown, int & maxHP, int & rescue){
    int n1;
    n1 = ((level + phoenixdown)%5 + 1) * 3;
    HP = HP + (s1(n1) % 100);
    HP++;
    while (prime(HP) == false){
        HP++;
    }
    if (HP > maxHP){
        HP = maxHP;
    }
}

/* EVENT 12 */
// FIBONACCI MUSH //
void event12(int & HP, int & level, int & phoenixdown, int & maxHP, int & rescue){
    HP = fibo(HP);
    rescue = -1;
}

/* EVENT 99 */
// BOWSER //
void event99(int & maxHP, int & level, int & rescue){
    if ((arthur(maxHP) == true) || (lancelot(maxHP) == true && level >= 8) || (level == 10)){
        rescue = -1;
    }
    else{
        rescue = 0;
    }
}

/* EVENT 15, 16, 17 IS DIRECTLY ADDED TO FUNCTION adventureToKoopa */

/* ADVENTURE TO KOOPA */
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue){
    /* READING FILE: KNIGHT DATA, EVENT DATA, AND EVENT'S FILE DATA */
    int event[1000], i = 1, n, size, j = 0;
    string line1, line2, line3, filename, strfilename, savefilename[3];
    // Open file_input //
    ifstream file;
    file.open(file_input);
    // Reading knight data
    getline(file, line1);
    stringstream l1(line1);
    l1 >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
    // Reading event data
    getline(file, line2);
    stringstream l2(line2);
    while (l2 >> n){
        event[i] = n;
        i++;
    }
    size = i-1; // Size of array events
    // Reading file's name of Mush ghost, Asclepius, and Merlin's data
    getline(file, line3);
    stringstream l3(line3);
    l3 >> filename;
    if (filename != ""){
        strfilename = filename;
    }
    for (int i = 0; i < strfilename.length(); i++){
        if (strfilename[i] != ','){
            savefilename[j] += strfilename[i];
        }
        else{
            j++;
        }
    }
    // Reading Asclepius, Merlin, and Mush ghost data from file
    int r1, c1;
    int acp[1000][1000];
    int n9;
    string mrl[1000];
    int n2;
    int mg[1000];
    for (int n = 0; n <= j; n++){ 
        // Asclepius
        if (savefilename[n].find("clepius") != string::npos){
            ifstream rfile;
            rfile.open(savefilename[n]);
            rfile >> r1 >> c1;
            for (int i = 0; i < r1; i++){
                for (int j = 0; j < c1; j++){
                    rfile >> acp[i][j];
                }
            }
        }
        // Merlin
        else if (savefilename[n].find("merlin") !=string::npos){
            ifstream tfile;
            tfile.open(savefilename[n]);
            tfile >> n9;
            for (int i = 0; i <= n9; i++){
                getline(tfile, mrl[i]);
            }
        }
        // Mush ghost
        else if (savefilename[n].find("mush_ghost") != string::npos){
            ifstream wfile;
            wfile.open(savefilename[n]);
            wfile >> n2;
            string mghost[n2];
            for (int i = 0; i < n2; i++){
                getline(wfile, mghost[i], ',');
                mg[i] = stoi(mghost[i]);
            } 
        }
    }
    /* EVENTS RUNNING */
    // Declare variables for running events
    int maxHP = HP; // For saving maxHP
    int levelO, b; // For counting damage
    bool small, frog; // For event 6, 7 and related events
    int count = 0, count1 = 0, count2 = 0;
    int LV; // For saving initial level (event 7)
    bool countmg; // For event 13 (mush ghost)
    int h; // For event 13 (mush ghost type 2)
    i = 1; // For running events (event[i])
    rescue = -1; // Initial rescue
    // Start running events //
    while (i <= size) {
        // Event 0 //
        // Auto rescue princess successfully
        if (event[i] == 0){
            rescue = 1;
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            break;
        }
        // Event 1 to 5 //
        // MadBear (1), Bandit (1.5), LordLupin (4.5), Elf (7.5), Troll (9.5)
        else if (event[i] >= 1 && event[i] <= 5) {
            int tam = event[i];
            event1to5(tam, HP, level, phoenixdown, rescue, maxHP, i, levelO, b, i, small);
            if (i == size){
                if (rescue == 0){
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
                else if (rescue == -1){
                    rescue = 1;
                    if (frog == true || small == true){
                        turn(count, small, HP, maxHP, frog, level, LV);
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }
            else {
                if (rescue == -1){
                    if (frog == true || small == true){
                        turn(count, small, HP, maxHP, frog, level, LV);
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    i++;
                }
                else if (rescue == 0){
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }
        }
        // Event 6 //
        // Shaman witch - Become small if losing
        else if (event[i] == 6){   
            if (small == true || frog == true){    
                turn(count, small, HP, maxHP, frog, level, LV);
                if (i < size){
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    i++;
                } 
                else if (i == size){
                    rescue = 1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }
            else if (small == false && frog == false){
                event6(HP, maxHP, level, remedy, rescue, levelO, small, b, i);
                if (i == size){  
                    rescue = 1; 
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
                else {   
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    i++;  
                }
            }
        }
        // Event 7 //
        // Siren Vajsh - Become frog if losing
        else if (event[i] == 7){   
            if (small == true || frog == true){  
                turn(count, small, HP, maxHP, frog, level, LV);
                if (i < size){
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    i++;
                } 
                else if (i == size){
                    rescue = 1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }
            else if (small == false && frog == false){
                event7(maxHP, LV, level, maidenkiss, rescue, levelO, frog, b, i);
                if (i == size){
                    rescue = 1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
                else{
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    i++;
                }
            }
        }
        // Event 11 //
        // Picking up Mario mush
        else if (event[i] == 11){
            event11(HP, level, phoenixdown, maxHP, rescue);
            if (i == size){
                rescue = 1;
                if (frog == true || small == true){
                    turn(count, small, HP, maxHP, frog, level, LV);
                }
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                break;
            }
            else{
                if (frog == true || small == true){
                    turn(count, small, HP, maxHP, frog, level, LV);
                }
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                i++;
            }     
        }
        // Event 12 //
        // Picking up Fibonacci mush
        else if (event[i] == 12){
            event12(HP, level, phoenixdown, maxHP, rescue);
            if (i == size){
                rescue = 1;
                if (frog == true || small == true){
                    turn(count, small, HP, maxHP, frog, level, LV);
                }
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                break; 
            }
            else{
                if (frog == true || small == true)
                    turn(count, small, HP, maxHP, frog, level, LV);
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                i++;
            }
        }
        // Event 15 //
        // Picking up Remedy - Release knight from tiny state
        else if (event[i] == 15){
            if (remedy <= 98) remedy++;
            // Check if knight is in tiny state for using Remedy
            if (small == true){
                small = false;
                HP = HP*5;
                if (HP > maxHP){
                    HP = maxHP;
                }
                remedy--;
            }
            if (i == size){
                if (frog == true || small == true){
                    turn(count, small, HP, maxHP, frog, level, LV);
                }
                rescue = 1;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                break;
            }
            else{
                if (frog == true || small == true){
                    turn(count, small, HP, maxHP, frog, level, LV);
                }
                rescue = -1;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                i++;
            }
        }
        // Event 16 //
        // Picking up MaidenKiss - Release knight from frog state
        else if (event[i] == 16){
            if (maidenkiss <= 98){
                maidenkiss++;
            }
            // Check if knight is in frog state for using Remedy
            if (frog == true){
                frog = false;
                level = LV;
                maidenkiss--;
            }
            if (i == size){
                rescue = 1;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                break;  
            }
            else{
                rescue = -1;
                if (frog == true || small == true){
                    turn(count, small, HP, maxHP, frog, level, LV);
                }
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                i++;   
            }
        }
        // Event 17 //
        // Picking up PhoenixDown
        else if (event[i] == 17){   
            if (phoenixdown <= 98){
                phoenixdown++;
            }
            // Check for using PhoenixDown
            if (i == size){
                rescue = 1;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                break;
            }   
            else{
                if (frog == true || small == true){
                    turn(count,small,HP,maxHP,frog,level,LV);
                }
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                i++;
            }
        }
        // Event 99 //
        // Bowser
        else if (event[i] == 99){   
            event99(maxHP, level, rescue);
            if (rescue == 0){   
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                break;
            }
            else if (rescue == -1){
                if (i == size){   
                    level = 10;
                    rescue = 1;
                    if (frog == true || small == true){
                        turn(count, small, HP, maxHP, frog, level, LV);
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
                else{   
                    level = 10;
                    if (frog == true || small == true){
                        turn(count, small, HP, maxHP, frog, level, LV);
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    i++;
                }
            }
        }
        // Event 19 //
        // Asclepius
        else if (event[i] == 19){
            // If meeting Asclepius again/meeting Asclepius more than one time
            if (count1 > 0){
                if (i == size){
                    rescue = 1;
                    if (frog == true || small == true){
                        turn(count,small,HP,maxHP,frog,level,LV);
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break; 
                }
                else {                   
                    if (frog == true || small == true){
                        turn(count, small, HP, maxHP, frog, level, LV);
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    i++;
                }
            }
            // If meeting Asclepius the first time
            else {
                count1++;
                for (int j = 0; j < r1; j++){
                    int take = 0;
                    for (int k = 0; k < c1; k++){
                        // Remedy
                        if (acp[j][k] == 16){ 
                            if (take < 3){
                                take++;
                                if (remedy <= 98){
                                    remedy++;
                                }      
                            }
                        }
                        // MaidenKiss
                        else if (acp[j][k] == 17){ 
                            if (take < 3){
                                take++;
                                if (maidenkiss <= 98){
                                    maidenkiss++;
                                }
                            }
                        }
                        // PhoenixDown
                        else if (acp[j][k] == 18){ 
                            if (take < 3){
                                take++;
                                if (phoenixdown <= 98){
                                    phoenixdown++;
                                }
                            }
                        }
                    }
                }
                // Check order of event
                if (i == size){
                    rescue = 1;
                    if (frog == true || small == true){
                        turn(count, small, HP, maxHP, frog, level, LV);
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
                else{
                    if (frog == true || small == true){
                        turn(count, small, HP, maxHP, frog, level, LV);
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    i++;
                }
            }
        }
        // Event 18 //
        // Merlin
        else if (event[i] == 18){
            // If meeting Merlin again/meeting Merlin more than one time
            if (count2 > 0){
                if (i == size){
                    rescue = 1;
                    if (frog == true || small == true){
                        turn(count, small, HP, maxHP, frog, level, LV);
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
                else {
                    if (frog == true || small == true){
                        turn(count, small, HP, maxHP, frog, level, LV);
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    i++;
                }
            }
            // If meeting Merlin the first time
            else{
                count2++;
                for (int j = 1; j <= n9; j++){
                    if ((substring(mrl[j], "Merlin") == 1) || (substring(mrl[j], "merlin") == 1)){
                        HP += 3;   
                        if (HP > maxHP){
                            HP = maxHP;
                        }
                    }
                    else{   
                        int mm = 0, ee = 0, rr = 0, ll = 0, ii = 0, nn = 0;
                        for (int k = 0; k < mrl[j].length(); k++){   
                            mrl[j][k] = tolower(mrl[j][k]);
                            if (mrl[j][k] == 'm'){
                                mm++;
                            }
                            else if (mrl[j][k] == 'e'){
                                ee++;
                            }
                            else if (mrl[j][k] == 'r'){
                                rr++;
                            }
                            else if (mrl[j][k] == 'l'){
                                ll++;
                            }
                            else if (mrl[j][k] == 'i'){
                                ii++;
                            }
                            else if (mrl[j][k] == 'n'){
                                nn++;
                            }
                        }
                        if (mm >= 1 && ee >= 1 && rr >= 1 && ll >= 1 && ii >= 1 && nn >= 1){
                            HP += 2;
                            if (HP > maxHP){
                                HP = maxHP;
                            }   
                        }
                    }
                }
            // Check order of event
                if (i == size){
                    rescue = 1;
                    if (frog == true || small == true){
                        turn(count, small, HP, maxHP, frog, level, LV);
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
                else {
                    if (frog == true || small == true){
                        turn(count, small, HP, maxHP, frog, level, LV);
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    i++;
                }
            }
        }  
        // Event 13 //
        // Mush ghost //
        else if (event[i] >= 130){
            string s = to_string(event[i]);
            // Taking type of mush ghost (get data after "13")
            for (int i = 1; i < s.length(); i++){
                s[i-1] = s[i];
            }
            s[s.length()-1] = '\0';
            for (int i = 1; i < s.length(); i++){
                s[i-1] = s[i];
            }
            s[s.length()-1] = '\0';
            // Taking absolute value of elements in mg[n2]
            int mg1[n2];
            for (int j = 0; j < n2; j++){
                if (mg[j] < 0){
                    mg1[j] = abs(mg[j]);
                }
                else{
                    mg1[j] = mg[j];
                }
            }
            // Sequence transformation
            for (int j = 0; j < n2; j++){
                mg1[j] = (17 * mg1[j] + 9) % 257; 
            }
            // Check type of mush ghost
            for (int j = 0; j < s.length(); j++){   
                // Mush ghost type 1
                if (s[j] == '1'){
                    HP = HP - (vtmax(mg, n2) + vtmin(mg, n2));
                    if (HP <= 0){
                        if (phoenixdown > 0){
                            phoenixdown--;
                            HP = maxHP;
                        }
                        else {
                            rescue = 0;
                            break;
                        }
                    }
                }
                // Mush ghost type 2
                else if (s[j] == '2'){   
                    int mtx = 0, mti = 0;
                    // Check if array has only 1 element
                    if (n2 == 1){
                        mtx = mg[0];
                        mti = 0;
                    }
                    // Check if array has more than 1 element
                    else if (n2 > 1){
                        // Check if mount is the first number
                        if (mg[0] > mg[1]){
                            int countx = 2;
                            for (int k = 1; k < n2-1; k++){
                                if (mg[k] > mg[k+1]){
                                    countx++;
                                }    
                            }  
                            if (countx == n2){
                                mtx = mg[0];
                                mti = 0;
                            }
                            // No mount
                            else{
                                mtx = -2;
                                mti = -3;
                            }
                        }
                        // Check if mount is the last number or in the middle
                        else if (mg[0] < mg[1]){      
                            int countx = 2;
                            for (int k = 1; k < n2-1; k++){
                                if (mg[k] < mg[k+1]){
                                    countx++;
                                }
                                else {
                                    mtx = mg[k]; // If mount is in the middle
                                    mti = k; // Position of mount
                                    countmg = true;
                                    countx--;
                                    h = k;
                                    break;  
                                } 
                            }
                            // Check if mount is the last number
                            if (h < n2-2){
                                for (int l = h; l < n2-1; l++){
                                    if (mg[l] > mg[l+1]){
                                        countmg = true;
                                    }
                                    else{
                                        countmg = false;
                                        break;
                                    }
                                }
                            }
                            if (countx == n2){
                                mtx = mg[n2-1];
                                mti = n2-1;
                            }
                            // No mount
                            else if (countmg == false){
                                mtx = -2;
                                mti = -3;
                            }
                        }
                    }
                    // Counting and checking HP
                    HP = HP - (mtx + mti);
                    if (HP <= 0){
                        if (phoenixdown > 0){
                            phoenixdown--;
                            HP = maxHP;
                        }
                        else{
                            rescue=0;
                            break;
                        }
                    }
                    if (HP > maxHP){
                        HP = maxHP;
                    }
                }
                // Mush ghost type 3
                else if (s[j] == '3'){
                    HP = HP - (vtmax3(mg1, n2) + vtmin3(mg1, n2));
                    if (HP <= 0){
                        if (phoenixdown > 0){
                            phoenixdown--;
                            HP = maxHP;
                        }
                        else{
                            rescue=0;
                            break;
                        }
                    }
                }
                // Mush ghost type 4
                else if (s[j]=='4'){   
                    int max2 = mg1[0], vt2 = 0;
                    // Check if there is a second largest number in the first 3 numbers
                    if (mg1[0] == mg1[1] && mg1[1] == mg1[2]){
                        max2 = -5;
                        vt2 = -7;
                    }
                    else {
                        for (int k = 0; k < 3; k++){
                            if (mg1[k] == max(mg1)){  
                                max2 = mg1[k];
                                vt2 = k;
                                break;
                            }
                        }
                    }
                    // Counting HP
                    HP = HP - (max2 + vt2);
                    if (HP <= 0){
                        if (phoenixdown>0){
                            phoenixdown--;
                            HP = maxHP;
                        }
                        else {
                            rescue = 0;
                            break;
                        }
                    }
                    if (HP > maxHP){
                        HP = maxHP;
                    }
                }   
            }
            // Check order of event
            if (i == size){
                if (rescue == 0){
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
                else if (rescue == -1){
                    rescue = 1;
                    if (frog == true || small == true){
                        turn(count, small, HP, maxHP, frog, level, LV);
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }
            else{
                if (rescue == -1){
                    if (frog == true || small == true){
                        turn(count, small, HP, maxHP, frog, level, LV);
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    i++;
                }
                else if (rescue == 0){
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }
        }
    }
}