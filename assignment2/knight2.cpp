#include "knight2.h"

/* Additional functions */
// Check type of knight
bool checkPaladin(int maxhp){
    if (maxhp < 2){
        return false;
    }
    for(int i = 2; i < maxhp; i++){
        if (maxhp % i == 0){
            return false;
        }
    }
    return true;
}
bool checkLancelot(int maxhp){
    if (maxhp == 888){
        return true;
    }
    return false;
}
bool checkDragon(int maxhp){
    if (maxhp == 345 || maxhp == 354 || maxhp == 435 || maxhp == 453 || maxhp == 534 || maxhp == 543){
        return true;
    }
    return false;
}
bool checkNormal(int maxhp){
    if (checkPaladin(maxhp) == false && checkLancelot(maxhp) == false && checkDragon(maxhp) == false){
        return true;
    }
    return false;
}


/* Class Events */
// Constructor
Events::Events(const string & file_events){ // Reading file
    ifstream event_file(file_events);
    event_file >> e;
    event = new int[e];
    for (int i = 0; i < e; i++){ // the order of events counting from 0
        event_file >> event[i];
    }
}
// Counting events
int Events::count() const{
    return e;
}
// Get event id
int Events::get(int i) const{ // i is the order of events counting from 0
    return event[i];
}
// Destructor
Events::~Events(){ // Delete dynamic array
    delete[]event;
}


/* Class BaseItem */
// Convert itemtype to string
string BaseItem::ItemString(ItemType itemType){
    string s;
    if (itemType == ANTIDOTE){
        s = "Antidote";
    }
    else if (itemType == PHOENIXI){
        s = "PhoenixI";
    }
    else if (itemType == PHOENIXII){
        s = "PhoenixII";
    }
    else if (itemType == PHOENIXIII){
        s = "PhoenixIII";
    }
    else if (itemType == PHOENIXIV){
        s = "PhoenixIV";
    }
    return s;
}
// Class Antidote
bool Antidote::canUse(BaseKnight* knight){
    if (knight->isPoisoned == true){
        return true;
    }
    return false;
}
void Antidote::use(BaseKnight* knight){
    knight->isPoisoned = false;
}
ItemType Antidote::getItemType(){
    return ANTIDOTE;
}
// Class PhoenixDownI
bool PhoenixDownI::canUse(BaseKnight* knight){
    if (knight->getHP() <= 0){
        return true;
    }
    return false;
}
void PhoenixDownI::use(BaseKnight* knight){
    knight->setHP(knight->getMaxHP());
    if (knight->getHP() > 999){
        knight->setHP(999);
    }
}
ItemType PhoenixDownI::getItemType(){
    return PHOENIXI;
}
// Class PhoenixDownII
bool PhoenixDownII::canUse(BaseKnight* knight){
    int temp = knight->getMaxHP();
    if (knight->getHP() < temp/4){
        return true;
    }
    return false;
}
void PhoenixDownII::use(BaseKnight* knight){
    int temp = knight->getMaxHP();
    knight->setHP(temp);
    if (knight->getHP() > 999){
        knight->setHP(999);
    }
}
ItemType PhoenixDownII::getItemType(){
    return PHOENIXII;
}
// Class PhoenixDownIII
bool PhoenixDownIII::canUse(BaseKnight* knight){
    int temp = knight->getMaxHP();
    if (knight->getHP() < temp/3){
        return true;
    }
    return false;
}
void PhoenixDownIII::use(BaseKnight* knight){
    int temp1 = knight->getHP();
    int temp2 = knight->getMaxHP();
    if (temp1 > 0){
        temp1 += temp2/4;
        knight->setHP(temp1);
    }
    else{
        knight->setHP(temp2/3);
    } 
    if (knight->getHP() > 999){
        knight->setHP(999);
    }
}
ItemType PhoenixDownIII::getItemType(){
    return PHOENIXIII;
}
// Class PhoenixDownIV
bool PhoenixDownIV::canUse(BaseKnight* knight){
    int temp = knight->getMaxHP();
    if (knight->getHP() < temp/2){
        return true;
    }
    return false;
}
void PhoenixDownIV::use(BaseKnight* knight){
    int temp1 = knight->getHP();
    int temp2 = knight->getMaxHP();
    if (knight->getHP() > 0){
        temp1 += temp2/5;
        knight->setHP(temp1);
    }
    else{
        knight->setHP(temp2/2);
    } 
    if (knight->getHP() > 999){
        knight->setHP(999);
    }
}
ItemType PhoenixDownIV::getItemType(){
    return PHOENIXIV;
}
// Virtual destructor
BaseItem::~BaseItem(){}


