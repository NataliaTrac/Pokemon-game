# Pokemon

This is a console-based C++ projectr, where players can engage in strategic battles using creatures with unique abilities. The game involves managing creatures, each with special powers, and battling against computer-controlled opponents or making strategic decisions such as attacking, evolving creatures, or swapping them during battle.

# Project Overview
The goal is to demonstrate skill in C++ and general software development skills, including the use of appropriate programming tools and creating documentation for developed modules. The project is inspired by turn-based battle systems found in games like Pokemon, where players manage a team of creatures to defeat their opponents.

# Features
- Turn-based combat system with player vs. computer battles.
- A selection of creatures each with unique abilities and stats.
- Special abilities for creatures, including offensive and defensive powers.
- Game progresses through rounds, each with multiple opponents.
- Command-line interface for game interaction and navigation.

# Gameplay
The game consists of at least four rounds, with each round featuring at least four opponents. Players select a team of six creatures from a predefined pool at the game's start. The gameplay involves making strategic decisions each turn, utilizing creatures' special abilities, and managing the team to ensure victory.

## Turn Mechanics
During each turn, players can choose to:

- **Attack** - Use your creature's basic attack or special ability to deal damage.
- **Swap Creatures** - Replace your active creature with another from your team, useful if facing a disadvantageous type matchup.
- **Evolve Creatures** - Enhance your creature's stats if it has gained enough experience from battles.

### Character Swapping
- **Strategic Swaps** - You can swap your active creature anytime during your turn. This is critical when your current creature is at a disadvantage due to the type effectiveness system or low health.
- **Swap Limitations** - Swapping does not cost a turn, but choose wisely, as each creature can only be swapped once per turn.

## Fainting Mechanics
- **Health Points (HP)** - Each creature has HP. When it reaches zero due to battle damage, the creature faints and cannot participate further in the battle.
- **Recovery** - Fainted creatures cannot be revived during a battle but are automatically revived after the battle concludes.

## Type Effectiveness System
Creatures belong to types (e.g., Water, Fire, Earth, Air, Ice, Steel), each with strengths and weaknesses against other types, similar to Pokémon's type mechanics. For example:

- Water is strong against Fire but weak against Earth.
- Fire is strong against Ice but weak against Water.
Understanding and exploiting these type matchups are essential for gaining an advantage in battles.

# Documentation and help
Use --help or -h command-line argument for usage instructions.
Ensure all non-trivial functions, methods, and classes are documented, focusing on what is done rather than how.


# Project Structure
The project consists of multiple classes that work together to simulate a battle environment. Key classes include:

- **``Creature`-** Defines the creatures involved in battles, including their attributes like strength, agility, HP, and special powers.
- **`Player` and `Computer` -**  Represent the player and the AI opponent, respectively, making decisions during the game.
- **`Game` -**  Manages the game's flow, including rounds of battles and interactions between players and creatures.
- **`SpecialPower` -**  Represents special abilities that creatures can use in battles.
- **`CreatureRepository` -**  A collection of available creatures from which players can choose.
- **`Random` -**  A utility class for generating random numbers.
- **`Input` -** Handles all user inputs, ensuring players can interact with the game by making selections and decisions through the console.
- **`Result` -**  Represents the outcome of actions within the game.




