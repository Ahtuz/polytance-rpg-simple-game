#include<iostream>
#include<string>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

/*
	DAFTAR ANGGOTA:
	ALBERTUS HERONIUS / 2101690042
	CHRISTIAN WINATA / 2101707642
	DAVID LIOIS / 2101628096
	MILLINOV ADMIRAL / 2101675804
*/


void space(){
	for(int i=0;i<24;i++){
		cout<<endl;
	}
}

void ending(){
	cout<<"Well done..."<<endl; Sleep(800);
	cout<<"Sad News... It's not the end yet..."<<endl; Sleep(500);
	cout<<"What? I know you already killed the Demon King..."<<endl; Sleep(600);
	cout<<"Didn't I say you must kill the Demon Lord, not Demon King from the beginning of the game?"<<endl; Sleep(600);
	cout<<"Don't worry, The Demon King will respawn again soon."<<endl; Sleep(700);
	cout<<"This game has no end. To quit, You only could GIVE UP."<<endl; Sleep(600);
	cout<<":)"<<endl; Sleep(700);
}

class Adventurer{
	private:
		int lv;
		int exp;
		string classs;
	protected:
		string name;
		int atk;
		int def;
		int maxHP;
		int hp;
		int skill;
	public:
		Adventurer(){
			this->classs="Adventurer";
			this->lv=0;
			this->skill=0;
			this->exp=0;
			this->atk=10;
			this->def=10;
			this->maxHP=50;
			this->hp=50;
		}

		void setName(string name){
			this->name=name;
		}

		string getName(){
			return this->name;
		}

		void setSkill(int skill){
			this->skill=skill;
		}

		int getSkill(){
			return this->skill;
		}

		void setExp(int exp){
			this->exp=exp;
		}

		int getExp(){
			return this->exp;
		}

		void setClass(string classs){
			this->classs = classs;
		}

		string getClass(){
			return this->classs;
		}

		void setLv(int lv){
			this->lv=lv;
		}

		int getLv(){
			return this->lv;
		}

		void setAtk(int atk){
			this->atk=atk;
		}

		int getAtk(){
			return this->atk;
		}
		
		void setDef(int def){
			this->def=def;
		}

		int getDef(){
			return this->def;
		}
		
		void setHp(int hp){
			this->hp=hp;
		}

		int getHp(){
			return this->hp;
		}

		void setMaxHp(int maxHP){
			this->maxHP=maxHP;
		}

		int getMaxHp(){
			return this->maxHP;
		}

		virtual void sleep(){
			space();
			cout<<"You take a rest, your HP is now fully recovered."<<endl;
			setHp(getMaxHp());
		} //SUBTYPE POLYMORPHISM

		virtual void levelUp(){
			setExp(0);
			setAtk(getAtk()+1);
			setDef(getDef()+1);
			setMaxHp(getMaxHp()+10);
			setHp(getMaxHp());
		} //SUBTYPE POLYMORPHISM

		virtual void view(){
			cout<<"NAME   : "<<getName()<<endl
				<<"CLASS  : "<<this->getClass()<<endl
				<<"LEVEL  : "<<this->getLv()<<endl
				<<"EXP    : "<<this->getExp()<<endl
				<<"HP     : "<<this->getHp()<<endl
				<<"MAX HP : "<<getMaxHp()<<endl
				<<"ATTACK : "<<getAtk()<<endl
				<<"DEFENCE: "<<getDef()<<endl
				<<"SKILL  : "<<this->getSkill()<<endl;
		} //SUBTYPE POLYMORPHISM