/* Class BaseOpponent */
// Constructor
BaseOpponent::BaseOpponent(){}
// Counting levelO
int BaseOpponent::levelO(int oppo, int i){
    return (i + oppo) % 10 + 1;
}
// Return basedamage
int BaseOpponent::basedamage(OpponentType oppo){
    if (oppo == MADBEAR){
        return 10;
    }
    else if (oppo == BANDIT){
        return 15;
    }
    else if (oppo == LORDLUPIN){
        return 45;
    }
    else if (oppo == ELF){
        return 75;
    }
    else if (oppo == TROLL){
        return 95;
    }
    return 0;
}
// Return gilwin
int BaseOpponent::gilwin(OpponentType oppo){
    if (oppo == MADBEAR){
        return 100;
    }
    else if (oppo == BANDIT){
        return 150;
    }
    else if (oppo == LORDLUPIN){
        return 450;
    }
    else if (oppo == ELF){
        return 750;
    }
    else if (oppo == TROLL){
        return 800;
    }
    return 0;
}
// Class MadBear
OpponentType MadBear::getOppo(){
    return MADBEAR;
}
// Class Bandit
OpponentType Bandit::getOppo(){
    return BANDIT;
}
// Class LordLupin
OpponentType LordLupin::getOppo(){
    return LORDLUPIN;
}
// Class Elf
OpponentType Elf::getOppo(){
    return ELF;
}
// Class Troll
OpponentType Troll::getOppo(){
    return TROLL;
}
// Class Tornbery
OpponentType Tornbery::getOppo(){
    return TORNBERY;
}
// Class QueenOfCards
OpponentType QueenOfCards::getOppo(){
    return QUEENOFCARDS;
}
// Class NinaDeRings
OpponentType NinaDeRings::getOppo(){
    return NINADERINGS;
}
// Class DurianGarden
OpponentType DurianGarden::getOppo(){
    return DURIANGARDEN;
}
// Class OmegaWeapon
OpponentType OmegaWeapon::getOppo(){
    return OMEGAWEAPON;
}
// Class Hades
OpponentType Hades::getOppo(){
    return HADES;
}
// Destructor
BaseOpponent::~BaseOpponent(){}


/* Class BaseBag */
// Constructor
BaseBag::BaseBag(BaseKnight* knight, int pnd1, int atd){
    this->knight = knight;
    this->head = nullptr;
    this->size = 0;
    this->maxsize = 0;
}
// Removing first item in bag
void BaseBag::removeFirst(){
    BaseItem* p = head;
    head = head->nextptr;
    delete p;
}
// Using PND
bool BaseBag::UsingPND(BaseKnight* knight){
    BaseItem* p = head;
    while (p != nullptr){
        if (p->getItemType() == ANTIDOTE){
            p = p->nextptr;
        }
        else{
            if (p->canUse(knight)){
                get(p->getItemType());
                //size--;
                return true;
            }
            else{
                p = p->nextptr;
            }
        }
    }
    return false;
}
// Insert node to head
bool BaseBag::insertFirst(BaseItem* item){
    if (size == maxsize)
        return false;
    item->nextptr = head;
    head = item;
    size++;
    return true;
}
/* It should be:
bool BaseBag::insertFirst(BaseItem* item){
    if (size == maxsize){
        return false;
    }
    else{
        if (head == NULL){
            head = item;
            size++;
        }
        else {
            item->nextptr = head;
            head = item;
            size++;
        }
    }
    return true;
}
*/

