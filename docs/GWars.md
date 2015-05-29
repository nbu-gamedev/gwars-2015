# GWars

## Game Description

In GWars, the player controls a small circular ship on a screen-sized battlefield without scrolling.
Enemies of two types appear from the edges of the screen in predetermined waves and attack the player.
The player can shoot at the enemies, and they shoot back at him. The player gets points for killing each enemy.
The duration of the game is fixed; if the player's ship is destroyed before that, it is respawned after a brief pause.
The objective of the game is to achieve the highest score.

### Control

The player's ship is controlled via the two analog sticks of a standard dual-stick gamepad.
The left stick controls the ship's movement; the ship moves in the direction the stick is held, instantly reorienting itself
when the direction changes. When the left stick is in the dead zone in the center, the ship stops moving.
The ship's movement is subject to inertia and friction; i.e. when starting to move, it takes some time to reach its
maximum speed; direction changes don't happen instantaneously; and when the stick is released, it slows down before
stopping completely.
The right stick shoots the ship's weapon. When the stick is held in a direction, bullets are fired periodically in that
direction; when the stick is released, the shooting stops. Bullets move faster than the ship and the enemies, and disappear
after travelling a certain distance.

### Enemies

The game has two types of enemies.

The first type of enemy, the Kamikaze, moves towards the current position of the player.
It doesn't shoot and moves slightly slower than the player's maximum speed.

The second type of enemy, the Shooter, tries to approach the player while keeping a safe distance.
When the player is within a certain radius, it shoots at the current position of the player's ship.
Its bullets move with their own speed, possibly different from the player's bullet, and also disappear after
travelling a certain distance, different from the player's bullets' travel distance.

Enemies appear at the edges of the screen at predetermined locations and moments in time.
This predefined sequence of waves intensifies as time goes on, so the game becomes progressively harder the
longer the player survives.

The player's bullets hurt only the enemies, and the enemies' bullets hurt only the player.
Both the player and the enemies can be killed by a single bullet. When an enemy is killed, it displays a brief
explosion animation and disappears. When the player is killed, all the enemies also disappear. After several seconds,
the player is respawned in the spot where he died; if this was too close to the border of the screen, this spot is adjusted
towards the center of the screen. The enemy spawn sequence continues after a few more seconds with the original
timing of waves - the enemies that should have been spawned while the player was dead and just-spawned are ignored.

The player is killed when colliding with an enemy. Enemies pass freely through each other. Both the player and the enemies
bounce off the edges of the screen.

### Scoring and Game Session

The game is played in sessions of 3 min each. 
Each killed enemy gives a certain number of points depending on its type.
The current score is shown in the top left part of the screen. The high score is shown in the top right part of the screen.
When the session ends, the high score is updated if needed (and saved to disk), a screen with the score and two options
("Play" and "Exit"). Pressing one of the gamepad buttons exits the game, pressing any other starts a new session begins.

## Implementation

SDL for input and graphics.

### Structure

Two game loops: one for gameplay, one for the play/exit screen between game sessions.

Represent all game entities: player, enemies, bullets, as objects of classes deriving from a common base class, Actor,
with two important virtual methods: Update() and Render()

Update() 
  * moves the actor according to its rules (controlled by gamepad in the case of the player, movement/attack logic in the case of the enemies)
  * checks for collisions with other actors (treat all actors as circles)
  * possibly spawns other actors (player shooting bullets if a gamepad button is pressed, enemies shooting)
  * if dead, spawn a new actor to represent explosion
  * if player dead, notify world to start respawn procedure, kill other actors etc.
  
Render(time)
  * draw the object as appropriately rotated and scaled sprite, position interpolated based on current time
  * pick frame from animation explosion if dead, based on time
  
Gameplay loop:
  * take global time
  * "catch up" with time elapsed by running 0 or several updates
  * each update consists of global update and updating all of the actors
  * global update handles enemies spawn, and player respawn sequence
  * render
  
Should render smoothly even when update time is very long; should work the same even if framerate is bad.
  
### Configuration

All gameplay constants - ship, enemy, bullet speeds, radii, inertia parameters - are stored in a text file which
is read in the beginning of each game session, so the game can be tweaked for "fun" without restarting, recompiling etc.

Enemy spawn waves are configured in a separate text file, also read on each session, controlling the timing, type and position of spawns.

10, 5KL

15, 3ST, 3SB

### Milestones

  1. Setup: project, SDL, GitHub, base Actor class, World class, main loop, rendering of sprites
  2. Basic features
    1. Player control - gamepad input, shooting
    2. Update enemies and bullets, enemy shooting, collisions
    3. World update: enemy spawn sequence, player respawn procedure  
  3. Advanced features
    1. Advanced player behavior - bouncing off walls, inertia when moving
    2. Advanced enemy behavior - specific for Kamikaze/Shooter
    3. High score, screen after session, explosion animations

## Additional work

  * sound effects
  * more interesting behavior of the enemies - slight randomization, sideways movement of the Shooter
  * randomized spawn sequences - e.g. specify only number and type of enemies to spawn, and pick a random part of the border
  * score multiplier: dead enemies drop an object which has to be collected by the player by passing over it;
    each of these increments a number which multiplies the point from each subsequently killed enemy. The
    multiplier is reset to 1 when the player dies
  * vector-, not sprite-based graphics