		virtual void fight(){
			int expTemp;
			int expLoseTemp;

			cout<<"..."<<endl; Sleep(500);
			cout<<"..."<<endl; Sleep(500);
			cout<<"You found an enemy!"<<endl; Sleep(500);
			system("pause");

			int mobHP;
			int mobAtk;
			int run=2;
			int playerAtk;

			expTemp = rand()%30+30;
		
			srand(time(NULL));

			mobHP = (rand()%30+10) + this->getLv();

			do{
				int choice=0;
				int sCounter=1;
			
				mobAtk = (rand()%20+5) + this->getLv();
				playerAtk = 5+rand()%this->getAtk();

				space();
				cout<<endl<<"- HP -"<<endl;
				cout<<left<<setw(20)<<"Monster"<<":"<<mobHP<<endl;
				cout<<left<<setw(20)<<getName()<<":"<<this->getHp()<<endl;
				cout<<endl<<endl;

				do{
					cout<<"ACTION:"<<endl;
					cout<<"1. ATTACK"<<endl;
					cout<<"2. RUN"<<endl;
					cout<<"Choice: ";
					cin>>choice; cin.clear(); cin.sync();
				}while(choice < 1 || choice > 2);

				switch(choice){
					case 1:
						sCounter = 1;
						cout<<endl<<endl<<"You attacked the monster!"<<endl;

						if(playerAtk > getAtk()){
							cout<<"CRITICAL HIT!!"<<endl;
						}

						cout<<"Damage given: "<< playerAtk <<"."<<endl<<endl;
						mobHP = mobHP - playerAtk;

						break;

					case 2:
						sCounter = 1;
						cout<<"..."<<endl
							<<"You try to run..."<<endl
							<<"..."<<endl;
						system("pause");

						run = rand()%2+1;

						if(run == 1){
							cout<<"You successfully escaped."<<endl<<endl<<endl;
							mobHP = 0;
						}
						else if(run == 2){
							cout<<"Failed to run."<<endl<<endl<<endl;
						}

						break;
				}

				if(run == 2 && mobHP > 0){
					cout<<"The monster attacks you!"<<endl;
					int dmg = mobAtk - this->getDef();

					if(dmg > 0){
						cout<<"Damage taken: "<< dmg <<"."<<endl<<endl;
					}
					else{
						cout<<"Damage taken: 1."<<endl<<endl;
						dmg=1;
					}

					this->setHp(this->getHp() - dmg);

					system("pause");
				
				}

				if(this->getHp() <= 0){
					run = 1;
					mobHP = 0;
					this->setHp(0);

					cout<<endl<<"You cannot fight because your HP is too low!"<<endl
						<<"You risk your life by forcing to fight."<<endl
						<<"You has been slained."<<endl<<endl;

					if(this->getExp()!=0){
						expLoseTemp = rand()%this->getExp()+1;
						cout<<"You lose "<< expLoseTemp << " EXP!"<<endl;
						this->setExp(this->getExp()-expLoseTemp);
					}
					else{
						cout<<"Your EXP is already 0. Your EXP didn't reduce."<<endl<<endl;
					}
					system("pause");
				}
			}while(mobHP > 0);

			if(run == 2 && mobHP <= 0){
				cout<<"Your HP left: ";
				cout<<this->getHp()<<endl<<endl;
				cout<<"After the tough fight."<<endl<<"You successfully killed the monster."<<endl<<"You get "<<expTemp
					<<" EXP."<<endl<<endl;
				this->setExp(this->getExp()+expTemp);

				if(this->getExp()>=100){
					this->setLv(this->getLv()+1);
					cout<<"LEVEL UP!"<<endl<<"Now you are level "
						<<this->getLv()<<"."<<endl
						<<"HP is fully recovered and your stats improved!"<<endl;
					levelUp();
				}

				system("pause");

			}
		}

		virtual void challenge(){
			; 
		} //QUASI VIRTUAL FUNCTION

		~Adventurer(){
		}
};

class Archer:public Adventurer{
	private:
		int lv;
		int exp;
		int skill;
	public:
		Archer(){
			this->lv=0;
			this->exp=0;
			this->skill=25;
		}

		void setLv(int lv){
			this->lv=lv;
		}

		void setExp(int exp){
			this->exp=exp;
		}

		int getExp(){
			return this->exp;
		}

		int getLv(){
			return this->lv;
		}