// Check, using and remove item
BaseItem* BaseBag::get(ItemType itemType){
    if (size == 0){
        return nullptr;
    }
    if (itemType == ANTIDOTE){
        BaseItem* p = head;
        while (p != nullptr){
            if (p->item == itemType){
                swap(head->item, p->item); // Exchange node's data with head's data
                p = head;
                head = head->nextptr;
                p->use(knight);
                size--;
                delete p;
                return nullptr;
            }
            else{
                p = p->nextptr;
            }
        }
    }
    else{
        BaseItem* p = head;
        while (p != nullptr){
            if (p->canUse(knight) == true){
                swap(head->item, p->item); // Exchange node's data with head's data
                p = head;
                head = head->nextptr;
                p->use(knight);
                size--;
                delete p;
                return nullptr;
            }
            else{
                p = p->nextptr;
            }
        }
    }
    return nullptr;
}
// Display bag
string BaseBag::toString() const{
    if (size > 0){
        string item[5] = {"Antidote", "PhoenixI", "PhoenixII", "PhoenixIII", "PhoenixIV"};
        string s1("");
        BaseItem* p = head;
        // Create string s2 and assign its value to the first item in bag at first
        string s2 = item[p->getItemType()]; // Data type of item in head->item if ItemType
        // Continue assign value to s2
        p = p->nextptr;
        while(p != nullptr){
            s2 = s2 + ',' + item[p->getItemType()];
            p = p->nextptr;
        }
        s1 = "Bag[count=" + to_string(size) + ';' + s2 + ']';
        return s1;
    }
    return "Bag[count=0;]";
}
// Destructor
BaseBag::~BaseBag(){
    while (head != nullptr){
        BaseItem* temp = head;
        head = head->nextptr;
        delete temp;
    }
}
// Class PaladinBag
PaladinBag::PaladinBag(BaseKnight* knight, int pnd1, int atd) : BaseBag(knight, pnd1, atd){
    this->maxsize = -1; // Unlimited size
}
PaladinBag::~PaladinBag(){}
// Class LancelotBag
LancelotBag::LancelotBag(BaseKnight* knight, int pnd1, int atd) : BaseBag(knight, pnd1, atd){
    this->maxsize = 16; 
}
LancelotBag::~LancelotBag(){}
// Class DragonBag
DragonBag::DragonBag(BaseKnight* knight, int pnd1, int atd) : BaseBag(knight, pnd1, atd){
    this->maxsize = 14; 
}
bool DragonBag::insertFirst(BaseItem* item){
    if (size == maxsize){
        return false;
    }
    if (item->item == ANTIDOTE){
        return false;
    }
    BaseItem* p = nullptr;
    if (item->item == PHOENIXI){
        p = new PhoenixDownI;
    }
    else if (item->item == PHOENIXII){
        p = new PhoenixDownII;
    }
    else if (item->item == PHOENIXIII){
        p = new PhoenixDownIII;
    }
    else if (item->item == PHOENIXIV){
        p = new PhoenixDownIV;
    }
    // Chỉnh sửa insertFirst tương tự insertFirst của BaseBag
    p->item = item->item;
    p->nextptr = head;
    head = p;
    size++;
    return true;
}
DragonBag::~DragonBag(){}
// Class NormalBag
NormalBag::NormalBag(BaseKnight* knight, int pnd1, int atd) : BaseBag(knight, pnd1, atd){
    this->maxsize = 19; 
}
NormalBag::~NormalBag(){}


