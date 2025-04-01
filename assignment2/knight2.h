#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG

/* CLASSES DECLARATION */
class Events;
class ArmyKnights;
class BaseKnight;
class BaseItem;
class BaseBag;
class BaseOpponent;
class KnightAdventure;

/* Enum */
enum ItemType {ANTIDOTE = 0, PHOENIXI, PHOENIXII, PHOENIXIII, PHOENIXIV};
enum KnightType {PALADIN = 0, LANCELOT, DRAGON, NORMAL};
enum OpponentType {MADBEAR = 1, BANDIT, LORDLUPIN, ELF, TROLL, TORNBERY, QUEENOFCARDS, NINADERINGS, DURIANGARDEN, OMEGAWEAPON, HADES};

/* Additional functions */
// Check type of knight
bool checkPaladin(int maxhp);
bool checkLancelot(int maxhp);
bool checkDragon(int maxhp);
bool checkNormal(int maxhp);

/* Class Events */
class Events {
public:
    int e;
    int* event;
public:
    Events(const string & file_events);
    int count() const;
    int get(int i) const;
    ~Events();
};

/* Class BaseItem */
// Parent class
class BaseItem {
public:
    // Create node for BaseBag
    ItemType item;
    BaseItem* nextptr = nullptr;
public:
    virtual bool canUse (BaseKnight* knight) = 0;
    virtual void use (BaseKnight* knight) = 0;
    virtual ItemType getItemType() = 0;
    string ItemString(ItemType itemType);
    virtual ~BaseItem();
};
// Inherited class
class Antidote : public BaseItem{
    virtual bool canUse (BaseKnight* knight);
    virtual void use (BaseKnight* knight);
    virtual ItemType getItemType();
};
class PhoenixDownI : public BaseItem{
    virtual bool canUse (BaseKnight* knight);
    virtual void use (BaseKnight* knight);
    virtual ItemType getItemType();
};
class PhoenixDownII : public BaseItem{
    virtual bool canUse (BaseKnight* knight);
    virtual void use (BaseKnight* knight);
    virtual ItemType getItemType();
};
class PhoenixDownIII : public BaseItem{
    virtual bool canUse (BaseKnight* knight);
    virtual void use (BaseKnight* knight);
    virtual ItemType getItemType();
};
class PhoenixDownIV : public BaseItem{
    virtual bool canUse (BaseKnight* knight);
    virtual void use (BaseKnight* knight);
    virtual ItemType getItemType();
};

/* Class BaseBag */
class BaseBag {
public:
    // Create bag's linked list
    BaseItem* head;
    // Size of bag
    int size;
    int maxsize;
    // Knight holding bag
    BaseKnight* knight;
public:
    // Constructor
    BaseBag(BaseKnight* knight, int pnd1, int atd);
    // Method 1
    void Remove(BaseItem* head); // Assist removing item for get function
    void removeFirst();
    bool UsingPND(BaseKnight* knight);
    // Method 2
    virtual bool insertFirst(BaseItem* item);
    virtual BaseItem* get(ItemType itemType);
    virtual string toString() const;

    // Destructor
    virtual ~BaseBag();
};
class PaladinBag : public BaseBag{
public:
    PaladinBag(BaseKnight* knight, int pnd1, int atd);
    ~PaladinBag();
};
class LancelotBag : public BaseBag{
public:
    LancelotBag(BaseKnight* knight, int pnd1, int atd);
    ~LancelotBag();
};
class DragonBag : public BaseBag{
public:
    DragonBag(BaseKnight* knight, int pnd1, int atd);
    virtual bool insertFirst(BaseItem* item);
    ~DragonBag();
};
class NormalBag : public BaseBag{
public:
    NormalBag(BaseKnight* knight, int pnd1, int atd);
    ~NormalBag();
};

/* Class BaseOpponent */
class BaseOpponent{
public:
    BaseOpponent();
    virtual ~BaseOpponent();
    virtual OpponentType getOppo() = 0;
    int levelO(int oppo, int i); // i is the order of event
    int basedamage(OpponentType oppo);
    int gilwin(OpponentType oppo);

};
class MadBear : public BaseOpponent{
public:
    virtual OpponentType getOppo();
};
class Bandit : public BaseOpponent{
public:
    virtual OpponentType getOppo();
};
class LordLupin : public BaseOpponent{
public:
    virtual OpponentType getOppo();
};
class Elf : public BaseOpponent{
public:
    virtual OpponentType getOppo();
};
class Troll : public BaseOpponent{
public:
    virtual OpponentType getOppo();
};
class Tornbery : public BaseOpponent{
public:
    virtual OpponentType getOppo();
};
class QueenOfCards : public BaseOpponent{
public:
    virtual OpponentType getOppo();
};
class NinaDeRings : public BaseOpponent{
public:
    virtual OpponentType getOppo();
};
class DurianGarden : public BaseOpponent{
public:
    virtual OpponentType getOppo();
};
class OmegaWeapon : public BaseOpponent{
public:
    virtual OpponentType getOppo();
};
class Hades : public BaseOpponent{
public:
    virtual OpponentType getOppo();
};


/* Class BaseKnight */
// Parent class
class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int phoenixdownI;
    int antidote;
    BaseBag* bag = nullptr;
    KnightType knightType;
public:
    bool isPoisoned = false;
    int count_omega = 0;
    int count_hades = 0;
public:
    // Constructor
    BaseKnight();
    // Return type of knight
    static BaseKnight* create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    // Getter functions
    int getID();
    int getHP();
    int getMaxHP();
    int getLevel();
    int getGil();
    int getPNDI();
    int getATD();
    BaseBag* getBag();
    virtual KnightType getKnightType() = 0;
    // Setter functions
    void setID(int id);
    void setHP(int hp);
    void setMaxHP(int maxhp);
    void setLevel(int level);
    void setGil(int gil);
    void setPNDI(int pnd1);
    void setATD(int atd);
    // Knights fights opponent
    bool knightFight(BaseKnight* knight, BaseOpponent* oppo, int i); // i is the order of event
    virtual double knightDam() = 0;
    // Display
    string toString() const;
    // Destructor
    virtual ~BaseKnight();
};
// Inherited classes
class PaladinKnight : public BaseKnight{
public:
    PaladinKnight();
    virtual KnightType getKnightType();
    virtual double knightDam();
};
class LancelotKnight : public BaseKnight{
public:
    LancelotKnight();
    virtual KnightType getKnightType();
    virtual double knightDam();
};
class DragonKnight : public BaseKnight{
public:
    DragonKnight();
    virtual KnightType getKnightType();
    virtual double knightDam();
};
class NormalKnight : public BaseKnight{
public:
    NormalKnight();
    virtual KnightType getKnightType();
    virtual double knightDam();
};

/* Class ArmyKnights */
class ArmyKnights {
public:
    int n;
    int i; // order of event
    BaseKnight** army;
    bool PaladinShield = false;
    bool LancelotSpear = false;
    bool GuinevereHair = false;
    bool ExcaliburSword = false; 
public:
    // Constructor
    ArmyKnights (const string & file_armyknights);
    // Fighting opponent
    int count() const;
    BaseKnight* lastKnight() const;
    bool fight(BaseOpponent* opponent);
    bool adventure (Events* events);
    // Check treasures
    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;
    // Display
    void printInfo() const;
    void printResult(bool win) const;
    // Destructor
    ~ArmyKnights();
};

/* Class KnightAdventure */
class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;
public:
    KnightAdventure();
    ~KnightAdventure();

    void loadArmyKnights(const string &);
    void loadEvents(const string &);
    void run();
};

#endif // __KNIGHT2_H__