		void setSkill(int skill){
			this->skill=skill;
		}

		int getSkill(){
			return this->skill;
		}

		void sleep(){
			cout<<"You take a rest, your HP is now fully recovered."<<endl;
			setHp(getMaxHp());
		}

		void levelUp(){
			setExp(0);
			setAtk(getAtk()+3);
			setSkill(getSkill()+4);
			setDef(getDef()+2);
			setMaxHp(getMaxHp()+20);
			setHp(getMaxHp());
		}

		void view(){
			cout<<"NAME   : "<<getName()<<endl
				<<"CLASS  : "<<this->getClass()<<endl
				<<"LEVEL  : "<<this->getLv()<<endl
				<<"EXP    : "<<this->getExp()<<endl
				<<"HP     : "<<this->getHp()<<endl
				<<"MAX HP : "<<getMaxHp()<<endl
				<<"ATTACK : "<<getAtk()<<endl
				<<"DEFENCE: "<<getDef()<<endl
				<<"SKILL  : "<<this->getSkill()<<endl;
		}

		void fight(){
			int expTemp;
			int expLoseTemp;

			cout<<"..."<<endl; Sleep(500);
			cout<<"..."<<endl; Sleep(500);
			cout<<"You found an enemy!"<<endl; Sleep(500);
			system("pause");

			int mobHP;
			int mobAtk;
			int run=2;
			int playerAtk;
			int sCounter=1;

			expTemp = rand()%30+20;
		
			srand(time(NULL));

			mobHP = (rand()%40+20) + this->getLv();

			do{
				int choice=0;
			
				mobAtk = (rand()%30+5) + this->getLv();
				playerAtk = 8+rand()%this->getAtk();

				space();
				cout<<endl<<"- HP -"<<endl;
				cout<<left<<setw(20)<<"Monster"<<":"<<mobHP<<endl;
				cout<<left<<setw(20)<<getName()<<":"<<this->getHp()<<endl;
				cout<<endl<<endl;

				do{
					cout<<"ACTION:"<<endl;
					cout<<"1. ATTACK"<<endl;
					cout<<"2. RUN"<<endl;
					cout<<"3. SKILL"<<endl;
					cout<<"Choice: ";
					cin>>choice; cin.clear(); cin.sync();
				}while(choice < 1 || choice > 3);

				switch(choice){
					case 1:
						sCounter = 1;
						cout<<endl<<endl<<"You attacked the monster!"<<endl;

						if(playerAtk > getAtk()){
							cout<<"CRITICAL HIT!!"<<endl;
						}

						cout<<"Damage given: "<< playerAtk <<"."<<endl<<endl;
						mobHP = mobHP - playerAtk;

						break;

					case 2:
						sCounter = 1;
						cout<<"..."<<endl
							<<"You try to run..."<<endl
							<<"..."<<endl;
						system("pause");

						run = rand()%2+1;

						if(run == 1){
							cout<<"You successfully escaped."<<endl<<endl<<endl;
							mobHP = 0;
						}
						else if(run == 2){
							cout<<"Failed to run."<<endl<<endl<<endl;
						}

						system("pause");
						break;

					case 3:
						if(sCounter == 0){
							cout<<"Your skill is still on cooldown!"<<endl<<endl;
							cout<<"You must wait next turn to use your skill again."<<endl<<endl;
							sCounter = 1;
						}

						else{
							cout<<"You used your skill!"<<endl;
							cout<<"P O W E R   S H O T ! ! !"<<endl;

							cout<<"Damage given: "<< playerAtk <<"."<<endl<<endl;
							mobHP = mobHP - (this->getSkill() +  ((int)playerAtk/2));

							sCounter = 0;
						}

						system("pause");
						break;
				}

				if(run == 2 && mobHP > 0){
					cout<<"The monster attacks you!"<<endl;
					int dmg = mobAtk - this->getDef();

					if(dmg > 0){
						cout<<"Damage taken: "<< dmg <<"."<<endl<<endl;
					}
					else{
						cout<<"Damage taken: 1."<<endl<<endl;
						dmg=1;
					}

					this->setHp(this->getHp() - dmg);

					system("pause");
				
				}

				if(this->getHp() <= 0){
					run = 1;
					mobHP = 0;
					this->setHp(0);

					cout<<endl<<"You cannot fight because your HP is too low!"<<endl
						<<"You risk your life by forcing to fight."<<endl
						<<"You has been slained."<<endl<<endl;

					if(this->getExp()!=0){
						expLoseTemp = rand()%this->getExp()+1;
						cout<<"You lose "<< expLoseTemp << " EXP!"<<endl;
						this->setExp(this->getExp()-expLoseTemp);
					}
					else{
						cout<<"Your EXP is already 0. Your EXP didn't reduce."<<endl<<endl;
					}
					system("pause");
				}
			}while(mobHP > 0);

			if(run == 2 && mobHP <= 0){
				cout<<"Your HP left: ";
				cout<<this->getHp()<<endl<<endl;
				cout<<"After the tough fight."<<endl<<"You successfully killed the monster."<<endl<<"You get "<<expTemp
					<<" EXP."<<endl<<endl;
				this->setExp(this->getExp()+expTemp);

				if(this->getExp()>=100){
					this->setLv(this->getLv()+1);
					cout<<"LEVEL UP!"<<endl<<"Now you are level "
						<<this->getLv()<<"."<<endl
						<<"HP is fully recovered and your stats improved!"<<endl;
					levelUp();
				}

				system("pause");

			}
		}