/* Class BaseKnight */
// Constructor
BaseKnight::BaseKnight(){}
// Create knight
BaseKnight* BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
    BaseKnight* knight = nullptr;
    if (checkPaladin(maxhp)){
        knight = new PaladinKnight();
        knight->bag = new PaladinBag(knight, phoenixdownI, antidote);
    }
    else if (checkLancelot(maxhp)){
        knight = new LancelotKnight();
        knight->bag = new LancelotBag(knight, phoenixdownI, antidote);
    }
    else if (checkDragon(maxhp)){
        knight = new DragonKnight();
        knight->bag = new DragonBag(knight, phoenixdownI, antidote);
    }
    else if (checkNormal(maxhp)){
        knight = new NormalKnight();
        knight->bag = new NormalBag(knight, phoenixdownI, antidote);
    }
    knight->id = id;
    knight->maxhp = maxhp;
    knight->hp = maxhp;
    knight->level = level;
    knight->gil = gil;
    knight->antidote = antidote;
    knight->phoenixdownI = phoenixdownI;

    while(phoenixdownI > 0){
        BaseItem* p = new PhoenixDownI();
        if (knight->bag->insertFirst(p) == false){
            delete p;
        }
        phoenixdownI--;
    }
    while(antidote > 0){
        BaseItem* p = new Antidote();
        if(knight->bag->insertFirst(p) == false){
            delete p;
        }
        antidote--;        
    }

    return knight;
}
// Class PaladinKnight 
PaladinKnight::PaladinKnight(){
    this->knightType = PALADIN;
}
KnightType PaladinKnight::getKnightType(){
    return PALADIN;
}
double PaladinKnight::knightDam(){
    return 0.06*level*hp;
}
// Class LancelotKnight
LancelotKnight::LancelotKnight(){
    this->knightType = LANCELOT;
}
KnightType LancelotKnight::getKnightType(){
    return LANCELOT;
}
double LancelotKnight::knightDam(){
    return 0.05*level*hp;
}
// Class DragonKnight
DragonKnight::DragonKnight(){
    this->knightType = DRAGON;
}
KnightType DragonKnight::getKnightType(){
    return DRAGON;
}
double DragonKnight::knightDam(){
    return 0.075*level*hp;
}
// Class NormalKnight 
NormalKnight::NormalKnight() {
    this->knightType = NORMAL;
}
KnightType NormalKnight::getKnightType(){
    return NORMAL;
}
double NormalKnight::knightDam(){
    return 0;
}
// Getter functions
int BaseKnight::getID(){
    return id;
}
int BaseKnight::getHP(){
    return hp;
}
int BaseKnight::getMaxHP(){
    return maxhp;
}
int BaseKnight::getLevel(){
    return level;
}
int BaseKnight::getGil(){
    return gil;
}
int BaseKnight::getPNDI(){
    return phoenixdownI;
}
int BaseKnight::getATD(){
    return antidote;
}
BaseBag* BaseKnight::getBag(){
    return bag;
}
// Setter functions
void BaseKnight::setID(int id){
    this->id = id;
}
void BaseKnight::setHP(int hp){
    this->hp = hp;
}
void BaseKnight::setMaxHP(int maxhp){
    this->maxhp = maxhp;
}
void BaseKnight::setLevel(int level){
    this->level = level;
}
void BaseKnight::setGil(int gil){
    this->gil = gil;
}
void BaseKnight::setPNDI(int pnd1){
    this->phoenixdownI = pnd1;
}
void BaseKnight::setATD(int atd){
    this->antidote = atd;
}
// Knight fights opponent - Check HP in the final
bool BaseKnight::knightFight(BaseKnight* knight, BaseOpponent* oppo, int i){
    int e_id = int(oppo->getOppo());
    // Event 1 to 5
    // Residual gil is updated in fight function of ArmyKnights
    if (e_id >= 1 && e_id <= 5){
        // Paladin or Lancelot - Auto win
        if (checkPaladin(this->maxhp) == true || checkLancelot(this->maxhp) == true){
            if (e_id == 1){
                this->gil += 100;
            }
            else if (e_id == 2){
                this->gil += 150;
            }
            else if (e_id == 3){
                this->gil += 450;
            }
            else if (e_id == 4){
                this->gil += 750;
            }
            else if (e_id == 5){
                this->gil += 800;
            }
        }
        // Not Paladin or Lancelot
        else{
            int levelO = oppo->levelO(e_id, i);
            // Win
            if (this->level >= levelO){
                if (e_id == 1){
                    this->gil += 100;
                }
                else if (e_id == 2){
                    this->gil += 150;
                }
                else if (e_id == 3){
                    this->gil += 450;
                }
                else if (e_id == 4){
                    this->gil += 750;
                }
                else if (e_id == 5){
                    this->gil += 800;
                }
            }
            // Lose
            else{
                if (e_id == 1){
                    this->hp = this->hp - 10*(levelO - this->level);
                }
                else if (e_id == 2){
                    this->hp = this->hp - 15*(levelO - this->level);
                }
                else if (e_id == 3){
                    this->hp = this->hp - 45*(levelO - this->level);
                }
                else if (e_id == 4){
                    this->hp = this->hp - 75*(levelO - this->level);
                }
                else if (e_id == 5){
                    this->hp = this->hp - 95*(levelO - this->level);
                }
                if (this->hp > 0){
                    this->bag->UsingPND(knight);
                }
                else{
                    // Step 1: Finding PhoenixDown
                    if (this->bag->UsingPND(knight));
                    // Step 2: Calling Phoenix and paying gil
                    else if(this->gil >= 100){
                        this->gil -= 100;
                        this->hp = this->maxhp/2;
                    }
                }
            }
        }
    }
    // Event 6
    else if (e_id == 6){
        int levelO = oppo->levelO(6, i);
        // Win
        if (this->level >= levelO){
            if (this->level < 10){
                this->level++;
            }
        }
        // Lose
        else {
            this->isPoisoned = true;
            // Dragon
            if (checkDragon(this->maxhp)){
                this->isPoisoned = false;
            }
            // Not Dragon
            else{
                // Have antidote
                if (this->antidote > 0){
                    this->antidote--;
                    this->bag->get(ANTIDOTE);
                    this->isPoisoned = false;
                }
                // Don't have antidote
                else{
                    // Drop 3 latest items
                    if (this->bag->size == 1){
                        this->bag->removeFirst();
                    }
                    else if (this->bag->size == 2){
                        this->bag->removeFirst();
                        this->bag->removeFirst();
                    }
                    else if (this->bag->size >= 3){
                        this->bag->removeFirst();
                        this->bag->removeFirst();
                        this->bag->removeFirst();
                    }
                    // Reduce HP
                    this->hp -= 10;
                    if (this->hp > 0){
                        this->bag->UsingPND(knight);
                    }
                    else{
                        // Step 1: Finding PhoenixDown
                        if (this->bag->UsingPND(knight));
                        // Step 2: Calling Phoenix and paying gil
                        else if(this->gil >= 100){
                            this->gil -= 100;
                            this->hp = this->maxhp/2;
                        }
                    }
                }
            }
        }
    }
    // Event 7
    // Residual gil is updated in fight function of ArmyKnights
    else if (e_id == 7){
        int levelO = oppo->levelO(7, i);
        // Win
        if (this->level >= levelO){
            this->gil *= 2;
        }
        // Lose
        else{
            if (checkPaladin(this->maxhp)){
                this->gil -= 0;
            }
            else{
                this->gil -= this->gil/2;
            }
        }
    }
    // Event 8
    else if (e_id == 8){
        if (checkPaladin(this->maxhp) == true){
            if (this->hp < this->maxhp/3){
                this->hp += this->maxhp/5;
            }
        }
        else{
            if (this->gil < 50){
                this->hp += 0;
            }
            else{
                if (this->hp < this->maxhp/3){
                    this->hp += this->maxhp/5;
                    this->gil -= 50;
                }
            }
        }
    }
    // Event 9
    else if (e_id == 9){
        this->hp = this->maxhp;
    }
    // Event 10
    else if (e_id == 10){
        // Won OmegaWeapon
        if (count_omega == 1){
            this->hp += 0;
        }
        // Haven't won or haven't met
        else{
            // Win
            if (((this->level == 10) && (this->hp = this->maxhp)) || checkDragon(this->maxhp) == true){
                this->level = 10;
                this->gil = 999;
                count_omega = 1;
            }
            // Lose
            else{
                this->hp = 0;
                // Step 1: Finding PhoenixDown
                if (this->bag->UsingPND(knight));
                // Step 2: Calling Phoenix and paying gil
                else if(this->gil >= 100){
                    this->gil -= 100;
                    this->hp = this->maxhp/2;
                }
            }
        }
    }
    // Event 11
    // PaldinShield is updated in fight function of ArmyKnights
    else if (e_id == 11){
        // Won Hades
        if (count_hades == 1){
            this->hp += 0;
        }
        // Haven't won or haven't met
        else{
            // Win
            if (this->level == 10 ||((checkPaladin(this->maxhp) == true) && this->level >= 8)){
                this->hp += 0;
                count_hades = 1;
            }
            else{
                this->hp = 0;
                // Step 1: Finding PhoenixDown
                if (this->bag->UsingPND(knight));
                // Step 2: Calling Phoenix and paying gil
                else if(this->gil >= 100){
                    this->gil -= 100;
                    this->hp = this->maxhp/2;
                }
            }
        }
    }
    if (this->hp <= 0){
        return false;
    }
    return true;
}
// Display knight
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(this->id) 
        + ",hp:" + to_string(this->hp) 
        + ",maxhp:" + to_string(this->maxhp)
        + ",level:" + to_string(this->level)
        + ",gil:" + to_string(this->gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}
