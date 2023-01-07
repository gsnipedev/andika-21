#include "db.h"

card_deck dealer_deck;
card_deck player_deck;

void awake_db()
{
    system("cls");

    dealer_deck.size = 0;
    player_deck.size = 0;

    hit_dealer(random(1, 13));
    hit_dealer(random(1, 13));

    hit_player(random(1, 13));
    hit_player(random(1, 13));
}

int random(int min, int max){
    return rand() % (max - min + 1) + min;
}

void print_deck(int hidden)
{
    // 1 is true, 0 is false

    int _total = 0;

    //============================[Dealer Block]===================//

    printf("Dealer : [");

    for(int i = 0; i < dealer_deck.size; i++)
    {

        if(hidden == 1 && i > 0)
        {
            printf("?");
        }
        else
        {
            printf("%d",dealer_deck.cards[i]);
        }

        if( i == dealer_deck.size - 1) continue;

        printf(", ");
    }

    printf("] ");

    if(hidden == 1) printf("(?)");
    else printf("(%d)", dealer_deck.total_count);
    

    printf("\n");

    //=============================================================//

    //============================[Player Block]===================//
    printf("Player : [");
    
    for(int i = 0; i < player_deck.size; i++)
    {
        _total += player_deck.cards[i];
        printf("%d", player_deck.cards[i]);

        if( i == player_deck.size - 1) continue;

        printf(", ");
    }

    printf("] ");
    printf("(%d)", player_deck.total_count);

    printf("\n");

    //=============================================================//

}

void hit_dealer(int card)
{
    dealer_deck.cards[dealer_deck.size] = card;
    dealer_deck.size++;
    dealer_deck.total_count += card;
}

void hit_player(int card)
{
    player_deck.cards[player_deck.size] = card;
    player_deck.size++;
    player_deck.total_count += card;
}

int is_player_busted()
{
    if(player_deck.total_count > 21) return 1;

    return 0;
}

int is_dealer_busted()
{
    if(dealer_deck.total_count > 21) return 1;

    return 0;
}

void final_message()
{

    if((is_dealer_busted() == 1) && (is_player_busted() == 1))
    {
        printf("Draw, you both Busted!");
    }
    else if((is_dealer_busted() == 1) && (is_player_busted() == 0))
    {
        printf("You win, dealer is Busted!");
    }
    else if((is_dealer_busted() == 0) && (is_player_busted() == 1))
    {
        printf("Dealer win, you are Busted!");
    }
    else if(player_deck.total_count == dealer_deck.total_count)
    {
        printf("Draw, your card are equals");
    }
    else if(player_deck.total_count > dealer_deck.total_count)
    {
        printf("You win!");
    }
    else
    {
        printf("Dealer win!");
    }

}