		void challenge(){
			int mobHP;
			int mobAtk;
			int run=2;
			int playerAtk;
			int sCounter=1;
		
			srand(time(NULL));

			mobHP = 250;

			do{
				int choice=0;
			
				mobAtk = (rand()%30+10) + this->getLv();
				playerAtk = 8+rand()%this->getAtk();

				space();
				cout<<endl<<"- HP -"<<endl;
				cout<<left<<setw(20)<<"Demon King"<<":"<<mobHP<<endl;
				cout<<left<<setw(20)<<this->getName()<<":"<<this->getHp()<<endl;

				cout<<endl<<endl;

				do{
					cout<<"ACTION:"<<endl;
					cout<<"1. ATTACK"<<endl;
					cout<<"2. RUN"<<endl;
					cout<<"3. SKILL"<<endl;
					cout<<"Choice: ";
					cin>>choice; cin.clear(); cin.sync();
				}while(choice < 1 || choice > 3);

				switch(choice){
					case 1:
						sCounter = 1;
						cout<<endl<<endl<<"You attacked the Demon King!"<<endl;

						if(playerAtk > getAtk()){
							cout<<"CRITICAL HIT!!"<<endl;
						}

						cout<<"Damage given: "<< playerAtk <<"."<<endl<<endl;
						mobHP = mobHP - playerAtk;

						break;

					case 2:
						cout<<"You cannot run from boss fight..."<<endl;

						system("pause");
						break;

					case 3:
						if(sCounter == 0){
							cout<<"Your skill is still on cooldown!"<<endl<<endl;
							cout<<"You must wait next turn to use your skill again."<<endl<<endl;
							sCounter = 1;
						}

						else{
							cout<<"You used your skill!"<<endl;
							cout<<"P O W E R   S H O T ! ! !"<<endl;

							cout<<"Damage given: "<< playerAtk <<"."<<endl<<endl;
							mobHP = mobHP - (this->getSkill() +  ((int)playerAtk/2));

							sCounter = 0;
						}

						system("pause");
						break;
				}

				if(run == 2 && mobHP > 0){
					cout<<"The Demon King attacks you!"<<endl;
					int dmg = mobAtk - this->getDef();

					if(dmg > 0){
						cout<<"Damage taken: "<< dmg <<"."<<endl<<endl;
					}
					else{
						cout<<"Damage taken: 1."<<endl<<endl;
						dmg=1;
					}

					this->setHp(this->getHp() - dmg);

					system("pause");
				
				}

				if(this->getHp() <= 0){
					run = 1;
					mobHP = 0;
					this->setHp(0);

					cout<<endl<<"You cannot fight because your HP is too low!"<<endl
						<<"You risk your life by forcing to fight."<<endl
						<<"You has been slained."<<endl<<endl;

					system("pause");
				}
			}while(mobHP > 0);

			if(run == 2 && mobHP <= 0){
				cout<<"Your HP left: ";
				cout<<this->getHp()<<endl<<endl;
				cout<<"After the tough fight..."<<endl; Sleep(600);
				cout<<"You successfully killed the Demon King..."<<endl<<endl;
				ending();

			}
		}

