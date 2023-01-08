#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct card_deck
{

    int cards[64];
    int size;
    int total_count;

}card_deck;

void awake_db();

void print_deck();

void hit_dealer(int card);

void hit_player(int card);

int is_player_busted();

int is_dealer_busted();

void final_message();

int random(int min, int max);