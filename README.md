# CMP105 Alternative Project

_NOTE: This is an example based on the alternative project as if submitted for the Trunk assignment_

## Game 

**Dino Hanyman: Spanner in the Works** 

This extension will turn the game into a simple Metroidvania where the dino handyman will unlock three new abilities to progress through one large level. This will include dash from level one, as well as the ability to through spanners as a form of attacking enemies and a double jump.

**Controls:** 

WASD to move,
Spacebar to jump,
F to interact (prompts will appear when possible),
R to reset (if you get stuck or fall down)
P to pause,
L-Control to dash,
left mouseclick in the menu.

## Student Details

**Student Name:** William Kavanagh

**Student Number:** 0000001

**Course:** _CGAD_ / _CGT_ I am of both courses, and of none.

---
---

# Proposal

## Brief Overview of game 

Dino Handyman: Spanner in the Works, will be a single-level metroidvania platformer where the play controls a small dinosaur. To begin with they will be able to jump, as the game progresses they will gain three skills -- dashing, double-jumping and attacking, in order to complete the game. The level will be setup so that progress is only possible with each ability, e.g., to cross the largest gap you will need to double-jump and to dash. The player will be timed while completing the level and at the end of the game, if they complete it without dying, they will be shown their time alongside the best time acheived. Additional levels could be created later thanks to the use of a data-driven level loading system which is used as the tilemap for the game. 

## Must Have Features

* Spanner Throwing: The player will be able to press 'r' to throw a spanner in the direction they are facing with a slight arc before it falls to the ground. 

* Enemies: Gremlins will be in certain parts of the level and will move towards a player if they are in range. On collision with the player the level will be reset on collision with a spanner they will despawn.

* Double Jumping: When they get a special coin, the player will be able to jump one more time in the air. This will allow them to get to a higher platform.

## Should Have Features

* Data-driven Level Loading: To create a level large enough to introduce the new mechanics without making the code a mess. 

* Lives and Losing: The play will only have a three lives. If they fall off a platform or hit an enemyn they will lose one life and if they get to zero lives they will see a game over screen.

* Pausing: The game will be able to be paused with a simple transparent overlay. Music will be paused similarly and resumed when play continues.

## Could Have Features

* Leaderboard: The speed with which a player completes the level will be written to file and then displayed once the level is completed.

* A Heads-up Display: Showing the time taken so far, the dash, wrench and double-jump cooldowns and the number of lives remaining will be shown fixed to the screen.

* Gremlin Animations: The gremlins will have different animation cycles including walking, running, idle, and attacking, for various actions they can be performing. 

## Wish to Have Features

* Checkpoints: There will be positions in the level where the player can restart from if they lose a life, should they have got far enough. These will be placed where the player gets new abilities.

* Coyote Time: The platforming will be enhanced by coyote time, a grace period during which the player can still jump even if they are not on a platform. 