		~Archer(){
		}
};

class Warrior:public Adventurer{
	private:
		int lv;
		int exp;
		int skill;
	public:
		Warrior(){
			this->lv=0;
			this->exp=0;
			this->skill=25;
		}

		void setLv(int lv){
			this->lv=lv;
		}
		
		int getLv(){
			return this->lv;
		}

		void setExp(int exp){
			this->exp=exp;
		}

		int getExp(){
			return this->exp;
		}

		void setSkill(int skill){
			this->skill=skill;
		}

		int getSkill(){
			return this->skill;
		}

		void sleep(){
			cout<<"You take a rest, your HP is now fully recovered."<<endl;
			setHp(getMaxHp());
		}

		void levelUp(){
			setExp(0);
			setAtk(getAtk()+2);
			setSkill(getSkill()+4);
			setDef(getDef()+3);
			setMaxHp(getMaxHp()+20);
			setHp(getMaxHp());
		}

		void view(){
				cout<<"NAME   : "<<Adventurer::getName()<<endl
					<<"CLASS  : "<<this->getClass()<<endl
					<<"LEVEL  : "<<this->getLv()<<endl
					<<"EXP    : "<<this->getExp()<<endl
					<<"HP     : "<<this->getHp()<<endl
					<<"MAX HP : "<<getMaxHp()<<endl
					<<"ATTACK : "<<getAtk()<<endl
					<<"DEFENCE: "<<getDef()<<endl
					<<"SKILL  : "<<this->getSkill()<<endl;
		}

