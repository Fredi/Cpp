/**
 * Studying C++
 * Simple Turn Based Battle Game
 * 
 * Based on TrinityCore's code
 * https://github.com/TrinityCore/TrinityCore
 *
 * Fredi Machado
 * http://github.com/fredi
 */

#include "creature.h"
#include "player.h"
#include "util.h"
#include "datastores.h"

#include <conio.h>

int main()
{
    LoadDataStores("data/");

    // player
    Player* player1 = new Player();
    player1->SetMaxHealth(30);
    player1->SetHealth(30);
    player1->SetDamage(1.0f, 4.0f);

    // creature
    Creature* mob1 = new Creature();
    mob1->SetMaxHealth(30);
    mob1->SetHealth(30);
    mob1->SetDamage(1.0f, 4.0f);

    while (player1->IsAlive() && mob1->IsAlive())
    {
        printf("******************************\n");
        printf("** Player's turn: ************\n\n");
        player1->AttackerStateUpdate(mob1);

        if (urand(0, 1) == 0) // 50% chance to cast spell on creature (just for testing)
            player1->CastSpell(mob1, urand(1, 2));

        printf("** End Player's turn: ********\n");
        printf("******************************\n\n");

        getch();

        if (mob1->IsAlive())
        {
            printf("******************************\n");
            printf("** Creature's turn: **********\n\n");
            mob1->AttackerStateUpdate(player1);

            if (urand(0, 1) == 0) // 50% chance to cast spell on player (just for testing)
                mob1->CastSpell(player1, urand(1, 2));

            printf("** End Creature's turn: ******\n");
            printf("******************************\n\n");

            getch();
        }
    }

    delete player1;
    delete mob1;

    return 0;
}