// Destructor
BaseKnight::~BaseKnight(){
    delete bag;
}


/* Class ArmyKnights */
// Constructor
ArmyKnights::ArmyKnights(const string & file_armyknights){ 
    ifstream knight_file(file_armyknights);
    knight_file >> n;
    army = new BaseKnight*[n];
    int maxhp, level, gil, antidote, phoenixdownI;
    for (int i = 0; i < n; i++){
        knight_file >> maxhp >> level >> phoenixdownI >> gil >> antidote;
        army[i] = BaseKnight::create(i + 1, maxhp, level, gil, antidote, phoenixdownI);
    }
}
// Quantity of army
int ArmyKnights::count() const{
    return this->n;
}
// Last knight - the one who fights opponent
BaseKnight* ArmyKnights::lastKnight() const{
    return army[n-1];
}
// Army fights opponent
bool ArmyKnights::fight(BaseOpponent* opponent){
    int resiGil; // residual gil
    while (n != 0){
        BaseKnight* lknight = lastKnight();
        // Win
        if (lknight->knightFight(lknight, opponent, i)){
            // Update resdiual gil
            for (int i = n - 1; i >= 0; i--){
                resiGil = army[i]->getGil() - 999;
                if (resiGil <= 0){
                    break;
                }
                else{
                    army[i]->setGil(999);
                    if (i >= 1){
                        army[i-1]->setGil(army[i-1]->getGil() + resiGil);
                    }
                }
            }
            // Update PaladinShield
            if (lknight->count_hades == 1){
                PaladinShield = true;
            }
            break;
        }
        // Lose
        else{
            n--;
            delete lknight;
            break;
        }
    } 
    delete opponent;
    if (n > 0){
        return true;
    } 
    return false;
}
// Army join events
bool ArmyKnights::adventure(Events* event){
    // Initial setting
    i = 0;
    PaladinShield = false;
    LancelotSpear = false;
    GuinevereHair = false;
    ExcaliburSword = false;
    bool winUltimecia = false;
    // Runinning events
    for (i = 0; i < event->count(); i++){
        if (event->get(i) == 1){
            this->fight(new MadBear());
        }
        else if (event->get(i) == 2){
            this->fight(new Bandit());
        }
        else if (event->get(i) == 3){
            this->fight(new LordLupin());
        }
        else if (event->get(i) == 4){
            this->fight(new Elf());
        }
        else if (event->get(i) == 5){
            this->fight(new Troll());
        }
        else if (event->get(i) == 6){
            this->fight(new Tornbery());
        }
        else if (event->get(i) == 7){
            this->fight(new QueenOfCards());
        }
        else if (event->get(i) == 8){
            this->fight(new NinaDeRings());
        }
        else if (event->get(i) == 9){
            this->fight(new DurianGarden());
        }
        else if (event->get(i) == 10){
            this->fight(new OmegaWeapon());
        }
        else if (event->get(i) == 11){
            this->fight(new Hades());
        }
        else if (event->get(i) == 112 || event->get(i) == 113 || event->get(i) == 114){
            BaseItem* p = nullptr;
            if (event->get(i) == 112){
                p = new PhoenixDownII;
            }
            else if (event->get(i) == 113){
                p = new PhoenixDownIII;
            }
            else if (event->get(i) == 114){
                p = new PhoenixDownIV;
            }
            bool checkInsert = false;
            for (int i = n - 1; i >= 0; i--){
                //checkInsert = army[i]->getBag()->insertFirst(p);
                if ((checkInsert = army[i]->getBag()->insertFirst(p))){
                    break;
                }
            }
            if (checkInsert == false){
                delete p;
            }
        }
        else if (event->get(i) == 95){
            PaladinShield = true;
        }
        else if (event->get(i) == 96){
            LancelotSpear = true;
        }
        else if (event->get(i) == 97){ 
            GuinevereHair = true;
        }
        else if (event->get(i) == 98){
            if (PaladinShield == true && LancelotSpear == true && GuinevereHair == true){
                ExcaliburSword  = true;
            }
            else{
                ExcaliburSword  = false;
            }
        }
        else if (event->get(i) == 99){
            // Win: Having Excalibur Sword
            if (ExcaliburSword  == true){
                winUltimecia = true;
            }
            // Ultimecia fights with Paladin, Lancelot, Dragon: Don't have Excalibur Sword but has 3 treasures
            else if (ExcaliburSword  == false && PaladinShield == true && LancelotSpear == true && GuinevereHair == true){
                int Ulti = 5000;
                while (n != 0){
                    BaseKnight* lknight = lastKnight();
                    Ulti -= lknight->knightDam();
                    if (Ulti <= 0){
                        winUltimecia = true;
                        break;
                    }
                    else{
                        delete lknight;
                        n--;
                    }
                }
                if (n == 0){
                    winUltimecia = false;
                }
            }
            // Don't have Excalibur Sword and 3 treasures
            else{
                for (int i = 0; i < n; i++){
                    delete army[i]; // Dead inside
                }
                delete[]army;
                n = 0;
                winUltimecia = false;
            }
        }
        printInfo();
    }
    if (winUltimecia == true){
        return true;
    }
    return false;
}
// Check treasures
bool ArmyKnights::hasPaladinShield() const{
    return PaladinShield;
}
bool ArmyKnights::hasLancelotSpear() const{
    return LancelotSpear;
}
bool ArmyKnights::hasGuinevereHair() const{
    return GuinevereHair;
}
bool ArmyKnights::hasExcaliburSword() const{
    return ExcaliburSword;
}

// Display Info
void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}
// Display result
void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}
// Destructor
ArmyKnights::~ArmyKnights(){
    /*
    for (int i = 1; i <= n; i++){
        delete[]army[i];
    }
    delete[]army;
    */
}


/* Class KnightAdventure */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}
void KnightAdventure::loadArmyKnights(const string & file_armyknights){
    this->armyKnights = new ArmyKnights(file_armyknights);
}
void KnightAdventure::loadEvents(const string & file_events){
    this->events = new Events(file_events);
}
void KnightAdventure::run(){
    armyKnights->printResult(armyKnights->adventure(events));
}
KnightAdventure::~KnightAdventure(){
    delete armyKnights;
    delete events;
}