		void fight(){
			int expTemp;
			int expLoseTemp;

			cout<<"..."<<endl; Sleep(500);
			cout<<"..."<<endl; Sleep(500);
			cout<<"You found an enemy!"<<endl; Sleep(500);
			system("pause");

			int mobHP;
			int mobAtk;
			int run=2;
			int playerAtk;
			int sCounter=1;

			expTemp = rand()%30+20;
		
			srand(time(NULL));

			mobHP = (rand()%40+20) + this->getLv();

			do{
				int choice=0;
			
				mobAtk = (rand()%30+5) + this->getLv();
				playerAtk = 8+rand()%this->getAtk();

				space();
				cout<<endl<<"- HP -"<<endl;
				cout<<left<<setw(20)<<"Monster"<<":"<<mobHP<<endl;
				cout<<left<<setw(20)<<getName()<<":"<<this->getHp()<<endl;
				cout<<endl<<endl;

				do{
					cout<<"ACTION:"<<endl;
					cout<<"1. ATTACK"<<endl;
					cout<<"2. RUN"<<endl;
					cout<<"3. SKILL"<<endl;
					cout<<"Choice: ";
					cin>>choice; cin.clear(); cin.sync();
				}while(choice < 1 || choice > 3);

				switch(choice){
					case 1:
						sCounter = 1;
						cout<<endl<<endl<<"You attacked the monster!"<<endl;

						if(playerAtk > getAtk()){
							cout<<"CRITICAL HIT!!"<<endl;
						}

						cout<<"Damage given: "<< playerAtk <<"."<<endl<<endl;
						mobHP = mobHP - playerAtk;

						break;

					case 2:
						sCounter = 1;
						cout<<"..."<<endl
							<<"You try to run..."<<endl
							<<"..."<<endl;
						system("pause");

						run = rand()%2+1;

						if(run == 1){
							cout<<"You successfully escaped."<<endl<<endl<<endl;
							mobHP = 0;
						}
						else if(run == 2){
							cout<<"Failed to run."<<endl<<endl<<endl;
						}

						system("pause");
						break;

					case 3:
						if(sCounter == 0){
							cout<<"Your skill is still on cooldown!"<<endl<<endl;
							cout<<"You must wait next turn to use your skill again."<<endl<<endl;
							sCounter = 1;
						}

						else{
							cout<<"You used your skill!"<<endl;
							cout<<"B L A D E   F U R Y ! ! !"<<endl;

							cout<<"Damage given: "<< playerAtk <<"."<<endl<<endl;
							mobHP = mobHP - (this->getSkill() +  ((int)playerAtk/2));

							sCounter = 0;
						}

						system("pause");
						break;
				}

				if(run == 2 && mobHP > 0){
					cout<<"The monster attacks you!"<<endl;
					int dmg = mobAtk - this->getDef();

					if(dmg > 0){
						cout<<"Damage taken: "<< dmg <<"."<<endl<<endl;
					}
					else{
						cout<<"Damage taken: 1."<<endl<<endl;
						dmg=1;
					}

					this->setHp(this->getHp() - dmg);

					system("pause");
				
				}

				if(this->getHp() <= 0){
					run = 1;
					mobHP = 0;
					this->setHp(0);

					cout<<endl<<"You cannot fight because your HP is too low!"<<endl
						<<"You risk your life by forcing to fight."<<endl
						<<"You has been slained."<<endl<<endl;

					if(this->getExp()!=0){
						expLoseTemp = rand()%this->getExp()+1;
						cout<<"You lose "<< expLoseTemp << " EXP!"<<endl;
						this->setExp(this->getExp()-expLoseTemp);
					}
					else{
						cout<<"Your EXP is already 0. Your EXP didn't reduce."<<endl<<endl;
					}
					system("pause");
				}
			}while(mobHP > 0);

			if(run == 2 && mobHP <= 0){
				cout<<"Your HP left: ";
				cout<<this->getHp()<<endl<<endl;
				cout<<"After the tough fight."<<endl<<"You successfully killed the monster."<<endl<<"You get "<<expTemp
					<<" EXP."<<endl<<endl;
				this->setExp(this->getExp()+expTemp);

				if(this->getExp()>=100){
					this->setLv(this->getLv()+1);
					cout<<"LEVEL UP!"<<endl<<"Now you are level "
						<<this->getLv()<<"."<<endl
						<<"HP is fully recovered and your stats improved!"<<endl;
					levelUp();
				}

				system("pause");

			}
		}

