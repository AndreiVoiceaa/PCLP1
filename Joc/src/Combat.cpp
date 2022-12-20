#include "Combat.h"

void Combat :: ShowStatsBeforeCombat(Player &player , Enemy &_enemy)
{

    cout<<"                                                                                                        Player|"<<_enemy.GetName()<<" Health: "<<player.GetHEALTH()<<"|"<<_enemy.GetHEALTH()<<endl<<endl;
    cout<<"Player|"<<_enemy.GetName()<<" Stats: "<<endl<<endl;
    cout<<"Maximum Health: "<<player.GetMAXHEALTH()<<"|"<<_enemy.GetMAXHEALTH()<<endl;
    cout<<"Physical Damage: "<<player.GetPHYSICALDAMAGE()<<"|"<<_enemy.GetPHYSICALDAMAGE()<<endl;
    cout<<"Magical Damage: "<<player.GetMAGICALDAMAGE()<<"|"<<_enemy.GetMAGICALDAMAGE()<<endl;
    cout<<"Physical Armor: "<<player.GetPHYSICALARMOR()<<"|"<<_enemy.GetPHYSICALARMOR()<<endl;
    cout<<"Magical Armor: "<<player.GetMAGICALARMOR()<<"|"<<_enemy.GetMAGICALARMOR()<<endl;
    cout<<"Evasion: "<<player.GetEVASION()<<"%|"<<_enemy.GetEVASION()<<"%"<<endl;
    cout<<"Level: "<<player.GetLevel()<<"|"<<_enemy.GetLevel()<<endl;
    cout<<"Experience: "<<player.GetExperience()<<endl;
    cout<<"Coins: "<<player.GetCoins()<<endl;

    cout<<endl;
    player.ShowInventory();
    cout<<endl;
    player.ShowPerks();
    cout<<"Combat Log: "<<endl<<endl;

}


void Combat :: Fight(Player &player , Enemy &_enemy , list<Perk> &_AllPerks)
{

    Grind:

    system("cls");
    player.RestoreHealth();
    _enemy.RestoreHealth();



    while(player.GetHEALTH()>0 && _enemy.GetHEALTH()>0)
    {

        system("cls");

        ///Player Turn

        unsigned short int RandomNumber = 1 + (rand() % 100);

        if(RandomNumber>_enemy.GetEVASION())
        {

            _enemy.TakeDamage(player.ReturnStats());
            ShowStatsBeforeCombat(player , _enemy);
            cout<<_enemy.GetName()<<" a fost lovit cu "<<player.GetPHYSICALDAMAGE()<<" physical damage si  "<<player.GetMAGICALDAMAGE()<<" magical damage"<<endl<<endl;


            if(player.GetHEALTH()<=0)
            {
                player.Defeat();
                break;
            }
            else if(_enemy.GetHEALTH()<=0)
            {

                _enemy.Drop(player);
                system("pause");
                system("cls");
                break;
            }


            }
            else
            {
                ShowStatsBeforeCombat(player,_enemy);
                cout<<_enemy.GetName()<<" s-a ferit de atac"<<endl<<endl;

            }

            system("pause");
            system("cls");

            ///Enemy Turn

            RandomNumber = 1 + (rand() % 100);

            if(RandomNumber>player.GetEVASION())
            {
                player.TakeDamage(_enemy.ReturnStats());
                ShowStatsBeforeCombat(player,_enemy);
                cout<<"Player-ul a fost lovit cu "<<_enemy.GetPHYSICALDAMAGE()<<" physical damage si "<<_enemy.GetMAGICALDAMAGE()<<" magical damage"<<endl<<endl;

                if(player.GetHEALTH()<=0)
                {
                    player.Defeat();
                    break;
                }
                else if(_enemy.GetHEALTH()<=0)
                {

                _enemy.Drop(player);
                system("pause");
                system("cls");
                break;
                }

            }
            else
            {
                ShowStatsBeforeCombat(player,_enemy);
                cout<<"Player-ul s-a ferit de atac"<<endl<<endl;
            }

            system("pause");

    }




    if(player.GetExperience()>=player.GetEXPERIENCELIMIT())
        player.LevelUp(_AllPerks , MainHandle);

    player.BuyStats(MainHandle , StatPrice);


    if(MainHandle.InputHandler("Doresti sa lupti cu inamicul din nou? (1-DA , 2-NU)" , 2)==1)
        goto Grind;



}
