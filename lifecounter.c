/* Magic the Gathering 4 player Commander Life Counter */

#include <gb/gb.h>
#include <stdint.h>
#include <gb/drawing.h>
#include "sprite.h"
#include <stdbool.h>

enum player {
    PLAYER1,
    PLAYER2,
    PLAYER3,
    PLAYER4
};

// Print all 4 players' HP totals to the screen
void printPlayerHPTotals(uint8_t* playerHPTotals) {
    uint8_t xPos = 0;
    uint8_t yPos = 0;
    for (int i=0; i<=3; i++) {
        switch (i) {
            case 0:
                xPos = 4;
                yPos = 4;
                break;
            case 1:
                xPos = 14;
                yPos = 4;
                break;
            case 2:
                xPos = 4;
                yPos = 12;
                break;
            case 3:
                xPos = 14;
                yPos = 12;
                break;
        }
        gotogxy(xPos, yPos);
        color(BLACK,WHITE,SOLID);
        // Print spaces to clear previous value
        gprintf("   "); 
        gotogxy(xPos, yPos);
	    gprintf("%u", playerHPTotals[i]);
    }
    return;
}

void main(void) {
    uint8_t playerHPTotals[] = {40, 40, 40, 40};
    bool playerSelected = false;

    printPlayerHPTotals(playerHPTotals);
    
    enum player currentPosition = PLAYER1;

    // Load the sprite tiles into VRAM
    set_sprite_data(0, sprite_TILE_COUNT, sprite_tiles);
    // Set sprite attributes
    // Set sprite 0 to use tile 0 from sprite_data
    set_sprite_tile(0, 0); 
    // P1 HP position
    move_sprite(0, 30, 47); 
    // P2 HP position
    // move_sprite(0, 111, 47);
    // P3 HP position
    // move_sprite(0, 30, 111);
    // P4 HP position
    // move_sprite(0, 111, 111); 
    SHOW_SPRITES; // Show sprites on the screen

    while(1) {
        uint8_t input = joypad();

        // If a player is not selected, navigate around the 4 players with the D-Pad
        if (!playerSelected) {
            if(input & J_A) {
                playerSelected = true;
            }
            if (input & J_UP) {
                if (currentPosition == PLAYER3) {
                    move_sprite(0, 30, 47); 
                    currentPosition = PLAYER1;
                } else if (currentPosition == PLAYER4) {
                    move_sprite(0, 111, 47);
                    currentPosition = PLAYER2;
                }
            }
            if (input & J_DOWN) {
                if (currentPosition == PLAYER1) {
                    move_sprite(0, 30, 111);
                    currentPosition = PLAYER3;
                } else if (currentPosition == PLAYER2) {
                    move_sprite(0, 111, 111); 
                    currentPosition = PLAYER4;
                }
            }
            if (input & J_LEFT) {
                if (currentPosition == PLAYER2) {
                    move_sprite(0, 30, 47); 
                    currentPosition = PLAYER1;
                } else if (currentPosition == PLAYER4) {
                    move_sprite(0, 30, 111);
                    currentPosition = PLAYER3;
                }
            }
            if (input & J_RIGHT) {
                if (currentPosition == PLAYER1){
                    move_sprite(0, 111, 47);
                    currentPosition = PLAYER2;
                } else if (currentPosition == PLAYER3) {
                    move_sprite(0, 111, 111); 
                    currentPosition = PLAYER4;
                }
            }
        // If a player is selected increment or decrement their HP total with Up or Down
        } else {
            if (input & J_UP) {
                if (playerHPTotals[currentPosition] <= 254) {
                    playerHPTotals[currentPosition]++;
                    printPlayerHPTotals(playerHPTotals);
                    delay(100);
                }
            } else if (input & J_DOWN){
                if (playerHPTotals[currentPosition] >= 1) {
                    playerHPTotals[currentPosition]--;
                    printPlayerHPTotals(playerHPTotals);
                    delay(100);
                }
            // When B is pressed, resume navigating between players
            } else if (input & J_B) {
                playerSelected = false;
            }
        }
    }

}