		void challenge(){
			int mobHP;
			int mobAtk;
			int run=2;
			int playerAtk;
			int sCounter=1;
		
			srand(time(NULL));

			mobHP = 250;

			do{
				int choice=0;
			
				mobAtk = (rand()%30+10) + this->getLv();
				playerAtk = 8+rand()%this->getAtk();

				space();
				cout<<endl<<"- HP -"<<endl;
				cout<<left<<setw(20)<<"Demon King"<<":"<<mobHP<<endl;
				cout<<left<<setw(20)<<this->getName()<<":"<<this->getHp()<<endl;

				cout<<endl<<endl;

				do{
					cout<<"ACTION:"<<endl;
					cout<<"1. ATTACK"<<endl;
					cout<<"2. RUN"<<endl;
					cout<<"3. SKILL"<<endl;
					cout<<"Choice: ";
					cin>>choice; cin.clear(); cin.sync();
				}while(choice < 1 || choice > 3);

				switch(choice){
					case 1:
						sCounter = 1;
						cout<<endl<<endl<<"You attacked the Demon King!"<<endl;

						if(playerAtk > getAtk()){
							cout<<"CRITICAL HIT!!"<<endl;
						}

						cout<<"Damage given: "<< playerAtk <<"."<<endl<<endl;
						mobHP = mobHP - playerAtk;

						break;

					case 2:
						cout<<"You cannot run from boss fight..."<<endl;

						system("pause");
						break;

					case 3:
						if(sCounter == 0){
							cout<<"Your skill is still on cooldown!"<<endl<<endl;
							cout<<"You must wait next turn to use your skill again."<<endl<<endl;
							sCounter = 1;
						}

						else{
							cout<<"You used your skill!"<<endl;
							cout<<"B L A D E   F U R Y ! ! !"<<endl;

							cout<<"Damage given: "<< playerAtk <<"."<<endl<<endl;
							mobHP = mobHP - (this->getSkill() +  ((int)playerAtk/2));

							sCounter = 0;
						}

						system("pause");
						break;
				}

				if(run == 2 && mobHP > 0){
					cout<<"The Demon King attacks you!"<<endl;
					int dmg = mobAtk - this->getDef();

					if(dmg > 0){
						cout<<"Damage taken: "<< dmg <<"."<<endl<<endl;
					}
					else{
						cout<<"Damage taken: 1."<<endl<<endl;
						dmg=1;
					}

					this->setHp(this->getHp() - dmg);

					system("pause");
				
				}

				if(this->getHp() <= 0){
					run = 1;
					mobHP = 0;
					this->setHp(0);

					cout<<endl<<"You cannot fight because your HP is too low!"<<endl
						<<"You risk your life by forcing to fight."<<endl
						<<"You has been slained."<<endl<<endl;

					system("pause");
				}
			}while(mobHP > 0);

			if(run == 2 && mobHP <= 0){
				cout<<"Your HP left: ";
				cout<<this->getHp()<<endl<<endl;
				cout<<"After the tough fight..."<<endl; Sleep(600);
				cout<<"You successfully killed the Demon King..."<<endl<<endl;
				ending();

			}
		}

		~Warrior(){
		}
};

Adventurer *player1 = new Adventurer();

void cheat(){
	string cheat;

	getline(cin, cheat);
	cin.clear(); cin.sync();

	if(cheat == "albertusheroniusganteng"){
		cout<<"Cheat success..."<<endl;

		player1->setLv(99);
		player1->setAtk(999);
		player1->setDef(999);
		player1->setMaxHp(999);
		player1->setHp(999);
		player1->setSkill(999);

		system("pause");
	}

	else if(cheat == "albertusheroniustampan"){
		cout<<"Cheat success..."<<endl;
		system("pause");
		space();

		ending();
	}

	else{
		cout<<"Cheat not found!"<<endl;
	}

}

void advance(int &adv){
	int pick;
	int atkTemp, defTemp, maxHpTemp;
	string nameTemp = player1->getName();
	atkTemp = player1->getAtk();
	defTemp = player1->getDef();
	maxHpTemp = player1->getMaxHp();

	if(player1->getLv() >= 5){
	cout<<"You are ready."<<endl;

	do{
		cout<<endl<<"Now, pick the class you want:"<<endl;
		cout<<"1. Warrior"<<endl<<"2. Archer"<<endl<<endl;
		cin>>pick; cin.clear(); cin.sync();
		adv = 1;

		if(pick < 1 || pick > 2){
			cout<<endl<<"Please pick either 1 or 2."<<endl;
		}

	}while(pick < 1 || pick > 2);

		switch(pick){
			case 1:
				player1 = new Warrior();
				player1->setName(nameTemp);
				player1->setAtk(atkTemp+5);
				player1->setDef(defTemp+10);
				player1->setMaxHp(maxHpTemp+10);
				player1->setHp(player1->getMaxHp());
				player1->setClass("Warrior");
				cout<<"Congratulations, you have become a Warrior!"<<endl;
				break;
			case 2:
				player1 = new Archer();
				player1->setName(nameTemp);
				player1->setAtk(atkTemp+10);
				player1->setDef(defTemp+5);
				player1->setMaxHp(maxHpTemp+10);
				player1->setHp(player1->getMaxHp());
				player1->setClass("Archer");
				cout<<"Congratulations, you have become an Archer!"<<endl;
				break;
		}
	}

	else{
		cout<<"You are not strong enough."<<endl;
		cout<<"< You must level 5 or more to advance your class >"<<endl;
	}

	system("pause");
	space();
	}

