#include "andika/db.h"


int main(void)
{
    srand(time(NULL));

    awake_db();

    printf("===== [Andika 21] =====\n\n");

    print_deck(1);

    //this is player turn
    do
    {
        char act[64];
        printf("Action (hit/stand): ");
        scanf("%s", &act);

        if(strcmp(act, "stand") == 0) break;

        system("cls");
        hit_player(random(1, 13));
        print_deck(1);

    }while(is_player_busted() == 0);

    //now dealer turn

    if(is_player_busted() == 0)
    {
        for(int i = 0; i < random(0, 2); i++)
        {
            if(is_dealer_busted() == 1) break;

            hit_dealer(random(1, 13));
        }
    }


    system("cls");
    print_deck(0);

    printf("\n\n");

    final_message();


}