int main(){
	string nameTemp;
	int ch;
	int adv = 0;
	space();

	cout<<"WELCOME TO THE WORLD OF POLYTANCE ..."<<endl; Sleep(700);
	cout<<"..."<<endl; Sleep(500);
	cout<<"..."; Sleep(500);
	cout<<endl<<"..."; Sleep(600);
	cout<<endl<<"SORRY, WHAT'S YOUR NAME?"; Sleep(500);
	cout<<endl;
			cout<<"I'm (input your name): ";
			getline(cin, nameTemp);
			system("cls");
			space();
			cout<<"Well, hello "<<nameTemp<<"."<<endl; Sleep(500);
			cout<<"First of all, the most important think you need to know is that you are already dead."<<endl; Sleep(600);
			cout<<"But because of your unforgivable sins, you trapped in this world, POLYTANCE."<<endl; Sleep(600);
			cout<<"You can leave this world by defeating the Demon Lord."<<endl; Sleep(600);
			cout<<"I think that's all you need to know."<<endl; Sleep(500);
			cout<<"Good luck!"<<endl<<endl; system("pause");

	player1->setName(nameTemp);

	do{
		do{
			system("cls");

			space();
			cout<<"1. VIEW STATUS"<<endl
				<<"2. FIGHT"<<endl
				<<"3. SLEEP"<<endl
				<<"4. ADVANCE CLASS"<<endl
				<<"5. CHALLENGE DEMON KING"<<endl
				<<"6. GIVE UP"<<endl
				<<"7. ..."<<endl
				<<"What are you going to do?"<<endl;
			cin>>ch; cin.clear(); cin.sync();
		}while(ch<1 || ch>7);

		switch(ch){
			case 1:
				system("cls");
				space();

				player1->view();

				system("pause");
				break;

			case 2:
				system("cls");
				space();

				if(player1->getHp() == 0){
					cout<<"You must rest. Your HP is 0!"<<endl;
				}

				else{
					player1->fight();
				}

				cin.get();
				break;

			case 3:
				system("cls");
				space();

				player1->sleep();

				system("pause");
				break;
			
			case 4:
				system("cls");
				space();

				if(adv == 0){
					advance(adv);
				}

				else{
					space();
					cout<<"You can only advance once!"<<endl;
					system("pause");
				}

				break;
				
			case 5:
				string cl;
				system("cls");
				space();
				
				if(player1->getClass() != "Warrior" && player1->getClass() != "Archer"){
					cout<<"You can't challenge yet."<<endl;
					cout<<"You are not strong enough..."<<endl;
				}

				else{
					do{
						cout<<endl<<"Are you sure?"<<endl;
						cout<<"Choice [yes/no]:"<<endl;
						getline(cin, cl); cin.clear(); cin.sync();
					}while(cl != "yes" && cl != "no");

					if(cl == "yes"){
						player1->challenge();
					}
					else{
						cout<<endl<<"~ Huh... I think I'm not strong enough.. ~"<<endl;
					}
													
				}
				
				system("pause");
				break;

		}

		if(ch == 7){
			system("cls");
			space();

			cout<<"Input cheat code:"<<endl;

			cheat();

			cin.get();
		}

	}while(ch!=6);

	cout<<"Well, " << nameTemp << ". Sometimes giving up is the best way though..."<<endl;Sleep(600);
	cout<<"Alright, thank you for wasting your time here."<<endl;Sleep(600);
	cout<<"See you next time!"<<endl;
	cout<<right<<setw(110)<<"By: 2101690042"<<endl;
	system("pause");

	return 0;
}